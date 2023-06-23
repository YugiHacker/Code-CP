/*
	www.youtube.com/YugiHackerChannel
	oj.vnoi.info/user/YugiHackerKhongCopCode
*/
#include<bits/stdc++.h>
using namespace std;

#define el cout<<"\n"
#define	f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn 100005
int n, q, a[maxn];
int pos[maxn], cur, cnt[maxn], h[maxn], p[maxn][18];
vector <int> ke[maxn];
long long IT[maxn*4], f[maxn], add[maxn*4];
void push(int id)
{
    add[id*2] += add[id];
    IT[id*2] += add[id];
    add[id*2+1] += add[id];
    IT[id*2+1] += add[id];
    add[id] = 0;
}
void up(int id, int l, int r, int u, int v, int val)
{
    if (u > r || v < l) return;
    if (u <= l && r <= v)
    {
        IT[id] += val;
        add[id] += val;
        return;
    }
    if (add[id]) push(id);
    int m = (l+r)/2;
    up(id*2, l, m, u, v, val);
    up(id*2+1, m+1, r, u, v, val);
    IT[id] = IT[id*2] + IT[id*2+1];
}
long long get(int id, int l, int r, int p)
{
    if (p < l || p > r) return 0;
    if (l == r) return IT[id];
    if (add[id]) push(id);
    int m = (l+r)/2;
    long long T1 = get(id*2, l, m, p);
    long long T2 = get(id*2+1, m+1, r, p);
    return T1 + T2;
}
void dfs(int u)
{
    pos[u] = ++cur;
    cnt[u] = 1;
    for (int i=0; i<ke[u].size(); i++)
    {
        int v = ke[u][i];
        if (v!=p[u][0])
        {
            h[v] = h[u] + 1;
            p[v][0] = u;
            for (int j=1; j<=17; j++) p[v][j] = p[p[v][j-1]][j-1];
            dfs(v);
            cnt[u] += cnt[v];
        }
    }
}
int lca(int u, int v)
{
    if (h[u]<h[v]) swap(u,v);
    int delta=h[u]-h[v];
    for(int i = 17; i >= 0; i--)
        if ((delta >> i) & 1) u = p[u][i];
    if (u == v) return u;

    for (int i = 17; i >= 0; i--)
        if (p[u][i] != p[v][i])
        {
            u = p[u][i];
            v = p[v][i];
        }
    return p[u][0];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    f1 (i, n) cin >> a[i], a[i] = abs(a[i]);
    f1 (i, n-1)
    {
        int u, v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    h[1] = 1;
    dfs(1);
    f1 (i, n) up(1, 1, n, pos[i], pos[i] + cnt[i] - 1, a[i]);
    while (q--)
    {
        int tt, u, v;
        cin >> tt >> u >> v;
        if (tt==1)
        {
            v = abs(v);
            up(1, 1, n, pos[u], pos[u] + cnt[u] - 1, v-a[u]);
            a[u] = v;
        }
        else
        {
            long long val_u = get(1, 1, n, pos[u]);
            long long val_v = get(1, 1, n, pos[v]);
            int p = lca(u, v);
            long long val_p = get(1, 1, n, pos[p]);
            long long ans = val_u + val_v - 2*val_p + a[p];
            cout << ans*2 - a[u] - a[v]; el;
        }
    }
    return 0;
}
