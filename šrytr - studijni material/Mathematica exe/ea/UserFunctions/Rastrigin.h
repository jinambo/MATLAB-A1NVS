//Rastrigin's function
//Test on this function described in PDF files at
//http://www.ft.utb.cz/people/zelinka/soma.htm was done for all parameters
//of individual inside inteval
//IntervalFrom = -5.12;
//IntervalTo = 5.11;
int ParmOfInd;	//parameter of individual
CostValue=0.0;

for(ParmOfInd=0;ParmOfInd<PD-1;ParmOfInd++)
	{
	if(getSpecimen(2,ParmOfInd)==1)
   	CostValue=CostValue+(-10*cos(2*3.14159*getIntPopulation(ParmOfInd,Individual)) + pow(getIntPopulation(ParmOfInd,Individual),2));
	else
   	CostValue=CostValue+(-10*cos(2*3.14159*getPopulation(ParmOfInd,Individual)) + pow(getPopulation(ParmOfInd,Individual),2));
   }
   CostValue=20*CostValue;

