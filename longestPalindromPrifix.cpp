#include <bits/stdc++.h>
using namespace std;

vector<int> LPS(string str)
{
    string rev = str;
    reverse(rev.begin(), rev.end());
    str = str + '?' + rev;
    int M = str.length();
    vector<int> lps(M);
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i] = 0, i++;
        }
    }
    return lps;
}

signed main()
{
    string s;
    cin >> s;
    vector<int> ans = LPS(s);
    for (int i : ans)
        cout << i << ' ';
    return 0;
}