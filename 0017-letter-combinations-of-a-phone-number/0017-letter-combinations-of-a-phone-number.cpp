class Solution {
public:
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
		vector<string> result;
        result.push_back("");
        
        for(auto digit: digits) {
            vector<string> tmp;
            for(auto candidate: pad[digit - '0']) {
                for(auto s: result) {
                    tmp.push_back(s + candidate);
                }
            }
            result.swap(tmp);
        }
        return result;
    }
};











/*
Simple and efficient iterative solution.

Explanation with sample input "123"

Initial state:

result = {""}
Stage 1 for number "1":

result has {""}
candiate is "abc"
generate three strings "" + "a", ""+"b", ""+"c" and put into tmp,
tmp = {"a", "b","c"}
swap result and tmp (swap does not take memory copy)
Now result has {"a", "b", "c"}
Stage 2 for number "2":

result has {"a", "b", "c"}
candidate is "def"
generate nine strings and put into tmp,
"a" + "d", "a"+"e", "a"+"f",
"b" + "d", "b"+"e", "b"+"f",
"c" + "d", "c"+"e", "c"+"f"
so tmp has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
swap result and tmp
Now result has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
Stage 3 for number "3":

result has {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
candidate is "ghi"
generate 27 strings and put into tmp,
add "g" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
add "h" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
add "h" for each of "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
so, tmp has
{"adg", "aeg", "afg", "bdg", "beg", "bfg", "cdg", "ceg", "cfg"
"adh", "aeh", "afh", "bdh", "beh", "bfh", "cdh", "ceh", "cfh"
"adi", "aei", "afi", "bdi", "bei", "bfi", "cdi", "cei", "cfi" }
swap result and tmp
Now result has
{"adg", "aeg", "afg", "bdg", "beg", "bfg", "cdg", "ceg", "cfg"
"adh", "aeh", "afh", "bdh", "beh", "bfh", "cdh", "ceh", "cfh"
"adi", "aei", "afi", "bdi", "bei", "bfi", "cdi", "cei", "cfi" }
Finally, return result.*/