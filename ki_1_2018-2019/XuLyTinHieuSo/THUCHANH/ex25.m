
clf;
n = -5:5;
u = -5:5;

[u1, n1] = sigshift(u,n,3);
figure(1);
stem(n1,u1);
xlabel('n'); ylabel('x(n)');

