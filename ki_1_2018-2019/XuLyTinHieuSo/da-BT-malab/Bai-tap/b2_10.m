%y(n) = nx(n)
n = -10:10;
x1 = randn(size(n)); %Tín hiệu x1 ngẫu nhiên
x2 = randn(size(n)); %Tín hiệu x2 ngẫu nhiên
a1 = 3; a2 = -2; %a1, a2 tùy ý
y1 = n.*x1;
y2 = n.*x2;

y = n.*(a1*x1 + a2*x2); %Tin hieu ra khi tin hieu vao la tong cua x1, x2 kem he so
y_t = a1*y1+a2*y2; %Tong cua cac tin hieu ra ung voi cac tin hieu vao kem he so

subplot(211), stem(n,y_t);
title('a_1y_1(n)+a_2y_2(n)');

subplot(212), stem(n,y);
title('H[a_1x_1(n)+a_2x_2(n)]');

%Ket luan: y(n) = nx(n) Tuyen tinh