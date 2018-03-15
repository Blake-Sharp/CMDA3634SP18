clear
clc
threads = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16];
time = [48.388,30.917,21.18,16.16,13.07,10.95,9.43,8.26,7.38,6.64,6.05,5.56,5.14,4.77,4.46,4.17];
plot(threads,time)
grid on
title('elapsed time vs thread count')
xlabel('number of OpenMP threads')
ylabel('time required to run the program')