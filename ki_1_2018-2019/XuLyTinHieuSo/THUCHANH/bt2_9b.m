%  y(n) = x(n)cos(0.5n)

n = -10:10;
x = randn(size(n)); %Tín hi?u x ng?u nhiên
temp = cos(0.5.*n); %cos(0.5n)
y = x.* temp; %y(n) = x(n)cos(0.5n)
yn4 = [0 0 0 0 y]; %d?ch ph?i y(n) 4 m?u -> y(n – 4)
x1 = [0 0 0 0 x]; %d?ch ph?i x(n) 4 m?u
temp1 = [0 0 0 0 temp];
n1 = [n 11:14]; % b? sung thêm giá tr? cho n
yn = x1.*temp1; % x(n-4)cos(0.5(n-4))
subplot(211), stem(n1,yn4), title('y(n – 4)');
subplot(212), stem(n1,yn), title('x(n-4)cos(0.5(n-4))');

% nhìn vào ?? th? ta th?y y(n-4) = x(n-4)cos(0.5(n-4)) 
% => có tính b?t bi?n

