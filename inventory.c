#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main()
{

    int i=0,k,t,j,ra,day=0;      //Variables are initialized
    double rand1;
    double invb,dd,inve,tor,imax,sht,c0,c1,cs,sum=0;
    invb=1.12;
    imax=2;
    dd=0;
    inve=0;
    tor=0;
    sht=0;
    c0=1;
    c1=1;
    cs=19;
    double arr[50][11];

  //Random Numbers Generated to produce the demand Function

	srand(time(NULL));

	 while (i<50)
  {
         ra=2;
         j=2;

    while(ra--)
    {

    arr[i][j] = (double)rand() / (double)RAND_MAX;
    j++;

    }

    rand1= arr[i][2]*arr[i][3];

    dd= (-1)*log(rand1); //demand is generated;


    if(invb>=dd)   //checking if inventory in the beginning more than or equal to demand
    	{
        	inve=invb-dd;
        	sht=0;
        	tor=0;
    	}
    else
    	{
   			 sht=dd-invb;
    		inve=(-1)*sht;
    		tor=imax;

    	}
    if(tor>0)    //costs are calculated on the basis if orders are made or not
    {
        c0=1;
        c1=0;
        cs=(-1)*inve*19;
    }
    else
    {
        c0=0;
        c1=1*inve;
        cs=0;
    }

    // data stored in form of array
    day=i+1;
    arr[i][0]=day;
    arr[i][1]=invb;
    arr[i][4]=dd;
    arr[i][5]=inve;
    arr[i][6]=tor;
	arr[i][7]=c0*tor;
    arr[i][8]=c1;
    arr[i][9]=cs;


	if(invb>=dd)           // Inventory in beginning is set for next day on the basis of order received;
	{
   		 invb=inve;
	}
	else
	{
 		invb=imax;
	}
	i++;

	}


    for(k=0;k<50;k++)		// Output is generated
    {
        for(t=0;t<10;t++)
        {
            printf(" %lf ",arr[k][t]);
        }

    printf("\n");

    }

for(j=0;j<50;j++)
    {
        sum=sum+arr[j][6];
    }
printf("\n\nMean number of papers should he order each day: %lf units \n",sum/50);
}
