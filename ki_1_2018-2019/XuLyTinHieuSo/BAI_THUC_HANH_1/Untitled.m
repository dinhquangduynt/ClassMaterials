clf; %xoa cac figure
%am a chua xong
[y1,Fs]=audioread('D:\BAI_THUC_HANH_1\a.wav');%mo file am thanh wav
n1=1/Fs:1/Fs:(length(y1)/Fs);%tao mot mien gia tri thoi gian
subplot(5,1,1);
plot(n1,y1);
[pksa, loc]= findpeaks(y1);%ham tra ve cac gia tri tai dinh cuc dai
n1a=loc(12023);%so luong mau tai moi dinh 1
n2a=loc(12142);%so luong mau tai moi dinh 2
dNa=n2a-n1a;
T1a=dNa * (1/Fs);% chu ki co ban
Fa=1/T1a;% tan so
title('Speech signal a');
sound(y1,Fs);%phat ra loa am a
pause(2);
aaa


%am u
[y2,Fs]=audioread('D:\BAI_THUC_HANH_1\u.wav');%mo file am thanh wav
n2=1/Fs:1/Fs:(length(y2)/Fs);%tao mot mien gia tri thoi gian
subplot(5,1,2);
plot(n2,y2);
[pksu, loc]= findpeaks(y2);%ham tra ve cac gia tri tai dinh cuc dai
n1u=loc(12023);%so luong mau tai moi dinh 1
n2u=loc(12142);%so luong mau tai moi dinh 2
dNu=n2-n1;
T1u=dN * (1/Fs);% chu ki co ban
Fu=1/T1;% tan so
title('Speech signal u');
sound(y2,Fs);%phat ra loa am u
pause(2);

%am e
[y3,Fs]=audioread('D:\BAI_THUC_HANH_1\e.wav');%mo file am thanh wav
n3=1/Fs:1/Fs:(length(y3)/Fs);%tao mot mien gia tri thoi gian
subplot(5,1,3);
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

%am i
[y4,Fs]=audioread('D:\BAI_THUC_HANH_1\i.wav');%mo file am thanh wav
n4=1/Fs:1/Fs:(length(y4)/Fs);%tao mot mien gia tri thoi gian
subplot(5,1,4);
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

%am o
[y5,Fs]=audioread('D:\BAI_THUC_HANH_1\o.wav');%mo file am thanh wav
n5=1/Fs:1/Fs:(length(y5)/Fs);%tao mot mien gia tri thoi gian
subplot(5,1,5);
plot(n5,y5);
[pkso, loc]= findpeaks(y5);%ham tra ve cac gia tri tai dinh cuc dai
n1o=loc(18152);%so luong mau tai moi dinh 1
n2o=loc(18166);%so luong mau tai moi dinh 2
dNo=n2o-n1o;
T1o=dNo * (1/Fs);% chu ki co ban
Fo=1/T1o;% tan so
title('Speech signal o');
sound(y5,Fs);%phat ra loa am o