sim('ukol5_model',[0 30])
figure
plot(u.time,u.signals.values,y.time,y.signals.values)
xlabel('�as (s)')
title('Pr�b�h simulace')