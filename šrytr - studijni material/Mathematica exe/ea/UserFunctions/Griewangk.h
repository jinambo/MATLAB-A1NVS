//Griewangk's function
//Test on this function described in PDF files at
//http://www.ft.utb.cz/people/zelinka/soma.htm was done for all parameters
//of individual inside inteval
//IntervalFrom = -100;
//IntervalTo = 100;
int ParmOfInd;	//parameter of individual
double TempCostValue;
CostValue=0.0;
TempCostValue=1.0;

for(ParmOfInd=1;ParmOfInd<PD;ParmOfInd++)
	{
	if(getSpecimen(2,ParmOfInd-1)==1)
   	{
      TempCostValue=TempCostValue*(cos(getIntPopulation(ParmOfInd-1,Individual)/sqrt(ParmOfInd)));
   	CostValue=CostValue+(pow(getIntPopulation(ParmOfInd-1,Individual),2)/4000.);
      }
	else
   	{
      TempCostValue=TempCostValue*cos(getPopulation(ParmOfInd-1,Individual)/sqrt(ParmOfInd));
   	CostValue=CostValue+(pow(getPopulation(ParmOfInd-1,Individual),2)/4000.);
      }
   }
   CostValue=1+CostValue-TempCostValue;

