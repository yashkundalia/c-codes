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
#define NUM 998244353
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
bool isvalid(ll i , ll j ,ll n,ll m)
{
    if(i<0 or i> n-1 or j<0 or j> m-1)
    {
        return false;
    }
    return true;
}
void dfs(vector<vector<int> > &adj, vector<bool> &check, int i)
{
    if(check[i]) return;
    check[i] = true;
    for(auto j : adj[i])
    {
        if(!check[j]) dfs(adj,check,j) ;
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
    ll n,l,r;
    cin>>n>>l>>r;
    vector<ll> v;
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    ll ans =0;
    for(ll i=0;i<n-1;i++)
    {
        if(r - v[i] >=v[i])
        {
            ll find = r-v[i];
            ll ind  = upper_bound(v.begin() + i+1,v.end() , find) - v.begin();
            //cout<<ind<<"ind"<<endl;
            ind--;
            ans+=ind-i;
            //if(ind == n) ans--;
            //cout<<find<<" "<<ans<<endl;
        }
        else break;
    }
    ll ans1=0;
    for(ll i=0;i<n-1;i++)
    {
        if(l-1 - v[i] >=v[i])
        {
            ll find = l-1-v[i];
            ll ind  = upper_bound(v.begin() + i+1,v.end() , find) - v.begin();
            ind--;
            ans1+=ind-i;
            //if(ind ==n) ans1--;
        }
        else break;
    }

    cout<<ans-ans1<<endl;
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
        //cout<<i<<endl;
        solve();
        //i++;
    }
    
}

    


    
