#include <bits/stdc++.h>
using namespace std ;

#define inf 10000000
vector<vector<int> > adj ;
vector<bool> visit ;

void dfs(int node)
  {
     visit[node]=true;
     for(auto to:adj[node])
     {
        if(visit[to]==false)
          dfs(to);
     }
  }

int main()
  {
    int n, m, u, v ;
    cin >> n >> m ;
    adj.resize(n+1) ;
    visit.assign(n+1, false) ;
    for (int i = 0; i < m; i++)
      {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
      }
      cin>>u;
     dfs(u-1);
     for(int i=0;i<=n;i++)
     {
       if(visit[i]==1)
       {
         cout << i+1 << " is reachable from "<<u<<endl;
       }
     }
  }
