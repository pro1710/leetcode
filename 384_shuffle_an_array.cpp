class Solution {

vector<int> initial_;
vector<int> curr_;

public:
    Solution(vector<int>& nums) : initial_(nums), curr_(nums)
    {
        srand((long long int)&nums); 
    }
    
    vector<int> reset() {
        return initial_;
    }
    
    vector<int> shuffle() {
        
        unsigned r = (unsigned long long)(this) % 100000;
        for (int i  = 0; i < curr_.size(); ++i) {
            int j = i + rand() % (curr_.size() - i);
            // unsigned j = (r + abs(curr_[i%curr_.size()]) + (unsigned long long)&r % r) % curr_.size();
            swap(curr_[i], curr_[j]);
        }
        return curr_;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
