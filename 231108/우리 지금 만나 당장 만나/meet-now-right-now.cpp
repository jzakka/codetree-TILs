#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#define ll long long

using namespace std;

bool check(vector<pair<ll, ll>> info, double time){
  double s = numeric_limits<double>::min();
  double e = numeric_limits<double>::max();

  for (const auto &i: info){
    s = max(s, i.first - time * i.second);
    e = min(e, i.first + time * i.second);
  }

  return s <= e;
}

void solution(vector<ll> &pos, vector<ll> &velocity){
  vector<pair<ll, ll>> info(pos.size());
  for (int i = 0; i < info.size(); ++i) {
    info.at(i).first = pos.at(i);
    info.at(i).second = velocity.at(i);
  }
  std::sort(info.begin(), info.end(), [](pair<ll,ll>& i1, pair<ll,ll>& i2){
    return i1.first < i2.first;
  });

  double lo = 0;
  double hi = 1'000'000'000;

  double ans = numeric_limits<double>::max();

  for (int i = 0; i < 100; ++i) {
    double mid = (lo + hi) / 2;

    if (check(info, mid)) {
      hi = mid - 1;
      ans = min(ans, mid);
    } else {
      lo = mid + 1;
    }
  }

  cout << fixed;
  cout.precision(4);

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<ll> pos(n);
  vector<ll> velocity(n);

  for (int i = 0; i < n; ++i) {
    cin >> pos.at(i);
  }
  for (int i = 0; i < n; ++i) {
    cin >> velocity.at(i);
  }

  solution(pos, velocity);
}