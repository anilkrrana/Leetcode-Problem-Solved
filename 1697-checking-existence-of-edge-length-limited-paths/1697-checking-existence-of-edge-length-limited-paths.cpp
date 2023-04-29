class disjoint_set {
public:
	vector<int> R;
	disjoint_set(int n) : R(n) { iota(R.begin(), R.end(), 0); }
	int find(int i) { return R[i] == i ? i : R[i] = find(R[i]); }
	bool join(int i, int j) { i = find(i); j = find(j); if (i == j) return false; R[i] = j; return true; }
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& el, vector<vector<int>>& qs) {
        disjoint_set ds(n);
        sort(el.begin(), el.end(), [](auto &a, auto &b){return a[2] < b[2];});

        vector<int> idx(qs.size()); // index sorting instead of data sorting
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){return qs[a][2] < qs[b][2];});

        int x = 0;
        vector<bool> ans(qs.size());
        for (auto &i : idx) {
            for (; x < el.size() && el[x][2] < qs[i][2]; x++)
                ds.join(el[x][0], el[x][1]);
            ans[i] = ds.find(qs[i][0]) == ds.find(qs[i][1]);
        }
        return ans;
    }
};