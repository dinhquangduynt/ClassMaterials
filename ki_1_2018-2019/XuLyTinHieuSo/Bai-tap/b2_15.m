nh = -1:5;
h = [0, 0, 0.4, 0.8, 0.4, 0, 0];
nx = -1:3;
x = [0, 1, 0.6, 0, 0];

[y,ny] = my_conv(x,nx,h,nh);

subplot(111),stem(ny, y);
title('y(n)');