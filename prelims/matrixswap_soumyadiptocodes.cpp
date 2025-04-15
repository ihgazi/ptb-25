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

void solve();
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}

bool check(vii &a, vii &b)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            return true;
    }
    return false;
}
void solve()
{
    ll n, m;
    cin >> n >> m;

    vvii a(n, vii(m)), b(n, vii(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> b[i][j];
    }

    vii r, c;
    for (int i = 0; i < n; i++)
    {
        vii temp1 = a[i], temp2 = b[i];
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());

        if (check(temp1, temp2))
        {
            r.push_back(i + 1);
        }
    }

    for (int j = 0; j < m; j++)
    {
        vii temp1, temp2;
        for (int i = 0; i < n; i++)
        {
            temp1.push_back(a[i][j]);
            temp2.push_back(b[i][j]);
        }
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());

        if (check(temp1, temp2))
            c.push_back(j + 1);
    }

    if (r.size() > 0)
        cout << r[0] << " " << r[1] << " ";
    else
        cout << -1 << " " << -1 << " ";

    if (c.size() > 0)
        cout << c[0] << " " << c[1];
    else
        cout << -1 << " " << -1;

    cout << endl;
}
