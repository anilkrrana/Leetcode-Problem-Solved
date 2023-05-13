// Approach
// Recursive will take more time so thought about DP

// Complexity
// Time complexity:
// O(n)

// Space complexity:

// O(n)

class Solution {
public:
    int mod=1e9+7;
    long long solve(int length,int high,int low,int zero,int one,vector<long long>& dp){
        if(length>=high)return 0;
        if(dp[length]!=-1)return dp[length];
        
        long long a= solve(length+zero,high,low,zero,one,dp);
         if(zero+length>=low and zero+length<=high)a++;
        
        long long b= solve(length+one,high,low,zero,one,dp);
         if(one+length>=low and one+length<=high)b++;
        
        return dp[length]=(a+b)%mod;
        
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(1e5+1,-1);
        return int(solve(0,high,low,zero,one,dp));
    }
};