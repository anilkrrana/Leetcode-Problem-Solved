//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here

        if(N == 1 && K == 1)
            return {A[0] + B[0]};
            
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        
        vector<int> ans;
        priority_queue<vector<int>> pq;
        
        for(int i=0; i<N; i++){
            pq.push({A[0] + B[i], 0, i});
        }
        while(K--){
            auto ele = pq.top();
            pq.pop();    
            ans.push_back(ele[0]);    
            pq.push({A[ele[1] + 1] + B[ele[2]], ele[1] + 1, ele[2]});    
       }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends