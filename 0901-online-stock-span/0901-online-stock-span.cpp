// class StockSpanner {
//     stack<pair<int, int>> storage;
//     int index = 0;
// public:
//     StockSpanner() {
        
//     }
    
//     int next(int price) {
//         if (storage.empty()) {
//             storage.push({price, index++});
//             return 1;
//         } else {
//             while (!storage.empty() && price >= storage.top().first) {
//                 storage.pop();
//             }
//             int res = 0;
//             res = storage.empty() ? index + 1 : index - storage.top().second;
//             storage.push({price, index++});
//             return res;
//         }
//     }
// };



class StockSpanner {
public:
    stack<int> storage;
    vector<int> vec;
    int i=0;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        vec.push_back(price);
        int res;
        while(!storage.empty() && price>=vec[storage.top()]) storage.pop();
        
        res = storage.empty() ? (i+1) : (i-storage.top());
      
        storage.push(i++);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */