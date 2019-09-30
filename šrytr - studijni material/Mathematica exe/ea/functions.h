#ifndef __FUNCTION_H
#define __FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern double 	*Population,*TMPPopulation,*PRTV,*History,*Specimen;
extern int 		PD;
extern int 		PNP;
extern int		k,kk,l,n,neval;
extern double	h,hh;

#if defined(_Windows) && defined (DEBUG)
extern char 	d_buf[256];
extern FILE *out;
#endif

int createPopulation(int pd, int pnp);
int destroyPopulation(void);
double getPopulation(int pd, int pnp);
double getIntPopulation(int pd, int pnp);
void setPopulation(int pd, int pnp, double pop);

int createTMPPopulation(void);
int destroyTMPPopulation(void);
double getTMPPopulation(int pd, int pnp);
void setTMPPopulation(int pd, int pnp, double pop);

int createPRTV(int ml);
int destroyPRTV(void);

int createHistory(int ml);
int destroyHistory(void);

int createSpecimen(int pd);
int destroySpecimen(void);
double getSpecimen(int dm, int pd);
void setSpecimen(int dm, int pd, double pop);

void CostValue(int Individual);

void WorstIndividual(void);
void BestIndividual(void);

#endif // __FUNCTION_H
