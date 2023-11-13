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

void solution(map<int,int>& counts){
  auto s = counts.begin();
  auto e = prev(counts.end());

  int ans = INT32_MIN;
  while (s->first <= e->first) {
    if (s->first == e->first) {
      ans = max(ans, 2 * s->first);
      break;
    } else {
      ans = max(ans, s->first + e->first);

      if (s->second < e->second) {
        e->second -= s->second;
        s++;
      } else if(s->second > e->second){
        s->second -= e->second;
        e--;
      } else {
        s++;
        e--;
      }
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

  map<int, int> cnts;

  for (int i = 0; i < n; ++i) {
    int num, cnt;
    cin >> cnt >> num;
    cnts[num] = cnt;
  }

  solution(cnts);
}