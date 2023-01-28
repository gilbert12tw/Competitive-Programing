struct BIT{
	int b[mxN];
    vector<int> tmp;
	int qry(int i) {
		int res = 0;
		for (; i > 0; i -= (i&-i)) res += b[i];
		return res;
	}
	void upd(int i, int v) {
		for (; i < mxN; i += (i&-i)) b[i] += v, tmp.eb(i); 
	}
    void clear() {
        for (int i : tmp) b[i] = 0;
        tmp.clear();
    }
	int findk(int k) {
		int id = 0, res = 0;
		int mx = __lg(mxN) + 1;
		for (int i = mx; i >= 0; i--) {
			if ((id | (1<<i)) > n) continue;
			if (res + b[id|(1<<i)] < k) { 
				id = (id | (1<<i));
				res += b[id];
			}
		}
		return id + 1;
	}
};
