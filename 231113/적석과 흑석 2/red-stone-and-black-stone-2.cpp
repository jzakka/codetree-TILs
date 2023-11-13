#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <map>

#define ll long long
#define pdd pair<double,double>
#define pii pair<int,int>

using namespace std;

void solution(int c, int n, vector<int> &red, vector<pii > &black){
  std::sort(red.begin(), red.end());
  std::sort(black.begin(), black.end(), [](pii& a, pii& b){
    if (a.second == b.second) {
      return a.first < b.first;
    }
    return a.second < b.second;
  });

  multiset<int> reds;
  reds.insert(red.begin(), red.end());
  int ans = 0;
  for (const auto &b: black){
    auto redIt = reds.lower_bound(b.first);
    if (redIt != reds.end() && *redIt <= b.second) {
      ans++;
      reds.erase(redIt);
    }
  }

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int c, n;
  cin >> c >> n;

  vector<int> red(c);
  vector<pii > black(n);

  for (int i = 0; i < c; ++i) {
    cin >> red.at(i);
  }
  for (int i = 0; i < n; ++i) {
    cin >> black.at(i).first >> black.at(i).second;
  }

  solution(c, n, red, black);
}

/*
6 8
13
28
43
2
0
21
0 21
1 20
12 14
14 33
22 38
0 11
12 19
0 31
 */