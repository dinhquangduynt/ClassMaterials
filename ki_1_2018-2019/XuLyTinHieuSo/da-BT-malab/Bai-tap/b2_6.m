%  x(n) = 2u(n - 3) + d(n - 2) 
L1 = 10;
L2 = 10;
n = -L1:L2;

u = [zeros(1,L1 + 3) ones(1,L2 - 2)];         % ham u(n-3)
d = [zeros(1,L1 + 2) 1 zeros(1,L2 - 2)];      % ham s(n-2)
x = 2*u + d;

% ve dang tin hieu cua x(n)
subplot(4,1,1)
stem(n,x)
title('x(n)');

%ve dang tin hieu cua 2x(n)
x1 = 2*x;
subplot(4,1,2)
stem(n,x1)
title('2x(n)');

%ve dang tin hieu cua x(-n)
x2 = fliplr(x);
subplot(4,1,3)
stem(n,x2)
title('x(-n)');

% ve dang tin hieu cua x(2n)
n3 = -floor(L1/2) :1: floor(L2/2);
x3 = zeros(1, length(n3));
for i=1:length(n3)
    x3(i) = x(2*n3(i) + L1 + 1);
end
subplot(4,1,4)
stem(n3,x3);
title('x(2n)');


