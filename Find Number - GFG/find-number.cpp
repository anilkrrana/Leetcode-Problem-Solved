//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++



class Solution{
public:
    long long help(long long n)
    {   
        if(n<6) return n+(n-1);
        if(n%5 == 0) return ((help((n/5) - 1))*10) + 9;
        else return (help(n/5)*10) + (n%5)+(n%5)-1;
    }
    long long findNumber(long long N){
        return help(N);
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends