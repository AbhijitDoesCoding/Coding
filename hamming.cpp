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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll n; cin >> n;
    string s; 
    cin >> s;
    ll r = 0;
    // redundant bits calculation
    while(pow(2,r) < n+r+1){
        r++;
    }
    ll len = n+r;
    cout << "Redundant bits: " << r << endl;
    cout << "Total bits: " << len << endl;
    // reverse the string
    reverse(all(s));
    ll j = 0;
    // new array to store the bits
    vi arr(len,0);
    loop(i,0,len){
        if((i+1) == pow(2,j)){
            j++;
        }else{
            arr[i] = s[i-j] - '0';
        }
    }
    cout << "Without redundant bits calculation: \n";
    rev(i,0,len){
        cout << arr[i] << " ";
    }
    nline;
    
    // calculation of redundant bits
    loop(i, 0, r){
        ll diff = pow(2, i);
        ll sum = 0;
        for(ll j = diff - 1; j < len; j += 2 * diff){
            for(ll k = 0; k < diff && j+k < len; k++){
                sum ^= arr[j+k];
            }
        }
        arr[diff-1] = sum;
    }

    cout << "With redundant bits calculation: \n";
    rev(i,0,len){
        cout << arr[i] << " ";
    }
    nline;

    //Input position of error bit
    cout << "Enter the position of error bit: ";
    ll pos; cin >> pos;
    arr[pos-1] = !arr[pos-1]; // flip the bit
    cout << "After flipping the bit: \n";
    rev(i,0,len){
        cout << arr[i] << " ";
    }
    nline;

    // Error detection
    ll error = 0;
    loop(i, 0, r){
        ll diff = pow(2, i);
        ll sum = 0;
        for(ll j = diff - 1; j < len; j += 2 * diff){
            for(ll k = 0; k < diff && j+k < len; k++){
                sum ^= arr[j+k];
            }
        }
        if(sum != arr[diff-1]){
            error += diff;
        }
    }
    if(error == 0)
        cout << "No error detected\n";
    else
        cout << "Error detected at position: " << error << endl;
    return 0;
}