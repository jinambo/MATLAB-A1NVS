x=0:10;
funkce=zeros(size(x));
maska=(x>=5);
funkce(maska)=sin(x(maska));
funkce