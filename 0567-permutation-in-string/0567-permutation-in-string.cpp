class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())   // base case
            return false;
        vector<int> pat(26, 0);
        for(char c : s1) pat[c-'a']++;  // store characters of s1
        vector<int> str(26, 0);
        for(int i = 0; i < s2.length(); i++){
            if(i >= s1.length())
                str[s2[i - s1.length()] - 'a']--;
            str[s2[i] - 'a']++;
            if(pat == str) return true;
        }
        return false;
    }
};