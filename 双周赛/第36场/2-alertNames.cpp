/*
* @Author: wilson_t
* @Date:   2020-10-03 20:22:21
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-04 17:57:05
*/
/*
力扣公司的员工都使用员工卡来开办公室的门。每当一个员工使用一次他的员工卡，安保系统会记录下员工的名字和使用时间。
如果一个员工在一小时时间内使用员工卡的次数大于等于三次，这个系统会自动发布一个 警告 。
给你字符串数组 keyName 和 keyTime ，其中 [keyName[i], keyTime[i]] 对应一个人的名字和他在 某一天 内使用员工卡的时间。
使用时间的格式是 24小时制 ，形如 "HH:MM" ，比方说 "23:51" 和 "09:49" 。
请你返回去重后的收到系统警告的员工名字，将它们按 字典序升序 排序后返回。
请注意 "10:00" - "11:00" 视为一个小时时间范围内，而 "23:51" - "00:10" 不被视为一小时内，因为系统记录的是某一天内的使用情况。

提示：
1 <= keyName.length, keyTime.length <= 105
keyName.length == keyTime.length
keyTime 格式为 "HH:MM" 。
保证 [keyName[i], keyTime[i]] 形成的二元对 互不相同 。
1 <= keyName[i].length <= 10
keyName[i] 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period
*/
class Solution {
public:
    bool check(vector<string>& time) {
        sort(time.begin(), time.end());
        int m = time.size();
        if(m < 3) return false;
        for(int i = 2; i < m; ++i) {
            int h1 = (time[i - 2][0] - '0') * 10 + (time[i - 2][1] - '0');
            int h2 = (time[i][0] - '0') * 10 + (time[i][1] - '0');
            int m1 = (time[i - 2][3] - '0') * 10 + (time[i - 2][4] - '0');
            int m2 = (time[i][3] - '0') * 10 + (time[i][4] - '0');
            if((h1 == h2) || (h1 == h2 - 1 && m1 >= m2)) return true;
        }
        return false;
    }
    vector<string> alertNames(vector<string>& name, vector<string>& time) {
        vector<string> res;
        int n = name.size();
        map<string, vector<string>> mp;
        for(int i = 0; i < n; ++i) {
            mp[name[i]].emplace_back(time[i]);
        }
        for(auto& p : mp) {
            if(check(p.second)) res.emplace_back(p.first);
        }
        return res;
    }
};