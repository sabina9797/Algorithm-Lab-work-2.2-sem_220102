#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int target)
{
    sort(arr, arr + size);
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the number to search: ";
    cin >> target;

    int option;
    cout << "Choose search method:\n1. Linear Search\n2. Binary Search\nEnter your choice: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int linearResult = linearSearch(arr, size, target);
        if (linearResult != -1)
        {
            cout << "Linear Search: Found at index " << linearResult << endl;
        }
        else
        {
            cout << "Linear Search: Not Found" << endl;
        }
        break;
    }
    case 2:
    {
        int binaryResult = binarySearch(arr, size, target);
        if (binaryResult != -1)
        {
            cout << "Binary Search: Found at index " << binaryResult << endl;
        }
        else
        {
            cout << "Binary Search: Not Found" << endl;
        }
        break;
    }
    default:
        cout << "Invalid choice. Exiting." << endl;
        break;
    }

    return 0;
}
