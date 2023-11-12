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

void solution(int n){
  int ans = 0;

  if ((n & 1) == 0) {
    ans += (n % 10) / 2;
    n = n / 10 * 10;
    ans += n / 5;
    cout << ans << "\n";
    return;
  } else {
    while (n % 5 > 0 && n > 0) {
      n -= 2;
      ans++;
    }
    if(n < 0){
      cout << -1 << "\n";
      return;
    }
    ans += n / 5;
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  solution(n);
}