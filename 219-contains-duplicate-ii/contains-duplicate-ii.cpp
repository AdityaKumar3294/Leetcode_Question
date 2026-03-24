#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int>> v;

        // Store value and index
        for (int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }

        // Sort by value
        sort(v.begin(), v.end());

        // Check adjacent elements
        for (int i = 1; i < v.size(); i++) {
            if (v[i].first == v[i - 1].first) {
                if (abs(v[i].second - v[i - 1].second) <= k) {
                    return true;
                }
            }
        }

        return false;
    }
};