#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

bool check(vector<int> &arrival, int waitTime, int m, int c) {
  int busCnt = 0;
  int lastArrive = arrival.front();

  int people = 0;
  for (const auto &arrive: arrival) {
    if (people > 0) {
      if(arrive - lastArrive > waitTime){
        busCnt++;
        people = 1;
        lastArrive = arrive;
      }else if (++people == c) {
        busCnt++;
        people = 0;
      }
    } else {
      people++;
      lastArrive = arrive;
    }
  }

  if (people > 0) {
    busCnt++;
  }

  return busCnt <= m;
}

void solution(vector<int> &arrival, int m, int c) {
  std::sort(arrival.begin(), arrival.end());

  int lo = 1;
  int hi = 1'000'000'000;

  int ans = hi + 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (check(arrival, mid, m, c)) {
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

  int n, m, c;
  cin >> n >> m >> c;
  vector<int> arrival(n);

  for (int i = 0; i < n; ++i) {
    cin >> arrival.at(i);
  }

  solution(arrival, m, c);
}

/*
3 3
2 10 8
4 5 11
20 1 2
1 0 0
0 1 0
0 0 1
 */