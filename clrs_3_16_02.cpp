#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int nums[100010], n = 1;

int search(int a[], int mid, int l, int r)
{
    int temp = 0, ret = 0;
    for (int i = mid - 1; i >= l; i--)
    {
        temp += a[i];
        ret = max(temp, ret);
    }
    int ret2 = 0;
    temp = 0;
    for (int i = mid + 1; i <= r; i++)
    {
        temp += a[i];
        ret2 = max(temp, ret2);
    }
    return (a[mid] + ret + ret2);
}

int array_MAX(int a[], int l, int r)
{
    if (l == r)
        return a[l];
    int mid = (l + r) / 2;
    int MAX_l = array_MAX(a, l, mid);
    int MAX_r = array_MAX(a, mid + 1, r);
    int MAX_m = search(a, mid, l, r);
    int temp = max(MAX_l, MAX_r);
    temp = max(temp, MAX_m);
    return temp;
}

int main()
{
    while (scanf("%d", &nums[n]) != EOF)
    {
        n += 1;
    }
    n -= 1;
    int ans = array_MAX(nums, 1, n);
    printf("%d\n", ans);
    return 0;
}