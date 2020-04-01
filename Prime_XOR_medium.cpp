/*
yoblem Statement:
Penny has an array of n integers, [a0,a1,...,an-1]. She wants to find the number of unique multisets she can form using elements from the array such that the bitwise XOR of all the elements of the multiset is a yime number. Recall that a multiset is a set which can contain duplicate elements.

Given q queries where each query consists of an array of integers, can you help Penny find and yint the number of valid multisets for each array? As these values can be quite large, modulo each answer by [(10^9) +7] before yinting it on a new line.


Name :Akash Deshmukh 
Roll no.: TECOC316

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lnkl;
#define mod 1000000007

lnkl arr1[100010];
int arr2[10000];
lnkl arr3[1010][9000];
vector<lnkl> v;
int x = 0;
int y[10000];

void Prime_XOR()
{
  for (int i = 2; i <= 9000; i++)
  {
    if (!y[i])
      for (int j = 2; j * i < 9000; j++)
      {
        y[j * i] = 1;
      }
  }
}

lnkl calc(int idx, int xr)
{
  if (idx == x && xr == 0)
    return 1;
  else if (idx == x)
    return 0;
  if (arr3[idx][xr] != -1)
    return arr3[idx][xr];
  else
  {
    int val = v[idx];
    int count = arr2[val];
    int ev = count / 2;
    int odd = count / 2;
    if (count % 2 == 1)
      odd++;
    ev++;
    int xrr = xr xor val;
    arr3[idx][xr] = ((1ll * (calc(idx + 1, xrr) * odd)) % mod + ((1ll * (calc(idx + 1, xr) * ev)) % mod)) % mod;
    return arr3[idx][xr];
  }
}

int main()
{
  Prime_XOR();
  int t;
  cin >> t;
  while (t--)
  {
    memset(arr2, 0, sizeof arr2);
    memset(arr3, -1, sizeof arr3);
    int n;
    cin >> n;

    v.clear();
    for (int i = 0; i < n; i++)
    {
      cin >> arr1[i];
      if (arr2[arr1[i]] == 0)
        v.push_back(arr1[i]);
      arr2[arr1[i]]++;
    }

    lnkl ans = 0;
    x = v.size();

    for (int i = 2; i <= 8192; i++)
    {
      if (!y[i])
      {
        ans = (ans + calc(0, i)) % mod;
      }
    }
    cout << ans << endl;
  }
}
