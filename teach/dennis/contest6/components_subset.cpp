/*
	www.youtube.com/YugiHackerChannel
	oj.vnoi.info/user/YugiHackerKhongCopCode
*/
#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn 5003
#define MOD 998244353
using namespace std;
int n;
vector <int> a[maxn];
long long f[2][maxn][maxn];
int sz[maxn];
void dfs(int u, int p=-1)
{
    f[0][u][0] = f[1][u][1] = 1;
    sz[u] = 1;
    for (int v:a[u]) if (v != p)
    {
        dfs(v, u);
        for (int i=sz[u]; ~i; i--)
        {
            long long cur[2] = {f[0][u][i], f[1][u][i]};
            f[0][u][i] = f[1][u][i] = 0;
            for (int j=0; j<=sz[v]; j++)
            {
                (f[0][u][i+j] += cur[0] * (f[0][v][j] + f[1][v][j]) % MOD) %= MOD;
                (f[1][u][i+j] += cur[1] * f[0][v][j] % MOD) %= MOD;
                if (j >= 1) (f[1][u][i+j-1] += cur[1] * f[1][v][j] % MOD) %= MOD;
            }
        }
        sz[u] += sz[v];
    }
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    f1 (i, n-1)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);
    f1 (i, n) cout << (f[0][1][i] + f[1][1][i]) % MOD, el;
}
