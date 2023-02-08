class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> cLoc[3];

        for (int i = 0; i < colors.size(); ++i) {
            cLoc[colors[i]-1].push_back(i);
        }

        vector<int> ans;
        for (auto& q: queries) {
            auto& locs = cLoc[q[1]-1];
            ans.push_back(closest(locs, q[0]));
        }
        return ans;
    }

    int closest(std::vector<int> const& vec, int value) {
        if (vec.empty()) {
            return -1;
        }
        auto const it = std::lower_bound(vec.begin(), vec.end(), value);
        if (it == vec.end()) { 
            return abs(vec.back()-value); 
        }
        
        if (it == vec.begin()) {
            return abs(*it-value);
        }
        return min(abs(*it-value), abs(*(it-1)-value));
    }

};
