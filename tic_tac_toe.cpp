#include<bits/stdc++.h>
using namespace std;

void display(char board[3][3])
{
    cout<<"      |"<<"    |"<<endl;
    cout<<"  "<<board[0][0]<<"     "<<board[0][1]<<"      "<<board[0][2]<<endl;
    cout<<"      |"<<"    |"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"      |"<<"    |"<<endl;
    cout<<"  "<<board[1][0]<<"     "<<board[1][1]<<"      "<<board[1][2]<<endl;
    cout<<"      |"<<"    |"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"      |"<<"    |"<<endl;
    cout<<"  "<<board[2][0]<<"     "<<board[2][1]<<"      "<<board[2][2]<<endl    ;
    cout<<"      |"<<"    |"<<endl<<endl;
}

void set_board(char board[3][3])
{
        char k='0';
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                board[i][j]=k;
                k++;
            }
        }

}

void edit_board(char board[3][3],int choice,char replace)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]==choice)
            {
                board[i][j]=replace;
            }
        }
    }
}

string check(char board[3][3],char p1,char p2)
{
    // for row elements

    int same_p1=0,same_p2=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]==p1)
            {
                same_p1++;
            }
            else if(board[i][j]==p2)
            {
                same_p2++;
            }
        }
        if(same_p1==3)
        {
            return "first";
        }
        else if(same_p2==3)
        {
            return "second";
        }
      
        same_p1=0;
        same_p2=0;
    }

    // for column elements

    same_p1=0;
    same_p2=0;

    for(int j=0;j<3;j++)
    {
        for(int i=0;i<3;i++)
        {
            if(board[i][j]==p1)
            {
                same_p1++;
            }
            else if(board[i][j]==p2)
            {
                same_p2++;
            }
        }
        if(same_p1==3)
        {
            return "first";
        }
        else if(same_p2==3)
        {
            return "second";
        }
        
        same_p1=0;
        same_p2=0;
    }

    same_p1=0;
    same_p2=0;

    // for diagonal elements 
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j)
            {
                if(board[i][j]==p1)
                {
                    same_p1++;
                }
                else if(board[i][j]==p2)
                {
                    same_p2++;
                }

                break;
            }
        }
        if(same_p1==3)
        {
            return "first";
        }
        else if(same_p2==3)
        {
            return "second";
        }
       
    }

    same_p1=0;
    same_p2=0;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i+j==2)
            {
                if(board[i][j]==p1)
                {
                    same_p1++;
                }
                else if(board[i][j]==p2)
                {
                    same_p2++;
                }

                break;
            }
        }
        if(same_p1==3)
        {
            return "first";
        }
        else if(same_p2==3)
        {
            return "second";
        }
       
    }


    return "draw";
}
int main()
{
    char board[3][3],p1,p2,choice;
    int count,select;
    string store_result="";

    cout<<endl;
    cout<<"                        ----Let's Play Tic-Tac Toe----"<<endl;
    cout<<endl;

    do
    {
        cout<<"                                1.Start"<<endl;
        cout<<"                                2.Exit"<<endl;
        cout<<"What do you want to do : ";
        cin>>select;
        switch(select)
        {
            case 1:
            {   
                cout<<"First Player Choose (O/X) : ";
                cin>>p1;
                cout<<endl;
                cout<<"Second Player Choose (O/X) : ";
                cin>>p2;
                cout<<endl;

                set_board(board);
                display(board);

                char enter_char=p1;
                count=1;
                while(count<=9)
                {
                    cout<<"Choose the Box Number you Want to mark : ";
                    cin>>choice;
                    count++;
                    edit_board(board,choice,enter_char);
                    display(board);
                    store_result=check(board,p1,p2);
                    if(store_result=="first" || store_result=="second")
                    {
                        break;
                    }
                    else
                    {
                        if(enter_char==p1)
                        {
                            enter_char=p2;
                        }
                        else
                        {
                            enter_char=p1;
                        }
                    }
                
                }
                
                if(store_result=="draw")
                {
                    cout<<endl;
                    cout<<"Draw"<<endl;
                    cout<<"                         Do you want to continue?"<<endl;
                }
                else if(store_result=="first")
                {
                    cout<<endl;
                    cout<<"First Player Win With the Charater "<<p1<<endl<<endl;
                    cout<<"                         Do you want to continue?"<<endl;
                }
                else
                {
                    cout<<endl;
                    cout<<"Second Player Win With the Charater "<<p2<<endl<<endl;
                    cout<<"                         Do you want to continue?"<<endl;
                }
                break;
            }
            case 2:
                exit(0);

            default:
                cout<<endl;
                cout<<"Invalid Choice"<<endl<<endl;
        }
    }while(1);


    
    return 0;
}