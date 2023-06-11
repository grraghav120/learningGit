#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> arr(k, vector<int>(n));

    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    set<vector<int>> pq;

    for (int i = 0; i < k; i++)
        pq.insert({arr[i][0], i, 0});

    int tmax = (*pq.rbegin())[0], tmin = (*pq.begin())[0];

    int max_ans = tmax, min_ans = tmin;

    while (1)
    {
        if (max_ans - min_ans > tmax - tmin)
        {
            max_ans = tmax;
            min_ans = tmin;
        }

        vector<int> top = *pq.begin();

        pq.erase(pq.begin());

        if (top[2] + 1 < n)
            pq.insert({arr[top[1]][top[2] + 1], top[1], top[2] + 1});
        else
            break;

        tmax = (*pq.rbegin())[0];
        tmin = (*pq.begin())[0];
    }
    cout << min_ans << ' ' << max_ans;
    return 0;
}