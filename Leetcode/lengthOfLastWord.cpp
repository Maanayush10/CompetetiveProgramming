#include<bits/stdc++.h>
using namespace std;
int lengthOfLastWord(string s) {
        int count=0;
        bool flag=false;
        for(int i=s.size()-1; i>=0; i--)
        {
            if(s[i]==' ' && flag==true)
            {
                break;
            }
            else if(s[i]!=' ')
            {
                flag= true;
                count++;
            }
        }

        return count;
    }
int main(){
    string s="I am Ayushman and I am the Best";
    Solution sol;
    int size=sol.lengthOfLastWord(s);

    cout<<"Length of last word: "<<size<<endl;

return 0;
}
