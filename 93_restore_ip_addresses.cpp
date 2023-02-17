class Solution {
public:
    vector<string> restoreIpAddresses(string& s) {
        if (s.size() > 12 || s.size() < 4) {
            return {};
        }

        vector<string> ans = {};
        vector<string> tmp = {};
        genBytes(ans, tmp, s, 0);

        return ans;
    }

    void genBytes(vector<string>& ans, vector<string>& bytes, const string& s, int pos) {

        if (bytes.size() == 4 && pos == s.size()) {
            ans.push_back(bytes[0] + "." + bytes[1] + "." + bytes[2] + "." + bytes[3]);
            return;
        }else if (bytes.size() == 4 || pos == s.size()) {
            return;
        }
        
        int num{0};
        for (int i = 0; i < 3 && pos + i < s.size(); ++i) {
            num = num*10 + (s[pos+i]-'0');
            if (num <= 255) {
                bytes.push_back(s.substr(pos, i+1));
                genBytes(ans, bytes, s, pos+i+1);
                bytes.pop_back();
            }
            if (num == 0) {
                break;
            }
        }   
    }

};
