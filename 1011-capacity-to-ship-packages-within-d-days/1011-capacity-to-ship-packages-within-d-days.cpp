class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
         int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);
    while (left < right) {
        int mid = (left + right) / 2;
        int curr_weight = 0;
        int curr_days = 1;
        for (int weight : weights) {
            if (curr_weight + weight > mid) {
                curr_weight = weight;
                curr_days++;
            } else {
                curr_weight += weight;
            }
        }
        if (curr_days > days) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
        return left;    
    }
};

