class Solution {
public:
    //lhs means left hand side, rhs means right hand side
    int longestPalindromeSubseq(string s) {
        if (s.empty()) return 0;
        
        vector<vector<int>> longest(s.size(), vector<int>(s.size()));
        for (int len=1; len<=s.size(); len++) {
            for (int lhs=0; lhs+len<=s.size(); lhs++) {
                int rhs = lhs+len-1;
                if (lhs == rhs) {
                    longest[lhs][rhs] = 1;
                } else if (lhs+1 == rhs) {
                    longest[lhs][rhs] = (s[lhs] == s[rhs]) ? 2 : 1;
                } else {
                    int add = s[lhs] == s[rhs] ? 2 : 0;
                    longest[lhs][rhs] = max(max(longest[lhs][rhs-1], longest[lhs+1][rhs]), longest[lhs+1][rhs-1] + add);
                }
            }
        }
        
        return longest[0].back();
    }
};