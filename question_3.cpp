#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

class Solution
{
public:
    static bool cmp(Job J1, Job J2) {
        return (J1.dead < J2.dead);
    }

    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr, arr + n, cmp);

        int maxDead = arr[n - 1].dead;
        vector<int> dp(maxDead + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead; j > 0; j--) {
                dp[j] = max(dp[j], dp[j - 1] + arr[i].profit);
            }
        }

        int lastTime = 0, maxProfit = 0;
        for (int i = 1; i <= maxDead; i++) {
            if (dp[i] > maxProfit) {
                maxProfit = dp[i];
                lastTime = i;
            }
        }

        return {lastTime, maxProfit};
    }
};

int main()
{
    int t = 1;

    while (t--) {
        int n = 5;

        Job arr[n] = {
            {1, 2, 100},
            {2, 1, 19},
            {3, 2, 27},
            {4, 1, 25},
            {5, 3, 15}
        };

        Solution ob;
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
