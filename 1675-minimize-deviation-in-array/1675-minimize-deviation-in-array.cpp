class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for(int num : nums) {
            if(num % 2 == 0) {
                s.insert(num);
            } else {
                s.insert(num * 2);
            }
        }
        int minDeviation = *s.rbegin() - *s.begin();
        while(*s.rbegin() % 2 == 0) {
            int maxElement = *s.rbegin();
            s.erase(maxElement);
            s.insert(maxElement / 2);
            minDeviation = min(minDeviation, *s.rbegin() - *s.begin());
        }
        return minDeviation;
    }
};