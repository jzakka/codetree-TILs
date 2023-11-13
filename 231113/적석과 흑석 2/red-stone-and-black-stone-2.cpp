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
    if (a.first == b.first) {
      return a.second < b.second;
    }
    return a.second < b.second;
  });

  int ans = 0;
  auto r = red.begin();
  for (const auto &b: black){
    while (r != red.end() && *r < b.first) {
      r++;
    }
    if (r != red.end() && b.first <= *r && *r <= b.second) {
      ans++;
      r++;
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