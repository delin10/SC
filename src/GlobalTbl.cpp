//
// Created by delinoz on 19-6-7.
//

#include "GlobalTbl.h"
#include "StringUtils.h"
#include "Utils.h"
#include "debug.h"

/**
 * 设置状态转换表
 * @param str
 */
void GlobalTbl::setLexTbl(string &file) {
    string str = readFileAsString(file);
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
        if (edge.empty() || edge[0] == '#') {
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
void GlobalTbl::setKeyWord(string &file) {
    string word = readFileAsString(file);
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

void GlobalTbl::setCmp(string &file) {
    string cmps = readFileAsString(file);
    vector<string> cmpLs;
    StringUtils::regexSplit(cmps, cmpLs, "\n");
    char i = 7;
    for (string &cmp:cmpLs) {
        string ww = StringUtils::trim(cmp);
        if (ww.size() > 0) {
            keyWordMap.insert(std::pair<string, char>(ww, i++));
        }
    }
}

void GlobalTbl::setBorder(string &file) {
    string ops = readFileAsString(file);
    vector<string> opLs;
    StringUtils::regexSplit(ops, opLs, "\n");
    char i = 20;
    for (string &op:opLs) {
        string ww = StringUtils::trim(op);
        if (ww.size() > 0) {
            keyWordMap.insert(std::pair<string, char>(ww, i++));
        }
    }
}

int GlobalTbl::getState(int from, int to) {
    return lexTbl[from][to];
}

int GlobalTbl::findKeyWordTokenId(string &keyword) {
    char tokenId = -1;
    bool isContains = findInMap<string, char>(keyWordMap, StringUtils::toUpperCase(keyword), &tokenId);
    return isContains ? tokenId : -1;
}


void GlobalTbl::setGrammarTbl(string &file) {
    string text = readFileAsString(file);
    vector<string> grammarLs;
    StringUtils::regexSplit(text, grammarLs, "\n");
    int grammarId = 100;
    for (string &grammar:grammarLs) {
        //这里拷贝太频繁了，我觉得可以定义一个StringBuilder
        string grammarTrim = StringUtils::trim(grammar);
        grammarTbl.insert(pair<string, int>(grammarTrim, grammarId++));
    }
    grammarTbl.insert(pair<string, int>("ID", 1));
    grammarTbl.insert(pair<string, int>("\"\"", 0));
    for (pair<string, int> g:grammarTbl) {
        cout << g.first << "," << g.second << endl;
    }
}

void GlobalTbl::setProductTbl(string &file) {
    string text = readFileAsString(file);
    vector<string> productLs;
    StringUtils::regexSplit(text, productLs, "\n");
    vector<string> productGrammarsBuffer;
    for (string &product:productLs) {
        cout << "processing " << product << " , empty= " << product.empty() << endl;
        vector<int> productVector;
        if (product.empty()) {
            productVector.push_back(0);
        } else {
            StringUtils::regexSplit(product, productGrammarsBuffer, "\\s+");

            for (string &grammar:productGrammarsBuffer) {
                string grammarTrim = StringUtils::trim(grammar);
                if (grammarTrim.empty()) {
                    continue;
                }
                int tmp;
                if (findGrammarId(grammarTrim, &tmp)) {
                    productVector.push_back(tmp);
                } else {
                    cout << "grammar is " << grammarTrim << endl;
                    cout << "error on " << product << endl;
                    exit(1);
                }
            }
        }
        productTbl.push_back(productVector);
        productGrammarsBuffer.clear();
    }

    int productNum = 0;
    for (vector<int> &productLs:productTbl) {
        cout << productNum << "-->";
        for (int &product:productLs) {
            cout << product << " ";
        }
        productNum++;
        cout << endl;
    }
}

bool GlobalTbl::findGrammarId(string &grammar, int *tmp) {
    return findInMap<string, int>(grammarTbl, grammar, tmp) || (*tmp = findKeyWordTokenId(grammar)) > 0;
}

void GlobalTbl::setParseTbl() {
    string firstSet = readFileAsString("resources/First.txt");
    string followSet = readFileAsString("resources/Follow.txt");

    vector<string> firstSetLs;
    StringUtils::regexSplit(firstSet, firstSetLs, "\n");
    vector<string> followSetLs;
    StringUtils::regexSplit(followSet, followSetLs, "\n");
    removeComment(firstSetLs);
    removeComment(followSetLs);
    int nonTeminateSymbol = -1, productNum = 0;
    for (int i = 0; i < firstSetLs.size(); ++i) {
        string &first = firstSetLs[i];
        string firstTrim = StringUtils::trim(first);
        //cout << "nonTeminateSymbol " << nonTeminateSymbol << endl;
        if (firstTrim == "//") {
            nonTeminateSymbol++;
            continue;
        }
        if (!firstTrim.empty()) {
            vector<string> grammarLs;
            StringUtils::regexSplit(firstTrim, grammarLs, "\\|");
            for (string &grammar:grammarLs) {
                string grammarTrim = StringUtils::trim(grammar);
                int tmp = -1;
                if (findGrammarId(grammarTrim, &tmp)) {
                    //非终结符号--a-->产生式
                    //cout << "tmp = " << tmp << endl;
                    cout << nonTeminateSymbol << "==" << tmp << "==>" << first << endl;
                    parseTbl[nonTeminateSymbol][tmp] = productNum;
                } else {
                    cout << "error " << first << ",grammar=" << grammar << endl;
                }
            }
        }
        //cout << "productNum = " << productNum << endl;
        if (productNum < productTbl.size() && productTbl[productNum][0] == 0) {
            string &follow = followSetLs[productNum];
            // cout << "follow-----------" << follow << endl;
            string followTrim = StringUtils::trim(follow);
            if (!followTrim.empty()) {
                vector<string> grammarLs;
                StringUtils::regexSplit(followTrim, grammarLs, "\\|");
                for (string &grammar:grammarLs) {
                    string grammarTrim = StringUtils::trim(grammar);
                    int tmp = -1;
                    if (findGrammarId(grammarTrim, &tmp)) {
                        //非终结符号--a-->产生式
                        if (parseTbl[nonTeminateSymbol][tmp] != -99) {
                            cout << "******************conflict" << endl;
                        }
                        parseTbl[nonTeminateSymbol][tmp] = productNum;
                    } else {
                        cout << "error follow line " << productNum << " " << followTrim << ",grammar=" << grammar
                             << endl;;
                    }
                }
            }
        }
        productNum++;
    }
}

void GlobalTbl::removeComment(vector<string> &tbl) {
    for (auto it = tbl.begin(); it != tbl.end();) {
        if (StringUtils::trim(*it)[0] == '#')
            it = tbl.erase(it);    //删除元素，返回值指向已删除元素的下一个位置
        else
            ++it;    //指向下一个位置
    }
}

void GlobalTbl::printParseTbl() {
    for (int i = 0; i < 80; ++i) {
        for (int j = 0; j < 128; ++j) {
            if (parseTbl[i][j] == END_STATE_NUM) {
                cout << " ";
            } else {
                cout << (int) parseTbl[i][j];
            }
            cout << " ";
        }
        cout << endl;
    }
}

const vector<int> &GlobalTbl::getProduct(const size_t &grammarId, const size_t &terminatedId) {
    int productId = parseTbl[grammarId - 100][terminatedId];
    cout << "next product is " << grammarId << "," << terminatedId << "==>" << productId << endl;
    return productTbl[productId];
}

bool GlobalTbl::getKeyWord(const size_t &id, string &output) {
    return findInMap<string, char>(keyWordMap, id, &output);
}

bool GlobalTbl::getGrammar(const size_t &id, string &output) {
    return findInMap<string, int>(grammarTbl, id, &output);
}

bool GlobalTbl::getKeyWordOrGrammar(const size_t &id, string &output) {
    return getGrammar(id, output) || getKeyWord(id, output);
}

void GlobalTbl::printProduct(const vector<int> &product) {
    cout << "-->";
    for (const int &g:product) {
        cout << g << " ";
    }
    cout << endl;
}

void GlobalTbl::initTbl() {
    memset(parseTbl, END_STATE_NUM, 80 * 128);
}


GlobalTbl::GlobalTbl() {
    initTbl();
}
