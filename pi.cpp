#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s="pipi";
    string str="";
    for(int i=0;i<s.length();i++)
    {

        if(s[i]=='p')
        {
            str+="3.14";
            i++;
        }
        else
            str+=s[i];

    }
    cout<<str;
    return 0;
}
