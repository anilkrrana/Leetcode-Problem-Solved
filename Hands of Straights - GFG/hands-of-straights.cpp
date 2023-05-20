//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, std::vector<int> &hand) {
        // code here
        if (N % groupSize != 0) {
            // Number of cards is not divisible evenly by groupSize
            return false;
        }

        std::map<int, int> freq;
        for (int num : hand) {
            freq[num]++;
        }

        while (!freq.empty()) {
            int start = freq.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                if (freq[start + i] == 0) {
                    // Cards are not consecutive
                    return false;
                }
                freq[start + i]--;
                if (freq[start + i] == 0) {
                    freq.erase(start + i);
                }
            }
        }

        return true;
    }


    int main() {
        int N = 9;
        int groupSize = 3;
        std::vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    
        Solution solution;
        bool result = solution.isStraightHand(N, groupSize, hand);
        std::cout << (result ? "true" : "false") << std::endl;
    
        return 0;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends