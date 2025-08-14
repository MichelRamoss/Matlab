%%Practica 2 - 07/12/18
%%Interpolacion 2D

clc;
close all;
clear all;
x1=load('Datos_3_2.txt');
y1=load('Datos_3_1.txt');
[n np]=size(x1);
figure(1)
mesh(y1(1,:), y1(2,:), y1(3:end,:));
grid on;
xlabel('x');
ylabel('y');
title('3D');
print('-f1', '-djpeg90', '-r300', 'GraficaID1.jpg');
 
figure(2)
mesh(y1(1,:), y1(2,:), y1(3:end,:));
hold on;
for i=1:np
    x(i,:)=x1(1,:);
    x2(i,:)=x1(2,:);
end
xi=x1(1,:);
xi2=x1(2,:);
yi=y1(1,:);
yi2= y1(2,:);
    plot3(x, x2', x1(3:end,:),'b.');
    mesh(y1(1,:), y1(2,:), y1(3:end,:));
grid on;
xlabel('x');
ylabel('y');
title('3D');
print('-f2', '-djpeg90', '-r300', 'GraficaID2.jpg');
 
%%
xi=x1(1,:);
xi2=x1(2,:);
yi=y1(1,:);
yi2= y1(2,:);
fxy=y1(3:end,:);
fxy2=x1(3:end,:);
incx=yi(2)-yi(1);
incy=yi2(2)-yi2(1);
nm=1;
for i=1:np
    for j=1:np
        yp=xi2(j);
        xp=xi(i);
       [it,xt]=interp2(yi,xp,incx);
       [it2,yt]=interp2(yi2,yp,incy);
        n=length(xt);
        for k=1:n
            p(2,k)=interp2([yi;fxy(:,it2(k))'],xp,nm);
        end
        p(1,:)=yi(it2);
        fxyp(i,j)=interp2(p,yp,nm);
    end
end
for i=1:n
    ea(i,:)=(fxyp(i,:)-fxy2(i,:)).^2;
end
et=0;
for i=1:n
    et=et+sum(ea(i,:))/(n*n);
end
    figure(3)
    plot3(x, x2', fxyp,'g.');
    hold on;
    plot3(x, x2', x1(3:end,:),'b.');
    mesh(y1(1,:), y1(2,:), y1(3:end,:));
    xlabel('x');
    ylabel('y');
    title('3D');
    grid on;
    print('-f3', '-djpeg90', '-r300', 'GraficaID3.jpg');
 
    nm=2;
for i=1:np
    for j=1:np
        yp=xi2(j);
        xp=xi(i);
       [it,xt]=interp2(yi,xp,incx);
       [it2,yt]=interp2(yi2,yp,incy);
        n=length(xt);
        for k=1:n
            p(2,k)=interpn([yi;fxy(:,it2(k))'],xp,nm);
        end
        p(1,:)=yi(it2);
        fxyp2(i,j)=interp2(p,yp,nm);
    end
end
 
for i=1:n
    ea(i,:)=(fxyp2(i,:)-fxy2(i,:)).^2;
end
et2=0;
for i=1:n
    et2=et2+sum(ea(i,:))/(n*n);
end
    figure(4)
    plot3(x, x2', fxyp2,'g.');
    hold on;
    plot3(x, x2', x1(3:end,:),'b.');
    mesh(y1(1,:), y1(2,:), y1(3:end,:));
    xlabel('x');
    ylabel('y');
    title('3D');
    grid on;
    print('-f4', '-djpeg90', '-r300', 'GraficaID4.jpg');
 
    nm=3;
for i=1:np
    for j=1:np
        yp=xi2(j);
        xp=xi(i);
       [it,xt]=interp2(yi,xp,incx);
       [it2,yt]=interp2(yi2,yp,incy);
        n=length(xt);
        for k=1:n
            p(2,k)=interp2([yi;fxy(:,it2(k))'],xp,nm);
        end
        p(1,:)=yi(it2);
        fxyp3(i,j)=interp2(p,yp,nm);
    end
end
for i=1:n
    ea(i,:)=(fxyp3(i,:)-fxy2(i,:)).^2;
end
et3=0;
for i=1:n
    et3=et3+sum(ea(i,:))/(n*n);
end
    figure(5)
    plot3(x, x2', fxyp3,'g.');
    hold on;
    plot3(x, x2', x1(3:end,:),'b.');
    mesh(y1(1,:), y1(2,:), y1(3:end,:));
    xlabel('x');
    ylabel('y');
    title('3D');
    grid on;
    print('-f5', '-djpeg90', '-r300', 'GraficaID5.jpg');
