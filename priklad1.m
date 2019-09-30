% Príklad 1
x = 0 : 0.1 : 2*pi; % naplnenie riadkoveho vektoru X 
% hodnotami 0 a 6.2 s krokom 0.1
y = sin(x) % Vypocet funkcnych hodnot sin pre vstupne hodnoty nacitane
% z vektorov x a ulozene do vektoru y
plot (x,y) % Vykreslenie funkcie sin, nezavysle premenna x, zavisle premenna y