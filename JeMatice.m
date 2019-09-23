function JeMatice(c)
% JeMatice funkce zjistí, zda je na vstupu skalár, vektor èi matice a vypíše text

r = size(c);

if (r(1) == 1) && (r(2) == 1)
    disp('Vstup je skalar');
elseif (r(1) == 1) && (r(2) > 1) || (r(1) > 1) && (r(2) == 1)
    disp('Vstup je vektor'); 
elseif (r(1) > 1) && (r(2) > 1)
    disp('Vstup je matice'); 
else
    disp('Vstup není matice, skalár ani vektor'); 
    
end
