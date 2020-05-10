/*
Parentheses Balance checking using STACK data structure in C++
Code written by Abdus Sukkur
Contact:
    FB: fb.com/abdussukkur85
    email: abdussukkur73@gmail.com
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    char str[10] = "((())())";

    stack<char> myStack;

    for(int i=0; str[i]; i++)
    {
        if(!myStack.empty() && myStack.top()=='(' && str[i]==')')
            myStack.pop();
        else
            myStack.push(str[i]);
    }

    if(myStack.empty())
        printf("%s is Balanced\n", str);
    else
        printf("%s is Not-balanced\n", str);


    return 0;
}
