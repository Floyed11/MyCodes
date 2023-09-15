#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int gas[n + 5], cost[n + 5], bias[n + 5];
    for (int i = 0; i < n; i++)
        cin >> gas[i];
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    int start = 0, max = -1;
    for (int i = 0; i < n; i++)
    {
        bias[i] = gas[i] - cost[i];
        if (bias[i] > max)
        {
            max = bias[i];
            start = i;
        }
    }
    int flag = 1;
    if (max >= 0)
    {
        int sum = bias[start];
        for (int i = (start + 1) % n; i != start; i = (i + 1) % n)
        {
            sum += bias[i];
            if (sum < 0)
            {
                flag = 0;
                break;
            }
        }
    }
    else
    {
        flag = 0;
    }
    if (flag == 1)
    {
        cout << start << endl;
        return 0;
    }
    else
    {
        cout << -1 << endl;
    }
    // start = 0, max = -1;
    // for (int i = 0; i < n; i++)
    // {
    //     bias[i] = cost[(i + n - 1) % n] - gas[i];
    //     if (bias[i] > max)
    //     {
    //         max = bias[i];
    //         start = i;
    //     }
    // }
    // if (max >= 0)
    // {
    //     int sum = bias[start];
    //     for (int i = (start - 1 + n) % n; i != start; i = (i - 1 + n) % n)
    //     {
    //         sum += bias[i];
    //         if (sum < 0)
    //         {
    //             flag = 0;
    //             break;
    //         }
    //     }
    // }
    // if (flag == 1)
    //     cout << start << endl;
    return 0;
}