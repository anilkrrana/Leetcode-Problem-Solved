//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int n, vector<int> p){
        // code here
        vector<int> out(n,0);
        
        for(int i = 1; i<n; i++){
            ++out[p[i]];
        }
        int ans = 0 ;
        
        for(int i = 0; i<n; i++)
            ans += out[i] == 0;
        
        if(out[0] == 1)
            ++ans;
        
        return max(n - 1 - ans, 0);
        
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends