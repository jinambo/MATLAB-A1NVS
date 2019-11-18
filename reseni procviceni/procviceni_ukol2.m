clear all
clc
disp('Vyberte:')
disp('[1] animace')
disp('[2] výpoèet objemu kvádru')

h = input('');

switch h
    case 1
        x = 0:pi/100:pi;
        y = 8*sin(9*x)+cos(10*x);
        b = 11;
        figure
        plot(x,y)
        hold on
        for a = 1:10
            b = b-1;
            y = 8*sin(9*x)+a.*cos(b.*x);
            plot(x,y,'Color',[0.5 0+0.1.*a 1-0.1.*b])
            pause(1)
        end
    case 2
        strana_a = input('Zadejte stranu a');
        strana_b = input('Zadejte stranu b');
        c = strana_a*strana_a*strana_b;
        vysledek = strcat('Objem kvádru je ',num2str(c));
        disp(vysledek)
    otherwise
        warndlg('Chyba 1')
end
opakovat = input('Opakovat [Ano/Ne]?','s');
switch upper(opakovat)
    case {'A','ANO'}
           procviceni_ukol2 %nazev tohoto souboru
    case {'N','NE'}
        return
    otherwise
      warndlg('Chyba 2')
end
