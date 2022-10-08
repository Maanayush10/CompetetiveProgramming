#include<bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> charStack;
    for(char &ch : s)
    {
        switch(ch)
        {
           case '(': charStack.push(ch);break;
           case '{': charStack.push(ch);break;
           case '[': charStack.push(ch);break;
           case ')': if(charStack.empty()|| charStack.top()!='(') return false;else charStack.pop();break;
           case '}': if(charStack.empty()|| charStack.top()!='{') return false;else charStack.pop();break;
           case ']': if(charStack.empty()|| charStack.top()!='[') return false;else charStack.pop();break;
           default:;
        }
    }

    return charStack.empty();
}


int main()
{
    string str;
    printf("Enter your parentheses string: \t");
    // scanf("%s", &str);
    cin>>str;

    bool check= isValid(str);

    if(check)
    {
        cout<<"The given string has valid parentheses"<<endl;
    }
    else
    {
        cout<<"The given string doesnot have valid parentheses"<<endl;
    }
}