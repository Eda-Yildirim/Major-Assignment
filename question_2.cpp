#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
        if (J1.dead != J2.dead)
            return J1.dead < J2.dead;
        return J1.profit > J2.profit;
    }

    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr, arr + n, cmp);
        int curr = 0;
        int p = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++) {
            Job J1 = arr[i];
            if (curr < J1.dead) {
                curr++;
                pq.push(J1.profit);
            }
            else if (curr == J1.dead and pq.top() < J1.profit) {
                pq.pop();
                pq.push(J1.profit);
            }
        }

        while (!pq.empty()) {
            p += pq.top();
            pq.pop();
        }

        return { curr, p };
    }
};

int main()
{
    // Number of test cases
    int t = 1;

    while (t--) {
        int n = 5; // Number of jobs

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
