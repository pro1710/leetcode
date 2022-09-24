class Solution {
public:
    
    typedef vector<int>::iterator vi_iter;

    bool update(int& min_sum, int& delta, const int& loc_sum, const int& ac, vi_iter low, vi_iter up) {
	    int d_low = abs(ac - (*low));
	    if (!d_low) return true;
	    
        int d_up = abs(ac - (*up));
        if (!d_up) return true;
        
        if (d_low > d_up) {
            if (delta > d_up) {
                delta = d_up;
                min_sum  = loc_sum + (*up);
            }
        } else {
            if (delta > d_low) {
                delta = d_low;
                min_sum  = loc_sum + (*low);
            }
        }
        return false;
    }

    int threeSumClosest(vector<int>& nums, int target) {
    
	if (nums.size() < 3) return 0;

	vector<int> abc(3, -666);
	if (nums.size() == 3) {
		return nums[0]+nums[1]+nums[2];
	}
	sort(nums.begin(), nums.end());

    int min_sum = target > 0 ? INT_MAX : INT_MIN;
	int delta = INT_MAX, d_loc = INT_MAX, ac = 0, loc_sum = 0;
    
    vi_iter low = nums.begin(), up = nums.end();

	for (vi_iter left = nums.begin(), e = nums.end() - 1; left != e; ++left) {
		for (vi_iter right = e; right - left > 1; --right) {
            loc_sum = (*left) + (*right);
			ac = target - loc_sum;
			if (ac < *(left+1)) {
			    if (update(min_sum, delta, loc_sum, ac, left+1, left+1)) 
			        return target;
			    continue;
			} else if (ac > *(right-1)) {
			    if (update(min_sum, delta, loc_sum, ac, right-2, right-1)) 
			        return target;
                break;
			} else {
                low = lower_bound(left+1, right-1, ac);
                if (low > right) {
                    if (update(min_sum, delta, loc_sum, ac, low, right-1)) 
                        return target;
                    break;
                } else {
                    up =  lower_bound(left+1, right-1, ac);
                    if (low > left) 
                        --low;
                    if (update(min_sum, delta, loc_sum, ac, low, up)) 
                        return target;
                }
 
			}
		} 
	}

	return min_sum;
    }
};
