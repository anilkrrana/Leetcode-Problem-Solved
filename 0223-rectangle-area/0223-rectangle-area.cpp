class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int h1 = ay2 - ay1;
        int h2 = by2 - by1;
        int w1 = ax2 - ax1;
        int w2 = bx2 - bx1;
        int area = h1 * w1 + h2 * w2;
        int overlapping_h = min(ay2, by2) - max(by1, ay1);
        int overlapping_w = min(ax2, bx2) - max(bx1, ax1);
        if(overlapping_h > 0 && overlapping_w > 0){
            area -= overlapping_h * overlapping_w;
        } 
        return area;
    }
};