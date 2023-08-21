#define _USE_MATH_DEFINES

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
#include<math.h>
#include<deque>
#include<numeric>
#include<iomanip>
#include<queue>

#define ull unsigned long long
#define ll long long
#define NUM 1000000007
//ll mod  = 1000000007;
using namespace std;
/*
cout.precision(10);
cout.setf(ios::fixed);
*/



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

bool sortbysec(pair<ll,ll> &a , pair<ll,ll> &b)
{
    if(a.first == b.first)
    {
        return (a.second <= b.second);
    }
    else return (a.first > b.first) ;
    
    
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
bool ispalindrome(string s)
{
    int n = s.length();
    for(int i=0;i<n/2;i++)
    {
        if(s[i] != s[n-1-i]) return false;
    }
    return true;
}

void dfs(int parent , int i , vector<vector<int>> &adj , vector<bool> &check , set<int> &ans)
{
    //cout<<parent<<"parent"<<endl;
    //cout<<check[parent]<<endl;
    /*if(check[parent])
    {

    }*/
    /*if(check[parent])
    {
        cout<<i<<" "<<parent<<endl;
        ans++;
        //cout<<ans<<" "<<parent<<endl;
    }*/
    if(check[parent] and parent == i)
    {
        ans.insert(i);
        //cout<<parent<<endl;

    }
    if(check[i]) return;
    check[i]  = true;
    for(auto j :adj[i])
    {
        /*if(check[j]) 
        {
            ans++;
            cout<<j<<endl;
        }*/
        dfs(parent,j,adj,check,ans);
    }
    return;
}


void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll> > v;
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        v.push_back(make_pair(temp,i+1)) ;
    }
    if(m < n or n==2)
    {
        cout<<-1<<endl;
        return;
    }
    ll ans =0;
    vector<pair<ll,ll> > res;
    sort(v.begin(),v.end()) ;
    ans+=v[0].first + v[n-1].first ;
    res.push_back(make_pair(v[0].second , v[n-1].second)) ;
    for(int i=0;i<n-1;i++)
    {
        ans+=v[i].first + v[i+1].first ;
        res.push_back(make_pair(v[i].second , v[i+1].second)) ;
        //cout<<v[i].second<<" "<<v[i+1].second<<endl;
    }
    for(ll i= n;i<m;i++)
    {
        res.push_back(make_pair(v[0].second ,v[1].second)) ;
        ans+=v[0].first + v[1].first;
    }
    cout<<ans<<endl;
    for(ll i=0;i<m;i++)
    {
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
    return;

    
}  


int main()
{
    int t;
    cin>>t;
    //t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}
