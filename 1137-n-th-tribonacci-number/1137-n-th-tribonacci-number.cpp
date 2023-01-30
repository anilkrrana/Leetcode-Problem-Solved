class Solution {
public:
     int tribonacci(int n) {
        if (n < 2) return n;    
        
        int T0 = 0, T1 = 1, T2 = 1, Tn = T0 + T1 + T2; 
        while (n-- > 2) {
            Tn = T0 + T1 + T2, T0 =T1, T1 = T2, T2 = Tn;
        }
        return T2;
    }
};