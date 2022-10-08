#include <stdio.h>
#include<stdlib.h>


int searchInsert(int *nums, int numsSize, int target)
{
    int low, high;
    low = 0;
    high = numsSize;

    do
    {
        int mid = (low + high) / 2;
        if (target == nums[mid])
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }while(low<=high);
    return high+1;
}

int main()
{
    int *nums;
    int numsSize, target;

    nums=(int *)malloc(sizeof(int));
    printf("Enter the size of array:\t");
    scanf("%d", &numsSize);
    printf("Enter array elements :\t");
    for (int i = 0; i < numsSize; i++)
    {
        /* code */
        scanf("%d", &nums[i]);
    }

    printf("Enter the number to be searched :\t");
    scanf("%d", &target);

    int k = searchInsert(nums, numsSize, target);

    printf("The index is : %d\n", k);

    return 0;
}
