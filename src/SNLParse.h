//
// Created by delinoz on 19-6-7.
//

#ifndef SC_SNLPARSE_H
#define SC_SNLPARSE_H

#include <map>
#include <string>
#include <vector>
#include "debug.h"
#include "SNLLex.h"

using std::map;
using std::string;
using std::vector;

class SNLParse {
private:
    vector<int> parseStack;
    SNLLex *lexer;
    size_t cursor;
public:
    SNLParse(SNLLex *lexer);

    void initParser();

    bool getNextToken(Token &output);

    void pushToParseStack(vector<int> product);

    int popFromParseStack();

    int parse();

};


#endif //SC_SNLPARSE_H
