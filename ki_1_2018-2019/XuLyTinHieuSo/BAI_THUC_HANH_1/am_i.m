[y4,Fs]=audioread('D:\BAI_THUC_HANH_1\i.wav');%mo file am thanh wav
n4=1/Fs:1/Fs:(length(y4)/Fs);%tao mot mien gia tri thoi gian
subplot(1,1,1);
plot(n4,y4);
[pksi, loc]= findpeaks(y4);%ham tra ve cac gia tri tai dinh cuc dai
n1i=loc(12309);%so luong mau tai moi dinh 1
n2i=loc(12332);%so luong mau tai moi dinh 2
dNi=n2i-n1i;
T1i=dNi * (1/Fs);% chu ki co ban
Fi=1/T1i;% tan so
title('Speech signal i');
sound(y4,Fs);%phat ra loa am i
pause(2);