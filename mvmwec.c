#include<stdio.h>

int eql(int[],int,int);
int pegarEsquerda(int);
int pegarDireita(int);
int altura(int[],int,int);

int main()
{
    
	int a[100],t,n,i,res,k;
	
	scanf("%d",&t);
	for(i=0;i<100;i++)
	{
		a[i]=-1;
	}
	while(t>0)
	{
		k=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		res=eql(a,n,k);
		if(res==0)
		printf("F\n");
		else
		printf("T\n");
		t--;
	}
	return 0;
}

int eql(int a[100],int n,int k)
{

	int i,j,k1;
	
	if (k>=100)
      return 1;
      
	if(a[k]==-1)
	return 1;
	
	k1=k;
	i=altura(a,n,pegarEsquerda(k));
	k=k1;
	j=altura(a,n,pegarDireita(k));
	
	if( ( (i-j)==1||(i-j)==-1||(i-j)==0) && eql(a,n,pegarEsquerda(k)) && eql(a,n,pegarDireita(k)) )
	{
		return 1;
	}
	
	return 0;
	
}

int pegarEsquerda(int pos)
{
	return ((2*pos)+1);
}
	
int pegarDireita(int pos)
{
	return ((2*pos)+2);
}

int altura(int a[100],int n,int k)
{
	int esquerda,direita;
	
	if(k>=n)
      return 0;
      
	if(a[k]==-1)
	{
		return 0;
	}
	
	else
	{
		esquerda=altura(a,n,pegarEsquerda(k));
		direita=altura(a,n,pegarDireita(k));
		
		if(esquerda>direita)
		return esquerda+1;
		
		else
		return direita+1;
	}
		
}