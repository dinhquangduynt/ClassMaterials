[y3,Fs]=audioread('D:\BAI_THUC_HANH_1\e.wav');%mo file am thanh wav
n3=1/Fs:1/Fs:(length(y3)/Fs);%tao mot mien gia tri thoi gian
subplot(1,1,1);
plot(n3,y3);
[pkse, loc]= findpeaks(y3);%ham tra ve cac gia tri tai dinh cuc dai
n1e=loc(14919);%so luong mau tai moi dinh 1
n2e=loc(14934);%so luong mau tai moi dinh 2
dNe=n2e-n1e;
T1e=dNe * (1/Fs);% chu ki co ban
Fe=1/T1e;% tan so
title('Speech signal e');
sound(y3,Fs);%phat ra loa am e
pause(2);