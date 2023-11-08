#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>

#define ll long long

using namespace std;

bool check(vector<pair<ll, ll>> info, ll time){
  ll s = INT64_MIN;
  ll e = INT64_MAX;

  for (const auto &i: info){
    s = max(s, i.first - time * i.second);
    e = min(e, i.first + time * i.second);
  }

  return s <= e;
}

void solution(vector<ll> &pos, vector<ll> &velocity){
  vector<pair<ll, ll>> info(pos.size());
  for (int i = 0; i < info.size(); ++i) {
    info.at(i).first = pos.at(i) * 10'000;
    info.at(i).second = velocity.at(i);
  }
  std::sort(info.begin(), info.end(), [](pair<ll,ll>& i1, pair<ll,ll>& i2){
    return i1.first < i2.first;
  });

  int dist = info.back().first - info.front().first;

  ll lo = 0; // 0.0001
  ll hi = dist / info.front().second;

  ll ans = hi + 1;
  while (lo <= hi) {
    ll mid = lo + (hi - lo) / 2;
    if(check(info, mid)) {
      hi = mid - 1;
      ans = min(ans, mid);
    } else {
      lo = mid + 1;
    }
  }

  cout << ans / 10'000 << "." << setw(4) << setfill('0') << ans % 10'000;
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