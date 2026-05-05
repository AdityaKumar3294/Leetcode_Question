class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> nums2;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                nums2.push_back(0);
            }
            else {
                nums2.push_back(1);
            }
        }
        sort(nums2.begin(), nums2.end());
        return nums2;
    }
};