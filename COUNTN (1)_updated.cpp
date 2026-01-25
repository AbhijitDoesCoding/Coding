#include <bits/stdc++.h>
using namespace std;

#define ll long long

using vi = vector<ll>;

const int MAX_LIMIT = 1e6 + 2;

vector<ll> primes;
vector<ll> smallestPrimeFactor(MAX_LIMIT, 0);

void calculateSPF()
{
    smallestPrimeFactor[1] = 1;
    for (int i = 2; i < MAX_LIMIT; i++)
    {
        if (smallestPrimeFactor[i] == 0)
        {
            smallestPrimeFactor[i] = i;
            for (int j = i * i; j < MAX_LIMIT; j += i)
                if (smallestPrimeFactor[j] == 0)
                    smallestPrimeFactor[j] = i;
        }
    }
}

void process()
{
    int k;
    cin >> k;
    ll result = 0;
    if (smallestPrimeFactor[k] == k)
        for (int i = 0; i < primes.size() && primes[i] <= k; i++)
            result += primes[i] * k;
    else
        for (int i = 0; i < primes.size() && primes[i] <= smallestPrimeFactor[k]; i++)
            result += primes[i] * k;
    cout << result << '\n';
}

signed main()
{
    calculateSPF();
    for (int i = 2; i < MAX_LIMIT; i++)
        if (smallestPrimeFactor[i] == i)
            primes.push_back(i);

    int t;
    cin >> t;
    while (t--)
        process();
    return 0;
}
