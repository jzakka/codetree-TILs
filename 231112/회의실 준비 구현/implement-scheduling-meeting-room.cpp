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

void solution(vector<pii>& schedule){
  std::sort(schedule.begin(), schedule.end(),[](pii& s1, pii& s2){
    if(s1.second == s2.second){
      return s1.first < s2.first;
    }
    return s1.second < s2.second;
  });

  pii top = schedule.front();
  int ans = 1;

  for (int i = 1; i < schedule.size(); ++i) {
    auto &sch = schedule.at(i);
    if (sch.first >= top.second) {
      top = sch;
      ans++;
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
  vector<pii > schedule(n);

  for (int i = 0; i < n; ++i) {
    cin >> schedule.at(i).first >> schedule.at(i).second;
  }

  solution(schedule);
}