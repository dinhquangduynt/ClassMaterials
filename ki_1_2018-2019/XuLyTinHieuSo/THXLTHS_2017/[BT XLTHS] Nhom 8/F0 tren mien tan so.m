%%Tim F0 trenn mien tan so

%Chu A
[y,Fs]=audioread('C:\Users\PC\Downloads\XLTHS\A30ms.wav');
max_value=max(abs(y));
y=y/max_value;
y=y(1:(Fs*.03));
t=1/Fs:1/Fs:(length(y)/Fs);
dfty=abs(fft(y));% bien doi fourier cua tin hieu y
dfty=dfty(1:(length(dfty)/16));
tt=linspace(1/Fs,Fs/16,length(dfty));
dftylog=10*log10(dfty);
subplot(3,1,1)% chia figure
plot(tt,dftylog)
[pks1,p1]=findpeaks(dftylog,tt,'Threshold',1);% tim cac dinh chenh lech nhau it nhat nguong 1 dB
findpeaks(dftylog,tt,'Threshold',1);
r1=length(p1);% so peak
tsA=1000/r1% tan so
title('Chu A')
ylabel('Bien do')


%Chu O
[y,Fs]=audioread('C:\Users\PC\Downloads\XLTHS\O30ms.wav');
max_value=max(abs(y));
y=y/max_value;
y=y(1:(Fs*.03));
t=1/Fs:1/Fs:(length(y)/Fs);
dfty=abs(fft(y));
dfty=dfty(1:(length(dfty)/16));
tt=linspace(1/Fs,Fs/16,length(dfty));
dftylog=10*log10(dfty);
subplot(3,1,2)
plot(tt,dftylog)
[pks2,p2]=findpeaks(dftylog,tt,'Threshold',2);
findpeaks(dftylog,tt,'Threshold',2);
r2=length(p2);
tsO=1000/r2
title('Chu O')
ylabel('Bien do')


%Chu E
[y,Fs]=audioread('C:\Users\PC\Downloads\XLTHS\E30ms.wav');
max_value=max(abs(y));
y=y/max_value;
y=y(1:(Fs*.03));
t=1/Fs:1/Fs:(length(y)/Fs);
dfty=abs(fft(y));
dfty=dfty(1:(length(dfty)/16));
tt=linspace(1/Fs,Fs/16,length(dfty));
dftylog=10*log10(dfty);
subplot(3,1,3)
plot(tt,dftylog)
[pks3,p3]=findpeaks(dftylog,tt,'Threshold',1);
findpeaks(dftylog,tt,'Threshold',1);
r3=length(p3);
tsE=1000/r3
title('Chu E')
ylabel('Bien do')