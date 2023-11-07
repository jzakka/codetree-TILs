#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

vector<int> dx = {-1, 0, 0, 1};
vector<int> dy = {0, -1, 1, 0};

bool accessible(vector<vector<int>> &mat, int x, int y) {
  int n = mat.size();

  return 0 <= x && x < n && 0 <= y && y < n;
}

void color(vector<vector<int>> &mat, vector<vector<bool>> &visited, int& colored, int x, int y, int diff) {
  visited.at(x).at(y) = true;
  colored++;

  for (int i = 0; i < 4; ++i) {
    int nextX = x + dx.at(i);
    int nextY = y + dy.at(i);

    if (accessible(mat, nextX, nextY) && !visited.at(nextX).at(nextY)
        && abs(mat.at(x).at(y) - mat.at(nextX).at(nextY)) <= diff) {
      color(mat, visited, colored, nextX, nextY, diff);
    }
  }
}

bool available(vector<vector<int>> &mat, int mid) {
  int n = mat.size();
  int colored = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      vector<vector<bool>> visited(n, vector<bool>(n));
      int area = 0;
      color(mat, visited, area, i, j, mid);
      colored = max(colored, area);
    }
  }

  return ((n * n + 1) / 2) <= colored;
}

void solution(vector<vector<int>> &mat) {
  int lo = 0;
  int hi = 1'000'000;

  int ans = hi + 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (available(mat, mid)) {
      hi = mid - 1;
      ans = min(ans, mid);
    } else {
      lo = mid + 1;
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
  vector<vector<int>> matrix(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> matrix.at(i).at(j);
    }
  }

  solution(matrix);
}