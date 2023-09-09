/*
* @Author: wilson_t
* @Date:   2020-10-03 20:22:11
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-04 17:55:38
*/
/*
请你给一个停车场设计一个停车系统。停车场总共有三种不同大小的车位：大，中和小，每种尺寸分别有固定数目的车位。
请你实现 ParkingSystem 类：

ParkingSystem(int big, int medium, int small) 初始化 ParkingSystem 类，三个参数分别对应每种停车位的数目。
bool addCar(int carType) 检车是否有 carType 对应的停车位。 carType 有三种类型：大，中，小，分别用数字 1， 2 和 3 表示。
一辆车只能停在  carType 对应尺寸的停车位中。如果没有空车位，请返回 false ，否则将该车停入车位并返回 true 。

提示：
0 <= big, medium, small <= 1000
carType 取值为 1， 2 或 3
最多会调用 addCar 函数 1000 次

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-parking-system
*/
class ParkingSystem {
    int cap[3], now[3];
public:
    ParkingSystem(int _big, int _medium, int _small) {
        cap[0] = _big;
        cap[1] = _medium;
        cap[2] = _small;
        now[0] = now[1] = now[2] = 0;
    }

    bool addCar(int t) {
        if(now[t - 1] == cap[t - 1]) return false;
        now[t - 1]++;
        return true;
    }
};