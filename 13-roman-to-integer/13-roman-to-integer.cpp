class Solution {
public:
    int romanToInt(string s)
{
        
      unordered_map<char,int> ns{
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000},
    };
    int ans = 0;
    for(int i = 0; i<s.size(); i++){
        if(ns[s[i]]<ns[s[i+1]])
            ans -= ns[s[i]];
        else
            ans += ns[s[i]];
    }
    return ans;
    
}
};