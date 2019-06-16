//
// Created by delinoz on 19-6-1.
//

#ifndef SC_UTILS_H
#define SC_UTILS_H

#include<string>
#include <map>
#include <algorithm>
#include <vector>
#include "debug.h"

using std::string;
using std::map;

string readFileAsString(string szFileName);

void writeLine(string &line, FILE *fp);

void writeLine(char *line, FILE *fp);

void writeLine(FILE *fp, int num, ...);

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

template<typename K, typename V>
bool findInMap(const map <K, V> &map, const K &key, V **output) {
    //typename std::map<K, V>::iterator iter;
    auto iter = map.find(key);
    if (iter == map.end()) {
        return false;
    }
    *output = (V *) &(iter->second);
    return true;
}

template<typename K, typename V>
bool findInMap(const map <K, V> &map, const V &value, K *output) {
    //typename std::map<K, V>::iterator iter;
    auto iter = std::find_if(map.begin(), map.end(),
                             [&value](const typename std::map<K, V>::value_type &e) -> bool {
                                 //cout << e.first << "," << (int) e.second << endl;
                                 return e.second == value;
                             });
    if (iter == map.end()) {
        return false;
    }
    *output = iter->first;
    return true;
}

template<typename E>
bool pop_back(vector<E> &vector, E &output) {
    if (vector.empty()) {
        return false;
    }
    output = vector.back();
    vector.pop_back();
    return true;
}

template<typename E>
bool pop_front(vector<E> &vector, E &output) {
    if (vector.empty()) {
        return false;
    }
    output = vector.front();
    vector.erase(vector.begin());
    return true;
}

template<typename E>
void push_back_all(vector<E *> &to, vector<E> &from) {
    for (auto it = from.begin(); it != from.end(); ++it) {
        to.push_back(&(*it));
    }
}

template<typename E>
void push_back_all(vector<E> &to, vector<E> &from) {
    for (auto it = from.begin(); it != from.end();) {
        to.push_back(*it++);
    }
}

#endif //SC_UTILS_H
