class Solution {
public:
    int firstUniqChar(string s) {
        
        map<char, int> count;
        
        for (auto i = 0; i < s.size(); i++) {           
            if (count.find(s[i]) == count.end()) {
                count[s[i]] = 1;
            } else {
                count[s[i]] += 1;
            }
        }

        for (auto i = 0; i < s.size(); i++) {
            if (count[s[i]] == 1) return i;
        }

        
        return -1;
    }
};
