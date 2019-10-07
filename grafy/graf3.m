% pouziti funkce errorbar
% k vykresleni grafu s chybovymi useckami

x=0:pi/10:pi;
y=sin(x);
e=std(y)*ones(size(x)); % funkce std - ochylka
errorbar(x,y,e)