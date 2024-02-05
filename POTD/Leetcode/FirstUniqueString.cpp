/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
*/

class Solution {
public:

    //TLE
    // int firstUniqChar(string s) {
    //     for(int i=0; i<s.length(); i++)
    //     {
    //         int flag=0;
    //         for(int j=0; j<s.length(); j++)
    //         {
    //             if(s[i]==s[j] && j!=i)
    //             {
    //                 flag=1;
    //             }
    //         }
    //         if(flag==0)
    //         {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

     int firstUniqChar(string s) {
         vector<int> charCount(26, 0);
         for(auto i: s) charCount[i -'a']++;

         for(int i=0; i<s.size(); i++)
         {
             if(charCount[s[i]-'a']==1) return i; //s[i]- 'a' cuz we need to go in the order of charecter in string s, not by alphabetical order
        }
         return -1;
     }
};
