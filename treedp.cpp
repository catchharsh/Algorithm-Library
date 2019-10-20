    struct tt
    {
       ll node;
       ll sz;
       ll val;
    };
    vector<ll> v[200005];
    bool visit[200005];
    bool visit1[200005];
    tt tree[200005];
    vector<tt> mtree;
    void dfs(ll no)
    {
       visit[no]=true;
       tree[no].node=no;
       tree[no].sz=1;
       for(auto to:v[no])
       {
         if(!visit[to])
         {
           dfs(to);
           tree[no].sz+=tree[to].sz;
         }
       }
    }
    void dfs1(ll no)
    {
       visit1[no]=true;
       mtree.pb(tree[no]);
       for(auto to:v[no])
       {
          if(!visit1[to])
            dfs1(to);
       }
    }
    int main()
    {   
         IOS;
         ll n,m,i,j,k;
         cin>>n;
         ll va[n+1];
         for(i=1;i<=n;i++) cin>>va[i];
          for(i=0;i<n-1;i++)
          {
            cin>>j>>k;
            v[j].pb(k);
            v[k].pb(j);
          }
          dfs(1);
          for(i=1;i<=n;i++)
          {
            tree[i].val=va[i];
          }
          dfs1(1);
          for(i=0;i<n;i++)
            cout<<mtree[i].node<<" ";cout<<endl;
          for(i=0;i<n;i++)
            cout<<mtree[i].sz<<" ";cout<<endl;
          for(i=0;i<n;i++)
            cout<<mtree[i].val<<" ";cout<<endl;;

         cerr <<endl<< "Time elapsed : " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';             
    }