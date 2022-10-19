// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// class Solution {
//     public:
//     int firstBadVersion(int n) {
//         long long int beg,last,mid;
//         beg = 1 , last = n;
//         long int pos = 1;
//         while(beg<=last){
//             mid = beg + (last-beg)/2;
//             bool x = isBadVersion(mid);
//             if(x == true){
//                 pos = mid;
//                 last = mid-1;
//             }
//             else
//                 beg = mid+1;
//         }

//         return pos;
//     }
// };

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};