/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/


//optimised code:
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>groups;

        for(auto str: strs)
        {
            string sortedStr= str;
            sort(sortedStr.begin(), sortedStr.end());
            groups[sortedStr].push_back(str); 
        }
        vector<vector<string>>result;
        for(auto entry: groups)
        {
            result.push_back(entry.second);
        }
        return result;
    }
};



//BELOW CODE GIVES TLE (brute force)
class Solution {
public:
    bool checkANA(string s1, string s2) {
        unordered_map<char, int> umap1, umap2;
        for (int i = 0; i < s1.length(); i++) {
            umap1[s1[i]]++;
        }
        for (int i = 0; i < s2.length(); i++) {
            umap2[s2[i]]++;
        }
        return umap1 == umap2;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if (strs.size() == 0) {
            return {{""}};
        }

        if (strs.size() == 1) {
            return {{strs[0]}};
        }
        set<string> myset;
        for (int i = 0; i < strs.size(); i++) {
            vector<string> temp;
            if (myset.find(strs[i]) != myset.end()) {
                continue;
            } else {
                for (int j = i + 1; j < strs.size(); j++) {
                    if (checkANA(strs[i], strs[j])) {
                        temp.push_back(strs[j]);
                        myset.insert(strs[j]);
                    }
                }
                temp.push_back(strs[i]);
                if(temp.size()!=0)result.push_back(temp);
            }
            myset.insert(strs[i]);
        }
        return result;
    }
};
