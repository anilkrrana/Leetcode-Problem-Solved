//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string S) { 
        int n = S.size();
        string R =  string(S.rbegin(), S.rend()); // string reverese.
        
        int dp[n+1][n+1] = {}; // To initialize first row and column to '0'
        
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(S[i] == R[j])
                {
                    dp[i+1][j+1] = 1 + dp[i][j];
                }
                else
                {
                    dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        
        return n-dp[n][n];
    } 
};




//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends