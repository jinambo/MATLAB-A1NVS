//Test function - egg holders
//Test on this function described in PDF files at
//http://www.ft.utb.cz/people/zelinka/soma.htm was done for all parameters
//of individual inside inteval
//IntervalFrom = -512;
//IntervalTo = 512;
int ParmOfInd;	//parameter of individual
CostValue=0.0;

for(ParmOfInd=0;ParmOfInd<PD-2;ParmOfInd++)
	{
	if(getSpecimen(2,ParmOfInd)==1)
   	CostValue=CostValue+(-(sin(sqrt(fabs(-47 + getIntPopulation(ParmOfInd,Individual)-getIntPopulation(ParmOfInd+1,Individual))))*getIntPopulation(ParmOfInd,Individual))-sin(sqrt(fabs(47 + getIntPopulation(ParmOfInd,Individual)/2. + getIntPopulation(ParmOfInd+1,Individual))))*(47 + getIntPopulation(ParmOfInd+1,Individual)));
	else
   	CostValue=CostValue-(sin(sqrt(fabs(-47 + getPopulation(ParmOfInd,Individual)-getPopulation(ParmOfInd+1,Individual))))*getPopulation(ParmOfInd,Individual))-sin(sqrt(fabs(47 + getPopulation(ParmOfInd,Individual)/2. + getPopulation(ParmOfInd+1,Individual))))*(47 + getPopulation(ParmOfInd+1,Individual));
   }

