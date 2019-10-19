int ar[100005];
int tree[500005];

void build(int node,int start,int end)
{
    if(start==end)
    {
        tree[node]=ar[start];
        return;
    }
   else
   {
     int mid=(start+end)/2;
     build(2*node,start,mid);
     build(2*node+1,mid+1,end);

     tree[node]=min(tree[2*node],tree[2*node+1]);

   }
}
void update(int idx,int value,int start,int end,int node)
{
    int mid=(start+end)/2;

    if(start==end)
    {
        ar[start]=value;
        tree[node]=value;
    }
    else
    {
        if(idx>=start&&idx<=mid)
        {
              update(idx,value,start,mid,2*node);
        }
       else 
       {
             update(idx,value,mid+1,end,2*node+1);
       }
        
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}

int query(int l,int r,int start,int end,int node)
{
    if(end<l||start>r)   //checking whether range is out of L and R
       {
            return 1000000;
       }
    else if(l<=start&&end<=r)   // if the range is completely under L and R
        {
            return tree[node];
        }
    else                // if there is partial overlap between range and L and R
       {
           int mid=(start+end)/2;
           int p1=query(l,r,start,mid,2*node);      // Checking for answer in left part
           int p2=query(l,r,mid+1,end,2*node+1);    // Checking for answer in right part
           return min(p1,p2);
       }
}
int main()
{   
    IOS;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>ar[i];
    build(1,0,n-1);

    int q;
    cin>>q;
    char c;
    for(int i=0;i<q;i++)
    {
        cin>>c;
        if(c=='q')
        {
            int l,r;
            cin>>l>>r;
            cout<<query(l,r,0,n-1,1)<<endl;
        }
        else
        { 
            int idx,value;
            cin>>idx>>value;
            update(idx,value,0,n-1,1);
        }
    } 
}
