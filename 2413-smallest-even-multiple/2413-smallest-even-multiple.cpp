class Solution {
public:
    int smallestEvenMultiple(int n) {

        // retun n * (n % 2 + 1);
        return n % 2 == 0 ? n:n * 2;
    }
};