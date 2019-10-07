% pouziti funkce bar3
% k vykresleni 3d sloupcoveho grafu

x=-2.9:0.2:2.9
bar3(x,exp(-x.*x))
colormap hsv % barevna paleta typu hue-saturation
afterDraw %funkce z disku P, slozka vizualizace3d