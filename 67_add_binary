class Solution {
public:
    string addBinary(string a, string b) {
        if (b.size() > a.size()) {
            std::swap(a, b);
        }
        
        string res;
        
        int c = 0;       
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0; --i, --j) {
            int va = a[i] - '0';
            int vb = (j >= 0 ? b[j] : '0') - '0';
            
            int s = (va + vb + c);
            c = s / 2;
            
            res.append(s % 2 ? "1" : "0");
        }
        
        if (c > 0) {
            res.append("1");
        }
        std::reverse(res.begin(), res.end());
        
        return res;
    }
};
