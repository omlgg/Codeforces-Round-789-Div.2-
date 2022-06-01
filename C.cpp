#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
 
int n;
int a[5005];
int pre[5005][5005];
int suf[5005][5005];
int cnt[5005];
 
void inp()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}
 
void proc()
{
    for (int j = 1; j <= n; j++) cnt[j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            pre[i][j] = pre[i][j-1] + cnt[j];
        cnt[a[i]]++;
    }
    for (int j = 1; j <= n; j++) cnt[j] = 0;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
            suf[i][j] = suf[i][j-1] + cnt[j];
        cnt[a[i]]++;
    }
 
    long long ans = 0;
    for (int i = 2; i < n-1; i++)
    for (int j = i+1; j < n; j++)
    {
        ans += pre[i][a[j]]*suf[j][a[i]];
    }
    cout << ans << '\n';
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
