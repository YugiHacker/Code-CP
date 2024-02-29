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

int n, a[maxn], l[maxn], r[maxn], s[maxn];
int max_len, max_sum;
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("exlist.inp", "r", stdin);
    freopen("exlist.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
        if (l[a[i]] == 0) l[a[i]] = i;
        r[a[i]] = i;
    }
    for (int i=1; i<=1000; i++)
        if (l[i] != 0)
        {
            if (max_len < r[i] - l[i] + 1)
            {
                max_len = r[i] - l[i] + 1;
                max_sum = s[r[i]] - s[l[i]-1];
            }
            else if (max_len == r[i] - l[i] + 1)
            {
                if (max_sum < s[r[i]] - s[l[i]-1])
                {
                    max_sum = s[r[i]] - s[l[i]-1];
                }
            }
        }
    cout << max_len << ' ' << max_sum;
}
