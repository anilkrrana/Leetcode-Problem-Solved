class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        while (n){
            if(n%2) res = n>0? res *x: res/x;
            x = x*x;
            n /= 2;
        }
        return res;
    }
};

// lets assume that x == 13;
// so we can, say Pow(x, 13) == pow(x, 1)*pow(x,4)*pow(x,8)
// so we can use iterative approach