
#include <bits/stdc++.h>
using namespace std;

#define int   long long
#define gcd   __gcd
#define pb    push_back
#define pf    push_front
#define em    emplace        //use in place of insert(x) or insert(position,x)
#define emb   emplace_back
#define pof   pop_front
#define pob   pop_back
#define ump   unordered_map
#define mpr    make_pair
#define fs    first
#define sc    second
#define deq   deque
#define stk   stack
#define LETSGO int TESTCASES;cin>>TESTCASES;while(TESTCASES--)
#define fr(a,b,c) for(int a=b;a<c;a++)
#define setbit(x) __builtin_popcount(x)
#define all(el) el.begin(),el.end()
#define BOOM ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define totalSum(el) accumulate(el.begin(),el.end(),0ll)
#define pinf LLONG_MAX
#define ninf LLONG_MIN
#define endl "\n"

void printans(std::vector<int>&a)
{
  int n = a.size();
  for (int i = 0; i < n; i++)
    cout << a[i] << " \n"[i == n - 1];
  return;
}




void solveTestCases()
{
    int n , m , x;
    cin>>n>>m>>x;

    int clm = x/n +(x%n!=0);
    int row = (x%n==0)?n:(x%n);

    if(clm==m)
    {
      cout<<m*row<<endl;
      return;
    }


    cout<<(row-1) * m + clm<<endl;

    return;
}

int32_t main() {
   BOOM
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif
    
      LETSGO
        solveTestCases ();
          
     
  return 0;
}
