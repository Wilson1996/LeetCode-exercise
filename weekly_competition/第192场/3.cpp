/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-07 11:31:36
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-07 11:36:43
*/
class BrowserHistory
{
private:
    vector<string> mHistory;
    int cur;
public:
    BrowserHistory(string homepage)
    {
        mHistory.push_back(homepage);
        cur = 0;
    }

    void visit(string url)
    {
        mHistory.resize(cur + 1);
        mHistory.push_back(url);
        ++cur;
    }

    string back(int steps)
    {
        cur = max(cur - steps, 0);
        return mHistory[cur];
    }

    string forward(int steps)
    {
        int _size = mHistory.size();
        cur = min(cur + steps, _size - 1);
        return mHistory[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */