/*
	www.youtube.com/YugiHackerChannel
	oj.vnoi.info/user/YugiHackerKhongCopCode
*/
#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn 1000006
using namespace std;

int cnt[maxn];

main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("prime.inp", "r", stdin);
    freopen("prime.out", "w", stdout);
    for (int i=2; i<maxn; i++) if (cnt[i] == 0)
        for (int j=i; j<maxn; j+=i)
            cnt[j]++;
    int ans = 0;
    int n; cin >> n;
    for (int i=1; i<=n; i++)
    {
        int x; cin >> x;
        if (cnt[x] > cnt[ans]) ans = x;
    }
    cout << ans;
}
