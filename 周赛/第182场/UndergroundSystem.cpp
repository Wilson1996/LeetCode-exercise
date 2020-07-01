/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-29 11:30:07
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-31 11:55:50
*/
/*********************************************************
* 题目[中等]：
请你实现一个类 UndergroundSystem ，它支持以下 3 种方法：
1. checkIn(int id, string stationName, int t)
	编号为 id 的乘客在 t 时刻进入地铁站 stationName 。
	一个乘客在同一时间只能在一个地铁站进入或者离开。
2. checkOut(int id, string stationName, int t)
	编号为 id 的乘客在 t 时刻离开地铁站 stationName 。
3. getAverageTime(string startStation, string endStation) 
	返回从地铁站 startStation 到地铁站 endStation 的平均花费时间。
	平均时间计算的行程包括当前为止所有从 startStation 直接到达 endStation 的行程。
	调用 getAverageTime 时，询问的路线至少包含一趟行程。
你可以假设所有对 checkIn 和 checkOut 的调用都是符合逻辑的。
也就是说，如果一个顾客在 t1 时刻到达某个地铁站，那么他离开的时间 
t2 一定满足 t2 > t1 。所有的事件都按时间顺序给出。
*********************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#if 0
namespace Design_1
{
	class UndergroundSystem
	{
	private:
		struct Passenger
		{
			int id;
			int startTime;
			int endTime;
			string startStation;
			string endStation;
			Passenger(int i, int s, int e, const string& start, const string& end):
				id(i), startTime(s), endTime(e), startStation(start), endStation(end) {}
		};
		struct PathSection
		{
			string startStation;
			string endStation;
			int nums;
			double averageTime;
		};
		struct PathSectionHash
		{
			size_t operator()(const PathSectionHash& rhs) const
			{
				return hash<string>()(rhs.startStation)
					   ^ hash<string>()(rhs.endStation);
			}
		};
		struct PathSectionCmp
		{
			bool operator()(const PathSection& lhs, const PathSection& rhs) const
			{
				return lhs.startStation == rhs.startStation && lhs.endStation == rhs.endStation;
			}
		};
		unordered_map<int, Passenger> passengers;
		unordered_set<PathSection, PathSectionHash, PathSectionCmp> pathSections;
	public:
		UndergroundSystem()
		{
		}

		void checkIn(int id, string stationName, int t)
		{
			pathSections[id] = Passenger(id, t, 0, stationName, "");
		}

		void checkOut(int id, string stationName, int t)
		{
			pathSections[id].endStation = stationName;
			pathSections[id].endTime = t;
			auto& it = pathSections.find(pathSections[id].startStation, pathSections[id].endStation);
		}

		double getAverageTime(string startStation, string endStation)
		{
		}
	};
}
#endif

namespace Design_2
{
class UndergroundSystem
{
private:
	string getKey(const string& startStation, const string& endStation)
	{
		//将加起来的字符串作为键值
	    return startStation + endStation;
	}

	unordered_map<int, pair<string, int>> checkRecord;
	unordered_map<string, pair<double, int>> count;
public:
	UndergroundSystem() {}

	void checkIn(int id, string stationName, int t)
	{
		checkRecord[id] = { stationName, t };
	}

	void checkOut(int id, string stationName, int t)
	{
		string name = getKey(checkRecord[id].first, stationName);
		t -= checkRecord[id].second;
		count[name].first += (double)t;
		count[name].second += 1;
	}

	double getAverageTime(string startStation, string endStation)
	{
		string name = getKey(startStation, endStation);
		double ans = count[name].first / (double)count[name].second;
		return ans;
	}
};
}

int main(int argc, char* argv[])
{
	Design_2::UndergroundSystem undergroundSystem;
	undergroundSystem.checkIn(45, "Leyton", 3);
	undergroundSystem.checkIn(32, "Paradise", 8);
	undergroundSystem.checkIn(27, "Leyton", 10);
	undergroundSystem.checkOut(45, "Waterloo", 15);
	undergroundSystem.checkOut(27, "Waterloo", 20);
	undergroundSystem.checkOut(32, "Cambridge", 22);
	cout << undergroundSystem.getAverageTime("Paradise", "Cambridge") << endl;
	cout << undergroundSystem.getAverageTime("Leyton", "Waterloo")<< endl; 
	undergroundSystem.checkIn(10, "Leyton", 24);
	cout << undergroundSystem.getAverageTime("Leyton", "Waterloo")<< endl; 
	undergroundSystem.checkOut(10, "Waterloo", 38);
	cout << undergroundSystem.getAverageTime("Leyton", "Waterloo")<< endl;
	return 0;
}