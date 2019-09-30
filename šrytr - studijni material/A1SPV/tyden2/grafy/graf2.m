% pouziti funkce plotyy
% k vykresleni dvou y-ov�ch os do jednoho grafu

X=0:0.01:20;
Y1=200*exp(-0.05*X).*sin(X);
Y2=0.8*exp(-0.5*X).*sin(10*X);
[AX, H1, H2]=plotyy(X,Y1, X,Y2,'plot')
set(get(AX(1),'Ylabel'),'string', 'Lev� y-ov� osa')
set(get(AX(2),'Ylabel'),'string', 'Prav� y-ov� osa')
xlabel('Nula a� 20\musec')
title('Ozna�en� os')
set(H1,'LineStyle','--')
set(H2,'LineStyle',':')