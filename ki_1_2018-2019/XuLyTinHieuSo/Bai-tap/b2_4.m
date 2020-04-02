%x(n) = (1-2^n)u(n)

%Nang luong va cong suat tin hieu x(n) trong doan [-10,10]
%Cong thuc: En = ∑ |x (n)| 2 (chay tu -N den N)
%P = E/(2N+1)
E1 = 0;
for i = 0:10  %vi u(n) = 0 khi n < 0 -> x(n) = 0
    E1 = E1 + (1-2^i)^2; %vi u(n) = 1 khi n >= 0
end
P1 = E1/(2*10+1);
 
%Nang luong tin hieu x(n) trong doan [0,1000]
%Cong thuc: En = ∑ |x (n)| 2 (chay tu 0 den N )
%P = E/N
E2 = 0;
for i = 0:1000
    E2 = E2 + (1-2^i)^2;
end
P2 = E2/1001;

%Nang luong tin hieu x(n) trong doan [0,1e6]
%Cong thuc: En = ∑ |x (n)| 2 (chay tu 0 den N - 1)
%P = E/N
E3 = 0;
for i = 0:1000000
    E3 = E3 + (1-2^i)^2;
end
P3 = E3/1000001;
