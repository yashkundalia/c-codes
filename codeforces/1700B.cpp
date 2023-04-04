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
    int n;
    cin>>n;
    string s;
    cin>>s;
    
    vector<int>  ans(n,0);
    if(s[0] == '9')
    {
        /*int i=0;
        if(s[i] >= s[n-1 - i])
        {
            int num = s[i] - '0';
            int num1 = s[n-1-i] - '0' ;
            //cout<<num<<endl;
            ans[i] = 9 - num;
            ans[n-1-i] = 9 - num1;
            //s[i] = '9';
            i++;
        }*/
        int i=0;
        while(i<n)
        {
            int req =  '9' - s[i];
            ans[i] = req;
            i++;
        }
        /*while(i<= (n-1)/2)
        {
            if(s[i] <= s[n-1-i])
            {
                int req = s[n-1-i] - s[i] ;
                ans[i] = req;
                ans[n-1-i] = 0; 
            }
            else if(s[i] >  s[n-1-i])
            {
                int req = s[i] - s[n-1-i] ;
                ans[n-1-i] = req;
                ans[i] = 0; 
            }
            i++;
        }*/
    
        int carry = (ans[n-1] + 2)/10;
        ans[n-1] = (ans[n-1] + 2)% 10;
        for(int i=n-2;i>=0;i--)
        {
            ans[i] = (ans[i] + carry + 1);
            carry = ans[i]/10;
            ans[i] = ans[i]%10;
        }
        string s1;
        for(int i=0;i<n;i++)
        {
            s1+=to_string(ans[i]);
        }
        cout<<s1<<endl;
        //cout<<endl;
        return;
        
    }
    int i=0;
    if(s[i] >= s[n-1 - i])
    {
        int num = s[i] - '0';
        int num1 = s[n-1-i] - '0' ;
        //cout<<num<<endl;
        ans[i] = 9 - num;
        ans[n-1-i] = 9 - num1;
        //s[i] = '9';
        i++;
    }
    
    while(i<= (n-1)/2)
    {
        if(s[i] <= s[n-1-i])
        {
            int req = s[n-1-i] - s[i] ;
            ans[i] = req;
            ans[n-1-i] = 0; 
        }
        else if(s[i] >  s[n-1-i])
        {
            int req = s[i] - s[n-1-i] ;
            ans[n-1-i] = req;
            ans[i] = 0; 
        }
        i++;
    }
    string s1;
    for(int i=0;i<n;i++)
    {
        s1+=to_string(ans[i]);
    }
    cout<<s1<<endl;
    //cout<<endl;
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
    return 0;
    
}
