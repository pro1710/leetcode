// 17_letters_combination_phone_number.cpp

class Solution {
    const vector<string> nums = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:

    vector<string> appender(const vector<string>& v, string& digits, size_t pos) {
        if (pos >= digits.size()) return v;
        vector<string> res;
        
        for (int i = 0, ie = v.size() ; i < ie; ++i) {
            size_t idx = (int)(digits[pos] - '0');
            for (int j = 0, je = nums[idx].size(); j < je; ++j)
                res.push_back(v[i] + nums[idx][j]);
        }
        return appender(res, digits, pos + 1);
        
        
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return vector<string>();
        return appender({""}, digits, 0);
        
    }
};

// 18_4sum.cpp

class Solution {
public:
    template<class T>
    int binSearch(const T& target, const vector<T>& v, const size_t& left, const size_t& right) {
    	
    	if (v.size() == 0)
    		return -1;
    	
    	if (right - left < 2) {
    		return v[left] == target ? left : (v[right] == target ? right : -1);
    	}
    
    	int mid = (left+right)/2;
    	
    	if (target < v[mid])
    		return binSearch(target, v, left, mid-1);
    	return binSearch(target, v, mid, right);
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return vector<vector<int>>();
        
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        for (int ileft = 0, e = nums.size(); ileft < e - 3; ++ileft) {
            for (int iright = e-1; iright - ileft > 2; --iright) {

                for (int i = ileft + 1, ei = iright -1; i < ei; ++i) {
                    int sub_target = target - (nums[ileft] + nums[iright] + nums[i]);
                    
                    if (sub_target < nums[i] ) break;
                    if (sub_target > nums[ei]) continue;

                    int idx = binSearch(sub_target, nums, i+1, ei);
                    if (idx != -1) {
                        res.push_back({nums[ileft], nums[i], nums[idx], nums[iright]});
                        while(nums[i] == nums[i+1] && i < ei) ++i;
                    }
                }
                while(nums[iright] == nums[iright-1] && iright - ileft > 2) --iright;
            }
            while(nums[ileft] == nums[ileft+1] && ileft < e - 3) ++ileft;
        }
        return res;
        
        
    }
};

/*
//solution using 3sum code

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

    int binSearch(const int& value, const vector<int>& base, const int& first, const int& last) {
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

    vector< vector<int> > threeSum(vector<int>& nums, int target) {
       	vector< vector<int> > result;
    	if (nums.size() < 3) return result;
    
    	vector<int> abc(3, INT_MIN);
    	if (nums.size() == 3) {
    		if (nums[0] + nums[1] + nums[2] == target) {
    			abc[0] = nums[0];
    			abc[1] = nums[1];
    			abc[2] = nums[2];
      			result.push_back(std::vector<int>(abc));
    		}
    		return result;
    	}

    	for (int left = 0, s = nums.size() - 2; left < s; left++) {
    		
    		for (int right = nums.size() - 1; right - left > 1; right--) {
    		    
    		 	if (abc[0] == nums[left] && abc[2] == nums[right]) continue;
    			int ac = -(nums[left] + nums[right] - target);

    			if (ac > nums[right]) break;
    			if (ac < nums[left]) continue;

    			if (int index = binSearch(ac, nums, left+1, right-1)){
    				abc[0] = nums[left];
    				abc[1] = nums[index];
    				abc[2] = nums[right];
    				result.push_back(abc);
    				while(nums[left] == nums[left+1]) left++;
    			}
    			
    		} 
	    }

	return result;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
            
        heapSort(nums);
        if (nums.size() == 4) {
            if (nums[0]+nums[1]+nums[2]+nums[3] == target) {
                res.push_back({nums[0], nums[1], nums[2], nums[3]});
            }
                
            return res;
        } 
            
        for (int i = 0, e = nums.size(); i < e-1;) {
            vector<int> vv(nums.begin() + i + 1, nums.end());
            if (vv.size() < 3) break;
            auto v = threeSum(vv, target - nums[i]);
            if (v.size()) {
                for (auto& it: v) {
                    res.push_back({nums[i], it[0], it[1], it[2]});
                }
                while (i < e-1 && nums[i] == nums[i+1]) ++i;
            }
            ++i;
        }
        return res;
    }
};
*/


// 19_delete_Nth_from_list_end.cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

/*    inline ListNode* removeNth(ListNode* head, int n) {
        
        if (!n) return head->next;
        
        ListNode* curr = head;
        for(int i = 1; i < n; ++i) {
            curr = curr->next;
        }
        
        ListNode* todel = curr->next;
        curr->next = curr->next->next;
        todel->next = NULL;
        return head;
    }
*/
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head, *last = head;
        for (int i = 0; i < n; ++i) {
            last = last->next;
        }
        
        // int idx = 0;
        if (!last) return first->next;
        last = last->next;
        while(last) {
            last = last->next;
            first = first->next;
            // ++idx;
        }
        ListNode* todel = first->next;
        first->next = first->next->next;
        todel->next = NULL;
        return head;
    }
};


