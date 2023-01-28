int n, c[mxN], pos[mxN], cnt[mxN], bk[mxN], res[mxN];
string s;
vector<pii> v;

void radix_sort(vector<pii> &v) {
	for(int i = 0; i < n; i++) cnt[v[i].S]++;
	pos[0] = 0;
	for(int i = 1; i < max(30LL, n); i++) pos[i] = pos[i - 1] + cnt[i - 1], cnt[i - 1] = 0;
	for(int i = 0; i < n; i++) bk[pos[v[i].S]++] = i;
	for(int i = 0; i < n; i++) cnt[v[i].F]++;
	pos[0] = 0;
	for(int i = 1; i < max(30LL, n); i++) pos[i] = pos[i - 1] + cnt[i - 1], cnt[i - 1] = 0;
	for(int i = 0; i < n; i++) res[pos[v[bk[i]].F]++] = bk[i];
}

void cal_c() {
	c[res[0]] = 0;
	for(int i = 1; i < n; i++) {
		if(v[res[i]] == v[res[i-1]]) c[res[i]] = c[res[i-1]];
		else c[res[i]] = c[res[i-1]] + 1;
	}
}

void build_sa(string &s) {
	s = s + "$";
	n = sz(s);
	v.resize(n);
	for(int i = 0; i < n; i++) v[i].F = s[i] - 'a' + 1;
	v[n - 1].F = 0;
	radix_sort(v);
	cal_c();
	int k = 0;
	while((1<<k) < n) {
		for(int i = 0, j = (1<<k); i < n; i++, j++) {
			if(j >= n) j %= n;
			v[i] = {c[i], c[j]};
		}
		radix_sort(v);
		cal_c();
		if(c[res[n-1]] == n-1) break;
		k++;
	}
}
