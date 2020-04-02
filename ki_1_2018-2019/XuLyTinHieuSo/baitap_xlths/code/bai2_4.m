E1 = 0;
for i = 0:10  
    E1 = E1 + (1-2^i).^2; 
end
P1 = E1/(2*10+1);
 
%Nang luong tin hieu x(n) trong doan [0,1000]
E2 = 0;
for j = 0:1000
    E2 = E2 + (1-2^j)^2;
end
P2 = E2/1001;

%Nang luong tin hieu x(n) trong doan [0,1e6]
E3 = 0;
for k = 0:1000000
    E3 = E3 + (1-2^k)^2;
end
P3 = E3/1000001;
