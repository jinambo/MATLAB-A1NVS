x=0:10
funkce=zeros(size(x));
for k=1:length(x)
    if x(k) >=5
        funkce(k)=sin(x(k));
    end
end
funkce