#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
 
int n,m;
int a[1000005];
string s;
int ans[1000005];
int col[1000005];
int row[1000005];
 
void inp()
{
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < n*m; i++)
        a[i] = s[i]-'0',ans[i] = 0;
}
 
void proc()
{
    int good = 0;
    for (int i = 0; i < n*m; i++) row[i] = col[i] = 0;
    for (int i = 0; i < n*m; i++)
    {
        if (col[i%m] == 0 && a[i] == 1)
        {
            good++;
        }
        col[i%m] += a[i];
        ans[i] += good;
    }
 
 
    int sum = 0;
    for (int i = 0; i < n*m; i++)
    {
        sum += a[i];
 
        if (i >= m)
        {
            sum -= a[i-m];
        }
        if (sum > 0)
                row[i]++;
    }
 
    for (int i = m; i < n*m; i++)
        row[i]+=row[i-m];
    for (int i = 0; i < n*m; i++)
        ans[i] += row[i];
 
    for (int i = 0; i < m*n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
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
