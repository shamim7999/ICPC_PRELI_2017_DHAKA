#include<bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 50000
#define mod 1000000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld e, ld b){ return log(e)/log(b); }

///////////////////////////////////////////////////////////////////

vector < pair<int, pair<int,int> > > graph;
vector < pair<int,int> > g[mx];
int parent[mx], sz[mx], st = 0;
int n;

int Findparent(int aa)
{
    if(parent[aa] == aa)
        return aa;
    return parent[aa] = Findparent(parent[aa]);
}

void kruskal(int tar)
{
    //cout<<0;
    
    for(int i=st;i<graph.size();i++)
    {
      int u=graph[i].second.first;
      int v=graph[i].second.second;
      int w=graph[i].first;

      st = i;

      if(w < tar){
         //st = i;
         return;
      }

      int xx = Findparent(u);
      int yy = Findparent(v);

      if(xx!=yy){
        g[u].pb({v,w});
        g[v].pb({u,w});
       
        if(sz[xx]<sz[yy])
        swap(xx, yy);
        parent[yy] = xx;
        sz[xx]+=sz[yy];


      }
    }
}

void ini()
{
    for(int i=1; i<=n; i++) parent[i]=i, sz[i] = 1, g[i].clear();
    graph.clear();
    st = 0;
}

void solve(int kk)
{
    
    int edge;
    cin >> n >> edge;
    ini();
    for(int i=0,n1,n2,w; i<edge; i++) cin >> n1 >> n2 >> w, graph.pb({w,{n1,n2}});
    
    
    int q;
    cin >> q;
    vector < pair < int, int > > vv, Ans;

    for(int i=0; i<q; i++){
        int cc;
        cin >> cc;
        vv.push_back({cc, i});
    }

    sort(vv.rbegin(), vv.rend());
    sort(graph.rbegin(),graph.rend());

    for(auto it : vv){
    
        int tar = it.first, id = it.second;
        kruskal(tar);
        int Root = Findparent(1);
        int tot_nodes = sz[Root];
        Ans.push_back({id, tot_nodes});
    
    }

    sort(Ans.begin(), Ans.end());
    
    cout << "Case " << kk << ":\n";
    
    for(auto it : Ans)
        cout << it.second-1 << "\n";
}


int main()
{
   fast;
   int t=1;
   cin >> t;
   for(int i=1; i<=t; i++)
        solve(i);

   return 0;
}
