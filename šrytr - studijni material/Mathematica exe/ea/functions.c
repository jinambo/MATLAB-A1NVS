#include "functions.h"
#include "math.h"

double 	*Population,*TMPPopulation,*PRTV,*History,*Specimen;
int 		PD;
int 		PNP;
int		k,kk,l,n,neval;
double	h,hh;

#if defined(_Windows) && defined (DEBUG)
char 	d_buf[256];
FILE *out;
#endif

int createPopulation(int pd, int pnp)
{

	if (Population) return -1;

	PD = pd;
	PNP = pnp;

	Population = (double*) calloc(PNP * PD, sizeof(double));
	return Population ? 0 : 1;
}

int destroyPopulation()
{
	PD = 0;
	PNP = 0;

   free(Population);
   Population = 0;
   return 0;
}

int createTMPPopulation()
{

	if (TMPPopulation) return -1;
	TMPPopulation = (double*) calloc(PNP * PD, sizeof(double));
	return TMPPopulation ? 0 : 1;
}

int destroyTMPPopulation()
{
   free(TMPPopulation);
   TMPPopulation = 0;
   return 0;
}

double getPopulation(int pd, int pnp)
{
   return Population[PD * pnp + pd];
}

double getIntPopulation(int pd, int pnp)
{
   return floor(Population[PD * pnp + pd]);
}

void setPopulation(int pd, int pnp, double pop)
{
   Population[PD * pnp + pd] = pop;
}

double getTMPPopulation(int pd, int pnp)
{
   return TMPPopulation[PD * pnp + pd];
}

void setTMPPopulation(int pd, int pnp, double pop)
{
   TMPPopulation[PD * pnp + pd] = pop;
}

int createSpecimen(int pd)
{

	if (Specimen) return -1;
	Specimen = (double*) calloc(pd * 3, sizeof(double));
	return Specimen ? 0 : 1;
}

int destroySpecimen()
{
   free(Specimen);
   Specimen = 0;
   return 0;
}

double getSpecimen(int dm, int pd)
{
   return Specimen[3 * pd + dm];
}

void setSpecimen(int dm, int pd, double pop)
{
   Specimen[3 * pd + dm] = pop;
}

int createPRTV(int pd)
{
	if (PRTV) return -1;
	PRTV = (double*) calloc(pd, sizeof(double));
	return Population ? 0 : 1;
}

int destroyPRTV()
{
   free(PRTV);
   PRTV = 0;
   return 0;
}

int createHistory(int ml)
{
	if (History) return -1;
	History = (double*) calloc(ml, sizeof(double));
	return Population ? 0 : 1;
}

int destroyHistory()
{
   free(History);
   History = 0;
   return 0;
}

void WorstIndividual()
{
	int	smc;
	kk=0;
	hh=getPopulation(PD-1,0);
	for(smc=1;smc<PNP-3;smc++)
		if(getPopulation(PD-1,smc)>hh)
			{
			kk=smc;
			hh=getPopulation(PD-1,smc);
			}
}

void BestIndividual()
{
	int	smc;
	k=0;
	h=getPopulation(PD-1,0);
	for(smc=1;smc<PNP-3;smc++)
		if(getPopulation(PD-1,smc)<h)
			{
			k=smc;
			h=getPopulation(PD-1,smc);
			}
}
