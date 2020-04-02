%y(n) = x^2(n)
L1=10;
L2=10;
n = -L1:L2;
x1 = randn(size(n));
x2 = randn(size(n)); 
a1 = 3; a2 = -2; 
y1 = x1.^2;
y2 = x2.^2;

y = (a1*x1 + a2*x2).^2; %Tin hieu ra khi tin hieu vao la tong cua x1, x2 binh phuong
y_t = a1*y1+a2*y2; %Tong cua cac tin hieu ra ung voi cac tin hieu vao kem he so

subplot(211), stem(n,y_t);
title('a_1y_1(n)+a_2y_2(n)');
xlabel('chi so thoi gian n');
ylabel('bien do');


subplot(212), stem(n,y);
title('H[a_1x_1(n)+a_2x_2(n)]');
xlabel('chi so thoi gian n');
ylabel('bien do');


%Ket luan: y(n) = x^2(n) Ko tuyen tinh