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

bool check(vector<int> &swimmers, int m, int maxTime){
  int time = 0;
  int cnt = 1;

  for (const auto &swimmer: swimmers){
    if (time + swimmer > maxTime) {
      cnt++;
      time = 0;
    }
    if (cnt > m) {
      break;
    }
    time += swimmer;
  }

  return cnt <= m;
}

void solution(vector<int> &swimmer, int m){
  int lo = 0;
  int hi = 0;
  for (int i = 0; i < swimmer.size(); ++i) {
    hi += swimmer.at(i);
    lo = max(lo, swimmer.at(i));
  }

  int ans = hi + 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (check(swimmer, m, mid)) {
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

  int n, m;
  cin >> n >> m;

  vector<int> swimmer(n);
  for (int i = 0; i < n; ++i) {
    cin >> swimmer.at(i);
  }

  solution(swimmer, m);
}