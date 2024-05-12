#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    bool isSafe(int id, bool mat[101][101], vector<int>& colors, int n, int col) {
        for (int j = 0; j < n; j++) {
            if (j != id && mat[j][id] == 1 && colors[j] == col) return false;
        }
        return true;
    }

    bool solve(int id, bool mat[101][101], vector<int>& colors, int m, int n) {
        if (id == n) return true;

        for (int i = 1; i <= m; i++) {
            if (isSafe(id, mat, colors, n, i)) {
                colors[id] = i;
                if (solve(id + 1, mat, colors, m, n)) return true;
                colors[id] = 0;
            }
        }
        return false;
    }

    bool graphColoring(bool mat[101][101], int m, int n) {
        vector<int> colors(n, 0);

        if (solve(0, mat, colors, m, n)) {
            return true;
        }
        return false;
    }
};

int main() {
    int n = 4; 
    int m = 3;
    int e = 5;

    bool graph[101][101];
    memset(graph, 0, sizeof(graph));

    // Örnek kenarlar
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[0][3] = graph[3][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;

    Solution ob;
    cout << ob.graphColoring(graph, m, n) << endl;

    return 0;
}
