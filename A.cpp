#include <bits/stdc++.h>
using namespace std;


int a[105];
int n;

void inp()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void proc()
{
    int ans = 0;
    sort(a+1,a+n+1);
    if (a[1] == 0)
    {
        for (int i = 1; i <= n; i++)
            if (a[i] != 0) ans++;
        cout << ans <<'\n';
    }
    else
    {
        bool flag = false;
        for (int i = 1; i < n; i++)
            if (a[i] == a[i+1]) flag = true;
        ans = 1 + n - 1;
        if (!flag) ans++;
        cout << ans << '\n';
    }
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
