#include <bits/stdc++.h>

using namespace std;

int n, k, p;

int main(){
	// freopen("test.txt","r",stdin);
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> k >> p;
	vector<int> ps, ks;
	for (int i=0; i<n; ++i){
		int x; cin >> x;
		ps.push_back(x);
	}
	for(int i=0; i<k; ++i){
		int x; cin >> x;
		ks.push_back(x);
	}
	sort(ps.begin(), ps.end());
	sort(ks.begin(), ks.end());
	int best = 2e9;
	for (int st=0; st <= k - n; ++st){
		int bestlen = 0;
		for (int i = st; i<st + n; ++i){
			bestlen = max(bestlen, abs(ks[i] - p) + abs(ks[i] - ps[i-st]));
		}
		best = min(best, bestlen);
	}
	cout << best;
	return 0;
}