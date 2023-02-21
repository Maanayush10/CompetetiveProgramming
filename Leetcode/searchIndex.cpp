//Leetcode Search Insert Position Problem
#include <iostream>
using namespace std;

int binarySearch(int *arr, int key, int start, int end)
{
    int mid = (start + end) / 2;
    if (start > end)
    {
        // return mid;
        if (key > arr[mid])
        {
            return mid + 1;
        }
        if (key < arr[mid])
        {
            return mid - 1;
        }
    }

    if (arr[mid] == key)
    {
        return mid;
    }
    if (key > arr[mid])
    {
        return binarySearch(arr, key, mid + 1, end);
    }
    if (key < arr[mid])
    {
        return binarySearch(arr, key, start, mid - 1);
    }
    return -1;
}
int main()
{
    int *arr;
    arr = (int *)malloc(sizeof(int));

    int size, key;

    cout << "Enter the size of the array :\t";
    cin >> size;

    cout << "Enter the elements of the array :\t";

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the Key:\t";
    cin >> key;

    int index = binarySearch(arr, key, 0, size - 1);

    cout << "The index returned is: \t" << index << endl;

    return 0;
}
