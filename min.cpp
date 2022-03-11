#include <time.h>
#include<stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;
#include "clui.h"
#define n 5
bool gameover=true;
int score=0;
int flag=0;
void random_placement(char home_situation[n][n],int size)
{
    int bomb=0;
    srand(time(NULL));
    while(bomb<6)
    {
        int i=rand()%5;
        int j=rand()%5;
        if(home_situation[i][j]=='*')
            continue;
        else
            {
                home_situation[i][j]='*';
                bomb++;
            }
    }
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
    {
        if(home_situation[i][j]=='*')
            continue;
        else
        {
            int Number_of_bombs=0;
            for(int k=i-1;k<i+2;k++)
            for(int z=j-1;z<j+2;z++)
            {
                if(k<0||k>4||z<0||z>4)continue;
                else {
                    if(home_situation[k][z]=='*')
                        Number_of_bombs++;
                     }
            }
            home_situation[i][j]=Number_of_bombs;
        }
    }

}
void print_board_X(char print_board[n][n],int size)
    {
        for(int i=0;i<size;i++)
            {
            for(int j=0;j<size;j++)
            {
            if(print_board[i][j]=='X'||print_board[i][j]=='F'||print_board[i][j]=='*')
            cout<<print_board[i][j]<<" ";
            else printf("%d ",print_board[i][j]);
            }
            cout<<endl;
            }
    }
void print_board_x_y(char print_board[n][n],char home_situation[n][n],char x,char y)
    {
        if(print_board[x][y]=='F')
        {
                cout<<"your choosen home is flaged"<<endl<<"please choose another home"<<endl;
        }
        else if(home_situation[x][y]=='*')
            gameover=false;
        else if(print_board[x][y]=='X')
        {
                print_board[x][y]=home_situation[x][y];score++;
        }
        print_board_X(print_board,n);
    }
void print_board_x_y_flag(char print_board[n][n],char x,char y)
    {
        if(print_board[x][y]=='F')
        {
            print_board[x][y]='X';
            flag--;
        }
        else if(flag<6 && print_board[x][y]=='X')
        {
            print_board[x][y]='F';
            flag++;
        }
        else if( print_board[x][y]<9 && print_board[x][y]>-1)
            cout<<"this home is opened"<<endl<<"choose another home"<<endl;
        else
        cout<<"flags are compelete"<<endl<<"please choose another  home"<<endl;
        print_board_X(print_board,n);
    }
void play_mine_game()
{
    init_clui();
    char print_board[n][n],home_situation[n][n];
    random_placement(home_situation,n);
    /*for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
            if(home_situation[i][j]=='*')
        cout<<home_situation[i][j]<<" ";
    else printf("%d ",home_situation[i][j]);}cout<<endl;}*/
    for(int i=0;i<5;i++)
        for(int j=0;j<n;j++)
        print_board[i][j]='X';
    print_board_X(print_board,n);
    while(gameover&&score<19)
    {
        cout<<"please inter your choice:"<<endl;
        cout<<"0=flag or unflag"<<endl;
        cout<<"1=open home"<<endl;
        char condition=getch();
        if(condition=='1')
        {
            int x,y;
            bool check=true;
            while(check)
            {
            cout<<"please inter X coordinate:(0<X<6)"<<endl;
            cin>>x;
            x--;
            if(x>4||x<0)
                cout<<"invalid coordinate"<<endl<<"enter another X"<<endl;
                else check=false;
            }
            check=true;
            while(check)
            {
            cout<<"please inter Y coordinate:(0<Y<6)"<<endl;
            cin>>y;
            y--;
            if(y>4||y<0)
                cout<<"invalid coordinate"<<endl<<"enter another Y"<<endl;
            else check=false;
            }
            clear_screen();
            print_board_x_y(print_board,home_situation,x,y);
        }
        else if(condition=='0')
        {
            int x,y;
             bool check=true;
            while(check)
            {
            cout<<"please inter X coordinate:(0<X<6)"<<endl;
            cin>>x;
            x--;
            if(x>4||x<0)
                cout<<"invalid coordinate"<<endl<<"enter another X"<<endl;
                else check=false;
            }
            check=true;
            while(check)
            {
            cout<<"please inter Y coordinate:(0<Y<6)"<<endl;
            cin>>y;
            y--;
            if(y>4||y<0)
                cout<<"invalid coordinate"<<endl<<"enter another Y"<<endl;
            else check=false;
            }
            clear_screen();
            print_board_x_y_flag(print_board,x,y);
        }
        else
        {
            clear_screen();
            print_board_X(print_board,n);
            cout<<"invalid number"<<endl<<"choose another number"<<endl;
        }
    }
    clear_screen();
    print_board_X(home_situation,n);
    if(score>=19)
    cout<<"Congratulations! you won(:"<<endl<<"You emptied all the houses";
    else
    cout<<"Unfortunately! you lost:("<<endl<<"The bomb exploded"<<endl;
}
int main()
{
play_mine_game();
return 0;
}




