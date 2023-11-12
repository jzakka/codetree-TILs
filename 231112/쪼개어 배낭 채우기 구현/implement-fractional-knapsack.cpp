#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>

#define ll long long
#define pdd pair<double,double>

using namespace std;

void solution(vector<pair<double,double>>& items, double m){
  vector<double> values;

  std::sort(items.begin(), items.end(),[](pdd& i1, pdd& i2){
    return i1.second/i1.first > i2.second/i2.first;
  });

  double ans = 0.0;
  int i = 0;
  while (m > 0 && i < items.size()) {
    pdd item = items.at(i);

    if(m < item.first){
      ans += item.second / item.first * m;
      m = 0;
    } else {
      ans += item.second;
      m -= item.first;
    }
    i++;
  }

  cout << fixed;
  cout.precision(3);
  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  double n, m;
  cin >> n >> m;

  vector<pair<double, double>> items(n);
  for (int i = 0; i < n; ++i) {
    cin >> items.at(i).first >> items.at(i).second;
  }

  solution(items, m);
}