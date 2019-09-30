//Cosine wave function (Masters)
//Test on this function described in PDF files at
//http://www.ft.utb.cz/people/zelinka/soma.htm was done for all parameters
//of individual inside inteval
//IntervalFrom = -5;
//IntervalTo = 5;
int ParmOfInd;	//parameter of individual
CostValue=0.0;

for(ParmOfInd=0;ParmOfInd<PD-2;ParmOfInd++)
	{
	if(getSpecimen(2,ParmOfInd)==1)
   	CostValue=CostValue-(exp((-pow(getIntPopulation(ParmOfInd,Individual),2) - 0.5*getIntPopulation(ParmOfInd,Individual)*getIntPopulation(ParmOfInd+1,Individual) - pow(getIntPopulation(ParmOfInd+1,Individual),2))/8.)*cos(4*sqrt(pow(getIntPopulation(ParmOfInd,Individual),2) + 0.5*getIntPopulation(ParmOfInd,Individual)*getIntPopulation(ParmOfInd+1,Individual) + pow(getIntPopulation(ParmOfInd+1,Individual),2))));
	else
   	CostValue=CostValue-(exp((-pow(getPopulation(ParmOfInd,Individual),2) - 0.5*getPopulation(ParmOfInd,Individual)*getPopulation(ParmOfInd+1,Individual) - pow(getPopulation(ParmOfInd+1,Individual),2))/8.)*cos(4*sqrt(pow(getPopulation(ParmOfInd,Individual),2) + 0.5*getPopulation(ParmOfInd,Individual)*getPopulation(ParmOfInd+1,Individual) + pow(getPopulation(ParmOfInd+1,Individual),2))));
   }

