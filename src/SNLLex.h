//
// Created by delinoz on 19-6-1.
//

#ifndef SC_SNLLEX_H
#define SC_SNLLEX_H

#include <string>
#include <map>
#include <vector>
#include "structures.h"

#define END_STATE_NUM -99
using std::string;
using std::map;
using std::vector;

class SNLLex {
private:
    char lexTbl[50][128];//词法分析表
    map<string, char> keyWordMap;
    vector<Token> tokenList;
    string fileName;
    string buffer;
    int cursor, curState, rowNum;

public:
    SNLLex(string fileName);

    void setLexTbl(string &str);

    void setKeyWord(string &word);

    void resolveToken(string &sourceCode);

    void sourceStream();

    void skipComment(string &sourceCode);

    void skipWhiteChar(string &sourceCode);

    int getCurState(string &sourceCode);

    bool isTokenTerminatedState();

    void resetState();

    void resetBuffer();

    void back();

    void addToTokenList();

    int getTokenId();

    int findKeyWordTokenId();

    void printLexTbl();

    ~SNLLex();
};


#endif //SC_SNLLEX_H
