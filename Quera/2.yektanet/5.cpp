#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define mp make_pair

int main() {
    ll t; cin >> t;
    while (t--) {

        ll n1, n2, k, cnt, i, j, sum;
        cin >> n1 >> n2 >> k;
        priority_queue<pair<ll, pii>,
                vector<pair<ll, pii>>,
                greater<pair<ll, pii>>> pq;
        vector<ll> v1 (n1);
        vector<ll> v2 (n2);
        set<pii> s;
        s.insert(mp(0, 0));

        for (i = 0; i < n1; i++)
            cin >> v1[i];
        for (i = 0; i < n2; i++)
            cin >> v2[i];

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        pq.push(mp(v1[0] + v2[0], mp(0, 0)));


        bool flag = true;
        cnt = 0;
        while (flag && (cnt++ < k)) {
            pair<ll, pii> temp = pq.top();
            pq.pop();

            i = temp.second.first;
            j = temp.second.second;

            cout << v1[i] << ' ' << v2[j] << endl;

            flag = false;
            if ((i + 1) < n1) {
                sum = v1[i + 1] * v2[j];
                pii tmp = mp(i + 1, j);

                if (!s.count(tmp)) {
                    s.insert(tmp);
                    pq.push(mp(sum, tmp));
                }
                flag = true;
            }
            if ((j + 1) < n2) {
                sum = v1[i] * v2[j + 1];
                pii tmp = mp(i, j + 1);

                if (!s.count(tmp)) {
                    s.insert(tmp);
                    pq.push(mp(sum, tmp));
                }
                flag = true;
            }
        }
    }
	return 0;
}