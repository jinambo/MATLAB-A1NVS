/*
 * This file automatically produced by C:\PROGRA~1\BC5\BIN\MPREP.EXE from:
 *	start.tm
 * mprep Revision 7 (c) Copyright Wolfram Research, Inc. 1990-1999
 */

#define MPREP_REVISION 7


#include "mathlink.h"

int MLAbort = 0;
int MLDone  = 0;
long MLSpecialCharacter = '\0';
HANDLE MLInstance = (HANDLE)0;
HWND MLIconWindow = (HWND)0;

MLINK stdlink = 0;
MLEnvironment stdenv = 0;
MLYieldFunctionObject stdyielder = 0;
MLMessageHandlerObject stdhandler = 0;

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#if WIN32_MATHLINK && !defined(_fstrncpy)
#       define _fstrncpy strncpy
#endif

#ifndef CALLBACK
#define CALLBACK FAR PASCAL
typedef LONG LRESULT;
typedef unsigned int UINT;
typedef WORD WPARAM;
typedef DWORD LPARAM;
#endif


LRESULT CALLBACK MLEXPORT
IconProcedure( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK MLEXPORT
IconProcedure( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch( msg){
	case WM_CLOSE:
		MLDone = 1;
		MLAbort = 1;
		break;
	case WM_QUERYOPEN:
		return 0;
	}
	return DefWindowProc( hWnd, msg, wParam, lParam);
}

#define _APISTR(i) #i
#define APISTR(i) _APISTR(i)

HWND MLInitializeIcon( HINSTANCE hInstance, int nCmdShow)
{
	char path_name[260], *icon_name;
	WNDCLASS  wc;
	HMODULE hdll;

	MLInstance = hInstance;
	if( ! nCmdShow) return (HWND)0;
#if WIN16_MATHLINK
	hdll = GetModuleHandle( "ml16i" APISTR(MLINTERFACE));
#else
	hdll = GetModuleHandle( "ml32i" APISTR(MLINTERFACE));
#endif

	(void)GetModuleFileName( hInstance, path_name, sizeof(path_name));
	icon_name = strrchr( path_name, '\\') + 1;
	*strchr( icon_name, '.') = '\0';

	wc.style = 0;
	wc.lpfnWndProc = IconProcedure;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	if( hdll)
		wc.hIcon = LoadIcon( hdll, "MLIcon");
	else
		wc.hIcon = LoadIcon( NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor( NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject( WHITE_BRUSH);
	wc.lpszMenuName =  (LPSTR) 0;
	wc.lpszClassName = "mprepIcon";
	(void)RegisterClass( &wc);

	MLIconWindow = CreateWindow( "mprepIcon", icon_name,
			WS_OVERLAPPEDWINDOW | WS_MINIMIZE, CW_USEDEFAULT,
			CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
			(HWND)0, (HMENU)0, hInstance, (void FAR*)0);

	if( MLIconWindow){
		ShowWindow( MLIconWindow, SW_MINIMIZE);
		UpdateWindow( MLIconWindow);
	}
	return MLIconWindow;
}


#if __BORLANDC__
#pragma argsused
#endif

MLYDEFN( devyield_result, MLDefaultYielder, ( MLINK mlp, MLYieldParameters yp))
{
	MSG msg;

#if !__BORLANDC__
	mlp = mlp; /* suppress unused warning */
	yp = yp; /* suppress unused warning */
#endif

	if( PeekMessage( &msg, (HWND)0, 0, 0, PM_REMOVE)){
		TranslateMessage( &msg);
		DispatchMessage( &msg);
	}
	return MLDone;
}


/********************************* end header *********************************/


# line 1 "start.tm"
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


# line 144 "start.c"


# line 94 "start.tm"
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
# line 187 "start.c"


void AOSoma P(( double _tp1, double _tp2, double _tp3, int _tp4, int _tp5, int _tp6, double _tp7, doublep_nt _tp8, long _tpl8));

#if MLPROTOTYPES
static int _tr0( MLINK mlp)
#else
static int _tr0(mlp) MLINK mlp;
#endif
{
	int	res = 0;
	double _tp1;
	double _tp2;
	double _tp3;
	int _tp4;
	int _tp5;
	int _tp6;
	double _tp7;
	doublep_nt _tp8;
	long _tpl8;
	if ( ! MLGetReal( mlp, &_tp1) ) goto L0;
	if ( ! MLGetReal( mlp, &_tp2) ) goto L1;
	if ( ! MLGetReal( mlp, &_tp3) ) goto L2;
	if ( ! MLGetInteger( mlp, &_tp4) ) goto L3;
	if ( ! MLGetInteger( mlp, &_tp5) ) goto L4;
	if ( ! MLGetInteger( mlp, &_tp6) ) goto L5;
	if ( ! MLGetReal( mlp, &_tp7) ) goto L6;
	if ( ! MLGetRealList( mlp, &_tp8, &_tpl8) ) goto L7;
	if ( ! MLNewPacket(mlp) ) goto L8;

	AOSoma(_tp1, _tp2, _tp3, _tp4, _tp5, _tp6, _tp7, _tp8, _tpl8);

	res = 1;
L8:	MLDisownRealList( mlp, _tp8, _tpl8);
L7: L6: L5: L4: L3: L2: L1: 
L0:	return res;
} /* _tr0 */


void AORSoma P(( double _tp1, double _tp2, double _tp3, int _tp4, int _tp5, int _tp6, double _tp7, doublep_nt _tp8, long _tpl8));

#if MLPROTOTYPES
static int _tr1( MLINK mlp)
#else
static int _tr1(mlp) MLINK mlp;
#endif
{
	int	res = 0;
	double _tp1;
	double _tp2;
	double _tp3;
	int _tp4;
	int _tp5;
	int _tp6;
	double _tp7;
	doublep_nt _tp8;
	long _tpl8;
	if ( ! MLGetReal( mlp, &_tp1) ) goto L0;
	if ( ! MLGetReal( mlp, &_tp2) ) goto L1;
	if ( ! MLGetReal( mlp, &_tp3) ) goto L2;
	if ( ! MLGetInteger( mlp, &_tp4) ) goto L3;
	if ( ! MLGetInteger( mlp, &_tp5) ) goto L4;
	if ( ! MLGetInteger( mlp, &_tp6) ) goto L5;
	if ( ! MLGetReal( mlp, &_tp7) ) goto L6;
	if ( ! MLGetRealList( mlp, &_tp8, &_tpl8) ) goto L7;
	if ( ! MLNewPacket(mlp) ) goto L8;

	AORSoma(_tp1, _tp2, _tp3, _tp4, _tp5, _tp6, _tp7, _tp8, _tpl8);

	res = 1;
L8:	MLDisownRealList( mlp, _tp8, _tpl8);
L7: L6: L5: L4: L3: L2: L1: 
L0:	return res;
} /* _tr1 */


void AASoma P(( double _tp1, double _tp2, double _tp3, int _tp4, int _tp5, int _tp6, double _tp7, doublep_nt _tp8, long _tpl8));

#if MLPROTOTYPES
static int _tr2( MLINK mlp)
#else
static int _tr2(mlp) MLINK mlp;
#endif
{
	int	res = 0;
	double _tp1;
	double _tp2;
	double _tp3;
	int _tp4;
	int _tp5;
	int _tp6;
	double _tp7;
	doublep_nt _tp8;
	long _tpl8;
	if ( ! MLGetReal( mlp, &_tp1) ) goto L0;
	if ( ! MLGetReal( mlp, &_tp2) ) goto L1;
	if ( ! MLGetReal( mlp, &_tp3) ) goto L2;
	if ( ! MLGetInteger( mlp, &_tp4) ) goto L3;
	if ( ! MLGetInteger( mlp, &_tp5) ) goto L4;
	if ( ! MLGetInteger( mlp, &_tp6) ) goto L5;
	if ( ! MLGetReal( mlp, &_tp7) ) goto L6;
	if ( ! MLGetRealList( mlp, &_tp8, &_tpl8) ) goto L7;
	if ( ! MLNewPacket(mlp) ) goto L8;

	AASoma(_tp1, _tp2, _tp3, _tp4, _tp5, _tp6, _tp7, _tp8, _tpl8);

	res = 1;
L8:	MLDisownRealList( mlp, _tp8, _tpl8);
L7: L6: L5: L4: L3: L2: L1: 
L0:	return res;
} /* _tr2 */


void ARSoma P(( double _tp1, double _tp2, double _tp3, int _tp4, int _tp5, int _tp6, double _tp7, doublep_nt _tp8, long _tpl8));

#if MLPROTOTYPES
static int _tr3( MLINK mlp)
#else
static int _tr3(mlp) MLINK mlp;
#endif
{
	int	res = 0;
	double _tp1;
	double _tp2;
	double _tp3;
	int _tp4;
	int _tp5;
	int _tp6;
	double _tp7;
	doublep_nt _tp8;
	long _tpl8;
	if ( ! MLGetReal( mlp, &_tp1) ) goto L0;
	if ( ! MLGetReal( mlp, &_tp2) ) goto L1;
	if ( ! MLGetReal( mlp, &_tp3) ) goto L2;
	if ( ! MLGetInteger( mlp, &_tp4) ) goto L3;
	if ( ! MLGetInteger( mlp, &_tp5) ) goto L4;
	if ( ! MLGetInteger( mlp, &_tp6) ) goto L5;
	if ( ! MLGetReal( mlp, &_tp7) ) goto L6;
	if ( ! MLGetRealList( mlp, &_tp8, &_tpl8) ) goto L7;
	if ( ! MLNewPacket(mlp) ) goto L8;

	ARSoma(_tp1, _tp2, _tp3, _tp4, _tp5, _tp6, _tp7, _tp8, _tpl8);

	res = 1;
L8:	MLDisownRealList( mlp, _tp8, _tpl8);
L7: L6: L5: L4: L3: L2: L1: 
L0:	return res;
} /* _tr3 */


void DERand1Bin P(( double _tp1, double _tp2, int _tp3, int _tp4, int _tp5, doublep_nt _tp6, long _tpl6));

#if MLPROTOTYPES
static int _tr4( MLINK mlp)
#else
static int _tr4(mlp) MLINK mlp;
#endif
{
	int	res = 0;
	double _tp1;
	double _tp2;
	int _tp3;
	int _tp4;
	int _tp5;
	doublep_nt _tp6;
	long _tpl6;
	if ( ! MLGetReal( mlp, &_tp1) ) goto L0;
	if ( ! MLGetReal( mlp, &_tp2) ) goto L1;
	if ( ! MLGetInteger( mlp, &_tp3) ) goto L2;
	if ( ! MLGetInteger( mlp, &_tp4) ) goto L3;
	if ( ! MLGetInteger( mlp, &_tp5) ) goto L4;
	if ( ! MLGetRealList( mlp, &_tp6, &_tpl6) ) goto L5;
	if ( ! MLNewPacket(mlp) ) goto L6;

	DERand1Bin(_tp1, _tp2, _tp3, _tp4, _tp5, _tp6, _tpl6);

	res = 1;
L6:	MLDisownRealList( mlp, _tp6, _tpl6);
L5: L4: L3: L2: L1: 
L0:	return res;
} /* _tr4 */


void DERand1Exp P(( double _tp1, double _tp2, int _tp3, int _tp4, int _tp5, doublep_nt _tp6, long _tpl6));

#if MLPROTOTYPES
static int _tr5( MLINK mlp)
#else
static int _tr5(mlp) MLINK mlp;
#endif
{
	int	res = 0;
	double _tp1;
	double _tp2;
	int _tp3;
	int _tp4;
	int _tp5;
	doublep_nt _tp6;
	long _tpl6;
	if ( ! MLGetReal( mlp, &_tp1) ) goto L0;
	if ( ! MLGetReal( mlp, &_tp2) ) goto L1;
	if ( ! MLGetInteger( mlp, &_tp3) ) goto L2;
	if ( ! MLGetInteger( mlp, &_tp4) ) goto L3;
	if ( ! MLGetInteger( mlp, &_tp5) ) goto L4;
	if ( ! MLGetRealList( mlp, &_tp6, &_tpl6) ) goto L5;
	if ( ! MLNewPacket(mlp) ) goto L6;

	DERand1Exp(_tp1, _tp2, _tp3, _tp4, _tp5, _tp6, _tpl6);

	res = 1;
L6:	MLDisownRealList( mlp, _tp6, _tpl6);
L5: L4: L3: L2: L1: 
L0:	return res;
} /* _tr5 */


void DECurrentToRand1 P(( double _tp1, double _tp2, int _tp3, int _tp4, int _tp5, doublep_nt _tp6, long _tpl6));

#if MLPROTOTYPES
static int _tr6( MLINK mlp)
#else
static int _tr6(mlp) MLINK mlp;
#endif
{
	int	res = 0;
	double _tp1;
	double _tp2;
	int _tp3;
	int _tp4;
	int _tp5;
	doublep_nt _tp6;
	long _tpl6;
	if ( ! MLGetReal( mlp, &_tp1) ) goto L0;
	if ( ! MLGetReal( mlp, &_tp2) ) goto L1;
	if ( ! MLGetInteger( mlp, &_tp3) ) goto L2;
	if ( ! MLGetInteger( mlp, &_tp4) ) goto L3;
	if ( ! MLGetInteger( mlp, &_tp5) ) goto L4;
	if ( ! MLGetRealList( mlp, &_tp6, &_tpl6) ) goto L5;
	if ( ! MLNewPacket(mlp) ) goto L6;

	DECurrentToRand1(_tp1, _tp2, _tp3, _tp4, _tp5, _tp6, _tpl6);

	res = 1;
L6:	MLDisownRealList( mlp, _tp6, _tpl6);
L5: L4: L3: L2: L1: 
L0:	return res;
} /* _tr6 */


void DECurrentToRand1Bin P(( double _tp1, double _tp2, double _tp3, int _tp4, int _tp5, int _tp6, doublep_nt _tp7, long _tpl7));

#if MLPROTOTYPES
static int _tr7( MLINK mlp)
#else
static int _tr7(mlp) MLINK mlp;
#endif
{
	int	res = 0;
	double _tp1;
	double _tp2;
	double _tp3;
	int _tp4;
	int _tp5;
	int _tp6;
	doublep_nt _tp7;
	long _tpl7;
	if ( ! MLGetReal( mlp, &_tp1) ) goto L0;
	if ( ! MLGetReal( mlp, &_tp2) ) goto L1;
	if ( ! MLGetReal( mlp, &_tp3) ) goto L2;
	if ( ! MLGetInteger( mlp, &_tp4) ) goto L3;
	if ( ! MLGetInteger( mlp, &_tp5) ) goto L4;
	if ( ! MLGetInteger( mlp, &_tp6) ) goto L5;
	if ( ! MLGetRealList( mlp, &_tp7, &_tpl7) ) goto L6;
	if ( ! MLNewPacket(mlp) ) goto L7;

	DECurrentToRand1Bin(_tp1, _tp2, _tp3, _tp4, _tp5, _tp6, _tp7, _tpl7);

	res = 1;
L7:	MLDisownRealList( mlp, _tp7, _tpl7);
L6: L5: L4: L3: L2: L1: 
L0:	return res;
} /* _tr7 */


static struct func {
	int   f_nargs;
	int   manual;
	int   (*f_func)P((MLINK));
	char  *f_name;
	} _tramps[8] = {
		{ 8, 0, _tr0, "AOSoma" },
		{ 8, 0, _tr1, "AORSoma" },
		{ 8, 0, _tr2, "AASoma" },
		{ 8, 0, _tr3, "ARSoma" },
		{ 6, 0, _tr4, "DERand1Bin" },
		{ 6, 0, _tr5, "DERand1Exp" },
		{ 6, 0, _tr6, "DECurrentToRand1" },
		{ 7, 0, _tr7, "DECurrentToRand1Bin" }
		};

static char* evalstrs[] = {
	"\"AOSoma[ Mass,Step,PRT,NP,D,Migrations,AcceptedError,list2]\"",
	(char*)0,
	"\"AORSoma[ Mass,Step,PRT,NP,D,Migrations,AcceptedError,list2]\"",
	(char*)0,
	"\"AASoma[ Mass,Step,PRT,NP,D,Migrations,AcceptedError,list2]\"",
	(char*)0,
	"\"ARSoma[ Mass,Step,PRT,NP,D,Migrations,AcceptedError,list2]\"",
	(char*)0,
	"\"DERand1Bin[ F, CR, NP, D, Generations, list]\"",
	(char*)0,
	"\"DERand1Exp[ F, CR, NP, D, Generations, list]\"",
	(char*)0,
	"\"DECurrentToRand1[ F, K, NP, D, Generations, list]\"",
	(char*)0,
	"\"DECurrentToRand1Bin[ F, CR, K, NP, D, Generations, list]\"",
	(char*)0,
	(char*)0
};
#define CARDOF_EVALSTRS 8

static int _definepattern P(( MLINK, char*, char*, int));

static int _doevalstr P(( MLINK, int));

int  _MLDoCallPacket P(( MLINK, struct func[], int));


#if MLPROTOTYPES
int MLInstall( MLINK mlp)
#else
int MLInstall(mlp) MLINK mlp;
#endif
{
	int _res;
	_res = MLConnect(mlp);
	if (_res) _res = _definepattern(mlp, "AOSoma[ Mass_Real,Step_Real,PRT_Real,NP_Integer,D_Integer,Migrations_Integer,AcceptedError_Real,list2:{___Real} ]", "{ Mass,Step,PRT,NP,D,Migrations,AcceptedError,list2 }", 0);
	if (_res) _res = _doevalstr( mlp, 0);
	if (_res) _res = _definepattern(mlp, "AORSoma[ Mass_Real,Step_Real,PRT_Real,NP_Integer,D_Integer,Migrations_Integer,AcceptedError_Real,list2:{___Real} ]", "{ Mass,Step,PRT,NP,D,Migrations,AcceptedError,list2 }", 1);
	if (_res) _res = _doevalstr( mlp, 1);
	if (_res) _res = _definepattern(mlp, "AASoma[ Mass_Real,Step_Real,PRT_Real,NP_Integer,D_Integer,Migrations_Integer,AcceptedError_Real,list2:{___Real} ]", "{ Mass,Step,PRT,NP,D,Migrations,AcceptedError,list2 }", 2);
	if (_res) _res = _doevalstr( mlp, 2);
	if (_res) _res = _definepattern(mlp, "ARSoma[ Mass_Real,Step_Real,PRT_Real,NP_Integer,D_Integer,Migrations_Integer,AcceptedError_Real,list2:{___Real} ]", "{ Mass,Step,PRT,NP,D,Migrations,AcceptedError,list2 }", 3);
	if (_res) _res = _doevalstr( mlp, 3);
	if (_res) _res = _definepattern(mlp, "DERand1Bin[ F_Real, CR_Real, NP_Integer, D_Integer, Generations_Integer, list:{___Real} ]", "{ F, CR, NP, D, Generations, list }", 4);
	if (_res) _res = _doevalstr( mlp, 4);
	if (_res) _res = _definepattern(mlp, "DERand1Exp[ F_Real, CR_Real, NP_Integer, D_Integer, Generations_Integer, list:{___Real} ]", "{ F, CR, NP, D, Generations, list }", 5);
	if (_res) _res = _doevalstr( mlp, 5);
	if (_res) _res = _definepattern(mlp, "DECurrentToRand1[ F_Real, K_Real, NP_Integer, D_Integer, Generations_Integer, list:{___Real} ]", "{ F, K, NP, D, Generations, list }", 6);
	if (_res) _res = _doevalstr( mlp, 6);
	if (_res) _res = _definepattern(mlp, "DECurrentToRand1Bin[ F_Real, CR_Real, K_Real, NP_Integer, D_Integer, Generations_Integer, list:{___Real} ]", "{ F, CR, K, NP, D, Generations, list }", 7);
	if (_res) _res = _doevalstr( mlp, 7);
	if (_res) _res = MLPutSymbol( mlp, "End");
	if (_res) _res = MLFlush( mlp);
	return _res;
} /* MLInstall */


#if MLPROTOTYPES
int MLDoCallPacket( MLINK mlp)
#else
int MLDoCallPacket( mlp) MLINK mlp;
#endif
{
	return _MLDoCallPacket( mlp, _tramps, 8);
} /* MLDoCallPacket */

/******************************* begin trailer ********************************/

#ifndef EVALSTRS_AS_BYTESTRINGS
#	define EVALSTRS_AS_BYTESTRINGS 1
#endif

#if CARDOF_EVALSTRS
static int  _doevalstr( MLINK mlp, int n)
{
	long bytesleft, charsleft, bytesnow;
#if !EVALSTRS_AS_BYTESTRINGS
	long charsnow;
#endif
	char **s, **p;
	char *t;

	s = evalstrs;
	while( n-- > 0){
		if( *s == 0) break;
		while( *s++ != 0){}
	}
	if( *s == 0) return 0;
	bytesleft = 0;
	charsleft = 0;
	p = s;
	while( *p){
		t = *p; while( *t) ++t;
		bytesnow = t - *p;
		bytesleft += bytesnow;
		charsleft += bytesnow;
#if !EVALSTRS_AS_BYTESTRINGS
		t = *p;
		charsleft -= MLCharacterOffset( &t, t + bytesnow, bytesnow);
		/* assert( t == *p + bytesnow); */
#endif
		++p;
	}


	MLPutNext( mlp, MLTKSTR);
#if EVALSTRS_AS_BYTESTRINGS
	p = s;
	while( *p){
		t = *p; while( *t) ++t;
		bytesnow = t - *p;
		bytesleft -= bytesnow;
		MLPut8BitCharacters( mlp, bytesleft, (unsigned char*)*p, bytesnow);
		++p;
	}
#else
	MLPut7BitCount( mlp, charsleft, bytesleft);
	p = s;
	while( *p){
		t = *p; while( *t) ++t;
		bytesnow = t - *p;
		bytesleft -= bytesnow;
		t = *p;
		charsnow = bytesnow - MLCharacterOffset( &t, t + bytesnow, bytesnow);
		/* assert( t == *p + bytesnow); */
		charsleft -= charsnow;
		MLPut7BitCharacters(  mlp, charsleft, *p, bytesnow, charsnow);
		++p;
	}
#endif
	return MLError( mlp) == MLEOK;
}
#endif /* CARDOF_EVALSTRS */


static int  _definepattern( MLINK mlp, char *patt, char *args, int func_n)
{
	MLPutFunction( mlp, "DefineExternal", (long)3);
	  MLPutString( mlp, patt);
	  MLPutString( mlp, args);
	  MLPutInteger( mlp, func_n);
	return !MLError(mlp);
} /* _definepattern */


int _MLDoCallPacket( MLINK mlp, struct func functable[], int nfuncs)
{
	long len;
	int n, res = 0;
	struct func* funcp;

	if( ! MLGetInteger( mlp, &n) ||  n < 0 ||  n >= nfuncs) goto L0;
	funcp = &functable[n];

	if( funcp->f_nargs >= 0
	&& ( ! MLCheckFunction(mlp, "List", &len)
	     || ( !funcp->manual && (len != funcp->f_nargs))
	     || (  funcp->manual && (len <  funcp->f_nargs))
	   )
	) goto L0;

	stdlink = mlp;
	res = (*funcp->f_func)( mlp);

L0:	if( res == 0)
		res = MLClearError( mlp) && MLPutSymbol( mlp, "$Failed");
	return res && MLEndPacket( mlp) && MLNewPacket( mlp);
} /* _MLDoCallPacket */


mlapi_packet MLAnswer( MLINK mlp)
{
	mlapi_packet pkt = 0;

	while( !MLDone && !MLError(mlp)
	&& (pkt = MLNextPacket(mlp), pkt) && pkt == CALLPKT){
		MLAbort = 0;
		if( !MLDoCallPacket(mlp)) pkt = 0;
	}
	MLAbort = 0;
	return pkt;
}



/*
	Module[ { me = $ParentLink},
		$ParentLink = contents of RESUMEPKT;
		Message[ MessageName[$ParentLink, "notfe"], me];
		me]
*/

static int refuse_to_be_a_frontend( MLINK mlp)
{
	int pkt;

	MLPutFunction( mlp, "EvaluatePacket", 1);
	  MLPutFunction( mlp, "Module", 2);
	    MLPutFunction( mlp, "List", 1);
		  MLPutFunction( mlp, "Set", 2);
		    MLPutSymbol( mlp, "me");
	        MLPutSymbol( mlp, "$ParentLink");
	  MLPutFunction( mlp, "CompoundExpression", 3);
	    MLPutFunction( mlp, "Set", 2);
	      MLPutSymbol( mlp, "$ParentLink");
	      MLTransferExpression( mlp, mlp);
	    MLPutFunction( mlp, "Message", 2);
	      MLPutFunction( mlp, "MessageName", 2);
	        MLPutSymbol( mlp, "$ParentLink");
	        MLPutString( mlp, "notfe");
	      MLPutSymbol( mlp, "me");
	    MLPutSymbol( mlp, "me");
	MLEndPacket( mlp);

	while( (pkt = MLNextPacket( mlp), pkt) && pkt != SUSPENDPKT)
		MLNewPacket( mlp);
	MLNewPacket( mlp);
	return MLError( mlp) == MLEOK;
}


int MLEvaluate( MLINK mlp, charp_ct s)
{
	if( MLAbort) return 0;
	return MLPutFunction( mlp, "EvaluatePacket", 1L)
		&& MLPutFunction( mlp, "ToExpression", 1L)
		&& MLPutString( mlp, s)
		&& MLEndPacket( mlp);
}


int MLEvaluateString( MLINK mlp, charp_ct s)
{
	int pkt;
	if( MLAbort) return 0;
	if( MLEvaluate( mlp, s)){
		while( (pkt = MLAnswer( mlp), pkt) && pkt != RETURNPKT)
			MLNewPacket( mlp);
		MLNewPacket( mlp);
	}
	return MLError( mlp) == MLEOK;
} /* MLEvaluateString */


#if __BORLANDC__
#pragma argsused
#endif

MLMDEFN( void, MLDefaultHandler, ( MLINK mlp, unsigned long message, unsigned long n))
{
#if !__BORLANDC__
	mlp = (MLINK)0; /* suppress unused warning */
	n = 0;          /* suppress unused warning */
#endif

	switch (message){
	case MLTerminateMessage:
		MLDone = 1;
	case MLInterruptMessage:
	case MLAbortMessage:
		MLAbort = 1;
	default:
		return;
	}
}



static int _MLMain( charpp_ct argv, charpp_ct argv_end, charp_ct commandline)
{
	MLINK mlp;
	long err;

	if( !stdenv)
		stdenv = MLInitialize( (MLParametersPointer)0);
	if( stdenv == (MLEnvironment)0) goto R0;

	if( !stdyielder)
		stdyielder = MLCreateYieldFunction( stdenv,
			NewMLYielderProc( MLDefaultYielder), 0);
	if( !stdhandler)
		stdhandler = MLCreateMessageHandler( stdenv,
			NewMLHandlerProc( MLDefaultHandler), 0);


	mlp = commandline
		? MLOpenString( stdenv, commandline, &err)
		: MLOpenArgv( stdenv, argv, argv_end, &err);
	if( mlp == (MLINK)0){
		MLAlert( stdenv, MLErrorString( stdenv, err));
		goto R1;
	}

	if( MLIconWindow){
		char textbuf[64];
		int len;
		len = GetWindowText(MLIconWindow, textbuf, sizeof(textbuf)-2);
		strcat( textbuf + len, "(");
		_fstrncpy( textbuf + len + 1, MLName(mlp), sizeof(textbuf) - len - 3);
		textbuf[sizeof(textbuf) - 2] = '\0';
		strcat( textbuf, ")");
		SetWindowText( MLIconWindow, textbuf);
	}

	if( MLInstance){
		if( stdyielder) MLSetYieldFunction( mlp, stdyielder);
		if( stdhandler) MLSetMessageHandler( mlp, stdhandler);
	}

	if( MLInstall( mlp))
		while( MLAnswer( mlp) == RESUMEPKT){
			if( ! refuse_to_be_a_frontend( mlp)) break;
		}

	MLClose( mlp);
R1:	MLDeinitialize( stdenv);
	stdenv = (MLEnvironment)0;
R0:	return !MLDone;
} /* _MLMain */


int MLMainString( charp_ct commandline)
{
	return _MLMain( (charpp_ct)0, (charpp_ct)0, commandline);
}

int MLMainArgv( char** argv, char** argv_end) /* note not FAR pointers */
{   
	static char FAR * far_argv[128];
	int count = 0;
	
	while(argv < argv_end)
		far_argv[count++] = *argv++;
		 
	return _MLMain( far_argv, far_argv + count, (charp_ct)0);

}

int MLMain( int argc, charpp_ct argv)
{
 	return _MLMain( argv, argv + argc, (charp_ct)0);
}
 
