#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] != 9) {
                digits[i]++;
                return digits;
            } else {
                digits[i] = 0;
            }
        }

        // If we reach here, it means all digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }

int main()
{
  //main logic here
  return 0;
}
