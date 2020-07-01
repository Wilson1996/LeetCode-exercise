/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-13 20:59:31
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-13 22:42:57
*/
class SubrectangleQueries
{
private:
    vector<vector<int>> _rect;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : _rect(rectangle)
    {
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
    {
        for(int i = row1; i < row2; ++i)
        {
            for(int j = col1; j < col2; ++j)
                _rect[i][j] = newValue;
        }
    }

    int getValue(int row, int col)
    {
        return _rect[row][col];
    }
};
