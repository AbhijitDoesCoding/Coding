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

struct Game2048{
    int board[4][4];
    
    void swipe_right(int arr[]){

    }

    bool has_game_ended(){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(board[i][j] == 0) return false;
            }
        }
        return true;
    }

    void randomPopulate(){
        while(1){
            int i = rand()%4;
            int j = rand()%4;
            if(board[i][j] == 0){
                int ch = rand()%2;
                if(ch == 0) board[i][j] = 2;
                else board[i][j] = 4;
                return;
            }
        }
    }

    void init(){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                board[i][j] = 0;
            }
        }
        randomPopulate();
        randomPopulate();
    }
    bool up(){
        for(int i = 0; i < 4; i++){
            int arr[4];
            for(int j = 0; j < 4; j++){
                arr[j] = board[j][i];
            }
            swipe_right(arr);
            for(int j = 0; j < 4; j++){
                board[j][i] = arr[j];
            }
        }
        if(has_game_ended()){
            return false;
        }
        randomPopulate();
        return true;
    }
    void down(){
        for(int i = 0; i < 4; i++){
            int arr[4];
            for(int j = 0; j < 4; j++){
                arr[j] = board[j][i];
            }
            swipe_right(arr);
            for(int j = 0; j < 4; j++){
                board[j][i] = arr[j];
            }
        }
        if(has_game_ended()){
            return false;
        }
        randomPopulate();
        return true;
    }
    void left(){
        for(int i = 0; i < 4; i++){
            int arr[4];
            for(int j = 0; j < 4; j++){
                arr[j] = board[j][i];
            }
            swipe_right(arr);
            for(int j = 0; j < 4; j++){
                board[j][i] = arr[j];
            }
        }
        if(has_game_ended()){
            return false;
        }
        randomPopulate();
        return true;
    }
    void right(){
        for(int i = 0; i < 4; i++){
            int arr[4];
            for(int j = 0; j < 4; j++){
                arr[j] = board[j][i];
            }
            swipe_right(arr);
            for(int j = 0; j < 4; j++){
                board[j][i] = arr[j];
            }
        }
        if(has_game_ended()){
            return false;
        }
        randomPopulate();
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    Game2048 game;
    game.init();
}