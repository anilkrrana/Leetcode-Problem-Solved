class Solution {
public:
    string addBinary(string a, string b) {
      int sum = 0;
      int i = a.size()-1;
      int j = b.size() -1;
      string str;
      
      while(i>=0 || j>=0 || sum ==1){
          
          sum += (i>=0)?(a[i]-'0'):0;
          sum += (j>=0)?(b[j]-'0'):0;
          
          // sum can be 0 1 2 3 only
          str = char(sum%2 + '0') + str; // remainder for binary number 
          // sum can be 0 1 2 3 only so, quotient can represent carry
          sum = sum/2; // quotient which is actually a carry, sum == 2 and 3 have carry 1
          
          i--; j--;
      }
       return str;
    }
};