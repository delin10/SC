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

typedef struct Node {
    string symbol;
    int num = -1;
    vector<Node> children;
} Node;

class SNLParse {
private:
    vector<int> parseStack;
    vector<Node *> nodeStack;
    SNLLex *lexer;
    size_t cursor;
    Node root;
    const int START_GRAMMAR_ID = 100;
public:
    SNLParse(SNLLex *lexer);

    void initParser();

    bool getNextToken(Token &output);

    void pushToParseStack(vector<int> product);

    int popFromParseStack();

    int parse();


    void pushToNodeStack(Node *node);

    void pushChildrenToNodeStack(const vector<Node> &nodes);

    bool popFromNodeStack(Node *&node);

    void setNodeSymbol(Node &node, const int &id);

    void addAll(Node &node, const vector<int> &children);

    void levelOrder();

};


#endif //SC_SNLPARSE_H
