#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>

#define ll long long
#define pdd pair<double,double>
#define pii pair<int,int>

using namespace std;

void solution(vector<int>& cars){
  vector<int> stk;

  int ans = 0;
  for (const auto &car: cars) {
    while (!stk.empty() && stk.back() > car){
      stk.pop_back();
    }
    stk.push_back(car);

    ans = max(ans, stk.back() - stk.front());
  }

  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<int> cars(n);
  for (int i = 0; i < n; ++i) {
    cin >> cars.at(i);
  }

  solution(cars);
}