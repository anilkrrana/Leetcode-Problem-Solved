class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;
        
        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }
        
        return result;
    }
};


// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int result = 0;
//         for (int i = 0; i < nums.size(); i++)
//             result ^= nums[i]^(i+1);
//         return result;
//     }
// };