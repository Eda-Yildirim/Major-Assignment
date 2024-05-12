
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> meetings(n);
        for (int i = 0; i < n; ++i) {
            meetings[i] = {end[i], start[i]};
        }
        sort(meetings.begin(), meetings.end());
        int cnt = 1;
        int temp = meetings[0].first;
        for (int i = 1; i < n; ++i) {
            if (temp < meetings[i].second) {
                cnt++;
                temp = meetings[i].first;
            }
        }
        return cnt;
    }
};

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    Solution ob;
    int ans = ob.maxMeetings(start, end);
    cout << "The maximum number of meetings that can be conducted: " << ans << endl;
    return 0;
}
