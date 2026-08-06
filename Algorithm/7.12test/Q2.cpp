#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    double n, m, p, q;
    cin >> n >> m >> p >> q;
    double prob = 1.0 * p / q;
    double base = 100.0 / n;
    double bonus = 1.0 / m;
    double normal = base * (prob + (1 - prob) * 0.5);
    double bre = base + bonus * (prob + (1 - prob) * 0.5);
    double ans = (n - m) * normal + m * bre;
    cout << fixed << setprecision(4) << ans << "%" << endl;
    return 0;
}