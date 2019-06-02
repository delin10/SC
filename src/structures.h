//
// Created by delinoz on 19-6-1.
//

#ifndef SC_STRUCTURES_H
#define SC_STRUCTURES_H

#include <string>

using std::string;

struct LineInfo {
    int rowNum;
    string srcFileName;

    LineInfo(int rowNum, string srcFileName);

    LineInfo();
};

struct Token {
    Token();

    int id;
    string word;
    LineInfo lineInfo;

    Token(int id, string word, int rowNum, string srcFileName);

    ~Token(void);
};

struct StateEdge {
    char start;//起始状态
    char end;//结束状态
    bool range;//true 表示是范围 ranges[n][0]-ranges[n][1];false表示非范围，值取ranges[0][0]
    bool all;
    bool notPrefix;
    char ranges[3][2];

    StateEdge(char start, char end);
};
#endif //SC_STRUCTURES_H
