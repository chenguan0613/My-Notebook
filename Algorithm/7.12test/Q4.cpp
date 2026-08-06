#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll k, const vector<pair<ll, ll>> &v, ll m)
{
    ll cnt = 0, cur = -1;
    for (auto p : v)
    {
        if (cur >= p.second)
            continue;
        ll st = max(cur + 1, p.first);
        ll len = p.second - st + 1;
        ll need = (len + k - 1) / k;
        cnt += need;
        if (cnt > m)
            return false;
        cur = st + need * k - 1;
    }
    return true;
}
int main()
{
    int t = 0;
    vector<int> res;
    cin >> t;
    while (t--)
    {
        ll n, m, max_r = 0;
        cin >> n >> m;
        vector<pair<ll, ll>> a(n), v;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
            max_r = max(max_r, a[i].second);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            if (v.empty() || v.back().second < a[i].first)
                v.push_back(a[i]);
            else
                v.back().second = max(v.back().second, a[i].second);
        }
        ll l = 1, r = max_r, ans = -1;
        while (l <= r)
        {
            ll mid = l + (r - l) / 2;
            if (check(mid, v, m))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        res.push_back(ans);
    }
    for (auto x : res)
        cout << x << endl;
    return 0;
}