#include<iostream>
using namespace std;

bool Palindrome(int x)
{
    int org, rev=0,rem;
    org=x;
    while(x!=0)
    {
        rem= x%10;
        rev= rev*10+rem;
        x= x/10;
    } 
    if(org==rev && org>=0)  // the number should be greater than zero
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int num;
    cout<<"Enter a Number :\t"<<endl;
    cin>>num;

    bool check=Palindrome(num);

    if(check == true)
    {
        cout<<"The number is a palindrome";
    }
    else
    {
        cout<<"The number is not a Palindrome";
    }


return 0;
}
