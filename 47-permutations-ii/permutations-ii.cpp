#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    void solve(vector<vector<int>>& ans, vector<int>& nums, int index) {
        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used; // track duplicates at this level

        for (int j = index; j < nums.size(); j++) {
            // Skip duplicates
            if (used.count(nums[j])) continue;
            used.insert(nums[j]);

            swap(nums[index], nums[j]);
            solve(ans, nums, index + 1);
            swap(nums[index], nums[j]); // backtrack
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(ans, nums, 0);
        return ans;
    }
};