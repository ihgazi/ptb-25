#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include  "../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define pb push_back
#define BIG 998244353
#define MOD 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

const int MAXN = 2e6;
ll sums[MAXN+1], prefsum[MAXN+1];

ll mult(ll p, ll q, ll m = MOD) {
    return (((p%m)*(q%m))%m);
}

ll binpow(ll p, ll q) {
    if (q == 0) return 1ll;
    ll temp = binpow(p, q/2);
    temp = mult(temp, temp);
    
    if (q%2) return mult(temp, p);
    return temp;
}

ll mod_inv(ll a, ll m = MOD) {
    return binpow(a, m - 2);
}

void precompute() {
    sums[0] = 0, prefsum[0] = 0;
    for (int i = 1; i <= MAXN; i++) {
        sums[i] = (sums[i-1]+i)%MOD;
    }
    for (int i = 1; i <= MAXN; i++) {
        prefsum[i] = (prefsum[i-1]+sums[i])%MOD;
    }
}

void solve() {
    int n;
    cin >> n;

    vector<array<ll,2>> alien;
    ll l,r;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        alien.pb({l,r});
    }

    vi dp(n);
    ll ways = 1;
    ll prevl = 0, prevr = 0;
    dp[0] = (sums[prevr]-sums[max(prevl-1,0ll)]+MOD)%MOD;

    for (int i = 0; i < n; i++) {
        ll l = alien[i][0], r = alien[i][1];
        if (i>0) dp[i] = mult((r-l+1),dp[i-1]);

        ll il = max(l,prevl), ir = min(r,prevr);
        if (il<=ir) {
            ll temp = (prefsum[ir-prevl]-prefsum[max(il-prevl-1,0ll)]+MOD)%MOD;
            dp[i] = (dp[i]+temp)%MOD;
            
            temp = (prefsum[prevr-il]-prefsum[max(prevr-ir-1,0ll)]+MOD)%MOD;
            dp[i] = (dp[i]+temp)%MOD;
        }

        il = max(prevr+1,l), ir = r;
        if (il<=ir) {
            ll a = (sums[ir-prevr]-sums[il-prevr-1]+MOD)%MOD;
            ll cnt = (ir-il+1)%MOD;
            dp[i] = (dp[i]+mult(cnt,sums[prevr-prevl]))%MOD;
            dp[i] = (dp[i]+mult(a,prevr-prevl+1))%MOD;
        }

        il = l, ir = min(r,prevl-1);
        if (il<=ir) {
            ll a = (sums[prevl-il]-sums[prevl-ir-1]+MOD)%MOD;
            ll cnt = (ir-il+1)%MOD;
            dp[i] = (dp[i]+mult(cnt,sums[prevr-prevl]))%MOD;
            dp[i] = (dp[i]+mult(a,prevr-prevl+1))%MOD;
        }

        prevl = l, prevr = r;
        ways = mult(ways,(r-l+1));
    }

    debug(dp[n-1],ways);
    ll exp = mult(dp[n-1],mod_inv(ways))%MOD;
    exp = (exp+n)%MOD;
    cout << exp << "\n";
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    precompute();
    fast_io;
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cerr << "Execution time: " << duration.count() << " seconds" << endl;
    #endif
}
