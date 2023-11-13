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

void solution(set<int>& a, vector<int>& b){
  int ans = 0;
  for (const auto &bNum: b){
    auto it = a.upper_bound(bNum);
    if (it != a.end()) {
      ans++;
      a.erase(it);
    } else {
      a.erase(a.begin());
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


  set<int> a;
  for (int i = 1; i <= 2*n; ++i) {
    a.insert(i);
  }
  vector<int> b;
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    b.push_back(num);
    a.erase(num);
  }


  solution(a, b);
}