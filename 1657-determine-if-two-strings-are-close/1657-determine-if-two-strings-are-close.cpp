// class Solution {
// public:
//     bool closeStrings(string word1, string word2) {
//         set<int> w1_letters, w2_letters, w1_freq, w2_freq;
//         unordered_map<char, int> w1_m, w2_m;
        
//         for (auto x : word1) {
//             w1_letters.insert(x);
//             w1_m[x]++;
//         }
        
//         for (auto x : word2) {
//             w2_letters.insert(x);
//             w2_m[x]++;
//         }
        
//         for (auto [k, v] : w1_m) w1_freq.insert(v);
        
//         for (auto [k, v] : w2_m) w2_freq.insert(v);

//         return w1_letters == w2_letters && w1_freq == w2_freq;
//     }
// };


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>w1(26,0),w2(26,0);
        set<char>s1,s2;
        for(char c:word1){
            w1[c-'a']++;
            s1.insert(c);
        }
        for(char c:word2){
            w2[c-'a']++;
            s2.insert(c);
        }
        sort(begin(w1),end(w1));
        sort(begin(w2),end(w2));
        return w1==w2&&s1==s2;
    }
};