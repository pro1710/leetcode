// class Solution {
// public:
//     int longestValidParentheses(string S) {
//         stack<int>st;
//         st.push(-1);
//         int c=0;
//         for(int i=0;i<S.size();i++){
//             if(S[i]==')'){
//                 st.pop();
//                 if(st.empty())
//                     st.push(i);
//                 else
//                     c=max(c,i-st.top());
//             }
//             else
//                 st.push(i);
//         }
//         return c;
//     }
// };


class Solution {
public:
    int longestValidParentheses(string& s) {

        vector<int> dp(s.size()+1);

        int ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i-1] == '(' && s[i] == ')') {
                dp[i] = 2;
                if (i > 1) {
                    dp[i] += dp[i-2];
                }
            } 

            if (i-1 >= dp[i-1] && s[i-1] == ')' && s[i] == ')' && s[i-1 - dp[i-1]] == '(') {
                dp[i] = 2 + dp[i-1];
                if (i-1 - dp[i-1]-1 >= 0) {
                    dp[i] += dp[i-1-dp[i-1]-1];
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
   
};
