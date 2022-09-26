class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int target = image[sr][sc];
        
        if (target == color) {
            return image;
        }
        
        vector<array<int, 2>> stack = {{sr, sc}};
        
        while (!stack.empty()) {
            
            auto p = stack.back();
            image[p[0]][p[1]] = color;
            stack.pop_back();
            
            // up
            if (p[0]-1 >= 0 && image[p[0]-1][p[1]] == target) {
                stack.push_back({p[0]-1, p[1]});
            }
            // down
            if (p[0]+1 < image.size() && image[p[0]+1][p[1]] == target) {
                stack.push_back({p[0]+1, p[1]});
            }
            // left
            if (p[1]-1 >= 0 && image[p[0]][p[1]-1] == target) {
                stack.push_back({p[0], p[1]-1});
            }
            // right
            if (p[1]+1 < image[p[0]].size() && image[p[0]][p[1]+1] == target) {
                stack.push_back({p[0], p[1]+1});
            }
        }
        return image;
    }
};
