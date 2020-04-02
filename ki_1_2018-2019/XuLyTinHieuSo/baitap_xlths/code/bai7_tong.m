function [y,n] = bai7_tong(x1,n1,x2,n2)
%cong hai vector
%nhap x1,n1;x2,n2
%nhap [y,n] = ad(x1,n1,x2,n2)
n  = min([n1 n2]) : max([n1 n2]);
L1 = length(n1);
L2 = length(n2);
Ln = length(n);
y1 = [zeros(1,n1(1)-n(1)) x1 zeros(1,n(Ln)-n1(L1))];
y2 = [zeros(1,n2(1)-n(1)) x2 zeros(1,n(Ln)-n2(L2))];
y=y1+y2;
end
