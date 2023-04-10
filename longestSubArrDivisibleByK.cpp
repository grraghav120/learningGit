#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k; cin>>n>>k;
    int a[n]; for (int i=0;i<n;i++)cin>>a[i];
    a[0]%=k;
    for (int i=1;i<n;i++)
        a[i]=((a[i]%k+a[i-1])%k+k)%k;
    unordered_map<int,int> m;
    for (int i=0;i<n;i++)m[a[i]]=1e9;
    m[0]=-1;
    int ans=0;
    for (int i=0;i<n;i++){
        ans=max(i-m[a[i]],ans);
        m[a[i]]=min(m[a[i]],i);
    }
    if (ans>n)cout<<-1<<'\n';
    else cout<<ans<<'\n';
    return 0;
}