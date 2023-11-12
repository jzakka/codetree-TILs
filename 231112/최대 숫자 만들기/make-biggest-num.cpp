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

void solution(vector<string>& nums){
  std::sort(nums.begin(), nums.end(), [](string& s1, string& s2){
    if (s1.length() > s2.length()) {
      return s1 > s2 + s1.substr(0, s1.length() - s2.length());
    } else if (s1.length() < s2.length()) {
      return s1 + s2.substr(0,s2.length()-s1.length()) > s2;
    }
    return s1 > s2;
  });
  for (const auto &item: nums){
    cout << item;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<string> nums(n);

  for (int i = 0; i < n; ++i) {
    cin >> nums.at(i);
  }

  solution(nums);
}