static int _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty() || s.size() == 0) {
            return {};
        }
        
        int wlen = words.at(0).size();
        int wnum = words.size();
        int wtotal = wnum*wlen;
        int slen = s.size();
        
        vector<int> res = {};
        
        std::unordered_map<string, int> whash = {};
        for (string& w: words) {
                whash[w]++;
        }
                
        for (int i = 0; i + wtotal <= slen ; ++i) {
                        
            std::unordered_map<string, int> tmp = {};
   
            for (int j = wnum - 1; j >= 0; --j) {
                string ss = s.substr(i + j*wlen, wlen);

                if (whash.find(ss) == whash.end()) {
                    break;
                }
                
                if (whash[ss] < 1 + tmp[ss]) {
                    i = i + j*wlen;
                    break;
                } else if (j == 0) {
                    
                    res.push_back(i);
                } else {
                    tmp[ss]++;
                }
            }
        }

        return res;
    }
};
