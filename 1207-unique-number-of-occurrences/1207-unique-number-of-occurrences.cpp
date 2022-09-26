class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
            unordered_map<int,int> m;
    
//     // counting the frequency of elements
//     for(int i=0; i<arr.size(); i+=1){
//         m[arr[i]]++;
//     }
//     vector<int>ans;
//     // copy frequency of map into vector
//     for(auto i:m) ans.push_back(i.second);
    
//     // copy vector into set
//     set<int>st(ans.begin(),ans.end());
    
//     int n=ans.size();
//     int y=st.size();
    
//     //compare vector size and set size
//     if(n==y){
//         return true;
//     } 
//         else{
//              return false;
//         }
//    }
        
        vector<int> ans;
        int size = arr.size();
        int i = 0;
        
        sort(arr.begin(), arr.end());
        
        while(i<size){
            int count = 1;
            for(int j =i+1;j<size;j++){
                if(arr[i]==arr[j]){
                    count++;
                }
                else{
                    break;
                }
            }
            ans.push_back(count);
            i = i + count;
        }
        size = ans.size();
        sort(ans.begin(),ans.end());
        
        for(int i = 0;i<size-1;i++){
            if(ans[i]==ans[i+1]){
                return false;
            }
        }
        return true;   
    }
    
};