figure
subplot(1,2,1)
ezplot3('t','sin(t)','cos(3*t).*sin(8*t)',[0,6*pi])
view(-50,60)
subplot(1,2,2)
[x,y]=meshgrid(-3:0.001:3);
z = 3*sin(x)+cos(3*x)+sin(8*y)+y.*y;
surface(x,y,z,'EdgeColor','none')
colormap hsv
view(-60,30)