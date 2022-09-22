class Solution {
public:
       
    int tribonacci(int n) {
        vector<int> tri = {0, 1, 1};
        for (int i = 0; i < n-2; ++i) {
            tri.push_back(tri[i] + tri[i+1] + tri[i+2]);
        }
        return tri[n];
    }
};
