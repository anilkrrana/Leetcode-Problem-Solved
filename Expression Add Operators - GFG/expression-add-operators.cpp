//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        backtrack(num, target, 0, 0, 0, "", result);
        return result;
    }

private:
    void backtrack(string& num, int target, int index, long currResult, long prevNum, string expression, vector<string>& result) {
        if (index == num.length()) {
            if (currResult == target) {
                result.push_back(expression);
            }
            return;
        }

        for (int i = index; i < num.length(); i++) {
            if (i != index && num[index] == '0') {
                break; // Skip leading zeros
            }

            string currentStr = num.substr(index, i - index + 1);
            long currentNum = stol(currentStr);

            if (index == 0) {
                backtrack(num, target, i + 1, currentNum, currentNum, currentStr, result);
            } else {
                backtrack(num, target, i + 1, currResult + currentNum, currentNum, expression + "+" + currentStr, result);
                backtrack(num, target, i + 1, currResult - currentNum, -currentNum, expression + "-" + currentStr, result);
                backtrack(num, target, i + 1, currResult - prevNum + prevNum * currentNum, prevNum * currentNum, expression + "*" + currentStr, result);
            }
        }
    }

    int main() {
        Solution solution;
    
        string S = "123";
        int target = 6;
        vector<string> result = solution.addOperators(S, target);
        cout << "Output: ";
        for (const string& expression : result) {
            cout << expression << " ";
        }
        cout << endl;
    
        S = "3456237490";
        target = 9191;
        result = solution.addOperators(S, target);
        cout << "Output: ";
        for (const string& expression : result) {
            cout << expression << " ";
        }
        cout << endl;
    
        S = "12";
        target = 12;
        result = solution.addOperators(S, target);
        cout << "Output: ";
        for (const string& expression : result) {
            cout << expression << " ";
        }
        cout << endl;
    
        return 0;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends