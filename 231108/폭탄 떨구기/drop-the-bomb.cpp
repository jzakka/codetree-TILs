#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

bool check(vector<int> &points, int k, int r){
  int last = INT32_MIN;

  int cnt = 0;
  for (const auto &point: points){
    if (point > last) {
      cnt++;
      last = point + 2 * r;
    }
  }

  return cnt <= k;
}

void solution(int k, vector<int>& points){
  std::sort(points.begin(), points.end());

  int lo = 1;
  int hi = 1'000'000'000;

  int ans = hi + 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (check(points, k, mid)) {
      hi = mid - 1;
      ans = min(ans, mid);
    } else {
      lo = mid + 1;
    }
  }

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector<int> points(n);
  for (int i = 0; i < n; ++i) {
    cin >> points.at(i);
  }

  solution(k, points);
}

/*
3 3
2 10 8
4 5 11
20 1 2
1 0 0
0 1 0
0 0 1
 */