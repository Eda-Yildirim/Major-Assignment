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
        
        int dp[n];
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (p[i].first > p[j].second && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }

        return *max_element(dp, dp + n);
    }
};

int main() {
    int n = 5; 
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
