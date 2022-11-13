// class Solution {
// public:
//     string reverseWords(string s) {
	
// 	    // Used for breaking words
//         stringstream i(s);
		
// 		// To store individual words
//         string word ; 
		
//         string ans = "" ; 
//         while(i>>word) 
//         {
//             string tmp = word + " " + ans ;
//             ans = tmp ; 
//         }
//         return ans.substr(0,ans.size()-1);    // removes the last space character
//     }
// };      
            
			
class Solution {
public:
    string reverseWords(string s) {
        stack<string> st ;
        string str = "";
        for(int i=0 ;i<s.size(); i++){
            if(s[i]!=' '){
                str+= s[i];
                if(i== s.size()-1){
                    st.push(str);
                    st.push(" ");
                }
            }else{
                if(str == ""){
                    continue ;
                }
                st.push(str);
                st.push(" ");
                str = "";
            }
        }
        st.pop(); // removing extra space at the end 
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans ;
    }
};
            
			
            
      