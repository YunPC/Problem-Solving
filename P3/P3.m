%% whole test
test_num = 1;
while 1
    disp(num2str(test_num));
    %% test case generation
    n = 100000;
    d = zeros(100000, 2);
    for idx = 1:100000
        d(idx, 1) = randi(100000); % pos
        d(idx, 2) = 0;
    end
    %% brute force
    d1 = sortrows(d, 1, 'descend');
    sum = 0;
    max_carrier = 0;
    other_carrier = 0;
    left_pair = 0;
    right_pair = 0;
    for idx = 1:99999
        if d(idx,2) == 1
           continue;
        end
        for i = idx+1:100000
            if d(i, 2) == 1
                continue;
            end
            temp_sum = d(idx,1) + d(i, 1);
            if temp_sum <= n && temp_sum > sum
                sum = temp_sum;
                left_pair = idx;
                right_pair = i;
            elseif d(idx,1) == n
                max_carrier = max_carrier + 1;
                d(idx,2) = 1;
                break;
            end
        end
        if sum > 0
            d(left_pair, 2) = 1;
            d(right_pair, 2) = 1;
            other_carrier = other_carrier + 1;
        end
        sum = 0;
    end
    for idx = 1:100000
       if d(idx, 2) ~= 1
           max_carrier = max_carrier + 1;
       end
    end
    max_pop_brute = max_carrier + other_carrier;
    
    %%
%     big_bag = [];
%     small_bag = [];
%     my_carrier = 0;
%     for idx = 1:10
%         if d(idx,1) == n
%             my_carrier = my_carrier + 1;
%         elseif d(idx,1) > n/2
%             big_bag = [big_bag, d(idx,1)];
%         else
%             small_bag = [small_bag, d(idx,1)];
%         end
%     end
%     
%     big_bag_sort = sort(big_bag, 'descend');
%     small_bag_sort = sort(small_bag);
%     
%     while(~(isempty(big_bag_sort) || isempty(small_bag_sort)))
%         if big_bag_sort(1) + small_bag_sort(1) <= n
%             my_carrier = my_carrier + 1;
%             big_bag_sort(1) = [];
%             small_bag_sort(1) = [];
%         elseif ~(isempty(big_bag_sort))
%             my_carrier = my_carrier + 1;
%             big_bag_sort(1) = [];
%         end
%     end
%     
%     if(~(isempty(big_bag_sort)))
%         my_carrier = my_carrier + length(big_bag_sort);
%     end
%     if(~(isempty(small_bag_sort)))
%         if mod(length(small_bag_sort), 2) == 0
%             my_carrier = my_carrier + floor(length(small_bag_sort)/2);
%         else
%             my_carrier = my_carrier + floor(length(small_bag_sort)/2)+1;
%         end
%     end
%     max_pop = my_carrier;
%     my_carrier = 0;
%     bag = [n];
%     for idx = 1:100000
%         if d1(idx,1) == n
%             my_carrier = my_carrier + 1;
%         else
%             bag = [bag, d1(idx,1)];
%         end
%     end
%    while ~(isempty(bag))
%         if size(bag) == 1
%             my_carrier = my_carrier + 1;
%             break;
%         elseif bag(1)+ bag(end) <= n
%             bag(end) = [];
%             bag(1) = [];
%             my_carrier = my_carrier + 1;
%         else
%             my_carrier = my_carrier + 1;
%             bag(1) = [];
%         end
%     end
% 
%     max_pop = my_carrier;


    % max_pop
    %%
    if max_pop ~= max_pop_brute
        break
    end
    test_num = test_num + 1;
end

%%
disp([num2str(n) ' ' num2str(n)]);
for idx = 1:n
    disp([num2str(d(idx, 2)) ' ' num2str(d(idx, 1))]);
end