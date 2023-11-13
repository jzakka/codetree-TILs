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

void solution(int lastTime, map<int, vector<int>> &time){
  multiset<int> bombs;

  int ans = 0;
  for (int i = lastTime; i >= 0; --i) {
    if (!bombs.empty()) {
      auto back = prev(bombs.end());
      ans += *back;
      bombs.erase(back);
    }
    if (time.find(i) != time.end()) {
      bombs.insert(time[i].begin(), time[i].end());
    }
  }

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  map<int, vector<int>> timeline;

  int lastTime = 0;
  for (int i = 0; i < n; ++i) {
    int points, deadline;
    cin >> points >> deadline;
    timeline[deadline].push_back(points);
    lastTime = max(lastTime, deadline);
  }

  solution(lastTime, timeline);
}