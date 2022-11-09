class StockSpanner {
    stack<pair<int, int>> stk;
    int index = 0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if (stk.empty()) {
            stk.push({price, index++});
            return 1;
        } else {
            while (!stk.empty() && price >= stk.top().first) {
                stk.pop();
            }
            int res = 0;
            res = stk.empty() ? index + 1 : index - stk.top().second;
            stk.push({price, index++});
            return res;
        }
    }
};



// class StockSpanner {
// public:
//     stack<int> storage;
//     vector<int> vec;
//     int i=0;
    
//     StockSpanner() {
        
//     }
    
//     int next(int price) {
//         vec.push_back(price);
//         int res;
//         while(!storage.empty() && price>=vec[storage.top()]) storage.pop();
        
//         res = storage.empty() ? (i+1) : (i-storage.top());
      
//         storage.push(i++);
//         return res;
//     }
// };

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */