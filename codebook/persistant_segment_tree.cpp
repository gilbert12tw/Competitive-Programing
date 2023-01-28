int tot, edit[mxN];

struct per_seg {
	int ls, rs, val;
} seg[mxN * 20];

int modify(int p, int pos, int l = 0, int r = n) {
	int mid = (l+r)>>1;
	int x = ++tot;
	seg[x] = seg[p];
	seg[x].val++;
	if(l == r) return x;
	if(pos <= mid) seg[x].ls = modify(seg[p].ls, pos, l, mid);
	else seg[x].rs = modify(seg[p].rs, pos, mid+1, r);
	return x;
}

int query(int p, int u, int a, int b, int l = 0, int r = n) {
	if(a <= l and r <= b) return seg[u].val - seg[p].val;
	int mid = (l+r)>>1;
	int ans = 0;
	if(a <= mid) ans += query(seg[p].ls, seg[u].ls, a, b, l, mid);
	if(b > mid) ans += query(seg[p].rs, seg[u].rs, a, b, mid+1, r);
	return ans;
}
