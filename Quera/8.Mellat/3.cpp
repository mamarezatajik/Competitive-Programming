#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxN = 2e6 + 10;
const ll mod = 1e9 + 7;
const ll base = 31;

ll n, q, st[4 * maxN], pows[maxN];
string s;

// Precompute powers of the base modulo `mod`
void precomputePowers() {
    pows[0] = 1;
    for (int i = 1; i < maxN; i++) {
        pows[i] = (pows[i - 1] * base) % mod;
    }
}

// Build the segment tree for hashing
void build(ll node, ll L, ll R) {
    if (L == R) {
        st[node] = (s[L] - '0' + 1) % mod;
        return;
    }
    ll mid = (L + R) / 2;
    ll leftChild = node << 1;
    ll rightChild = node << 1 | 1;

    build(leftChild, L, mid);
    build(rightChild, mid + 1, R);

    ll rightLen = R - mid;
    st[node] = (st[leftChild] * pows[rightLen] % mod + st[rightChild]) % mod;
}

// Update a character in the segment tree
void update(ll node, ll L, ll R, ll idx) {
    if (L == R) {
        st[node] = (s[L] - '0' + 1) % mod;
        return;
    }
    ll mid = (L + R) / 2;
    ll leftChild = node << 1;
    ll rightChild = node << 1 | 1;

    if (idx <= mid) {
        update(leftChild, L, mid, idx);
    } else {
        update(rightChild, mid + 1, R, idx);
    }

    ll rightLen = R - mid;
    st[node] = (st[leftChild] * pows[rightLen] % mod + st[rightChild]) % mod;
}

// Query the hash of a substring [l, r]
ll query(ll node, ll L, ll R, ll l, ll r) {
    if (r < L || R < l) return 0; // No overlap
    if (l <= L && R <= r) return st[node]; // Complete overlap

    ll mid = (L + R) / 2;
    ll leftChild = node << 1;
    ll rightChild = node << 1 | 1;

    ll leftHash = query(leftChild, L, mid, l, r);
    ll rightHash = query(rightChild, mid + 1, R, l, r);

    ll rightLen = max(0ll, min(R, r) - mid);
    return (leftHash * pows[rightLen] % mod + rightHash) % mod;
}

// Binary search to check if a pattern exists in the string
bool substringExists(const string& t) {
    ll lenT = t.size();
    ll targetHash = 0;

    // Compute the hash of the pattern `t`
    for (int i = 0; i < lenT; i++) {
        targetHash = (targetHash * base + (t[i] - '0' + 1)) % mod;
    }

    // Use binary search to check for the pattern
    ll low = 0, high = n - lenT;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll currentHash = query(1, 0, n - 1, mid, mid + lenT - 1);

        if (currentHash == targetHash) {
            return true;
        } else if (currentHash < targetHash) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false;
}

void solve() {
    cin >> n >> q >> s;

    precomputePowers();
    build(1, 0, n - 1);

    while (q--) {
        char op;
        cin >> op;

        if (op == '?') {
            string t;
            cin >> t;

            if (substringExists(t)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else if (op == '!') {
            ll k;
            cin >> k;
            k--; // Convert to 0-based index

            // Flip the character
            s[k] = (s[k] == '0' ? '1' : '0');

            // Update the segment tree
            update(1, 0, n - 1, k);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
