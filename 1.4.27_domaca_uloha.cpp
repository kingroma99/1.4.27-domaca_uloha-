#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *najdi_najdlhsi_monotonny_usek(int*p,int lp,int *ip){
	int i,j;
	int a=0;
	int *z;
	int *A[*ip];
	int pocet=1;
	int rastuci_usek=0;
	int klesajuci_usek=0;
	int najvacsi_usek;
	int usek=0;

	for(i=0;i<*ip;i++)
    	A[i]=(p+i);	
	
	for (i=a; i<*ip; i++)
	{
		for (j=a; j<*ip-1;j++)
		{	
		
			if (*A[j]<=*A[j+1])
			{
				pocet=pocet+1;
				a++;
			}
			else
			{
				a++;
				break;
			}
		}
		if (pocet>usek)
		{
		    usek=pocet;
		    pocet=1;
		}
		else pocet=1;

	}
	
    rastuci_usek=usek;
	usek=0;
	a=0;
	
	for (i=a; i<*ip; i++)
	{
		for (j=a; j<*ip-1;j++)
		{   
			
			if (*A[j]>=*A[j+1])
			{
				pocet=pocet+1;
				a++;
			}
			else
			{
				a++;
				break;
			}
		}
		if (pocet>usek)
		{
		    usek=pocet;
		    pocet=1;
		}
		else pocet=1;
	}
	
	klesajuci_usek=usek;
	usek=0;
	
	
	if (rastuci_usek>=klesajuci_usek)
	{
		a=0; 
		  
		for (i=a; i<*ip; i++)
		{
			for (j=a; j<*ip-1;j++)
			{
	    		if (*A[j]<=*A[j+1])
				{
					pocet=pocet+1;
					a++;
				}
				else
				{
					a++;
					
					if (pocet==rastuci_usek)
					p=A[j-rastuci_usek+1];
					break;
				}
			}
			
			pocet=1;
		}
	}	
	else
	{ 	
		a=0;
		
		for (i=a; i<*ip; i++)
		{	
			for (j=a; j<*ip-1;j++)
			{
				if (*A[j]>=*A[j+1])
				{
					pocet=pocet+1;
					a++;
				}
				else
				{
					a++;
					
					if (pocet==klesajuci_usek)
					p=A[j-klesajuci_usek+1];
					break;
				}
			}
			
			pocet=1;
		}
	}
	
	if (rastuci_usek>klesajuci_usek)
		najvacsi_usek=rastuci_usek;
	else
		najvacsi_usek = klesajuci_usek;
	
	*ip=najvacsi_usek;
	
	return p;
}	

int main()
{
	int lp,*ip,*p;
	int *c,d;
	int A[d];
	int i;

	srand(time(0));

	printf("zadaj pocet prvkov: ");
	scanf("%d",&d);
	
	for(i=0;i<d;i++)
	{
		lp=rand()%10+1;
		A[i]=lp;
		printf("%d ",A[i]);
	}
	
	printf("\n");	
	
	p=&A[0];
	ip=&d;
	
	c=najdi_najdlhsi_monotonny_usek(p,lp,ip);
	printf("najvatsi monotonny usek: ");
	
	for (i=0;i<d;i++)
	{
		printf(" %d ",*(c+i));
	}
	
	printf("\n");
	
	printf("Adresa najdlhsieho monotonneho useka: %d\n ",c);
	printf("Dlzka najdlhsieho monotonneho useka: %d",d);
}
