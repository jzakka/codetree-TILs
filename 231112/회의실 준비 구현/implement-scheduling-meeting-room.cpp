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
#define pii pair<int,int>

using namespace std;

void solution(vector<pii>& schedule){
  std::sort(schedule.begin(), schedule.end(),[](pii& s1, pii& s2){
    if(s1.first == s2.first){
      return s1.second < s2.second;
    }
    return s1.first < s2.first;
  });

  auto compare = [](pii& s1, pii& s2){
    return s1.second < s2.second;
  };
  priority_queue<pii , vector<pii>, decltype(compare)> pq(compare);

  for (const auto &sch: schedule){
    while (!pq.empty() && pq.top().second > sch.first) {
      pq.pop();
    }
    pq.push(sch);
  }

  cout << pq.size();
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