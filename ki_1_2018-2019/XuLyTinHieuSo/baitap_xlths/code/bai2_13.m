h1 = [1 2 -2 -3]; %he thong 1
h2 = [-2 0 3 1];  %he thong 1
h = conv(h1,h2);%tong chap cua h1 va h2
%nhan hai da thuc lai voi nhau va tra ve he so
N = 30;
x = randn(1,N); %tao mot vecto ngau nhien x gom N phan tu theo phan bo chuan,

y11 = conv(x,h1);
y1 = conv(y11,h2);

y21 = conv(x,h2);
y2 = conv(y21,h1);

y = conv(x,h); %tong chap cua x va h

subplot(3,1,1);
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



