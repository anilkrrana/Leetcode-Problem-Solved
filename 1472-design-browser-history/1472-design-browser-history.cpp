class BrowserHistory {
public:
    int curr, r;
    vector<string> ds;
    BrowserHistory(string homepage) {
      ds.resize(1);
      ds[0] = homepage;
      curr = 0; r = ds.size();
    }
    
    void visit(string url) {
      curr++;
      if(curr == ds.size()){
        ds.emplace_back(url);
        r = ds.size();
      } 
      else {
        r = curr + 1;
        // ds.resize(curr);
        // ds.emplace_back(url);
        ds[curr] = url;
      }
    }
    
    string back(int steps) {
      curr = max(0, curr - steps);
      return ds[curr];
    }
    
    string forward(int steps) {
      curr = min(r - 1, curr + steps);
      return ds[curr];
    }
};
/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */