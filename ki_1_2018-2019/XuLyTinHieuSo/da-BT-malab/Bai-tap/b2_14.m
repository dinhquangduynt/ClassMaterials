
N = 30;
x = randn(1,N);

a1 = [1, -0.1]; %He so y1
b1 = [2, -0.5, 0, 0.5]; %He so x1
h1 = impz(b1, a1, N); %Hệ thống 1

a2 = [1, 0.1]; %He so y2
b2 = [0.3, 0, 0.2]; %He so x2
h2 = impz(b2, a2, N); %Hệ thống 2

h = conv(h1,h2);

y11 = conv(x,h1);
y1 = conv(y11,h2);

y21 = conv(x,h2);
y2 = conv(y21,h1);

y = conv(x,h);

subplot(311),stem(y1);
title('y(n) = (x*h_1(n))*h_2(n)');

subplot(312),stem(y2);
title('y(n) = (x*h_2(n))*h_1(n)');

subplot(313),stem(y);
title('y(n) = x*(h_1(n)*h_2(n))');

%Ket luan: y1 = y2 -> giao hoan, y1=y1 = y -> ket hop
