n = -10:10;
n1 = 0:10;
x = (1/2).^n1;
delta = [zeros(1,10) x];
stem(n,delta);
figure;

x2 = 3.^n1;
delta2 = [zeros(1,10) x2];
stem(n, delta2);

