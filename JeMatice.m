function JeMatice(c)
% JeMatice funkce zjist�, zda je na vstupu skal�r, vektor �i matice a vyp�e text

r = size(c);

if (r(1) == 1) && (r(2) == 1)
    disp('Vstup je skalar');
elseif (r(1) == 1) && (r(2) > 1) || (r(1) > 1) && (r(2) == 1)
    disp('Vstup je vektor'); 
elseif (r(1) > 1) && (r(2) > 1)
    disp('Vstup je matice'); 
else
    disp('Vstup nen� matice, skal�r ani vektor'); 
    
end
