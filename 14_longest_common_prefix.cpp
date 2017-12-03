// 14_longest_common_prefix.cpp

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string res = strs[0];
        for (int i = 1, e = strs.size(); i < e; ++i) {
            string s = strs[i];
            for (int j = 0, d = res.size(); j < d; ++j) {
                if (res[j] != s[j]) {
                    res =  res.substr(0, j);
                    if (res == "") return res;
                    break;
                }
            }
        }
        return res;
    }
};


// 15_3sum.cpp

class Solution {
public:

    void swapVr(vector<int> &base, int i, int j) {
    	int t = base[i];
    	base[i] = base[j];
    	base[j] = t;
    }

    void heapSort(vector<int> &base) {
    	//heapify
    	int i = (base.size()/2 - 1), n = base.size(), c, r;
    	for (; i >= 0; i--) {
    		for (r = i; r * 2 + 1 < n; r = c) {
    			c = r * 2 + 1;
    			if (c < n - 1 && base[c] < base[c+1]) c++;
    			if (base[r] > base[c]) break;
    			swapVr(base, r, c);
    		}
    	}
    	//sort
    	for (i = n - 1; i > 0; i--) {
    		swapVr(base, 0, i);
    		for (r = 0; r * 2 + 1 < i; r = c) {
    			c = r * 2 + 1;
    			if (c < i - 1 && base[c] < base[c+1]) c++;
    			if (base[r] > base[c]) break;
    			swapVr(base, r, c);
    		}
    	}
    }

    int binSearch(int value, vector<int>& base, int first, int last) {
    	if (value > base[last] || value < base[first]) return 0;
    
    	if (first == last) return ((value == base[first])? first : 0);
    
    	if (last - first == 1) {
    		if (value == base[first]) return first;
    		else if (value == base[last]) return last;
    		else return 0;
    	}
    
    	int mid  = (first + last)/2;
    
    	if (value > base[mid]) return binSearch(value, base, mid, last);
    	else return binSearch(value, base, first, mid);
    }

    vector< vector<int> > threeSum(vector<int>& nums) {
     
	vector< vector<int> > result;
	if (nums.size() < 3) return result;

	vector<int> abc(3, -666);
	if (nums.size() == 3) {
		if (nums[0] + nums[1] + nums[2] == 0) {
			abc[0] = nums[0];
			abc[1] = nums[1];
			abc[2] = nums[2];
			heapSort(abc);
			result.push_back(std::vector<int>(abc));
		}
		return result;
	}
	heapSort(nums);

	

	for (int left = 0, s = nums.size() - 2; left < s; left++) {
		// cout << "l: " << left << "\n";
		for (int right = nums.size() - 1; right - left > 1; right--) {
			// cout <<  "r: " << right << "\n";
			if (abc[0] == nums[left] && abc[2] == nums[right]) continue;
			int ac = nums[left] + nums[right];

			// cout << "ac: " << ac << "\n";

			if (ac > nums[right] || ac < nums[left]) break;

			if (int index = binSearch(-ac, nums, left+1, right-1)){
				// cout << "found" << nums[index] << "\n";
				// if (abc[0] == nums[left] && abc[1] == nums[index]) continue;
				abc[0] = nums[left];
				abc[1] = nums[index];
				abc[2] = nums[right];
				result.push_back(abc);
				while(nums[left] == nums[left+1]) left++;
				//continue;
			}
			
		} 
	}

	return result;
    }
};


// 16_3sum_closest.cpp

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


