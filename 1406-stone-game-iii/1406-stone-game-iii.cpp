class Solution {
public:
    // dp[i] denotes the maximum score if alice takes the ith stone
    int dp[50005];
    
    int solve(int i, vector<int>&a){
        int n=a.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int alice=0,ans=INT_MIN;
        
        // alice can take upto 3 stones
        
        for(int k=i;k<min(n,i+3); k++){
            alice+=a[k];
            
            // after alice takes bob will take 1,2,3 and leave the minimum for alice
            ans=max(ans, alice+min({solve(k+2,a), solve(k+3,a) , solve(k+4,a)}));
        }
        return dp[i]=ans;
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        
        memset(dp,-1,sizeof dp);
        int aliceScore=solve(0,stoneValue);
        
        int bobScore=accumulate(stoneValue.begin(),stoneValue.end(),0)-aliceScore;
        if(aliceScore>bobScore) return "Alice";
        else if(aliceScore==bobScore) return "Tie";
        return "Bob";
    }
};