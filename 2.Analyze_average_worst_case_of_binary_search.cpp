#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int target;
    cin >> target;
    int index = -1;  
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == target) {
            index = mid;  
            break;
        }

        if (target > a[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (index != -1) {
        cout << "found " << target << " at index " << index << endl;
    } else {
        cout << "not found" << endl;
    }

    return 0;
}
