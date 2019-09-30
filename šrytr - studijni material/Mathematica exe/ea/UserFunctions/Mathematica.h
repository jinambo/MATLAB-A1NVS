//This call cost function in Mathematica enviroment
//defined like CostFunction[x_]:=Module[{},.....]
//where x_ is generally individual (vector)
//For more details please see
//http://www.ft.utb.cz/people/zelinka/soma.htm
int ParmOfInd,n;
CostValue=0.0;

MLPutFunction(stdlink, "EvaluatePacket", 1);
MLPutFunction(stdlink, "CostFunction", 1);
MLPutFunction(stdlink, "List", 1);
for(ParmOfInd=0;ParmOfInd<PD-1;ParmOfInd++)
	{
	MLPutFunction(stdlink, "Sequence", 2);
  	if(getSpecimen(2,ParmOfInd)==1)
		MLPutReal(stdlink, getIntPopulation(ParmOfInd,Individual));
   else
		MLPutReal(stdlink, getPopulation(ParmOfInd,Individual));
   }
MLPutFunction(stdlink, "Sequence", 0);
MLEndPacket(stdlink);
MLCheckFunction(stdlink, "ReturnPacket", &n);
MLGetReal(stdlink, &CostValue);

