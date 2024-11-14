#include <bits/stdc++.h>
int T,N,a[300009],t[300009];
signed main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for(int i=1;i<=N;i++) {
			scanf("%d",&a[i]);
		}
		int x=0;
		for(int i=1;i<=N;i++) {
			if(x<a[i]) x++;
			else if(x>a[i]) x--;
			t[i]=x;
			t[i]=std::max(t[i],t[i-1]);
		}
		int q=0;
		for(int i=2;i<=N;i++) {
			q=std::max(q,t[i-2]);
			if(q<a[i]) q++;
			else if(q>a[i]) q--;
		}
		q=std::max(q,t[N-1]);
		printf("%d\n",q);
	}
}