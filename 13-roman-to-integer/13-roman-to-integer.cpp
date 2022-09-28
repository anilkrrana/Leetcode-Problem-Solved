class Solution {
public:
    int romanToInt(string s)
{
        
//       unordered_map<char,int> ns{
//         {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000},
//     };
//     int ans = 0;
//     for(int i = 0; i<s.size(); i++){
//         if(ns[s[i]]<ns[s[i+1]])
//             ans -= ns[s[i]];
//         else
//             ans += ns[s[i]];
//     }
//     return ans;
    
//}
        

          unordered_map<char,
        int>m1={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

    int ans=0;
    for(int i=s.length();i>=0;i--)
        ((i+1)<s.length() and m1[s[i]]<m1[s[i+1]])?ans-=m1[s[i]]:ans+=m1[s[i]];
    
    return ans;
    }
};