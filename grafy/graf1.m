% pouziti funkce plot
% k vykresleni krivek ve 2D

t=0:pi/20:2*pi; % vektor od 0 do 2*pi - krok po pi/20
plot(t,sin(t),'-.r*') %cechovana, cervene, body jsou hvezdicky
hold on
plot(sin(t-pi/2),'--mo') %carkovana, fialove, body jsou kolecka
plot(sin(t-pi),':bs') %teckovana, modre, body jsou ctverce

%upreseni stylu vykreslovani - 3. parametr, tvoøí jej 3 èásti, 
% tj. styl krivky, barva a tvar bodù
% styl krivky:
% - plna cara
% -- carkovana
% -. cerchovana
% : teckovana
% barva:
% r cervena
% g zelena
% b modra
% c svetle modra
% m fialova
% y zluta
% k cerna
% w bila
% tvar bodu:
% + plus
% o kolecko
% * hvezdicka
% . bod
% x kriz
% s ctverec
% d kosoctverec
% ^ horni trojuhelnik
% > pravobodovy trojuhelnik
% < levobodovy trojuhelnik
% p peticipa hvezda
% h sesticipa hvezda