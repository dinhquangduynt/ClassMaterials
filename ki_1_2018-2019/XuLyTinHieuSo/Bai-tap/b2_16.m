n = -20:20;
u = [zeros(1,20) ones(1,21)];
x = (-2).^n.*u;

h1 = [zeros(1,19),1,0,-1,3, zeros(1,18)];
h2 = [zeros(1,18),2,-2,1, zeros(1, 20)];
h3 = [zeros(1, 18), 3,4,-1,1, zeros(1,19)];
h4 = [zeros(1,19),-3,5,6,-1,1, zeros(1,17)];

%Phuong phap theo so do:
[y1, n1] = my_conv(x,n,h1,n);

[y12, n12] = my_conv(y1, n1, h2, n);
[y13, n13] = my_conv(y1, n1, h3, n);

y123 = y12 + y13;
n123 = n12;

[ya, na] = my_conv(y123, n123, h4, n);

%Phuong phap dap ung xung tuong duong
h23 = h2 + h3;
[h123, n_h123] = my_conv(h1, n, h23, n);
[hb, n_hb] = my_conv(h123, n_h123, h4, n);
[yb, nb] = my_conv(x,n, hb, n_hb);


subplot(111);
plot(na, ya, 'y-', nb, yb, 'r--');
