class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, 
               vector<int>& temp, vector<vector<int>>& ans) {
        
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            
            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1]) continue;

            // If number exceeds target, break
            if (candidates[i] > target) break;

            temp.push_back(candidates[i]);
            solve(i + 1, candidates, target - candidates[i], temp, ans);
            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, candidates, target, temp, ans);
        return ans;
    }
};