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

int dfs(int i, vector<vector<int> > &adj , vector<bool> &check , int &ans , string s )
{
    //ans+=1;
    if(check[i-1]) return 0;
    check[i-1] = true ;
    ll temp = 0;
    if(s[i-1] == 'B') temp++;
    if(s[i-1] == 'W') temp--;
    //cout<<i<<" "<<temp<<endl;
    //if(temp == 0) ans++;
    for(auto j : adj[i])
    {
        if(!check[j-1])
        {
            
            temp +=dfs(j ,adj,check,ans,s);
        }
    }
    if(temp == 0)
    {
        ans++;
    }
    return temp;
}
/*
void fun()
{

}*/
void solve()
{
    int n;
    cin>>n;
    vector<vector<int> > v(n+1);
    for(int i=1;i<n;i++)
    {
        int temp;
        cin>>temp;
        v[temp].push_back(i+1);
        v[i+1].push_back(temp);
    }
    string s;
    cin>>s;
    vector<bool> check(n,false) ;
    int ans = 0;
    int temp1 = 0;
    int cnt = dfs(1,v,check,ans ,s) ;
    cout<<ans<<endl;
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
