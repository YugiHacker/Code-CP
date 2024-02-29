/*
	www.youtube.com/YugiHackerChannel
	oj.vnoi.info/user/YugiHackerKhongCopCode
*/
#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn 1003
using namespace std;

const int MOD = 1e8 + 7;
int n, m, d[maxn][maxn];
char a[maxn][maxn];
long long f[maxn][maxn];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("ant.inp", "r", stdin);
    freopen("ant.out", "w", stdout);

    cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            cin >> a[i][j];
            d[i][j] = 1e9;
        }

    queue <pair<int, int>> q;
    d[1][1] = 0;
    f[1][1] = 1;
    q.push({1, 1});

    while (q.size())
    {
        int u = q.front().first, v = q.front().second;
        q.pop();
        for (int i=0; i<4; i++)
        {
            int nu = u + dx[i];
            int nv = v + dy[i];
            if (0 < nu && nu <= n && 0 < nv && nv <= m && a[nu][nv] == '1')
            {
                if (d[nu][nv] > d[u][v] + 1)
                {
                    d[nu][nv] = d[u][v] + 1;
                    f[nu][nv] = f[u][v];
                    q.push({nu, nv});
                }
                else if (d[nu][nv] == d[u][v] + 1)
                {
                    (f[nu][nv] += f[u][v]) %= MOD;
                }
            }
        }
    }
    cout << f[n][m] << '\n' << d[n][m];
}
