%%Practica 2 - 07/12/18
%%Interpolacion 1D

clc;
close all;
clear all;

x1=load('Datos_2_2.txt');
y1=load('Datos_2_1.txt');
inc=0.1;
np = length(y1);
y=y1(1,:);
fx1=y1(2,:);
for i1=1:np
    xp = x1(1,i1);
    x=interpn(y1,xp,1);
   interli(1,i1) = x;
end
ea=(x1(2,:)-interli).^2/np;
one=ones(np,1);
et=ea*one;
figure(1);
plot(x1(1,:),x1(2,:),'r.',y1(1,:),y1(2,:),'b.',x1(1,1:end),interli,'g.');
grid on;
xlabel('x');
ylabel('y');
title('Interpolacion lineal');
print('-f1', '-djpeg90', '-r300', 'GraficaI1.jpg');
 
 
 
fx = zeros(1,np);
for i1=1:np 
    xp = x1(1,i1);
    x=interpn(y1,xp,2);
   interli2(1,i1) = x;
end
ea=(x1(2,1:end)-interli2).^2/np;
one=ones(np,1);
et2=ea*one;
figure(2);
plot(x1(1,:),x1(2,:),'r.',y1(1,:),y1(2,:),'b.',x1(1,1:end),interli2,'g.');
grid on;
xlabel('x');
ylabel('y');
title('Interpolacion Cuadrada');
print('-f2', '-djpeg90', '-r300', 'GraficaI2.jpg');
 
for i1=1:np
    xp = x1(1,i1);
    x=interpn(y1,xp,3);
   interli3(1,i1) = x;
end
ea=(x1(2,1:end)-interli3).^2/np;
one=ones(np,1);
et3=ea*one;
figure(3);
plot(x1(1,:),x1(2,:),'r.',y1(1,:),y1(2,:),'b.',x1(1,1:end),interli3,'g.');
grid on;
xlabel('x');
ylabel('y');
title('Interpolacion Cubica');
print('-f3', '-djpeg90', '-r300', 'GraficaI3.jpg');
 
 
for i1=1:np
    xp = x1(1,i1);
    x=interpn(y1,xp,4);
   interli4(1,i1) = x;
end
ea=(x1(2,1:end)-interli4).^2/np;
one=ones(np,1);
et4=ea*one;
figure(4);
plot(x1(1,:),x1(2,:),'r.',y1(1,:),y1(2,:),'b.',x1(1,1:end),interli3,'g.');
grid on;
xlabel('x');
ylabel('y');
title('Interpolacion Cuarta');
print('-f4', '-djpeg90', '-r300', 'GraficaI4.jpg');

