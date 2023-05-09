//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// #include <iostream>
// using namespace std;

class Solution{
public:
    const long M = 1000000007; 
    map<long, long> F;
    long long f(long long n)
    {
        if (F.count(n)) return F[n];
        long k = n / 2;
        if (n % 2 == 0) return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % M;
        return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % M;
    }
    int countStrings(long long int N)
    {
        F[0] = 1;
        F[1] = 1;
        return f(N + 1);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int N;
        cin >> N;
        Solution obj;
        cout << obj.countStrings(N) << endl;
    }
}
// } Driver Code Ends