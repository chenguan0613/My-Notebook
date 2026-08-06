#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int N;
    cin >> N;
    vector<int> v;
    while (N--)
    {
        int a, b, c, d;
        int x1, y1, x2, y2;
        cin >> a >> b >> c >> d;
        cin >> x1 >> y1 >> x2 >> y2;
        int count_x = 0, count_y = 0;
        if (x1 > a)
            count_x++;
        if (x2 < c)
            count_x++;
        if (y1 > b)
            count_y++;
        if (y2 < d)
            count_y++;
        v.push_back(max(count_x, count_y));
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}