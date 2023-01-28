bool cmp(point a, point b) {
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

vector<point> build(vector<point> p) {
	vector<point> up, dn;	
	sort(all(p), cmp);
	for(int i = 0; i < n; i++) {
		while(sz(up) > 1 and cross(up[sz(up) - 1] - up[sz(up) - 2], p[i] - up[sz(up) - 2]) > 0)
			up.pop_back();
		while(sz(dn) > 1 and cross(dn[sz(dn) - 1] - dn[sz(dn) - 2], p[i] - dn[sz(dn) - 2]) < 0)
			dn.pop_back();
		dn.pb(p[i]);
		up.pb(p[i]);
	}
	reverse(all(dn));
	for (int i = 1; i + 1 < sz(dn); i++) up.eb(dn[i]);
	return up;
}
