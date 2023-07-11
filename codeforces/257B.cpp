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
bool ispalindrome(string s)
{
    int n = s.length();
    for(int i=0;i<n/2;i++)
    {
        if(s[i] != s[n-1-i]) return false;
    }
    return true;
}


void solve()
{
    int n,m;
    cin>>n>>m;
    /*if(n==1 and m==1)
    {
        cout<<0<<" "<<1<<endl;
        return;
    }
    
    /*int tot = n+m;
    if(tot%2 == 0)
    {
        cout<<tot/2<<" "<<tot/2 - 1<<endl;
        return;
    }*/
    if(n==m)
    {
        cout<<n-1<<" "<<n<<endl;
        return;
    }
    string s ="";
    if(n<m)
    {
        swap(n,m);
    }
    int t1 = n;
    int t2 = m;
    s+='B';
    m= m-1;
    bool flag = true;
    while(n>0 and m>0)
    {
        if(flag)
        {
            if(n>=2)
            {
                s+="RR";
                n-=2;
            }
            else
            {
                s+='R';
                n--;
            }
            flag = false;
        }
        else
        {
            if(m>=2)
            {
                s+="BB" ;
                m-=2;
            }
            else
            {
                s+='B';
                m--;
            }
            flag = true;
        }
    }
    while(n>0)
    {
        s+='R' ;
        n--;
    }
    //cout<<s<<endl;
    int x =0;
    int y=0;
    for(int i=1;i<s.length();i++)
    {
        if(s[i] == s[i-1]) x++;
        else y++;
    }
    //cout<<x<<" "<<y<<endl;

    n=t1;
    m=t2;
    s="";
    s+='R';
    n= n-1;
    flag = false;
    while(n>0 and m>0)
    {
        if(flag)
        {
            if(n>=2)
            {
                s+="RR";
                n-=2;
            }
            else
            {
                s+='R';
                n--;
            }
            flag = false;
        }
        else
        {
            if(m>=2)
            {
                s+="BB" ;
                m-=2;
            }
            else
            {
                s+='B';
                m--;
            }
            flag = true;
        }
    }
    while(n>0)
    {
        s+='R' ;
        n--;
    }
    //cout<<s<<endl;
    int x1=0;
    int y1=0;

    for(int i=1;i<s.length();i++)
    {
        if(s[i] == s[i-1]) x1++;
        else y1++;
    }
    //cout<<x<<" "<<y<<endl;
    if(x1>x)
    {
        cout<<x1<<" "<<y1<<endl;
        return;
    }
    cout<<x<<" "<<y<<endl;
    return;


    //return;


}



int main()
{
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}
