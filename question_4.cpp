#include <iostream>
#include <algorithm>

using namespace std;

struct val {
    int first;
    int second;
};

class Solution {
public:
    int maxChainLen(struct val p[], int n) {
        sort(p, p + n, [](val a, val b) {
            return a.second < b.second;
        });
        int curr = INT_MIN;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (curr < p[i].first) {
                curr = p[i].second;
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    int n = 5; // Örnek olarak 5 çift girilecek
    val p[n] = {
        {5, 24},
        {39, 60},
        {15, 28},
        {27, 40},
        {50, 90}
    };

    Solution ob;
    cout << "Max chain length: " << ob.maxChainLen(p, n) << endl;

    return 0;
}
