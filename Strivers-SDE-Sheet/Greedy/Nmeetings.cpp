#include<bits/stdc++.h>
using namespace std;
struct meeting{
        int startingTime;
        int endingtime;
        int index;
    };
    
    static bool comparator(struct meeting m1, meeting m2)
    {
        if(m1.endingtime < m2.endingtime){return true;}
        else if(m1.endingtime > m2.endingtime){return false;}
        else if(m1.index < m2.index){return true;}
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct meeting meet[n];
        for(int i=0; i<n; i++)
        {
            meet[i].startingTime= start[i];
            meet[i].endingtime= end[i];
            meet[i].index= i;
        }
        
        std::sort(meet, meet+n, comparator);
        
        int endTimeLatest= meet[0].endingtime;
        int count=1;
        for(int i=0; i<n; i++)
        {
            if(meet[i].startingTime > endTimeLatest)
            {
                count++;
                endTimeLatest= meet[i].endingtime;
            }
            else
            {
                continue;
            }
        }
        return count;
    }
int main()
{

  //main logic here
  return 0;
}
