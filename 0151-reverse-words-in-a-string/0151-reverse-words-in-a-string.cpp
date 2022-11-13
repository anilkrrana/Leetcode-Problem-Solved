class Solution {
public:
    string reverseWords(string s) {
	
	    // Used for breaking words
        stringstream i(s);
		
		// To store individual words
        string word ; 
		
        string ans = "" ; 
        while(i>>word) 
        {
            string tmp = word + " " + ans ;
            ans = tmp ; 
        }
        return ans.substr(0,ans.size()-1);    // removes the last space character
    }
};      
            
			
            
			
            
      