//
// Created by delinoz on 19-6-1.
//
#include <cstdarg>
#include "Utils.h"

string readFileAsString(string szFileName) {
    string szFileContent = "";
    FILE *fp = fopen(szFileName.c_str(), "rt");

    if (fp == NULL) {
        return "";
    }

    int i = 1;
    char Buffer[1];

    while (i == 1) {
        i = fread(Buffer, 1, 1, fp);

        if (i == 1) {
            szFileContent.push_back((char) Buffer[0]);
        }
    }

    fclose(fp);
    return szFileContent;
}

void writeLine(string &line, FILE *fp) {
    fputs(line.c_str(), fp);
    fputc('\n', fp);
}

void writeLine(char *line, FILE *fp) {
    fputs(line, fp);
    fputc('\n', fp);
}

void writeLine(FILE *fp, int num, ...) {
    va_list argLs;
    va_start(argLs, num);
    for (int i = 0; i < num; ++i) {
        fputs(va_arg(argLs, char *), fp);
    }
    fputc('\n', fp);
    va_end(argLs);
}