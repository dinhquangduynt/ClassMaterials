[y2,Fs]=audioread('D:\BAI_THUC_HANH_1\u.wav');%mo file am thanh wav
n2=1/Fs:1/Fs:(length(y2)/Fs);%tao mot mien gia tri thoi gian
subplot(1,1,1);
plot(n2,y2);
[pksu, loc]= findpeaks(y2);%ham tra ve cac gia tri tai dinh cuc dai
n1u=loc(14829);%so luong mau tai moi dinh 1
n2u=loc(14840);%so luong mau tai moi dinh 2
dNu=n2u-n1u;
T1u=dNu * (1/Fs);% chu ki co ban
Fu=1/T1u;% tan so
title('Speech signal u');
sound(y2,Fs);%phat ra loa am u