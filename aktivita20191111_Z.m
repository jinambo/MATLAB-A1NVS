clc
% Vytvo�te skript, kter�:
% 
% 1. vy�e�� diferenci�ln� rovnici y'+2y=t^2*e^(-2t)+5, po��te�n� podm�nka
% y(0)=0.
syms y t

y(t) = dsolve('Dy + 2*y = t^2*exp(-2*t)+5','y(0)=0','t')

% 2. �e�en� diferenci�ln� rovnice bude zobrazeno graficky pro t z intervalu 
% 0 a� 10 s krokem 1/10.

t = 0:1/10:10;
y1 = y(t);

plot(t, y1)