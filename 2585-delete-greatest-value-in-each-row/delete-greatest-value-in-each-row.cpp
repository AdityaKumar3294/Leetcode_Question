class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans = 0 , m = grid.size() , n = grid[0].size();

        for(int i = 0; i<m; i++){
            sort(grid[i].begin(),grid[i].end());
        }

        for(int i = 0; i<n; i++){
            int max_elem = INT_MIN;
            for(int j = 0; j<m; j++){
                max_elem = max(max_elem , grid[j][i]);
            }
            ans += max_elem;
        }
        return ans;
    }
};