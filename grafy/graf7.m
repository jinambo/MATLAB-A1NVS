% pouziti funkce polar
% k vykresleni grafu v polarnich souradnicich
% polar(uhel,polomer)
t=0:0.01:2*pi;
polar(t,sin(2*t).*cos(2*t),'-r')