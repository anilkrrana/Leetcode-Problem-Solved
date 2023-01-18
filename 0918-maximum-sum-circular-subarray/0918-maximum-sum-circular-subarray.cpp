class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int ans = nums[0]; //contain answer || max sum containing array
        int n = nums.size();
        int totalSum = nums[0]; // total sum of array
        int maxElement = nums[0]; //contains the max element to tackle all the negative number containing array

        vector<int> currMax(n);
        vector<int> currMin(n);
        currMax[0] = nums[0];
        currMin[0] = nums[0];

        for(int i=1;i<n;i++){
            currMax[i] = max(nums[i],currMax[i-1]+nums[i]);
            currMin[i] = min(nums[i],currMin[i-1]+nums[i]);
            totalSum += nums[i];
            maxElement = max(maxElement,nums[i]);
        }

        for(int i=0;i<n;i++){
            ans = max(ans,max(currMax[i],totalSum-currMin[i]));
        }

        return ans > 0 ? ans : maxElement;
    }
};