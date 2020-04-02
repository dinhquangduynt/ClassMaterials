L1 = 5;
L2 = 5;
n = -L1:L2;

u1 = [zeros(1,L1 + 3) ones(1,L2 - 2)];      % ham u(n-3)
subplot(1,2,1)
stem(n,u1)
title('u(n-3)');


u2 = [zeros(1,L1 - 2) ones(1,L2 + 3)];      % ham u(n+2)
subplot(1,2,2)
stem(n,u2)
title('u(n+2)');
