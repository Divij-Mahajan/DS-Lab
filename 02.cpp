//2. Palindrome check 

#include <iostream>
using namespace std;

bool isPalindrome(string s){
    int i=0,n=s.length();
    while(i<n/2){
        if(s[i]!=s[n-i-1]){
            return false;
        }
        i++;
    }
    return true;
}

int main(){
    cout<<isPalindrome("racecar")<<endl;
    cout<<isPalindrome("hello")<<endl;
    cout<<isPalindrome("ab cddc ba")<<endl;
    return 0;
}
