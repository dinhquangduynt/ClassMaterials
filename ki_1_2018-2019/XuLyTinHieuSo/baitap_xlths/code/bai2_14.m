
N = 30;
x = randn(1,N);%tao mot vecto ngau nhien x 1 hang gom N phan tu theo phan bo chuan

d1 = [1, -0.1]; %He so y1
n1 = [2, -0.5, 0, 0.5]; %He so x1
h1 = impz(n1, d1, N); %tao xung dap ung He thong 1

d2 = [1, 0.1]; %He so y2
n2 = [0.3, 0, 0.2]; %He so x2
h2 = impz(n2, d2, N); %tao xung dap ung he thong 2

h = conv(h1,h2);

y11 = conv(x,h1);
y1 = conv(y11,h2);

y21 = conv(x,h2);
y2 = conv(y21,h1);

y = conv(x,h);

subplot(3,1,1); %bieu do nang o hang 1 
stem(y1);
title('y(n) = (x*h_1(n))*h_2(n)');
xlabel('chi so thoi gian n');
ylabel('bien do');


subplot(3,1,2);
stem(y2);
title('y(n) = (x*h_2(n))*h_1(n)');
xlabel('chi so thoi gian n');
ylabel('bien do');


subplot(3,1,3);
stem(y);
title('y(n) = x*(h_1(n)*h_2(n))');
xlabel('chi so thoi gian n');
ylabel('bien do');


