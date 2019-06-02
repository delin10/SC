#include <iostream>
#include "src/debug.h"
#include "src/Utils.h"
#include "src/SNLLex.h"

int main() {
    string res = readFileAsString("resources/StateTbl.txt");
    string keyword = readFileAsString("resources/KeyWords.txt");
    SNLLex lexer("resources/src.snl");
    lexer.setLexTbl(res);
    lexer.setKeyWord(keyword);
    lexer.sourceStream();
    return 0;
}