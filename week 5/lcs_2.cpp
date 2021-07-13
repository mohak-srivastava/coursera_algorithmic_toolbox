#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<long long>> v)
{
  for (auto x : v)
  {
    for (auto y : x)
    {
      cout << y << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

int lcs2(vector<long long> &a, vector<long long> &b)
{
  
  vector<vector<long long>> dp(a.size() + 1, vector<long long>(b.size() + 1, 0));
 
  for (int i = 1; i <= a.size(); i++)
  {
    for (int j = 1; j <= b.size(); j++)
    {
      if (a[i - 1] == b[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
 
  return dp[a.size()][b.size()];
}

int main()
{
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  int m;
  cin >> m;
  vector<long long> b(m);
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }

  cout << lcs2(a, b) << endl;
}