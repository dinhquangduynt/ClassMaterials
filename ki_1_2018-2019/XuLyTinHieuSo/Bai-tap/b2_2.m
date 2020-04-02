L1 = 5;
L2 = 5;
n = -L1:L2;
u = [zeros(1,L1) ones(1,L2 + 1)];  % ham u(n)

v1 = ((1/2).^n).*u;  % ham v(n) = (1/2)^n* u(n)
subplot(1,2,1)
stem(n,v1)
title('(1/2)^n*u(n)');

v2 = (3.^n).*u; %v2(n) = 3^nu(n)
subplot(1,2,2)
stem(n,v2)
title('3^n*u(n)');
