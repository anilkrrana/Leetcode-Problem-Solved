// class Solution {
// public:
    
//     int result;
    
//     int DFS(unordered_map<int, vector<int>> &adj, int curr, int parent, string &s) {
        
//         int longest = 0;
//         int second_longest = 0;
        
//         for(int &child : adj[curr]) {
            
//             if(child == parent)
//                 continue;
            
//             int child_longest_length = DFS(adj, child, curr, s);
            
//             if(s[child] == s[curr])
//                 continue;
            
//             if(child_longest_length > second_longest)
//                 second_longest = child_longest_length;
            
//             if(second_longest > longest)
//                 swap(longest, second_longest);
//         }
        
//         int best_of_one = max(longest, second_longest) + 1;
        
//         int only_good_root = 1;
        
//         int answer_got_it_below = 1 + longest + second_longest;
        
//         result = max({result, best_of_one, only_good_root, answer_got_it_below});
        
//         return max(best_of_one, only_good_root);
        
//     }
    
//     int longestPath(vector<int>& parent, string s) {
//         int n = parent.size();
//         unordered_map<int, vector<int>>adj;
        
//         result = 0;
        
//         for(int i = 1; i<n; i++) {
//             int u = i;
//             int v = parent[i];
            
//             adj[v].push_back(v);
//             adj[v].push_back(u);
            
//         }
        
//         DFS(adj, 0, -1, s);
//         return result;
//     }
// };

class Solution {
public:
    vector<int> child[100001];
    int ans;
    int dfs(string &s, int curr_node)
    {
        if(child[curr_node].empty())return 1;
        int mx1 = 0, mx2 =0;
    // traversing over all the child nodes of the curr_node
        for(auto &child_node : child[curr_node])
        {
        // recursively trying for child nodes
            int len = dfs(s, child_node);
            ans = max(ans , len);
     // rejecting the current node if it's of same character
            if(s[curr_node] == s[child_node])continue;
     // updating the mx1 and mx2 paths that we can take from all the children of the given node
            if(len > mx1)
            {
                mx2 = mx1;
                mx1 = len;
            }
    //seecond max will be updated
            else mx2 = max(mx2 , len);
        }
    // Update the result.
    //Again, max1+mx2+1 means the length of the longest valid path 
    //going through this node in the sub-tree rooted at this node
        ans = max(ans, 1 + mx1 + mx2);
    //Adding 1 for the current node
        return 1 + mx1;
    }
    int longestPath(vector<int>& parent, string s){
        int n = parent.size();
        for(int i=1;i<n;i++)child[parent[i]].push_back(i);
        ans = 1;
        dfs(s,0);
        return ans;
    }
};


