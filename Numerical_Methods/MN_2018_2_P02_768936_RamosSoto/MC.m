function [B,f1]=MC(x,y,ni)
nt=ni;
n=nt+1;
nx=nt*2;
nm = length(x);
for i=2:(nx)
    x(i,:)=x(1,:).^i;
end

for i=2:n
    y(i,:)=y(1,:).*x(i-1,:);
end
one=ones(nm,1);
xs=zeros(nx,1);
ys=zeros(n,1);
for i=1:nx
    xs(i,1)=x(i,:)*one;
end
for i=1:n
    ys(i,1)=y(i,:)*one;
end
M=ones(n);
M(1,1)=nm;
M(1,2:end)=xs(1:n-1);
j=n-1;
for i=2:n
    j=j+1;
    M(i,1:end)=[M(i-1,2:end) xs(j)];
end

B=LU(M,ys);
f=poly2sym(fliplr(B'));
f1=inline(f);
end