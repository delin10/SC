//
// Created by delinoz on 19-6-1.
//

#include "SNLLex.h"
#include "StringUtils.h"
#include "debug.h"
#include "structures.h"
#include "Utils.h"
#include "GlobalTbl.h"

#include <string.h>

extern GlobalTbl globalTbl;

SNLLex::SNLLex(string fileName) {
    this->fileName = fileName;
    cursor = 0;
    rowNum = 1;
}

SNLLex::~SNLLex() {

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

//    for (Token &token:tokenList) {
//        cout << "token:(" << token.id << "," << token.word << ")" << " " << token.lineInfo.srcFileName << ":"
//             << token.lineInfo.rowNum << endl;
//    }
}

void SNLLex::resolveToken(string &sourceCode) {
    while (cursor < sourceCode.length()) {
        //cout << "now char:" << sourceCode[cursor] << endl;
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
            Token &token = tokenList.back();
            cout << "token:(" << token.id << "," << token.word << ")" << " " << token.lineInfo.srcFileName << ":"
                 << rowNum << endl;
            //cout << "------------------>" << buffer << endl;
            break;
        }
        if (curState == END_STATE_NUM) {
            cout << "error line:" << fileName << ":" << rowNum << endl;
            exit(0);
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
    curState = globalTbl.getState(curState, ch);
    //cout << "cursor=" << cursor - 1 << "," << sourceCode[cursor - 1] << curState << endl;
    return curState;
}

bool SNLLex::isTokenTerminatedState() {
    return curState != END_STATE_NUM && curState < 0;
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
    //cout << "tokenId " << tokenId << endl;
    tokenList.push_back(Token(tokenId, buffer, this->rowNum, fileName));
}

int SNLLex::findKeyWordTokenId() {
    return globalTbl.findKeyWordTokenId(buffer);
}

vector<Token> &SNLLex::getTokenList() {
    return tokenList;
}

bool SNLLex::getTokenAt(Token &output, size_t pos) {
    if (pos >= tokenList.size()) {
        return false;
    }
    output = tokenList.at(pos);
    return true;
}

void SNLLex::printLexTbl() {
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 128; ++j) {
            cout << (int) globalTbl.getState(i, j) << " ";
        }
        cout << endl;
    }
}