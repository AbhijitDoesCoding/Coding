/*PROBLEM STATEMENT: 
A business house has several offices in different countries; 
they want to lease phone lines to connect them with each other and the phone company charges different rent to connect different pairs of cities. 
Business house wants to connect all its offices with a minimum total cost. Solve the problem using Prim’s algorithm.
*/

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
#define loop(i,l,h) for(ll i=l;i<h;i++)
#define rev(i,l,h) for(ll i=h-1;i>=l;i--)

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi;
typedef pair<ll,ll> pi;

bool directed = true;

class prims{
    ll costadj[20][20];
    ll n;
    public:
    prims(){
        n=0;
        loop(i,0,20){
            loop(j,0,20){
                costadj[i][j]=INT_MAX;
            }
        }
    }
    void accept();
    void primsalgo(ll start_v);
    void display();
};

void prims::display(){
    loop(i,0,n){
        loop(j,0,n){
            if(costadj[i][j]==INT_MAX) cout<<"INF\t";
            else cout<<costadj[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void prims::accept(){
    cout << "\nEnter 1 if the graph is directed, 0 if undirected: ";
    cin >> directed;

    cout<<"Enter the number of vertices: \n";
    cin>>n;
    cout<<"Enter the cost adjacency matrix: \n";
    if(directed == true){
        loop(i,0,n){
            loop(j,0,n){
                if (i == j) {
                    costadj[i][j] = INT_MAX;
                    continue;
                }
                char ch;
                cout<<"Is there an edge between "<<i<<" and "<<j<<"? (y/n): ";
                cin>>ch;
                if(ch=='y'){
                    cout<<"Enter the cost: ";
                    cin>>costadj[i][j];
                } else {
                    costadj[i][j] = INT_MAX;
                }
            }
        }
    }
    else{
        loop(i,0,n){
            loop(j,i+1,n){
                char ch;
                cout<<"Is there an edge between "<<i<<" and "<<j<<"? (y/n): ";
                cin>>ch;
                if(ch=='y'){
                    cout<<"Enter the cost: ";
                    cin>>costadj[i][j];
                    costadj[j][i] = costadj[i][j];
                } 
            }
        }
    }
}

void prims::primsalgo(ll start_v){
    vi nearest(n, -1);
    vector<bool> inMST(n, false);
    vector<pair<ll, ll>> mstEdges;
    ll mincost = 0;

    nearest[start_v] = -1;
    for (ll i = 0; i < n; i++) {
        if (i != start_v) {
            nearest[i] = start_v;
        }
    }

    for (ll i = 1; i < n; i++) {
        ll min = INT_MAX;
        ll j = -1;

        for (ll k = 0; k < n; k++) {
            if (!inMST[k] && nearest[k] != -1 && costadj[k][nearest[k]] < min) {
                j = k;
                min = costadj[k][nearest[k]];
            }
        }

        if (j == -1) break;

        mstEdges.pb({nearest[j], j});
        mincost += costadj[j][nearest[j]];
        inMST[j] = true;
        for (ll k = 0; k < n; k++) {
            if (!inMST[k] && costadj[k][j] < costadj[k][nearest[k]]) {
                nearest[k] = j;
            }
        }
    }

    cout << "Minimum cost: " << mincost << "\n";
    cout << "Edges in MST:\n";
    for (auto edge : mstEdges) {
        cout << edge.first << " - " << edge.second << " = " <<costadj[edge.second][edge.first] << "\n";
    }
}


signed main(){
    cout << "PRIM'S ALGORITHM\n";
    cout << "----------------\n";
    prims p;
    ll choice;
    while (true) {
        cout << "1. Input new matrix\n";
        cout << "2. Display the adjacency matrix\n";
        cout << "3. Find MST (Directed)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                p.accept();
                break;
            case 2:
                p.display();
                break;
            case 3:
                directed = true;
                p.primsalgo(0);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

}

// Time Complexity: O(V^2)
// Space Complexity: O(V^2)
// Where V is the number of vertices in the graph.
