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

bool check(string& a, string&b , vector<int>& del, int toDel){
  unordered_set<int> delPos;
  for (int i = 0; i < toDel; ++i) {
    delPos.insert(del.at(i));
  }

  int j = 0;
  for (int i = 0; i < a.length() && j < b.length(); ++i) {
    if (delPos.find(i + 1) == delPos.end() && a.at(i) == b.at(j)) {
      j++;
    }
  }

  return j == b.length();
}

void solution(string& a, string& b, vector<int>& del){
  int lo = 0;
  int hi = a.size();

  int ans = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (check(a, b, del, mid)) {
      lo = mid + 1;
      ans = max(ans, mid);
    } else {
      hi = mid - 1;
    }
  }

  cout << (ans + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string a,b;
  cin >> a >> b;
  vector<int> del(a.size());

  for (int i = 0; i < del.size(); ++i) {
    cin >> del.at(i);
  }

  solution(a, b, del);
}