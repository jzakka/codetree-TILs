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

bool dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int x, int y, int minH, int maxH){
  int n = matrix.size();
  int m = matrix[0].size();
  if (x == n - 1 && y == m - 1) {
    return true;
  }

  visited[x][y] = true;

  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(available(n,m,nx,ny) && !visited[nx][ny]
      && minH <= matrix[nx][ny] && matrix[nx][ny] <= maxH
      && dfs(matrix, visited, nx, ny, minH, maxH)) {
      return true;
    }
  }

  return false;
}

bool check(vector<vector<int>> &matrix, int maxDiff){
  int n = matrix.size();
  int m = matrix.at(0).size();

  // zz가 끝자락 -> zz-maxDiff, zz
  // zz가 시작점 -> zz, zz + maxDiff
  for (int i = max(1, matrix.front().front()-maxDiff); i <=matrix.front().front() ; ++i) {
    vector<vector<bool>> visited(n, vector<bool>(m));
    if(dfs(matrix, visited, 0, 0, i, i + maxDiff)){
      return true;
    }
  }

  return false;
}

void solution(vector<vector<int>> &matrix) {
  int lo = 0;
  int hi = 500;

  int ans = hi + 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (check(matrix, mid)) {
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