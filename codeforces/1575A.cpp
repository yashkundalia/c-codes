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
/*ll count(ll num)
{
    if(num == 0) return 0;
    ll ans1 =0;
    while(num!=0)
    {
        ans1++;
        num/=2;
    }
    return ans1;
}
void solve()
{
    string s;
    cin>>s;
    ll n = s.length();
    map<char,ll> mp;
    for(ll i=0;i<n;i++)
    {
        mp[s[i]]++;
    }
    ll m1 = -1;
    char c;
    for(auto i: mp)
    {
        if(i.second > m1)
        {
            c = i.first;
            m1 = i.second;
        }
    }
    if(m1 == 1)
    {
        cout<<count(n) - 1<<endl;
        return;
    }
    vector<ll> cnt;
    ll st =0;
    for(ll i=0;i<n;i++)
    {
        if(s[i]== c)
        {
            cnt.push_back(st);
            st=0;
        }
        else st++;
    }
    cnt.push_back(st);
    ll ans=0;
    for(ll i=0;i<cnt.size();i++)
    {
        ans = max(ans,count(cnt[i]));
    }
    cout<<ans<<endl;
    return;


}

*/
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<string,ll> > v;
    for(ll i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        v.push_back(make_pair(temp,i+1));
    }
    for(ll j=0;j<n;j++)
    {
        string s1 = v[j].first;
        for(ll i=0;i<m;i++)
        {
            if(i%2 == 1)
            {
                s1[i] = 'z' + 'a' - s1[i];
            }
            else continue;
        }
        v[j].first = s1;
    }
    sort(v.begin(),v.end());
    for(ll i=0;i<n;i++)
    {
        cout<<v[i].second<<" ";
    }
    cout<<endl;
    return;

    
}
int main()
{

    int t ;
    //cin>>t;
    t=1;
    //int i=1;
    while(t--)
    {
        //cout<<i<<endl;
        solve();
        //i++;
    }
    
}

    


    
