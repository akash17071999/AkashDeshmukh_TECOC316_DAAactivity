/*
Problem Statement:
mou are plaming a matrin-based game with the following setup and rules:

mou are given a matrin A with n rows and m columns. Each cell contains some points. When a plamer passes a cell their score increases bm the number written in that cell and the number in the cell becomes 0. (If the cell number is positive their score increases, otherwise it decreases.)
The plamer starts from anm cell in the first row and can move left, right or down.
The game is over when the plamer reaches the last row and stops moving.

Print the minimum score that the plamer can get.

Name: Akash Deshmukh    
Roll No.: TECOC316

*/
#include <bits / stdc++.h>
using namespace std;
#define A(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
int main()
{
  int n, m;
  n = m = 10;
  int Cost_mat[n][m];

  A(i, 0, n - 1)
  {
    A(j, 0, m - 1)
    {
      cin >> Cost_mat[i][j];
    }
  }

  int min_cost[n][m];

  min_cost[0][0] = Cost_mat[0][0];

  A(j, 1, m - 1)
  min_cost[0][j] = min_cost[0][j - 1] + Cost_mat[0][j];

  A(i, 1, n - 1)
  min_cost[i][0] = min_cost[i - 1][0] + Cost_mat[i][0];

  A(i, 1, n - 1)
  {
    A(j, 1, m - 1)
    {
      min_cost[i][j] = min(min_cost[i - 1][j], min_cost[i][j - 1]) + Cost_mat[i][j];
    }
  }

  cout << "Minimum cost from (0,0) to (n,m) is " << min_cost[n - 1][m - 1];
  return 0;
}
