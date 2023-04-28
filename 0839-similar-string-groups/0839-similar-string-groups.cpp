class Solution {
public:
    bool c(string a,string b){
        int f=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])f++;
        }
        if(f==2 || f==0)
            return true;
        else return false;
    }
    int numSimilarGroups(vector<string>& s) {
        int n=s.size();
        vector<bool>vis(n,false);
        queue<string>q;
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                vis[i]=true;
                q.push(s[i]);
                while(q.size()){
                    string f=q.front();
                    q.pop();
                    for(int j=0;j<n;j++){
                        if(c(f,s[j]) && !vis[j]){
                            vis[j]=true;
                            q.push(s[j]);
                        }
                    }
                }
            }
        }
        return ans;
    }
};