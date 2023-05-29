//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    vector<string> CamelCase(int n, vector<string> Dict, string Pat) {
      vector<string>ans(1,"-1");
      bool f=true;
      for(int i=0;i<n;i++)
      {
          string s=Dict[i];
          string x="";
          for(int j=0;j<s.size();j++)
          {
              if(s[j]<='Z' && s[j]>='A')
              x+=s[j];
              
              if(x==Pat)
              {
                 if(f)
                 {
                     ans.pop_back();
                     f=false;
                 }
                 ans.push_back(s);
                 break;
              }
          }
      }
      
      return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends