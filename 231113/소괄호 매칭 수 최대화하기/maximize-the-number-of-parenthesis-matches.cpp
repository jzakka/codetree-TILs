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

struct compare {
  bool operator()(const pair<string, double> &a, const pair<string, double> &b) const {
    return a.second < b.second;
  }
};

void solution(set < pair<string, double>, compare > &fragments) {
  string T = "";

  for (const auto &fragment: fragments){
    T += fragment.first;
  }

  ll ans = 0;
  ll rBracketCnt = 0;
  for (int i = T.length() - 1; i >= 0; --i) {
    if(T.at(i) == ')') {
      rBracketCnt++;
    } else {
      ans += rBracketCnt;
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

  set < pair<string, double>, compare > T;

  for (int i = 0; i < n; ++i) {
    pair<string, double> fragment;
    cin >> fragment.first;

    for (const auto &letter: fragment.first) {
      if (letter == ')') {
        fragment.second++;
      }
    }

    fragment.second /= fragment.first.length();

    T.insert(fragment);
  }

  solution(T);
}