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
/*
void findRoots(ll a, ll b, ll c)
{
    // If a is 0, then equation is not quadratic, but
    // linear
    if (a == 0) {
        cout << "Invalid";
        return;
    }
    //cout<<a<<" "<<b<<" "<<c<<endl;
    ull d = b * b + 4 * a * abs(c);
    //cout<<b*b<<endl;
    //cout<<4*a*c<<endl;
    ll sqrt_val = sqrt(abs(d));
    //cout<<d<<endl;
 
    if (d > 0) {
        //cout << "Roots are real and different \n";
        cout << (-b + sqrt_val) / (2 * a) << "\n" ;
             
    }
    else if (d == 0) {
        //cout << "Roots are real and same \n";
        cout << -b / (2 * a);
    }
    else // d < 0
    {
        cout<<d<<endl;
        cout << "Roots are complex \n";
    }
}
/*
void solve()
{
    ll n,c;
    cin>>n>>c;
    ll sum1 =0;
    ll sum2 = 0;
    for(ull i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        sum1+=temp;
        sum2+=temp*temp;
    }
    for(ll i=1;i<c;i++)
    {
        ll term = sum2 + 4*sum1*i + 4*i*i*n ;
        if(term == c)
        {
            cout<<i<<endl;
            return;
        }
    }
    //cout<<sum2<<" "<<c<<endl;
    findRoots(4*n , 4*sum1 , sum2-c);
    return;
    ull l =1;
    ull r = c;
    while(l<r)
    {
        ull i = l+ (r-l)/2;
        ull term = sum2 + 4*sum1*i + 4*i*i*n ;
        if(term==c)
        {
            cout<<i<<endl;
            return;
        }
        if(term>c)
        {
            r = i-1;
        }
        else l =i+1;
    }
    //return;
}
*/
/*
void solve()
{
    ll n;
    cin>>n;
    vector<ll> v;
    for(ll i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        v.push_back(temp);
    }
    vector<ll> cnt(n+1,0);
    for(ll i=0;i<n;i++)
    {
        ll j=0ll;
        ll dist = 0ll;
        while(dist<n)
        {
            dist = j+v[i];
            j =dist;
            cnt[dist]++;
        }
    }
    cout<<*max_element(cnt.begin(),cnt.end())<<endl;
    return;
}  
*/
void solve()
{
    ll n;
    cin>>n;
    vector<pair<ll ,ll > > v;
    for(ll i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    ll cnt = 0;
    map<ll,ll> mp1;
    map<ll,ll> mp2;
    map<ll,ll> mp3;
    map<ll,ll> mp4;
    for(ll i=0;i<n;i++)
    {
        mp1[v[i].second - v[i].first]++ ;
        mp2[v[i].second]++;
        mp3[v[i].first]++;
        mp4[v[i].second  + v[i].first]++ ;
    }
    for(auto i:mp1)
    {
        ll num = i.second ;
        cnt+=(num*(num-1))/2 ;
    }
    //cout<<cnt<<endl;
    for(auto i:mp2)
    {
        ll num = i.second ;
        cnt+=(num*(num-1))/2 ;
    }
    for(auto i:mp3)
    {
        ll num = i.second ;
        cnt+=(num*(num-1))/2 ;
    }
    for(auto i:mp4)
    {
        ll num = i.second ;
        cnt+=(num*(num-1))/2 ;
    }
    cout<<2*cnt<<endl;
    return;
    /*
    for(ll i=0;i<n;i++)
    {
        for(ll j=i+1;j<n;j++)
        {
            ll d1 = v[j].second - v[i].second;
            ll d2 = v[j].first - v[i].first ;
            if(d1 == 0 or d2 == 0)
            {
                cnt++;
            }
            else if(d1 == d2) cnt++;
            else if(d1+d2 == 0) cnt++;
        }
    }
    cout<<2*cnt<<endl;*/
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
