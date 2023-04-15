#include<bits/stdc++.h>
using namespace std;


/*

flower
flight 
flow

*/

string shortestFunc(vector<string> str)
{
    string shortest = str[0];
    for(int i=0; i<str.size(); i++)
    {
        if(str[i].size()<shortest.size())
        {
            shortest = str[i];
        }
    }
    return shortest;
}
int main(){
    vector<string> str={"flower", "flight", "flow"};
    string shortString= shortestFunc(str);
    int len=0;
    for(int i=0; i<str.size(); i++)
    {
        for (int j = 0; j < shortString.size(); j++)
        {
            /* code */
            if(str[0][j]!=str[i][j])
            {
                len=j;
                break;
            }
        }
        
    }
    cout<<str[0].substr(0, len);

return 0;
}




/*
flower, flow, flight


*/