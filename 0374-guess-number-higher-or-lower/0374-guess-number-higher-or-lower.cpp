/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */


class Solution {
	public:
		int guessNumber(int n) 
		{
			long x=1;   //low
			long y=n;   //high
			long mid;
			while(x<=y)
			{
				mid= (x+y)/2;
				if(guess(mid)==1)           //guess API
				{
					x=mid+1;
				}
				else if(guess(mid)==-1)         //guess API
				{
					y=mid-1;
				}
				else
				{
					return mid;
				}
			}
			return x;
    }
};