class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0 || intervals.size() == 1) return intervals;
        
        int u = 0, v = 0;
        vector<vector<int>> ans;
        
        std::sort(intervals.begin(), intervals.end());
        
        while (v < intervals.size()) { 
            if (intervals[v][0] > intervals[u][1]) {
                ans.emplace_back(intervals[u]);
                u = v;
            } else if (intervals[v][1] <= intervals[u][1]) {
                ++ v;
            } else {
                intervals[u][1] = intervals[v][1];
                ++ v;
            }
        }
        
        ans.emplace_back(intervals[u]);
        return ans;
    }
};

/*
56. 合并区间
给出一个区间的集合，请合并所有重叠的区间。

 

示例 1:

输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: intervals = [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
注意：输入类型已于2019年4月15日更改。 请重置默认代码定义以获取新方法签名。

 

提示：

intervals[i][0] <= intervals[i][1]
*/
