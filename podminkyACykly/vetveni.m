disp('Vyberte')
disp(' ')
disp('[1] Cola')
disp('[2] Džus')
disp(' ')
c=input(''); %vstup z klavesnice, pro nacteni cisel
switch c
    case 1
        disp('Vybral jste colu')
    case 2
        disp('Vybral jste dzus')
    otherwise
        disp('chyba')
end
disp(' ')
disp('Dalsi volba? [A/N]')
z=input('','s'); %pro nacteni znaku
switch upper(z)
    case 'A'
        vetveni
    case 'N'
        disp('konec programu')
    otherwise
        disp('chyba')
end
        
        