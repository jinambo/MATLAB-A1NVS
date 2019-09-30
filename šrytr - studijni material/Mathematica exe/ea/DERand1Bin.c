#include "mathlink.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "functions.h"

void DERand1Bin P(( double,double, int, int, int,doublep_nt));

void DERand1Bin( double F,double CR, int NP, int D, int Generations,doublep_nt list )
{
	int i,j,V1,V2,V3;
   double	ckl1;

   createPopulation(D+1, NP+3);
   createTMPPopulation();
	createHistory(Generations);
   createSpecimen(D);

  	k=neval=0;
	for(i=0;i<PD-1;i++)
		for(j=0;j<3;j++)
			{
			setSpecimen(j,i,list[k]);
			k++;
			}

   //initialize population
   randomize();
   for(i=0;i<PNP-3;i++)
   	{
      	for(j=0;j<PD-1;j++)
      		{
         	setPopulation(j, i, getSpecimen(0,j)+(random (1000)/1000.0)*(getSpecimen(1,j)-getSpecimen(0,j)));
         	}
      neval++;
     	CostValue(i);
     	}

   for(l=0;l<Generations;l++)
   	{
	   //evolution
	   for(i=0;i<PNP-3;i++)
	   	{
	      //three random vectors
	   	do {
	   	V1=random (PNP-3);
	   	V2=random (PNP-3);
	   	V3=random (PNP-3);
	   	} while (V1==V2 || V1==V3 || V2==V3 || V1==i || V2==i || V3==i );

	      //from difference vector to trial vector
	      for(j=0;j<PD-1;j++)
	      	{
				if((random (1000)/1000.0)<CR || j==PD-1)
	            setPopulation(j,PNP-3,F*(getPopulation(j,V1)-getPopulation(j,V2))+getPopulation(j,V3));
				else
	            setPopulation(j,PNP-3,getPopulation(j,i));

				//type of variable and boundary checking
		     	if(getSpecimen(0,j)>getPopulation(j,PNP-3) || getSpecimen(1,j)<getPopulation(j,PNP-3))
					setPopulation(j,PNP-3,getSpecimen(0,j)+(random (1000)/1000.0)*(getSpecimen(1,j)-getSpecimen(0,j)));
	         }

	      //best individual into new generation
         neval++;
         CostValue(PNP-3);
	      if(getPopulation(PD-1,i)>getPopulation(PD-1,PNP-3))
      		for(k=0;k<PD;k++)
         		{
            	setTMPPopulation(k,i,getPopulation(k,PNP-3));
	            }
         else
	      	for(k=0;k<PD;k++)
   	      	{
      	      setTMPPopulation(k,i,getPopulation(k,i));
         	   }
	      }

   	//new population replace old population
	   for(i=0;i<PNP;i++)
	   	{
	      for(j=0;j<PD;j++)
	      	{
            setPopulation(j,i,getTMPPopulation(j,i));
	         }
	      }

		//search for the best individual
   	WorstIndividual();
		BestIndividual();

		//append to History
		History[l]=h;
      }

   //return the best individual
	MLPutFunction(stdlink, "List", 1);
	for(i=0;i<PD-1;i++)
		{
	  	if(getSpecimen(2,i)==1)
      	{
  			MLPutFunction(stdlink, "Sequence", 2);
      	ckl1=getIntPopulation(i,k);
			MLPutReal(stdlink, ckl1);
         }
   	else
      	{
  			MLPutFunction(stdlink, "Sequence", 2);
	      ckl1=getPopulation(i,k);
			MLPutReal(stdlink, ckl1);
         }
		}

   //return cost value of the best individual
	MLPutFunction(stdlink, "Sequence", 4);
	ckl1=getPopulation(PD-1,k);
	MLPutReal(stdlink,  ckl1);
	MLPutReal(stdlink,  l);//l
	MLPutReal(stdlink,  neval);//neval

	//send History to Mathematica
	for(i=0;i<Generations;i++)
		{
		MLPutFunction(stdlink, "Sequence", 2);
		MLPutReal(stdlink,  History[i]);
		}

	MLPutFunction(stdlink, "Sequence", 0);

   destroySpecimen();
	destroyHistory();
   destroyTMPPopulation();
   destroyPopulation();

	return ;
}

