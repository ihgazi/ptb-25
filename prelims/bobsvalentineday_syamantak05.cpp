#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nline "\n"
#define pii pair<ll, ll>
#define vi vector<ll>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define vvi vector<vi>
#define vpii vector<pii>
#define ff first
#define ss second
#define mkp make_pair
#define pb emplace_back
#define vvb vector<vector<bool>>
#define vvpii vector<vector<pii>>
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 + 7;
const ll MODD = 998244353;

int path[200001];
vi pending[200001];
// vi start[200001];
int level[200001];
bool vis[200001];
vi adj[200001];

void sol()
{
    ll n, q;
    cin >> n >> q;
    ll tmp1, tmp2;
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> tmp1 >> tmp2;
        adj[tmp1].pb(tmp2);
        adj[tmp2].pb(tmp1);
    }
    queue<ll> qq;
    qq.push(1ll);
    vis[1] = 1;
    ll cur = 0;
    while (!qq.empty())
    {
        ll sz = qq.size();
        while (sz--)
        {
            ll node = qq.front();
            qq.pop();
            level[node] = cur;
            for (auto &it : adj[node])
                if (!vis[it])
                {
                    vis[it] = 1;
                    qq.push(it);
                }
        }
        cur++;
    }
    vvi queries;
    vi ans(q, -1);
    for (ll j = 0; j < q; j++)
    {
        ll m;
        cin >> m;
        vi temp(m);
        ll mnlvl = 1e9, strt = 0;
        ll mxlvl = -1, endd = 0;
        for (ll i = 0; i < m; i++)
        {
            cin >> temp[i];
            if (level[temp[i]] < mnlvl)
            {
                mnlvl = level[temp[i]];
                strt = temp[i];
            }
            if (level[temp[i]] > mxlvl)
            {
                mxlvl = level[temp[i]];
                endd = temp[i];
            }
        }
        temp.pb(endd);
        pending[endd].pb(j);
        queries.pb(temp);
        // start[strt].pb(queries.size() - 1);
    }

    //queries keep track of queries in the qn. the last element of queries[i] is the element at max depth
    //pending[i] is a list of the queries which has i as the deepest node
    //path[i] is true if the current dfs chain has i in it


    path[1] = 1;
    auto dfs = [&](auto &&dfs, ll node, ll parent) -> void
    {
        for (auto &it : adj[node])
            if (it != parent)
                path[it] = 1;
        if (!pending[node].empty())
        {
            for (auto &it : pending[node])
            {
                bool flag = true;
                for (ll i = 0; i < queries[it].size() - 1; i++)
                {
                    if (!path[queries[it][i]])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    ans[it] = 1;
                else
                    ans[it] = 0;
            }

            pending[node].clear();
        }

        for (auto &it : adj[node])
            if (it != parent)
                dfs(dfs, it, node);

        for (auto &it : adj[node])
            if (it != parent)
                path[it] = 0;
    };

    dfs(dfs, 1, 0);

    for (auto &it : ans)
    {
        if (it == 1)
            yes;
        else
            no;
    }
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ll t;
    t = 1;
    // cin >> t;
    // precompute();
    for (ll i = 1; i <= t; i++)
    {

        sol();
        // cout<<"Hello\n";
    }
#ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;
#endif
    //  cout << ans;
    //   sol();
}
