//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) {
            return false;
        }

        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, visited, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col, string& word, int index) {
        if (index == word.length()) {
            return true;  // Word found
        }

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) {
            return false;  // Out of bounds
        }

        if (visited[row][col] || board[row][col] != word[index]) {
            return false;  // Already visited or mismatching character
        }

        visited[row][col] = true;  // Mark the current cell as visited

        // Check in all four directions
        bool found = dfs(board, visited, row + 1, col, word, index + 1) ||
                     dfs(board, visited, row - 1, col, word, index + 1) ||
                     dfs(board, visited, row, col + 1, word, index + 1) ||
                     dfs(board, visited, row, col - 1, word, index + 1);

        visited[row][col] = false;  // Reset the visited status after backtracking

        return found;
    }

    int main() {
        int N, M;
        cin >> N >> M;
    
        vector<vector<char>> board(N, vector<char>(M));
    
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> board[i][j];
            }
        }
    
        string word;
        cin >> word;
    
        Solution solution;
        bool result = solution.isWordExist(board, word);
        cout << (result ? "1" : "0") << endl;
    
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends