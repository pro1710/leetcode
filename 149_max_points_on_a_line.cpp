class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int  res = 0;
        for (int i = 0; i < points.size()-1; ++i) {
            unordered_map<double, int> slope;
            for (int j = i+1; j < points.size(); ++j) {
                auto& p1 = points[i];
                auto& p2 = points[j];
                auto& cnt = slope[(p2[0] != p1[0] ? (p2[1]-p1[1])/(double)(p2[0]-p1[0]) : 100001)];
                cnt++;
                res = max(cnt, res);
                
            }
        }
        return res+1;
    }
};
