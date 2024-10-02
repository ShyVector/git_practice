#include <iostream>
using namespace std;

int fa[1010];

void fa_init(int n) {
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
}

int get_fa(int x) { return (fa[x] = ((fa[x] == x) ? x : get_fa(fa[x]))); }

void join(int x, int y) {
  int fx = get_fa(x), fy = get_fa(y);
  fa[fy] = fx;
}

int main() {
  // freopen("P1536_1.in", "r", stdin);
  // freopen("P1536_1_test.out", "w", stdout);
  int n, m;
  cin >> n;
  while (n) {

    fa_init(n);
    cin >> m;
    while (m--) {
      int x, y;
      cin >> x >> y;
      join(x, y);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (get_fa(i) == i)
        cnt++;
    }
    cout << cnt - 1 << endl;
    cin >> n;
  }
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
