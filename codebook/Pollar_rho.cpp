inline ll f(ll x, ll c, ll n) {
	return (x * x + c) % n;	
}

ll Pollard_Rho(ll n) {
  ll c = rand() % (n - 1) + 1;
  ll t = f(0, c, n); // turtle 
  ll r = f(f(0, c, n), c, n); // rabit
  while (t != r) {
    ll d = gcd(abs(t - r), n);
    if (d > 1) return d;
    t = f(t, c, n);
    r = f(f(r, c, n), c, n);
  }
  return n;
}
