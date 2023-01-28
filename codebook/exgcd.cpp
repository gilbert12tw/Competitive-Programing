pii exgcd(int a, int b) {
	if(b == 0) return {1 ,0};
	pii ans = exgcd(b, a % b);
	return {ans.S, ans.F - a / b * ans.S};
}
