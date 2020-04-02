clf;
L1=10;
L2=10;
n = -L1:L2;
x = randn(size(n)); 

figure(1);
%Dich dau ra
yn = fliplr(x); %y(n) = H[x(n)] = x(-n)
yn_k = [0 0 0 0 0 yn]; 
%n_yn_k = [n, 11:15]; % them gia tri cho n

%Dich dau vao
x1 = [0 0 0 0 0 x]; %Dich phai x(n) 5 mau -> x(n-5)
n1 = [n, 11:15];
y1 = fliplr(x1); %H[x(n-k)] = x(-(n-k));


subplot(2,1,1);
stem(n1,yn_k);
title('y(n - k)');
xlabel('chi so thoi gian n');
ylabel('bien do');

subplot(2,1,2);
stem(n1,y1);
title('H[x(n - k)]');
xlabel('chi so thoi gian n');
ylabel('bien do');



 
%==================================================================================
%xac dinh tinh bat bien cua y(n) = x(n)cos(0.5n).
figure(2);
%Dich dau ra
y = x.*cos(0.5.*n); %y(n) = H[x(n)] = x(n)cos(0.5n)
yn_k = [0 0 0 0 0 y]; %dich phai yn_k 5 mau --> yn_k(n-5)
n_yn_k = [n, 11:15];  

%Dich dau vao
x1 = [0 0 0 0 0 x]; %dich phai x1 5 mau -> x1(n-5)
n1 = [n, 11:15]; 

y1 = x1.*cos(0.5.*n1); % y1 = H[x(n - 5)] = x(n-5)cos(0.5(n-5))


subplot(2,1,1);
stem(n_yn_k,yn_k);
title('y(n - k)');
xlabel('chi so thoi gian n');
ylabel('bien do');

subplot(2,1,2);
stem(n1,y1);
title('H[x(n - k)]');
xlabel('chi so thoi gian n');
ylabel('bien do');



