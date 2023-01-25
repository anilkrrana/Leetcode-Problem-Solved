class Solution {
public:
    // int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        void dfs(vector<int>&e,int node,vector<int>&d,int dis){
        d[node]=dis;
        if(e[node]!=-1 and d[e[node]]==INT_MAX){
            dfs(e,e[node],d,dis+1);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        
        vector<int>dis1(n,INT_MAX),dis2(n,INT_MAX);
       dfs(edges,node1,dis1,0);
        dfs(edges,node2,dis2,0);
        int ans=INT_MAX;
        int index=-1;
        for(int i=0;i<n;i++){
            if(max(dis1[i],dis2[i])<ans){
                ans=max(dis1[i],dis2[i]);
                index=i;
            }
        }
        return index;
       
    }
};