class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int> table(128, 0);

        for (auto& c: t) {
           table[c] += 1;
        }

        int b = 0;
        int e = 0;
        int cnt = t.size();
        int wsize = s.size() + 1;
        int wbegin = 0;

        while (e < s.size()) {
            if (table[s[e]] > 0) {
                cnt--;
            }
            table[s[e]]--;
            e++;

            while (cnt == 0) {
                if (e - b < wsize) {
                    wsize = e - b;
                    wbegin = b;
                }

                if (table[s[b]] == 0) {
                    cnt++;
                }
                table[s[b]]++;
                b++;
                
            }
            
        }
        return wsize == s.size()+1 ? "" : s.substr(wbegin, wsize);
       
    }
};
