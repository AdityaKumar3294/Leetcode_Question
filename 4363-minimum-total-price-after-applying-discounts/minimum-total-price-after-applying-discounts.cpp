class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();

        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        int i=0, j=0;
        double ans = 0;
        while (i<n && j<m) {
            ans += (double)(prices[i] * (double)(100 - discounts[j])/100);
            i++;
            j++;
        }

        while (i<n) {
            ans += (double)prices[i++];
        }

        return ans;
    }
};