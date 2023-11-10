#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>

#define ll long long

using namespace std;

void solution(vector<int> &coins, int k){
  sort(coins.begin(), coins.end(), [](int a, int b){return a > b;});

  int ans = 0;
  auto it = coins.begin();
  while (k > 0) {
    int cnt = k/(*it);
    ans += cnt;
    k -= (*it) * cnt;
    it = next(it);
  }

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;
  vector<int> coins(n);

  for (int i = 0; i < n; ++i) {
    cin >> coins.at(i);
  }

  solution(coins, k);
}