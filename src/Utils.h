//
// Created by delinoz on 19-6-1.
//

#ifndef SC_UTILS_H
#define SC_UTILS_H

#include<string>
#include <map>

using std::string;
using std::map;

string readFileAsString(string szFileName);

template<typename K, typename V>
bool findInMap(const map<K, V> &map, const K &key, V *output) {
    //typename std::map<K, V>::iterator iter;
    auto iter = map.find(key);
    if (iter == map.end()) {
        return false;
    }
    *output = iter->second;
    return true;
}

#endif //SC_UTILS_H
