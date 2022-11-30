class Solution {
public:
    int pivotIndex(vector<int>& nums) {
         int len=nums.size();
    if(len==1){
          return 0;
    }  
    int sum[len];
    sum[0]=nums[0];
    for(int i=1;i<len;i++){
        sum[i]=nums[i]+sum[i-1];
    }
    for(int i=0;i<len;i++)
    {
        int left=sum[i]-nums[i];
        int right=sum[len-1]-sum[i];

    if(left==right)
        return i;
    }
      return -1;
    }
};

