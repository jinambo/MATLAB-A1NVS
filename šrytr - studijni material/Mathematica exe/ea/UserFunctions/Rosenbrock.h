//Rosenbrock's saddle
//Test on this function described in PDF files at
//http://www.ft.utb.cz/people/zelinka/soma.htm was done for all parameters
//of individual inside inteval
//IntervalFrom = -2.048;
//IntervalTo = 2.047;
int ParmOfInd;	//parameter of individual
CostValue=0.0;

for(ParmOfInd=0;ParmOfInd<PD-2;ParmOfInd++)
	{
	if(getSpecimen(2,ParmOfInd)==1)
   	CostValue=CostValue+pow(1 - getIntPopulation(ParmOfInd,Individual),2) + 100*pow(pow(getIntPopulation(ParmOfInd,Individual),2) - getIntPopulation(ParmOfInd+1,Individual),2);
	else
   	CostValue=CostValue+pow(1 - getPopulation(ParmOfInd,Individual),2) + 100*pow(pow(getPopulation(ParmOfInd,Individual),2) - getPopulation(ParmOfInd+1,Individual),2);
   }

