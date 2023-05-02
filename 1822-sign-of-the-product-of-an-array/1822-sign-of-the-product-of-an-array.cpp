class Solution {
public:
    int arraySign(vector<int>& nums) {
         int i , neg_num = 0;
        for(i=0 ; i<nums.size() ; i++)
        {
            if(nums[i] == 0)
                return 0;
            else if(nums[i] < 0)
                neg_num++;
        }
        if(neg_num %2 == 0)
            return 1;
        else
            return -1;
    }
};