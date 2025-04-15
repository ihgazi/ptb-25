#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007
#define ff first
#define ss second
typedef vector<ll> vii;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
typedef vector<vii> vvii;

ll MAXN = 5000;
void input(vpii &v, ll n)
{
    for (int i = 0; i < n; i++)
    {
        ll a, t;
        cin >> a >> t;
        v[i] = {a, t};
    }
}
void precompute(vpii &v, vii &dp, ll n)
{
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = MAXN - v[i].first; j >= 0; j--)
        {
            dp[j + v[i].first] = min(dp[j + v[i].first], dp[j] + v[i].second);
        }
    }

    for (int i = MAXN - 1; i >= 0; i--)
    {
        dp[i] = min(dp[i], dp[i + 1]);
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;

    vpii physics(n), chemistry(m), maths(k);

    input(physics, n);
    input(chemistry, m);
    input(maths, k);

    vii dp_phy(MAXN + 1, 1e17), dp_che(MAXN + 1, 1e17), dp_math(MAXN + 1, 1e17);

    precompute(physics, dp_phy, n);
    precompute(chemistry, dp_che, m);
    precompute(maths, dp_math, k);

    ll q;
    cin >> q;
    while (q-- > 0)
    {
        ll T;
        cin >> T;

        ll l = 0, r = MAXN;
        while (r - l > 1)
        {
            ll mid = (l + r) / 2;
            if (dp_phy[mid] + dp_che[mid] + dp_math[mid] <= T)
                l = mid;
            else
                r = mid;
        }
        ll ans = l;
        if (dp_phy[r] + dp_che[r] + dp_math[r] <= T)
            ans = r;

        cout << ans << " ";
    }
}
