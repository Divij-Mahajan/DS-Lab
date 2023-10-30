//36. Postfix representation 
#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char c) {
    return (isalpha(c) || isdigit(c));
}

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1; 
}

string reverse(string a){
    int n=a.size();
    string rev="";
    for(int i=n-1;i>=0;i--){
        rev+=a[i];
    }
    return rev;
}

string infixToPostfix(string infix) {
    int n=infix.size();
    stack<int> operators;
    string postfix;

    for (char ch : infix) {
        if (isOperand(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); 
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}



int main(){
    string s="(a+b)*c/a";
    cout<<"Infix :"<<s<<endl;
    cout<<"Postfix :"<<infixToPostfix(s)<<endl;
    return 0;
}
