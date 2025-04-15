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
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
const ll MOD = 1e9 + 7;
const ll BIG = 998244353;

void sol()
{
    string s; cin>>s;
    string t = "baton";
    if(s.size()<t.size()){
        no;
        return;
    }
    ll i = 0, j = 0;
    while(i<s.size() && j<t.size()){
        if(s[i]==t[j]){
            i++;
            j++;
        }
        else i++;
    }
    if(j>=t.size()) yes;
    else no;
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ll t;
    t = 1;
    cin >> t;
    // precompute();
    // cout<<"here"<<nline;
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

