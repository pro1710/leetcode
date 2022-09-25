class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> vs1(26);
        for (auto& c: s1) {
            vs1[c - 'a']++;
        }
        
        vector<int> tmp(26);   
        int e = s1.size()-1;

        for (int i = 0; i < s2.size(); i++) {
            
            tmp[s2[i]-'a']++;
            if (i < e) {
                continue;
            }
            
            if (vs1 == tmp) {
                return true;
            }
            
            tmp[s2[i-e]-'a']--;
        }
        
        return false;
    }
};
