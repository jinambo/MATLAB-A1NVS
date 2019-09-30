% pouziti funkce contour3
% k vykresleni 3d vrstevnicoveho grafu

[x,y]=meshgrid([-2:.25:2]);  %generovani souradnic site v promennych x a y
z=x.*exp(-x.^2-y.^2)
contour3(x,y,z,30)
surface(x,y,z,'EdgeColor', [0.8 0.8 0.8],'FaceColor','none') % nastaveni barvy povrchu
grid off % zruseni mrizky
view(-15, 25) % nastaveni pohledu
colormap cool %nastaveni palety