//
// Created by delinoz on 19-6-1.
//

#include "SNLLex.h"
#include "StringUtils.h"
#include "debug.h"
#include "structures.h"
#include "Utils.h"

#include <string.h>

SNLLex::SNLLex(string fileName) {
    this->fileName = fileName;
    cursor = 0;
    rowNum = 1;
}

SNLLex::~SNLLex() {

}

/**
 * 设置状态转换表
 * @param str
 */
void SNLLex::setLexTbl(string &str) {
    vector<string> edges;
    vector<string> edgeInfoStr;
    StringUtils::regexSplit(str, edges, "\n");
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 128; ++j) {
            lexTbl[i][j] = END_STATE_NUM;
        }
    }
    for (string &edge_:edges) {
        string edge = StringUtils::trim(edge_);
        if (edge.size() == 0 || edge[0] == '#') {
            continue;
        }
        string start, cond, end;
        start = edge.substr(0, 2);
        end = edge.substr(edge.size() - 3, 3);
        cond = edge.substr(3, edge.size() - 7);
        int from = atoi(start.data()), to = atoi(end.data());
        //cout << "from:" << from << "," << cond << "," << "to:" << to << endl;
        if (cond.size() == 1) {
            lexTbl[from][cond[0]] = to;
        } else if (cond == "**") {
            for (int i = 0; i < 128; ++i) {
                lexTbl[from][i] = to;
            }
        } else if (cond[0] == '^') {
            //画重点
            //之前是直接设置所有char < m ,char > n
            int i = 1, j = 0;
            int m, n;
            while (i < cond.size()) {
                m = cond[i++];
                ++i;
                n = cond[i++];
                while (j < m) {
                    lexTbl[from][j++] = to;
                }
                while (j <= n) {
                    ++j;
                }
            }

            while (j < 128) {
                lexTbl[from][j++] = to;
            }
        } else {
            int i = 0;
            while (i < cond.size()) {
                int m = cond[i++];
                ++i;
                int n = cond[i++];
                for (int j = m; j <= n; ++j) {
                    lexTbl[from][j] = to;
                }
            }
        }
    }
}

/**
 * 设置关键字列表
 * @param word
 */
void SNLLex::setKeyWord(string &word) {
    vector<string> keywords;
    StringUtils::regexSplit(word, keywords, "\n");
    char i = 50;
    for (string &w:keywords) {
        string ww = StringUtils::trim(w);
        if (ww.size() > 0) {
            keyWordMap.insert(std::pair<string, char>(ww, i++));
        }
    }
}

void SNLLex::sourceStream() {
    string sourceCode = readFileAsString(this->fileName);
    while (cursor < sourceCode.length()) {
        skipWhiteChar(sourceCode);
        if (cursor >= sourceCode.length()) {
            return;
        }
        resetState();
        resolveToken(sourceCode);
    }
}


void SNLLex::skipComment(string &sourceCode) {
    cout << "skip comment:";
    ++cursor;
    while (cursor < sourceCode.length() && sourceCode[cursor] != '}') {
        if (sourceCode[cursor] == '\n') {
            rowNum++;
        }
        cout << sourceCode[cursor++];
    }
    cursor++;
    cout << endl;
}

void SNLLex::skipWhiteChar(string &sourceCode) {
    while (cursor < sourceCode.length() && StringUtils::isWhiteSpace(sourceCode[cursor])) {
        if (sourceCode[cursor] == '\n') {
            rowNum++;
        }
        ++cursor;
    }

    for (Token &token:tokenList) {
        cout << "token:(" << token.id << "," << token.word << ")" << " " << token.lineInfo.srcFileName << ":"
             << token.lineInfo.rowNum << endl;
    }
}

void SNLLex::resolveToken(string &sourceCode) {
    while (cursor < sourceCode.length()) {
        cout << "now char:" << sourceCode[cursor] << endl;
        //此处cursor++会乱码
        //跳过注释
        if (sourceCode[cursor] == '{') {
            skipComment(sourceCode);
            return;
        }
        getCurState(sourceCode);
        if (isTokenTerminatedState()) {
            //cout << "end state:" << curState << endl;
            addToTokenList();
            cout << "------------------>" << buffer << endl;
            break;
        }
        if (curState == END_STATE_NUM) {
            cout << "error.." << endl;
            return;
        }
        //Error State
        buffer.push_back(sourceCode[cursor - 1]);
    }
    back();
    resetBuffer();
}


int SNLLex::getCurState(string &sourceCode) {
    char ch = sourceCode[cursor++];
    //cout << ch << endl;
    curState = lexTbl[curState][ch];
    //cout << "cursor=" << cursor - 1 << "," << sourceCode[cursor - 1] << curState << endl;
    return curState;
}

bool SNLLex::isTokenTerminatedState() {
    return curState < 0;
}

void SNLLex::resetState() {
    this->curState = 0;
}

void SNLLex::resetBuffer() {
    buffer = "";
}

void SNLLex::back() {
    --cursor;
}

void SNLLex::addToTokenList() {
    int tokenId = -curState;
    int keyWordTokenId = findKeyWordTokenId();
    if (keyWordTokenId != -1) {
        tokenId = keyWordTokenId;
    }
    cout << "tokenId " << tokenId << endl;
    tokenList.push_back(Token(tokenId, buffer, this->rowNum, fileName));
}

int SNLLex::findKeyWordTokenId() {
    char tokenId;
    tokenId = -1;
    cout << "findKeyWordTokenId " << buffer << endl;
    bool isContains = findInMap<string, char>(keyWordMap, StringUtils::toUpperCase(buffer), &tokenId);
    cout << "isContains " << isContains << endl;
    cout << (int) tokenId << endl;
    return isContains ? tokenId : -1;
}

void SNLLex::printLexTbl() {
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 128; ++j) {
            cout << (int) lexTbl[i][j] << " ";
        }
        cout << endl;
    }
}