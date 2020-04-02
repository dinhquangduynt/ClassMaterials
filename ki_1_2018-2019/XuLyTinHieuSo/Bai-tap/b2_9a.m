n = -10:10;

x = randn(size(n)); %Tín hiệu x ngẫu nhiên

%Dich dau ra
yn = fliplr(x); %y(n) = H[x(n)] = x(-n)
yn_k = [0 0 0 0 yn]; %Dịch phải y(n) 4 mẫu -> y(n – 4)
n_yn_k = [n, 11:14]; 

%Dich dau vao
x1 = [0 0 0 0 x]; %Dich phai x(n) 4 mau -> x(n-4)
n1 = [n, 11:14];
y1 = fliplr(x1); %H[x(n-k)] = x(-(n-k));


subplot(211), stem(n_yn_k,yn_k), title('y(n – k)');
subplot(212), stem(n1,y1), title('H[x(n – k)]');

%Ket luan: Ko bat bien

