#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int start;
    int end;
} interval;

bool cmp(interval a, interval b)
{
    return a.end < b.end;
}

interval *intervals;
int n;

int main()
{
    cin >> n;
    intervals = new interval[n];
    for (int i = 0; i < n; i++)
    {
        cin >> intervals[i].start >> intervals[i].end;
    }
    sort(intervals, intervals + n, cmp);
    int last = 0;
    int ans = 1;
    int i = 1;
    while (i < n)
    {
        while (intervals[i].start < intervals[last].end && i < n)
        {
            i++;
        }
        if (i < n)
            ans++;
        last = i;
        i++;
    }
    cout << n - ans << endl;
    return 0;
}