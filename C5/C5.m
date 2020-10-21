%% whole test
test_num = 1;
while 1
    disp(num2str(test_num));
    %% test case generation
    n = 10;
    d = zeros(10, 3);
    d2 = zeros(10, 3);
    for idx = 1:10
        d(idx, 1) = randi(100); % pos
        d(idx, 2) = 0; % r
        d(idx, 3) = randi(100); %max_r
    end
    d = sortrows(d, 1);
    d2 = d;
    %% brute force
    %first ballon is always max
    d(1, 2) = d(1, 3);
    d2(1, 2) = d(1, 3);
    br_max_r = 0;
    op_max_r = 0;
    temp = 0;
    temp_r = 0;
    comp_idx = 1;
    flag = 0;
    for idx = 2:10
        br_max_r = d(idx, 3);
        op_max_r = d(idx, 3);
        %brute force calculation
        for i = idx-1 : -1 : 1
            %if two circle can meet
            if d(i,1)+d(i,2) > d(idx,1) - d(idx,3)
                %brute force calculation
                temp = ((d(idx,1)-d(i,1)).^2) ./ (4*d(i,2));
                temp = fix(temp*10^3)./10^3;
                br_max_r = min(br_max_r, temp);  
            end
        end
        %brute force
        d(idx, 2) = br_max_r;
        %optimize calculation
        if d(comp_idx,1)+d(comp_idx,2) > d(idx,1) - d(idx,3)
            temp_r = ((d(idx,1)-d(comp_idx,1)).^2) ./ (4*d(comp_idx,2));
            temp_r = fix(temp_r*10^3) ./ 10^3;
            op_max_r = min(temp_r, op_max_r);
            if (d(comp_idx, 1) + d(comp_idx, 2)) < (d(idx,1) + op_max_r)
                comp_idx = idx;
            end
            if comp_idx ~= idx-1
                temp_r = ((d(idx,1)-d(idx-1,1)).^2) ./ (4*d(idx-1,2));
                temp_r = fix(temp_r*10^3) ./ 10^3;
                op_max_r = min(temp_r, op_max_r);
            end
        end
        d2(idx, 2) = op_max_r;
        if d(idx,2) ~= d2(idx,2)
            flag = 1;
            break
        end
    end
        
    if flag ==1
        break
    end
%%
    test_num = test_num + 1;
end

%%
% disp([num2str(n) ' ' num2str(n)]);
% for idx = 1:n
%     disp([num2str(d(idx, 2)) ' ' num2str(d(idx, 1))]);
% end