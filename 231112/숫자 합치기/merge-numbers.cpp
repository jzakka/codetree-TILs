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

void solution(multiset<ll>& vec){
  ll ans = 0;

  while (vec.size() > 1) {
    auto first = vec.begin();
    auto second = next(first);

    int merged = (*first) + (*second);
    vec.erase(first);
    vec.erase(second);
    vec.insert(merged);
    ans += merged;
  }

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  multiset<ll> vec;
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    vec.insert(num);
  }

  solution(vec);
}