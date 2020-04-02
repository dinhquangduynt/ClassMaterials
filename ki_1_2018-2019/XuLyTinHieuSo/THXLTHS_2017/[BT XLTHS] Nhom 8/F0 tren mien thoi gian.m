%Tim F0 tren mien thoi gian

%%Chu O
[y,Fs]=audioread('C:\Users\PC\Downloads\XLTHS\O30ms.wav'); max_value=max(abs(y));
y=y/max_value;
y=y(1:(Fs*.03));
t=1/Fs:1/Fs:(length(y)/Fs);
subplot(3,1,1)% chia figure
plot(t,y)
indexmax=find(max(y)==y);%vi tri co gia tri lon nhat cua y
xmax=t(indexmax);%toa do x tai max
ymax=y(indexmax);%toa do y tai max
findpeaks(y,t,'MinPeakHeight',ymax/1.2);
[pks1,locs1]=findpeaks(y,t,'MinPeakHeight',ymax/1.2);%tim cac dinh co gia tri tu ymax/1.2
k1=diff(locs1);%tim khoang chenh lech giua hai dinh lien tiep
t0=sum(k1)/length(k1);
f1=1/t0
title('Chu O')
ylabel('Magnitude(dB) ')
grid on


%%Chu A
[y,Fs]=audioread('C:\Users\PC\Downloads\XLTHS\A30ms.wav'); max_value=max(abs(y));
y=y/max_value;
y=y(1:(Fs*.03));
t=1/Fs:1/Fs:(length(y)/Fs);
subplot(3,1,2)
plot(t,y)
title('Chu A');
indexmax=find(max(y)==y);
xmax=t(indexmax);
ymax=y(indexmax);
findpeaks(y,t,'MinPeakHeight',ymax/1.2);
[pks2,locs2]=findpeaks(y,t,'MinPeakHeight',ymax/1.2);
k2=diff(locs2);
t0=sum(k2)/length(k2);
f2=1/t0
title('Chu A');
ylabel('Magnitude(dB) ')
grid on

%%Chu E
[y,Fs]=audioread('C:\Users\PC\Downloads\XLTHS\E30ms.wav'); max_value=max(abs(y));
y=y/max_value;
y=y(1:(Fs*.03));
t=1/Fs:1/Fs:(length(y)/Fs);
subplot(3,1,3)
plot(t,y)
indexmax=find(max(y)==y);%vi tri co gia tri lon nhat cua y
xmax=t(indexmax);%toa do x tai max
ymax=y(indexmax);%toa do y tai max
findpeaks(y,t,'MinPeakHeight',ymax/1.2);
[pks3,locs3]=findpeaks(y,t,'MinPeakHeight',ymax/1.2);%tim cac dinh co gia tri tu ymax/1.2
k3=diff(locs3);%tim khoang chenh lech giua hai dinh lien tiep
t0=sum(k3)/length(k3);
f3=1/t0
title('Chu E');
xlabel('time(s)')
ylabel('Magnitude(dB) ')
grid on