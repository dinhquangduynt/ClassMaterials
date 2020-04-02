
nh = -1:5;
h = [0, 0, 0.4, 0.8, 0.4, 0, 0]; %tin hieu h
%tin hieu h(n)
nx = -1:3;
x = [0, 1, 0.6, 0, 0]; %tin hieu x

a=nx(1)+nh(1); %thoi gian bat dau cua tin hieu tong
b=nx(length(x)) + nh(length(h)); %thoi gian ket thuc cua tin hieu tong

ny=a:b; %mien gia tri thoi gian moi cua tin hieu tong 

y=conv(x,h); %tong chap cua tin hieu x va h

subplot(1,1,1);
stem(ny, y);
title('y(n)');
xlabel('chi so thoi gian n');
ylabel('bien do');