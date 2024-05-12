#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void solve(int row, int col, vector<string>& ans, string& path, vector<vector<int>>& m, int n, vector<vector<int>>& visited) {
        if (row == n - 1 && col == n - 1) {
            ans.push_back(path);
            return;
        }
        int drow[] = { -1, 0, 1, 0 };
        int dcol[] = { 0, 1, 0, -1 };
        char dir[] = { 'U', 'R', 'D', 'L' };
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && visited[nrow][ncol] == 0 && m[nrow][ncol] == 1) {
                visited[nrow][ncol] = 1;
                path += dir[i];
                solve(nrow, ncol, ans, path, m, n, visited);
                visited[nrow][ncol] = 0;
                path.pop_back();
            }
        }
    }
    vector<string> findPath(vector<vector<int>>& m, int n) {
        if (m[0][0] == 0) return { "-1" };
        vector<string> ans;
        string path = "";
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        solve(0, 0, ans, path, m, n, visited);
        return ans;
    }
};

int main() {
    int n = 3; 
    vector<vector<int>> m = {
        {1, 0, 0},
        {1, 1, 1},
        {0, 1, 1}
    };
    
    Solution obj;
    vector<string> result = obj.findPath(m, n);
    sort(result.begin(), result.end());
    if (result.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << endl;

    return 0;
}
