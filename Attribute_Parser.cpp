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


void solve(){
    int n, q;
    cin >> n >> q;
    cin.ignore();

    vector<string> hrml;
    vector<string> quer;

    for (int i = 0; i < n; i++) {
        string temp;
        getline(cin, temp);
        hrml.push_back(temp);
    }

    for (int i = 0; i < q; i++) {
        string temp;
        getline(cin, temp);
        quer.push_back(temp);
    }

    map<string, string> m;
    vector<string> tag;

    for (int i = 0; i < n; i++) {
        string temp = hrml[i];
        temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '>'), temp.end());

        if (temp.substr(0, 2) == "</") {
            tag.pop_back();
        } else {
            stringstream ss;
            ss.str("");
            ss << temp;
            string t1, p1, v1;
            char ch;
            ss >> ch >> t1 >> p1 >> ch >> v1;

            string temp1 = "";
            if (tag.size() > 0) {
                temp1 = *tag.rbegin();
                temp1 = temp1 + "." + t1;
            } else {
                temp1 = t1;
            }

            tag.push_back(temp1);
            m[*tag.rbegin() + "~" + p1] = v1;

            while (ss) {
                ss >> p1 >> ch >> v1;
                m[*tag.rbegin() + "~" + p1] = v1;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        if (m.find(quer[i]) == m.end()) {
            cout << "Not Found!\n";
        } else {
            cout << m[quer[i]] << endl;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}