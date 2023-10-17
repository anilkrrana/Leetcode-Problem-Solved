//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            int N = Integer.parseInt(in.readLine());
            int graph[][] = new int[N][N];
            
            for(int i = 0;i < N;i++)
                {String a[] = in.readLine().trim().split("\\s+");
                for(int j=0;j<N;j++)
                graph[i][j] = Integer.parseInt(a[j]);}
            
            Solution ob = new Solution();
            ArrayList<ArrayList<Integer>> ans = ob.transitiveClosure(N, graph);
            for(int i = 0;i < N;i++)
               { for(int j = 0;j < ans.get(i).size();j++)
                    System.out.print(ans.get(i).get(j) + " ");
            System.out.println();}
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    static ArrayList<ArrayList<Integer>> transitiveClosure(int N, int graph[][])
    {
        // code here
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        
        for(int src=0; src<N; src++) {
            adj.add(new ArrayList<>());
            ans.add(new ArrayList<>(Collections.nCopies(N, 0)));
            for(int dest=0; dest<N; dest++) {
                if(graph[src][dest]==1) {
                    adj.get(src).add(dest);
                }
            }
        }
        
        for(int idx=0; idx<N; idx++) {
            dfs(idx, idx, new boolean[N], adj, ans);
        }
        return ans;
    }
    
    static void dfs(int src, int dest, boolean[] visited, ArrayList<ArrayList<Integer>> adj, ArrayList<ArrayList<Integer>> ans) {
        ans.get(src).set(dest, 1);
        visited[dest] = true;
        for(int neighbor: adj.get(dest)){
            if(!visited[neighbor]){
                dfs(src, neighbor, visited, adj, ans);
            }
        }
    }
}