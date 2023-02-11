class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        vector<int> curr = {n};
        factor(ans, curr);
        return ans;
    }


    void factor(vector<vector<int>>& ans, vector<int>& curr) {
        if (curr.size() > 1) {
            ans.push_back(curr);
        }

        int val = curr.back();
        curr.pop_back();

        int start = curr.empty() ? 2 : curr.back();
        for (int i = start; i <= val/i; i++) {
            if (val%i == 0) {
                curr.push_back(i);
                curr.push_back(val/i);
                cout << curr.size() << endl;
                factor(ans, curr);
                curr.pop_back();
                curr.pop_back();
            }
            
            
        }
        curr.push_back(val);
    }
};
