// Evaluate the value of postfix expression string
#include <bits/stdc++.h>
using namespace std;

int main(){
    string postfix;
    cin>>postfix;
    stringstream ss(postfix);
    char token;
    stack<int> s;
    while(ss>>token){
        if((token=='+')||(token=='-')||(token=='*')||(token=='/')){
            int first,second,result;
            second = s.top();
            s.pop();
            first = s.top();
            s.pop();
            if(token=='+') result = first + second;
            else if(token=='-') result = first - second;
            else if(token=='*') result = first * second;
            else if(token=='/') result = first / second;
            s.push(result);
        }
        else{
            s.push(token-'0');
        }
    }
    cout<<s.top();
    s.pop();  
    return 0;
}