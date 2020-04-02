n = -10:10;
x = randn(size(n)); %Tín hiệu x ngẫu nhiên
y = n.*x; %y(n) = nx(n)
ynk = [0 0 0 0 y]; %Dịch phải y(n) 4 mẫu -> y(n – 4)
x1 = [0 0 0 0 x]; %Dịch phải x(n) 4 mẫu
n1 = [n 11:14]; % Bổ sung them giá trị cho n
yn = n1.*x1; % yn = H[x(n – 4)]
subplot(211), stem(n1,ynk), title('y(n – k)');
subplot(212), stem(n1,yn), title('H[x(n – k)]');

%Ket luan: Ko bat bien