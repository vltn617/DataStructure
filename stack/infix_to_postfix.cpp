#include <iostream>
#include <string>
#include <stack>

using namespace std;

int priority(char a){
    if (a == '+' || a== '-') return 0;
    
    else if (a == '*' || a== '/') return 1;

    else return 2;
}

string infix_to_postfix (string str){
    string postfix = "";
    stack <char> s;
    int len = str.length();
    
    for (int i = 0; i < len; i++){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            postfix += str[i];
        }
        
        else if (str[i] == '('){
            s.push('(');
        }
        else if (str[i] == ')'){
            while (!s.empty() && s.top() != '('){
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();
        }
        else if (str[i] == '+' || str[i] == '*' || str[i] == '-' || str[i]== '/'){
            while (!s.empty() && priority(s.top()) >= priority(str[i])){
                postfix += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
 
    while (!s.empty()){
        postfix += s.top();
        s.pop();
    }
            
    return postfix;
}

int main(){
    string infix;
    cin >> infix;
    cout << infix_to_postfix(infix);
    return 0;
}