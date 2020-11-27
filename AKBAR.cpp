//  https://www.spoj.com/problems/AKBAR/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
 
 
/* 
*    coder :: ATUL_PANDEY_2608
*        >>> INDIA <<<
*/	
using namespace std;
using namespace __gnu_pbds;
 
// #define  part ..
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end() 
#define mod 1000000007
//#define maxx 200006
#define ll long long 
#define quick    ios_base::sync_with_stdio(NULL),cin.tie(0);
#define listll vector< long long > 
#define listi vector< int> 
#define pii   pair<int , int> 
#define pll pair<long long , long long > 
#define minheap priority_queue<long long , vector< long long >, greater<long long > >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define sc(i) scanf("%d", &i )
#define scl(i) scanf("%lld" , &i ) 
 
 
 
 
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
 
ll power( ll a, ll n, ll m= 1000000007){
  ll ans = 1;
  while(n){
  if(n&1)
  {
  ans *= a;
  ans%=m;
  }
  a*=a;
  a%=m;
  n/=2;
  }
  return ans ;
} 
 
 
vector< int > prm ;
vector < bool > vsp ;
 
void prime ( int nn = 100000 ) {
	vsp = vector < bool > ( nn+1, 0 );
	int size_prime = nn;
	for( ll i =2; i*i < size_prime ; i++){
		
		if( vsp[i] == 1)
		continue;
		for(ll j = i*i; j < size_prime ;j+=i){
			
			vsp[j] =1;
			
		}
		
		
	}
	
	for( int i= 2; i < size_prime ; i++)
	if (vsp[i] == 0)
	prm.pb(i);
	
	
}
 
 
template < class T > using oset = tree< T , null_type, less  < T  > , rb_tree_tag , tree_order_statistics_node_update > ;
 
 
// end of #define 
 
// define globals ...
const int maxx = 2e5+26;
 
//write function from here ...
// never forget  to recheck your predefined function in template .. 
// already defined ::  prime , power , gcd : ( ll ).. 
 
 
 
vector< vector< int > > adj ; 
vector< bool > vis ;
vector<bool > sol ;
void dfs( int u , int cnt )
{ 
	queue < array < int ,2 > > q;
	q.push({u,cnt});
	while(q.size()>0){	
		array < int , 2>  temp = q.front();
		q.pop();
		//cout<<temp[0]<<endl;
		if( vis[temp[0]] == 1 )
		continue;
		vis[temp[0]] =1; 
		
		if( temp[1] == 0)
		continue;
		
		for( auto it: adj[temp[0]]){
	 		if( sol[it ]==0 && vis[it]==0 && temp[1] >0){
			q.push( {it , temp[1] -1 }); 
	    	}
		}
	}
}
 
 
int Main(){
	
	int  n ,r , m ;
	scanf("%d%d%d" , &n,&r,&m);
	vis = vector< bool > ( n +1  , 0 ) ;
	adj = vector< vector <int  > > ( n + 1 ) ;
	sol = vector< bool > ( n+1 , 0 ) ;
	for( int i =0 ; i < r ;i++){
		
		int a,b;
		scanf("%d %d" ,&a,&b );
		a-- , b-- ;
		adj[a].pb( b) ;
		adj[b] . pb(a);
	}
   
    int flag = 1 ;
    vector< array < int , 2 >  > ss(m)  ;
    
    for( int i =0 ; i < m;i++){
		
		int a, s; 
		scanf( "%d %d" ,&a, &s) ; 
		a-- ;
		ss[i] = {a,s} ;
		sol[a] = 1 ;
 
		
	}   
	
	for(int i=0; i < m;i++){
		
		dfs( ss[i][0] , ss[i][1]) ;
		
	}
	for( int i =0  ; i < n;i++){
		
		if( vis[i] == 0 )
		{
			//cout<<i<<endl;
			flag = 0 ;
		}
		
	}
  
  
    if( flag == 1 ) {
		printf("Yes\n");
	}
	else{
		
		printf("No\n");
	}
  
  
return 0;
 
}
 
 
 
 
 
 
int main(){
 quick;
int t =1; 
scanf("%d", &t);
while(t-- )
 Main();
 
 return 0;
}
 
 
  
