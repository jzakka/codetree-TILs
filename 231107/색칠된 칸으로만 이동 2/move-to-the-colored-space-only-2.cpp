#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

#define ll long long

using namespace std;

vector<int> dx = {-1, 0, 0, 1};
vector<int> dy = {0, -1, 1, 0};

bool accessible(int n, int m, int x, int y){
  return 0 <= x && x < n && 0 <= y && y < m;
}

void move(vector<vector<int>> &mat, vector<vector<int>> &visited, int x, int y, int diff){
  visited.at(x).at(y) = 1;

  for (int i = 0; i < 4; ++i) {
    int nx = x + dx.at(i);
    int ny = y + dy.at(i);

    if (accessible(mat.size(), mat.at(0).size(), nx, ny) && !visited.at(nx).at(ny)
        && abs(mat.at(x).at(y) - mat.at(nx).at(ny)) <= diff) {
      move(mat, visited, nx, ny, diff);
    }
  }
}

bool available(vector<vector<int>> &mat, vector<vector<int>> &color, int diff){
  int n = mat.size();
  int m = mat.at(0).size();
  vector<vector<int>> visited(n, vector<int>(m, 0));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (color.at(i).at(j) == 1) {
        move(mat, visited, i, j, diff);
        break;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (color.at(i).at(j) && !visited.at(i).at(j)) {
        return false;
      }
    }
  }
  return true;
}

void solution(vector<vector<int>> &mat, vector<vector<int>> &color) {
  int lo = 0;
  int hi = 1'000'000'000;

  int ans = hi + 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (available(mat,color, mid)) {
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

  int n, m;
  cin >> n >> m;
  vector<vector<int>> matrix(n, vector<int>(m));
  vector<vector<int>> color(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> matrix.at(i).at(j);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> color.at(i).at(j);
    }
  }

  solution(matrix, color);
}