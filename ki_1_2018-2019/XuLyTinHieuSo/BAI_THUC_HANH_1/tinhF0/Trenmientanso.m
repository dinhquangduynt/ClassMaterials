clear;clc;clf;
[y,Fs]=audioread('C:\Users\kieungu\Documents\Custom Office Templates\XU LY TIN HIEU SO\SUONGCUT.wav');
max_value=max(abs(y));
y=y/max_value;
y=y(1:(Fs*.03));
dfty=abs(fft(y));
dfty=dfty(1:(length(dfty)/2));
tt=linspace(1/Fs,Fs/2,length(dfty));%chia doan tu 1/Fs->Fs/2 thanh N doan voi N=length(dfty);
dftylog=10*log10(dfty);%tinh bien do tren thang logarit
subplot(2,1,1);
plot(tt,dftylog);%ve pho bien do tren thang logarit
xlabel('Log Magnitude Spectrum  frequency in Hz');
ylabel('db');
title('Pho bien do tren thang log');
cb=1100;
tiso = Fs/(2*cb);
dfty1= dfty(1:(length(dfty)/tiso)); %TRUC BIEN DO
tt1= tt(1:length(dfty1));%TRUC TAN SO
subplot(2,1,2); 
findpeaks(dfty1,tt1,'MinPeakProminence',2.5,'Annotate','extents');
%Su dung findpeaks de tim va ve cac dinh noi bat co bien do it nhat la 5
[pks,locs]= findpeaks(dfty1,tt1,'MinPeakProminence',2.5); 
%locs la mang chua vi tri tren truc tan so cac dinh vua tim duoc 
title('Hinh ve cac dinh duoc tim');
xlabel('Tan so (Hz)');
ylabel('Bien do');
F0=1000/length(locs)
%F0 se bang 1000 chia cho tong so dinh da tim duoc