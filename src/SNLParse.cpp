//
// Created by delinoz on 19-6-7.
//

#include <stdio.h>
#include "SNLParse.h"
#include "Utils.h"
#include "StringUtils.h"
#include "GlobalTbl.h"

extern GlobalTbl globalTbl;

SNLParse::SNLParse(SNLLex *lexer) {
    this->lexer = lexer;
}

void SNLParse::pushToParseStack(vector<int> product) {
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
    parseStack.push_back(START_GRAMMAR_ID);
    setNodeSymbol(root, START_GRAMMAR_ID);
    pushToNodeStack(&root);
    cursor = 0;
}

bool SNLParse::getNextToken(Token &output) {
    return lexer->getTokenAt(output, cursor++);
}

int SNLParse::parse() {
    initParser();
    Token token;
    bool hasNextToken = getNextToken(token);
    Node *node;
    while (hasNextToken && !parseStack.empty()) {
        int topVal = popFromParseStack();
        popFromNodeStack(node);
        cout << "input : " << token.word << "," << token.id << endl;
        string str;
        globalTbl.getKeyWordOrGrammar(topVal, str);
        //cout << "stack topVal : " << topVal << endl;
        //cout << "node is " << node->symbol << endl;
        cout << "stack top : " << str << endl;
        cout << "parseStack Size:" << parseStack.size() << "," << "node stack size:" << nodeStack.size() << endl;
        //遇到0产生式,并未发生pop
        if (parseStack.size() != nodeStack.size()) {
            cout << "?????????????????????????????????" << endl;
            exit(1);
        }
//        if (token.word == ".") {
//            break;
//        }
        if (topVal >= 100) {
            const vector<int> &product = globalTbl.getProduct(topVal, token.id == 38 ? 1 : token.id);
            addAll(*node, product);
            pushChildrenToNodeStack(node->children);
            //globalTbl.printProduct(product);
            pushToParseStack(product);
        } else if (0 < topVal && topVal < 100) {
            cout << "output-------------->" << token.word << " " << endl << endl;
            Node valueNode;
            valueNode.symbol = token.word;
            node->children.push_back(valueNode);
            hasNextToken = getNextToken(token);
            cout << "next token:(" << token.id << "," << token.word << ")" << " " << token.lineInfo.srcFileName << ":"
                 << token.lineInfo.rowNum << endl;
        }
        cout << "parse stack :[";
        for (int x:parseStack) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }
    if (token.word != ".") {
        cout << "complex error occurred! I don't know how to report the position..." << endl;
        exit(-1);
    }
    cout << "parse success!!" << endl;
}

void SNLParse::pushToNodeStack(Node *node) {
    nodeStack.push_back(node);
}

void SNLParse::pushChildrenToNodeStack(const vector<Node> &nodes) {
    auto it = nodes.begin();
    for (int i = nodes.size() - 1; i >= 0; --i) {
        nodeStack.push_back((Node *) (it + i).base());
    }
}

bool SNLParse::popFromNodeStack(Node *&node) {
    if (nodeStack.empty()) {
        return false;
    }
    node = nodeStack.back();//在空容器调用未定义行为
    nodeStack.pop_back();
    return true;
}

void SNLParse::setNodeSymbol(Node &node, const int &id) {
    string output;
    globalTbl.getKeyWordOrGrammar(id, output);
    node.symbol = output;
}

void SNLParse::addAll(Node &node, const vector<int> &children) {
//    if (children[0] == 0) {
//        return;
//    }
//    cout << "addAll ";
    for (int i = 0; i < children.size(); ++i) {
        const int &child = children[i];
        Node newChild;
        setNodeSymbol(newChild, child);
//        cout << "[" << newChild.symbol << "]";
        node.children.push_back(newChild);
    }
//    cout << "" << endl;
}

void SNLParse::levelOrder() {
    map<string, int> mapper;
    FILE *fp = fopen("output/tree.dot", "w+");
    string str = "graph tree{";
    writeLine(str, fp);
    cout << "level order" << endl;
    vector<Node *> queue;
    queue.push_back(&root);
    Node *node;
    int count = 0;
    while (!queue.empty()) {
        pop_front<Node *>(queue, node);
        push_back_all(queue, node->children);
        int countParent = 0;
        if (node->symbol == "\"\"") {
            node->symbol = "null";
            //continue;
        }
//        if (!findInMap<string, int>(mapper, node->symbol, &countParent)) {
//            mapper.insert(pair<string, int>(node->symbol, countParent));
//        } else {
//            mapper.find(node->symbol)->second = countParent + 1;
//        }
        if (node->num < 0) {
            node->num = count++;
        }
        for (Node &child:node->children) {
            int countChild = 0;
            if (child.num < 0) {
                child.num = count++;
            }
//            cout << node->symbol + StringUtils::intToString(node->num) << "------->"
//                 << child.symbol + StringUtils::intToString(child.num) << endl;
//            if (!findInMap<string, int>(mapper, child.symbol, &countChild)) {
//                mapper.insert(pair<string, int>(child.symbol, countChild));
//            } else {
//                mapper.find(child.symbol)->second = countChild + 1;
//            }
            if (child.symbol == "\"\"") {
                child.symbol = "null";
                //  continue;
            }


            str = "\"" + node->symbol + "\\n[" + StringUtils::intToString(node->num) + "]\"" + "--\"" + child.symbol +
                  "\\n[" +
                  StringUtils::intToString(child.num) + "]\";";
            writeLine(str, fp);
        }
    }
    writeLine("}", fp);
    fclose(fp);
}