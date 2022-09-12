class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs = {};
        
        auto strt = path.begin()+1;
        while (strt < end(path)) {
            
            auto nxt = find(strt, end(path), '/');
            
            auto s = string(strt, nxt);
            
            if (s == "..") {
                if (!dirs.empty()) {
                     dirs.pop_back();
                }
            } else if (!s.empty() && s != ".") {
                dirs.push_back(s);
            }
            
            strt = ++nxt;
        }
        
        stringstream ss;
        for (auto d: dirs) {
            ss << "/" << d;
        } 
        if (ss.str().empty()) {
            ss << "/";
        }
        return ss.str();
    }
};
