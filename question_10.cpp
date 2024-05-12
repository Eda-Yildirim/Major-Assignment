#include <iostream>
using namespace std;

class Solution {
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i = 0;
        int j = 0;
        int value = -1;
        while (i < n && j < m && k) {
            if (arr1[i] < arr2[j]) {
                if (k == 1) return arr1[i];
                i++;
            }
            else {
                if (k == 1) return arr2[j];
                j++;
            }
            k--;
        }
        while (i < n && k) {
            if (k == 1) return arr1[i];
            i++;
            k--;
        }
        while (j < m && k) {
            if (k == 1) return arr2[j];
            j++;
            k--;
        }
        return -1;
    }
};

int main()
{
    int t = 1; 
    while (t--) {
        int n = 5;
        int m = 4; 
        int k = 5;
        int arr1[] = {2, 3, 6, 7, 9}; 
        int arr2[] = {1, 4, 8, 10};    

        Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k) << endl;
    }
    return 0;
}
