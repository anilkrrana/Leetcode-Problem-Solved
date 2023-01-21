// class Solution {
// public:
//     // Helper function to check if a given string is a valid IP address segment
//     bool valid(string temp){
//         if(temp.size()>3 || temp.size()==0) return false; // segment length should be between 1 and 3
//         if(temp.size()>1 && temp[0]=='0')   return false; // segment should not start with 0, unless it is a single digit
//         if(temp.size() && stoi(temp)>255) return false; // segment should not be greater than 255
//         return true;
//     }

//     // Backtracking function to generate all possible IP addresses
//     void solve(vector<string>& ans, string output, int ind, string s, int dots){
//         if(dots == 3){ // if we have already added 3 dots, check if the remaining segment is valid
//             if(valid(s.substr(ind)))
//                 ans.push_back(output+s.substr(ind));
//             return;
//         }
//         int sz = s.size();
//         for(int i=ind;i<min(ind+3, sz);i++){
//             if(valid(s.substr(ind, i-ind+1))){
//                 output.push_back(s[i]);
//                 output.push_back('.');
//                 solve(ans, output, i+1, s, dots+1);
//                 output.pop_back(); //backtrack
//             }
//         }

//     }

//     vector<string> restoreIpAddresses(string s) {
//         vector<string> ans;
//         string res;
//         solve(ans, res, 0, s, 0);
//         return ans;
//     }
// };




class Solution {
public:
    bool check(string s){
        int n=s.size();
        //if the size of string is 1 that is always possible so return true
        if(n==1){
            return true;
        }
        //if we have length >3 or string starts with 0 return false
        if(n>3||s[0]=='0'){
            return false;
        }
        //we are converting string to integer to check if it is less than equalto 255
        int val=stoi(s);
        if(val>255){
            return false;
        }

        //return true at last
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        //we will store our ans in ans vector of strings
        vector<string>ans;
        //the max length of the ip address could be 12 as 255.255.255.255 so 
        //all the string s with size greater than 12 can have ans
        if(n>12){
            return ans;
        }
        //now we have our string of length 12 or less than 12 so now 
        //1. we have to spit the s in parts such that it satisfy the ip address conditions
        //2. if all 4 strings satisfy the condition we will push into ans vector
        
        for(int i=1;i<=3;i++){//for the length before first '.'
            for(int j=1;j<=3;j++){//for the length between first and second '.'
                for(int k=1;k<=3;k++){//for the length between second and third '.'
                    //checking condition if the last segment is of length 3 or less
                    if(i+j+k<n&&i+j+k+3>=n){
                        //dividing the s int substrings 
                        string a=s.substr(0,i);
                        string b=s.substr(i,j);
                        string c=s.substr(j+i,k);
                        string d=s.substr(i+j+k);
                        //if all the substring satisfy the check function condition 
                        //then we will push into ans vector 
                        if(check(a)&&check(b)&&check(c)&&check(d)){
                            ans.push_back(a+"."+b+"."+c+"."+d);
                        }
                    }
                }
            }
        }
        //return the ans vector
        return ans;
    }
};