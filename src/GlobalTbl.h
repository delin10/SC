//
// Created by delinoz on 19-6-7.
//

#ifndef SC_GLOBALTBL_H
#define SC_GLOBALTBL_H

#include <string>
#include <map>
#include <vector>
#include "structures.h"

#define END_STATE_NUM -99

using std::string;
using std::map;
using std::vector;

class GlobalTbl {
private:
    char lexTbl[50][128];//词法分析表
    char parseTbl[80][128];//语法分析表
    map<string, int> grammarTbl;
    vector<vector<int>> productTbl;
    map<string, char> keyWordMap;

    void initTbl();

public:
    GlobalTbl();

    void setLexTbl(string &file);

    void setKeyWord(string &file);

    void setBorder(string &file);

    void setCmp(string &file);

    void setGrammarTbl(string &file);

    void setProductTbl(string &file);

    bool findGrammarId(string &grammar, int *tmp);

    void setParseTbl();

    int findKeyWordTokenId(string &keyword);

    int getState(int from, int to);

    const vector<int> &getProduct(const size_t &grammarId, const size_t &terminatedId);

    bool getKeyWordOrGrammar(const size_t &id, string &output);

    bool getGrammar(const size_t &id, string &output);

    bool getKeyWord(const size_t &id, string &output);

    void printProduct(const vector<int> &product);

    void printParseTbl();

    void removeComment(vector<string> &tbl);
};


#endif //SC_GLOBALTBL_H
