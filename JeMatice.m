function JeMatice(c)
% Fu JeMatice zisti cu vstupna premenna je skalar alebo vektor alebo matica
r = size(c); % Do premennej r ulozim rozmer vstupnej premennej
% a potlacim vypis do command window pomoci medzeri

if (r(1) == 1) && (r(2) == 1)
    disp('Vstup je skalar')
elseif ((r(1) == 1) && (r(2) > 1)) || ((r(1) > 1) && (r(2) == 1))
    disp('Vstup je vektor')
elseif (r(1) > 1) && (r(2) > 1)
    disp('Vstup je Matica')
else 
    disp('Vstup neni ani skalar, ani vektor a ani matica.')
end

