#include <iostream>
#include <vector>
using namespace std;

#define size 100000

void insert(vector<int> &a, int index)
{
    int k = index;
    if (k < 0)
        k = -1 * index;
    if (a[k % size] == 1000000005)
    {
        a[k % size] = index;
    }
    else
    {
        for (int i = (k + 1) % size; i != (k % size); i = (i + 1) % size)
        {
            if (a[i] == 1000000005)
            {
                a[i] = index;
                break;
            }
        }
    }
    return;
}
bool search(vector<int> &a, int index)
{
    int k = index;
    if (k < 0)
        k = -1 * index;
    if (a[k % size] == index)
        return true;
    if (a[k % size] == 1000000005)
        return false;
    for (int i = ((k + 1) % size); i != (k % size); i = (i + 1) % size)
    {
        if (a[i] == 1000000005)
            return false;
        if (a[i] == index)
            return true;
    }
    return false;
}
int main()
{
    int n, index;
    char m;
    cin >> n;
    vector<int> a(100005, 1000000005);
    for (int i = 1; i <= n; i++)
    {
        cin >> m >> index;
        if (m == 'I')
        {
            insert(a, index);
        }
        else if (m == 'Q')
        {
            if (search(a, index))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}