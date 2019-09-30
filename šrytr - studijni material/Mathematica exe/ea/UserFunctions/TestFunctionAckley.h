//Test function (Ackley)
//Test on this function described in PDF files at
//http://www.ft.utb.cz/people/zelinka/soma.htm was done for all parameters
//of individual inside inteval
//IntervalFrom = -30;
//IntervalTo = 30;
int ParmOfInd;	//parameter of individual
CostValue=0.0;

for(ParmOfInd=0;ParmOfInd<PD-2;ParmOfInd++)
	{
	if(getSpecimen(2,ParmOfInd)==1)
   	CostValue=CostValue+(3*(cos(2*getIntPopulation(ParmOfInd,Individual)) + sin(2*getIntPopulation(ParmOfInd+1,Individual))) + 0.8187307530779818*sqrt(pow(getIntPopulation(ParmOfInd,Individual),2) + pow(getIntPopulation(ParmOfInd+1,Individual),2)));
	else
   	CostValue=CostValue+(3*(cos(2*getPopulation(ParmOfInd,Individual)) + sin(2*getPopulation(ParmOfInd+1,Individual))) + 0.8187307530779818*sqrt(pow(getPopulation(ParmOfInd,Individual),2) + pow(getPopulation(ParmOfInd+1,Individual),2)));
   }

