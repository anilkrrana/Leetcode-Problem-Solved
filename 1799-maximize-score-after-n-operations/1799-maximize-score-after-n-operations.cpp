class Solution { // 58 ms, faster than 94.74%
public:
    int gcdMemo[14][14] = {};
    int memo[1 << 14] = {};
    int m, n;
    int maxScore(vector<int>& nums) {
        m = nums.size(), n = m / 2;
        return dp(nums, 1, 0);
    }
    int dp(vector<int>& nums, int op, int mask) {
        if (op > n) return 0; // Reach to n operations
        if (memo[mask] != 0) return memo[mask];

        for (int i = 0; i < m; ++i) {
            if ((mask >> i) & 1) continue; // If nums[i] is used -> Skip
            for (int j = i + 1; j < m; ++j) {
                if ((mask >> j) & 1) continue; // If nums[i] is used -> Skip
                int newMask = (1 << i) | (1 << j) | mask; // Mark nums[i] and nums[i] as used!
                int score = op * gcd(nums, i, j) + dp(nums, op + 1, newMask);
                memo[mask] = max(memo[mask], score);
            }
        }
        return memo[mask];
    }
    int gcd(vector<int>& nums, int i, int j) { // gcd with cache
        if (gcdMemo[i][j] != 0) return gcdMemo[i][j];
        return gcdMemo[i][j] = __gcd(nums[i], nums[j]);
    }
};


// Complexity:

// Time: O(2^m * m^2), where mask = 2^m, m = 2n <= 14
// Firstly, we thought that there are total op * mask = n * 2^m states, but op information is already included in mask (op = numberBit1s(mask) / 2 + 1).
// That's why, we have total mask states, each state needs 2 loops with m^2 to compute, so dp takes O(mask * m^2).
// And since we cache gcd(x, y), so we plus with time complexity to calculate gcd(x,y) for m^2 pairs of (x, y) is O(m^2 * logMAX_NUM), where MAX_NUM <= 10^6.
// Total time complexity: O(mask * m^2 + m^2 * logMAX_NUM) ~ O(2^m * m^2), we can remove m^2 * logMAX_NUM part, since it's too small compared to O(2^m * m^2).
// Space: O(mask) = O(2^m)


// Idea

// Please notice that n <= 7 which is very small, we can bruteforce try all possible ways by using mask, and cache the computed result with Top Down DP approach.
// Let dp(op, mask) is the maximum score you can receive after performing op operations, where mask represent the indices of nums we already used (ith bit = 1 means we used nums[i]).
// Then dp(1, 0) is our answer.
// The base case: return 0 when op == n+1, we reach n opeartions.
// Transition state:
// Choose pair index of (i, j) from [0..2*n-1], where nums[i] and nums[j] hasn't been used yet.
// newMask = (1 << i) | (1 << j) | mask # Mark nums[i] and nums[j] as used!
// score = dp(op+1, newMask) + op * gcd(nums[i], nums[j])
// Choose maximum score between possible scores.
