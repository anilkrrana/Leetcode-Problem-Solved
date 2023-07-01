class Solution {
public:
    bool check(int s, vector<int>a, int k)// a function to see if given sum s, can array a  be divided into  k parts, such that
        // sum of each part is just less than equal to s . we  take parts to have sum as close to s as possible,
        // now if no of parts <=k, then for less case we can easily increase no of parts to k, unless k>n but then it will never be possible to divide and that case is not in the constraints,
        //we check for all possiblities by checking all permutations
    {
        
        do{
        int parts=0;
        //remember to count in last part
        int sum=0;
        int n= a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i]>s)return false;
            sum+=a[i];
            if(sum >s)
            {
                sum=a[i];
                parts++;
            }
        }
        parts++;
        if(parts<=k)return true;
        } while(next_permutation(a.begin(),a.end()));
        return false;
        
    }
    int distributeCookies(vector<int>& cookies, int k) {
                  sort(cookies.begin(), cookies.end());
                int l=0;
        int r= 1000000;
        int ans=-1;
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(check(mid,cookies,k))
            {
                 ans= mid;
                r= mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};