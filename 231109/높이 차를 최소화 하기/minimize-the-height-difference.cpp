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

vector<int> dx = {-1, 0, 0, 1};
vector<int> dy = {0, -1, 1, 0};

bool available(int n, int m, int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

bool check(vector<vector<int>> &matrix, int maxDiff, vector<vector<bool>> &visited,
           int x, int y, int minH, int maxH) {
  if (x == matrix.size() - 1 && y == matrix[0].size() - 1) {
    return true;
  }

  visited[x][y] = true;

  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (available(matrix.size(), matrix[0].size(), nx, ny) && !visited[nx][ny]
        && abs(max(maxH, matrix[nx][ny]) - min(minH, matrix[nx][ny])) <= maxDiff
        && check(matrix, maxDiff, visited, nx, ny, min(minH, matrix[nx][ny]), max(maxH, matrix[nx][ny]))) {
      return true;
    }
  }

  return false;
}

void solution(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  int lo = 0;
  int hi = 500;

  int ans = hi + 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    vector<vector<bool>> visited(n, vector<bool>(m));
    if (check(matrix, mid, visited, 0, 0, matrix[0][0], matrix[0][0])) {
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
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> matrix.at(i).at(j);
    }
  }

  solution(matrix);
}