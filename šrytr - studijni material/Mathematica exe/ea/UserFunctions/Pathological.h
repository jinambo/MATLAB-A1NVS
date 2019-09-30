//Test function - pathological
//Test on this function described in PDF files at
//http://www.ft.utb.cz/people/zelinka/soma.htm was done for all parameters
//of individual inside inteval
//IntervalFrom = -100;
//IntervalTo = 100;
int ParmOfInd;	//parameter of individual
CostValue=0.0;

for(ParmOfInd=0;ParmOfInd<PD-2;ParmOfInd++)
	{
	if(getSpecimen(2,ParmOfInd)==1)
   	CostValue=CostValue+(0.5 + (-0.5 + pow(sin(sqrt(100.*pow(getIntPopulation(ParmOfInd,Individual),2) + pow(getIntPopulation(ParmOfInd+1,Individual),2))),2))/(1. + 0.001*pow(pow(getIntPopulation(ParmOfInd+1,Individual),2) - 2*getIntPopulation(ParmOfInd,Individual)*getIntPopulation(ParmOfInd+1,Individual) + pow(getIntPopulation(ParmOfInd+1,Individual),2),2)));
	else
   	CostValue=CostValue+(0.5 + (-0.5 + pow(sin(sqrt(100.*pow(getPopulation(ParmOfInd,Individual),2) + pow(getPopulation(ParmOfInd+1,Individual),2))),2))/(1. + 0.001*pow(pow(getPopulation(ParmOfInd+1,Individual),2) - 2*getPopulation(ParmOfInd,Individual)*getPopulation(ParmOfInd+1,Individual) + pow(getPopulation(ParmOfInd+1,Individual),2),2)));
   }

