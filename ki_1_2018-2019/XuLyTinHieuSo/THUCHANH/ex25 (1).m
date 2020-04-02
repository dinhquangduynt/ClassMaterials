
clf;
n = -5:5;
u = -5:5;

[u1, n1] = sigshift(u,n,3);
figure(1);
stem(n1,u1);
xlabel('n'); ylabel('x(n)');

[u2, n2] = sigshift(u,n,-2);
figure(2);
stem(n2,u2);
xlabel('n'); ylabel('x(n)');

 
function [y,n] = sigshift(x,m,k) 
    n = m + k;
    y = x;
end
