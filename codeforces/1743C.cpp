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

bool sortbysec(pair<ll,ll> &a , pair<ll,ll> &b)
{
    if(a.first == b.first)
    {
        return (a.second <= b.second);
    }
    return (a.first < b.first) ;
}
 
int binarysearch(vector<int> v, int find,int l, int r)
{
    if(find<v[l] or find > v[r]) 
    {
        return -1;
    }
    while(l<=r)
    {
        int mid  = l + (r-l)/2 ;
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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> v;
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        v.push_back(temp);
    }
    //vector<pair<ll,ll> > nums;
    ll start = -1;
    for(ll i=0;i<n;i++)
    {
        if(s[i] == '0')
        {
            start = i;
            break;
        }
    }
    ll sum =0;
    if(start ==-1)
    {
        for(ll i=0;i<n;i++)
        {
            sum+=v[i];
        }
        cout<<sum<<endl;
        return;
    }
    ll i=start;
    //cout<<start<<endl;
    while(i<n)
    {
        if(s[i] == '1')
        {
            ll prev = i-1 ;
            ll min1 = v[i-1];
            ll ind =-1;
            //cout<<min1<<" "<<i<<endl;
            while(s[i]!= '0' and i < n)
            {
                if(min1>=v[i])
                {
                    min1 =v[i];
                    ind =i;
                    //cout<<min1<<" "<<ind<<endl;
                }
                i++;
            }
            if(ind != -1)
            {
                //cout<<prev<<" "<<ind<<endl;
                s[prev] = '1';
                s[ind] = '0';
            }
            //nums.push_back(make_pair(min1,ind));
        }
        else i++;
    }
    for(ll i=0;i<n;i++)
    {
        if(s[i] == '1')
        {
            sum+=v[i];
        }
    }
    cout<<sum<<endl;
    return;

}



    

int main()
{
    

    int t ;
    cin>>t;
    //t=1;
    
    while(t--)
    {
    
        solve();
    }
    return 0;
    
}
