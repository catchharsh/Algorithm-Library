#include <bits/stdc++.h>
using namespace std ;

#define inf 10000000
vector<vector<int> > adj ;
vector<int> dist ;

void bfs(int start)
  {
    queue<int> discovered ;
    int t ;
    dist[start]=0 ;
    discovered.push(start) ;
    while(!discovered.empty())
      {
        t=discovered.front() ;
        discovered.pop() ;
        for(int i=0 ; i<adj[t].size() ; i++)
          if(dist[adj[t][i]]==inf)
            {
                dist[adj[t][i]]=dist[t]+1 ;
                discovered.push(adj[t][i]) ;
            }
      }
  }

int main()
  {
    int n, m, u, v ;
    cin >> n >> m ;
    adj.resize(n+1) ;
    dist.assign(n+1, inf) ;
    for (int i = 0; i < m; i++)
      {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
      }
    cin>> u >> v ;
    bfs(u-1) ;
    if(dist[v-1]==inf) cout<< -1 ;
    else cout<< dist[v-1] ;
    return 0 ;
  }