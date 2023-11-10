#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>

#define ll long long

using namespace std;

bool check(vector<int> &c, int k, int l, int h){
  int i = 0;
  while (i < h && c.at(i) >= h) {
    i++;
  }

  int remainPosts = k * l;
  for (;i < h; ++i) {
    int ci = c.at(i);

    int diff = h - ci;

    if (diff > k || remainPosts - diff < 0) {
      break;
    } else {
      remainPosts -= diff;
    }
  }

  return i == h;
}

void solution(int k, int l, vector<int> &c){
  std::sort(c.begin(), c.end(), [](int a, int b){return a>b;});

  int lo = 0;
  int hi = c.size();

  int ans = -1;

  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (check(c, k, l, mid)) {
      lo = mid + 1;
      ans = max(ans, mid);
    } else {
      hi = mid - 1;
    }
  }
  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k, l;
  cin >> n >> k >> l;

  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c.at(i);
  }

  solution(k, l, c);
}