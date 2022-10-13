// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n= prices.size();
//         int mn= INT_MAX;
//         int ans=0;
        
//         for(int i=0; i<n; i++){
//             mn = min(mn, prices[i]);
//             ans = max(ans, prices[i]-mn);
//         }
        
//         return ans;
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mop = INT_MAX;
        int ans = 0;
        int n = 0;
        
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < mop)
            {
                mop = prices[i];
            }
            n = prices[i] - mop;
            if(ans < n)
            {
                ans = n;
            }
        }
        return ans;
    }
};