class Solution {
public:
    long putMarbles(std::vector<int>& W, int k) {
        int n = W.size();
        std::vector<int> pairs(n - 1);
        for (int i = 1; i < n; i++) {
            pairs[i - 1] = W[i] + W[i - 1];
        }
        std::sort(pairs.begin(), pairs.end());
        
        long min = 0;
        long max = 0;
        for (int i = 0; i < k - 1; i++) {
            min += pairs[i];
            max += pairs[n - i - 2];
        }
        
        return max - min;
    }
};