class Solution {
public:
    
    int mod= 1e9+7;
    
    int recur(vector<int>& locations, int cur, int& finish, int fuel, vector<vector<int>>& dp)
    {
        if(fuel==0 && cur== finish)
            return 1;
        
        if(cur== locations.size() || fuel <0)
            return 0;
        
        if(dp[cur][fuel]!=-1) return dp[cur][fuel];
        
        long long ways=0;
        for(int j=0; j<locations.size(); j++)
        {
            if(cur==j) continue;
            ways+= recur(locations, j, finish, fuel- abs(locations[j]- locations[cur]),dp)% mod;
        }
        
        return dp[cur][fuel]= ways% mod;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        
        long long result=0;
        int n= locations.size();
        
        vector<vector<int>> dp(n, vector<int>(fuel+1,-1));
        
        for(int i=0;i<=fuel;i++)
        {
            result+= recur(locations, start, finish, i,dp)% mod;
            // cout<<recur(locations, start, finish, i,dp)<<endl;
        }
        
        return result% mod;
    }
};