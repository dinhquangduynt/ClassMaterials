[y1,Fs]=audioread('D:\BAI_THUC_HANH_1\a.wav');%mo file am thanh wav
n1=1/Fs:1/Fs:(length(y1)/Fs);%tao mot mien gia tri thoi gian
subplot(1,1,1);
plot(n1,y1);
[pksa, loc]= findpeaks(y1);%ham tra ve cac gia tri tai dinh cuc dai
n1a=loc(12085);%so luong mau tai moi dinh 1
n2a=loc(12102);%so luong mau tai moi dinh 2
dNa=n2a-n1a;
T1a=dNa * (1/Fs);% chu ki co ban
Fa=1/T1a;% tan so
title('Speech signal a');
sound(y1,Fs);%phat ra loa am a
pause(2);