//
// Created by delinoz on 19-5-22.
//

#ifndef DIM_STRINGUTILS_H
#define DIM_STRINGUTILS_H

#include <string>
#include <vector>
#include <regex>

using std::string;
using std::vector;

class StringUtils {
public:
    static string trim(string &src);

    static string ltrim(string &src);

    static string rtrim(string &src);

    static string toUpperCase(string &str);

    static string toLowerCase(string &str);

    static bool isUpperCase(char ch);

    static bool isLowerCase(char ch);

    static bool isWhiteSpace(char ch);

    static void regexSplit(string &input, vector<string> &container, string regex);

    static int toInt(string str);

    static long toLong(string str);


    static string intToString(int intValue);
};


#endif //DIM_STRINGUTILS_H
