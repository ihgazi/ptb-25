
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

void solve() {
    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vi cnt(30,0);
    for (int i = 29; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if ((1ll<<i)&a[j]) cnt[i]++;
        }
    }

    ll x = 0;
    for (int i = 29; i >= 0; i--) {
        if (n-cnt[i] < cnt[i]) {
            x |= (1ll<<i);
            cnt[i] = n-cnt[i];
        }
    }

    ll ans = 0;
    for (int i = 29; i >= 0; i--) 
        ans += cnt[i];

    cout << ans << " " << x << "\n";
}

int main() {
    auto start = chrono::high_resolution_clock::now();
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

