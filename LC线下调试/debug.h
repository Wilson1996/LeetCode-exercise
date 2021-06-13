#ifndef __DEBUG_H
#define __DEBUG_H
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

struct Debug {
    template<typename T>
    Debug& operator<<(const vector<T>& v) {
        cerr << "[";
        for(int i = 0; i < (int)v.size(); ++i) {
            if(i == 0) cerr << v[i];
            else cerr << ", " << v[i];
        }
        cerr << "]";
        return *this;
    }
    template<typename T>
    Debug& operator<<(const vector<vector<T>>& v) {
        // cerr << "[";
        for(int i = 0; i < (int)v.size(); ++i) {
            if(i == 0) operator<<(v[i]);
            else {
                cerr << ",\n";
                operator<<(v[i]);
            }
        }
        // cerr << "\n]";
        return *this;
    }
    Debug& operator<<(const int& v) {
        cerr << v;
        return *this;
    }
    Debug& operator<<(const long& v) {
        cerr << v;
        return *this;
    }
    Debug& operator<<(const char& v) {
        cerr << v;
        return *this;
    }
    Debug& operator<<(const long long& v) {
        cerr << v;
        return *this;
    }
    Debug& operator<<(const double& v) {
        cerr << v;
        return *this;
    }
    Debug& operator<<(const float& v) {
        cerr << v;
        return *this;
    }
    Debug& operator<<(const unsigned int& v) {
        cerr << v;
        return *this;
    }
    Debug& operator<<(const unsigned long& v) {
        cerr << v;
        return *this;
    }
    Debug& operator<<(const unsigned long long& v) {
        cerr << v;
        return *this;
    }
    Debug& operator<<(const unsigned char& v) {
        cerr << v;
        return *this;
    }
    Debug& operator<<(const string& v) {
        cerr << v;
        return *this;
    }
    template<typename K, typename V>
    Debug& operator<<(const unordered_map<K, V>& v) {
        cerr << "{";
        for(auto& kv : v) {
            *this << kv.first << ": " << kv.second << ", ";
        }
        cerr << "}";
        return *this;
    }

    template<typename K, typename V>
    Debug& operator<<(const map<K, V>& v) {
        cerr << "{";
        for(auto& kv : v) {
            *this << kv.first << ": " << kv.second << ", ";
        }
        cerr << "}";
        return *this;
    }

    template<typename K>
    Debug& operator<<(const unordered_set<K>& v) {
        cerr << "{";
        int cnt = 0;
        for(auto& kv : v) {
            if(cnt == 0) *this << kv;
            else {
                cerr << ", ";
                *this << kv;
            }
            ++cnt;
        }
        cerr << "}";
        return *this;
    }

    template<typename K>
    Debug& operator<<(const set<K>& v) {
        cerr << "{";
        int cnt = 0;
        for(auto& kv : v) {
            if(cnt == 0) *this << kv;
            else {
                cerr << ", ";
                *this << kv;
            }
            ++cnt;
        }
        cerr << "}";
        return *this;
    }
};

#endif /* __DEBUG_H */