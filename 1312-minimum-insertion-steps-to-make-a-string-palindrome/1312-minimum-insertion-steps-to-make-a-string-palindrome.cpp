class Solution {
public:
    int minInsertions(string s) {
        string p=s;
        reverse(s.begin(),s.end());
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[j-1]==p[i-1])dp[i][j]=max(dp[i-1][j],max(1+dp[i-1][j-1],dp[i][j-1]));
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return n-dp[n][n];
    }
};