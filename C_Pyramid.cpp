#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    vector<int> x(N), y(N), h(N);

    for(int i=0;i<N;i++){
        cin >> x[i] >> y[i] >> h[i];
    }

    for(int cx=0; cx<=100; cx++){
        for(int cy=0; cy<=100; cy++){

            ll H = -1;

            for(int i=0;i<N;i++){
                if(h[i] > 0){
                    H = h[i] + abs(x[i]-cx) + abs(y[i]-cy);
                    break;
                }
            }

            bool ok = true;

            for(int i=0;i<N;i++){
                ll expected = max(H - abs(x[i]-cx) - abs(y[i]-cy), 0LL);
                if(expected != h[i]){
                    ok = false;
                    break;
                }
            }

            if(ok){
                cout << cx << " " << cy << " " << H << "\n";
                return 0;
            }
        }
    }
}