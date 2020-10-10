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
        cout << "[";
        for(auto& x : v) {
            cout << x << ", ";
        }
        // cout << "\b\b";
        cout << "]";
        return *this;
    }
    template<typename T>
    Debug& operator<<(const vector<vector<T>>& v) {
        // cout << "[";
        for(auto& x : v) {
        	// cout << "\n";
            operator<<(x);
            cout << ", \n";
        }
        // cout << "\n]";
        return *this;
    }
    Debug& operator<<(const int& v) {
        cout << v;
        return *this;
    }
    Debug& operator<<(const long& v) {
        cout << v;
        return *this;
    }
    Debug& operator<<(const char& v) {
        cout << v;
        return *this;
    }
    Debug& operator<<(const long long& v) {
        cout << v;
        return *this;
    }
    Debug& operator<<(const double& v) {
        cout << v;
        return *this;
    }
    Debug& operator<<(const float& v) {
        cout << v;
        return *this;
    }
    Debug& operator<<(const unsigned int& v) {
        cout << v;
        return *this;
    }
    Debug& operator<<(const unsigned long& v) {
        cout << v;
        return *this;
    }
    Debug& operator<<(const unsigned long long& v) {
        cout << v;
        return *this;
    }
    Debug& operator<<(const unsigned char& v) {
        cout << v;
        return *this;
    }
    Debug& operator<<(const string& v) {
        cout << v;
        return *this;
    }
    template<typename K, typename V>
    Debug& operator<<(const unordered_map<K, V>& v) {
        cout << "{";
        for(auto& kv : v) {
            *this << kv.first << ": " << kv.second << ", ";
        }
        // cout << "\b\b";
        cout << "}";
        return *this;
    }

    template<typename K, typename V>
    Debug& operator<<(const map<K, V>& v) {
        cout << "{";
        for(auto& kv : v) {
            *this << kv.first << ": " << kv.second << ", ";
        }
        // cout << "\b\b";
        cout << "}";
        return *this;
    }

    template<typename K>
    Debug& operator<<(const unordered_set<K>& v) {
        cout << "{";
        for(auto& kv : v) {
            *this << kv << ", ";
        }
        // cout << "\b\b";
        cout << "}";
        return *this;
    }

    template<typename K>
    Debug& operator<<(const set<K>& v) {
        cout << "{";
        for(auto& kv : v) {
            *this << kv << ", ";
        }
        // cout << "\b\b";
        cout << "}";
        return *this;
    }
};

#endif /* __DEBUG_H */