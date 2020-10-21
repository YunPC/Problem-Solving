%% generate test case
n = 10;
n_max = 1000;
d = [randi(n_max, n, 1) randi(n_max+1, n, 1)-1];
d = sortrows(d, 1);
unique_ck = 1;
while unique_ck
    unique_ck = 0;
    for idx = 2:n
        if d(idx, 1) == d(idx-1, 1)
            d(idx, 1) = randi(n_max);
            unique_ck = 1;
        end
    end
    d = sortrows(d, 1);
end
%% brute force
x1 = d(:, 1);
r1 = d(:, 2);
r_max1 = d(:, 2);

for idx = 2:n
    for idx2 = 1:idx-1
        r1(idx) = min((x1(idx)-x1(idx2))^2/4/r1(idx2), r1(idx));
    end
end
d
r1
close all
figure(1)
th = linspace(0, 2*pi, 100);
for idx = 1:n
    circ_x = r1(idx)*cos(th);
    circ_y = r1(idx)*sin(th);
    plot(circ_x+x1(idx), circ_y+r1(idx));
    hold on
end