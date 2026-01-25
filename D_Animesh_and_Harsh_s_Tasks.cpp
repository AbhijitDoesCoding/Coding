#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Task
{
    ll sA, sH, vA, vH;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll p0;
    cin >> n >> p0;

    vector<Task> tasks(n);
    for (int i = 0; i < n; i++)
        cin >> tasks[i].sA;
    for (int i = 0; i < n; i++)
        cin >> tasks[i].sH;
    for (int i = 0; i < n; i++)
        cin >> tasks[i].vA;
    for (int i = 0; i < n; i++)
        cin >> tasks[i].vH;

    // Greedy sorting: tasks with high potential profit should go first
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j)
         {
    ll si = max(tasks[i].sA, tasks[i].sH);
    ll sj = max(tasks[j].sA, tasks[j].sH);
    if (si != sj) return si > sj;
    return max(tasks[i].vA, tasks[i].vH) > max(tasks[j].vA, tasks[j].vH); });

    ll skillA = p0, skillH = p0, totalProfit = 0;
    for (int idx : order)
    {
        ll profitA = skillA * tasks[idx].vA;
        ll profitH = skillH * tasks[idx].vH;
        if (profitA >= profitH)
        {
            totalProfit += profitA;
            skillA += tasks[idx].sA;
        }
        else
        {
            totalProfit += profitH;
            skillH += tasks[idx].sH;
        }
    }

    cout << totalProfit << "\n";
    return 0;
}
