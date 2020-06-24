// 38_count_and_say.cpp

class Solution {
private:
    vector<int> say(vector<int> current, int n) {

        if (n > 1) {
          
            vector<int> ans = {};
            vector<int> buf = {};
            for(auto it = current.begin(); it != current.end(); ++it) {
                if (buf.empty() || *it == buf.at(0)) {
                    buf.push_back(*it);
                    continue;
                }
                
                ans.push_back(buf.size());
                ans.push_back(buf.at(0));
                buf.clear();
                buf.push_back(*it);
  
            }
            
            if (!buf.empty()) {
                ans.push_back(buf.size());
                ans.push_back(buf.at(0));
            }
            
            return say(ans, --n);
        } 
        return current;
    }
    
public:
    string countAndSay(int n) {
        vector<int> ans = say({1}, n);
        ostringstream s;
        copy(ans.begin(), ans.end(), ostream_iterator<int>(s));
             
        return s.str();
    }
};
