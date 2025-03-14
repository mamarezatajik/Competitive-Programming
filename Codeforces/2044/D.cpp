#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

mt19937_64 rng((unsigned ll) chrono::steady_clock::now().time_since_epoch().count());

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 2e5 + 10;
const ll inf  = 7e18 + 7;
const ll lg   = 20   + 2;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;


ll n, m, k, q, u, v, w, x, y, z, l, r;
ll a[maxN], b[maxN];


ll _main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = 0;
    }

    map<ll, ll> cnt;
    ll mxm = a[0], idx;
    b[0] = mxm;
    cnt[mxm] = 1;
    queue<ll> savePos;
    for (int i = 1; i < n; i++) {
        savePos.push(i);
        if (cnt[a[i]] == cnt[mxm]) {
            continue;
        } else {
            while (cnt[a[i]] != cnt[mxm]) {
                idx = savePos.front(); 
                savePos.pop();
                cnt[a[i]]++;
                b[idx] = a[i];
            }
        }
    }

    set<pll> st;
    for (int i = 1; i <= n; i++) {
        st.insert({0, i});
    }

    map<ll, ll> ctr;
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            auto [count, number] = *st.begin();
            st.erase({count, number});
            st.insert({count + 1, number});
            cout << number << ' ';
        }
        else {
            st.erase({ctr[b[i]], b[i]});
            st.insert({ctr[b[i]] + 1, b[i]});
            cout << b[i] << ' ';
            ctr[b[i]]++;
        }
    }

    return cout << "" << '\n', 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        _main();
    }
    return 0;
}