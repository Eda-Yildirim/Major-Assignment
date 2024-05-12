#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void genIp2(string& s, int idx, int count, vector<string>& result, string current) {
        if (count == 4 && idx == s.size()) {
            current.pop_back();
            result.push_back(current);
            return;
        }

        if (count == 4 || idx == s.size()) {
            return;
        }

        for (int i = 1; i <= 3; i++) {
            if (idx + i > s.size()) {
                break;
            }

            string part = s.substr(idx, i);
            int val = stoi(part);
            if (val > 255 || (i > 1 && s[idx] == '0')) {
                continue;
            }

            genIp2(s, idx + i, count + 1, result, current + part + '.');
        }
    }

    vector<string> genIp(string& s) {
        vector<string> result;
        string current;
        genIp2(s, 0, 0, result, current);
        return result;
    }
};

int main() {
    int T = 1; 
    while (T--) {
        string s = "25525511135"; 

        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if (str.size() == 0)
            cout << -1 << "\n";
        else {
            for (auto& u : str) {
                cout << u << "\n";
            }
        }
    }
    return 0;
}
