
clf;
n = -10:10;

x = 2*stepseq(3,-10,10) + impseq(2,-10,10);
figure(1);
stem(n,x);
xlabel('n'); ylabel('x(n)');

y1 = sigfold(x,n);
figure(2);
stem(n,y1);
xlabel('n'); ylabel('x(-n)');

y2 = 2.*x;
figure(3);
stem(n,y2);
xlabel('n'); ylabel('2x(n)');

n1 = 2.*n;
figure(4);
stem(n1,x);
xlabel('n'); ylabel('x(2n)');

% xung don vi x(n) = g(n-n0) n: n1->n2
function [g,n] = impseq(n0,n1,n2)
     n = n1:n2; 
     g = (n-n0) == 0;
end

% xung nhay bac x(n) = u(n-n0) n: n1->n2
function [u,n] = stepseq(n0,n1,n2)
     n = n1:n2; 
     u = (n-n0) >= 0;
end

%x(-n)
function [y,n] = sigfold(x,n) 
    y = fliplr(x);
    n = -fliplr(n);
end