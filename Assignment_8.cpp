#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dd;

typedef vector<ll> vi;
typedef vector<dd> vd;

template <class generic>
void bbl(generic &arr, ll n) {
    for (ll i = 0; i < n-1; i++)
        for (ll j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

int main(){
    // cout<<"Enter the number of elements in the array: ";
    ll n;
    cin>>n;
    vi arr(n);
    vd arr1(n);
    // cout<<"Enter the type of elements in the array: 1. Integer 2. Float\n";
    ll choice;
    cin>>choice;
    // cout<<"Enter the elements of the array: ";
    if(choice==1){
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        bbl(arr,n);
        // cout<<"The sorted array is: ";
        for(ll i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }
    else{
        for(ll i=0;i<n;i++){
            cin>>arr1[i];
        }
        bbl(arr1,n);
        // cout<<"The sorted array is: ";
        for(ll i=0;i<n;i++){
            cout<<arr1[i]<<" ";
        }
    }
    return 0;
}
