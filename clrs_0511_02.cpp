#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 5];
    memset(a, 0, sizeof(a));
    a[0] = 1;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= j; i++)
        {
            a[j] += a[i - 1] * a[j - i];
        }
    }
    cout << a[n] << endl;
    return 0;
}