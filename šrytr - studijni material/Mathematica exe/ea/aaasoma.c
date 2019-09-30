#include "mathlink.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "functions.h"

void ARSoma P(( double,double,double,int,int,int,double, doublep_nt, long));

void ARSoma( double Mass,double Step,double PRT, int NP, int D, int Migrations,double AcceptedError,doublep_nt list2, long len2 )
{
//   double	PRTV[Dimension];
//   double	Specimen[3][Dimension];
   //History[LengthOfHistory],
   double	ckl1,xxx;
	int 		i,j;//l,n,neval;

#if 0 //defined(_Windows) && defined (DEBUG)
   sprintf(d_buf, "SOMA AOSoma enter");
	MessageBox(0, d_buf, "SOMA", MB_OK);
#endif

   createPopulation(D+1, NP+3);
   createPRTV(D);
	createHistory(Migrations);
   createSpecimen(D);

#if 0 //defined(_Windows) && defined (DEBUG)
   sprintf(d_buf, "SOMA AOSoma\nPNP: %d (%d), PD: %d (%d), Population: %p", PNP, NP, PD, D, Population);
	MessageBox(0, d_buf, "SOMA", MB_OK);
#endif

	k=neval=0;
	for(i=0;i<PD-1;i++)
		for(j=0;j<3;j++)
			{
			setSpecimen(j,i,list2[k]);
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

	//search for the best and the worst of individuals
   WorstIndividual();
	BestIndividual();

	for(l=0;l<Migrations;l++)
   	{
		//append to History
		History[l]=h;
		if(AcceptedError>=fabs(fabs(h)-fabs(hh)))
      	goto SKIP;

		//Migration
      for(k=0;k<PNP-3;k++)
	      {
			for(i=0;i<PNP-3;i++)
			  	{
				k=floor((PNP-3)*random (1000)/1000.0);
				if(i!=k)
					{
					for(n=0;n<PD;n++)
						setPopulation(n,PNP-2,getPopulation(n,i));
					for(n=0;n<PD-1;n++)
						{
						if((random (1000)/1000.0)>PRT)
							PRTV[n]=0.0;
						else
							PRTV[n]=1.0;
						}
					for(ckl1=0;ckl1<=Mass;ckl1=ckl1+Step)
						{
      	         for(j=0;j<PD-1;j++)
	      				{
		      	   	setPopulation(j,PNP-3,getPopulation(j,i)+(getPopulation(j,k)-getPopulation(j,i))*ckl1*PRTV[j]);
							//type of variable and boundary checking
				     		if(getSpecimen(0,j)>getPopulation(j,PNP-3) || getSpecimen(1,j)<getPopulation(j,PNP-3))
//					     		if(getSpecimen(2,j)==0)
										setPopulation(j,PNP-3,getSpecimen(0,j)+(random (1000)/1000.0)*(getSpecimen(1,j)-getSpecimen(0,j)));
//									else
//										setPopulation(j,PNP-3,floor(getSpecimen(0,j)+(random (1000)/1000.0)*(getSpecimen(1,j)-getSpecimen(0,j)+1)));
//      	            else
//						     	if(getSpecimen(2,j)==1)
//										setPopulation(j,PNP-3,floor(getPopulation(j,PNP-3)));
							}
				      neval++;
						CostValue(PNP-3);
						if(getPopulation(PD-1,PNP-3)<getPopulation(PD-1,PNP-2))
							{
							for(n=0;n<PD;n++)
							setPopulation(n,PNP-2,getPopulation(n,PNP-3));
							}
						}
					for(n=0;n<PD;n++)
						setPopulation(n,i,getPopulation(n,PNP-2));
					}
				}
      	}
	   WorstIndividual();
		BestIndividual();

		}
SKIP:
   //return the best individual
	MLPutFunction(stdlink, "List", 1);
	for(i=0;i<PD-1;i++)
		{
		MLPutFunction(stdlink, "Sequence", 2);
      ckl1=getPopulation(i,k);
#if 0 //defined(_Windows) && defined (DEBUG)
   sprintf(d_buf, "ckl1=%f",ckl1);
	MessageBox(0, d_buf, "SOMA", MB_OK);
#endif
		MLPutReal(stdlink, ckl1);
		}


#if 0 //defined(_Windows) && defined (DEBUG)
   sprintf(d_buf, "BI k=%d",k);
	MessageBox(0, d_buf, "SOMA", MB_OK);
#endif

   //return cost value of the best individual
//	MLPutFunction(stdlink, "List", 1);
	MLPutFunction(stdlink, "Sequence", 4);
	ckl1=getPopulation(PD-1,k);
	MLPutReal(stdlink,  ckl1);
	MLPutReal(stdlink,  l);//l
	MLPutReal(stdlink,  neval);//neval

#if 0 //defined(_Windows) && defined (DEBUG)
   sprintf(d_buf, "CVI");
	MessageBox(0, d_buf, "SOMA", MB_OK);
#endif

	//send History to Mathematica
//	MLPutFunction(stdlink, "List", 1);
	for(i=0;i<Migrations;i++)
		{
		MLPutFunction(stdlink, "Sequence", 2);
		MLPutReal(stdlink,  History[i]);
		}

#if 0 //defined(_Windows) && defined (DEBUG)
   sprintf(d_buf, "Hist");
	MessageBox(0, d_buf, "SOMA", MB_OK);
#endif

/*   //return whole last population
//	MLPutFunction(stdlink, "List", 1);
	for(i=0;i<PNP;i++)
		{
		MLPutFunction(stdlink, "List", 1);
      for(j=0;j<PD;j++)
      	{
			MLPutFunction(stdlink, "Sequence", 2);
			MLPutReal(stdlink,  Population[i][j]);
         }
		}
*/
	MLPutFunction(stdlink, "Sequence", 0);


   destroySpecimen();
	destroyHistory();
   destroyPRTV();
   destroyPopulation();

#if 0 //defined(_Windows) && defined (DEBUG)
   sprintf(d_buf, "SOMA AOSoma exit");
	MessageBox(0, d_buf, "SOMA", MB_OK);
#endif
	return ;
}


