#include <bits/stdc++.h>
using namespace std;
string Pi(string s)
{
    if (s.length() == 0 || s.length() == 1)
        return s;

    if (s[0] == 'p' && s[1] == 'i')
    {
        return "3.14" + Pi(s.substr(2));
    }
    else {
               return s[0] + Pi(s.substr(1));
         }
}
int main()
{

string s="xxpixx";
string str=Pi(s);
cout<<str;
}
