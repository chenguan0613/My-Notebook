#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int t;
    cin >> t;
    vector<ll> res;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++)
            cin >> a[i];
        vector<int> dp(N, 0);
        ll ans = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] = max(dp[i], dp[j] + gcd(a[i], a[j]));
            }
            ans = max(ans, (ll)dp[i]);
        }
        res.push_back(ans);
    }
    for (auto x : res)
    {
        cout << x << "\n";
    }
    return 0;
}