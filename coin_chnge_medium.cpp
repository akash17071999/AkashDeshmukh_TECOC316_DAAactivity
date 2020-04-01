/*
Problem Statement:

You are working at the cash counter at a fun-fair, and you have different types of coins available to you in infinite quantities. The value of each coin is already given. Can you determine the number of ways of making change for a particular number of units using the given types of coins?

For example, if you have 4 types of coins, and the value of each type is given as 8,3,1,2 respectively, you can make change for 3 units in three ways: {1,1,1}, {1,2}, and {3}.



Name: Akash Deshmukh
Roll No. TECOC316

*/

#include <bits/stdc++.h>
using namespace std;

#define lnkl long long int

lnkl coinchange(lnkl arr2[], lnkl a, lnkl b)
{
  lnkl arr1[a + 1][b + 1];
  for (lnkl i = 0; i < a + 1; i++)
  {
    arr1[i][0] = 1;
  }
  for (lnkl j = 0; j < b + 1; j++)
  {
    arr1[0][j] = 0;
  }
  for (lnkl i = 1; i < a + 1; i++)
  {
    for (lnkl j = 1; j < b + 1; j++)
    {
      if (arr2[i - 1] > j)
      {
        arr1[i][j] = arr1[i - 1][j];
      }
      else
      {
        arr1[i][j] = (arr1[i - 1][j] + arr1[i][j - arr2[i - 1]]);
      }
    }
  }

  return arr1[a][b];
}
int main()
{
  lnkl a;
  cin >> a;
  lnkl b;
  cin >> b;

  lnkl arr1[b];
  for (lnkl i = 0; i < b; i++)
    cin >> arr1[i];
  cout << coinchange(arr1, b, a);
}
