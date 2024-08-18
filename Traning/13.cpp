#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef long double         ld;
typedef pair<ll, ll>        pll;

#define F                   first
#define S                   second
#define len(a)              (ll) (a.size())
#define all(a)              (a).begin(), (a).end()

const ll maxN = 2e6 + 10;
const ll inf  = 7e18 + 7;
const ll mod  = 1e9 + 7 ; // 998244353; // 1e9 + 9;

ll _main() {
    // 0 --> B
    // 1 --> S
    // 2 --> C

    vector<ll> count (3, 0);
    string recipe; cin >> recipe;
    for (ll i = 0; i < len(recipe); i++) {
        if (recipe[i] == 'B')
            count[0]++;
        else if (recipe[i] == 'S')
            count[1]++;
        else
            count[2]++;
    }

    vector<ll> nums (3);
    cin >> nums[0] >> nums[1] >> nums[2];

    vector<ll> price (3);
    cin >> price[0] >> price[1] >> price[2];

    ll money; 
    cin >> money;

    bool ok = true, noNums;
    ll ans = 0, need;
    while (ok) {
        noNums = true;
        for (ll i = 0; i < 3; i++) {
            if (nums[i] >= count[i]) {
                nums[i] -= count[i];
            }
            else {
                need = count[i] - nums[i];
                nums[i] = 0;
                if ((need * price[i]) > money) {
                    ok = false; break;
                }
                else {
                    money -= (need * price[i]);
                }
            }
            noNums &= (nums[i] == 0 || count[i] == 0);
        }

        if (ok) {
            ans++;
        }
        if (noNums) {
            need = 0;
            for (ll i = 0; i < 3; i++) 
                need += (count[i] * price[i]);
            ans += money / need;
            ok = false;
        }
    }


    return cout << ans, 0;
}


signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--)
        _main();

    return 0;
}