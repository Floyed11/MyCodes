#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

void flip(int a[], int k)
{
    for (int i = 0; i < k / 2; i++)
    {
        swap(a[i], a[k - i - 1]);
    }
    cout << k << ' ';
    return;
}
int main()
{
    int n = 0, a[10005], cnt = 0;
    while (cin >> a[n])
    {
        n++;
    }
    cnt = n;
    while (1)
    {
        int k = 0, max = 0;
        for (int i = 0; i < cnt - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                k = 1;
            }
            if (a[i+1] > a[max])
            {
                max = i+1;
            }
        }
        if (k == 0)
        {
            break;
        }
        if (max != 0 && max != cnt - 1)
            flip(a, max + 1);
        // k = 0;
        // for (int i = 0; i < cnt - 1; i++)
        // {
        //     if (a[i] > a[i + 1])
        //     {
        //         k = 1;
        //         break;
        //     }
        // }
        // if (k == 0)
        // {
        //     break;
        // }
        if (max !=cnt-1)flip(a, cnt);
        cnt--;
    }
    cout << '\n';
    return 0;
}