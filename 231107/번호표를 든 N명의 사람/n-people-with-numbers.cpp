#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long

using namespace std;

bool available(vector<int> &d, int k, int t){
  auto compare = [](int a, int b){return a > b;};
  priority_queue<int, vector<int>, decltype(compare)> pq(compare);

  for (int i = 0; i < k; ++i) {
    pq.push(d.at(i));
  }

  for (int i = k; i < d.size(); ++i) {
    int elapsed = pq.top();
    pq.pop();

    int nextElapse = elapsed + d.at(i);
    if (nextElapse > t) {
      return false;
    }
    pq.push(nextElapse);
  }

  return true;
}

void solution(vector<int> &d, int t){
  int lo = 1;
  int hi = d.size();

  int ans = hi;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (available(d, mid, t)) {
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

  int n, t;
  cin >> n >> t;
  vector<int> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d.at(i);
  }

  solution(d, t);
}

/*
3
4
1 5
10 10
13 15
18 22
 */