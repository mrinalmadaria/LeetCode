#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> myStack;

        for(int i = 0; i < s.length(); i++){
            char curChar = s[i];

            if(myStack.empty()){
                myStack.push(curChar);
                continue;
            }

            if(curChar == 'B' && myStack.top() == 'A'){
                myStack.pop();
            }else if(curChar == 'D' && myStack.top() == 'C'){
                myStack.pop();
            }else{
                myStack.push(curChar);
            }
        }
        return myStack.size();
    }
};