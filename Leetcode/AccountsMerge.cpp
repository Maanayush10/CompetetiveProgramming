/*

721. Accounts Merge
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Example 2:

Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
 

Constraints:

1 <= accounts.length <= 1000
2 <= accounts[i].length <= 10
1 <= accounts[i][j].length <= 30
accounts[i][0] consists of English letters.
accounts[i][j] (for j > 0) is a valid email.

*/

/*see Striver's explaination for clarity*/
/*

Approach
1) Initialize Disjoint Set:   Create an instance of the DisjointSet class for n accounts to manage the union-find operations for email grouping.

2) Map Emails to Accounts:    Use an unordered map mapMailNode to store the mapping of each email to its corresponding account index.
Traverse through each email in each account. If an email is not in the map, add it with its account index. If it is already in the map, union the current account index with the stored index.
Group Emails by Root Accounts:

3)Create an array mergedMail of vectors to store grouped emails:  For each email in the map, find the representative (root) account index using the findPar method and add the email to the corresponding group in mergedMail.
Sort and Prepare Final Result:

4)Traverse through the mergedMail array:   For each non-empty group, sort the emails and create a temporary vector temp.
Add the account name (first element of the corresponding account) to temp, followed by the sorted emails.

5)Build and Return Result:    Add the temp vector to the final result vector result for each non-empty group in mergedMail.
Return the result vector containing merged account information.

*/
class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v)
            return; // they belong to the same component
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mapMailNode;
        DisjointSet ds(accounts.size());
        vector<vector<string>> result;
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    ds.unionByRank(i, mapMailNode[mail]);
                }
            }
        }
        vector<string> mergedMail[accounts.size()];
        for (auto it : mapMailNode) {
            int node = ds.findPar(it.second);
            string mail = it.first;
            mergedMail[node].push_back(mail);
        }
        for (int i = 0; i < accounts.size(); i++) {
            if (mergedMail[i].size() == 0)
                continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergedMail[i]) {
                temp.push_back(it);
            }
            result.push_back(temp);
        }
        return result;
    }
};
