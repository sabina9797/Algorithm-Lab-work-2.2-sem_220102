
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int numbers[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    int min_value = INT_MAX;
    int max_value = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        min_value = min(min_value, numbers[i]);
        max_value = max(max_value, numbers[i]);
    }

    cout << "Minimum value: " << min_value << endl;
    cout << "Maximum value: " << max_value << endl;

    return 0;
}
