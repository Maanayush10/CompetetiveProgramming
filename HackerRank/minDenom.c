/*Given a value of V Rs and an infinite supply of each of the denominations {1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, The task is to find the minimum number of coins and/or notes needed to make the change*/

//I have added 200 and 2000 denominations as well


#include <stdio.h>
#include <stdlib.h>
int ListOfDen[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
void findMin(int cost)
{
    int i, j = 0;
    // int *reqArr;
    // reqArr = (int *)malloc(sizeof(int));
    int reqArr[20]= {0};
    for (i = 9; i >= 0; i--)
    {
        /* code */
        while (cost >= ListOfDen[i])
        {
            cost = cost - ListOfDen[i];
            reqArr[j++] = ListOfDen[i];
        }
    }

    for (int k = 0; k < j; k++)
    {
        printf("%d ", reqArr[k]);
    }
}

int main()
{
    int cost;
    printf("Enter the cost : \t");
    scanf("%d", &cost);

    printf("Minimum number of Changes: \t");

    findMin(cost);
    printf("\n");

    return 0;
}