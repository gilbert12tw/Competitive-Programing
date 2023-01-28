#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma loop-opt(on)
#define pb push_back
#define ep emplace_back
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()
#define int long long
#define pii pair<int, int>
#define inf 1e9
#define INF 1e18
#define mod 1000000007
#define F first
#define S second
#define wopen(x) freopen((x),"w",stdout)
#define ropen(x) freopen((x),"r",stdin)
#define de(x) cout << #x << " = " << x << ' '
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
void trace_() {cerr << "\n";}
template<typename T1, typename... T2> void trace_(T1 t1, T2... t2) {cerr << ' ' << t1; trace_(t2...); }
#define trace(...) cerr << "[" << #__VA_ARGS__ << "] :", trace_(__VA_ARGS__);

mt19937 ran(time(nullptr));
uniform_int_distribution<int> dis(1, 1000000000);
char in[20], out[20];

void generate_input(int c) {
	sprintf(in, "%lld.in", c);
	wopen(in);
}

void gen(int st, int ed) {
	for (int i = st; i <= ed; i++) {
		generate_input(i);
	}
	cerr << "Finish Yeh!!!\n";
}

signed main() {
	gen(1, 0);	
}


