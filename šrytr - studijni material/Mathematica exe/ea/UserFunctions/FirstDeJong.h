//Sphere model, 1st De Jong's function
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
   	CostValue=CostValue+pow(getIntPopulation(ParmOfInd,Individual),2);
	else
   	CostValue=CostValue+pow(getPopulation(ParmOfInd,Individual),2);
   }

