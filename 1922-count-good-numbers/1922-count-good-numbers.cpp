// class Solution {
// public:
//     long long Power(long N, long long R){
//         if(R==0){
//             return 1;
//         }
//         if(R==1){
//             return (N%1000000007);
//         }
//         long long ans = 1;
        
//         long long know = Power(N, R/2)% 1000000007;
//         if(R%2){
//             ans = (ans*N)% 100000007;
//         }
//         return(ans*((know*know)% 1000000007))% 1000000007;
//     }
//     int countGoodNumbers(long long n) {
//         long long ans = Power(20, n/2);
//         if(n%2){
//             ans= (ans*5)% 1000000007;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    long long power(long long base, long long exponent, long long mod) {
        if (exponent == 0) {
            return 1;
        }
        long long result = 1;
        base = base % mod;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % mod;
            }
            exponent = exponent >> 1;
            base = (base * base) % mod;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        const long long mod = 1000000007;
        
        long long ans = power(20, n / 2, mod);
        
        if (n % 2) {
            ans = (ans * 5) % mod;
        }

        return static_cast<int>(ans);
    }
};
