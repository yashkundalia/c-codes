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
    int n,k,r,c;
    cin>>n>>k>>r>>c;
    vector<int> rows(n+1,0);
    vector<int> cols(n+1,0);
    //rows[r] = 1;
    //cols[c] = 1;
    vector<pair<int,int> > ans;
    //ans.push_back(make_pair(r,c));
    int num = n/k ;
    int num1 = num;
    while(num1>0)
    {
        //cout<<num1<<"num1"<<endl;
        num = n/k;
        while(num>0)
        {
            ans.push_back(make_pair(r,c));
            c=(c+k)%n;
            if(c==0) c=n;
            //cout<<r<<" "<<c<<endl;
            rows[r] = 1;
            cols[c] = 1;
            num--;
        }
        r= (r+k)%n;
        if(r==0) r=n;
        //cout<<r<<"r"<<endl;
        num1--;
    }
    
    for(int i=1;i<=n;i++)
    {
        if(rows[i] == 0)
        {
            //cout<<i<<"row"<<endl;
            for(int j=1;j<=n;j++)
            {
                if(cols[j] == 0 )
                {
                    num1 = n/k;
                    r = i;
                    c=j;
                    while(num1>0)
                    {
        
                        num = n/k;
                        while(num>0)
                        {
                            ans.push_back(make_pair(r,c));
                            //cout<<r<<" "<<c<<endl;
                            c=(c+k)%n;
                            if(c==0) c= n;
                            rows[r] = 1;
                            cols[c] = 1;
                            num--;
                        }
                        r= (r+k)%n;
                        if(r==0) r=n;
                        //cout<<r<<"r"<<endl;
                        num1--;
                    }
                    break;
                }
            }
        }
        
    }

    //vector<vector<char> > v(n+1,vector<char> (n+1 ,'.'));
    string s = "";
    for(int i=0;i<n;i++)
    {
        s+=".";
    }
    vector<string> v(n ,s);

    for(int i=0;i<ans.size();i++)
    {
        v[ans[i].first-1][ans[i].second-1] = 'X';
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[i][j];
        }
        cout<<endl;
    }
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
