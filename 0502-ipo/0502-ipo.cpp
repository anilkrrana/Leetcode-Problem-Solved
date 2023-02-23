class Solution {
public:

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    priority_queue<int> maxHeap;
    vector<pair<int, int>> projects;
    int n = profits.size();
    
    for(int i = 0; i < n; i++) {
        projects.push_back(make_pair(capital[i], profits[i]));
    }
    sort(projects.begin(), projects.end());
    int curr = 0;
    for(int i = 0; i < k; i++) {
        while(curr < n && projects[curr].first <= w) {
            maxHeap.push(projects[curr].second);
            curr++;
        }
        if(maxHeap.empty()) break;
        w += maxHeap.top();
        maxHeap.pop();
    }
    return w;
}

int main() {
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};
    int k = 2, w = 0;
    cout << findMaximizedCapital(k, w, profits, capital);
    return 0;
}
};