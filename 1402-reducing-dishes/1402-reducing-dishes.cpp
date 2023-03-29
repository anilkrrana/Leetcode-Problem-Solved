// After sorting the array becomes - -9,-8,-1,0,5
// As we have sorted the array the bigger element will be at the end , so we start from the end of the array
// at i = n-1 i.e 4 -> Cumulative_sum = 0, and cur = 5 (5*1) = 5
// at i = 3 -> Cumulative-sum = 5, and cur = 5 + 5 + 0 (0*1 + 5*2) = 10
// at i = 2 -> Cumulative-sum = 5 (5 + 0), and cur = cur + Cumlative_sum + satis[i] = (10 + 5 + -1) = -1*1 + 0*2 + 5*3 = 14
// at i = 1 -> Cumulative-sum = 4 (5 + 0 + -1), and cur = cur + Cumlative_sum + satis[i] = (14 + 4 + -8) = -8*1 + -1*2 + 0*3 + 5*5= 14
// And similarly for i = 0 and and max of all currents is printed

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        
        int Cumulative_sum = 0; // From back
        
        int ans = 0;
        int cur = 0;
        for(int i = n-1;i>=0;i--)
        {
            cur += Cumulative_sum + satisfaction[i];
            Cumulative_sum += satisfaction[i];
            
            ans = max(ans,cur);
        }
        
        return ans;
        
    }
};
