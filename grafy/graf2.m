% pouziti funkce plotyy
% k vykresleni dvou y-ových os do jednoho grafu

X=0:0.01:20;
Y1=200*exp(-0.05*X).*sin(X);
Y2=0.8*exp(-0.5*X).*sin(10*X);
[AX, H1, H2]=plotyy(X,Y1, X,Y2,'plot')
set(get(AX(1),'Ylabel'),'string', 'Levá y-ová osa')
set(get(AX(2),'Ylabel'),'string', 'Pravá y-ová osa')
xlabel('Nula až 20\musec')
title('Oznaèení os')
set(H1,'LineStyle','--')
set(H2,'LineStyle',':')