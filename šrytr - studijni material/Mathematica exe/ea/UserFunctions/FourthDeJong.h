//4th De Jong's function
//Test on this function described in PDF files at
//http://www.ft.utb.cz/people/zelinka/soma.htm was done for all parameters
//of individual inside inteval
//IntervalFrom = -1.28;
//IntervalTo = 1.27;
int ParmOfInd;	//parameter of individual
CostValue=0.0;

for(ParmOfInd=0;ParmOfInd<PD-1;ParmOfInd++)
	{
	if(getSpecimen(2,ParmOfInd)==1)
   	CostValue=CostValue+ParmOfInd*pow(getIntPopulation(ParmOfInd,Individual),4);
	else
   	CostValue=CostValue+ParmOfInd*pow(getPopulation(ParmOfInd,Individual),4);
   }

