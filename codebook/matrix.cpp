struct mat {
	int n;
	vector<vector<int>> m;

	auto operator [](int x) {
		return m[x];
	}

	mat(int _n): n(_n) {
		m.resize(n, vector<int>(n, 0));
	}

	void init() {
		for (int i = 0; i < n; i++)	for (int j = 0; j < n; j++)	m[i][j] = 0;
		for(int i = 0; i < n; i++) m[i][i] = 1;
	}

	void clear() {
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)	m[i][j] = 0;
	}

	mat operator * (mat &a) {
		mat t(n);
		for(int i = 0; i < a.n; i++) 
			for(int k = 0; k < a.n; k++) 
				for(int j = 0; j < a.n; j++) 
					t.m[i][j] = (t.m[i][j] + m[i][k] * a.m[k][j]) % mod;
		return t;
	}

	mat operator ^ (int x) {
		mat t(n), b = *this; t.init();
		while (x) {
			if (x & 1) t = t * b;
			b = b * b;
			x >>= 1;
		}
		return t;
	}

	void print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << m[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
};



