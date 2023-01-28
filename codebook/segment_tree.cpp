#define ls x<<1
#define rs x<<1|1
#define mid (l+r>>1)

void up(int x) {
	seg[x] = seg[ls] + seg[rs];
}

void build(int l = 1, int r = n, int x = 1) {
	if(l == r) {
		seg[x] = a[l];
		return;
	}
	build(l, mid, ls);
	build(mid+1, r, rs);
	up(x);
}

void modify(int p, int v, int l = 1, int r = n, int x = 1) {
	if(l == r) {
		seg[x] = v;
		return;
	}
	if(p <= mid) modify(p, v, l, mid, ls);
	else modify(p, v, mid+1, r, rs);
	up(x);
}

int query(int a, int b, int l = 1, int r = n, int x = 1) {
	if(a <= l and r <= b) return seg[x];
	int res = 0;
	if(a <= mid) res = query(a, b, l, mid, ls);
	if(b > mid) res += query(a, b, mid+1, r, rs);
	return res;
}
