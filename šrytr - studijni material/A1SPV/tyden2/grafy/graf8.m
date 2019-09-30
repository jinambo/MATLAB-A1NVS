% pouziti funkce area
% k vykresleni plosneho grafu

y=[1 5 3; 3 2 7; 1 5 3; 2 6 1]
area(y)
grid on %zobrazeni mrizky
colormap summer %nastaveni barevne palety
set(gca,'Layer','top') %aby se neprekryvaly prubehy
title('Plosny graf') %nadpis grafu