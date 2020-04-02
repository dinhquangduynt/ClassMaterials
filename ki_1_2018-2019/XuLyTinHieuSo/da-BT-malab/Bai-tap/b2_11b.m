%y(n) = x(n^2)
nl = -10; %Bien do trai tin hieu vao
nr = 10; %Bien do phai tin hieu vao
n = nl:nr;

nyl = floor(sqrt(abs(nl))); %Tinh bien do ben trai cua tin hieu ra
if(nl < 0)   
    nyl = nyl*(-1); 
end
    
nyr = floor(sqrt(abs(nr))); %Tinh bien do ben phai cua tin hieu ra
if(nr < 0)   
    nyr = nyr*(-1); 
end

ny = nyl : nyr; %N cua tin hieu ra
ny_size = nyr - nyl + 1; %Do dai mau cua tin hieu ra

x1 = randn(size(n)); %Tín hiệu x1 ngẫu nhiên
x2 = randn(size(n)); %Tín hiệu x2 ngẫu nhiên
a1 = 3; a2 = -2; %a1, a2 tùy ý

y1 = zeros(1, ny_size);
for i = 1: ny_size
   nyi = ny(i)^2; %N tin hieu ra: n = -3 thi ny = 9, vi du y(-3) = x(9); 
   if(nyi < nl || nyi > nr)
       y1(i) = 0;
   else
       y1(i) = x1(nyi -nl +1); % voi n = x thi gia tri cua tin hieu vao la x(n-nl+1)
   end
end

y2 = zeros(1, ny_size);
for i = 1: ny_size
    nyi = ny(i)^2;
    if(nyi < nl || nyi > nr)
       y2(i) = 0;
    else
       y2(i) = x2(nyi - nl + 1); 
    end
end

y_t = a1*y1+a2*y2; %Tong cua cac tin hieu ra ung voi cac tin hieu vao kem he so


y = zeros(1, ny_size); %Tin hieu ra khi tin hieu vao la tong cua cac tin hieu kem he so
x = a1*x1 + a2*x2; %Tin hieu vao la tong cua cac tin hieu kem he so
for i = 1:ny_size
    nyi = ny(i)^2;
    if(nyi < nl || nyi > nr)
       y(i) = 0;
    else
        y(i) = x(nyi - nl + 1); 
    end  
end

subplot(211), stem(ny,y_t);
title('a_1y_1(n)+a_2y_2(n)');

subplot(212), stem(ny,y);
title('H[a_1x_1(n)+a_2x_2(n)]');

%Ket luan: y(n) = x(n62) Tuyen tinh