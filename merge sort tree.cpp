    // Returns the number of elements less than or equal to a particular number
    // in an unsorted array in a given range for multiple queries
    // in n*log n for building and log n for answerig each query
    #define all(v) v.begin(),v.end()
    const int N=1e5; 
    vector<int> tree[4*N];
    int n,m,arr[100005];
    void build(int node,int l,int r)
    {
         if(l==r)
         {
           tree[node].push_back(arr[l]);
           return;
         }
         int mid=l+(r-l)/2;
         build(2*node,l,mid);
         build(2*node+1,mid+1,r);
         merge(all (tree[2*node]),all (tree[2*node+1]),back_inserter(tree[node]));
    }
    int query(int node,int start,int end,int l,int r,int val)
    {
        if(start>r||end<l)
         return 0;
        if(l<=start&&end<=r)
          return lower_bound(all(tree[node]),val)-tree[node].begin();
        ll mid=start+(end-start)/2;
        return query(2*node,start,mid,l,r,val)+query(2*node+1,mid+1,end,l,r,val);
    }