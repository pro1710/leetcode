class Solution {
public:
    
    unordered_map<int, int> memo = {{0, 0}, {1, 1}};
    
    int fib(int n) {
        
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        
        memo[n] = fib(n-1) + fib(n-2);
        return  memo[n];
    }
};
