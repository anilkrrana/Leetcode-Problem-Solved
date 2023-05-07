class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> lis;
        vector<int> ans;
        for (int i = 0; i < obstacles.size(); ++i) {
            int x = obstacles[i];
            if (lis.empty() || lis.back() <= x) { // Append to LIS if new element is >= last element in LIS
                lis.push_back(x);
                ans.push_back(lis.size());
            } else {
                int idx = upper_bound(lis.begin(), lis.end(), x) - lis.begin(); // Find the index of the smallest number > x
                lis[idx] = x; // Replace that number with x
                ans.push_back(idx + 1);
            }
        }
        return ans;
    }
};