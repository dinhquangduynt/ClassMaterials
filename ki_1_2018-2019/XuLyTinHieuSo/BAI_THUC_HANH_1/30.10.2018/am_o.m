
[y5,Fs]=audioread('o.wav');%mo file am thanh wav
n5=1/Fs:1/Fs:(length(y5)/Fs);%tao mot mien gia tri thoi gian
subplot(1,1,1);
plot(n5,y5);
[pkso, loc]= findpeaks(y5);%ham tra ve cac gia tri tai dinh cuc dai
n1o=loc(7414);%so luong mau tai moi dinh 1
n2o=loc(7429);%so luong mau tai moi dinh 2
dNo=n2o-n1o;
T1o=dNo * (1/Fs);% chu ki co ban
Fo=1/T1o;% tan so
title('Speech signal o');
sound(y5,Fs);%phat ra loa am o