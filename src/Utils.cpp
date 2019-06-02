//
// Created by delinoz on 19-6-1.
//
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