#include <string>
#include<iostream>
using namespace std;

bool isPalindrome(string s) {
    int i,j;
    i=0;
    j=s.length()-1;
    while(i<j){
        while((s[i]<'A'||s[i]>'Z')&&(s[i]<'a'||s[i]>'z')&&(s[i]<'0'||s[i]>'9')){
            i++;
        }
        while((s[j]<'A'||s[j]>'Z')&&(s[j]<'a'||s[j]>'z')&&(s[j]<'0'||s[j]>'9')){
            j--;
        }
        if(s[i]!=s[j]&&abs(s[i]-s[j])!=32)
            return false;
        i++;
        j--;
    }
    return true;
}

int main(){
    string str = "Was it a car or a cat I saw?";
    cout << isPalindrome(str);
}