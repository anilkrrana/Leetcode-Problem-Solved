// class Solution {
// public:
//     int dp[1005][1005];
//     int bestTeamScore(vector<int>& scores, vector<int>& ages) {
//         vector<vector<int>>grp;
//         for(int i=0;i<scores.size();i++)
//         {
//             grp.push_back({scores[i],ages[i]});
//         }
//         sort(grp.begin(),grp.end());     
//         memset(dp,-1,sizeof(dp));
//         return recur(grp,0,ages.size(),0);
//     }
    
//     int recur(vector<vector<int>>&grp , int i , int n , int maxiAge)
//     {
//         if(i==n)
//             return 0;
//         if(dp[i][maxiAge]!=-1)
//             return dp[i][maxiAge];
//         // score is already greater than previous socre we need to check age 
//         // if current age is  greater than previous maxiAge then two choices
//         if(grp[i][1]>=maxiAge)
//         {
//             return dp[i][maxiAge] = max(grp[i][0]+recur(grp,i+1,n,grp[i][1]),recur(grp,i+1,n,maxiAge));
//         }
//         return dp[i][maxiAge] = recur(grp,i+1,n,maxiAge);
//     }
// };


class Solution {
public:
    int bestTeamScore(vector<int>& score, vector<int>& ages) {
       vector<pair<int,int>>grp;
       int n=score.size();
       for(int i=0;i<n;i++){
           grp.push_back({ages[i],score[i]});
       }
       sort(grp.begin(),grp.end());
       vector<int>dp(n+1);
       dp[0]=grp[0].second;
       for(int i=1;i<n;i++){
           dp[i]=grp[i].second;
           for(int j=0;j<i;j++){
               if(grp[i].second>=grp[j].second){
                   dp[i]=max(dp[j]+grp[i].second,dp[i]);
               }
           }
       }
       return *max_element(dp.begin(),dp.end());
    }
};