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
    ll n,k;
    cin>>n>>k;
    vector<ll> v;
    map<ll,ll> mp;
    set<ll> s;
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        //v.push_back(temp);
        s.insert(temp);
        mp[temp]++;
    }
    //sort(v.begin(),v.end());
    for(auto i :s)
    {
        v.push_back(i);
    }
    ll start = -1;
    ll end = -1;
    vector<pair<ll,ll> > ans;
    if(mp[v[0]] >=k)
    {
        start = v[0];
        end = v[0];
    }
    for(ll i=1;i<v.size();i++)
    {
        if(v[i] - v[i-1] > 1)
        {
            if(start != -1)
            {
                ans.push_back(make_pair(start,end));
                start = -1;
                end = -1;
            }
            if(mp[v[i]] >=k)
            {
                start = v[i];
                end = v[i];
            }
        }
        else
        {
            if(mp[v[i]] >= k)
            {
                if(start != -1)
                {
                    end  = v[i];
                }
                else
                {
                    start = v[i];
                    end  = v[i];
                }
            }
            else
            {
                if(start!= -1)
                {
                    ans.push_back(make_pair(start,end));
                    start = -1;
                    end = -1;
                }
                
            }
        }
    }
    if(start != - 1)
    {
        ans.push_back(make_pair(start,end));
    }
    if(ans.empty())
    {
        //cout<<"here"<<endl;
        cout<<-1<<endl;
        return;

    }
    ll fin1,fin2;
    ll max1 = -1;
    for(ll i=0;i<ans.size();i++)
    {
        if(ans[i].second - ans[i].first > max1)
        {
            max1 = ans[i].second - ans[i].first ;
            fin1 = ans[i].first;
            fin2 = ans[i].second;
        }
    }
    cout<<fin1<<" "<<fin2<<endl;
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

    


    
