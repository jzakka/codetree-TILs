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

vector<int> dx = {0, 1, -1, 0};
vector<int> dy = {1, 0, 0, -1};

bool available(int n, int m, int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

bool check(vector<vector<int>> &matrix, int maxDiff, vector<vector<int>> &visited,
           int x, int y, int minH, int maxH) {
  if (x == matrix.size() - 1 && y == matrix[0].size() - 1) {
    return true;
  }

  visited[x][y] = maxH - minH;

  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (available(matrix.size(), matrix[0].size(), nx, ny)
        && max(maxH, matrix[nx][ny]) - min(minH, matrix[nx][ny]) < min(visited[nx][ny], maxDiff + 1)
        && check(matrix, maxDiff, visited, nx, ny, min(minH, matrix[nx][ny]), max(maxH, matrix[nx][ny]))) {
      return true;
    }
  }

  return false;
}

void debug(vector<vector<int>> &matrix, vector<vector<bool>> &visited){
  int n = matrix.size();
  int m = matrix[0].size();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout.width(7);
      cout << matrix[i][j] << ":" << visited[i][j] << " ";
    }
    cout << "\n";
  }
}

void solution(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  int lo = 0;
  int hi = 500;

  int ans = hi + 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    vector<vector<int>> visited(n, vector<int>(m, INT32_MAX));
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