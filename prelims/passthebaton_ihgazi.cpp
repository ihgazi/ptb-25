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

    cout << (n+2)/3 << "\n";
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    fast_io;
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cerr << "Execution time: " << duration.count() << " seconds" << endl;
    #endif
}

