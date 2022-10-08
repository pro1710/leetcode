class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> lMax(height.size(), 0);
        vector<int> rMax(height.size(), 0);
        rMax[rMax.size()-1] = height[height.size()-1];
        lMax[0] = height[0];
        for (int i = 1; i < lMax.size(); ++i) {
            lMax[i] = max(lMax[i-1], height[i]);
            int j = rMax.size()-i-1;
            rMax[j] = max(rMax[j+1], height[j]);
        }

        int ans = 0;
        for (int i = 1; i < height.size()-1; ++i) {
            ans += min(lMax[i], rMax[i]) - height[i];
        }
        return ans;
    }
};

// // stack
// int trap(vector<int>& height)
// {
//     int ans = 0, current = 0;
//     stack<int> st;
//     while (current < height.size()) {
//         while (!st.empty() && height[current] > height[st.top()]) {
//             int top = st.top();
//             st.pop();
//             if (st.empty())
//                 break;
//             int distance = current - st.top() - 1;
//             int bounded_height = min(height[current], height[st.top()]) - height[top];
//             ans += distance * bounded_height;
//         }
//         st.push(current++);
//     }
//     return ans;
// }
