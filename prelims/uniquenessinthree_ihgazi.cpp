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
    int n,m;
    cin >> n >> m;

    if (n==m) {
        for (int i = 0; i < n; i++)
            cout << 1 << " ";
        cout << "\n";
    }
    else if (m<=2*n-1) {
        vector<int> res(n);
        res[0] = 1;
        res[1] = 2;

        int i = 2, ext = m-n;
        for (int iter = 0; iter < ext-1; iter++) {
            res[i] = 1+i%2;
            i++;
        }

        while (i<n) {
            res[i] = res[i-1];
            i++;
        }

        for (auto &x: res) cout << x << " ";
        cout << "\n";
    }
    else {
        vector<int> res(n);
        int ext = m-(2*n-1);
        res[0] = 1;
        res[1] = 2;
        res[2] = 3;

        int i = 3;
        for (int iter = 0; iter < ext-1; iter++) {
            res[i] = 1+i%3;
            i++;
        }

        while (i<n) {
            res[i] = res[i-2];
            i++;
        }

        for (auto &x: res) 
            cout << x << " ";
        cout << "\n";
    }
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
