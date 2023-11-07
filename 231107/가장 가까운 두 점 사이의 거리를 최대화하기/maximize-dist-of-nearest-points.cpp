#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

bool available(vector<pair<ll,ll>> &lines, ll dist){
  ll last = INT64_MIN;

  for (const auto &line: lines){
    ll s = line.first;
    ll e = line.second;

    if (last + dist > e) {
      return false;
    }
    last = max(last + dist, s);
  }

  return true;
}

void solution(vector<pair<ll, ll>> &lines) {
  std::sort(lines.begin(), lines.end(), [](pair<ll, ll> &l1, pair<ll, ll> &l2) {
    return l1.first < l2.first;
  });

  ll lo = 1;
  ll hi = lines.back().second - lines.front().first;

  ll ans = -1;
  while (lo <= hi) {
    ll mid = (lo + hi) / 2;

    if (available(lines, mid)) {
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

  int  m;
  cin  >> m;

  vector<pair<ll, ll>> lines(m);
  for (int i = 0; i < m; ++i) {
    cin >> lines.at(i).first >> lines.at(i).second;
  }

  solution(lines);
}

/*
3
4
1 5
10 10
13 15
18 22
 */