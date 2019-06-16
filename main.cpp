#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <termio.h>
#include "src/debug.h"
#include "src/Utils.h"
#include "src/SNLLex.h"
#include "src/SNLParse.h"
#include "src/GlobalTbl.h"
#include "src/StringUtils.h"

GlobalTbl globalTbl;

#include <termio.h>

/*
 * 得到用户输入的一个字符
 *        : 返回得到字符
 */
int getch(void) {
    int cr;
    struct termios nts, ots;

    if (tcgetattr(0, &ots) < 0) // 得到当前终端(0表示标准输入)的设置
        return EOF;

    nts = ots;
    cfmakeraw(&nts); // 设置终端为Raw原始模式，该模式下所有的输入数据以字节为单位被处理
    if (tcsetattr(0, TCSANOW, &nts) < 0) // 设置上更改之后的设置
        return EOF;

    cr = getchar();
    if (tcsetattr(0, TCSANOW, &ots) < 0) // 设置还原成老的模式
        return EOF;

    return cr;
}

int main() {
    string stateTbl = "resources/StateTbl.txt";
    string keyword = "resources/KeyWords.txt";
    string border = "resources/Border.txt";
    string cmp = "resources/Cmp.txt";
    SNLLex lexer("resources/snl/bubble.snl");
    globalTbl.setKeyWord(keyword);
    globalTbl.setLexTbl(stateTbl);
    globalTbl.setCmp(cmp);
    globalTbl.setBorder(border);
    SNLParse parser(&lexer);
    string grammarFile = "resources/Grammar.txt";
    string productFile = "resources/Product.txt";
    string productHeadFile = "resources/ProductHead.txt";
    globalTbl.setGrammarTbl(grammarFile);
    globalTbl.setProductTbl(productFile);
    globalTbl.setProductMapper(productHeadFile);
    globalTbl.setParseTbl();
    lexer.sourceStream();
    string ss;
    cout << "lex success! next phrase is parse. please press enter key two times to enter next phrase. " << endl;
    getch();
    parser.parse();
    cout << "next phrase: generate dot file. please press enter key two times to enter next phrase." << endl;
    getch();
    parser.levelOrder();
    cout << "next phrase:  using graphviz generate tree image. " << endl;
    system("dot -Tpng output/tree.dot -o output/tree.png");
    system("ls output");
//    char buf[1024] = {0};
//    int fd[2];
//    int backfd;
//    pipe(fd);
//    backfd = dup(STDOUT_FILENO);//备份标准输出，用于恢复
//    dup2(fd[1], STDOUT_FILENO);  //将标准输出重定向到fd[1]
//    read(fd[0], buf, 1024);
//    dup2(backfd, STDOUT_FILENO);  //恢复标准输出
//    cout << buf << endl; //上面不恢复，则此处的执行结果无法再屏幕上打印
    cout << "succeed to generate tree.png" << endl;
    return 0;
}