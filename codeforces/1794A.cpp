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
    int n,k;
    cin>>n>>k;
    if(k==1)
    {
        cout<<"YES"<<endl;
        return;
    }
    vector<int> num;
    for(int i=0;i<k;i++)
    {
        int temp;
        cin>>temp;
        num.push_back(temp);
    }
    vector<int> v;
    if(n==k)
    {
        v.push_back(num[0]);
        for(int i=1;i<k;i++)
        {
            v.push_back(num[i] - num[i-1]);
        }
        for(int i=0;i<n-1;i++)
        {
            if(v[i+1]>=v[i])
            {
                continue;
            }
            else
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
        return;
    }
    else
    {
        for(int i=1;i<k;i++)
        {
            v.push_back(num[i] - num[i-1]);
        }
        for(int i=0;i<v.size() - 1;i++)
        {
            if(v[i+1]>=v[i])
            {
                continue;
            }
            else
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        int max1 = v[0]*(n-k+1);
        if(max1 >= num[0])
        {
            cout<<"YES"<<endl;
            return;
        }
        else
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    return;
}



 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for(int test_number = 0; test_number < t; test_number++){
        int n; cin >> n;
        vector <string> long_subs;
        for(int i = 0; i < 2 * n - 2; i++){
            string s; 
            cin >> s;
            if((int)s.size() == n - 1){
                long_subs.push_back(s);
            }
        }
        reverse(long_subs[1].begin(), long_subs[1].end());
        if(long_subs[0] == long_subs[1]){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    
    return 0;
}
    

/*int main()
{
    

    int t ;
    cin>>t;
    //t=1;
    
    while(t--)
    {
    
        solve();
    }
    return 0;
    
}*/
