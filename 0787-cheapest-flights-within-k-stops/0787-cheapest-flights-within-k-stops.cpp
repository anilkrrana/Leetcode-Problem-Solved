class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto e : flights) {
            graph[e[0]].push_back({e[1], e[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // {dist_from_src_node, node, number_of_stops_from_src_node}
        pq.push({0, src, 0});
        
        vector<int> stops(n, INT_MAX);
        // number of stops to reach indexth node with least possible price from src node
        // as it will be calculated once the pq.top() equals to indexth node
        
        // pq.top() will always store least cost among the pq elements so if already stop is calculated
        // and if that is greater than the cstop that means already we have a path with cheaper cost
        // as well as with less or equal number of stops
        
        while(!pq.empty()) {
            auto temp=pq.top();
            int cdist=temp[0];
            int cnode=temp[1];
            int cstop=temp[2];
            pq.pop();
            
            if(cstop>stops[cnode] || cstop>k+1)
                continue;
            
            stops[cnode]=cstop;
            if(cnode==dst) {
                return cdist;
            }
            
            for(auto a : graph[cnode]) {
                pq.push({cdist+a.second, a.first, cstop+1});
            }
        }
        return -1;
    }
};