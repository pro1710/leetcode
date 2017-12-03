// 11_container_wt_most_water.cpp

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_cont_size = 0, new_size = 0;
        int *lit = &height.data()[0], *rit = &height.data()[height.size()-1];
        // vector<int>::iterator lit = height.begin(), rit = height.end() - 1;
        while (lit < rit) {
            if (*lit > *rit) {
                new_size = (*rit)*(rit-lit);
                --rit;
            } else {
                new_size = (*lit)*(rit-lit);
                ++lit;
            }
            if (new_size > max_cont_size) max_cont_size = new_size;
        }
        return max_cont_size;
    }
};

