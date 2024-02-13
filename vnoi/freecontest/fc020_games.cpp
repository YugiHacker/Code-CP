/*
	www.youtube.com/YugiHackerChannel
	oj.vnoi.info/user/YugiHackerKhongCopCode
*/
#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn 200005
using namespace std;
int n, k, l[maxn], r[maxn], b[maxn], d[maxn], c[maxn];
vector <int> a[maxn], v;
bool dfs(int u, int cur, int color)
{
    if (d[u] == cur) return c[u] == color;
    d[u] = cur;
    c[u] = color;
    for (int id:a[u]) if (id <= cur)
    {
        int v = l[id] ^ r[id] ^ u;
        if (!dfs(v, cur, color ^ b[id])) return 0;
    }
    return 1;
}
bool check(int x)
{
    f1 (i, n)
        if (d[i] != x && dfs(i, x, 0) == 0) return 0;
    return 1;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    if (k == 0) return cout << 0, 0;
    f1 (i, k)
    {
        string s;
        cin >> l[i] >> r[i] >> s;
        b[i] = s[0] == 'o';
        v.push_back(--l[i]);
        v.push_back(r[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()));
    n = v.size();
    f1 (i, k)
    {
        l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin() + 1;
        r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin() + 1;
        a[l[i]].push_back(i);
        a[r[i]].push_back(i);
    }
    int l = 1, r = k+1;
    while (r - l > 1)
    {
        int m = (l+r)/2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l;
}
