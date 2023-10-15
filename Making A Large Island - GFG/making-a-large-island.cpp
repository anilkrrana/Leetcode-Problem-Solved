//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSet{
    private:
    vector<int>parent;
    vector<int>rank;
    vector<int>size;
    int n;
    public:
    DisjointSet(int n){
        this -> n = n;
        parent.resize(n+1,0);
        size.resize(n+1,1);
        rank.resize(n+1,0);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    int find_parent(int a){
        if(parent[a] == a){
            return a;
        }
        return parent[a] = find_parent(parent[a]);
    }
    void unionByRank(int a, int b){
        int uP_a = find_parent(a);
        int uP_b = find_parent(b);
        if(uP_a == uP_b) return;
        if(rank[uP_a] < rank[uP_b]){
            parent[uP_a] = uP_b;
        }else if(rank[uP_a] > rank[uP_b]){
            parent[uP_b] = uP_a;
        }else{
            parent[uP_b] = uP_a;
            rank[uP_a]++;
        }
    }

    void unionBySize(int a, int b){
        int uP_a = find_parent(a);
        int uP_b = find_parent(b);
        if(uP_a == uP_b) return;
        if(size[uP_a] < size[uP_b]){
            parent[uP_a] = uP_b;
            size[uP_b] += size[uP_a];
        }else{
            parent[uP_b] = uP_a;
            size[uP_a] += size[uP_b];
        }
    }
    int getSize(int i){
        return size[i];
    }
};
class Solution
{
    int n;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    bool isSafe(int i, int j,vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i == n || j == n || grid[i][j] == 0){
            return false;
        }
        return true;
    }
    int solve(DisjointSet &ds, int i, int j,vector<vector<int>>& grid){
        set<int>s;
        for(int a = 0; a < 4; a++){
            int nI = i + dx[a];
            int nJ = j + dy[a];
            if(isSafe(nI,nJ,grid)){
                s.insert(ds.find_parent(nI*n+nJ));
            }
        }
        int sum = 1;
        for(auto it:s){
            sum += ds.getSize(it);
        }
        return sum;
    }
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        n = grid.size();
        DisjointSet ds(n*n);
        vector<pair<int,int>> to_change;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    for(int a = 0; a < 4; a++){
                        int nI = i + dx[a];
                        int nJ = j + dy[a];
                        if(isSafe(nI,nJ,grid)){
                            if(ds.find_parent(i*n+j) != ds.find_parent(nI*n+nJ)){
                                ds.unionBySize(i*n+j,nI*n+nJ);
                            }
                        }
                    }
                }else{
                    to_change.push_back({i,j});
                }
            }
        }
        int largestLandSize = 0; 
        for(int i = 0; i < n; i++){
            largestLandSize = max(largestLandSize,ds.getSize(i));
        }
        for(auto it: to_change){
            int i = it.first;
            int j = it.second;
            largestLandSize = max(largestLandSize,solve(ds,i,j,grid));
        }
        return largestLandSize;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends