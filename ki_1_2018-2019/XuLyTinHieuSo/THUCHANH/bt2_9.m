n = -5:5;
x = randn(size(n)); %Tín hi?u x ng?u nhiên
x1 = sigfold(x,n); % x(-n)
y = x1; % y(n) = x(-n)
yn = [0 0 0 0 y]; %D?ch ph?i y(n) 4 m?u -> y(n – 4)
x2 = [0 0 0 0 x1]; %D?ch ph?i x(-n) 4 m?u
n1 = [n 11:14]; % B? sung them giá tr? cho n
subplot(211), stem(n1,yn), title('y(n – 4)');
subplot(212), stem(n1,x2), title('[x(-n – 4)]');
% y(n – 4) = [x(-n – 4)] => có tính b?t bi?n

function [y,n] = sigfold(x,n) 
    y = fliplr(x);
    n = -fliplr(n);
end