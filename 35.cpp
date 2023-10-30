//35. Prefix representation
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

string infixToPrefix(string infix) {
    int n=infix.size();
    stack<int> operators;
    string prefix;

    string reversedInfix = reverse(infix);

    for (char ch : reversedInfix) {
        if (isOperand(ch)) {
            prefix += ch;
        } else if (ch == ')') {
            operators.push(ch);
        } else if (ch == '(') {
            while (!operators.empty() && operators.top() != ')') {
                prefix += operators.top();
                operators.pop();
            }
            operators.pop(); 
        } else {
            while (!operators.empty() && precedence(operators.top()) > precedence(ch)) {
                prefix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        prefix += operators.top();
        operators.pop();
    }

    prefix=reverse(prefix);

    return prefix;
}



int main(){
    string s="(a+b)*c/a";
    cout<<"Infix :"<<s<<endl;
    cout<<"Prefix :"<<infixToPrefix(s)<<endl;
    return 0;
}