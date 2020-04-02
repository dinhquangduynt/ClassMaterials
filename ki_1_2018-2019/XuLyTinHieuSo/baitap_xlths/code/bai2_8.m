n = -10:10;
x = randn(size(n)); 
y = n.*x; %y(n) = nx(n)
ynk = [0 0 0 0 y]; %dich phai y(n) 4 mau -> y(n-4)
x1 = [0 0 0 0 x];
n1 = [n 11:14]; %bo sung them gia tri cho n
yn = n1.*x1; % y(n)=n1 * x1
subplot(2,1,1);
stem(n1,ynk); %ve tin hieu roi rac ynk
title('y(n-k)');
xlabel('chi so thoi gian n');
ylabel('bien do');


subplot(2,1,2);
stem(n1,yn);
title('H[x(n - k)]');
xlabel('chi so thoi gian n');
ylabel('bien do');


