figure
x=0:pi/20:2*pi; y=sin(4*x)+cos(3*x);subplot(2,2,1); plot(x,y,'r--')
y=sin(3*x)-cos(4*x);subplot(2,2,2); plot(x,y,'-g*')
subplot(2,2,3); ezplot('exp(3*x)*sin(4*x)')

figure
[x,y]=meshgrid(-2:0.05:2);
z=sin(3*x)+cos(5*y);
contour3(x,y,z,30); view(-10, 30) ; colormap summer
pause(5)
mesh(x,y,z); view(-10, 30) ; colormap summer
pause(5)
meshc(x,y,z); view(-10, 30) ; colormap summer
pause(5)
surf(x,y,z);  view(-10, 30) ; colormap summer
set(findobj(gca,'type','surface'),'EdgeColor','none')
afterDraw;