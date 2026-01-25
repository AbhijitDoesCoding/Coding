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

struct Edge {
    int to;
    long long cost;
    bool operator>(const Edge& other) const {
        return cost > other.cost;
    }
};

void solve(){
    // Your code here
    ll n;
    cin >> n;

    vector<int> x(n), a(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> a[i];

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    vector<bool> visited(n, false);

    pq.push({0, 0});
    long long totalCost = 0;

    while (!pq.empty()) {
        Edge current = pq.top();
        pq.pop();

        int node = current.to;
        long long cost = current.cost;

        if (visited[node]) continue;

        visited[node] = true;
        totalCost += cost;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && i != node) {
                long long dist = abs(x[i] - x[node]);
                long long threadCost = min(a[i], a[node]);
                pq.push({i, dist * threadCost});
            }
        }
    }

    cout << totalCost << endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}