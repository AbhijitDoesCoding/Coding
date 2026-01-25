#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nline cout<<"\n";
#define yes cout<<"Yes\n";
#define no cout<<"No\n";
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define e 2.718281828459045235360
#define inf 1e18
#define PI 3.1415926535897932384626
#define loop(i,l,h) for(int i=l;i<h;i++)
#define rev(i,l,h) for(int i=h-1;i>=l;i--)

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi;
typedef pair<ll,ll> pi;
/*C. Special Triangle
time limit per test
2 seconds
memory limit per test
256 megabytes

A triangle of numbers is called a 'Special Triangle' if every number in each row (except the last row) is strictly less than the two numbers which are just below it. Consider the example shown in the first figure. Every number is less than the numbers which are just below it (except the numbers in the last row). For the first row, the numbers which are just below the 2
are 3 and 3. For the second row, the elements below the first 3 are 5 and 4, and for the second 3 are 4 and 5

.

Now consider the second example figure. The element marked in red is violating the property of Special Triangle.

You have given an array of numbers. You have to find whether you can construct a Special Triangle using only those numbers. If you can construct such a triangle, print 'YES', otherwise 'NO'.
Input

The first line contains height of the triangle h,1≤h≤1000

that you need to construct using the given numbers.

The second line contains n=h∗(h+1)/2
space-separated numbers, A1,A2,…,An an such that 0≤Ai≤109

.
Output

If you can construct a Special triangle using the given numbers print 'YES', otherwise 'NO' (without quotes).
Examples
Input
Copy

3
5 4 2 3 5 3

Output
Copy

YES

Input
Copy

3
6 3 2 2 3 3

Output
Copy

NO

Note

Explanation 1: See the above first example figure.

Explanation 2: We can't able to construct any special triangle using these number

*/
void solve(){
    // write your code here
    ll n;
    cin >> n;
    ll size = n*(n+1)/2;
    vi a(size);
    loop(i, 0, size){
        cin >> a[i];
    }
    if(n == 1){
        cout << "YES";
        return;
    }
    sort(all(a));
    
    if(a[0] >= a[1]){
        cout << "NO";
        return;
    }

    loop(i, 1, n-1){
        ll end = (i+1)*(i+2)/2;
        ll start = i*(i+1)/2;
        if(a[end] <= a[end-1]){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
    
}
/*
void solve(){
    // write your code here
    ll n;
    cin >> n;
    ll size = n*(n+1)/2;
    vi a(size);
    vi b(n);
    loop(i, 0, size){
        cin >> a[i];
    }
    if(n == 1){
        cout << "YES";
        return;
    }
    sort(all(a));
    ll lastrowhighest = a[0];
 
    ll nextrowlowest = a[1];
    if(nextrowlowest <= lastrowhighest){
        cout << "NO";
        return;
    }
    loop(i, 1, n){
        ll start = (i*(i+1))/2;
        ll end = (i+1)*(i+2)/2;
        b[i] = a[end-1];
        if(i > 1){
            if(b[i] <= b[i-1]){
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES";
}
*/
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll t = 1;
    // cin >> t;
    while(t--){
        // cout << "Case #" << t << ": \n";
        solve();
    }
    return 0;
}