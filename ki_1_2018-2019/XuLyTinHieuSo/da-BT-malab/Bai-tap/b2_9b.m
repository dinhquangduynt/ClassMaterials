n = -10:10;

x = randn(size(n)); %Tín hiệu x ngẫu nhiên

%Dich dau ra
y = x.*cos(0.5.*n); %y(n) = H[x(n)] = x(n)cos(0.5n)
yn_k = [0 0 0 0 y]; %Dịch phải y(n) 4 mẫu -> y(n – 4)
n_yn_k = [n, 11:14];  % Bổ sung them giá trị cho n

%Dich dau vao
x1 = [0 0 0 0 x]; %Dịch phải x(n) 4 mẫu -> x(n-4)
n1 = [n, 11:14]; % Bổ sung them giá trị cho n

y1 = x1.*cos(0.5.*n1); % y1 = H[x(n – 4)] = x(n-4)cos(0.5(n-4))


subplot(211), stem(n_yn_k,yn_k), title('y(n – k)');
subplot(212), stem(n1,y1), title('H[x(n – k)]');

%Ket luan: Ko bat bien