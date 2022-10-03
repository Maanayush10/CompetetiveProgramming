#include<stdio.h>

int tribonacci(int n){
	if(n==0)
    {
        return 0;
    }
    if(n<3)
    {
        return 1;
    }
    int x=0, y=1, z=1, result;
    for(int i=3; i<=n; i++)
    {
        result= x+y+z;
        x=y;
        y=z;
        z=result;
    }
    return result;
}

int main(){
    int num;
    printf("\nEmter a number till which you want the tribonacci series: \t");
    scanf("%d", &num);

    int trib= tribonacci(num);

    printf("\nThe %dth tribonacci number is:  %d\n",num, trib );
return 0;
}