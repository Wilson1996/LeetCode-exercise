/*
* @Author: wilson_t
* @Date:   2020-10-31 08:36:09
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-31 08:37:52
*/
/**
* 题目[困难]：
设计一个支持在平均 时间复杂度 O(1) 下， 执行以下操作的数据结构。
注意: 允许出现重复元素。
insert(val)：向集合中插入元素 val。
remove(val)：当 val 存在时，从集合中移除一个 val。
getRandom：从现有集合中随机获取一个元素。每个元素被返回的概率应该与其在集合中的数量呈线性相关。

示例:
// 初始化一个空的集合。
RandomizedCollection collection = new RandomizedCollection();
// 向集合中插入 1 。返回 true 表示集合不包含 1 。
collection.insert(1);
// 向集合中插入另一个 1 。返回 false 表示集合包含 1 。集合现在包含 [1,1] 。
collection.insert(1);
// 向集合中插入 2 ，返回 true 。集合现在包含 [1,1,2] 。
collection.insert(2);
// getRandom 应当有 2/3 的概率返回 1 ，1/3 的概率返回 2 。
collection.getRandom();
// 从集合中删除 1 ，返回 true 。集合现在包含 [1,2] 。
collection.remove(1);
// getRandom 应有相同概率返回 1 和 2 。
collection.getRandom();

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-delete-getrandom-o1-duplicates-allowed
*/
class RandomizedCollection {
    unordered_map<int, unordered_set<int>> mp;
    vector<int> arr;
    int cnt;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        mp.clear();
        arr.resize(1000);
        cnt = 0;
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(arr.size() == cnt) arr.resize(arr.size() * 2);
        arr[cnt] = val;
        if(mp.find(val) == mp.end()) {
            mp[val].insert(cnt);
            cnt++;
            return true;
        } else {
            mp[val].insert(cnt);
            cnt++;
            return false;
        }
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) != mp.end()) {
            int idx = *(mp[val].begin());
            if(mp[val].size() == 1) {
                mp[arr[cnt - 1]].erase(cnt - 1);
                mp[arr[cnt - 1]].insert(idx);
                arr[idx] = arr[cnt - 1];
                cnt--;
                mp.erase(val);
            } else {
                mp[val].erase(mp[val].begin());
                mp[arr[cnt - 1]].erase(cnt - 1);
                mp[arr[cnt - 1]].insert(idx);
                arr[idx] = arr[cnt - 1];
                cnt--;
            }
            return true;
        }
        return false;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        int idx = rand() % cnt;
        return arr[idx];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */