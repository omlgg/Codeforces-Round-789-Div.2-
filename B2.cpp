#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
 
int n;
string s;
pair<int,int> f[200005][2];
 
void inp()
{
    cin >> n;
    cin >> s;
    s = ' ' + s;
}
 
void proc()
{
    for (int i = 1; i <= n; i++)
        f[i][0].fi = f[i][0].se = f[i][1].fi = f[i][1].se = n+1;
    for (int i = 1; i <= n; i++)
    {
        pair <int,int> tmp;
        if (i%2 == 1)
        {
 
            tmp = f[i-1][1];
            tmp.fi += (s[i] != '0');
            tmp.se++;
            f[i][0] = min(f[i][0],tmp);
 
            tmp = f[i-1][0];
            tmp.fi += (s[i] != '1');
            tmp.se++;
            f[i][1] = min(f[i][1],tmp);
        }
        tmp = f[i-1][0];
        tmp.fi += (s[i]!='0');
        f[i][0] = min(f[i][0],tmp);
 
        tmp = f[i-1][1];
        tmp.fi += (s[i] != '1');
        f[i][1] = min(f[i][1],tmp);
    }
    pair <int,int> ans = min(f[n][0],f[n][1]);
    cout << ans.first << ' ' << ans.second+1 << '\n';
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
