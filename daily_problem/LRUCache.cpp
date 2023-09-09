/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-25 09:43:19
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-06-08 20:48:43
*/
/*********************************************************
* 题目[中等]：
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。
它应该支持以下操作： 获取数据 get 和 写入数据 put 。
获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥已经存在，则变更其数据值；如果密钥不存在，
则插入该组「密钥/数据值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

进阶:
你是否可以在 O(1) 时间复杂度内完成这两种操作？

示例:
LRUCache cache = new LRUCache( 2 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4
*********************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

struct Node {
    int key;
    int value;
    Node(int k, int v) : key(k), value(v) {}
};
using listIter_node = std::list<Node>::iterator;
class LRUCache {
    unordered_map<int, listIter_node> MP;
    list<Node> cache;
    int capacity;
public:
    LRUCache(int cap): capacity(cap) {
    }

    int get(int key) {
        auto it = MP.find(key);
        if(it == MP.end())
            return -1;
        int val = it->second->value;
        cache.erase(it->second);
        cache.push_front(Node(key, val));
        MP[key] = cache.begin();
        return val;
    }

    void put(int key, int value) {
        if(MP.find(key) != MP.end()) {
            cache.erase(MP[key]);
            cache.push_front(Node(key, value));
            MP[key] = cache.begin();
            return;
        }
        if(cache.size() == capacity) {
            int k_back = cache.back().key;
            cache.pop_back();
            MP.erase(k_back);
        }
        cache.push_front(Node(key, value));
        MP[key] = cache.begin();
    }
};


class Solution {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        unordered_map<int, list<pair<int, int>>::iterator> mp;    //key, iter
        unordered_map<int, int> value2key;    //value to key
        list<pair<int, int>> seq;    //val: (key, value)
        vector<int> res;
        for(auto& v : operators) {
            if(v[0] == 1) {
                if(mp.size() >= k) {
                    if(mp.count(v[1])) {
                        auto old = mp[v[1]];
                        seq.erase(old);
                    } else {
                        auto old = *seq.begin();
                        seq.erase(seq.begin());
                        mp.erase(old.first);
                    }
                }
                auto it = seq.insert(seq.end(), make_pair(v[1], v[2]));
                mp[v[1]] = it;
            } else {
                if(!mp.count(v[1])) {
                    res.emplace_back(-1);
                } else {
                    auto it = mp[v[1]];
                    pair<int, int> kv = *it;
                    seq.erase(it);
                    it = seq.insert(seq.end(), kv);
                    mp[v[1]] = it;
                    res.emplace_back(kv.second);
                }
            }
        }
        return res;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char* argv[]) {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;       // 返回  1
    cache.put(3, 3);                    // 该操作会使得密钥 2 作废
    cout << cache.get(2) << endl;       // 返回 -1 (未找到)
    cache.put(4, 4);                    // 该操作会使得密钥 1 作废
    cout << cache.get(1) << endl;       // 返回 -1 (未找到)
    cout << cache.get(3) << endl;       // 返回  3
    cout << cache.get(4) << endl;       // 返回  4
    return 0;
}