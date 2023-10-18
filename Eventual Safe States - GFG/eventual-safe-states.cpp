//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
  
    void dfs(int node, vector<int>& vis, vector<int>& topo, vector<int> adj[]) {
        vis[node] = true;
        for(int nbr: adj[node]) {
            if(vis[nbr] == false) {
                dfs(nbr, vis, topo, adj);
            }
        }
        topo.push_back(node);
    }
  
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        vector<int> topo;
        vector<int> vis(n, false);
        for(int i = 0; i < n; i++) {
            if(vis[i] == false)
                dfs(i, vis, topo, adj);
        }
        
        vector<int> res;
        vector<int> mark(n, false);
        
        for(auto it: topo) {
            bool flag = true;
            for(int nbr: adj[it]) {
                if(mark[nbr] == false) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                mark[it] = true;
                res.push_back(it);
            }
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends