#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*Example:

if we have 19
according to the problem:
    1 + 81 = 82
    64 + 4 = 68
    36 + 64 = 100
    1+0+0=1
    hence 19 is a happy number.
*/

bool isHappy(int n)
{
    set<int> s;
    while (s.count(n) == 0) // check if the same number is present in the set or not
    {
        if (n == 1)
            return true; // if n==1 return true as it fullfills the conditions
        s.insert(n);

        int temp = 0; // temp variable to store the squares

        while (n)
        {
            temp += (n % 10) * (n % 10); // squaring each digit
            n = n / 10;                  // reducing the number by each digit
        }
        n = temp; // making 'temp' as the new number
    }
    return false;
}

//main function

int main()
{
    int n = 19;

    if (isHappy(n))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
