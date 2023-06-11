#include <iostream>
#include <map>
#include<unordered_map>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include<utility>
#include<climits>
#include<stack>
#include<set>
#include<cmath>
#include<deque>
#include<numeric>
#include<iomanip>
#include<queue>

#define ull unsigned long long
#define ll long long
#define NUM 1000000007
//ll mod  = 1000000007;
using namespace std;



ll binpow(ll x, ll y)
{
    ll res = 1ll; // Initialize result
  
    while (y > 0ll) {
        // If y is odd, multiply x with result
        if (y & 1ll)
            res = ((res%NUM) * (x%NUM))%NUM;
  
        // y must be even now
        y = y >> 1; // y = y/2
        x = ((x%NUM) * (x%NUM))%NUM; // Change x to x^2
    }
    return res%NUM;
}

bool sortbysec(string &a , string &b)
{
    /*if(a.first == b.first)
    {
        return (a.second <= b.second);
    }*/
    return (a[1] <= b[1]) ;
}
 
ll binarysearch(vector<ll> v, ll find,ll l, ll r)
{
    if(find<v[l] or find > v[r]) 
    {
        return -1;
    }
    while(l<=r)
    {
        ll mid  = l + (r-l)/2 ;
        if(v[mid] == find) return mid;
        if(v[mid]  > find) r = mid -1;
        else l =mid +1;
    }
    return -1;
}
int fact(int x)
{
    if(x<=1) return 1;
    int start =1;
    int ans =1;
    while(start<=x)
    {
        ans = ans*start;
        start++;
    }
    return ans;
}
bool isvalid(int i , int j ,int n,int m,vector<vector<int> > adj)
{

    if(i<0 or i> n-1 or j<0 or j> m-1)
    {
        return false;
    }
    if(adj[i][j] == 0) return false;
    return true;
}
void dfs(vector<vector<int> > &adj, vector<vector<bool>> &check, int &ans,int i, int j,int n, int m)
{
    if(check[i][j]) return;
    check[i][j] = true;
    ans+=adj[i][j] ;
    if(isvalid(i+1,j,n,m,adj))
    {
        dfs(adj,check,ans,i+1,j,n,m);
    }
    if(isvalid(i-1,j,n,m,adj))
    {
        dfs(adj,check,ans,i-1,j,n,m);
    }
    if(isvalid(i,j+1,n,m,adj))
    {
        dfs(adj,check,ans,i,j+1,n,m);
    }
    if(isvalid(i,j-1,n,m,adj))
    {
        dfs(adj,check,ans,i,j-1,n,m);
    }
    return;
}
vector<ll> factors(ll a, ll b)
{
    vector<ll> res;
    for(ll i=1;i*i<=a;i++)
    {
        if(a%i ==0)
        {
            res.push_back(i*b);
            res.push_back((a/i)*b);
        }
    }
    return res;
}

void solve()
{
    ll n,k,q;
    cin>>n>>k>>q;
    vector<ll> v;
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        v.push_back(temp);
    }
    vector<ll> count;
    ll c = 0;
    for(ll i=0;i<n;i++)
    {
        if(v[i] <= q) c++;
        else
        {
            count.push_back(c);
            c=0;
        }
    }
    count.push_back(c);
    ll ans =0;
    for(ll i=0;i<count.size();i++)
    {
        if(count[i] >= k)
        {
            ll x = min(count[i],n);
            ll t1  = x - k  +1;
            ans += (count[i] + 1)*(t1) -t1*(k-1) - t1*(t1+1)/2 ;
        }
    }
    cout<<ans<<endl;
    return;
}

    
int main()
{

    
    int t ;
    cin>>t;
    //t=1;
    //int i=1;
    while(t--)
    {
        solve();
    }
    return 0;
    
    
}


    
