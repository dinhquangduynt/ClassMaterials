function [y, ny] = my_conv(x,nx,h,nh)
    nyb = nx(1)+nh(1); 
    nye = nx(length(x)) + nh(length(h));
    ny = nyb:nye;
    y = conv(x,h);
end