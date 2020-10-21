#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int frame[8][8];

bool cover(int block_num, int square_size, vector<int> slices[], int n);

int main()
{
    int n, h, w, value, block_cnt = 0;
    int possible_square_num[8] = {1, 4, 9, 16, 25, 36, 49, 64};
    vector<int> slices[5];
    vector<bool> visited[5]; 
    cin >> n;

    //조각 입력받기
    for (int slice_idx = 1; slice_idx <= n; slice_idx++)
    {
        cin >> h >> w;
        switch (slice_idx)
        {
        case 1:
            slices[0].push_back(h);
            slices[0].push_back(w);
            for (int height = 0; height < h; height++)
            {
                for (int width = 0; width < w; width++)
                {
                    cin >> value;
                    slices[0].push_back(value);
                    visited[0].push_back(false);
                    if (value == 1)
                        block_cnt++;
                }
            }
            break;
        case 2:
            slices[1].push_back(h);
            slices[1].push_back(w);
            for (int height = 0; height < h; height++)
            {
                for (int width = 0; width < w; width++)
                {
                    cin >> value;
                    slices[1].push_back(value);
                    visited[1].push_back(false);
                    if (value == 1)
                        block_cnt++;
                }
            }
            break;
        case 3:
            slices[2].push_back(h);
            slices[2].push_back(w);
            for (int height = 0; height < h; height++)
            {
                for (int width = 0; width < w; width++)
                {
                    cin >> value;
                    slices[2].push_back(value);
                    visited[2].push_back(false);
                    if (value == 1)
                        block_cnt++;
                }
            }
            break;
        case 4:
            slices[3].push_back(h);
            slices[3].push_back(w);
            for (int height = 0; height < h; height++)
            {
                for (int width = 0; width < w; width++)
                {
                    cin >> value;
                    slices[3].push_back(value);
                    visited[3].push_back(false);
                    if (value == 1)
                        block_cnt++;
                }
            }
            break;
        case 5:
            slices[4].push_back(h);
            slices[4].push_back(w);
            for (int height = 0; height < h; height++)
            {
                for (int width = 0; width < w; width++)
                {
                    cin >> value;
                    slices[4].push_back(value);
                    visited[4].push_back(false);
                    if (value == 1)
                        block_cnt++;
                }
            }
            break;
        default:
            break;
        }
    }
    //조각 입력 끝

    bool is_square_number = false;
    int square_size;
    for (int idx = 0; idx < 8; idx++)
    {
        if (block_cnt == possible_square_num[idx])
        {
            is_square_number = true;
            square_size = possible_square_num[idx];
            break;
        }
    }

    block_cnt = 0;
    bool is_overlap = false;
    bool can_cover;
    int height, width;
    if (is_square_number)
    {
        int col = 0, row = 0, block_num = 0;
        square_size = (int)sqrt(square_size);
        can_cover = cover(0, square_size, slices, n);
        if (!can_cover)
        {
            cout << "No solution possible";
        }
    }
    else
    {
        cout << "No solution possible";
    }
}

bool cover(int block_num, int square_size, vector<int> slices[], int n)
{
    int height, width;
    bool is_overlap = false;
    bool can_cover = false;
    for (int row = 0; row < square_size; row++)
    {
        for (int col = 0; col < square_size; col++)
        {
            if (frame[row][col] == 0)
            {
                // height = slices[block_num][0];
                // width = slices[block_num][1];
                // int block_idx = 2;
                // for (int s1_row = row; s1_row < row + height; s1_row++)
                // {
                //     if (is_overlap)
                //         break;
                //     for (int s1_col = col; s1_col < col + width; s1_col++)
                //     {
                //         if (frame[s1_row][s1_col] != 0 && slices[block_num][block_idx++] == 1)
                //         {
                //             is_overlap = true;
                //             for (int r = 0; r < square_size; r++)
                //             {
                //                 for (int l = 0; l < square_size; l++)
                //                 {
                //                     frame[r][l] = 0;
                //                 }
                //             }
                //             break;
                //         }
                //         else if (slices[block_num][block_idx++] == 1)
                //         {
                //             frame[s1_row][s1_col] = block_num + 1;
                //             outside_zero = false;
                //         }
                //         else if(slices[block_num][block_idx++] == 0)
                //         {
                //             s1_col--;
                //         }
                //     }
                // }
                // if (!is_overlap)
                // {
                //     block_num++;
                //     if (block_num == n)
                //     {
                //         for (int r = 0; r < square_size; r++)
                //             {
                //                 for (int l = 0; l < square_size; l++)
                //                 {
                //                     cout << frame[r][l];
                //                 }
                //                 cout << endl;
                //             }
                //         return true;
                //     }
                    can_cover = cover(block_num, square_size, slices, n);
                //}
                

            }
        }
    }

    return can_cover;
}
//첫번째로 1인 값을 넘겨주어야함
int putTile(int block_num, int square_size, vector<int> slices[], vector<bool> visited[], int row, int col, int tile_idx)
{
    int height = slices[block_num][0];
    int width = slices[block_num][1];
    int res;
    if(slices[block_num][tile_idx] == 0)
        return 0;
    else if(row > square_size)
        return 0;
    else if(col > square_size)
        return 0;
    else if(visited[block_num][tile_idx-2] == true)
        return 0;
    else
    {
        frame[row][col] = slices[block_num][tile_idx];
        int left = 0, right = 0, down = 0;
        if((tile_idx-2) % width != 0)
            left = putTile(block_num, square_size, slices, visited, row, col-1, tile_idx-1);
        if((tile_idx-2) % width != width-1)
            right = putTile(block_num, square_size, slices, visited,  row, col+1, tile_idx+1);
        if(tile_idx-2 + width < height*width)
            down = putTile(block_num, square_size, slices, visited, row+1, col, tile_idx+width);

        res = 1 + left + right + down;
    }
    
    return res;

}