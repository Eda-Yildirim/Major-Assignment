#include <iostream>
using namespace std;

class Solution {
public:
    int numberSequence(int m, int n) {
        if (m == 0 || n == 1) return m;
        int ans = 0;
        for (int i = m; i >= 1; i--) {
            ans += numberSequence(i / 2, n - 1);
        }
        return ans;
    }
};

int main() {
    int t = 1; 
        int m = 4; 
        int n = 2;

        Solution ob;
        cout << ob.numberSequence(m, n) << endl;
    }
    return 0;
}
