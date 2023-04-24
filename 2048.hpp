//JGD

#include<iostream>
#include<random>

class game
{
    private:
        int board[4][4];
    public:
        game();
        void print_board();
        void start_game();
        void play();
        void up();
        void down();
        void left();
        void right();
};

game::game()
{
    for(int i = 0 ; i < 4 ; i++)
        for(int j = 0 ; j < 4 ; j++)
            board[i][j] = 0;
}

void game::print_board()
{
    //it should be like
    /*
    _________________________________
    |       |       |       |       |
    |   O   |   X   |   O   |   2   |
    |_______|_______|_______|_______|
    |       |       |       |       |
    |   X   |   X   |   O   |   4   |
    |_______|_______|_______|_______|
    |       |       |       |       |
    |   X   |   O   |   X   |   8   |
    |_______|_______|_______|_______|
    |       |       |       |       |
    |   2   |   4   |   8   |   16  |
    |_______|_______|_______|_______|
    */
   system("clear");
   std::cout<<"_________________________________"<<"\n";
    for(int i = 0 ; i < 4 ; i++)
    {
         std::cout<<"|       |       |       |       |"<<"\n";
         for(int j = 0 ; j < 4 ; j++)
         {
              if(board[i][j] == 0)
                std::cout<<"|       ";
              else
              {
                    if(board[i][j] < 10)
                        std::cout<<"|   "<<board[i][j]<<"   ";
                    else if(board[i][j] < 100)
                        std::cout<<"|   "<<board[i][j]<<"  ";
                    else if(board[i][j] < 1000)
                        std::cout<<"|   "<<board[i][j]<<" ";
                    else
                        std::cout<<"|  "<<board[i][j]<<" ";
              }
         }
         std::cout<<"|"<<"\n";
         std::cout<<"|_______|_______|_______|_______|"<<"\n";
    }
}

void game::down()
{
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            if( board[i][j] == board[i+1][j] )
            {
                board[i+1][j] = board[i][j] + board[i+1][j];
                board[i][j] = 0;
            }
            if( board[i+1][j] == 0 )
            {
                board[i+1][j] = board[i][j];
                board[i][j] = 0;
            }
        }
    }

    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            if( board[i+1][j] == 0 )
            {
                board[i+1][j] = board[i][j];
                board[i][j] = 0;
            }
        }
    }
}

void game::up()
{
    for(int i = 3 ; i > 0 ; i--)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            if( board[i][j] == board[i-1][j] )
            {
                board[i-1][j] = board[i][j] + board[i-1][j];
                board[i][j] = 0;
            }
            if( board[i-1][j] == 0)
            {
                board[i-1][j] = board[i][j];
                board[i][j] = 0;
            }
        }
    }

    for(int i = 3 ; i > 0 ; i--)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            if( board[i-1][j] == 0)
            {
                board[i-1][j] = board[i][j];
                board[i][j] = 0;
            }
        }
    } 
}

void game::right()
{
    for(int j = 0 ; j < 3 ; j++)
    {
        for(int i = 0 ; i < 4 ; i++)
        {
            if( board[i][j] == board[i][j+1] )
            {
                board[i][j+1] = board[i][j] + board[i][j+1];
                board[i][j] = 0;
            }
            if( board[i][j+1] == 0 )
            {
                board[i][j+1] = board[i][j];
                board[i][j] = 0;
            }
        }
    }

    for(int j = 0 ; j < 3 ; j++)
    {
        for(int i = 0 ; i < 4 ; i++)
        {
            if( board[i][j+1] == 0 )
            {
                board[i][j+1] = board[i][j];
                board[i][j] = 0;
            }
        }
    }
}

void game::left()
{
    for(int j = 3 ; j > 0 ; j--)
    {
        for(int i = 0 ; i < 4 ; i++)
        {
            if( board[i][j] == board[i][j-1] )
            {
                board[i][j-1] = board[i][j] + board[i][j-1];
                board[i][j] = 0;
            }
            if( board[i][j-1] == 0 )
            {
                board[i][j-1] = board[i][j];
                board[i][j] = 0;
            }
        }
    }

    for(int j = 3 ; j > 0 ; j--)
    {
        for(int i = 0 ; i < 4 ; i++)
        {
            if( board[i][j-1] == 0 )
            {
                board[i][j-1] = board[i][j];
                board[i][j] = 0;
            }
        }
    }
}

void game::start_game()
{
    //int x = rand()%16;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 15);

    int x = dis(gen);
board[x/4][x%4] = 2; 
}

void game::play()
{
    char ch;
    while(1)
    {
        int flag = 1;
        for(int i = 0 ; i < 4 ; i++)
        {
            for(int j = 0 ; j < 4 ; j++)
            {
                if(board[i][j] == 0)
                {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 1)
        {
            std::cout<<"Game Over"<<"\n";
            break;
        }
        while(1)
        {   
            //int x = rand()%16;
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, 15);

            int x = dis(gen);
            if(board[x/4][x%4] == 0)
            {
                board[x/4][x%4] = 2;
                break;
            }
        }
        print_board();
        std::cout<<"Enter your move : ";
        std::cin>>ch;
        switch(ch)
        {
            case 'w' : up();
                       break;
            case 's' : down();
                       break;
            case 'a' : left();
                       break;
            case 'd' : right();
                       break;
            default  : std::cout<<"Wrong input"<<"\n";
                       break;
        }
    }
  
}




        