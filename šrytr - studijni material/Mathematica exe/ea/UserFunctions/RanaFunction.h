//Rana's function
//Test on this function described in PDF files at
//http://www.ft.utb.cz/people/zelinka/soma.htm was done for all parameters
//of individual inside inteval
//IntervalFrom = -500;
//IntervalTo = 500;
int ParmOfInd;	//parameter of individual
CostValue=0.0;

for(ParmOfInd=0;ParmOfInd<PD-2;ParmOfInd++)
	{
	if(getSpecimen(2,ParmOfInd)==1)
   	CostValue=CostValue+(cos(sqrt(fabs(1 + getIntPopulation(ParmOfInd,Individual) + getIntPopulation(ParmOfInd+1,Individual))))*sin(sqrt(fabs(1 - getIntPopulation(ParmOfInd,Individual) + getIntPopulation(ParmOfInd+1,Individual))))*getIntPopulation(ParmOfInd,Individual)+cos(sqrt(fabs(1 - getIntPopulation(ParmOfInd,Individual) + getIntPopulation(ParmOfInd+1,Individual))))*sin(sqrt(fabs(1 + getIntPopulation(ParmOfInd,Individual) + getIntPopulation(ParmOfInd+1,Individual))))*(1 + getIntPopulation(ParmOfInd+1,Individual)));
	else
   	CostValue=CostValue+(cos(sqrt(fabs(1 + getPopulation(ParmOfInd,Individual) + getPopulation(ParmOfInd+1,Individual))))*sin(sqrt(fabs(1 - getPopulation(ParmOfInd,Individual) + getPopulation(ParmOfInd+1,Individual))))*getPopulation(ParmOfInd,Individual)+cos(sqrt(fabs(1 - getPopulation(ParmOfInd,Individual) + getPopulation(ParmOfInd+1,Individual))))*sin(sqrt(fabs(1 + getPopulation(ParmOfInd,Individual) + getPopulation(ParmOfInd+1,Individual))))*(1 + getPopulation(ParmOfInd+1,Individual)));
   }


