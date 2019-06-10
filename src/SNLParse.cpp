//
// Created by delinoz on 19-6-7.
//

#include "SNLParse.h"
#include "Utils.h"
#include "StringUtils.h"
#include "GlobalTbl.h"

extern GlobalTbl globalTbl;

SNLParse::SNLParse(SNLLex *lexer) {
    this->lexer = lexer;
}

void SNLParse::pushToParseStack(vector<int> product) {
    if (product[0] == 0) {
        return;
    }
    for (int i = product.size() - 1; i >= 0; --i) {
        parseStack.push_back(product[i]);
    }
}

int SNLParse::popFromParseStack() {
    int next = -1;
    if (!parseStack.empty()) {
        next = parseStack.back();//在空容器调用未定义行为
        parseStack.pop_back();
    }
    return next;
}

void SNLParse::initParser() {
    parseStack.clear();
    parseStack.push_back(100);
    cursor = 0;
}

bool SNLParse::getNextToken(Token &output) {
    return lexer->getTokenAt(output, cursor++);
}

int SNLParse::parse() {
    initParser();
    Token token;
    bool hasNextToken = getNextToken(token);
    while (hasNextToken && !parseStack.empty()) {
        int topVal = popFromParseStack();
        cout << "input : " << token.word << "," << token.id << endl;
        string str;
        globalTbl.getKeyWordOrGrammar(topVal, str);
        cout << "stack topVal : " << topVal << endl;
        cout << "stack top : " << str << endl;
        if (topVal >= 100) {
            const vector<int> &product = globalTbl.getProduct(topVal, token.id == 38 ? 1 : token.id);
            globalTbl.printProduct(product);
            pushToParseStack(product);
            cout << "parse stack :[";
            for (int x:parseStack) {
                cout << x << " ";
            }
            cout << "]" << endl;
        } else if (0 < topVal && topVal < 100) {
            cout << "-------------->" << token.word << " " << endl;
            hasNextToken = getNextToken(token);
        }
    }
    cout << "parse success!!" << endl;
}