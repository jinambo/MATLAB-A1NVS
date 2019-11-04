clc
syms x y%definice symbolickych promennych
derivace=diff(x*sin(x)*exp(2*x),'x') %derivace podle x
v1=collect(derivace) %zjednoduseni vypisu
v2=simplify(derivace) %zjednoduseni vypisu
%v3=pretty(derivace) %zjednoduseni vypisu
der3=diff(x*sin(x)*exp(2*x),'x',3) %3.derivace podle x
i1=int(3*x/(4+5*x^3),'x') %neurcity integral, dx 
i2=int(3*x/(4+5*x^3),'x',0,1) 
%urcity integral od 0 do 1, dx 
i3=int(3*x*y/(4+5*x^3),'y') 
lim1=limit(x^3-2*x^2+1) %limita
lim2=limit(x^3-2*x^2+1,x,2,'right') %limita pro x=2 zprava
lim3=limit(x^3-2*x^2+1,x,1,'left') %limita pro x=1 zleva
t1=taylor(3*x/(4+5*x^3)+2*x)%rozvoj v Taylorovu radu
t2=taylor(3*x/(4+5*x^3)+2*x,6)
%rozvoj v Taylorovu radu, maximalne 6 prvku rady
t2=taylor(3*x/(4+5*x^3)+2*x,2)
%rozvoj v Taylorovu radu, maximalne 2 prvky rady
%funtool %dialog pro symbolicke operace
%Laplaceova transformace (laplace):
syms t
laplace(3*exp(-4*t)*sin(2*t))
laplace(2*sin(3*t)+4*exp(-2*t))
%zpetna Laplaceova transformace (ilaplace):
syms s
ilaplace((s+1)/(s^2+7*s+12))
ilaplace(3/(s^3+9*s^2+26*s+24))
%reseni soustavy algebraickych rovnic (solve):
syms a b x y
promenna=solve('3*x+a*y=7','b*x+9*y=11','x','y')
promenna.x %vypis reseni - promenna x pouze
%reseni obycejne diferencialni rovnice nebo soustavy
%obycejnych diferencialnich rovnic (dsolve):
dsolve('D2y+2*Dy+y=3','x') %pro nezavisle promennou x
dsolve('D2y+2*Dy+y=3','y(0)=1','x') %pocatec. podminky
dsolve('D2y+2*Dy+y=3','Dy(0)=0,y(0)=1','x') %pocatec. podminky
res=dsolve('D2y+3*Dx+y=5,D2x+7*Dy+11*x=6',...
    'Dy(0)=0,y(0)=1,Dx(0)=0,x(0)=1')
%reseni soustavy diferencialnich rovnic
	 %volani funkce Maplu
%v apostrofech je funkce a za ni je carkou oddelen
% argument funkce
mhelp euler%napoveda k funkci Maplu
mfunlist %seznam funkci Maplu

