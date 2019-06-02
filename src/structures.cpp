//
// Created by delinoz on 19-6-1.
//

#include "structures.h"

Token::Token() {}

Token::Token(int id, string word, int rowNum, string srcFileName) {
    this->id = id;
    this->word = word;
    this->lineInfo = LineInfo(rowNum, srcFileName);
}

Token::~Token() {}

LineInfo::LineInfo() {}

LineInfo::LineInfo(int rowNum, string srcFileName) {
    this->rowNum = rowNum;
    this->srcFileName = srcFileName;
}

StateEdge::StateEdge(char start, char end) : start(start), end(end) {
    this->start = start;
    this->end = end;
    this->all = false;
    this->notPrefix = false;
    this->range = false;
}
