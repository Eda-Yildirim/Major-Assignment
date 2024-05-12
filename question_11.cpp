#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int findPages(int A[], int N, int M) {
        if (M > N) {
            return -1;
        }
        int end = 0, start = INT_MIN, ans;
        for (int i = 0; i < N; i++) {
            start = max(A[i], start);
            end += A[i];
        }
        int page = 0, count = 0, mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            page = 0, count = 1;
            for (int i = 0; i < N; i++) {
                page = page + A[i];
                if (page > mid) {
                    count++;
                    page = A[i];
                }
            }
            if (count <= M) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    int t = 1;
    while (t--) {
        int N = 4; 
        int M = 2; 
        int A[] = {12, 34, 67, 90};

        Solution ob;
        cout << ob.findPages(A, N, M) << endl;
    }
    return 0;
}
