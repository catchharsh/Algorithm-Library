
int distance[100005]; //size of array
bool processed[100005];
void dijkstra(int x)
{
   memset(processed,false,sizeof processed);
   for (int i = 1; i <= n; i++)
      distance[i] = INF;
     distance[x] = 0;
     priority_queue<pair<int,int> >q; 
     q.push({0,x});
      while (!q.empty()) 
      {
        int a = q.top().second;
        q.pop();
        if (processed[a]) 
        	continue;
        processed[a] = true;
        for (auto u : adj[a]) 
        {
           int b = u.first, w = u.second;
           if (distance[a]+w < distance[b]) 
           {
              distance[b] = distance[a]+w;
              q.push({-distance[b],b});
           }
        }
       }
}