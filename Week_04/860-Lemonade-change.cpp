class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> map;
        for (int i : bills) {
            if (i == 5) map[5] ++;
            else if (i == 10) {map[10] ++, map[5] --;}
            else if (i == 20 && map[10] > 0) {map[10] --, map[5] --;}
            else map[5] -= 3; 
            if(map[5] < 0) return false;
        }
        return true;
    }
};
