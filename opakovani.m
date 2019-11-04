% soustava rovnic
A=[3 7 4; 5 -2 8; 9 1 -6]
b=[11 13 9]'

x=A\b


M = [2 3 5; 7 8 1; 9 2 4]

% nahodna cela cisla v intervalu 3 - 11
N = 3 + (11-3).*rand(3,3)

soucinMatic = M * N
determinantMatice = det(M)
transponovanaMatice = N'
vlastniCislaMatice = eig(M)
umocnenaMatice = N .* N
mKratsi=M(2:end, :) 
prvniPrvek=N(1,1)
sestyPrvek=N(2,3)
sedmyPrvek=N(3,1)
devatyPrvek=N(3,3)
minimum = min(min(N))
delkaDimenze = size(N)

