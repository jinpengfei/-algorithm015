class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.empty())
            return 0;
        int size = height.size();
        vector<int> left_max(size);
        vector<int> right_max(size);
        int ans=0;
        left_max[0] = height[0];
        for(int i=1;i<size;i++)
        {
            left_max[i] = max(left_max[i-1],height[i]);
        }
        right_max[size-1]=height[size-1];
        for(int i=size-2;i>=0;i--)
        {
            right_max[i] = max(right_max[i+1],height[i]);
        }
        for(int i=1;i<size-1;i++)
        {
            ans += min(right_max[i],left_max[i]) - height[i];
        }
        return ans;
    }
};
/*思路：
1.核心思路（这个得找到，否则根本不能程序化）：隐含公式是不包括自己的左边最大和右边最大中的最小值-自己本身的高度就是本身能蓄水的多少。最后加起来。
2.统计当前节点左边的最大
3.统计当前节点右边的最大
4.再从第2个和倒数第2个遍历height,按照隐含公式统计每个位置的蓄水，累加，就可以最终确定所有的积水
心得体会：
1掌握一种方法，可以默写，其余能够看懂即可。（5分钟必须判断出自己会不会做，否则就看解法（主要是训练自己快速做抉择能力），因为像看书一样。看几种解法通过题友交叉验证学会思想，但要提交一道题(能总结出很多东西的挑出来)提交到leetcode，做前进行思路分析(用先进的思想，而不是以前的自己的想法)，流水账这种千万不要用）
2数组下标体会：两两比较并平移;一个与随后的比较;一个与之前的比较;下标和含义的不同组合;是每个都要统计还是累加统计
3知识盲点要搞懂

*/
