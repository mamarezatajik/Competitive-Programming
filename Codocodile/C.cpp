#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PII;

int main() {
    int n, q, k; cin >> n >> q >> k;
    set<PII> S;
    while (q--) {
        ll op, t; cin >> op >> t;
        if (op == 1) {
            ll x, h; cin >> x >> h;
            S.insert({x, h - t * k});
        } else if (op == 2)
        {
            ll l, r, h; cin >> l >> r >> h;
            h -= t * k;
            while (S.size() && l <= r) {
                auto it = S.lower_bound({l, h});
                if (it == S.end())
                    break;
                if (it -> first > l) {
                    l = it -> first;
                    continue;
                }
                S.erase(it);
            }
        }
        
    }
}