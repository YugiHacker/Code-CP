/*
    www.youtube.com/YugiHackerChannel
    oj.vnoi.info/user/YugiHackerKhongCopCode
*/
#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn 10004
#define maxm 20004
#define maxmask (1<<15)
#define bit(mask,i) ((mask>>i)&1)
#define fi first
#define se second
using namespace std;

int n, m, k, p[maxn];
struct edge{
    int u, v, c;
}e[maxm];
vector <int> a[maxn];
int d[16][maxn];
int cycle[maxmask], f[maxmask][16], dp[maxmask];

void dijkstra(int s, int d[])
{
    priority_queue <pair<int, int>> q;
    f1 (i, n) d[i] = 1e9;
    d[s] = 0;
    q.push({0, s});
    while (q.size())
    {
        int du = -q.top().fi;
        int u = q.top().se;
        q.pop();
        if (du != d[u]) continue;
        for (int id:a[u])
        {
            int v = u ^ e[id].u ^ e[id].v;
            if (d[u] + e[id].c < d[v])
            {
                d[v] = d[u] + e[id].c;
                q.push({-d[v], v});
            }
        }
    }
}

void calcCycle()
{
    memset(cycle, 60, sizeof cycle);
    f0 (start, k)
    {
        memset(f, 60, sizeof f);
        f[1 << start][start] = 0;
        f0 (mask, (1 << k))
        {
            f0 (i, k) if (bit(mask, i))
            {
                f0 (j, k) if (bit(mask, j) && i != j)
                    f[mask][i] = min(f[mask][i], f[mask ^ (1 << i)][j] + d[j][e[p[i]].u]);
            }
            f0 (i, k)
            {
                cycle[mask] = min(cycle[mask], f[mask][i] + d[i][e[p[start]].u]);
            }
        }
    }
}

void calc()
{
    memset(dp, 60, sizeof dp);
    f0 (mask, 1 << k)
    {
        dp[mask] = cycle[mask];
        for (int sub = mask; sub; sub = mask & (sub - 1))
            dp[mask] = min(dp[mask], cycle[sub] + dp[mask ^ sub]);
    }
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    f0 (i, k) cin >> p[i];
    f1 (i, m) cin >> e[i].u >> e[i].v >> e[i].c, a[e[i].u].push_back(i);
    f0 (i, k) dijkstra(e[p[i]].v, d[i]);
    calcCycle();
    calc();
    int ans = dp[(1<<k)-1];
    if (ans >= 1e9) ans = -1;
    cout << ans;
}
