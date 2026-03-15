#include<bits/stdc++.h>
using namespace std; typedef long long ll;

#define nline cout<<"\n";
#define yes cout<<"Yes\n";
#define no cout<<"No\n";
#define loop(i,l,h) for(int i=l;i<h;i++)

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

char grid[5][5];
string s, c;
ll n;
bool found=false;

bool check(){

    loop(i,0,n){
        ll a=0,b=0,cc=0;
        char first='.';
        loop(j,0,n){
            if(grid[i][j]=='A') a++;
            if(grid[i][j]=='B') b++;
            if(grid[i][j]=='C') cc++;
            if(grid[i][j]!='.' && first=='.') first=grid[i][j];
        }
        if(a!=1||b!=1||cc!=1) return false;
        if(first!=s[i]) return false;
    }

    loop(i,0,n){
        ll a=0,b=0,cc=0;
        char first='.';
        loop(j,0,n){
            if(grid[j][i]=='A') a++;
            if(grid[j][i]=='B') b++;
            if(grid[j][i]=='C') cc++;
            if(grid[j][i]!='.' && first=='.') first=grid[j][i];
        }
        if(a!=1||b!=1||cc!=1) return false;
        if(first!=c[i]) return false;
    }

    return true;
}

bool check1(ll row,ll col,char ch){

    ll a=0,b=0,cc=0;

    if(ch=='A') a++;
    if(ch=='B') b++;
    if(ch=='C') cc++;

    loop(i,0,n){
        if(grid[row][i]=='A') a++;
        if(grid[row][i]=='B') b++;
        if(grid[row][i]=='C') cc++;
    }

    if(a>1||b>1||cc>1) return false;

    a=b=cc=0;

    if(ch=='A') a++;
    if(ch=='B') b++;
    if(ch=='C') cc++;

    loop(i,0,n){
        if(grid[i][col]=='A') a++;
        if(grid[i][col]=='B') b++;
        if(grid[i][col]=='C') cc++;
    }

    if(a>1||b>1||cc>1) return false;

    // early leftmost row constraint
    if(ch!='.'){
        bool has=false;
        loop(i,0,col)
            if(grid[row][i]!='.') has=true;

        if(!has && ch!=s[row]) return false;
    }

    // early topmost column constraint
    if(ch!='.'){
        bool has=false;
        loop(i,0,row)
            if(grid[i][col]!='.') has=true;

        if(!has && ch!=c[col]) return false;
    }

    return true;
}

void rec(ll row,ll col){

    if(found) return;

    if(col==n){
        rec(row+1,0);
        return;
    }

    if(row==n){
        if(check()){
            found=true;
            yes
            loop(i,0,n){
                loop(j,0,n) cout<<grid[i][j];
                nline;
            }
        }
        return;
    }

    // count letters in row
    ll letters=0;
    loop(i,0,n)
        if(grid[row][i]!='.') letters++;

    ll remaining=n-col;

    // if already 3 letters → rest must be empty
    if(letters==3){
        grid[row][col]='.';
        rec(row,col+1);
        return;
    }

    if(check1(row,col,'A')){
        grid[row][col]='A';
        rec(row,col+1);
        grid[row][col]='.';
    }

    if(check1(row,col,'B')){
        grid[row][col]='B';
        rec(row,col+1);
        grid[row][col]='.';
    }

    if(check1(row,col,'C')){
        grid[row][col]='C';
        rec(row,col+1);
        grid[row][col]='.';
    }

    // try empty
    if(remaining>3-letters){
        grid[row][col]='.';
        rec(row,col+1);
    }
}

void solve(){

    cin>>n;
    cin>>s>>c;

    loop(i,0,5)
        loop(j,0,5)
            grid[i][j]='.';

    rec(0,0);

    if(!found) no
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
