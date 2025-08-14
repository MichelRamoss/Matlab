%%Practica 2 - 0/12/18
%%Minimos Cuadrados

clc;
close all;
clear all;

inf = load('Datos_1_1.txt');
inf1 = load('Datos_1_2.txt');
figure(1)
plot(inf(1,:),inf(2,:),'r.');
hold on;
grid on;
x=inf(1,:);
x1=inf1(1,:);
y=inf(2,:);
y1=inf1(2,:);
plot(x1,y1,'b.');

%%Regresion lineal en todo el rango
nm = length(y1);
nt=1;
n=20;
c=floor(nm/n);
ini=1;
fin=0;
for i=1:n
    fin=fin+c;
    [B,f1]=MC(x(ini:fin),y(ini:fin),nt);
    yp=f1(x1(ini:fin));
    ea(ini:fin)=(y1(ini:fin)-yp).^2/c;
    xt=x(ini):0.001:x(fin);
    ini=fin;
yt=f1(xt);
plot(xt,yt,'b-');
end
xlabel('x');
ylabel('y');
title('n sepmentos lineal');
print('-f1', '-djpeg90', '-r300', 'Grafica1n.jpg');
hold off;

one= ones(nm,1);
et= ea*one;

%%Para un modelo de 5 segmentos 
figure(2)
plot(inf(1,:),inf(2,:),'r.');
hold on;
plot(x1,y1,'b.');
grid on;
x=inf(1,:);
x1=inf1(1,:);
y=inf(2,:);
y1=inf1(2,:);
nm = length(y1);
nt=5;
    fin=fin+c;
    [B,f1]=MC(x,y,nt);
    yp=f1(x1);
    ea=(y1-yp).^2/c;
    xt=x(1):0.001:x(end);
yt=f1(xt);
plot(xt,yt,'b-');
hold off;
xlabel('x');
ylabel('y');
title('Para modelo de 5 segmentos');
print('-f2', '-djpeg90', '-r300', 'Grafica4.jpg');
hold off;

%%Regresion n para un modelo Cuadratico
figure(3)
plot(inf(1,:),inf(2,:),'r.');
hold on;
plot(x1,y1,'b.');
grid on;
x=inf(1,:);
x1=inf1(1,:);
y=inf(2,:);
y1 = inf1(2,:);
nm = length(y1);
nt=2;
n=20;
c=floor(nm/n);
ini=1;
fin=0;
for i=1:n
    fin=fin+c;
    [B,f1]=MC(x(ini:fin),y(ini:fin),nt); 
    yp=f1(x1(ini:fin));
    ea2(ini:fin)=(y1(ini:fin)-yp).^2/c;
    xt=x(ini):0.001:x(fin);
    ini=fin;
yt=f1(xt);
plot(xt,yt,'b-');
end
one= ones(nm,1);
et2= ea2*one;
xlabel('x');
ylabel('y');
title('Para n segmentos cuadrado');
print('-f3', '-djpeg90', '-r300', 'Grafica2n.jpg');
hold off;


%%Para un modelo Cuadratico
figure(4)
plot(inf(1,:),inf(2,:),'r.');
hold on;
plot(x1,y1,'b.');
grid on;
x=inf(1,:);
x1=inf1(1,:);
y=inf(2,:);
y1=inf1(2,:);
nm = length(y1);
nt=2;
    fin=fin+c;
    [B,f1]=MC(x,y,nt);
    yp=f1(x1);
    ea=(y1-yp).^2/c;
    xt=x(1):0.001:x(end);
yt=f1(xt);
plot(xt,yt,'b-');
xlabel('x');
ylabel('y');
title('Para modelo cuadrado');
print('-f4', '-djpeg90', '-r300', 'Grafica2.jpg');
hold off;


%%Para n segmentos cubicos
figure(5)
plot(inf(1,:),inf(2,:),'r.');
hold on;
plot(x1,y1,'b.');
grid on;
x=inf(1,:);
x1=inf1(1,:);
y=inf(2,:);
y1=inf1(2,:);
nm = length(y1);
nt=3;
n=20;
c=floor(nm/n);
ini=1;
fin=0;
for i=1:n
    fin=fin+c;
    [B,f1]=MC(x(ini:fin),y(ini:fin),nt);
    yp=f1(x1(ini:fin));
    ea3(ini:fin)=(y1(ini:fin)-yp).^2/c;
    xt=x(ini):0.001:x(fin);
    ini=fin;
yt=f1(xt);
plot(xt,yt,'b-');
end
one= ones(nm,1);
et3= ea3*one;
xlabel('x');
ylabel('y');
title(' Para n segmentos cubico');
print('-f5', '-djpeg90', '-r300', 'Grafica3n.jpg');
hold off;

%%Para un modelo Lineal
figure(6)
plot(inf(1,:),inf(2,:),'r.');
hold on;
plot(x1,y1,'b.');
grid on;
x=inf(1,:);
x1=inf1(1,:);
y=inf(2,:);
y1=inf1(2,:);
nm = length(y1);
nt=1;
n=20;
    fin=fin+c;
    [B,f1]=MC(x,y,nt);
    yp=f1(x1);
    ea=(y1-yp).^2/c;
    xt=x(1):0.001:x(end);
yt=f1(xt);
plot(xt,yt,'b-');
xlabel('x');
ylabel('y');
title('Para un modelo lineal');
print('-f6', '-djpeg90', '-r300', 'Grafica1.jpg');
hold off;

%%Para un modelo cubico
figure(7)
plot(inf(1,:),inf(2,:),'r.');
hold on;
plot(x1,y1,'b.');
grid on;
x=inf(1,:);
x1=inf1(1,:);
y=inf(2,:);
y1=inf1(2,:);
nm = length(y1);
nt=3;
    fin=fin+c;
    [B,f1]=MC(x,y,nt);
    yp=f1(x1);
    ea=(y1-yp).^2/c;
    xt=x(1):0.001:x(end);
yt=f1(xt);
plot(xt,yt,'b-');
hold off;
xlabel('x');
ylabel('y');
title('Para modelo cubico');
print('-f7', '-djpeg90', '-r300', 'Grafica3.jpg');
hold off;
