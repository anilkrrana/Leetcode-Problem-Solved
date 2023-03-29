class Solution {
public:
    int findMaxSatisfaction(vector<int>& satisfaction, vector<vector<int>>& memo, int index, int time) {
        
        if (index == satisfaction.size()) {
            return 0;
        }
        
        if (memo[index][time] != -1) {
            return memo[index][time];
        }
        
        
        return memo[index][time] = max(satisfaction[index]*time + 
                            findMaxSatisfaction(satisfaction, memo, index + 1, time+1),
                                      findMaxSatisfaction(satisfaction, memo, index + 1, time));
        
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        
        vector<vector<int>> memo(satisfaction.size() + 1, vector<int>(satisfaction.size() + 1, -1));
        return findMaxSatisfaction(satisfaction, memo, 0, 1);
    }
};

