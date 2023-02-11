class Solution {
    struct Res {
        int vmax;
        int smin;
    };

    unordered_map<int, Res> memo;

public:
    int mctFromLeafValues(vector<int>& arr) {
        auto res = calc(arr, 0, arr.size());
        return res.smin;        
    }

    Res calc(vector<int>& arr, int b, int e) {

        int index = b*100+e;
        if (memo.find(index) != memo.end()) {
            return memo[index];
        }

        if (e-b == 1) {
            return {.vmax = arr[b], .smin = 0};
        }

        Res res = {.vmax = 0, .smin = INT_MAX};

        for (int i = b+1; i < e; ++i) {
            auto lres = calc(arr, b, i);
            auto rres = calc(arr, i, e);
            int cand = lres.smin + rres.smin + lres.vmax * rres.vmax;
            if (res.smin > cand) {
                res.smin = cand;
                res.vmax = max(lres.vmax, rres.vmax);
            }

        }

        memo[index] = res;

        return res;

    }
};


//  int mctFromLeafValues(vector<int>& A) {
//     int res = 0;
//     vector<int> stack = {INT_MAX};
//     for (int a : A) {
//         while (stack.back() <= a) {
//             int mid = stack.back();
//             stack.pop_back();
//             res += mid * min(stack.back(), a);
//         }
//         stack.push_back(a);
//     }
//     for (int i = 2; i < stack.size(); ++i) {
//         res += stack[i] * stack[i - 1];
//     }
//     return res;
// }
