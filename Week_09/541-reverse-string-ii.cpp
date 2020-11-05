class Solution {
    public:
        void reverse(string& s, int start, int end){
            for(int i = start, j=end; i< j; i++, j--)
            {
                swap(s[i],s[j]);
            }
        }
        string reverseStr(string s, int k) {
            for(int i = 0; i< s.size(); i+=2*k)
            {
                if(i+k <= s.size()){
                    reverse(s, i, i+k-1);
                    continue;
                }
                reverse(s,i,s.size() - 1);
            }
            return s;
        }
};

/*
难点识别：
    1.如何确定循环次数
    2.如何确定基本单元和调度结构
        1.识别位置(几种情况：1.经过2k次剩余的小于k 2.经过2k次剩余的大于k；反向理解就是i*2k+k<size)
        2.交换基本单元
        3.特殊情况
        4.定义接口
*/
