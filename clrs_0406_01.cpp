#include <iostream>
using namespace std;

int sort(int a[], int k, int l, int r)
{
    int pilot = l;
    int pl = l, pr = r;
    while (pl < pr)
    {
        while (a[pl] <= a[pilot] && pl <= r)
        {
            pl++;
        }
        while (a[pr] > a[pilot] && pr >= l)
        {
            pr--;
        }
        if (pl < pr)
        {
            int tmp = a[pl];
            a[pl] = a[pr];
            a[pr] = tmp;
        }
    }
    int tmp = a[pl - 1];
    a[pl - 1] = a[pilot];
    a[pilot] = tmp;
    if ((pl - 1) == k)
    {
        return a[pl - 1];
    }
    else if ((pl - 1) > k)
    {
        return sort(a, k, l, pl - 2);
    }
    else
    {
        return sort(a, k, pl, r);
    }
}

int main()
{
    int nums[10005], k, p = 1;
    while (cin >> nums[p])
    {
        p++;
    }
    k = nums[p - 1];
    p = p - 2;
    k = p - k + 1;
    // cout<<k<<'\n';
    int ans = sort(nums, k, 1, p);
    cout << ans;
    cout << '\n';
    return 0;
}