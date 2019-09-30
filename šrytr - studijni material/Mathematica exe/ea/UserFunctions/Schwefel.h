//Schwefel's function
//Test on this function described in PDF files at
//http://www.ft.utb.cz/people/zelinka/soma.htm was done for all parameters
//of individual inside inteval
//IntervalFrom = -512;
//IntervalTo = 511;
int ParmOfInd;	//parameter of individual
CostValue=0.0;

for(ParmOfInd=0;ParmOfInd<PD-1;ParmOfInd++)
	{
	if(getSpecimen(2,ParmOfInd)==1)
		CostValue=CostValue-(getIntPopulation(ParmOfInd,Individual)*sin(sqrt(abs(getIntPopulation(ParmOfInd,Individual)))));
	else
		CostValue=(CostValue-getPopulation(ParmOfInd,Individual)*sin(sqrt(abs(getPopulation(ParmOfInd,Individual)))));
   }
