class Solution {
public:
    int MOD = 1000000007;

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = n-1;
        long long ans = 0;
        vector<int> power(n, 1);

        // calculating powers of 2
        for(int i=1;i<n;i++) {
            power[i] = (power[i-1]*2)%MOD;
        }

        // Two pointer approach
        while(left <= right) {
            if(nums[left] + nums[right] > target) {
                right--;
            }
            else {
                ans = (ans + power[right-left])%MOD;
                left++;
            }
        }
        return ans;
    }
};
