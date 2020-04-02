clear();

[a, fsa] = audioread('o.wav');
fsa_len = length(fsa); % chieu dai tan so
a_len = length(a); % chieu dai tin hieu
frame_len = 0.03 * fsa; % chieu dai moi khung (1s lay duoc fsa mau thi 0.03s lay duoc frame_len mau)
number_frame = round(a_len/frame_len) - 1; % so luong khung, quy dinh khung bat dau la 1
max_period = round(1/80*fsa);
min_period = round(1/600*fsa);

subplot(2,1,1);
plot(a);
xlabel("Chi so mau n");
ylabel("Tin hieu am");
axis([0 a_len*1.02 -inf inf]);

index = 1;
for k = 1 : number_frame
 % lay mau tin hieu theo tung khung
    range = (k -1)* frame_len + 1 : k * frame_len; % xac dinh vi tri khung thu k + 1 
    frame = a(range); % khung thu k + 1 
 
    
  %loc bang bo loc Gaussian
   frame = gaussianFilter(frame);

  % tinh toan ham tu tuong quan
   [fr_xcorr, ~] = xcorr(frame, frame); 
  
   %tinh cuc dai cuc bo cua ham tu tuong quan
    [pks,lag] = findpeaks(fr_xcorr);
   % tinh delta n giua 2 cuc dai bat ki
    delta = 0;
    fo = 0;
  
   % tinh delta n
    max_loc = find(pks == max(pks)); %tim chi so cua max (cung la 1 cuc dai)
    if(max_loc > 1 && length(lag) >= 3)
        delta = lag(max_loc) - lag(max_loc - 1);
    end
    
    %tinh fo
   if(delta ~= 0 && delta > min_period && delta < max_period)
       fo = fsa/delta; 
       fo_vecto(index) = fsa/delta;
       loc_vecto(index) = (k-1)*frame_len + frame_len/2;
       index = index+1;
   end
   
end

subplot(2,1,2);
plot(loc_vecto, fo_vecto, 'marker', '*', 'markersize', 5);
plot(loc_vecto, fo_vecto, '*');
axis([0 a_len*1.02 0 inf]);
xlabel("Chi so mau n");
ylabel("Tan so Fo (Hz)");
