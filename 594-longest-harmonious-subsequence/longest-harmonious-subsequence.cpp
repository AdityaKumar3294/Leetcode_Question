class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto i:nums) freq[i]++;
        int ans = 0;
        for (auto& [num, count] : freq) {
            if (freq.find(num+1) != freq.end()) {
                ans = max(ans, count + freq[num+1]); 
            }
        }
        return ans;
    }
};