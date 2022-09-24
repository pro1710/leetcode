class Solution {
public:
    
        std::vector<std::vector<int>> threeSum(std::vector<int>& values) {
        
        std::vector< std::vector<int> > res = {};
        if (values.size() < 3) {
            return res;
        }
        
        sort(values.begin(), values.end());

        for (size_t i = 0; i < values.size() - 2; ++i) { 
            int l = i + 1; 
            int r = values.size() - 1; 

            while (l < r) { 
                int tmp = values[i] + values[l] + values[r];
                bool iterateLeft = false, iterateRight = false;
                
                if (tmp == 0) { 
                    res.push_back({values[i], values[l], values[r]});
                    iterateLeft = true;
                    iterateRight = true;
                } else if (tmp < 0) {
                    iterateLeft = true;
                } else {
                    iterateRight = true;
                }
                
                if (iterateLeft) {
                    do {
                        ++l;
                    } while (values[l-1] == values[l] && r > l);
                }
                
                if (iterateRight) {
                    do {
                        --r;     
                    } while (values[r+1] == values[r] && r > l);
                }
            } 
            while (values[i] == values[i+1] && i < values.size() - 2) ++i;
        }  
        return res;
    }

};
