%nang luong va cong suat cua tin hieu x(n) trong doan [-10:10]
%vi n<0 thi tin hieu u(n)=0 nen chi xet voi >0
E1=0;
for i=0:10
    E1=E1+(1/2)^(2*i);
end;
P1=E1/(2*10+1);
%nang luong va cong suat cua tin hieu x(n) trong doan 0:1000

E2=0;
for j=0:1000
    E2=E2+(1/2)^(2*j);
end;
P2=E2/(1000+1);

%nang luong va cong suat cua tin hieu x(n) trong doan 0:1000000
E3=0;
for k=0:1000000;
    E3=E3+(1/2)^(2*k);
end;
P3=E3/(1000000+1);