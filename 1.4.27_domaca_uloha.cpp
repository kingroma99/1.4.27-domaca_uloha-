#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *najdi_najdlhsi_monotonny_usek(int*p,int lp,int *ip){
	int i,j,u,v;
	int a=0;
	int pocet=1;
	int rastuci_usek=0;
	int klesajuci_usek=0;
	int najvacsi_usek;
	int usek=0;

	for (i=a; i<lp; i++)
	{
		for (j=a; j<lp-1;j++)
		{	
		
			if (p[j]<=p[j+1])
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
	
	for (i=a; i<lp; i++)
	{
		for (j=a; j<lp-1;j++)
		{   
			
			if (p[j]>=p[j+1])
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
		  
		for (i=a; i<lp; i++)
		{
			for (j=a; j<lp-1;j++)
			{
	    		if (p[j]<=p[j+1])
				{
					pocet=pocet+1;
					a++;
					
					if (pocet==rastuci_usek)
					{
						u=pocet;
						v=j;
					}
				}
				else
				{
					a++;
					break;
				}
			}
			
			pocet=1;
		}
		
		p=(p+v-u+2);
	}	
	else
	{ 	
		a=0;
		
		for (i=a; i<lp; i++)
		{	
			for (j=a; j<lp-1;j++)
			{
				if (p[j]>=p[j+1])
				{
					pocet=pocet+1;
					a++;
					
					if (pocet==klesajuci_usek)
					{
						u=pocet;
						v=j;
					}
				}
				else
				{
					a++;
					break;
				}
			}
			
			pocet=1;
		}
		p=(p+v-u+2);
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
	int aa,*ab,*ac;
	int *c,d;
	int i;

	srand(time(0));

	printf("zadaj pocet prvkov: ");
	scanf("%d",&d);
	
	int A[d];
	
	for(i=0;i<d;i++)
	{
	    aa=rand()%10+1;
		A[i]=aa;
		printf("%d ",A[i]);
	}
	
	printf("\n");	
	
	ac=&A[0];
	aa=d;
	ab=&d;
	c=najdi_najdlhsi_monotonny_usek(ac,aa,ab);
	printf("najvatsi monotonny usek: ");
	
	for (i=0;i<d;i++)
	{	
		printf(" %d ",c[i]);
	}
	
	printf("\n");
	
	printf("Adresa najdlhsieho monotonneho useka: %d\n ",c);
	printf("Dlzka najdlhsieho monotonneho useka: %d",d);
}
