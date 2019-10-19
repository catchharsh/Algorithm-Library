int expo(int base,int  exponent,int mod)
{
    int ans=1;
    base%=mod;
    exponent%=(mod-1);
    while(exponent!=0)
    {
        if(exponent&1)
          ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}