h1 = [1 2 -2 -3]; %H? th?ng 1 

h2 = [-2 0 3 1]; %H? th?ng 2 

h = conv(h1,h2); 

N = 30; 

x = randn(1,N); 

y11 = conv(x,h1); 

 y1 = conv(y11,h2); 

y21 = conv(x,h2); 

y2 = conv(y21,h1); 

y = conv(x,h); 

subplot(311),stem(y1); 
title('y(n) = (x*h_1(n))*h_2(n)');

subplot(312),stem(y2); 

title('y(n) = (x*h_2(n))*h_1(n)'); 

subplot(313),stem(y); 
title('y(n) = x*(h_1(n)*h_2(n)'); 