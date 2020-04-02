function [y] = gaussianFilter(input)

len = 44100;   
kernel = linspace(-len/2, len/2, len); %khoi tao ma tran 1xlen, gom cac phan tu cach deu nhau bat da tu -len/2 den len/2

%tinh do lenh chuan sigma
tmp = sum(kernel.^2);
sigma = sqrt(tmp/(len-1));

gaussFilter = 1/(sqrt(2*3.14)*sigma)*exp(-kernel .^ 2 / (2 * sigma ^ 2));
gaussFilter = gaussFilter / sum (gaussFilter); % normalize

y = filter (gaussFilter,1, input);

end

%https://stackoverflow.com/questions/6992213/gaussian-filter-on-a-vector-in-matlab
%https://en.wikipedia.org/wiki/Gaussian_filter