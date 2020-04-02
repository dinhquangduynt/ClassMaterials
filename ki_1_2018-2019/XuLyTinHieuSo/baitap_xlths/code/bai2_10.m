%y(n) = nx(n)
n = -10:10;
x1 = randn(size(n)); 
x2 = randn(size(n)); 
a1 = 5; a2 = 4; 
y1 = n.*x1;
y2 = n.*x2;

y = n.*(a1*x1 + a2*x2); %Tin hieu ra khi tin hieu vao la tong cua x1, x2 kem he so
y_t = a1*y1+a2*y2; %Tong cua cac tin hieu ra ung voi cac tin hieu vao kem he so

subplot(211);
stem(n,y_t);
title('a_1y_1(n)+a_2y_2(n)');
xlabel('chi so thoi gian n');
ylabel('bien do');


subplot(212);
stem(n,y);
title('H[a_1x_1(n)+a_2x_2(n)]');
xlabel('chi so thoi gian n');
ylabel('bien do');


