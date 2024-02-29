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

int n, a[maxn];
int ans, max_cnt;

main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("prime.inp", "r", stdin);
    freopen("prime.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];

    for (int i=1; i<=n; i++)
    {
        int cnt = 0;
        int tmp = a[i];
        for (int j=2; j*j <= tmp; j++)
            if (tmp % j == 0)
            {
                cnt++;
                while (tmp % j == 0)
                    tmp /= j;
            }
        if (tmp > 1) cnt++;
        if (cnt > max_cnt)
        {
            ans = a[i];
            max_cnt = cnt;
        }
    }
    cout << ans;
}
