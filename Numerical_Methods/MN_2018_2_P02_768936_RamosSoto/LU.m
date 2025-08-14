function x=LU(A,b)
[N, M] = size(A);
L = eye(N, M);
U = A;
Ld = b;
D=det(A);
for i=1:N
    j=i;
    while j<=N
        if U(i,j)<0.00000000000001
            j=j+1;
        else
            break;
        end
     U([i j],:)=U([j i],:); 
     Ld([i j])=Ld([j i]);
    end
end

for i1=1:(M-1)
    for i2=(i1+1):N
        fct=U(i2,i1)/U(i1,i1);
        U(i2,:)=U(i2,:)-U(i1,:)*fct;
        Ld(i2)=Ld(i2)-Ld(i1)*fct;
        L(i2,i1)=fct;
    end
end
 
x = U\Ld;
 