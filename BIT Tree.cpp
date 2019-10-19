    int bit[100005];
    void update(int x,int val,int n)
    {
        for(;x<=n;x=x+(x&(-x)))
            bit[x]+=val;
    }
    int query(int x)
    {
        int sum=0;
        for(;x>0;x=x-(x&(-x)))
            sum+=bit[x];
        return sum;
    }