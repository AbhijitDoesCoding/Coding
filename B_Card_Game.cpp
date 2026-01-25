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
/*Suneet and Slavic play a card game. The rules of the game are as follows:

    Each card has an integer value between 1

and 10
.
Each player receives 2

    cards which are face-down (so a player doesn't know their cards).
    The game is turn-based and consists exactly of two turns. In a round, both players pick a random unflipped card and flip it. The player who flipped a card with a strictly greater number wins the round. In case of equality, no one wins the round.
    A player wins a game if he wins the most number of rounds (i.e. strictly greater than the other player). In case of equality, no one wins the game. 

Since Suneet and Slavic aren't best friends, you need to calculate the number of ways the game could happen that Suneet would end up as the winner.

For a better understanding, please check the notes section.
Input

The first line contains an integer t
(1≤t≤104

) — the number of test cases.

The first and only line of each test case contains 4
integers a1, a2, b1, b2 (1≤a1,a2,b1,b2≤10) where a1 and a2 represent the cards Suneet has, and b1 and b2

represent the cards Slavic has, respectively.
Output

For each test case, output a single integer — the number of games Suneet would win considering all possible games.*/
void solve(){
    // Your code here
    ll a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1 > b1 && a2 > b2 && a1 > b2 && a2 > b1) cout<<4<<"\n";
    else if(a1 <= b1 && a2 <= b2 && a1 <= b2 && a2 <= b1) cout<<0<<"\n";
    else if(a1 > b1 && a2 <= b2 && a1 <= b2 && a2 <= b1) cout<<1<<"\n";        
    else if(a1 <= b1 && a2 > b2 && a1 <= b2 && a2 <= b1) cout<<1<<"\n";
    else if(a1 <= b1 && a2 <= b2 && a1 > b2 && a2 <= b1) cout<<1<<"\n";
    else if(a1 <= b1 && a2 <= b2 && a1 <= b2 && a2 > b1) cout<<1<<"\n";
    else if(a1 > b1 && a2 > b2 && a1 <= b2 && a2 <= b1) cout<<2<<"\n";
    else if(a1 > b1 && a2 > b2 && a1 <= b2 && a2 > b1) cout<<2<<"\n";
    else if(a1 > b1 && a2 > b2 && a1 > b2 && a2 <= b1) cout<<2<<"\n";
    else if(a1 <= b1 && a2 <= b2 && a1 > b2 && a2 > b1) cout<<2<<"\n";
    else if(a1 > b1 && a2 <= b2 && a1 > b2 && a2 <= b1) cout<<2<<"\n";
    else if(a1 <= b1 && a2 > b2 && a1 > b2 && a2 <= b1) cout<<2<<"\n";
    else if(a1 <= b1 && a2 > b2 && a1 <= b2 && a2 > b1) cout<<2<<"\n";
    else if(a1 > b1 && a2 <= b2 && a1 > b2 && a2 > b1) cout<<2<<"\n";
    else if(a1 > b1 && a2 <= b2 && a1 <= b2 && a2 > b1) cout<<2<<"\n";
    else if(a1 <= b1 && a2 > b2 && a1 > b2 && a2 > b1) cout<<2<<"\n";
    
    
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