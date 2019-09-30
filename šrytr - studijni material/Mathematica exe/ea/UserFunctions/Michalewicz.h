//Michalewicz's function
//Test on this function described in PDF files at
//http://www.ft.utb.cz/people/zelinka/soma.htm was done for all parameters
//of individual inside inteval
//IntervalFrom = 0;
//IntervalTo = 3.14 (Pi);
int ParmOfInd;	//parameter of individual
CostValue=0.0;

for(ParmOfInd=0;ParmOfInd<PD-2;ParmOfInd++)
	{
	if(getSpecimen(2,ParmOfInd)==1)
   	CostValue=CostValue+(-(sin(getIntPopulation(ParmOfInd,Individual))*pow(sin(0.3183098861837907*pow(getIntPopulation(ParmOfInd,Individual),2)),20))-sin(getIntPopulation(ParmOfInd+1,Individual))*pow(sin(0.6366197723675814*pow(getIntPopulation(ParmOfInd+1,Individual),2)),20));
	else
   	CostValue=CostValue+(-(sin(getPopulation(ParmOfInd,Individual))*pow(sin(0.3183098861837907*pow(getPopulation(ParmOfInd,Individual),2)),20))-sin(getPopulation(ParmOfInd+1,Individual))*pow(sin(0.6366197723675814*pow(getPopulation(ParmOfInd+1,Individual),2)),20));
   }

