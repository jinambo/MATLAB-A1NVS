% pouziti funkce loglog
% k vykresleni grafu v logaritmicko-logaritmickych souradnicich

x=logspace(-1,2); %generovani bodu v logaritmickem prostoru
loglog(x,exp(x),'-s') % body budou ctverce, cara bude plnou carou
grid on % s mrizkou