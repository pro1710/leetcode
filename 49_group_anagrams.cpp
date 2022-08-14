class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<string>> hm = {};
        
        for (auto& str: strs) {
            string s = str;
            sort(begin(s), end(s));
            
            hm[s].push_back(str);
            
        }
        
        vector<vector<string>> res = {};
        
        std::transform(hm.begin(), hm.end(), 
                       std::back_inserter(res),
                       [](std::unordered_map<string, std::vector<string>>::value_type it) {
                          return it.second;
                       }
        );
        
        return res;
    }
};
