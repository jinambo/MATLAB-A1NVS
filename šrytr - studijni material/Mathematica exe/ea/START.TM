/* To launch this program from within Mathematica use:
 *   In[1]:= link = Install["sumalist"]
 *
 * Or, launch this program from a shell and establish a
 * peer-to-peer connection.  When given the prompt Create Link:
 * type a port name. ( On Unix platforms, a port name is a
 * number less than 65536.  On Mac or Windows platforms,
 * it's an arbitrary word.)
 * Then, from within Mathematica use:
 *   In[1]:= link = Install["portname", LinkMode->Connect]
 */


:Begin:
:Function:      AOSoma
:Pattern:       AOSoma[ Mass_Real,Step_Real,PRT_Real,NP_Integer,D_Integer,Migrations_Integer,AcceptedError_Real,list2:{___Real} ]
:Arguments:     { Mass,Step,PRT,NP,D,Migrations,AcceptedError,list2 }
:ArgumentTypes: { Real,Real,Real,Integer,Integer,Integer,Real, RealList}
:ReturnType:    Manual
:End:

:Evaluate:      "AOSoma[ Mass,Step,PRT,NP,D,Migrations,AcceptedError,list2]"

:Begin:
:Function:      AORSoma
:Pattern:       AORSoma[ Mass_Real,Step_Real,PRT_Real,NP_Integer,D_Integer,Migrations_Integer,AcceptedError_Real,list2:{___Real} ]
:Arguments:     { Mass,Step,PRT,NP,D,Migrations,AcceptedError,list2 }
:ArgumentTypes: { Real,Real,Real,Integer,Integer,Integer,Real, RealList}
:ReturnType:    Manual
:End:

:Evaluate:      "AORSoma[ Mass,Step,PRT,NP,D,Migrations,AcceptedError,list2]"

:Begin:
:Function:      AASoma
:Pattern:       AASoma[ Mass_Real,Step_Real,PRT_Real,NP_Integer,D_Integer,Migrations_Integer,AcceptedError_Real,list2:{___Real} ]
:Arguments:     { Mass,Step,PRT,NP,D,Migrations,AcceptedError,list2 }
:ArgumentTypes: { Real,Real,Real,Integer,Integer,Integer,Real, RealList}
:ReturnType:    Manual
:End:

:Evaluate:      "AASoma[ Mass,Step,PRT,NP,D,Migrations,AcceptedError,list2]"

:Begin:
:Function:      ARSoma
:Pattern:       ARSoma[ Mass_Real,Step_Real,PRT_Real,NP_Integer,D_Integer,Migrations_Integer,AcceptedError_Real,list2:{___Real} ]
:Arguments:     { Mass,Step,PRT,NP,D,Migrations,AcceptedError,list2 }
:ArgumentTypes: { Real,Real,Real,Integer,Integer,Integer,Real, RealList}
:ReturnType:    Manual
:End:

:Evaluate:      "ARSoma[ Mass,Step,PRT,NP,D,Migrations,AcceptedError,list2]"

:Begin:
:Function:      DERand1Bin
:Pattern:       DERand1Bin[ F_Real, CR_Real, NP_Integer, D_Integer, Generations_Integer, list:{___Real} ]
:Arguments:     { F, CR, NP, D, Generations, list }
:ArgumentTypes: { Real, Real, Integer, Integer, Integer, RealList}
:ReturnType:    Manual
:End:

:Evaluate:      "DERand1Bin[ F, CR, NP, D, Generations, list]"

:Begin:
:Function:      DERand1Exp
:Pattern:       DERand1Exp[ F_Real, CR_Real, NP_Integer, D_Integer, Generations_Integer, list:{___Real} ]
:Arguments:     { F, CR, NP, D, Generations, list }
:ArgumentTypes: { Real, Real, Integer, Integer, Integer, RealList}
:ReturnType:    Manual
:End:

:Evaluate:      "DERand1Exp[ F, CR, NP, D, Generations, list]"

:Begin:
:Function:      DECurrentToRand1
:Pattern:       DECurrentToRand1[ F_Real, K_Real, NP_Integer, D_Integer, Generations_Integer, list:{___Real} ]
:Arguments:     { F, K, NP, D, Generations, list }
:ArgumentTypes: { Real, Real, Integer, Integer, Integer, RealList}
:ReturnType:    Manual
:End:

:Evaluate:      "DECurrentToRand1[ F, K, NP, D, Generations, list]"

:Begin:
:Function:      DECurrentToRand1Bin
:Pattern:       DECurrentToRand1Bin[ F_Real, CR_Real, K_Real, NP_Integer, D_Integer, Generations_Integer, list:{___Real} ]
:Arguments:     { F, CR, K, NP, D, Generations, list }
:ArgumentTypes: { Real, Real, Real, Integer, Integer, Integer, RealList}
:ReturnType:    Manual
:End:

:Evaluate:      "DECurrentToRand1Bin[ F, CR, K, NP, D, Generations, list]"

#if MACINTOSH_MATHLINK

int main( int argc, char* argv[])
{
	/* Due to a bug in some standard C libraries that have shipped with
	 * MPW, zero is passed to MLMain below.  (If you build this program
	 * as an MPW tool, you can change the zero to argc.)
	 */
	argc = argc; /* suppress warning */
	return MLMain( 0, argv);
}

#elif WINDOWS_MATHLINK

#if __BORLANDC__
#pragma argsused
#endif

int PASCAL WinMain( HANDLE hinstCurrent, HANDLE hinstPrevious, LPSTR lpszCmdLine, int nCmdShow)
{
	char  buff[512];
	char FAR * buff_start = buff;
	char FAR * argv[32];
	char FAR * FAR * argv_end = argv + 32;

	if( !MLInitializeIcon( hinstCurrent, nCmdShow)) return 1;
	MLScanString( argv, &argv_end, &lpszCmdLine, &buff_start);
	return MLMain( argv_end - argv, argv);
}

#else

int main(argc, argv)
	int argc; char* argv[];
{
	return MLMain(argc, argv);
}

#endif
