clf;
L1=10;
L2=10;
n=-L1:L2;
F=[zeros(1,L1) 1 ones(1,L2)];

figure(1);
u1=((1/2).^n).*F;
stem(n,u1);
axis([-L1 L2 0 1.2]);
title('(1/2)^n*u(n)');
xlabel('chi so thoi gian n');
ylabel('bien do');


figure(2);
u2=(3.^n).*F;
stem(n,u2);
axis([-L1 L2 0 1.2]);
title('3^n*u(n)');
xlabel('chi so thoi gian n');
ylabel('bien do');
