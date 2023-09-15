#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n + 5];
    memset(a, 0, sizeof(a));
    a[1] = 1;
    a[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            a[i] += a[j] * a[i - j - 1];
        }
    }
    cout << a[n] << endl;
    return 0;
}