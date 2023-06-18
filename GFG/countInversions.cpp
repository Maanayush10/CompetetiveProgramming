#include<bits/stdc++.h>
using namespace std;
    long long merge(long long int arr[], int low, int mid, int high) {
    vector<long long> temp; // temporary array
    long long left = low;      // starting index of left half of arr
    long long right = mid + 1;   // starting index of right half of arr
    long long cnt=0;
    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt+= mid-left+1;
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return cnt;
}

long long mergeSort(long long int arr[], long long low, long long high) {
    long long cnt=0;
    if (low >= high) return cnt;
    long long mid = (low + high) / 2 ;
     cnt+=mergeSort(arr, low, mid);  // left half
     cnt+=mergeSort(arr, mid + 1, high); // right half
     cnt+=merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}
    long long int inversionCount(long long int arr[], long long N)
    {
        // Your Code Here
        long long count=0;
        
        //brute force O(N^2)
        // for(int i=0; i< N; i++)
        // {
        //     for(int j=i; j<N; j++)
        //     {
        //         if(arr[i]>arr[j])
        //         {
        //             count++;
        //         }
        //     }
        // }
        count= mergeSort(arr, 0, N-1 );
        
        
        return count;
    }

};
