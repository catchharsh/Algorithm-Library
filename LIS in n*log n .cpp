    vector<int> v;
    int idx(int n,int k,vector<int> &t)
    {
         int lo=0;
         int hi=n;
         int ans=0;
         int mid=lo+(hi-lo)/2;
         while(lo<=hi)
         {
          mid=lo+(hi-lo)/2;
            if(v[t[mid]]<=k)
              {ans=mid;lo=mid+1;}
            else
              hi=mid-1;
         }
         return ans;
    }
    int main()
    {   
         int n,m,i,j,k;
         cin>>n;
         for(i=0;i<n;i++)
          {
            cin>>j;
            v.push_back(j);
          }
         n=v.size();
        vector<int> t(n,0);
        vector<int> r(n,-1);
        t[0]=0;
        int len=0;
        for(i=1;i<n;i++)
        { 
          if(v[i]<v[t[0]])
          {
            t[0]=i;
          }
          else if(v[i]>v[t[len]])
          {
            t[++len]=i;
            r[t[len]]=t[len-1];
          }
           
          else
          {
                  int id=idx(len,v[i],t);id++;
                  t[id]=i;
                  r[t[id]]=t[id-1];
          }
        }
        cout<<len+1<<endl;
        
    
    }