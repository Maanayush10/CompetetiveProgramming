// sort an array containing 0s,1s,2s without using a sorting algorithm

/*

1 0 1 2 2 1 0 ----> 0 0 1 1 1 2 2

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the value of size :\t";
    int size;
    cin >> size;
    int arr[size];

    cout << "Enter arraty elements:" << endl;

    for (int i = 0; i < size; i++)
    {
        /* code */
        cin >> arr[i];
    }

    int counter0 = 0, counter1 = 0, counter2 = 0;
    for (int i = 0; i < size; i++)
    {
        /* code */
        if (arr[i] == 0)
            counter0++;
        else if (arr[i] == 1)
            counter1++;
        else
            counter2++;
    }
    int k = 0;
    for (int j = 0; j < counter0; j++)
    {
        arr[k++] = 0;
    }
    for (int j = 0; j < counter1; j++)
    {
        arr[k++] = 1;
    }
    for (int j = 0; j < counter2; j++)
    {
        arr[k++] = 2;
    }

    for (int i = 0; i < size; i++)
    {
        /* code */
        cout << arr[i] << " ";
    }

    return 0;
}
