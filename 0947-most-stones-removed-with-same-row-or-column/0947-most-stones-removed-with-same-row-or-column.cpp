class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
         const int n = stones.size();
        res = vector<int>(n);
        for(int i=0;i<n;i++) res[i] = i;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    connect(i,j);
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++) 
            if(res[i] == i) cnt++;
        return n - cnt;
    }
    
    int getRoot(int i){
        if(res[i] != i){
            res[i] = getRoot(res[i]);
        }
        return res[i];
    }
    
    void connect(int i, int j){
        res[getRoot(i)] = getRoot(j); 
    }
    
    vector<int> res;
    
};


