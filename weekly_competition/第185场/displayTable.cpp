/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-19 11:25:31
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-19 22:12:01
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static vector<vector<string>> displayTable(vector<vector<string>>& orders)
    {
        set<string> dish;
        set<int> table;
        for(auto& order : orders)
        {
            table.insert(stoi(order[1]));
            dish.insert(order[2]);
        }
        unordered_map<string, int> dish_hash;
        unordered_map<int, int> table_hash;
        int index = 1;
        for(auto& x : dish)
        {
            dish_hash[x] = index;
            ++index;
        }
        index = 1;
        for(auto& x : table)
        {
            table_hash[x] = index;
            ++index;
        }
        vector<vector<string>> result(table.size() + 1, vector<string>(dish.size() + 1, "0"));
        result[0][0] = "table";
        int i = 1;
        for(auto& x : dish)
        {
            result[0][i] = x;
            ++i;
        }
        i = 1;
        for(auto& x : table)
        {
            result[i][0] = to_string(x);
            ++i;
        }
        for(auto& order : orders)
        {
            string tmp = result[table_hash[stoi(order[1])]][dish_hash[order[2]]];
            result[table_hash[stoi(order[1])]][dish_hash[order[2]]] = to_string(stoi(tmp) + 1);
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
	vector<vector<string>> orders = {{"David","3","Ceviche"},{"Corina","10","Beef Burrito"},{"David","3","Fried Chicken"},
		{"Carla","5","Water"},{"Carla","5","Ceviche"},{"Rous","3","Ceviche"}};
	vector<vector<string>> result = Solution::displayTable(orders);
	for(int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			cout << result[i][j] << ",\t";
		}
		cout << endl;
	}
	return 0;
}