#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int k;
    cin >> k;
    int n = k * k;
    for (int i = 0; i < n; i++)
    {
        int big_shift = k * (i % k);
        int small_shift = i / k;
        int total_shift = big_shift + small_shift;
        for (int j = 0; j < n; j++)
        {
            cout << ((j + total_shift) % n) + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}