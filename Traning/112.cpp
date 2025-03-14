#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define len(a) (ll) (a.size())
#define all(a) a.begin(), a.end()

const ll maxN = 4e2 + 10;

ll n, m;
string s[maxN];
vector<set<string>> curriculum;

ll nextJ(int i, int j) {
    for (; j < m; j++) {
        if (s[i][j] == '+') {
            return j;
        }
    }
    return -1;
}

ll nextI(int i, int j) {
    for (; i < n; i++) {
        if (s[i][j] == '+') {
            return i;
        }
    }
    return -1;
}

set<string> parse(int I, int J, int rightLen, int downLen) {
    set<string> result;
    for (int i = I; i < I + downLen; i++) {
        string tmp = "";
        for (int j = J; j < J + rightLen; j++) {
            if (s[i][j] != ' ') {
                tmp += tolower(s[i][j]);
            }
            s[i][j] = '-';
        }
        if (len(tmp)) {
            result.insert(tmp);
        }
    }
    return result;
}

void addToSet(set<string>& st, int idx) {
    for (string course: curriculum[idx]) {
        st.insert(course);
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int i = 0;
    string t;
    ll cnt = 0;
    while (true) {
        getline(cin, s[i]);
        if (s[i++][0] == '+') {
            cnt++;
        }
        if (cnt == 2) {
            break;
        }
    }

    n = i;
    m = len(s[0]);

    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '+') {
                ll rgt = nextJ(i, j + 1);
                ll bot = nextI(i + 1, j);
                s[i][j] = s[bot][j] = s[i][rgt] = s[bot][rgt] = '.';
                set<string> res = parse(i + 1, j + 1, rgt - j - 1, bot - i - 1);
                if (len(res)) {
                    curriculum.push_back(res);
                }
            }
        }
    }


    const ll inf = 7e18 + 2;
    ll ans = inf;
    n = len(curriculum);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                set<string> res;
                addToSet(res, i);
                addToSet(res, j);
                addToSet(res, k);
                ans = min(ans, len(res));
            }
        }
    }
    cout << ans;

    return 0;
}