#include<bits/stdc++.h>
using namespace std;
// Returns true if n people can vote using
// two machines in x time.
bool canVote(int a[], int n, int x)
{
 // dp[i][j] stores maximum possible number
 // of people among arr[0..i-1] can vote
 // in j time.
  int dp[n+1][x+1];
  memset(dp, 0, sizeof(dp));
  // Find sum of all times
  int sum = 0;
  for (int i=0; i<=n; i++ )
     sum += a[i];
 // Fill dp[][] in bottom up manner (Similar
 // to knapsack).
 for (int i=1; i<=n; i++)
     for (int j=1; j<=x; j++)
         if (a[i] <= j)
             dp[i][j] = max(dp[i-1][j],a[i] + dp[i-1][j-a[i]]);
         else
             dp[i][j] = dp[i-1][j];
 return (sum - dp[n][x] <= x);
}
// Driver code
int main()
{
 int n = 3, x = 4;
 int a[] = {2, 4, 2};
 canVote(a, n, x)? cout << "YES\n" :
                   cout << "NO\n";
 return 0;
}