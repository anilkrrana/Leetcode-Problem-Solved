//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
         int res=1;

       int sum=0;

       int min=*min_element(arr,arr+n);

       if(s<min){

           return{-1};

       }

       for(int i=0;i<n;i++){

           sum=sum+arr[i];

           if(sum==s){

               return {res,i+1};

           }

           if(sum>s){

               while(sum>=s){

                   sum=sum-arr[res-1];

                   res=res+1;

                   if(sum==s){

                       return{res,i+1}; 

                   }

               }

           }

       }

       return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends