//Ackley's function
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
   	CostValue=CostValue+((20 + 2.71828 - exp(0.5*(cos(2*3.14159*getIntPopulation(ParmOfInd,Individual)) + cos(2*3.14159*getIntPopulation(ParmOfInd+1,Individual))))-20/exp(0.14142135623730953*sqrt(pow(getIntPopulation(ParmOfInd,Individual),2) + pow(getIntPopulation(ParmOfInd+1,Individual),2)))));
	else
   	CostValue=CostValue+(20 + 2.71828 - exp(0.5*(cos(2*3.14159*getPopulation(ParmOfInd,Individual)) + cos(2*3.14159*getPopulation(ParmOfInd+1,Individual))))-20/exp(0.14142135623730953*sqrt(pow(getPopulation(ParmOfInd,Individual),2) + pow(getPopulation(ParmOfInd+1,Individual),2))));
   }

