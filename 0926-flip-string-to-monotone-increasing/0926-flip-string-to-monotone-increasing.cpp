class Solution {
public:
    int minFlipsMonoIncr(string s) {
        if(s.size()==0){
            return 0;
        }
        int countFlips = 0;
        int countOnes = 0;
        for(auto ele:s){
            if(ele=='0'){
                if(countOnes==0)
                    continue;
                else
                    countFlips++;
            }else{
                countOnes++;
            }
            if(countFlips>countOnes){
                countFlips = countOnes;
            }
        }
        return countFlips;
    }
};