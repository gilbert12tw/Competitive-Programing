const int test_time = 8;
bool millerRabin(ll n) {
  if (n < 3 || n % 2 == 0) return n == 2LL;
  ll a = n - 1, b = 0;
  while (a % 2 == 0) a /= 2, ++b;
  // test_time 最好在 8 以上
  for (int i = 1, j; i <= test_time; ++i) {
    ll x = rand() % (n - 2) + 2, v = fp(x, a, n);
    if (v == 1) continue;
    for (j = 0; j < b; ++j) {
      if (v == n - 1) break;
      v = v * v % n;
    }
    if (j >= b) return 0;
  }
  return 1;
}
