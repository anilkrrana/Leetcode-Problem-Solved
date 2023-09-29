//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here

int n=grid.size(),m=grid[1].size();
        if(m<3 || n<3) return 0;

        queue<pair<int,int>> q;
        int count=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1) count++;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[0][j]==1){
                    grid[0][j]=2;
                    q.push({0,j});
                }
                if(grid[n-1][j]==1){
                    grid[n-1][j]=2;
                    q.push({n-1,j});
                }
            }
            if(grid[i][0]==1) {
                    grid[i][0]=2;
                    q.push({i,0});
            }
            if(grid[i][m-1]==1){
                    grid[i][m-1]=2;
                    q.push({i,m-1});
            }
        }
        count-=q.size();
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                
                if( nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    grid[nrow][ncol]=2;
                    count--;
                }
            }
        }
        return count;

}

};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends