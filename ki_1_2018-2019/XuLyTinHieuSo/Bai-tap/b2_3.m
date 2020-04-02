%x(n) = ((1/2)^n)u(n)


%Nang luong tin hieu x(n) trong doan [-10,10]
%Cong thuc: En = ∑ |x (n)| 2 (chay tu -N den N)
E1 = 0;
for i = 0:10  %vi u(n) = 0 khi n < 0 -> x(n) = 0
    E1 = E1 + (1/2)^(2*i); %vi u(n) = 1 khi n >= 0
end
 
%Nang luong tin hieu x(n) trong doan [0,1000]
%Cong thuc: En = ∑ |x (n)| 2 (chay tu 0 den N )
E2 = 0;
for i = 0:1000
    E2 = E2 + (1/2)^(2*i);
end

%Nang luong tin hieu x(n) trong doan [0,1e6]
%Cong thuc: En = ∑ |x (n)| 2 (chay tu 0 den N )
E3 = 0;
for i = 0:1000000
    E3 = E3 + (1/2)^(2*i);
end

