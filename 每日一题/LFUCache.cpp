/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-05 09:46:33
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-08 10:02:32
*/
/*********************************************************
* 题目[困难]：
设计并实现最不经常使用（LFU）缓存的数据结构。它应该支持以下操作：get 和 put。
get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
put(key, value) - 如果键不存在，请设置或插入值。当缓存达到其容量时，
它应该在插入新项目之前，使最不经常使用的项目无效。在此问题中，当存在平局
（即两个或更多个键具有相同使用频率）时，最近最少使用的键将被去除。

进阶：
你是否可以在 O(1) 时间复杂度内执行两项操作？

示例：
LFUCache cache = new LFUCache( 2 );// capacity (缓存容量) //
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回 1
cache.put(3, 3);    // 去除 key 2
cache.get(2);       // 返回 -1 (未找到key 2)
cache.get(3);       // 返回 3
cache.put(4, 4);    // 去除 key 1
cache.get(1);       // 返回 -1 (未找到 key 1)
cache.get(3);       // 返回 3
cache.get(4);       // 返回 4
*********************************************************/
#include <iostream>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

// class LFUCache
// {
// private:
// 	struct Wrap
// 	{
// 		int key;
// 		int value;
// 		unsigned int use_freq;
// 		Wrap(int k, int v) : value(v), use_freq(0) {}
// 		bool operator<(const Wrap& other) const
// 		{
// 			return use_freq < other.use_freq;
// 		}
// 		bool operator>(const Wrap& other) const
// 		{
// 			return use_freq > other.use_freq;
// 		}
// 		bool operator==(const Wrap& other) const
// 		{
// 			return use_freq == other.use_freq;
// 		}
// 	};
// 	struct WrapCmp
// 	{
// 	    bool operator() (Wrap* a, Wrap* b)
// 	    {
// 	        return a->use_freq > b->use_freq;
// 	    }
// 	};
// 	unordered_map<int, Wrap*> cache;
// 	priority_queue<Wrap*, vector<Wrap*>, WrapCmp> LFU_list;
// 	int _capacity;
// public:
// 	LFUCache(int capacity) : _capacity(capacity)
// 	{
// 	}
// 	~LFUCache()
// 	{
// 		for(auto it = cache.begin(); it != cache.end(); ++it)
// 		{
// 			if(it->second != nullptr)
// 				delete it->second;
// 		}
// 	}

// 	int get(int key)
// 	{
// 		if(cache.find(key) == cache.end())
// 			return -1;
// 		else
// 		{
// 			cache[key]->use_freq += 1;
// 			Wrap* tmp = LFU_list.top();
// 			LFU_list.pop();
// 			LFU_list.push(tmp);
// 			return cache[key]->value;
// 		}
// 	}

// 	void put(int key, int value)
// 	{
// 		if(cache.size() == _capacity)
// 		{
// 			Wrap* toDel = LFU_list.top();
// 			cache.erase(toDel->key);
// 			LFU_list.pop();
// 			delete toDel;
// 		}
// 		Wrap* newWrap = new Wrap(key, value);
// 		LFU_list.push(newWrap);
// 		cache[key] = newWrap;
// 	}
// 	void print()const
// 	{
// 		for(auto p: cache)
// 		{
// 			cout << p.first << ": " << p.second->value << endl;
// 		}
// 	}
// };


struct Node
{
	int cnt, time, key, value;

	Node(int _cnt, int _time, int _key, int _value)
		: cnt(_cnt), time(_time), key(_key), value(_value) {}

	bool operator < (const Node& rhs) const
	{
		return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
	}
};
class LFUCache
{
	int capacity, time;
	unordered_map<int, Node> key_table;
	set<Node> S;
public:
	LFUCache(int _capacity)
	{
		capacity = _capacity;
		time = 0;
		key_table.clear();
		S.clear();
	}

	int get(int key)
	{
		if (capacity == 0) return -1;
		auto it = key_table.find(key);
		if (it == key_table.end()) return -1;
		Node cache = it -> second;
		S.erase(cache);
		cache.cnt += 1;
		cache.time = ++time;
		S.insert(cache);
		it -> second = cache;
		return cache.value;
	}

	void put(int key, int value)
	{
		if (capacity == 0) return;
		auto it = key_table.find(key);
		if (it == key_table.end())
		{
			if (key_table.size() == capacity)
			{
				key_table.erase(S.begin() -> key);
				S.erase(S.begin());
			}
			Node cache = Node(1, ++time, key, value);
			key_table.insert(make_pair(key, cache));
			S.insert(cache);
		}
		else
		{
			Node cache = it -> second;
			S.erase(cache);
			cache.cnt += 1;
			cache.time = ++time;
			cache.value = value;
			S.insert(cache);
			it -> second = cache;
		}
	}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char* argv[])
{
	LFUCache cache(2);// capacity (缓存容量) //
	cache.put(1, 1);
	cache.put(2, 2);
	// cache.print();
	cout << cache.get(1) << endl;       // 返回 1
	cache.put(3, 3);    // 去除 key 2
	cout << cache.get(2) << endl;      // 返回 -1 (未找到key 2)
	cout << cache.get(3) << endl;      // 返回 3
	cache.put(4, 4);    // 去除 key 1
	cout << cache.get(1) << endl;      // 返回 -1 (未找到 key 1)
	cout << cache.get(3) << endl;      // 返回 3
	cout << cache.get(4) << endl;	   // 返回 4
	return 0;
}