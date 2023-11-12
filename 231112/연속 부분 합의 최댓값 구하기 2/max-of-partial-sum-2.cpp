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

void solution(vector<ll>& seq){
  ll subSum = 0;
  ll ans = INT64_MIN;

  for (const auto &num: seq){
    subSum += num;
    ans = max(subSum, ans);

    if (subSum < 0) {
      subSum = 0;
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
  vector<ll> seq(n);

  for (int i = 0; i < n; ++i) {
    cin >> seq.at(i);
  }

  solution(seq);
}