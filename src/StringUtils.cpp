//
// Created by delinoz on 19-5-22.
//
#include "debug.h"
#include "StringUtils.h"

string StringUtils::ltrim(string &src) {
    if (src.empty()) {
        return src;
    }

    string szTmp = "";
    int i;

    for (i = 0; isWhiteSpace(src[i]) && i < src.length(); i++);

    for (; i < src.length(); i++) {
        szTmp.append(1, src[i]);
    }

    return szTmp;
}

string StringUtils::rtrim(string &src) {
    {
        if (src.empty()) {
            return src;
        }

        string szTmp = "";
        int i;
        for (i = src.length() - 1; isWhiteSpace(src[i]) && i >= 0; i--);

        for (int j = 0; j <= i; j++) {
            szTmp.append(1, src[j]);
        }

        return szTmp;
    }
}

string StringUtils::trim(string &src) {
    if (src.empty()) {
        return src;
    }

    string szTmp = "";
    int start, end;
    for (end = src.length() - 1; isWhiteSpace(src[end]) && end >= 0; --end);
    for (start = 0; src[start] <= 32 && start <= end; ++start);

    for (int j = start; j <= end; j++) {
        szTmp.append(1, src[j]);
    }
    return szTmp;
}

string StringUtils::toUpperCase(string &str) {
    string tmp;
    for (char ch:str) {
        tmp.push_back(isLowerCase(ch) ? ch - 32 : ch);
    }
    return tmp;
}

string StringUtils::toLowerCase(string &str) {
    string tmp;
    for (char ch:str) {
        tmp.push_back(isUpperCase(ch) ? ch + 32 : ch);
    }
    return tmp;
}

bool StringUtils::isUpperCase(char ch) {
    return 'A' <= ch && ch <= 'Z';
}

bool StringUtils::isLowerCase(char ch) {
    return 'a' <= ch && ch <= 'z';
}

bool StringUtils::isWhiteSpace(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}

void StringUtils::regexSplit(string &input, vector<string> &container, string seperator) {
    std::regex re(seperator);
    std::sregex_token_iterator p(input.begin(), input.end(), re, -1);
    std::sregex_token_iterator end;
    while (p != end) {
        container.emplace_back(*p++);
    }
}

int StringUtils::toInt(string str) {
    std::stringstream ss;
    ss << str;
    int intValue;
    ss >> intValue;
    return intValue;
}

long StringUtils::toLong(string str) {
    std::stringstream ss;
    ss << str;
    long longValue;
    ss >> longValue;
    return longValue;
}