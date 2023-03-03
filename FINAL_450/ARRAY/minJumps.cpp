// Minimum jumps to reach the end of the array
#include <bits/stdc++.h>
using namespace std;

int minJumps(int *arr, int start, int end)
{
    int minJumpcount = INT_MAX;
    if (start >= end)
    {
        return 0;
    }
    for (int i = 1; i <= arr[start] && i < end; i++)
    {
        int jumpcount = 1 + minJumps(arr, start + i, end);
        if (minJumpcount > jumpcount)
        {
            minJumpcount = jumpcount;
        }
    }
    return minJumpcount;
}
int main()
{
    int size = 11;
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

    int ans = minJumps(arr, 0, size);
    cout << ans << endl;

    return 0;
}
