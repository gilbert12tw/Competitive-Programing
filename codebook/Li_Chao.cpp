struct Line {
	int a, b;	
	int operator () (int x) {
		return a * x + b;
	}
} seg[mxN * 5];
const int mxR = 1e6;

#define ls (id<<1)
#define rs (ls|1)
void insert(Line t, int l = 1, int r = mxR, int id = 1) {
	int mid = (l+r) >> 1;
	if (t(mid) > seg[id](mid)) swap(t, seg[id]);
	if (l == r)  return;
	if (t(l) > seg[id](l)) insert(t, l, mid, ls);
	if (t(r) > seg[id](r)) insert(t, mid+1, r, rs);
}

int query(int p, int l = 1, int r = mxR, int id = 1) {
	if (l == r) return seg[id](p);
	int mid = (l+r)>>1;
	if (p <= mid) return max(query(p, l, mid, ls), seg[id](p));
	else return max(query(p, mid+1, r, rs), seg[id](p));
}


