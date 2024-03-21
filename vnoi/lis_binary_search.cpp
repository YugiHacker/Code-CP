/*
	www.youtube.com/YugiHackerChannel
	oj.vnoi.info/user/YugiHackerKhongCopCode
*/
#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn 100005
#define MOD 1000000007
using namespace std;
int n, a[maxn], b[maxn], ma;
int cnp (int x)
{
    int ans = 0;
    int l = 1, r = ma;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (b[mid] < x)
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++)
    {
        int j = cnp(a[i]);
        b[j+1] = a[i];
        ma = max(ma, j+1);
    }
    cout << ma;
}
