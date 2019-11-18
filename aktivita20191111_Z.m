clc
% Vytvoøte skript, který:
% 
% 1. vyøeší diferenciální rovnici y'+2y=t^2*e^(-2t)+5, poèáteèní podmínka
% y(0)=0.
syms y t

y(t) = dsolve('Dy + 2*y = t^2*exp(-2*t)+5','y(0)=0','t')

% 2. Øešení diferenciální rovnice bude zobrazeno graficky pro t z intervalu 
% 0 až 10 s krokem 1/10.

t = 0:1/10:10;
y1 = y(t);

plot(t, y1)