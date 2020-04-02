clf;
L1=10;
L2=10;
n=-L1:L2;
d=[zeros(1,L1) 1 ones(1,L2)];
stem(n,d);
axis([-L1 L2 0 1.5]);
title('u(n)');