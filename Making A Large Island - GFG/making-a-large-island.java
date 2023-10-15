//{ Driver Code Starts
import java.io.*;
import java.util.*;


class IntMatrix
{
    public static int[][] input(BufferedReader br, int n, int m) throws IOException
    {
        int[][] mat = new int[n][];

        for(int i = 0; i < n; i++)
        {
            String[] s = br.readLine().trim().split(" ");
            mat[i] = new int[s.length];
            for(int j = 0; j < s.length; j++)
                mat[i][j] = Integer.parseInt(s[j]);
        }

        return mat;
    }

    public static void print(int[][] m)
    {
        for(var a : m)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }

    public static void print(ArrayList<ArrayList<Integer>> m)
    {
        for(var a : m)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            int n;
            n = Integer.parseInt(br.readLine());
            
            
            int[][] grid = IntMatrix.input(br, n, n);
            
            Solution obj = new Solution();
            int res = obj.largestIsland(n, grid);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends


class Solution{
    private int[] parent;
    private int[] size;
    private int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    public int largestIsland(int N,int[][] grid) 
    {
        parent = new int[N * N];
        size = new int[N * N];
        
        // Initialize parent and size arrays
        for (int i = 0; i < N * N; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        
        // Step 1: Union islands
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    for (int[] dir : directions) {
                        int ni = i + dir[0];
                        int nj = j + dir[1];
                        
                        if (ni >= 0 && ni < N && nj >= 0 && nj < N && grid[ni][nj] == 1) {
                            union(i * N + j, ni * N + nj);
                        }
                    }
                }
            }
        }
        
        // Step 2: Count sizes of connected components
        int maxIslandSize = 0;
        int[] componentSizes = new int[N * N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 0) {
                    int componentSize = 1;
                    Set<Integer> connectedComponents = new HashSet<>();
                    for (int[] dir : directions) {
                        int ni = i + dir[0];
                        int nj = j + dir[1];
                        
                        if (ni >= 0 && ni < N && nj >= 0 && nj < N && grid[ni][nj] == 1) {
                            int parent = find(ni * N + nj);
                            if (!connectedComponents.contains(parent)) {
                                componentSize += size[parent];
                                connectedComponents.add(parent);
                            }
                        }
                    }
                    maxIslandSize = Math.max(maxIslandSize, componentSize);
                }
            }
        }
        
        return maxIslandSize == 0 ? N * N : maxIslandSize;
    }
    
    private int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    private void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }}
    }

