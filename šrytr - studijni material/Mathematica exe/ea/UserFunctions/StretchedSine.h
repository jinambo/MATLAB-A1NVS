//Stretched V sine wave function (Ackley)
//Test on this function described in PDF files at
//http://www.ft.utb.cz/people/zelinka/soma.htm was done for all parameters
//of individual inside inteval
//IntervalFrom = -10;
//IntervalTo = 10;
int ParmOfInd;	//parameter of individual
CostValue=0.0;

for(ParmOfInd=0;ParmOfInd<PD-2;ParmOfInd++)
	{
	if(getSpecimen(2,ParmOfInd)==1)
   	CostValue=CostValue+((1 + pow(sin(50*pow(pow(getIntPopulation(ParmOfInd,Individual),2) + pow(getIntPopulation(ParmOfInd+1,Individual),2),0.1)),2))*pow(pow(getIntPopulation(ParmOfInd,Individual),2) + pow(getIntPopulation(ParmOfInd+1,Individual),2),0.25));
	else
   	CostValue=CostValue+(1 + pow(sin(50*pow(pow(getPopulation(ParmOfInd,Individual),2) + pow(getPopulation(ParmOfInd+1,Individual),2),0.1)),2))*pow(pow(getPopulation(ParmOfInd,Individual),2) + pow(getPopulation(ParmOfInd+1,Individual),2),0.25);
   }

