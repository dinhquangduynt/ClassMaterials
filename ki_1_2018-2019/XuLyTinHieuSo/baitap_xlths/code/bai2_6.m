clf;
L1=10;
L2=10;
n=-L1:L2; %mien thoi gian
u=[zeros(1,L1 + 3) 1 ones(1,L2 - 3)];%tao tin hieu cho ham u(n-3)
d=[zeros(1,L1+2) 1 zeros(1,L2-2)];%tao tin hieu cho ham u(n-2)

%ve ham x(n)=2u(n-3) + d(n-2)
x=2*u+d;
subplot(4,1,1);
stem(n,x);
axis([-L1 L2 0 2]);%dinh dang so phan tu chi thoi gian tu -L1 den L2,
title('x(n)');

%ve ham x(-n)
x1=fliplr(x);% tao ham dao thu tu tu ham x
subplot(4,1,2);
stem(n,x1);
title('x(-n)');

%ve ham 2x(n)
x2=2*x;
subplot(4,1,3);
stem(n,x2);
title('2x(n)');

%ve ham x(2n)
n3 = -floor(L1/2) :1: floor(L2/2);%thu hep khoang n giam di 2 lan
x3 = zeros(1, length(n3)); % tao 1 mang toan gia tri 0 
for i=1:length(n3)
    x3(i) = x(2*i-1); %gan gia tri cua x cho mang x3
end
subplot(4,1,4);
stem(n3,x3);
title('x(2n)');
xlabel('chi so thoi gian n');
ylabel('bien do');





