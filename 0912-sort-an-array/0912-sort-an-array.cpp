class Solution {
public:
    void merge(vector<int>& nums, vector<int>& temp, int left, int mid, int right) {
        int i = left, j = mid + 1, k = left;
        
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k] = nums[i];
                i++;
            }
            else {
                temp[k] = nums[j];
                j++;
            }
            k++;
        }
        
        while (i <= mid) {
            temp[k] = nums[i];
            i++;
            k++;
        }
        
        while (j <= right) {
            temp[k] = nums[j];
            j++;
            k++;
        }
        
        for (i = left; i <= right; i++) {
            nums[i] = temp[i];
        }
    }
    
    void mergeSort(vector<int>& nums, vector<int>& temp, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            mergeSort(nums, temp, left, mid);
            mergeSort(nums, temp, mid + 1, right);
            
            if (nums[mid] > nums[mid + 1]) {
                merge(nums, temp, left, mid, right);
            }
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        mergeSort(nums, temp, 0, n - 1);
        return nums;
    }
};