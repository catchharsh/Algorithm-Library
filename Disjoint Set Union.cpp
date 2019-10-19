    #define N 1e5+5
    int ar[N];
    int size[N];
    void initialize(int n)
    {
        for(int i=0;i<=n;i++)
          {ar[i]=i;size[i]=1;}
    }
    int root(int i)
    {
       while(i!=ar[i])
       {
         ar[i]=ar[ar[i]];
         i=ar[i];
       }
       return i;
    }
    void uni(int a,int b)
    {
       int root_a=root(a);
       int root_b=root(b);
       if(root_a==root_b)
        return;
       if(size[root_a]<size[root_b])
       {
          ar[root_a]=ar[root_b];
          size[root_b]+=size[root_a];
       }
       else
       {
         ar[root_b]=ar[root_a];
         size[root_a]+=size[root_b];
       }
    }
