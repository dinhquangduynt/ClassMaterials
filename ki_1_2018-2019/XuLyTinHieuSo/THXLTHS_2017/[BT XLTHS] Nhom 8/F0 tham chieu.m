%Phan tich tin hieu (automatic signal analysis):

%%%Chu O
[y,Fs]=audioread('C:\Users\Thu Nguyen\Desktop\XLTHS\Chu O\O30ms.wav'); max_value=max(abs(y));
y=y/max_value;
y=y(1:(Fs*.03));
t=1/Fs:1/Fs:(length(y)/Fs);
dfty=abs(fft(y)); % chuyen sang tin hieu mien tan so
dfty=dfty(1:(length(dfty))/2);
tt=linspace(1/Fs,Fs/2,length(dfty));% lay mau tt 1/Fs toi Fs/2 voi buoc nhay (Fs/2-1/Fs)/(length(dfty)-1)
dftylog=10*log10(dfty); % chuyen sang tin hieu mien logarit
subplot(3,1,1)% chia figure
plot(tt,dftylog)
title('Chu O')
ylabel('Magnitude(dB) ')
grid on


%%Chu A
[y,Fs]=audioread('C:\Users\Thu Nguyen\Desktop\XLTHS\Chu A\A30ms.wav'); max_value=max(abs(y));
y=y/max_value;
y=y(1:(Fs*.03));
t=1/Fs:1/Fs:(length(y)/Fs);
dfty=abs(fft(y));
dfty=dfty(1:(length(dfty))/2);
tt=linspace(1/Fs,Fs/2,length(dfty));
dftylog=10*log10(dfty);
subplot(3,1,2)
plot(tt,dftylog)
title('Chu A')
ylabel('Magnitude(dB) ')
grid on

%%Chu E
[y,Fs]=audioread('C:\Users\Thu Nguyen\Desktop\XLTHS\Chu E\E30ms.wav'); max_value=max(abs(y));
y=y/max_value;
y=y(1:(Fs*.03));
t=1/Fs:1/Fs:(length(y)/Fs);
dfty=abs(fft(y));
dfty=dfty(1:(length(dfty))/2);
tt=linspace(1/Fs,Fs/2,length(dfty));
dftylog=10*log10(dfty);
subplot(3,1,3)
plot(tt,dftylog)
title('Chu E')
xlabel('Log Magnitude Spectrum')
ylabel('Magnitude(dB) ')
grid on