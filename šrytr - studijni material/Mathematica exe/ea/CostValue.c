#include "mathlink.h"
#include "functions.h"
#include <math.h>

//by user defined cost value
void CostValue(int Individual)
{
double CostValue;

//Dear user, you can use empty predefined cost function:...

//#include "UserFunctions\\Empty.h"

//...or use one of these test functions. Before use, this "//" C language
//special mark for notices have to be erased from the beginning of the row
//where is cost function to be use. For more details please open Readme.txt
//or see http://www.ft.utb.cz/people/zelinka/soma.htm

//#include "UserFunctions\\FirstDeJong.h"
//#include "UserFunctions\\Rosenbrock.h"
//#include "UserFunctions\\ThirdDeJong.h"
//#include "UserFunctions\\FourthDeJong.h"
//#include "UserFunctions\\Rastrigin.h"
//#include "UserFunctions\\Schwefel.h"
//#include "UserFunctions\\Griewangk.h"
//#include "UserFunctions\\StretchedSine.h"
//#include "UserFunctions\\TestFunctionAckley.h"
//#include "UserFunctions\\AckleyFunction.h"
//#include "UserFunctions\\EggHolders.h"
//#include "UserFunctions\\RanaFunction.h"
//#include "UserFunctions\\Pathological.h"
//#include "UserFunctions\\Michalewicz.h"
//#include "UserFunctions\\Masters.h"

#include "UserFunctions\\Mathematica.h"

setPopulation(PD-1,Individual,CostValue);
}

