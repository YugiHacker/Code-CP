/*
	www.youtube.com/YugiHackerChannel
	oj.vnoi.info/user/YugiHackerKhongCopCode
*/
#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn 300005
#define MOD 1000000009
using namespace std;
int n, q, a[maxn];
long long fib[maxn];
long long t[maxn * 4], lz[2][maxn * 4];
void build(int id, int l, int r)
{
    if (l == r) return void(t[id] = a[l]);
    int m = l+r>>1;
    build(id*2, l, m);
    build(id*2+1, m+1, r);
    t[id] = (t[id*2] + t[id*2+1]) % MOD;
}
/*
    f[1] + f[2] + ... + f[i] = f[i+2] - 1;
    f[l] + ... + f[r] = f[r+2] - f[l+1]
    Range |L - R| = n
    g[l] -> g[r] : a, b, a+b, a+2b, ...
    coef[] : 1 0, 0 1, 1 1, 1 2, ...
    f[] : 1 0, f[0] f[1], f[1] f[2], ..., f[n-2] f[n-1]
    g[i] = a * f[i-2] + b * f[i-1];
    t[id] = g[l] + ... + g[r] = (1 + f[1] + ... + f[n-2]) * a + (f[1] + ... + f[n-1) * b
    t[id] = a * f[n] + b * (f[n+1] - 1)

*/
void add(int id, int l, int r, int A, int B)
{
    t[id] = (t[id] + A * fib[r-l+1] + B * (fib[r-l+2] - 1)) % MOD;
    lz[0][id] = (lz[0][id] + A) % MOD;
    lz[1][id] = (lz[1][id] + B) % MOD;
}
void push(int id, int l, int r)
{
    int m = l+r>>1;
    add(id*2, l, m, lz[0][id], lz[1][id]);
    add(id*2+1, m+1, r, (lz[0][id] * fib[m-l] + lz[1][id] * fib[m-l+1]) % MOD,
        (lz[0][id] * fib[m-l+1] + lz[1][id] * fib[m-l+2])%MOD);
    lz[0][id] = lz[1][id] = 0;
}
void up(int id, int l, int r, int u, int v)
{
    if (v < l || r < u) return;
    if (u <= l && r <= v)
    {
        add(id, l, r, fib[l-u+1], fib[l-u+2]);
        return;
    }
    int m = l+r>>1;
    push(id, l, r);
    up(id*2, l, m, u, v);
    up(id*2+1, m+1, r, u, v);
    t[id] = (t[id*2] + t[id*2+1]) % MOD;
}
long long get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return t[id];
    int m = l+r>>1;
    push(id, l, r);
    int t1 = get(id*2, l, m, u, v);
    int t2 = get(id*2+1, m+1, r, u, v);
    return (t1 + t2) % MOD;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    f1 (i, n) cin >> a[i];
    build(1, 1, n);
    fib[1] = 1;
    for (int i=2; i<=n+3; i++) fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    while(q--)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) up(1, 1, n, l, r);
        else cout << get(1, 1, n, l, r), el;
    }
}
