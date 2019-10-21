% Vytvoøte 3D graf funkce z = 3sin(2x)cos(3y) pro x z <0, pi>, krok pi/30
% a pro y z <0,2pi>, krok pi/15. Graf bude síovı, barevná paleta autumn, 
% azimut -45, elevace 10. Zobrazte popis grafu "Prùbìh funkce z", popis os
% "osa x", "osa y", "osa z", møíku a legendu.

[x, y] = meshgrid(0:pi/30:pi, 0:pi/15:2*pi);
z = 3*sin(2*x).*cos(3*y);
%z = times(3*sin(2*x), cos(3*y));

mesh(x,y,z)

grid on % s mrizkou
view([-45 10])
title('Prùbìh funkce z')
xlabel('osa x')
ylabel('osa y')
zlabel('osa z')
colormap autumn
legend('graf z')



