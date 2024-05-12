#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
        vector<string> ans;
        for (int k = 0; k < dictionary.size(); k++) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (board[i][j] == dictionary[k][0]) {
                        helper(board, ans, dictionary[k], "", i, j, 0);
                    }
                }
            }
        }
        set<string> s;
        for (int i = 0; i < ans.size(); i++) {
            s.insert(ans[i]);
        }
        vector<string> result;
        for (auto it : s) {
            result.push_back(it);
        }
        return result;
    }

    void helper(vector<vector<char>>& board, vector<string>& ans, string up, string p, int r, int c, int pos) {
        if (board[r][c] == '*') {
            return;
        }
        char temp = board[r][c];
        p = p + temp;
        if (p == up) {
            ans.push_back(p);
            return;
        }
        board[r][c] = '*';
        if (r > 0 && board[r - 1][c] == up[pos + 1]) {
            helper(board, ans, up, p, r - 1, c, pos + 1);
        }
        if (r > 0 && c < board[0].size() - 1 && board[r - 1][c + 1] == up[pos + 1]) {
            helper(board, ans, up, p, r - 1, c + 1, pos + 1);
        }
        if (c < board[0].size() - 1 && board[r][c + 1] == up[pos + 1]) {
            helper(board, ans, up, p, r, c + 1, pos + 1);
        }
        if (r < board.size() - 1 && c < board[0].size() - 1 && board[r + 1][c + 1] == up[pos + 1]) {
            helper(board, ans, up, p, r + 1, c + 1, pos + 1);
        }
        if (r < board.size() - 1 && board[r + 1][c] == up[pos + 1]) {
            helper(board, ans, up, p, r + 1, c, pos + 1);
        }
        if (r < board.size() - 1 && c > 0 && board[r + 1][c - 1] == up[pos + 1]) {
            helper(board, ans, up, p, r + 1, c - 1, pos + 1);
        }
        if (c > 0 && board[r][c - 1] == up[pos + 1]) {
            helper(board, ans, up, p, r, c - 1, pos + 1);
        }
        if (r > 0 && c > 0 && board[r - 1][c - 1] == up[pos + 1]) {
            helper(board, ans, up, p, r - 1, c - 1, pos + 1);
        }
        board[r][c] = temp;
        return;
    }
};

int main() {
    int t = 1; // Örnek olarak 1 test durumu
    while (t--) {
        vector<string> dictionary = {"GEEKS", "FOR", "QUIZ", "GO"};
        int R = 3, C = 3; 
        vector<vector<char>> board = {
            {'G', 'I', 'Z'},
            {'U', 'E', 'K'},
            {'Q', 'S', 'E'}
        };

        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
