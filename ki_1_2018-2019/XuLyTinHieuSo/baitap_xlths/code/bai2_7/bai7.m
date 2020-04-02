n = -3:2;
x1 = [ 0 1, -1, 2, 3, -2];
x2 = [-2, -2, 1, 1, -4 0];

[tong, nhan,m] = ham(x1, x2,n);%goi ham de dung

subplot(2,1,1);
stem(m, tong);
title('x1(n) + x2(n)');
xlabel('chi so thoi gian n');
ylabel('bien do');

subplot(2,1,2);
stem(m, nhan);
title('x1(n) * x2(n)');
xlabel('chi so thoi gian n');
ylabel('bien do');

