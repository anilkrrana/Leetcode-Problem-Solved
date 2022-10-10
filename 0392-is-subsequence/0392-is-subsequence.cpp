class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = 0;  
        if(s.length() == 0) return true;
        for(int i = 0; i < t.length(); i++)
        {
           if(t[i] == s[m]){
               ++m;
           } 
            if(m == s.length()) return true;
        }
        return false;
    }
};