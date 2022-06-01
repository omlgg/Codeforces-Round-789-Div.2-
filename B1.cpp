#include <bits/stdc++.h>
using namespace std;
 
 
int n;
string s;
int f[200005][2];
 
void inp()
{
    cin >> n;
    cin >> s;
    s = ' ' + s;
}
 
void proc()
{
    for (int i = 1; i <= n; i++)
        f[i][0] = f[i][1] = n+1;
    for (int i = 1; i <= n; i++)
    {
        if (i%2 == 1)
        {
            f[i][0] = min(f[i-1][1]+('0'!=s[i]),f[i][0]);
            f[i][1] = min(f[i-1][0]+('1'!=s[i]),f[i][1]);
        }
        f[i][0] = min(f[i][0],f[i-1][0]+(s[i]!='0'));
        f[i][1] = min(f[i][1],f[i-1][1]+(s[i]!='1'));
    }
    cout << min(f[n][0],f[n][1]) << '\n';
}
 
void mult()
{
    int t;
    cin >> t;
    while (t--)
    {
        inp();
        proc();
    }
 
}
 
int main()
{
    mult();
    return 0;
}
