// class MedianFinder {
// private:
//     int size; 
//     multiset<int> numsSet;
//     multiset<int>::iterator midIter;
// public:

//     // Adds a number into the data structure.
//     void addNum(int num) 
//     {
//         if(numsSet.empty())
//         {
//             midIter = numsSet.insert(num);
//             size++;
//             return ; 
//         }
//         numsSet.insert(num);
//         if((size&1) && num<*midIter) --midIter; 
//         else if(!(size&1) && num>=*midIter) ++midIter;
//         size++;
//     }

//     // Returns the median of current data stream
//     double findMedian() 
//     {
//         if(size & 1) return *midIter;   
//         else return (double)(*midIter+*next(midIter))/2;
//     }
// };


class MedianFinder {
public:
    
    // we will use heaps (min and max) to get the median using . We will try to keep them balanced on basis of their size so that at    end we will have the medians at top.
    
	// we are using min and max beacuse we will maintain our heaps in a way that max of max heap will always be lesser than equal to min of min Heap in this way we be able to get the medians
    priority_queue<int,vector<int>,greater<int>> min;
    priority_queue<int> max;
    MedianFinder() {}
    
    void addNum(int num) {
        // we are trying to maintain a stream i.e., maxH.top() <= minH.top() in that way only we can assure the medians
        if(max.empty() || num<max.top()){
            max.push(num);
        }
        // incase we encounter greater number than the one present in maxH we need to add it in minH 
        else{
            min.push(num);
        }
        // we are trying to balance our heaps the max diff of size can be only 1
        // therefore popping the extra from that heap and pushing that in the other one
        if(max.size()>min.size()+1){
            min.push(max.top());
            max.pop();
        }
        else if(min.size()>max.size()+1){
            max.push(min.top());
            min.pop();
        }
    }
    
    double findMedian() {
        // this operation is going to be O(1)
        // incase of even entries
        if(max.size() == min.size()){
            // we will find mean of middle 2 entries and return 
            return (max.top() + min.top()) / 2.0;
        }
        // incase of odd entries:
        // our median will be present in that heap which has greater size
        else{
            return max.size() > min.size() ? max.top() : min.top();
        }
        
    }
};

// /**
//  * Your MedianFinder object will be instantiated and called as such:
//  * MedianFinder* obj = new MedianFinder();
//  * obj->addNum(num);
//  * double param_2 = obj->findMedian();
//  */