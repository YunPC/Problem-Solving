#include <iostream>
#include <cmath>

using namespace std;

int polys[5][4][4];
int frame[8][8];
int h[5];
int w[5];
int n, m;

bool cover();

int main()
{
    int one_cnt = 0;
    bool is_square = false;
    int possible_square_num[8] = {1, 4, 9, 16, 25, 36, 49, 64};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i] >> w[i];
        for (int j = 0; j < h[i]; j++)
        {
            for (int k = 0; k < w[i]; k++)
            {
                cin >> polys[i][j][k];
                if (polys[i][j][k] == 1)
                    one_cnt++;
            }
        }
    }

    for (int idx = 0; idx < 8; idx++)
    {
        if (one_cnt == possible_square_num[idx])
        {
            is_square = true;
            m = (int)sqrt(possible_square_num[idx]);
            for (int i = 0; i < n; i++)
            {
                if (h[i] > m || w[i] > m)
                    is_square = false;
            }
            break;
        }
    }

    if (is_square)
    {
        if (cover())
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << frame[i][j] << " ";
                }
                if(i < m-1)
                    cout << endl;
            }
        }
        else
        {
            cout << "No solution possible";
        }
    }
    else
    {
        cout << "No solution possible";
    }
}

bool cover()
{
    bool can_cover = false;
    int block = 0;
    //block(0)
    for (int idx1 = 0; idx1 < (m - w[block] + 1) * (m - h[block] + 1); idx1++)
    {
        int r = idx1 / (m - w[block] + 1), c = idx1 % (m - w[block] + 1);
        // place block
        for (int r_idx = 0; r_idx < h[block]; r_idx++)
        {
            for (int c_idx = 0; c_idx < w[block]; c_idx++)
            {
                frame[r + r_idx][c + c_idx] = polys[block][r_idx][c_idx];
            }
        }
        block++;
        // check next block(1)
        if (block < n)
        {
            for (int idx2 = 0; idx2 < (m - w[block] + 1) * (m - h[block] + 1); idx2++)
            {
                bool overlap_flag = false;
                int r = idx2 / (m - w[block] + 1), c = idx2 % (m - w[block] + 1);
                // place block
                for (int r_idx = 0; r_idx < h[block]; r_idx++)
                {
                    for (int c_idx = 0; c_idx < w[block]; c_idx++)
                    {

                        if (polys[block][r_idx][c_idx] != 0)
                        {
                            if (frame[r + r_idx][c + c_idx] == 0)
                                frame[r + r_idx][c + c_idx] = block + 1;
                            else
                            {
                                overlap_flag = true;
                            }
                        }
                    }
                }
                //wrong place
                if (overlap_flag)
                {
                    for (int r_idx = 0; r_idx < h[block]; r_idx++)
                    {
                        for (int c_idx = 0; c_idx < w[block]; c_idx++)
                        {
                            if (frame[r + r_idx][c + c_idx] == block + 1)
                                frame[r + r_idx][c + c_idx] = 0;
                        }
                    }
                    continue;
                }
                //check next block(2)
                block++;
                if (block < n)
                {
                    for (int idx3 = 0; idx3 < (m - w[block] + 1) * (m - h[block] + 1); idx3++)
                    {
                        bool overlap_flag = false;
                        int r = idx3 / (m - w[block] + 1), c = idx3 % (m - w[block] + 1);
                        // place block(2)
                        for (int r_idx = 0; r_idx < h[block]; r_idx++)
                        {
                            for (int c_idx = 0; c_idx < w[block]; c_idx++)
                            {

                                if (polys[block][r_idx][c_idx] != 0)
                                {
                                    if (frame[r + r_idx][c + c_idx] == 0)
                                        frame[r + r_idx][c + c_idx] = block + 1;
                                    else
                                    {
                                        overlap_flag = true;
                                    }
                                }
                            }
                        }
                        //wrong place(2)
                        if (overlap_flag)
                        {
                            for (int r_idx = 0; r_idx < h[block]; r_idx++)
                            {
                                for (int c_idx = 0; c_idx < w[block]; c_idx++)
                                {
                                    if (frame[r + r_idx][c + c_idx] == block + 1)
                                        frame[r + r_idx][c + c_idx] = 0;
                                }
                            }
                            continue;
                        }
                        //check next block(3)
                        block++;
                        if (block < n)
                        {
                            for (int idx4 = 0; idx4 < (m - w[block] + 1) * (m - h[block] + 1); idx4++)
                            {
                                bool overlap_flag = false;
                                int r = idx4 / (m - w[block] + 1), c = idx4 % (m - w[block] + 1);
                                // place block(3)
                                for (int r_idx = 0; r_idx < h[block]; r_idx++)
                                {
                                    for (int c_idx = 0; c_idx < w[block]; c_idx++)
                                    {

                                        if (polys[block][r_idx][c_idx] != 0)
                                        {
                                            if (frame[r + r_idx][c + c_idx] == 0)
                                                frame[r + r_idx][c + c_idx] = block + 1;
                                            else
                                            {
                                                overlap_flag = true;
                                            }
                                        }
                                    }
                                }
                                //wrong place(3)
                                if (overlap_flag)
                                {
                                    for (int r_idx = 0; r_idx < h[block]; r_idx++)
                                    {
                                        for (int c_idx = 0; c_idx < w[block]; c_idx++)
                                        {
                                            if (frame[r + r_idx][c + c_idx] == block + 1)
                                                frame[r + r_idx][c + c_idx] = 0;
                                        }
                                    }
                                    continue;
                                }
                                //check next block(4)
                                block++;
                                if(block < n)
                                {
                                    for (int idx5 = 0; idx5 < (m - w[block] + 1) * (m - h[block] + 1); idx5++)
                                    {
                                        bool overlap_flag = false;
                                        int r = idx5 / (m - w[block] + 1), c = idx5 % (m - w[block] + 1);
                                        //place block(4)
                                        for (int r_idx = 0; r_idx < h[block]; r_idx++)
                                        {
                                            for (int c_idx = 0; c_idx < w[block]; c_idx++)
                                            {

                                                if (polys[block][r_idx][c_idx] != 0)
                                                {
                                                    if (frame[r + r_idx][c + c_idx] == 0)
                                                        frame[r + r_idx][c + c_idx] = block + 1;
                                                    else
                                                    {
                                                        overlap_flag = true;
                                                    }
                                                }
                                            }
                                        }
                                        //wrong place(4)
                                        if (overlap_flag)
                                        {
                                            for (int r_idx = 0; r_idx < h[block]; r_idx++)
                                            {
                                                for (int c_idx = 0; c_idx < w[block]; c_idx++)
                                                {
                                                    if (frame[r + r_idx][c + c_idx] == block + 1)
                                                        frame[r + r_idx][c + c_idx] = 0;
                                                }
                                            }
                                            continue;
                                        }
                                        return true;
                                        
                                    }
                                }
                                else
                                {
                                    can_cover = true;
                                }
                                block--;
                                if(can_cover)
                                    return true;
                                else
                                {
                                    //erase block(3)
                                    for (int r_idx = 0; r_idx < h[block]; r_idx++)
                                    {
                                        for (int c_idx = 0; c_idx < w[block]; c_idx++)
                                        {
                                            if (frame[r + r_idx][c + c_idx] == block + 1)
                                                frame[r + r_idx][c + c_idx] = 0;
                                        }
                                    }
                                }
                                
                                
                            }
                        }
                        else
                        {
                            can_cover = true;
                        }
                        block--;
                        if(can_cover)
                            return true;
                        else
                        {
                            //erase block(2)
                            for (int r_idx = 0; r_idx < h[block]; r_idx++)
                            {
                                for (int c_idx = 0; c_idx < w[block]; c_idx++)
                                {
                                    if (frame[r + r_idx][c + c_idx] == block + 1)
                                        frame[r + r_idx][c + c_idx] = 0;
                                }
                            }
                        }
                        
                    }
                }
                else
                {
                    can_cover = true;
                }
                block--;
                if (can_cover)
                    return true;
                else
                {
                    //erase block
                    for (int r_idx = 0; r_idx < h[block]; r_idx++)
                    {
                        for (int c_idx = 0; c_idx < w[block]; c_idx++)
                        {
                            if (frame[r + r_idx][c + c_idx] == block + 1)
                                frame[r + r_idx][c + c_idx] = 0;
                        }
                    }
                }
            }
        }
        else
        {
            can_cover = true;
        }
        block--;
        // erase block
        if (can_cover)
            return true;
        else
        {
            for (int r_idx = 0; r_idx < h[block]; r_idx++)
            {
                for (int c_idx = 0; c_idx < w[block]; c_idx++)
                {
                    if (frame[r + r_idx][c + c_idx] == block + 1)
                        frame[r + r_idx][c + c_idx] = 0;
                }
            }
        }
    }
    return false;
}