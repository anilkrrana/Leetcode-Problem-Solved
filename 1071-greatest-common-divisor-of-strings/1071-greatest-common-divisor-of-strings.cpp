class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1)? 
        str1.substr(0, gcd(size(str1),size(str2))): "";
    }
};



// class Solution {
// public:
//     int gcd(int num1,int num2){
//         if(num1 < num2) swap(num1, num2);
//         for(int i = num2; i >= 1; i--){
//             if(num1%i == 0 && num2 %i == 0) return i;
//         }
//         return 1;
//     }
//     string gcdOfStrings(string str1, string str2) {
//         string ans;
//         if(str1 + str2 != str2 + str1) return "";
//         else{
//             int len = gcd(str1.length(), str2.length());
//             ans = str1.substr(0, len);
//         }
//         return ans;
//     }
// };