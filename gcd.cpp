// Based On Euclid's Theorem gcd(a,b)=gcd(b,a%b)
int gcd(int a,int b)
{
	 if(b==0)
	 	return a;
	 else
	 	return gcd(b,a%b);
}