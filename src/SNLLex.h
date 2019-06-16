//
// Created by delinoz on 19-6-1.
//

#ifndef SC_SNLLEX_H
#define SC_SNLLEX_H

#include <string>
#include <map>
#include <vector>
#include "structures.h"

using std::string;
using std::map;
using std::vector;

class SNLLex {
private:
    vector<Token> tokenList;
    string fileName;
    string buffer;
    int cursor, curState, rowNum;

public:
    SNLLex(string fileName);

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

    vector<Token> &getTokenList();

    bool getTokenAt(Token &output, size_t pos);

    void printLexTbl();

    ~SNLLex();
};


#endif //SC_SNLLEX_H
