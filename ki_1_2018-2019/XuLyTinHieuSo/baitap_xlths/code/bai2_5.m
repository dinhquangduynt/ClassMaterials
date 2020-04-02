L1 = 10;
L2 = 10;
n = -L1:L2;

%figure(1)
u1 = [zeros(1,L1 + 3) 1 ones(1,L2 - 3)];      % ham u(n-3)
subplot(2,1,1)
stem(n,u1);
title('u(n-3)');
xlabel('chi so thoi gian n');
ylabel('bien do');
axis([-L1 L2 0 1.2]);%dat gioi han truc x tu -L1:L2 va truc y tu 0:1.2

%figure(2)
u2 = [zeros(1,L1 - 2) 1 ones(1,L2 + 2)];      % ham u(n+2)
subplot(2,1,2)
stem(n,u2);
title('u(n+2)');
xlabel('chi so thoi gian n');
ylabel('bien do');
axis([-L1 L2 0 1.2]);%dat gioi han truc x tu -L1:L2 va truc y tu 0:1.2