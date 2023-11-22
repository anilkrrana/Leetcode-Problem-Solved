class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int currentConsecutiveSeq = 1;
        int longestConsecutiveSeq = 0;
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == nums[i-1] + 1){
                    currentConsecutiveSeq++;
                }
                else{
                    longestConsecutiveSeq = max(longestConsecutiveSeq, currentConsecutiveSeq);
                    currentConsecutiveSeq = 1;
                }
            }
        }
        return max(longestConsecutiveSeq, currentConsecutiveSeq);
    }
};