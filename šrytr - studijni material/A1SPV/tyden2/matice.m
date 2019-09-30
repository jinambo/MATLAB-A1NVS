a=5
a=5;
a
a=3;
a
v=[5 8 2.1]
v=[5, 6.3, 2.1]
v2=[5; 8; 0.1] % sloupcový vektor - støedník vytvoøí nový sloupec
v2=[5;8;5.4] 
M=[5 8;8 5;5.4 8.5]
k=3 + 2i
v2=1:0.1:2 % mezdolni:krok:mezhorni
v3=linspace(1,2,11) %meze a pocet prvku
v4=rand(1,3) %radkovy
M1=rand(3)%ctverc. matice
M2=rand(3,2) %3 radky, 2 sloupce
M3=zeros(3,2)
M3=ones(3,2)
M3=eye(3)
%operace s maticemi:
N1=[3 6;4 5]
N2=[2 7;9 6]
S=N1+N2
S=N1-N2
S=N1*N2 %maticove
S=N1.*N2 %po prvcich
S=N1/N2 % maticove zprava
S=N2\N1 % maticove zleva
S=N1./N2 %po prvcich
S=N2.\N1 %po prvcich
%reste soustavu rovnic
%2x1 + 8x2 + x3 =3
%4x1 + 5x2 + 3x3=8
%9x1 + 7x2 + 4x3=5
A=[2 8 1; 4 5 3; 9 7 4]
b=[3 8 5]'
x=A\b
% nebo
x=inv(A)*b
S=N1^4 %maticove
S=N1.^4
S2=diag(b) %diagonalni matice
c1=length(S2) %vraci delku nejdelsi dimenze
c2=size(S2) %vraci delku kazde dimenze
% vypis prvku, promennych
a
a1=v(3)
v3=v2(8:10)
v4=v2([6,8,10])
v5=v2(6:end) % 6ty az posledni prvek
c=M2(3,1)% prvek z 3 radku a prvniho sloupce
c1=M2(:,1) %vsechny prvky 1.sloupce
c2=M2(2:end,:)% 2 az posledni radek a vsechny sloupce
c=cat(1,N1,N2) %slouceni pod sebe
c2=cat(2,N1,N2) % slouceni vedle sebe
numel(c2)%pocet prvku pole
min(c2)%nejmensi prvek po sloupcich
max(c2)%nevetsi prvek po sloupcich
vys1=det(N1) %determinant
vys1=inv(N1) % inverzni matice
vys2=N1' %transponovana matice
vys3=norm(N1) %norma matice
vys4=norm(N1,1) %norma matice 1. druhu
vys5=norm(N1,'fro') %Frobeniova norma matice
vys6=norm(N1,inf) %norma matice v nekonecnu
vys7=orth(N1) %orthogonalni matice
vys7=rank(N1) %hodnost matice
vys8=trace(N1) %stopa matice
vys9=cond(N1) %podminkove cislo
vys10=eig(N1) %vlastni cisla
%komplexni cisla
k=3+2j
%nebo
k=3+2i
abs(k)%absolutni hodnota
angle(k)%fazovy uhel
real(k)%realna cast
imag(k)%imaginarni cast
conj(k)%doplnek komplexniho cisla
%zaokrohlouvani
c5=3.7339
fix(c5) %k nule
floor(c5) % k - nekonecnu
ceil(c5) % k + nekonecnu
round(c5) % k nejblizsimu celemu
sign(c5) % funkce signum (1 pro kladna cisla, -1 pro zaporna)

help rem % napoveda
doc rem %napoveda v okne
rem(5,2) %zbytek po deleni
mod(5,2) %modul po deleni

%cos,cosh, cot, coth, csc, csch, sec, sech, sin, sinh, tan, tanh, acos ,,,
log(14)%prirozeny
log2(14)%binarni
log10(14)%dekadicky

%retezce
r='øetìzec'
clear all
r='21'
r1=str2double(r) %znak na cislo formatu double
r2=str2num(r)  %znak na cislo vychoziho formatu
r3=num2str(r2) %cislo na znak
r1='Dnes'
r2='možná skonèíme'
r3=strcat(r1,r2) %slouèení øetìzcù
r3=cat(2,r1,r2)
r4=regexprep(r3,'možná','urèitì') %nahrazeni mozna za urcite v retezci r3


