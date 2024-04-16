#include<iostream>
#include<windows.h>
#include<fstream>
#include<math.h>
using namespace std;
#define abaad 19
void jaygozary (int makaneSefid[2], int makaneSiah[2] , char zamin[abaad][abaad], int sefid[2] , int  siah[2] );
void print (char zamin[abaad][abaad] , HANDLE h);
void jaygozary2 (int makanesefid1[2] , int makanesefid2[2], int makanesiah1[2], int makanesiah2[2] , char zamin[abaad][abaad], int sefid1[2] , int  siah1[2] , int sefid2[2] , int siah2[2]);
void print2 (char zamin[abaad][abaad] , HANDLE h);
void printeror1(HANDLE h);
void printeror2(HANDLE h);
int game2players( int winer , string user2[2]);///// بازی دونفره تکمهره ای
int game2players2( int winer , string user2[2]);
int game2playersDaliz( int winer , string user2[2]);
int game4players( int winer , string user2[4]);
int game4playersDaliz( int winer , string user2[4]);

void harekat2( int sabz[2]  , int makanesabz[2], char zamin[abaad][abaad]);
void harekat1( int sabz[2]  , int makanesabz[2], char zamin[abaad][abaad]);
void jaygozary4players (int makaneSefid[2],int makaneSiah[2],int makanesabz[2],int makanezard[2],char zamin[abaad][abaad],int sefid[2],int  siah[2],int sabz[2],int zard[2]);

void jaygozary4playersDaliz (int makaneSefid[2],int makaneSiah[2],int makanesabz[2],int makanezard[2],char zamin[abaad][abaad],int sefid[2],int  siah[2],int sabz[2],int zard[2]);

void jaygozary2playersDaliz (int makaneSefid[2], int makaneSiah[2] , char zamin[abaad][abaad], int sefid[2] , int  siah[2] , int noeparcham);

void print4players (char zamin[abaad][abaad] , HANDLE h , int wall1 , int wall2 , int wall3 ,int wall4);

void print4playersDaliz (char zamin[abaad][abaad] , HANDLE h , int wall1 , int wall2 , int wall3 ,int wall4);

void  name(string *user , int *score , string *user2 , int two);//اضافه کردن اسم به فایل
void  name2(string *user , int *score);//نشان دادن لیدربورد اول بازی
void win(string * user ,int *score  , string *user2 , int winer); //اضافه کردن امتیاز به امتیاز کاربر برنده و ذخیره در فایل
void Markgozari (char zamin[19][19],int mark[19][19]);
int is_valid(int x, int y ,int mark[19][19]);
void dfs (int mark[19][19],int x , int y);
int errorDivar (int d[2][2],int mark[19][19],int zamin[19][19]);
void printleaderboard(string user[100] , int score[100]);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    char a[1];
    int winer=124  ;
    int score[100];
    string user[100],user2[4] , username ;
    while (true)
    {

        cout << "welcome to Couridor Game" << endl;
        cout << "1 Two Player classic" << endl;
        cout << "2 Two Player X2 classic" << endl;
        cout << "3 Four-player classic" << endl;
        cout << "4 Two Player Daliz " << endl;
        cout << "5 Four player Daliz" << endl;
        cout << "6 Contact us" << endl;
        cout << "7 Leaderboard" << endl;
        cout << "8 Exit" << endl;
        cout<< "Enter a number:";
        cin >> a[0] ;
        // شروع بازی دونفره
        if ( a[0]=='1') // Two Player game
        {
            for(int i=0 ; i<2 ; i++)
                name( user , score , user2 , i );//عدد آخر برای اینه که تابع بفهمه بازیکن چندمو باید وارد فایل کنه

            win( user , score , user2 , game2players(winer , user2));//عدد آخر نشون میده که کدوم بازیکن برنده شده
        }
        // اتمام بازی دونفره
        else if ( a[0]=='2') // Double Game with 2 vertebrae
        {
            for(int i=0 ; i<2 ; i++)
                name( user , score , user2 , i );
            win( user , score , user2 , game2players2(winer , user2));
        }
        else if ( a[0]=='3') // Four-player Game
        {
            for(int i=0 ; i<4 ; i++)
                name( user , score , user2 , i );
            win( user , score , user2 , game4players(winer , user2));
        }
        else if ( a[0]=='4') // Two Player Daliz
        {
            for(int i=0 ; i<2 ; i++)
                name( user , score , user2 , i );//عدد آخر برای اینه که تابع بفهمه بازیکن چندمو باید وارد فایل کنه
            win( user , score , user2 , game2playersDaliz(winer , user2));//عدد آخر نشون میده که کدوم بازیکن برنده شده
        }
        else if ( a[0]=='5') // Four-player Game Daliz
        {
            for(int i=0 ; i<4 ; i++)
                name( user , score , user2 , i );
            win( user , score , user2 , game4playersDaliz(winer , user2));
        }
        else if ( a[0]=='6') // Contact us
        {
            cout<<"akgh1382@gmail.com"<<endl;
            cout << "talaei.pouria06@gmail.com" << endl;
            cout << "dallalfateme2512003@gmail.com" << endl;
        }
        else if ( a[0]=='7') // Leaderboard
        {
            name2(user , score);
            printleaderboard( user , score);
        }
        else if ( a[0]=='8') // Exit
        {
            cout<<"good bye"<<endl;
            return 0;
        }
        else
        {
            printeror1(h);
            continue;
        }
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void jaygozary (int makaneSefid[2], int makaneSiah[2] , char zamin[abaad][abaad], int sefid[2] , int  siah[2] )
{


    for (int i=0;i<abaad;i++)
        for(int j=0;j<abaad;j++)
        {
            if(i % 2 == 1 && j % 2 == 1)
            {
                zamin[i][j]='*';
            }
            else if(i % 2 ==1 && j % 2 == 0 && zamin[i][j] != '|')
            {
                zamin[i][j]= ' ';//                zamin[i][j]= '|';
            }
            else if (j % 2 ==1 && i % 2 == 0 && zamin[i][j] != '-')
            {
                zamin[i][j] = ' ';//                zamin[i][j] = '-';
            }
            else if (zamin[i][j] == '|' || zamin[i][j] == '-')
            {

            }
            else zamin[i][j] = ' ';
        }
    zamin [makaneSefid[0]][makaneSefid[1]] = 'R';
    sefid[0]=makaneSefid[0];
    sefid[1]=makaneSefid[1];

    zamin [makaneSiah[0]][makaneSiah[1]] = 'B';
    siah[0]=makaneSiah[0];
    siah[1]=makaneSiah[1];

    for (int i=0,j=1;j<abaad-1;j+=2) // چاپ دیوار بالا
    {
        zamin[i][j] = '-';
    }
    for (int i=abaad-1,j=1;j<abaad-1;j+=2) // چاپ دیوار پایین
    {
        zamin[i][j] = '-';
    }
    for (int i = 1,j=0;i<abaad-1;i+=2) //چاپ دیوار چپ
    {
        zamin[i][j] = '|';
    }
    for (int i = 1,j=abaad-1;i<abaad-1;i+=2) //چاپ دیوار راست
    {
        zamin[i][j] = '|';
    }

}
void jaygozary4players (int makaneSefid[2], int makaneSiah[2] ,int makanesabz[2],int makanezard[2], char zamin[abaad][abaad], int sefid[2] , int  siah[2] ,int sabz[2] , int zard[2])
{


    for (int i=0;i<abaad;i++)
        for(int j=0;j<abaad;j++)
        {
            if(i % 2 == 1 && j % 2 == 1)
            {
                zamin[i][j]='*';
            }
            else if(i % 2 ==1 && j % 2 == 0 && zamin[i][j] != '|')
            {
                zamin[i][j]= ' ';//                zamin[i][j]= '|';
            }
            else if (j % 2 ==1 && i % 2 == 0 && zamin[i][j] != '-')
            {
                zamin[i][j] = ' ';//                zamin[i][j] = '-';
            }
            else if (zamin[i][j] == '|' || zamin[i][j] == '-')
            {

            }
            else zamin[i][j] = ' ';
        }
    zamin [makaneSefid[0]][makaneSefid[1]] = 'R';
    sefid[0]=makaneSefid[0];
    sefid[1]=makaneSefid[1];
    zamin [makanezard[0]][makanezard[1]] = 'Y';
    zard[0]=makanezard[0];
    zard[1]=makanezard[1];
    zamin [makanesabz[0]][makanesabz[1]] = 'G';
    sabz[0]=makanesabz[0];
    sabz[1]=makanesabz[1];
    zamin [makaneSiah[0]][makaneSiah[1]] = 'B';
    siah[0]=makaneSiah[0];
    siah[1]=makaneSiah[1];

    for (int i=0,j=1;j<abaad-1;j+=2) // چاپ دیوار بالا
    {
        zamin[i][j] = '-';
    }
    for (int i=abaad-1,j=1;j<abaad-1;j+=2) // چاپ دیوار پایین
    {
        zamin[i][j] = '-';
    }
    for (int i = 1,j=0;i<abaad-1;i+=2) //چاپ دیوار چپ
    {
        zamin[i][j] = '|';
    }
    for (int i = 1,j=abaad-1;i<abaad-1;i+=2) //چاپ دیوار راست
    {
        zamin[i][j] = '|';
    }

}

void jaygozary4playersDaliz (int makaneSefid[2],int makaneSiah[2],int makanesabz[2],int makanezard[2],char zamin[abaad][abaad],int sefid[2],int  siah[2],int sabz[2],int zard[2])
{

    for (int i=0;i<abaad;i++)
        for(int j=0;j<abaad;j++)
        {
            if(i % 2 == 1 && j % 2 == 1)
            {
                zamin[i][j]='*';
            }
            else if(i % 2 ==1 && j % 2 == 0 && zamin[i][j] != '|')
            {
                zamin[i][j]= ' ';//                zamin[i][j]= '|';
            }
            else if (j % 2 ==1 && i % 2 == 0 && zamin[i][j] != '-')
            {
                zamin[i][j] = ' ';//                zamin[i][j] = '-';
            }
            else if (zamin[i][j] == '|' || zamin[i][j] == '-')
            {

            }
            else zamin[i][j] = ' ';
        }
    zamin [makaneSefid[0]][makaneSefid[1]] = 'R';
    sefid[0]=makaneSefid[0];
    sefid[1]=makaneSefid[1];
    zamin [makanezard[0]][makanezard[1]] = 'Y';
    zard[0]=makanezard[0];
    zard[1]=makanezard[1];
    zamin [makanesabz[0]][makanesabz[1]] = 'G';
    sabz[0]=makanesabz[0];
    sabz[1]=makanesabz[1];
    zamin [makaneSiah[0]][makaneSiah[1]] = 'B';
    siah[0]=makaneSiah[0];
    siah[1]=makaneSiah[1];

    for (int i=0,j=1;j<abaad-1;j+=2) // چاپ دیوار بالا
    {
        zamin[i][j] = '-';
    }
    for (int i=abaad-1,j=1;j<abaad-1;j+=2) // چاپ دیوار پایین
    {
        zamin[i][j] = '-';
    }
    for (int i = 1,j=0;i<abaad-1;i+=2) //چاپ دیوار چپ
    {
        zamin[i][j] = '|';
    }
    for (int i = 1,j=abaad-1;i<abaad-1;i+=2) //چاپ دیوار راست
    {
        zamin[i][j] = '|';
    }

    zamin[9][9] = '%';//////DALIZ
}

void jaygozary2playersDaliz (int makaneSefid[2], int makaneSiah[2] , char zamin[abaad][abaad], int sefid[2] , int  siah[2] , int noeeparcham)
{
    for (int i=0;i<abaad;i++)
        for(int j=0;j<abaad;j++)
        {
            if(i % 2 == 1 && j % 2 == 1)
            {
                zamin[i][j]='*';
            }
            else if(i % 2 ==1 && j % 2 == 0 && zamin[i][j] != '|')
            {
                zamin[i][j]= ' ';//                zamin[i][j]= '|';
            }
            else if (j % 2 ==1 && i % 2 == 0 && zamin[i][j] != '-')
            {
                zamin[i][j] = ' ';//                zamin[i][j] = '-';
            }
            else if (zamin[i][j] == '|' || zamin[i][j] == '-')
            {

            }
            else zamin[i][j] = ' ';
        }
    zamin [makaneSefid[0]][makaneSefid[1]] = 'R';
    sefid[0]=makaneSefid[0];
    sefid[1]=makaneSefid[1];

    zamin [makaneSiah[0]][makaneSiah[1]] = 'B';
    siah[0]=makaneSiah[0];
    siah[1]=makaneSiah[1];

    for (int i=0,j=1;j<abaad-1;j+=2) // چاپ دیوار بالا
    {
        zamin[i][j] = '-';
    }
    for (int i=abaad-1,j=1;j<abaad-1;j+=2) // چاپ دیوار پایین
    {
        zamin[i][j] = '-';
    }
    for (int i = 1,j=0;i<abaad-1;i+=2) //چاپ دیوار چپ
    {
        zamin[i][j] = '|';
    }
    for (int i = 1,j=abaad-1;i<abaad-1;i+=2) //چاپ دیوار راست
    {
        zamin[i][j] = '|';
    }
    if (noeeparcham == 1)
    {
        zamin[9][1] = '%';//////DALIZ
    }
    if (noeeparcham==2)
    {
        zamin[9][9] = '%';//////DALIZ
    }
    if (noeeparcham == 3)
    {
        zamin[9][1] = '%';//////DALIZ
        zamin[9][9] = '%';//////DALIZ
    }

}
void jaygozary2 (int makanesefid1[2] , int makanesefid2[2], int makanesiah1[2], int makanesiah2[2] , char zamin[abaad][abaad], int sefid1[2] , int  siah1[2] , int sefid2[2] , int siah2[2])
{


    for (int i=0;i<abaad;i++)
        for(int j=0;j<abaad;j++)
        {
            if(i % 2 == 1 && j % 2 == 1)
            {
                zamin[i][j]='*';
            }
            else if(i % 2 ==1 && j % 2 == 0 && zamin[i][j] != '|')
            {
                zamin[i][j]= ' ';//                zamin[i][j]= '|';
            }
            else if (j % 2 ==1 && i % 2 == 0 && zamin[i][j] != '-')
            {
                zamin[i][j] = ' ';//                zamin[i][j] = '-';
            }
            else if (zamin[i][j] == '|' || zamin[i][j] == '-')
            {

            }
            else zamin[i][j] = ' ';
        }
    zamin [makanesefid1[0]][makanesefid1[1]] = 'A';
    sefid1[0]=makanesefid1[0];
    sefid1[1]=makanesefid1[1];

    zamin[makanesefid2[0]][makanesefid2[1]] = 'B';
    sefid2[0]=makanesefid2[0];
    sefid2[1]=makanesefid2[1];

    zamin[makanesiah2[0]][makanesiah2[1]] = 'D';
    siah2[0]=makanesiah2[0];
    siah2[1]=makanesiah2[1];

    zamin [makanesiah1[0]][makanesiah1[1]] = 'C';
    siah1[0]=makanesiah1[0];
    siah1[1]=makanesiah1[1];

    for (int i=0,j=1;j<abaad-1;j+=2) // چاپ دیوار بالا
    {
        zamin[i][j] = '-';
    }
    for (int i=abaad-1,j=1;j<abaad-1;j+=2) // چاپ دیوار پایین
    {
        zamin[i][j] = '-';
    }
    for (int i = 1,j=0;i<abaad-1;i+=2) //چاپ دیوار چپ
    {
        zamin[i][j] = '|';
    }
    for (int i = 1,j=abaad-1;i<abaad-1;i+=2) //چاپ دیوار راست
    {
        zamin[i][j] = '|';
    }

}
void print2 (char zamin[abaad][abaad] , HANDLE h , int wall1 , int wall2)
{

    system("cls");
    cout << "       ";
    for (int i=1;i<abaad-1;i++)
    {
        if (i<=9)
            cout << i << "  " ;//چاپ اعداد افقی
        else {
            cout << i << " ";
        }
    }
    cout << endl ;
    for(int i = 0; i < abaad; ++i)
    {
        if (i <= 9 && i != 0)
            cout << i << "   ";//چاپ اعداد عمودی
        if (i >= 10 && i != abaad-1)
            cout << i  << "  ";
        if (i==0 || i==abaad-1)
        {
            cout << "    ";
        }

        for(int j = 0; j < abaad; ++j)
        {
            if (zamin [i][j] == '-')
            {
                cout << "-\b\b\b-----";

            }
            else if( zamin [i][j] == 'A')
            {
                SetConsoleTextAttribute(h, 0x4);
                cout<<zamin[i][j]<<"  ";
                SetConsoleTextAttribute(h, 0xf);
            }
            else if( zamin [i][j] == 'B')
            {
                SetConsoleTextAttribute(h, 0x4);
                cout<<zamin[i][j]<<"  ";
                SetConsoleTextAttribute(h, 0xf);
            }
            else if( zamin [i][j] == 'D')
            {
                SetConsoleTextAttribute(h, 0x9);
                cout<<zamin[i][j]<<"  ";
                SetConsoleTextAttribute(h, 0xf);
            }
            else if( zamin [i][j] == 'C')
            {
                SetConsoleTextAttribute(h, 0x9);
                cout<<zamin[i][j]<<"  ";
                SetConsoleTextAttribute(h, 0xf);
            }
            else
            {
                cout<<zamin[i][j]<<"  ";
                if(i==1 && j==abaad-1)
                {
                    cout<<"  Blue Walls = ";
                    SetConsoleTextAttribute(h, 0x9);
                    cout<<wall2;
                    SetConsoleTextAttribute(h, 0xf);
                }
                if(i==17 && j==abaad-1)
                {
                    cout<<"  Red Walls =  ";
                    SetConsoleTextAttribute(h, 0x4);
                    cout<<wall1;
                    SetConsoleTextAttribute(h, 0xf);
                }
            }

            if(j == abaad-1)
                cout << endl;
        }
    }
}
void print (char zamin[abaad][abaad] , HANDLE h , int wall1 , int wall2)
{

    system("cls");
    cout << "       ";
    for (int i=1;i<abaad-1;i++)
    {
        if (i<=9)
            cout << i << "  " ;//چاپ اعداد افقی
        else {
            cout << i << " ";
        }
    }
    cout << endl ;
    for(int i = 0; i < abaad; ++i)
    {
        if (i <= 9 && i != 0)
            cout << i << "   ";//چاپ اعداد عمودی
        if (i >= 10 && i != abaad-1)
            cout << i  << "  ";
        if (i==0 || i==abaad-1)
        {
            cout << "    ";
        }

        for(int j = 0; j < abaad; ++j)
        {
            if (zamin [i][j] == '-')
            {
                cout << "-\b\b\b-----";

            }
            else if( zamin [i][j] == 'B')
            {
                SetConsoleTextAttribute(h, 0x9);
                cout<<zamin[i][j]<<"  ";
                SetConsoleTextAttribute(h, 0xf);
            }
            else if( zamin [i][j] == 'R')
            {
                SetConsoleTextAttribute(h, 0x4);
                cout<<zamin[i][j]<<"  ";
                SetConsoleTextAttribute(h, 0xf);
            }
            else
            {
                cout<<zamin[i][j]<<"  ";
                if(i==1 && j==abaad-1)
                {
                    cout<<"  Blue Walls = ";
                    SetConsoleTextAttribute(h, 0x9);
                    cout<<wall2;
                    SetConsoleTextAttribute(h, 0xf);
                }
                if(i==17 && j==abaad-1)
                {
                    cout<<"  Red Walls =  ";
                    SetConsoleTextAttribute(h, 0x4);
                    cout<<wall1;
                    SetConsoleTextAttribute(h, 0xf);
                }
            }

            if(j == abaad-1)
                cout << endl;
        }
    }
}
void print4players (char zamin[abaad][abaad] , HANDLE h , int wall1 , int wall2 , int wall3 ,int wall4)
{

    system("cls");
    cout << "       ";
    for (int i=1;i<abaad-1;i++)
    {
        if (i<=9)
            cout << i << "  " ;//چاپ اعداد افقی
        else {
            cout << i << " ";
        }
    }
    cout << endl ;
    for(int i = 0; i < abaad; ++i)
    {
        if (i <= 9 && i != 0)
            cout << i << "   ";//چاپ اعداد عمودی
        if (i >= 10 && i != abaad-1)
            cout << i  << "  ";
        if (i==0 || i==abaad-1)
        {
            cout << "    ";
        }

        for(int j = 0; j < abaad; ++j)
        {
            if (zamin [i][j] == '-')
            {
                cout << "-\b\b\b-----";

            }
            else if( zamin [i][j] == 'B')
            {
                SetConsoleTextAttribute(h, 0x9);
                cout<<zamin[i][j]<<"  ";
                SetConsoleTextAttribute(h, 0xf);
            }
            else if( zamin [i][j] == 'R')
            {
                SetConsoleTextAttribute(h, 0x4);
                cout<<zamin[i][j]<<"  ";
                SetConsoleTextAttribute(h, 0xf);
            }
            else if( zamin [i][j] == 'Y')
            {
                SetConsoleTextAttribute(h, 0x6);
                cout<<zamin[i][j]<<"  ";
                SetConsoleTextAttribute(h, 0xf);
            }
            else if( zamin [i][j] == 'G')
            {
                SetConsoleTextAttribute(h, 0xA);
                cout<<zamin[i][j]<<"  ";
                SetConsoleTextAttribute(h, 0xf);
            }

            else
            {
                cout<<zamin[i][j]<<"  ";
                if(i==1 && j==abaad-1)
                {
                    cout<<"  Blue Walls = ";
                    SetConsoleTextAttribute(h, 0x9);
                    cout<<wall2;
                    SetConsoleTextAttribute(h, 0xf);
                }
                if(i==17 && j==abaad-1)
                {
                    cout<<"  Red Walls =  ";
                    SetConsoleTextAttribute(h, 0x4);
                    cout<<wall1;
                    SetConsoleTextAttribute(h, 0xf);
                }
                if(i==6 && j==abaad-1)
                {
                    cout<<" Yellow Walls = ";
                    SetConsoleTextAttribute(h, 0x6);
                    cout<<wall3;
                    SetConsoleTextAttribute(h, 0xf);
                }
                if(i==12 && j==abaad-1)
                {
                    cout<<" Green Walls =  ";
                    SetConsoleTextAttribute(h, 0xA);
                    cout<<wall4;
                    SetConsoleTextAttribute(h, 0xf);
                }
            }

            if(j == abaad-1)
                cout << endl;
        }
    }
}

void print4playersDaliz (char zamin[abaad][abaad] , HANDLE h , int wall1 , int wall2 , int wall3 ,int wall4)
{

    system("cls");
    cout << "       ";
    for (int i=1;i<abaad-1;i++)
    {
        if (i<=9)
            cout << i << "  " ;//چاپ اعداد افقی
        else {
            cout << i << " ";
        }
    }
    cout << endl ;
    for(int i = 0; i < abaad; ++i)
    {
        if (i <= 9 && i != 0)
            cout << i << "   ";//چاپ اعداد عمودی
        if (i >= 10 && i != abaad-1)
            cout << i  << "  ";
        if (i==0 || i==abaad-1)
        {
            cout << "    ";
        }

        for(int j = 0; j < abaad; ++j)
        {
            if (zamin [i][j] == '-')
            {
                cout << "-\b\b\b-----";

            }
            else if( zamin [i][j] == 'B')
            {
                SetConsoleTextAttribute(h, 0x9);
                cout<<zamin[i][j]<<"  ";
                SetConsoleTextAttribute(h, 0xf);
            }
            else if( zamin [i][j] == 'R')
            {
                SetConsoleTextAttribute(h, 0x4);
                cout<<zamin[i][j]<<"  ";
                SetConsoleTextAttribute(h, 0xf);
            }
            else if( zamin [i][j] == 'Y')
            {
                SetConsoleTextAttribute(h, 0x6);
                cout<<zamin[i][j]<<"  ";
                SetConsoleTextAttribute(h, 0xf);
            }
            else if( zamin [i][j] == 'G')
            {
                SetConsoleTextAttribute(h, 0xA);
                cout<<zamin[i][j]<<"  ";
                SetConsoleTextAttribute(h, 0xf);
            }
            else if( zamin [i][j] == '%') //////////////DALIZ
            {
                SetConsoleTextAttribute(h, 0x5);
                cout<<zamin[i][j]<<"  ";
                SetConsoleTextAttribute(h, 0xf);
            }
            else
            {
                cout<<zamin[i][j]<<"  ";
                if(i==1 && j==abaad-1)
                {
                    cout<<"  Blue Walls = ";
                    SetConsoleTextAttribute(h, 0x9);
                    cout<<wall2;
                    SetConsoleTextAttribute(h, 0xf);
                }
                if(i==17 && j==abaad-1)
                {
                    cout<<"  Red Walls =  ";
                    SetConsoleTextAttribute(h, 0x4);
                    cout<<wall1;
                    SetConsoleTextAttribute(h, 0xf);
                }
                if(i==6 && j==abaad-1)
                {
                    cout<<" Yellow Walls = ";
                    SetConsoleTextAttribute(h, 0x6);
                    cout<<wall3;
                    SetConsoleTextAttribute(h, 0xf);
                }
                if(i==12 && j==abaad-1)
                {
                    cout<<" Green Walls =  ";
                    SetConsoleTextAttribute(h, 0xA);
                    cout<<wall4;
                    SetConsoleTextAttribute(h, 0xf);
                }
            }

            if(j == abaad-1)
                cout << endl;
        }
    }

}
void print2playersDaliz (char zamin[abaad][abaad] , HANDLE h , int wall1 , int wall2)
{

    system("cls");
    cout << "       ";
    for (int i=1;i<abaad-1;i++)
    {
        if (i<=9)
            cout << i << "  " ;//چاپ اعداد افقی
        else {
            cout << i << " ";
        }
    }
    cout << endl ;
    for(int i = 0; i < abaad; ++i)
    {
        if (i <= 9 && i != 0)
            cout << i << "   ";//چاپ اعداد عمودی
        if (i >= 10 && i != abaad-1)
            cout << i  << "  ";
        if (i==0 || i==abaad-1)
        {
            cout << "    ";
        }

        for(int j = 0; j < abaad; ++j)
        {
            if (zamin [i][j] == '-')
            {
                cout << "-\b\b\b-----";

            }
            else if( zamin [i][j] == 'B')
            {
                SetConsoleTextAttribute(h, 0x9);
                cout<<zamin[i][j]<<"  ";
                SetConsoleTextAttribute(h, 0xf);
            }
            else if( zamin [i][j] == 'R')
            {
                SetConsoleTextAttribute(h, 0x4);
                cout<<zamin[i][j]<<"  ";
                SetConsoleTextAttribute(h, 0xf);
            }
            else if( zamin [i][j] == '%') //////////////DALIZ
            {
                SetConsoleTextAttribute(h, 0x5);
                cout<<zamin[i][j]<<"  ";
                SetConsoleTextAttribute(h, 0xf);
            }
            else
            {
                cout<<zamin[i][j]<<"  ";
                if(i==1 && j==abaad-1)
                {
                    cout<<"  Blue Walls = ";
                    SetConsoleTextAttribute(h, 0x9);
                    cout<<wall2;
                    SetConsoleTextAttribute(h, 0xf);
                }
                if(i==17 && j==abaad-1)
                {
                    cout<<"  Red Walls =  ";
                    SetConsoleTextAttribute(h, 0x4);
                    cout<<wall1;
                    SetConsoleTextAttribute(h, 0xf);
                }
            }

            if(j == abaad-1)
                cout << endl;
        }
    }
}
void printeror1(HANDLE h)
{
    SetConsoleTextAttribute(h, 0x4);
    cout<<"ba deghat horoof ra vared konid !"<<endl;
    SetConsoleTextAttribute(h, 0xf);
}
void printeror2(HANDLE h)
{
    SetConsoleTextAttribute(h, 0x4);
    cout<<"in harekat mojaz nist!"<<endl;
    SetConsoleTextAttribute(h, 0xf);
}
void Markgozari (char zamin[19][19],int mark[19][19])
{
    for (int i=0;i<19;i++)
        for (int j=0;j<19;j++)
        {
            if ((zamin[i][j]=='-' )||(zamin[i][j] ==  '|') || (i % 2 == 0 && j % 2 == 0))
            {
                mark[i][j]=1;
            }
            else {
                mark[i][j]=0;
            }

        }
    mark[1][1]=1;

}
int is_valid(int x, int y ,int mark[19][19])
{
    if (x<0)
        return 0;
    if (y<0)
        return 0;
    if (x>=19)
        return 0;
    if (y>=19)
        return 0;
    if (mark[x][y]==1)
        return 0;

    return 1;

}

void dfs (int mark[19][19],int x , int y)
{
    if (is_valid(x-1,y,mark)==1)
    {
        mark[x-1][y] =1;
        dfs (mark,x-1,y);
    }
    if (is_valid(x+1,y,mark)==1)
    {
        mark[x+1][y] =1;
        dfs (mark,x+1,y);
    }
    if (is_valid(x,y-1,mark)==1)
    {
        mark[x][y-1] =1;
        dfs (mark,x,y-1);
    }
    if (is_valid(x,y+1,mark)==1)
    {
        mark[x][y+1] =1;
        dfs (mark,x,y+1);
    }

}
int errorDivar (int ss,int aval,int akhar,int mark[19][19])
{
    if ( ss % 2 == 1 || aval % 2 == 0 || akhar %2 == 0)
    {
        return 0;
    }
    for (int i=0;i<19;i++)
        for (int j=0;j<19;j++)
            if (mark[i][j]==0)
            {
                return 0;
            }

    return 1;
}

int game2players( int winer , string user2[2])
{
    char zamin[abaad][abaad];
    int  mark[19][19];
    int  radifstartDFS=1;
    int  sotoonstartDFS=1;
    char NoeHarekat,NoeDivar;
    char harekat[1];
    int sotoonYAsatrdivar,avaldivar,akhardivar;//ابتدا و انتهای دیوار
    int makaneSefid[2]={ abaad-2 , abaad/2},makaneSiah[2]={ 1 , abaad/2};
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int sefid[2],siah[2] ;
    int divar[2][2];//دیوار وارد شده
    int taeen_nobat=1;
    int wall1=10 , wall2=10;
    bool t=true;
    jaygozary (makaneSefid , makaneSiah , zamin , sefid , siah );
    print (zamin , h , wall1 , wall2);
    while (t == true)
    {
        if (taeen_nobat % 2 == 1)
        {
            SetConsoleTextAttribute(h, 0x4);
            cout<<user2[0];
            SetConsoleTextAttribute(h, 0xf);
        }
        else if (taeen_nobat % 2 == 0)
        {
            SetConsoleTextAttribute(h, 0x9);
            cout<<user2[1];
            SetConsoleTextAttribute(h, 0xf);
        }
        cout << " Noe Harekat Ra Vared Konid (d:divar , m:mohreh)";
        cin >> NoeHarekat;

        if (NoeHarekat == 'd' || NoeHarekat == 'D')/////////دیوار
        {
            if(wall1==0 && taeen_nobat % 2 == 1)
            {
                SetConsoleTextAttribute(h, 0x4);
                cout<<" Red ";
                SetConsoleTextAttribute(h, 0xf);
                cout<<"walls = 0"<<endl;
                continue;
            }
            if(wall2==0 && taeen_nobat % 2 == 0)
            {
                SetConsoleTextAttribute(h, 0x9);
                cout<<" Blue ";
                SetConsoleTextAttribute(h, 0xf);
                cout<<"walls = 0"<<endl;
                continue;
            }
            cout << "Noe Divar Ra Vared Konid (a:amoodi , o:ofoghi) ";
            cin >> NoeDivar;
            if (NoeDivar == 'a')
            {
                cout << "Sotoone Divar Ra Vared Konid ";
                cin >> sotoonYAsatrdivar;
                cout << "Ebtedaye Divar Dar Kodam Satr Ast? ";
                cin >> avaldivar;
                cout << "Entehaye Divar Dar Kodam Satr Ast? ";
                cin >> akhardivar;
                if(abs(avaldivar-akhardivar)!=2)
                {
                    printeror2(h);
                    continue;
                }
                divar[0][0] = avaldivar;
                divar[0][1] = sotoonYAsatrdivar;
                divar[1][0]=akhardivar;
                divar[1][1]=sotoonYAsatrdivar;
                zamin[divar[0][0]][divar[0][1]]='|';
                zamin[divar[1][0]][divar[1][1]]='|';
            }
            else if (NoeDivar =='o')
            {
                cout << "Satre Divar Ra Vared Konid ";
                cin >> sotoonYAsatrdivar;
                cout << "Ebtedaye Divar Dar Kodam Sotoon Ast? ";
                cin >> avaldivar;
                cout << "Entehaye Divar Dar Kodam Sotoon Ast? ";
                cin >> akhardivar;
                if(abs(avaldivar-akhardivar)!=2)
                {
                    printeror2(h);
                    continue;
                }
                divar[0][0] = sotoonYAsatrdivar;
                divar[0][1] = avaldivar;
                divar[1][0]=sotoonYAsatrdivar;
                divar[1][1]= akhardivar;
                zamin[divar[0][0]][divar[0][1]]='-';
                zamin[divar[1][0]][divar[1][1]]='-';
            }
            else
            {
                printeror1(h);
                continue;
            }
            Markgozari(zamin,mark);
            dfs (mark,radifstartDFS,sotoonstartDFS);
            if (errorDivar (sotoonYAsatrdivar,avaldivar,akhardivar, mark) == 0 )
            {
                printeror2(h);
                zamin[divar[0][0]][divar[0][1]]=' ';
                zamin[divar[1][0]][divar[1][1]]=' ';
                continue;
            }
            if(taeen_nobat % 2 ==1)
                wall1--;
            if(taeen_nobat % 2 ==0)
                wall2--;
        }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else if (NoeHarekat == 'm' || NoeHarekat == 'M')////////مهره
        {
            bool b=true;
            if (taeen_nobat % 2 == 1)////////سفید
            {
                while (b)
                {
                    cout<<" R (user1) "<<" harekat baadi mohreh ra vared konid (bala=b , paeen=p, chap=c, rast=r, movarab=m)";
                    cin>> harekat[0];

                    if(harekat[0]=='b') /////////// بالا
                    {
                        if(zamin[sefid[0] - 1][sefid[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[sefid[0] - 2][sefid[1]]=='B')
                        {
                            if(zamin[sefid[0] - 3][sefid[1]]=='-')
                            {

                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makaneSefid[0]=sefid[0] - 4;
                                makaneSefid[1]=sefid[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSefid[0]=sefid[0] - 2;
                            makaneSefid[1]=sefid[1];
                            b=false;
                        }
                    }
                    else if(harekat[0]=='p' ) ////////// پایین
                    {
                        if(zamin[sefid[0] + 1][sefid[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        if(zamin[sefid[0] + 2][sefid[1]]=='B')
                        {
                            if(zamin[sefid[0] + 3][sefid[1]]=='-')
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makaneSefid[0]=sefid[0] + 4;
                                makaneSefid[1]=sefid[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSefid[0]=sefid[0] + 2;
                            makaneSefid[1]=sefid[1];
                            b=false;
                        }
                    }
                    else if( harekat[0]=='c' ) ////////// چپ
                    {

                        if(zamin[sefid[0]][sefid[1] - 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        if(zamin[sefid[0]][sefid[1] - 2]=='B')
                        {
                            if(zamin[sefid[0]][sefid[1] - 3]=='|')
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makaneSefid[0]=sefid[0];
                                makaneSefid[1]=sefid[1] - 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSefid[0]=sefid[0];
                            makaneSefid[1]=sefid[1] - 2;
                            b=false;
                        }
                    }
                    else if( harekat[0]=='r' ) ///////// راست
                    {

                        if(zamin[sefid[0]][sefid[1] + 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        if(zamin[sefid[0]][sefid[1] + 2]=='B')
                        {
                            if(zamin[sefid[0]][sefid[1] + 3]=='|')
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makaneSefid[0]=sefid[0];
                                makaneSefid[1]=sefid[1] + 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSefid[0]=sefid[0];
                            makaneSefid[1]=sefid[1] + 2;
                            b=false;
                        }
                    }
                    else if(harekat[0]=='m') //////////// مورب
                    {
                        if( zamin[sefid[0] - 2][sefid[1]]=='B' && zamin[sefid[0] - 3][sefid[1]]=='-')
                        {
                            cout<<"harekat be samt chape B ya harekat be samt raste B?( chape B = c , raste B = r ):";
                            char m[0];
                            cin>>m[0];
                            if(m[0]=='r')
                            {
                                if(zamin[sefid[0] - 1][sefid[1] + 1]=='|' || zamin[sefid[0] - 1][sefid[1]]=='-'
                                        ||zamin[sefid[0] - 1][sefid[1] + 1]=='-')
                                {
                                    printeror2(h);
                                    continue;
                                }
                                else
                                {
                                    makaneSefid[0]=sefid[0] - 2 ;
                                    makaneSefid[1]=sefid[1] + 2 ;
                                    b=false;
                                }
                            }
                            else if(m[0]=='c')
                            {
                                if(zamin[sefid[0] - 1][sefid[1] - 1]=='|' || zamin[sefid[0] - 1][sefid[1]]=='-'
                                        ||zamin[sefid[0] - 1][sefid[1] - 1]=='-')
                                {
                                    printeror2(h);
                                    continue;
                                }
                                else
                                {
                                    makaneSefid[0]=sefid[0] - 2 ;
                                    makaneSefid[1]=sefid[1] - 2 ;
                                    b=false;
                                }
                            }
                        }
                        else
                        {
                            printeror2(h);
                            continue;
                        }
                    }
                    else
                    {
                        printeror1(h);
                        continue;
                    }
                }
            }
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            else if (taeen_nobat % 2 == 0)/////////سیاه
            {
                while (b)
                {
                    cout<<" B (user2) "<<" harekat baadi mohreh ra vared konid (bala=b , paeen=p, chap=c, rast=r, movarab=m):";
                    cin>> harekat[0];

                    if(harekat[0]=='b') //////////// بالا
                    {
                        if(zamin[siah[0] - 1][siah[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        if(zamin[siah[0] - 2][siah[1]]=='R')
                        {
                            if(zamin[siah[0] - 3][siah[1]]=='-')
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makaneSiah[0]=siah[0] - 4;
                                makaneSiah[1]=siah[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSiah[0]=siah[0] - 2;
                            makaneSiah[1]=siah[1];
                            b=false;
                        }
                    }
                    else if(harekat[0]=='p' ) ////////// پایین
                    {
                        if(zamin[siah[0] + 1][siah[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        if(zamin[siah[0] + 2][siah[1]]=='R')
                        {
                            if(zamin[siah[0] + 3][siah[1]]=='-')
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makaneSiah[0]=siah[0] + 4;
                                makaneSiah[1]=siah[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSiah[0]=siah[0] + 2;
                            makaneSiah[1]=siah[1];
                            b=false;
                        }
                    }
                    else if( harekat[0]=='c' ) //////////// چپ
                    {

                        if(zamin[siah[0]][siah[1] - 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        if(zamin[siah[0]][siah[1] - 2]=='R')
                        {
                            if(zamin[siah[0]][siah[1] - 3]=='|')
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makaneSiah[0]=siah[0];
                                makaneSiah[1]=siah[1] - 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSiah[0]=siah[0];
                            makaneSiah[1]=siah[1] - 2;
                            b=false;
                        }
                    }
                    else if( harekat[0]=='r' ) /////////// راست
                    {

                        if(zamin[siah[0]][siah[1] + 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        if(zamin[siah[0]][siah[1] + 2]=='R')
                        {
                            if(zamin[siah[0]][siah[1] + 3]=='|')
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makaneSiah[0]=siah[0];
                                makaneSiah[1]=siah[1] + 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSiah[0]=siah[0];
                            makaneSiah[1]=siah[1] + 2;
                            b=false;
                        }
                    }
                    else if(harekat[0]=='m') //////////// مورب
                    {
                        if( zamin[siah[0] + 2][siah[1]]=='R' && zamin[siah[0] + 3][siah[1]]=='-')
                        {
                            cout<<"harekat be samt chape R ya harekat be samt raste R ?( chape W = c , raste W = r ):";
                            char m[0];
                            cin>>m[0];
                            if(m[0]=='r')
                            {
                                if(zamin[siah[0] + 1][siah[1] + 1]=='|' || zamin[siah[0] + 1][siah[1]]=='-')
                                {
                                    printeror2(h);
                                    continue;
                                }
                                else
                                {
                                    makaneSiah[0]=siah[0] + 2 ;
                                    makaneSiah[1]=siah[1] + 2 ;
                                    b=false;
                                }
                            }
                            else if(m[0]=='c')
                            {
                                if(zamin[siah[0] + 1][siah[1] - 1]=='|' || zamin[siah[0] + 1][siah[1]]=='-'
                                        ||zamin[sefid[0] + 1][sefid[1] - 1] ||zamin[sefid[0] + 1][sefid[1] + 1]=='-')
                                {
                                    printeror2(h);
                                    continue;
                                }
                                else
                                {
                                    makaneSiah[0]=siah[0] + 2 ;
                                    makaneSiah[1]=siah[1] - 2 ;
                                    b=false;
                                }
                            }
                        }
                        else
                        {
                            printeror2(h);
                            continue;
                        }
                    }
                    else
                    {
                        printeror1(h);
                        continue;
                    }
                }
            }
        }
        else
        {
            printeror1(h);
            continue;
        }
        jaygozary (makaneSefid , makaneSiah , zamin , sefid , siah );
        print (zamin , h , wall1 , wall2);
        for(int i =0 ; i<19 ; i++)
        {
            if(zamin[1][i]=='R')
            {
                winer=0;
                t=false;
            }
            if(zamin[17][i]=='B')
            {
                winer=1;
                t=false;
            }
        }
        taeen_nobat++;
    }
    return winer;
}
int game2players2( int winer , string user2[2])
{
    char zamin[abaad][abaad];
    int  mark[19][19];
    int  radifstartDFS=1;
    int  sotoonstartDFS=1;
    char NoeHarekat,NoeDivar;
    int sotoonYAsatrdivar,avaldivar,akhardivar;//ابتدا و انتهای دیوار
    int makanesefid1[2]={ abaad-2 , abaad/2},makanesiah1[2]={ 1 , abaad/2};
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int sefid1[2],siah1[2] ,sefid2[2] , siah2[2] , makanesefid2[2] , makanesiah2[2];
    int divar[2][2];//دیوار وارد شده
    int taeen_nobat=1;
    int wall1=10 , wall2=10;
    int harekat_avval ;
    bool t=true;
    jaygozary (makanesefid1 , makanesiah1 , zamin , sefid1 , siah1 );
    print (zamin , h , wall1 , wall2);
    while (t)
    {
        SetConsoleTextAttribute(h, 0x4);
        cout<<user2[0];
        SetConsoleTextAttribute(h, 0xf);
        cout << "Sotoon Dovomin mohre ghermez ra vared konid: " ;
        cin >> harekat_avval ;
        makanesefid2[0] = 17;
        makanesefid2[1] = harekat_avval;
        zamin[makanesefid2[0]][makanesefid2[1]] = 'B';
        if(harekat_avval>17 || harekat_avval<1 || harekat_avval % 2 == 0)
        {
            printeror1(h);
            continue;
        }
        t=false;
    }
    t=true;
    while(t)
    {
        SetConsoleTextAttribute(h, 0x9);
        cout<<user2[1];
        SetConsoleTextAttribute(h, 0xf);
        cout << "Sotoon Dovomin mohre aby ra vared konid: " ;
        cin >> harekat_avval ;
        makanesiah2[0] = 1;
        makanesiah2[1] = harekat_avval;
        zamin[makanesiah2[0]][makanesiah2[1]] = 'D';
        if(harekat_avval>17 || harekat_avval<1|| harekat_avval % 2 == 0)
        {
            printeror1(h);
            continue;
        }
        t=false;
    }
    t=true;
    jaygozary2 (makanesefid1 ,makanesefid2,makanesiah1 , makanesiah2 , zamin , sefid1 , siah1 , sefid2 , siah2 );
    print2 (zamin , h , wall1 , wall2);
    while (t == true)
    {
        if (taeen_nobat % 2 == 1)
        {
            SetConsoleTextAttribute(h, 0x4);
            cout<<user2[0];
            SetConsoleTextAttribute(h, 0xf);
        }
        else if (taeen_nobat % 2 == 0)
        {
            SetConsoleTextAttribute(h, 0x9);
            cout<<user2[1];
            SetConsoleTextAttribute(h, 0xf);
        }
        cout << " Noe Harekat Ra Vared Konid (d:divar , m:mohreh1 , n:mohreh2)";
        cin >> NoeHarekat;

        if (NoeHarekat == 'd' || NoeHarekat == 'D')/////////دیوار
        {
            if(wall1==0 && taeen_nobat % 2 == 1)
            {
                SetConsoleTextAttribute(h, 0x4);
                cout<<" Red ";
                SetConsoleTextAttribute(h, 0xf);
                cout<<"walls = 0"<<endl;
                continue;
            }
            if(wall2==0 && taeen_nobat % 2 == 1)
            {
                SetConsoleTextAttribute(h, 0x9);
                cout<<" Blue ";
                SetConsoleTextAttribute(h, 0xf);
                cout<<"walls = 0"<<endl;
                continue;
            }
            cout << "Noe Divar Ra Vared Konid (a:amoodi , o:ofoghi) ";
            cin >> NoeDivar;
            if (NoeDivar == 'a')
            {
                cout << "Sotoone Divar Ra Vared Konid ";
                cin >> sotoonYAsatrdivar;
                cout << "Ebtedaye Divar Dar Kodam Satr Ast? ";
                cin >> avaldivar;
                cout << "Entehaye Divar Dar Kodam Satr Ast? ";
                cin >> akhardivar;
                if(abs(avaldivar-akhardivar)!=2)
                {
                    printeror2(h);
                    continue;
                }
                divar[0][0] = avaldivar;
                divar[0][1] = sotoonYAsatrdivar;
                divar[1][0]=akhardivar;
                divar[1][1]=sotoonYAsatrdivar;
                zamin[divar[0][0]][divar[0][1]]='|';
                zamin[divar[1][0]][divar[1][1]]='|';
            }
            else if (NoeDivar =='o')
            {
                cout << "Satre Divar Ra Vared Konid ";
                cin >> sotoonYAsatrdivar;
                cout << "Ebtedaye Divar Dar Kodam Sotoon Ast? ";
                cin >> avaldivar;
                cout << "Entehaye Divar Dar Kodam Sotoon Ast? ";
                cin >> akhardivar;
                if(abs(avaldivar-akhardivar)!=2)
                {
                    printeror2(h);
                    continue;
                }
                divar[0][0] = sotoonYAsatrdivar;
                divar[0][1] = avaldivar;
                divar[1][0]=sotoonYAsatrdivar;
                divar[1][1]= akhardivar;
                zamin[divar[0][0]][divar[0][1]]='-';
                zamin[divar[1][0]][divar[1][1]]='-';
            }
            else
            {
                printeror1(h);
                continue;
            }
            Markgozari(zamin,mark);
            dfs (mark,radifstartDFS,sotoonstartDFS);
            if (errorDivar (sotoonYAsatrdivar,avaldivar,akhardivar, mark) == 0 )
            {
                printeror2(h);
                zamin[divar[0][0]][divar[0][1]]=' ';
                zamin[divar[1][0]][divar[1][1]]=' ';
                continue;
            }
            if(taeen_nobat % 2 ==1)
                wall1--;
            if(taeen_nobat % 2 ==0)
                wall2--;
        }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// مهره اول سفید
        else if (NoeHarekat == 'm' || NoeHarekat == 'M')////////مهره
        {
            if (taeen_nobat % 2 == 1)////////سفید
            {
                harekat1(sefid1 , makanesefid1 , zamin);
            }
            else if (taeen_nobat % 2 == 0)/////////سیاه
            {
                harekat2(siah1 , makanesiah1 , zamin);

            }
        }
         else if (NoeHarekat == 'n' || NoeHarekat == 'N')////////مهره
         {
                if (taeen_nobat % 2 == 1)////////سفید
                {
                    harekat1(sefid2 , makanesefid2 , zamin);

                }
                else if (taeen_nobat % 2 == 0)/////////سیاه
                {
                    harekat2(siah2 , makanesiah2 , zamin);

                }
         }
        jaygozary2 (makanesefid1 ,makanesefid2,makanesiah1 , makanesiah2 , zamin , sefid1 , siah1 , sefid2 , siah2 );
        print2 (zamin , h , wall1 , wall2);
        for(int i =0 ; i<19 ; i++)
        {
            for(int j=0 ; j<19 ; j++)
            {
                if(zamin[1][i]=='A' && zamin[1][j]=='B' )
                {
                    winer=0;
                    t=false;
                }
            }
        }
        for(int i =0 ; i<19 ; i++)
        {
            for(int j=0 ; j<19 ; j++)
            {
                if(zamin[17][i]=='C' && zamin[17][j]=='D' )
                {
                    winer=1;
                    t=false;
                }
            }
        }
        taeen_nobat++;
    }
    return winer;

}
int game2playersDaliz( int winer , string user2[2])
{
    char zamin[abaad][abaad];
    int  mark[19][19];
    int  radifstartDFS=1;
    int  sotoonstartDFS=1;
    char NoeHarekat,NoeDivar;
    char harekat[1];
    int noeparcham;
    int sotoonYAsatrdivar,avaldivar,akhardivar;//ابتدا و انتهای دیوار
    int makaneSefid[2]={ 17 , 11},makaneSiah[2]={ 1 , 11};///////DALIZ
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int sefid[2],siah[2] ;
    int divar[2][2];//دیوار وارد شده
    int taeen_nobat=1;
    int wall1=10 , wall2=10;
    bool t=true;
    cout << "1.yek parcham kenar" <<endl << "2.yek parcham vasat" << endl << "3. do parcham" << endl;
    cin >> noeparcham;
    jaygozary2playersDaliz(makaneSefid , makaneSiah , zamin , sefid , siah , noeparcham );
    print2playersDaliz (zamin , h , wall1 , wall2);
    while (t == true)
    {
        if (taeen_nobat % 2 == 1)
        {
            SetConsoleTextAttribute(h, 0x4);
            cout<<user2[0];
            SetConsoleTextAttribute(h, 0xf);
        }
        else if (taeen_nobat % 2 == 0)
        {
            SetConsoleTextAttribute(h, 0x9);
            cout<<user2[1];
            SetConsoleTextAttribute(h, 0xf);
        }
        cout << " Noe Harekat Ra Vared Konid (d:divar , m:mohreh)";
        cin >> NoeHarekat;

        if (NoeHarekat == 'd' || NoeHarekat == 'D')/////////دیوار
        {
            if(wall1==0 && taeen_nobat % 2 == 1)
            {
                SetConsoleTextAttribute(h, 0x4);
                cout<<" Red ";
                SetConsoleTextAttribute(h, 0xf);
                cout<<"walls = 0"<<endl;
                continue;
            }
            if(wall2==0 && taeen_nobat % 2 == 1)
            {
                SetConsoleTextAttribute(h, 0x9);
                cout<<" Blue ";
                SetConsoleTextAttribute(h, 0xf);
                cout<<"walls = 0"<<endl;
                continue;
            }
            cout << "Noe Divar Ra Vared Konid (a:amoodi , o:ofoghi) ";
            cin >> NoeDivar;
            if (NoeDivar == 'a')
            {
                cout << "Sotoone Divar Ra Vared Konid ";
                cin >> sotoonYAsatrdivar;
                cout << "Ebtedaye Divar Dar Kodam Satr Ast? ";
                cin >> avaldivar;
                cout << "Entehaye Divar Dar Kodam Satr Ast? ";
                cin >> akhardivar;
                if(abs(avaldivar-akhardivar)!=2)
                {
                    printeror2(h);
                    continue;
                }
                divar[0][0] = avaldivar;
                divar[0][1] = sotoonYAsatrdivar;
                divar[1][0]=akhardivar;
                divar[1][1]=sotoonYAsatrdivar;
                zamin[divar[0][0]][divar[0][1]]='|';
                zamin[divar[1][0]][divar[1][1]]='|';
            }
            else if (NoeDivar =='o')
            {
                cout << "Satre Divar Ra Vared Konid ";
                cin >> sotoonYAsatrdivar;
                cout << "Ebtedaye Divar Dar Kodam Sotoon Ast? ";
                cin >> avaldivar;
                cout << "Entehaye Divar Dar Kodam Sotoon Ast? ";
                cin >> akhardivar;
                if(abs(avaldivar-akhardivar)!=2)
                {
                    printeror2(h);
                    continue;
                }
                divar[0][0] = sotoonYAsatrdivar;
                divar[0][1] = avaldivar;
                divar[1][0]=sotoonYAsatrdivar;
                divar[1][1]= akhardivar;
                zamin[divar[0][0]][divar[0][1]]='-';
                zamin[divar[1][0]][divar[1][1]]='-';
            }
            else
            {
                printeror1(h);
                continue;
            }
            Markgozari(zamin,mark);
            dfs (mark,radifstartDFS,sotoonstartDFS);
            if (errorDivar (sotoonYAsatrdivar,avaldivar,akhardivar, mark) == 0 )
            {
                printeror2(h);
                zamin[divar[0][0]][divar[0][1]]=' ';
                zamin[divar[1][0]][divar[1][1]]=' ';
                continue;
            }
            if(taeen_nobat % 2 ==1)
                wall1--;
            if(taeen_nobat % 2 ==0)
                wall2--;
        }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else if (NoeHarekat == 'm' || NoeHarekat == 'M')////////مهره
        {
            bool b=true;
            if (taeen_nobat % 2 == 1)////////سفید
            {
                while (b)
                {
                    cout<<" R (user1) "<<" harekat baadi mohreh ra vared konid (bala=b , paeen=p, chap=c, rast=r, movarab=m)";
                    cin>> harekat[0];

                    if(harekat[0]=='b') /////////// بالا
                    {
                        if(zamin[sefid[0] - 1][sefid[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[sefid[0] - 2][sefid[1]]=='B')
                        {
                            if(zamin[sefid[0] - 3][sefid[1]]=='-')
                            {

                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makaneSefid[0]=sefid[0] - 4;
                                makaneSefid[1]=sefid[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSefid[0]=sefid[0] - 2;
                            makaneSefid[1]=sefid[1];
                            b=false;
                        }
                    }
                    else if(harekat[0]=='p' ) ////////// پایین
                    {
                        if(zamin[sefid[0] + 1][sefid[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        if(zamin[sefid[0] + 2][sefid[1]]=='B')
                        {
                            if(zamin[sefid[0] + 3][sefid[1]]=='-')
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makaneSefid[0]=sefid[0] + 4;
                                makaneSefid[1]=sefid[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSefid[0]=sefid[0] + 2;
                            makaneSefid[1]=sefid[1];
                            b=false;
                        }
                    }
                    else if( harekat[0]=='c' ) ////////// چپ
                    {

                        if(zamin[sefid[0]][sefid[1] - 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        if(zamin[sefid[0]][sefid[1] - 2]=='B')
                        {
                            if(zamin[sefid[0]][sefid[1] - 3]=='|')
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makaneSefid[0]=sefid[0];
                                makaneSefid[1]=sefid[1] - 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSefid[0]=sefid[0];
                            makaneSefid[1]=sefid[1] - 2;
                            b=false;
                        }
                    }
                    else if( harekat[0]=='r' ) ///////// راست
                    {

                        if(zamin[sefid[0]][sefid[1] + 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        if(zamin[sefid[0]][sefid[1] + 2]=='B')
                        {
                            if(zamin[sefid[0]][sefid[1] + 3]=='|')
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makaneSefid[0]=sefid[0];
                                makaneSefid[1]=sefid[1] + 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSefid[0]=sefid[0];
                            makaneSefid[1]=sefid[1] + 2;
                            b=false;
                        }
                    }
                    else if(harekat[0]=='m') //////////// مورب
                    {
                        if( zamin[sefid[0] - 2][sefid[1]]=='B' && zamin[sefid[0] - 3][sefid[1]]=='-')
                        {
                            cout<<"harekat be samt chape B ya harekat be samt raste B?( chape B = c , raste B = r ):";
                            char m[0];
                            cin>>m[0];
                            if(m[0]=='r')
                            {
                                if(zamin[sefid[0] - 1][sefid[1] + 1]=='|' || zamin[sefid[0] - 1][sefid[1]]=='-')
                                {
                                    printeror2(h);
                                    continue;
                                }
                                else
                                {
                                    makaneSefid[0]=sefid[0] - 2 ;
                                    makaneSefid[1]=sefid[1] + 2 ;
                                    b=false;
                                }
                            }
                            else if(m[0]=='c')
                            {
                                if(zamin[sefid[0] - 1][sefid[1] - 1]=='|' || zamin[sefid[0] - 1][sefid[1]]=='-'
                                        ||zamin[sefid[0] - 1][sefid[1] - 1] ||zamin[sefid[0] - 1][sefid[1] + 1]=='-')
                                {
                                    printeror2(h);
                                    continue;
                                }
                                else
                                {
                                    makaneSefid[0]=sefid[0] - 2 ;
                                    makaneSefid[1]=sefid[1] - 2 ;
                                    b=false;
                                }
                            }
                        }
                        else
                        {
                            printeror2(h);
                            continue;
                        }
                    }
                    else
                    {
                        printeror1(h);
                        continue;
                    }
                }
            }
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            else if (taeen_nobat % 2 == 0)/////////سیاه
            {
                while (b)
                {
                    cout<<" B (user2) "<<" harekat baadi mohreh ra vared konid (bala=b , paeen=p, chap=c, rast=r, movarab=m):";
                    cin>> harekat[0];

                    if(harekat[0]=='b') //////////// بالا
                    {
                        if(zamin[siah[0] - 1][siah[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        if(zamin[siah[0] - 2][siah[1]]=='R')
                        {
                            if(zamin[siah[0] - 3][siah[1]]=='-')
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makaneSiah[0]=siah[0] - 4;
                                makaneSiah[1]=siah[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSiah[0]=siah[0] - 2;
                            makaneSiah[1]=siah[1];
                            b=false;
                        }
                    }
                    else if(harekat[0]=='p' ) ////////// پایین
                    {
                        if(zamin[siah[0] + 1][siah[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        if(zamin[siah[0] + 2][siah[1]]=='R')
                        {
                            if(zamin[siah[0] + 3][siah[1]]=='-')
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makaneSiah[0]=siah[0] + 4;
                                makaneSiah[1]=siah[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSiah[0]=siah[0] + 2;
                            makaneSiah[1]=siah[1];
                            b=false;
                        }
                    }
                    else if( harekat[0]=='c' ) //////////// چپ
                    {

                        if(zamin[siah[0]][siah[1] - 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        if(zamin[siah[0]][siah[1] - 2]=='R')
                        {
                            if(zamin[siah[0]][siah[1] - 3]=='|')
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makaneSiah[0]=siah[0];
                                makaneSiah[1]=siah[1] - 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSiah[0]=siah[0];
                            makaneSiah[1]=siah[1] - 2;
                            b=false;
                        }
                    }
                    else if( harekat[0]=='r' ) /////////// راست
                    {

                        if(zamin[siah[0]][siah[1] + 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        if(zamin[siah[0]][siah[1] + 2]=='R')
                        {
                            if(zamin[siah[0]][siah[1] + 3]=='|')
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makaneSiah[0]=siah[0];
                                makaneSiah[1]=siah[1] + 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSiah[0]=siah[0];
                            makaneSiah[1]=siah[1] + 2;
                            b=false;
                        }
                    }
                    else if(harekat[0]=='m') //////////// مورب
                    {
                        if( zamin[siah[0] + 2][siah[1]]=='R' && zamin[siah[0] + 3][siah[1]]=='-')
                        {
                            cout<<"harekat be samt chape R ya harekat be samt raste R ?( chape W = c , raste W = r ):";
                            char m[0];
                            cin>>m[0];
                            if(m[0]=='r')
                            {
                                if(zamin[siah[0] + 1][siah[1] + 1]=='|' || zamin[siah[0] + 1][siah[1]]=='-')
                                {
                                    printeror2(h);
                                    continue;
                                }
                                else
                                {
                                    makaneSiah[0]=siah[0] + 2 ;
                                    makaneSiah[1]=siah[1] + 2 ;
                                    b=false;
                                }
                            }
                            else if(m[0]=='c')
                            {
                                if(zamin[siah[0] + 1][siah[1] - 1]=='|' || zamin[siah[0] + 1][siah[1]]=='-'
                                        ||zamin[sefid[0] + 1][sefid[1] - 1] ||zamin[sefid[0] + 1][sefid[1] + 1]=='-')
                                {
                                    printeror2(h);
                                    continue;
                                }
                                else
                                {
                                    makaneSiah[0]=siah[0] + 2 ;
                                    makaneSiah[1]=siah[1] - 2 ;
                                    b=false;
                                }
                            }
                        }
                        else
                        {
                            printeror2(h);
                            continue;
                        }
                    }
                    else
                    {
                        printeror1(h);
                        continue;
                    }
                }
            }
        }
        else
        {
            printeror1(h);
            continue;
        }
        jaygozary2playersDaliz(makaneSefid , makaneSiah , zamin , sefid , siah , noeparcham );
        print2playersDaliz(zamin , h , wall1 , wall2);
        for(int i =0 ; i<19 ; i++)
        {
            if (noeparcham == 1)
            {
                if(zamin[1][i]=='R' ||
                        (zamin[7][1]=='R' && zamin[8][1] != '-') ||
                        (zamin[11][1]=='R' && zamin[10][1] != '-') ||
                        (zamin[9][3]=='R' && zamin[9][2] != '|'))//////////DALIZ
                {
                    winer=0;
                    t=false;
                }
                if(zamin[17][i]=='B' ||
                        (zamin[7][1]=='B' && zamin[8][1] != '-') ||
                        (zamin[11][1]=='B' && zamin[10][1] != '-') ||
                        (zamin[9][3]=='B' && zamin[9][2] != '|'))//////////DALIZ
                {
                    winer=1;
                    t=false;
                }
            }
            if (noeparcham == 2)
            {
                if(zamin[1][i]=='R' ||
                        (zamin[7][9]=='R' && zamin[8][9] != '-')||
                        (zamin[11][9]=='R' && zamin[10][9] != '-') ||
                        (zamin[9][7]=='R' && zamin[9][8] != '|')||
                        (zamin[9][11]=='R' && zamin[9][10] != '|'))
                {
                    winer=0;
                    t=false;
                }
                if(zamin[17][i]=='B' ||
                        (zamin[7][9]=='B' && zamin[8][9] != '-')||
                        (zamin[11][9]=='B' && zamin[10][9] != '-') ||
                        (zamin[9][7]=='B' && zamin[9][8] != '|')||
                        (zamin[9][11]=='B' && zamin[9][10] != '|'))
                {
                    winer=1;
                    t=false;
                }
            }
            if (noeparcham == 3)
            {

                if(zamin[1][i]=='R' ||
                        (zamin[7][9]=='R' && zamin[8][9] != '-')||
                        (zamin[11][9]=='R' && zamin[10][9] != '-') ||
                        (zamin[9][7]=='R' && zamin[9][8] != '|')||
                        (zamin[9][11]=='R' && zamin[9][10] != '|')||
                        (zamin[7][1]=='R' && zamin[8][1] != '-') ||
                        (zamin[11][1]=='R' && zamin[10][1] != '-') ||
                        (zamin[9][3]=='R' && zamin[9][2] != '|'))//////////DALIZ
                {
                    winer=0;
                    t=false;
                }
                if(zamin[17][i]=='B' ||
                        (zamin[7][9]=='B' && zamin[8][9] != '-')||
                        (zamin[11][9]=='B' && zamin[10][9] != '-') ||
                        (zamin[9][7]=='B' && zamin[9][8] != '|')||
                        (zamin[9][11]=='B' && zamin[9][10] != '|')||
                        (zamin[7][1]=='B' && zamin[8][1] != '-') ||
                        (zamin[11][1]=='B' && zamin[10][1] != '-') ||
                        (zamin[9][3]=='B' && zamin[9][2] != '|'))//////////DALIZ
                {
                    winer=1;
                    t=false;
                }

            }

        }
        taeen_nobat++;
    }
    return winer;
}
void  name(string *user , int *score , string *user2 , int two)//اضافه کردن اسم به فایل
{
    float num;
    int j=0,m=0;
    string username,name;
    ifstream z("leaderboard of Quoridor game.txt" , ios::in | ios::binary);
    for(int i=0 ; ! z.eof() ; i++)
    {
        if(i%2==0)
        {
            z>>name;
            if(user[j-1]== name)
                break;
            user[j]=name;
            j++;
        }

        else
        {
            z>>num;
            score[m]=num;
            m++;
        }

    }
    z.close();
    bool t=false;
    bool r(true);
    while (r)
    {
        cout<<"user "<< two+1 <<" enter your name:";
        cin>>username;
        for(int i=0 ;i<j; i++)
        {
            if(username==user[i])
            {
                user2[two]=username;
                r=false;
                t=true;
            }
        }
        if(j==0)
        {
            user2[two]=username;
            user[j]=username;
            score[m]=0;
            r=false;
            t=false;
        }

        if(t==false && j!=0)
        {
            user2[two]=username;
            user[j]=username;
            score[m]=0;
            r=false;
            t=false;
            break;
        }

    }
    if(t==false)
    {
        ofstream x("leaderboard of Quoridor game.txt" , ios::app | ios::binary);
        x << username << " " << 0 << endl;
        x.close();
    }

}
void win(string * user ,int *score  , string *user2 , int winer) //اضافه کردن امتیاز به امتیاز کاربر برنده و ذخیره در فایل
{
    bool t=true;
    int i=0;
    string j;
    while (t)
    {
        if(user[i]==user2[winer])
        {
            score[i]++;
            t=false;
        }
        i++;
    }
    ifstream x("leaderboard of Quoridor game.txt" , ios::app);
    for(i=0 ; !x.eof() ; i++)
        x>>j;
    x.close();
    for(int k=0 ; k<(i-1)/2 -1 ; k++)//سورت کردن بازیکن ها بر اساس امتیازشون
        for(int l=k+1 ; l<(i-1)/2 ; l++)
            if(score[l] > score[k])
            {
                int t=score[l] ;
                score[l]=score[k];
                score[k]=t;
                string f=user[l];
                user[l]=user[k];
                user[k]=f;
            }
    ofstream y("leaderboard of Quoridor game.txt");
    for(int h=0 ; h<(i-1)/2 ; h++)
        y << user[h] << "  " << score[h] << endl;
    y.close();
    cout<<"--------------"<<endl;
    cout<<user2[winer]<<" won\n"<<endl;
}
////////////////////////////////////////////////////////////////////////////////
void printleaderboard(string user[100] , int score[100])
{
    system("cls");
    cout<<"leaderboard :"<<endl;
    for (int i=0 ; user[i]!="" ; i++)
    {
        cout<<user[i]<<"\t"<<score[i]<<endl;
    }
    cout<<"-------------------------------------"<<endl;
}
/////////////////////////////////////////////////////////////////////////////////
void  name2(string *user , int *score)//نشان دادن لیدربورد اول بازی
{
    float num;
    int j=0,m=0;
    string username,name;
    ifstream z("leaderboard of Quoridor game.txt" , ios::in | ios::binary);
    for(int i=0 ; ! z.eof() ; i++)
    {
        if(i%2==0)
        {
            z>>name;
            if(user[j-1]== name)
                break;
            user[j]=name;
            j++;
        }

        else
        {
            z>>num;
            score[m]=num;
            m++;
        }

    }
    z.close();
}

int game4players( int winer , string user2[4])
{
    char zamin[abaad][abaad];
    int  mark[19][19];
    int  radifstartDFS=1;
    int  sotoonstartDFS=1;
    char NoeHarekat,NoeDivar;
    char harekat[1];
    int sotoonYAsatrdivar,avaldivar,akhardivar;//ابتدا و انتهای دیوار
    int makaneSefid[2]={ abaad-2 , abaad/2},makaneSiah[2]={ 1 , abaad/2},makanezard[2]={ abaad/2 , 1},makanesabz[2]={ abaad/2 , 17};
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int sefid[2] , siah[2] , zard[2] , sabz[2];
    int divar[2][2];//دیوار وارد شده
    int taeen_nobat=1;
    int wall1=5 , wall2=5 , wall3=5 , wall4=5;
    bool t=true;
    jaygozary4players(makaneSefid , makaneSiah , makanesabz ,makanezard , zamin , sefid , siah , sabz , zard);
    print4players(zamin , h , wall1 , wall2 , wall3 , wall4);
    while (t == true)
    {
        if (taeen_nobat % 4 == 1)
        {
            SetConsoleTextAttribute(h, 0x4);
            cout<<user2[0];
            SetConsoleTextAttribute(h, 0xf);
        }
        else if (taeen_nobat % 4 == 0)////////////////zard
        {
            SetConsoleTextAttribute(h, 0x6);
            cout<<user2[3];
            SetConsoleTextAttribute(h, 0xf);
        }
        else if (taeen_nobat % 4 == 3)
        {
            SetConsoleTextAttribute(h, 0x9);
            cout<<user2[2];
            SetConsoleTextAttribute(h, 0xf);
        }
        else if (taeen_nobat % 4 == 2)////////////////sabs
        {
            SetConsoleTextAttribute(h, 0xA);
            cout<<user2[1];
            SetConsoleTextAttribute(h, 0xf);
        }
        cout << " Noe Harekat Ra Vared Konid (d:divar , m:mohreh)";
        cin >> NoeHarekat;

        if (NoeHarekat == 'd' || NoeHarekat == 'D')/////////دیوار
        {
            if(wall1==0 && taeen_nobat % 4 == 1)
            {
                SetConsoleTextAttribute(h, 0x4);
                cout<<" Red ";
                SetConsoleTextAttribute(h, 0xf);
                cout<<"walls = 0"<<endl;
                continue;
            }
            if(wall2==0 && taeen_nobat % 4 == 3)
            {
                SetConsoleTextAttribute(h, 0x9);
                cout<<" Blue ";
                SetConsoleTextAttribute(h, 0xf);
                cout<<"walls = 0"<<endl;
                continue;
            }
            if(wall3==0 && taeen_nobat % 4 == 0)///////////////zard
            {
                SetConsoleTextAttribute(h, 0x6);
                cout<<" Yellow ";
                SetConsoleTextAttribute(h, 0xf);
                cout<<"walls = 0"<<endl;
                continue;
            }
            if(wall2==0 && taeen_nobat % 4 == 2)///////////////sabs
            {
                SetConsoleTextAttribute(h, 0xA);
                cout<<" Green ";
                SetConsoleTextAttribute(h, 0xf);
                cout<<"walls = 0"<<endl;
                continue;
            }
            cout << "Noe Divar Ra Vared Konid (a:amoodi , o:ofoghi) ";
            cin >> NoeDivar;
            if (NoeDivar == 'a')
            {
                cout << "Sotoone Divar Ra Vared Konid ";
                cin >> sotoonYAsatrdivar;
                cout << "Ebtedaye Divar Dar Kodam Satr Ast? ";
                cin >> avaldivar;
                cout << "Entehaye Divar Dar Kodam Satr Ast? ";
                cin >> akhardivar;
                if(abs(avaldivar-akhardivar)!=2)
                {
                    printeror2(h);
                    continue;
                }
                divar[0][0] = avaldivar;
                divar[0][1] = sotoonYAsatrdivar;
                divar[1][0]=akhardivar;
                divar[1][1]=sotoonYAsatrdivar;
                zamin[divar[0][0]][divar[0][1]]='|';
                zamin[divar[1][0]][divar[1][1]]='|';
            }
            else if (NoeDivar =='o')
            {
                cout << "Satre Divar Ra Vared Konid ";
                cin >> sotoonYAsatrdivar;
                cout << "Ebtedaye Divar Dar Kodam Sotoon Ast? ";
                cin >> avaldivar;
                cout << "Entehaye Divar Dar Kodam Sotoon Ast? ";
                cin >> akhardivar;
                if(abs(avaldivar-akhardivar)!=2)
                {
                    printeror2(h);
                    continue;
                }
                divar[0][0] = sotoonYAsatrdivar;
                divar[0][1] = avaldivar;
                divar[1][0]=sotoonYAsatrdivar;
                divar[1][1]= akhardivar;
                zamin[divar[0][0]][divar[0][1]]='-';
                zamin[divar[1][0]][divar[1][1]]='-';
            }
            else
            {
                printeror1(h);
                continue;
            }
            Markgozari(zamin,mark);
            dfs (mark,radifstartDFS,sotoonstartDFS);
            if (errorDivar (sotoonYAsatrdivar,avaldivar,akhardivar, mark) == 0 )
            {
                printeror2(h);
                zamin[divar[0][0]][divar[0][1]]=' ';
                zamin[divar[1][0]][divar[1][1]]=' ';
                continue;
            }
            if(taeen_nobat % 4 ==1)
                wall1--;
            if(taeen_nobat % 4 ==3)
                wall2--;
            if(taeen_nobat % 4 ==0)
                wall3--;
            if(taeen_nobat % 4 ==2)
                wall4--;
        }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else if (NoeHarekat == 'm' || NoeHarekat == 'M')////////مهره
        {
            bool b=true;
            if (taeen_nobat % 4 == 1)////////red
            {
                while (b)
                {
                    cout<<" R (user1) "<<" harekat baadi mohreh ra vared konid (bala=b , paeen=p, chap=c, rast=r, movarab=m)";
                    cin>> harekat[0];

                    if(harekat[0]=='b') /////////// بالا
                    {
                        if(zamin[sefid[0] - 1][sefid[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[sefid[0] - 2][sefid[1]]!='*')
                        {
                            if(zamin[sefid[0] - 3][sefid[1]]=='-')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[sefid[0] - 4][sefid[1]]!='*')
                            {
                                if(zamin[sefid[0] - 5][sefid[1]]=='-')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[sefid[0] - 6][sefid[1]]!='*')
                                {
                                    if(zamin[sefid[0] - 7][sefid[1]]=='-')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSefid[0]=sefid[0] - 8;
                                        makaneSefid[1]=sefid[1];
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makaneSefid[0]=sefid[0] - 6;
                                    makaneSefid[1]=sefid[1];
                                    b=false;
                                }
                            }
                            else
                            {
                                makaneSefid[0]=sefid[0] - 4;
                                makaneSefid[1]=sefid[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSefid[0]=sefid[0] - 2;
                            makaneSefid[1]=sefid[1];
                            b=false;
                        }
                    }
                    else if(harekat[0]=='p' ) ////////// پایین
                    {
                        if(zamin[sefid[0] + 1][sefid[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[sefid[0] + 2][sefid[1]]!='*')
                        {
                            if(zamin[sefid[0] + 3][sefid[1]]=='-')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[sefid[0] + 4][sefid[1]]!='*')
                            {
                                if(zamin[sefid[0] + 5][sefid[1]]=='-')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[sefid[0] + 6][sefid[1]]!='*')
                                {
                                    if(zamin[sefid[0] + 7][sefid[1]]=='-')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSefid[0]=sefid[0] + 8;
                                        makaneSefid[1]=sefid[1];
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makaneSefid[0]=sefid[0] + 6;
                                    makaneSefid[1]=sefid[1];
                                    b=false;
                                }
                            }
                            else
                            {
                                makaneSefid[0]=sefid[0] + 4;
                                makaneSefid[1]=sefid[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSefid[0]=sefid[0] + 2;
                            makaneSefid[1]=sefid[1];
                            b=false;
                        }
                    }
                    else if( harekat[0]=='c' ) ////////// چپ
                    {

                        if(zamin[sefid[0]][sefid[1] - 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[sefid[0]][sefid[1] - 2]!='*')
                        {
                            if(zamin[sefid[0]][sefid[1] - 3]=='|')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[sefid[0]][sefid[1] - 4]!='*')
                            {
                                if(zamin[sefid[0]][sefid[1] - 5]=='|')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[sefid[0]][sefid[1] - 6]!='*')
                                {
                                    if(zamin[sefid[0]][sefid[1] - 7]=='|')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSefid[0]=sefid[0];
                                        makaneSefid[1]=sefid[1] - 8;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makaneSefid[0]=sefid[0];
                                    makaneSefid[1]=sefid[1] - 6;
                                    b=false;
                                }
                            }
                            else
                            {
                                makaneSefid[0]=sefid[0];
                                makaneSefid[1]=sefid[1] - 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSefid[0]=sefid[0];
                            makaneSefid[1]=sefid[1] - 2;
                            b=false;
                        }
                    }
                    else if( harekat[0]=='r' ) ///////// راست
                    {

                        if(zamin[sefid[0]][sefid[1] + 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[sefid[0]][sefid[1] + 2]!='*')
                        {
                            if(zamin[sefid[0]][sefid[1] + 3]=='|')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[sefid[0]][sefid[1] + 4]!='*')
                            {
                                if(zamin[sefid[0]][sefid[1] + 5]=='|')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[sefid[0]][sefid[1] + 6]!='*')
                                {
                                    if(zamin[sefid[0]][sefid[1] + 7]=='|')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSefid[0]=sefid[0];
                                        makaneSefid[1]=sefid[1] + 8;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makaneSefid[0]=sefid[0];
                                    makaneSefid[1]=sefid[1] + 6;
                                    b=false;
                                }
                            }
                            else
                            {
                                makaneSefid[0]=sefid[0];
                                makaneSefid[1]=sefid[1] + 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSefid[0]=sefid[0];
                            makaneSefid[1]=sefid[1] + 2;
                            b=false;
                        }
                    }
                    else if(harekat[0]=='m') //////////// مورب
                    {
                        if( zamin[sefid[0] - 2][sefid[1]]!='*')
                        {
                            if(zamin[sefid[0] - 3][sefid[1]]=='-')
                            {
                                cout<<"harekat be samt chape "<<zamin[sefid[0] - 2][sefid[1]]<<" ya harekat be samt raste "<<zamin[sefid[0] - 2][sefid[1]]
                                        <<"?( chape "<<zamin[sefid[0] - 2][sefid[1]]<<" = c , raste "<<zamin[sefid[0] - 2][sefid[1]]<<"  = r ):";
                                char m[0];
                                cin>>m[0];
                                if(m[0]=='r')
                                {
                                    if(zamin[sefid[0] - 1][sefid[1] + 1]=='|' || zamin[sefid[0] - 1][sefid[1]]=='-'
                                            ||zamin[sefid[0] - 1][sefid[1] + 1]=='-' || zamin[sefid[0]-2][sefid[1]+2]!='*')
                                    {
                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSefid[0]=sefid[0] - 2 ;
                                        makaneSefid[1]=sefid[1] + 2 ;
                                        b=false;
                                    }
                                }
                                else if(m[0]=='c')
                                {
                                    if(zamin[sefid[0] - 1][sefid[1] - 1]=='|' || zamin[sefid[0] - 1][sefid[1]]=='-'
                                            ||zamin[sefid[0] - 1][sefid[1] - 1]=='-' ||zamin[sefid[0]-2][sefid[1]-2]!='*' )
                                    {
                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSefid[0]=sefid[0] - 2 ;
                                        makaneSefid[1]=sefid[1] - 2 ;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    printeror1(h);
                                    continue;
                                }
                            }
                            else if(zamin[sefid[0] - 4][sefid[1]]!='*')
                            {
                                if(zamin[sefid[0] - 5][sefid[1]]=='-')
                                {
                                    cout<<"harekat be samt chape "<<zamin[sefid[0] - 4][sefid[1]]<<" ya harekat be samt raste "<<zamin[sefid[0] - 4][sefid[1]]
                                            <<"?( chape "<<zamin[sefid[0] - 4][sefid[1]]<<" = c , raste "<<zamin[sefid[0] - 4][sefid[1]]<<"  = r ):";
                                    char m[0];
                                    cin>>m[0];
                                    if(m[0]=='r')
                                    {
                                        if(zamin[sefid[0] - 1][sefid[1] + 1]=='|' || zamin[sefid[0] - 1][sefid[1]]=='-'
                                                ||zamin[sefid[0] - 1][sefid[1] + 1]=='-' || zamin[sefid[0]-4][sefid[1]+2]!='*')
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makaneSefid[0]=sefid[0] - 4 ;
                                            makaneSefid[1]=sefid[1] + 2 ;
                                            b=false;
                                        }
                                    }
                                    else if(m[0]=='c')
                                    {
                                        if(zamin[sefid[0] - 1][sefid[1] - 1]=='|' || zamin[sefid[0] - 1][sefid[1]]=='-'
                                                ||zamin[sefid[0] - 1][sefid[1] - 1]=='-'|| zamin[sefid[0]-4][sefid[1]-2]!='*' )
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makaneSefid[0]=sefid[0] - 4 ;
                                            makaneSefid[1]=sefid[1] - 2 ;
                                            b=false;
                                        }
                                    }
                                    else
                                    {
                                        printeror1(h);
                                        continue;
                                    }
                                }

                            }
                            else if(zamin[sefid[0] - 6][sefid[1]]!='*')
                            {
                                if(zamin[sefid[0] - 7][sefid[1]]=='-')
                                {
                                    cout<<"harekat be samt chape "<<zamin[sefid[0] - 6][sefid[1]]<<" ya harekat be samt raste "<<zamin[sefid[0] - 6][sefid[1]]
                                            <<"?( chape "<<zamin[sefid[0] - 6][sefid[1]]<<" = c , raste "<<zamin[sefid[0] - 6][sefid[1]]<<"  = r ):";
                                    char m[0];
                                    cin>>m[0];
                                    if(m[0]=='r')
                                    {
                                        if(zamin[sefid[0] - 1][sefid[1] + 1]=='|' || zamin[sefid[0] - 1][sefid[1]]=='-'
                                                ||zamin[sefid[0] - 1][sefid[1] + 1]=='-'|| zamin[sefid[0]-6][sefid[1]+2]!='*')
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makaneSefid[0]=sefid[0] - 6 ;
                                            makaneSefid[1]=sefid[1] + 2 ;
                                            b=false;
                                        }
                                    }
                                    else if(m[0]=='c')
                                    {
                                        if(zamin[sefid[0] - 1][sefid[1] - 1]=='|' || zamin[sefid[0] - 1][sefid[1]]=='-'
                                                ||zamin[sefid[0] - 1][sefid[1] - 1]=='-'|| zamin[sefid[0]-6][sefid[1]-2]!='*' )
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makaneSefid[0]=sefid[0] - 6 ;
                                            makaneSefid[1]=sefid[1] - 2 ;
                                            b=false;
                                        }
                                    }
                                    else
                                    {
                                        printeror1(h);
                                        continue;
                                    }
                                }
                                else
                                {
                                    printeror2(h);
                                    continue;
                                }
                            }
                            else
                            {
                                printeror2(h);
                                continue;
                            }
                        }
                        else
                        {
                            printeror2(h);
                            continue;
                        }
                    }
                    else
                    {
                        printeror1(h);
                        continue;
                    }
                }
            }
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////////////////////////////////

            if (taeen_nobat % 4 == 2)////////sabz
            {
                while (b)
                {
                    cout<<" G (user2) "<<" harekat baadi mohreh ra vared konid (bala=b , paeen=p, chap=c, rast=r, movarab=m)";
                    cin>> harekat[0];

                    if(harekat[0]=='b') /////////// بالا
                    {
                        if(zamin[sabz[0] - 1][sabz[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[sabz[0] - 2][sabz[1]]!='*')
                        {
                            if(zamin[sabz[0] - 3][sabz[1]]=='-')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[sabz[0] - 4][sabz[1]]!='*')
                            {
                                if(zamin[sabz[0] - 5][sabz[1]]=='-')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[sabz[0] - 6][sabz[1]]!='*')
                                {
                                    if(zamin[sabz[0] - 7][sabz[1]]=='-')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanesabz[0]=sabz[0] - 8;
                                        makanesabz[1]=sabz[1];
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makanesabz[0]=sabz[0] - 6;
                                    makanesabz[1]=sabz[1];
                                    b=false;
                                }
                            }
                            else
                            {
                                makanesabz[0]=sabz[0] - 4;
                                makanesabz[1]=sabz[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makanesabz[0]=sabz[0] - 2;
                            makanesabz[1]=sabz[1];
                            b=false;
                        }
                    }
                    else if(harekat[0]=='p' ) ////////// پایین
                    {
                        if(zamin[sabz[0] + 1][sabz[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[sabz[0] + 2][sabz[1]]!='*')
                        {
                            if(zamin[sabz[0] + 3][sabz[1]]=='-')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[sabz[0] + 4][sabz[1]]!='*')
                            {
                                if(zamin[sabz[0] + 5][sabz[1]]=='-')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[sabz[0] + 6][sabz[1]]!='*')
                                {
                                    if(zamin[sabz[0] + 7][sabz[1]]=='-')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanesabz[0]=sabz[0] + 8;
                                        makanesabz[1]=sabz[1];
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makanesabz[0]=sabz[0] + 6;
                                    makanesabz[1]=sabz[1];
                                    b=false;
                                }
                            }
                            else
                            {
                                makanesabz[0]=sabz[0] + 4;
                                makanesabz[1]=sabz[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makanesabz[0]=sabz[0] + 2;
                            makanesabz[1]=sabz[1];
                            b=false;
                        }
                    }
                    else if( harekat[0]=='c' ) ////////// چپ
                    {

                        if(zamin[sabz[0]][sabz[1] - 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[sabz[0]][sabz[1] - 2]!='*')
                        {
                            if(zamin[sabz[0]][sabz[1] - 3]=='|')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[sabz[0]][sabz[1] - 4]!='*')
                            {
                                if(zamin[sabz[0]][sabz[1] - 5]=='|')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[sabz[0]][sabz[1] - 6]!='*')
                                {
                                    if(zamin[sabz[0]][sabz[1] - 7]=='|')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanesabz[0]=sabz[0];
                                        makanesabz[1]=sabz[1] - 8;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makanesabz[0]=sabz[0];
                                    makanesabz[1]=sabz[1] - 6;
                                    b=false;
                                }
                            }
                            else
                            {
                                makanesabz[0]=sabz[0];
                                makanesabz[1]=sabz[1] - 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makanesabz[0]=sabz[0];
                            makanesabz[1]=sabz[1] - 2;
                            b=false;
                        }
                    }
                    else if( harekat[0]=='r' ) ///////// راست
                    {

                        if(zamin[sabz[0]][sabz[1] + 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[sabz[0]][sabz[1] + 2]!='*')
                        {
                            if(zamin[sabz[0]][sabz[1] + 3]=='|')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[sabz[0]][sabz[1] + 4]!='*')
                            {
                                if(zamin[sabz[0]][sabz[1] + 5]=='|')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[sabz[0]][sabz[1] + 6]!='*')
                                {
                                    if(zamin[sabz[0]][sabz[1] + 7]=='|')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanesabz[0]=sabz[0];
                                        makanesabz[1]=sabz[1] + 8;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makanesabz[0]=sabz[0];
                                    makanesabz[1]=sabz[1] + 6;
                                    b=false;
                                }
                            }
                            else
                            {
                                makanesabz[0]=sabz[0];
                                makanesabz[1]=sabz[1] + 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makanesabz[0]=sabz[0];
                            makanesabz[1]=sabz[1] + 2;
                            b=false;
                        }
                    }
                    else if(harekat[0]=='m') //////////// مورب
                    {
                        if( zamin[sabz[0]][sabz[1] - 2]!='*')
                        {
                            if(zamin[sabz[0]][sabz[1] - 3]=='|')
                            {
                                cout<<"harekat be samt balaye "<<zamin[sabz[0]][sabz[1]- 2]<<" ya harekat be samt paeene "<<zamin[sabz[0]][sabz[1] - 2]
                                        <<" ?( balaye "<<zamin[sabz[0]][sabz[1] - 2]<<" = b , paeene "<<zamin[sabz[0]][sabz[1] - 2]<<"  = p ):";
                                char m[0];
                                cin>>m[0];
                                if(m[0]=='p')
                                {
                                    if(zamin[sabz[0] + 1][sabz[1] - 2]=='-' || zamin[sabz[0]][sabz[1] - 1]=='|'
                                            ||zamin[sabz[0] + 2][sabz[1] - 1]=='|' ||zamin[sabz[0]+2][sabz[1]-2]!='*')
                                    {
                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanesabz[1]=sabz[1] - 2 ;
                                        makanesabz[0]=sabz[0] + 2 ;
                                        b=false;
                                    }
                                }
                                else if(m[0]=='b')
                                {
                                    if(zamin[sabz[0] - 1][sabz[1] - 2]=='-' || zamin[sabz[0]][sabz[1] - 1]=='|'
                                            ||zamin[sabz[0] - 2][sabz[1] - 1]=='|'||zamin[sabz[0]-2][sabz[1]-2]!='*')
                                    {
                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanesabz[1]=sabz[1] - 2 ;
                                        makanesabz[0]=sabz[0] - 2 ;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    printeror1(h);
                                    continue;
                                }
                            }
                            else if(zamin[sabz[0]][sabz[1] - 4]!='*')
                            {
                                if(zamin[sabz[0]][sabz[1] - 5]=='|')
                                {
                                    cout<<"harekat be samt balaye "<<zamin[sabz[0]][sabz[1]- 4]<<" ya harekat be samt paeene "<<zamin[sabz[0]][sabz[1] - 4]
                                            <<"?( balaye "<<zamin[sabz[0]][sabz[1] - 4]<<" = b , paeene "<<zamin[sabz[0]][sabz[1] - 4]<<"  = p ):";
                                    char m[0];
                                    cin>>m[0];
                                    if(m[0]=='p')
                                    {
                                        if(zamin[sabz[0] + 1][sabz[1] - 2]=='-' || zamin[sabz[0]][sabz[1] - 1]=='|'
                                                ||zamin[sabz[0] + 2][sabz[1] - 1]=='|'||zamin[sabz[0]+2][sabz[1]-4]!='*')
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makanesabz[0]=sabz[0] + 2 ;
                                            makanesabz[1]=sabz[1] - 4 ;
                                            b=false;
                                        }
                                    }
                                    else if(m[0]=='b')
                                    {
                                        if(zamin[sabz[0] - 1][sabz[1] - 2]=='-' || zamin[sabz[0]][sabz[1] - 1]=='|'
                                                ||zamin[sabz[0] - 2][sabz[1] - 1]=='|'||zamin[sabz[0]-2][sabz[1]-4]!='*')
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makanesabz[0]=sabz[0] - 2 ;
                                            makanesabz[1]=sabz[1] - 4 ;
                                            b=false;
                                        }
                                    }
                                    else
                                    {
                                        printeror1(h);
                                        continue;
                                    }
                                }

                            }
                            else if(zamin[sabz[0]][sabz[1] - 6]!='*')
                            {
                                if(zamin[sabz[0]][sabz[1] - 7]=='|')
                                {
                                    cout<<"harekat be samt balaye "<<zamin[sabz[0]][sabz[1]- 6]<<" ya harekat be samt paeene "<<zamin[sabz[0]][sabz[1] - 6]
                                            <<"?( balaye "<<zamin[sabz[0]][sabz[1] - 6]<<" = b , paeene "<<zamin[sabz[0]][sabz[1] - 6]<<"  = p ):";
                                    char m[0];
                                    cin>>m[0];
                                    if(m[0]=='p')
                                    {
                                        if(zamin[sabz[0] + 1][sabz[1] - 2]=='-' || zamin[sabz[0]][sabz[1] - 1]=='|'
                                                ||zamin[sabz[0] + 2][sabz[1] - 1]=='|'||zamin[sabz[0]+2][sabz[1]-6]!='*')
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makanesabz[0]=sabz[0] + 2 ;
                                            makanesabz[1]=sabz[1] - 6 ;
                                            b=false;
                                        }
                                    }
                                    else if(m[0]=='b')
                                    {
                                        if(zamin[sabz[0] - 1][sabz[1] - 2]=='-' || zamin[sabz[0]][sabz[1] - 1]=='|'
                                                ||zamin[sabz[0] - 2][sabz[1] - 1]=='|'||zamin[sabz[0]-2][sabz[1]-6]!='*')
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makanesabz[0]=sabz[0] - 2 ;
                                            makanesabz[1]=sabz[1] - 6 ;
                                            b=false;
                                        }
                                    }
                                    else
                                    {
                                        printeror1(h);
                                        continue;
                                    }
                                }
                                else
                                {
                                    printeror2(h);
                                    continue;
                                }
                            }
                            else
                            {
                                printeror2(h);
                                continue;
                            }
                        }
                        else
                        {
                            printeror2(h);
                            continue;
                        }
                    }
                    else
                    {
                        printeror1(h);
                        continue;
                    }
                }
            }
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            else if (taeen_nobat % 4 == 3)////////blue
            {
                while (b)
                {
                    cout<<" B (user3) "<<" harekat baadi mohreh ra vared konid (bala=b , paeen=p, chap=c, rast=r, movarab=m):";
                    cin>> harekat[0];

                    if(harekat[0]=='b') /////////// بالا
                    {
                        if(zamin[siah[0] - 1][siah[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[siah[0] - 2][siah[1]]!='*')
                        {
                            if(zamin[siah[0] - 3][siah[1]]=='-')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[siah[0] - 4][siah[1]]!='*')
                            {
                                if(zamin[siah[0] - 5][siah[1]]=='-')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[siah[0] - 6][siah[1]]!='*')
                                {
                                    if(zamin[siah[0] - 7][siah[1]]=='-')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSiah[0]=siah[0] - 8;
                                        makaneSiah[1]=siah[1];
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makaneSiah[0]=siah[0] - 6;
                                    makaneSiah[1]=siah[1];
                                    b=false;
                                }
                            }
                            else
                            {
                                makaneSiah[0]=siah[0] - 4;
                                makaneSiah[1]=siah[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSiah[0]=siah[0] - 2;
                            makaneSiah[1]=siah[1];
                            b=false;
                        }
                    }
                    else if(harekat[0]=='p' ) ////////// پایین
                    {
                        if(zamin[siah[0] + 1][siah[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[siah[0] + 2][siah[1]]!='*')
                        {
                            if(zamin[siah[0] + 3][siah[1]]=='-')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[siah[0] + 4][siah[1]]!='*')
                            {
                                if(zamin[siah[0] + 5][siah[1]]=='-')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[siah[0] + 6][siah[1]]!='*')
                                {
                                    if(zamin[siah[0] + 7][siah[1]]=='-')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSiah[0]=siah[0] + 8;
                                        makaneSiah[1]=siah[1];
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makaneSiah[0]=siah[0] + 6;
                                    makaneSiah[1]=siah[1];
                                    b=false;
                                }
                            }
                            else
                            {
                                makaneSiah[0]=siah[0] + 4;
                                makaneSiah[1]=siah[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSiah[0]=siah[0] + 2;
                            makaneSiah[1]=siah[1];
                            b=false;
                        }
                    }
                    else if( harekat[0]=='c' ) ////////// چپ
                    {

                        if(zamin[siah[0]][siah[1] - 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[siah[0]][siah[1] - 2]!='*')
                        {
                            if(zamin[siah[0]][siah[1] - 3]=='|')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[siah[0]][siah[1] - 4]!='*')
                            {
                                if(zamin[siah[0]][siah[1] - 5]=='|')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[siah[0]][siah[1] - 6]!='*')
                                {
                                    if(zamin[siah[0]][siah[1] - 7]=='|')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSiah[0]=siah[0];
                                        makaneSiah[1]=siah[1] - 8;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makaneSiah[0]=siah[0];
                                    makaneSiah[1]=siah[1] - 6;
                                    b=false;
                                }
                            }
                            else
                            {
                                makaneSiah[0]=siah[0];
                                makaneSiah[1]=siah[1] - 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSiah[0]=siah[0];
                            makaneSiah[1]=siah[1] - 2;
                            b=false;
                        }
                    }
                    else if( harekat[0]=='r' ) ///////// راست
                    {

                        if(zamin[siah[0]][siah[1] + 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[siah[0]][siah[1] + 2]!='*')
                        {
                            if(zamin[siah[0]][siah[1] + 3]=='|')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[siah[0]][siah[1] + 4]!='*')
                            {
                                if(zamin[siah[0]][siah[1] + 5]=='|')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[siah[0]][siah[1] + 6]!='*')
                                {
                                    if(zamin[siah[0]][siah[1] + 7]=='|')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSiah[0]=siah[0];
                                        makaneSiah[1]=siah[1] + 8;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makaneSiah[0]=siah[0];
                                    makaneSiah[1]=siah[1] + 6;
                                    b=false;
                                }
                            }
                            else
                            {
                                makaneSiah[0]=siah[0];
                                makaneSiah[1]=siah[1] + 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSiah[0]=siah[0];
                            makaneSiah[1]=siah[1] + 2;
                            b=false;
                        }
                    }
                    else if(harekat[0]=='m') //////////// مورب
                    {
                        if( zamin[siah[0] + 2][siah[1]]!='*')
                        {
                            if(zamin[siah[0] + 3][siah[1]]=='-')
                            {
                                cout<<"harekat be samt chape "<<zamin[siah[0] + 2][siah[1]]<<" ya harekat be samt raste "<<zamin[siah[0] + 2][siah[1]]
                                        <<"?( chape "<<zamin[siah[0] + 2][siah[1]]<<" = c , raste "<<zamin[siah[0] + 2][siah[1]]<<"  = r ):";
                                char m[0];
                                cin>>m[0];
                                if(m[0]=='r')
                                {
                                    if(zamin[siah[0] + 1][siah[1] + 1]=='|' || zamin[siah[0] + 1][siah[1]]=='-'
                                            ||zamin[siah[0] + 1][siah[1] + 1]=='-' ||zamin[siah[0]+2][siah[1]+2])
                                    {
                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSiah[0]=siah[0] + 2 ;
                                        makaneSiah[1]=siah[1] + 2 ;
                                        b=false;
                                    }
                                }
                                else if(m[0]=='c')
                                {
                                    if(zamin[siah[0] + 1][siah[1] - 1]=='|' || zamin[siah[0] + 1][siah[1]]=='-'
                                            ||zamin[siah[0] + 1][siah[1] - 1]=='-'||zamin[siah[0]+2][siah[1]-2])
                                    {
                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSiah[0]=siah[0] + 2 ;
                                        makaneSiah[1]=siah[1] - 2 ;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    printeror1(h);
                                    continue;
                                }
                            }
                            else if(zamin[siah[0] + 4][siah[1]]!='*')
                            {
                                if(zamin[siah[0] + 5][siah[1]]=='-')
                                {
                                    cout<<"harekat be samt chape "<<zamin[siah[0] + 4][siah[1]]<<" ya harekat be samt raste "<<zamin[siah[0] + 4][siah[1]]
                                            <<"?( chape "<<zamin[siah[0] + 4][siah[1]]<<" = c , raste "<<zamin[siah[0] + 4][siah[1]]<<"  = r ):";
                                    char m[0];
                                    cin>>m[0];
                                    if(m[0]=='r')
                                    {
                                        if(zamin[siah[0] + 1][siah[1] + 1]=='|' || zamin[siah[0] + 1][siah[1]]=='-'
                                                ||zamin[siah[0] + 1][siah[1] + 1]=='-'||zamin[siah[0]+4][siah[1]+2])
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makaneSiah[0]=siah[0] + 4 ;
                                            makaneSiah[1]=siah[1] + 2 ;
                                            b=false;
                                        }
                                    }
                                    else if(m[0]=='c')
                                    {
                                        if(zamin[siah[0] + 1][siah[1] - 1]=='|' || zamin[siah[0] + 1][siah[1]]=='-'
                                                ||zamin[siah[0] + 1][siah[1] - 1]=='-' ||zamin[siah[0]+4][siah[1]-2])
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makaneSiah[0]=siah[0] + 4 ;
                                            makaneSiah[1]=siah[1] - 2 ;
                                            b=false;
                                        }
                                    }
                                    else
                                    {
                                        printeror1(h);
                                        continue;
                                    }
                                }

                            }
                            else if(zamin[siah[0] + 6][siah[1]]!='*')
                            {
                                if(zamin[siah[0] + 7][siah[1]]=='-')
                                {
                                    cout<<"harekat be samt chape "<<zamin[siah[0] + 6][siah[1]]<<" ya harekat be samt raste "<<zamin[siah[0] + 6][siah[1]]
                                            <<"?( chape "<<zamin[siah[0] + 6][siah[1]]<<" = c , raste "<<zamin[siah[0] + 6][siah[1]]<<"  = r ):";
                                    char m[0];
                                    cin>>m[0];
                                    if(m[0]=='r')
                                    {
                                        if(zamin[siah[0] + 1][siah[1] + 1]=='|' || zamin[siah[0] + 1][siah[1]]=='-'
                                                ||zamin[siah[0] + 1][siah[1] + 1]=='-'||zamin[siah[0]+6][siah[1]+2])
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makaneSiah[0]=siah[0] + 6 ;
                                            makaneSiah[1]=siah[1] + 2 ;
                                            b=false;
                                        }
                                    }
                                    else if(m[0]=='c')
                                    {
                                        if(zamin[siah[0] + 1][siah[1] - 1]=='|' || zamin[siah[0] + 1][siah[1]]=='-'
                                                ||zamin[siah[0] + 1][siah[1] - 1]=='-' ||zamin[siah[0]+6][siah[1]-2])
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makaneSiah[0]=siah[0] + 6 ;
                                            makaneSiah[1]=siah[1] - 2 ;
                                            b=false;
                                        }
                                    }
                                    else
                                    {
                                        printeror1(h);
                                        continue;
                                    }
                                }
                                else
                                {
                                    printeror2(h);
                                    continue;
                                }
                            }
                            else
                            {
                                printeror2(h);
                                continue;
                            }
                        }
                        else
                        {
                            printeror2(h);
                            continue;
                        }
                    }
                    else
                    {
                        printeror1(h);
                        continue;
                    }
                }
            }
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////

            else if (taeen_nobat % 4 == 0)////////zard
            {
                while (b)
                {
                    cout<<" Y (user4) "<<" harekat baadi mohreh ra vared konid (bala=b , paeen=p, chap=c, rast=r, movarab=m):";
                    cin>> harekat[0];

                    if(harekat[0]=='b') /////////// بالا
                    {
                        if(zamin[zard[0] - 1][zard[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[zard[0] - 2][zard[1]]!='*')
                        {
                            if(zamin[zard[0] - 3][zard[1]]=='-')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[zard[0] - 4][zard[1]]!='*')
                            {
                                if(zamin[zard[0] - 5][zard[1]]=='-')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[zard[0] - 6][zard[1]]!='*')
                                {
                                    if(zamin[zard[0] - 7][zard[1]]=='-')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanezard[0]=zard[0] - 8;
                                        makanezard[1]=zard[1];
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makanezard[0]=zard[0] - 6;
                                    makanezard[1]=zard[1];
                                    b=false;
                                }
                            }
                            else
                            {
                                makanezard[0]=zard[0] - 4;
                                makanezard[1]=zard[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makanezard[0]=zard[0] - 2;
                            makanezard[1]=zard[1];
                            b=false;
                        }
                    }
                    else if(harekat[0]=='p' ) ////////// پایین
                    {
                        if(zamin[zard[0] + 1][zard[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[zard[0] + 2][zard[1]]!='*')
                        {
                            if(zamin[zard[0] + 3][zard[1]]=='-')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[zard[0] + 4][zard[1]]!='*')
                            {
                                if(zamin[zard[0] + 5][zard[1]]=='-')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[zard[0] + 6][zard[1]]!='*')
                                {
                                    if(zamin[zard[0] + 7][zard[1]]=='-')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanezard[0]=zard[0] + 8;
                                        makanezard[1]=zard[1];
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makanezard[0]=zard[0] + 6;
                                    makanezard[1]=zard[1];
                                    b=false;
                                }
                            }
                            else
                            {
                                makanezard[0]=zard[0] + 4;
                                makanezard[1]=zard[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makanezard[0]=zard[0] + 2;
                            makanezard[1]=zard[1];
                            b=false;
                        }
                    }
                    else if( harekat[0]=='c' ) ////////// چپ
                    {

                        if(zamin[zard[0]][zard[1] - 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[zard[0]][zard[1] - 2]!='*')
                        {
                            if(zamin[zard[0]][zard[1] - 3]=='|')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[zard[0]][zard[1] - 4]!='*')
                            {
                                if(zamin[zard[0]][zard[1] - 5]=='|')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[zard[0]][zard[1] - 6]!='*')
                                {
                                    if(zamin[zard[0]][zard[1] - 7]=='|')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanezard[0]=zard[0];
                                        makanezard[1]=zard[1] - 8;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makanezard[0]=zard[0];
                                    makanezard[1]=zard[1] - 6;
                                    b=false;
                                }
                            }
                            else
                            {
                                makanezard[0]=zard[0];
                                makanezard[1]=zard[1] - 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makanezard[0]=zard[0];
                            makanezard[1]=zard[1] - 2;
                            b=false;
                        }
                    }
                    else if( harekat[0]=='r' ) ///////// راست
                    {

                        if(zamin[zard[0]][zard[1] + 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[zard[0]][zard[1] + 2]!='*')
                        {
                            if(zamin[zard[0]][zard[1] + 3]=='|')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[zard[0]][zard[1] + 4]!='*')
                            {
                                if(zamin[zard[0]][zard[1] + 5]=='|')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[zard[0]][zard[1] + 6]!='*')
                                {
                                    if(zamin[zard[0]][zard[1] + 7]=='|')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanezard[0]=zard[0];
                                        makanezard[1]=zard[1] + 8;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makanezard[0]=zard[0];
                                    makanezard[1]=zard[1] + 6;
                                    b=false;
                                }
                            }
                            else
                            {
                                makanezard[0]=zard[0];
                                makanezard[1]=zard[1] + 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makanezard[0]=zard[0];
                            makanezard[1]=zard[1] + 2;
                            b=false;
                        }
                    }
                    else if(harekat[0]=='m') //////////// مورب
                    {
                        if( zamin[zard[0]][zard[1] + 2]!='*')
                        {
                            if(zamin[zard[0]][zard[1] + 3]=='|')
                            {
                                cout<<"harekat be samt balaye "<<zamin[zard[0]][zard[1]+ 2]<<" ya harekat be samt paeene "<<zamin[zard[0]][zard[1] + 2]
                                        <<" ?( balaye "<<zamin[zard[0]][zard[1] + 2]<<" = b , paeene "<<zamin[zard[0]][zard[1] + 2]<<"  = p ):";
                                char m[0];
                                cin>>m[0];
                                if(m[0]=='p')
                                {
                                    if(zamin[zard[0] + 1][zard[1] + 2]=='-' || zamin[zard[0]][zard[1] + 1]=='|'
                                            ||zamin[zard[0] + 2][zard[1] + 1]=='|' ||zamin[zard[0]+2][zard[1]+2])
                                    {
                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanezard[1]=zard[1] + 2 ;
                                        makanezard[0]=zard[0] + 2 ;
                                        b=false;
                                    }
                                }
                                else if(m[0]=='b')
                                {
                                    if(zamin[zard[0] - 1][zard[1] + 2]=='-' || zamin[zard[0]][zard[1] + 1]=='|'
                                            ||zamin[zard[0] - 2][zard[1] + 1]=='|'||zamin[zard[0]-2][zard[1]+2])
                                    {
                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanezard[1]=zard[1] + 2 ;
                                        makanezard[0]=zard[0] - 2 ;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    printeror1(h);
                                    continue;
                                }
                            }
                            else if(zamin[zard[0]][zard[1] + 4]!='*')
                            {
                                if(zamin[zard[0]][zard[1] + 5]=='|')
                                {
                                    cout<<"harekat be samt balaye "<<zamin[zard[0]][zard[1]+ 4]<<" ya harekat be samt paeene "<<zamin[zard[0]][zard[1] + 4]
                                            <<"?( balaye "<<zamin[zard[0]][zard[1] + 4]<<" = b , paeene "<<zamin[zard[0]][zard[1] + 4]<<"  = p ):";
                                    char m[0];
                                    cin>>m[0];
                                    if(m[0]=='p')
                                    {
                                        if(zamin[zard[0] + 1][zard[1] + 2]=='-' || zamin[zard[0]][zard[1] + 1]=='|'
                                                ||zamin[zard[0] + 2][zard[1] + 1]=='|'||zamin[zard[0]+2][zard[1]+4])
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makanezard[0]=zard[0] + 2 ;
                                            makanezard[1]=zard[1] + 4 ;
                                            b=false;
                                        }
                                    }
                                    else if(m[0]=='b')
                                    {
                                        if(zamin[zard[0] - 1][zard[1] + 2]=='-' || zamin[zard[0]][zard[1] + 1]=='|'
                                                ||zamin[zard[0] - 2][zard[1] + 1]=='|'||zamin[zard[0]-2][zard[1]+4])
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makanezard[0]=zard[0] - 2 ;
                                            makanezard[1]=zard[1] + 4 ;
                                            b=false;
                                        }
                                    }
                                    else
                                    {
                                        printeror1(h);
                                        continue;
                                    }
                                }

                            }
                            else if(zamin[zard[0]][zard[1] + 6]!='*')
                            {
                                if(zamin[zard[0]][zard[1] + 7]=='|')
                                {
                                    cout<<"harekat be samt balaye "<<zamin[zard[0]][zard[1]+ 6]<<" ya harekat be samt paeene "<<zamin[zard[0]][zard[1] + 6]
                                            <<"?( balaye "<<zamin[zard[0]][zard[1] + 6]<<" = b , paeene "<<zamin[zard[0]][zard[1] + 6]<<"  = p ):";
                                    char m[0];
                                    cin>>m[0];
                                    if(m[0]=='p')
                                    {
                                        if(zamin[zard[0] + 1][zard[1] + 2]=='-' || zamin[zard[0]][zard[1] + 1]=='|'
                                                ||zamin[zard[0] + 2][zard[1] + 1]=='|'||zamin[zard[0]+2][zard[1]+6])
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makanezard[0]=zard[0] + 2 ;
                                            makanezard[1]=zard[1] + 6 ;
                                            b=false;
                                        }
                                    }
                                    else if(m[0]=='b')
                                    {
                                        if(zamin[zard[0] - 1][zard[1] + 2]=='-' || zamin[zard[0]][zard[1] + 1]=='|'
                                                ||zamin[zard[0] - 2][zard[1] + 1]=='|'||zamin[zard[0]-2][zard[1]+6])
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makanezard[0]=zard[0] - 2 ;
                                            makanezard[1]=zard[1] + 6 ;
                                            b=false;
                                        }
                                    }
                                    else
                                    {
                                        printeror1(h);
                                        continue;
                                    }
                                }
                                else
                                {
                                    printeror2(h);
                                    continue;
                                }
                            }
                            else
                            {
                                printeror2(h);
                                continue;
                            }
                        }
                        else
                        {
                            printeror2(h);
                            continue;
                        }
                    }
                    else
                    {
                        printeror1(h);
                        continue;
                    }
                }
            }
        }
        else
        {
            printeror1(h);
            continue;
        }

        jaygozary4players( makaneSefid , makaneSiah , makanesabz , makanezard,  zamin , sefid , siah , sabz , zard);
        print4players(zamin , h , wall1 , wall2 , wall3 , wall4);
        for(int i =0 ; i<19 ; i++)
        {
            if(zamin[1][i]=='R')
            {
                winer=0;
                t=false;
            }
            if(zamin[17][i]=='B')
            {
                winer=1;
                t=false;
            }
            if(zamin[i][17]=='Y')
            {
                winer=3;
                t=false;
            }
            if(zamin[i][1]=='G')
            {
                winer=2;
                t=false;
            }
        }
        taeen_nobat++;
    }
    return winer;
}

int game4playersDaliz( int winer , string user2[4])
{
    char zamin[abaad][abaad];
    int  mark[19][19];
    int  radifstartDFS=1;
    int  sotoonstartDFS=1;
    char NoeHarekat,NoeDivar;
    char harekat[1];
    int sotoonYAsatrdivar,avaldivar,akhardivar;//ابتدا و انتهای دیوار
    int makaneSefid[2]={ abaad-2 , abaad/2},makaneSiah[2]={ 1 , abaad/2},makanezard[2]={ abaad/2 , 1},makanesabz[2]={ abaad/2 , 17};
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int sefid[2] , siah[2] , zard[2] , sabz[2];
    int divar[2][2];//دیوار وارد شده
    int taeen_nobat=1;
    int wall1=5 , wall2=5 , wall3=5 , wall4=5;
    bool t=true;
    jaygozary4playersDaliz(makaneSefid , makaneSiah , makanesabz ,makanezard , zamin , sefid , siah , sabz , zard);
    print4playersDaliz(zamin , h , wall1 , wall2 , wall3 , wall4);
    while (t == true)
    {
        if (taeen_nobat % 4 == 1)
        {
            SetConsoleTextAttribute(h, 0x4);
            cout<<user2[0];
            SetConsoleTextAttribute(h, 0xf);
        }
        else if (taeen_nobat % 4 == 0)////////////////zard
        {
            SetConsoleTextAttribute(h, 0x6);
            cout<<user2[3];
            SetConsoleTextAttribute(h, 0xf);
        }
        else if (taeen_nobat % 4 == 3)
        {
            SetConsoleTextAttribute(h, 0x9);
            cout<<user2[2];
            SetConsoleTextAttribute(h, 0xf);
        }
        else if (taeen_nobat % 4 == 2)////////////////sabs
        {
            SetConsoleTextAttribute(h, 0xA);
            cout<<user2[1];
            SetConsoleTextAttribute(h, 0xf);
        }
        cout << " Noe Harekat Ra Vared Konid (d:divar , m:mohreh)";
        cin >> NoeHarekat;

        if (NoeHarekat == 'd' || NoeHarekat == 'D')/////////دیوار
        {
            if(wall1==0 && taeen_nobat % 4 == 1)
            {
                SetConsoleTextAttribute(h, 0x4);
                cout<<" Red ";
                SetConsoleTextAttribute(h, 0xf);
                cout<<"walls = 0"<<endl;
                continue;
            }
            if(wall2==0 && taeen_nobat % 4 == 3)
            {
                SetConsoleTextAttribute(h, 0x9);
                cout<<" Blue ";
                SetConsoleTextAttribute(h, 0xf);
                cout<<"walls = 0"<<endl;
                continue;
            }
            if(wall3==0 && taeen_nobat % 4 == 0)///////////////zard
            {
                SetConsoleTextAttribute(h, 0x6);
                cout<<" Yellow ";
                SetConsoleTextAttribute(h, 0xf);
                cout<<"walls = 0"<<endl;
                continue;
            }
            if(wall2==0 && taeen_nobat % 4 == 2)///////////////sabs
            {
                SetConsoleTextAttribute(h, 0xA);
                cout<<" Green ";
                SetConsoleTextAttribute(h, 0xf);
                cout<<"walls = 0"<<endl;
                continue;
            }
            cout << "Noe Divar Ra Vared Konid (a:amoodi , o:ofoghi) ";
            cin >> NoeDivar;
            if (NoeDivar == 'a')
            {
                cout << "Sotoone Divar Ra Vared Konid ";
                cin >> sotoonYAsatrdivar;
                cout << "Ebtedaye Divar Dar Kodam Satr Ast? ";
                cin >> avaldivar;
                cout << "Entehaye Divar Dar Kodam Satr Ast? ";
                cin >> akhardivar;
                if(abs(avaldivar-akhardivar)!=2)
                {
                    printeror2(h);
                    continue;
                }
                divar[0][0] = avaldivar;
                divar[0][1] = sotoonYAsatrdivar;
                divar[1][0]=akhardivar;
                divar[1][1]=sotoonYAsatrdivar;
                zamin[divar[0][0]][divar[0][1]]='|';
                zamin[divar[1][0]][divar[1][1]]='|';
            }
            else if (NoeDivar =='o')
            {
                cout << "Satre Divar Ra Vared Konid ";
                cin >> sotoonYAsatrdivar;
                cout << "Ebtedaye Divar Dar Kodam Sotoon Ast? ";
                cin >> avaldivar;
                cout << "Entehaye Divar Dar Kodam Sotoon Ast? ";
                cin >> akhardivar;
                if(abs(avaldivar-akhardivar)!=2)
                {
                    printeror2(h);
                    continue;
                }
                divar[0][0] = sotoonYAsatrdivar;
                divar[0][1] = avaldivar;
                divar[1][0]=sotoonYAsatrdivar;
                divar[1][1]= akhardivar;
                zamin[divar[0][0]][divar[0][1]]='-';
                zamin[divar[1][0]][divar[1][1]]='-';
            }
            else
            {
                printeror1(h);
                continue;
            }
            Markgozari(zamin,mark);
            dfs (mark,radifstartDFS,sotoonstartDFS);
            if (errorDivar (sotoonYAsatrdivar,avaldivar,akhardivar, mark) == 0 )
            {
                printeror2(h);
                zamin[divar[0][0]][divar[0][1]]=' ';
                zamin[divar[1][0]][divar[1][1]]=' ';
                continue;
            }
            if(taeen_nobat % 4 ==1)
                wall1--;
            if(taeen_nobat % 4 ==3)
                wall2--;
            if(taeen_nobat % 4 ==0)
                wall3--;
            if(taeen_nobat % 4 ==2)
                wall4--;
        }

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else if (NoeHarekat == 'm' || NoeHarekat == 'M')////////مهره
        {
            bool b=true;
            if (taeen_nobat % 4 == 1)////////red
            {
                while (b)
                {
                    cout<<" R (user1) "<<" harekat baadi mohreh ra vared konid (bala=b , paeen=p, chap=c, rast=r, movarab=m)";
                    cin>> harekat[0];

                    if(harekat[0]=='b') /////////// بالا
                    {
                        if(zamin[sefid[0] - 1][sefid[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[sefid[0] - 2][sefid[1]]!='*')
                        {
                            if(zamin[sefid[0] - 3][sefid[1]]=='-')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[sefid[0] - 4][sefid[1]]!='*')
                            {
                                if(zamin[sefid[0] - 5][sefid[1]]=='-')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[sefid[0] - 6][sefid[1]]!='*')
                                {
                                    if(zamin[sefid[0] - 7][sefid[1]]=='-')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSefid[0]=sefid[0] - 8;
                                        makaneSefid[1]=sefid[1];
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makaneSefid[0]=sefid[0] - 6;
                                    makaneSefid[1]=sefid[1];
                                    b=false;
                                }
                            }
                            else
                            {
                                makaneSefid[0]=sefid[0] - 4;
                                makaneSefid[1]=sefid[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSefid[0]=sefid[0] - 2;
                            makaneSefid[1]=sefid[1];
                            b=false;
                        }
                    }
                    else if(harekat[0]=='p' ) ////////// پایین
                    {
                        if(zamin[sefid[0] + 1][sefid[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[sefid[0] + 2][sefid[1]]!='*')
                        {
                            if(zamin[sefid[0] + 3][sefid[1]]=='-')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[sefid[0] + 4][sefid[1]]!='*')
                            {
                                if(zamin[sefid[0] + 5][sefid[1]]=='-')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[sefid[0] + 6][sefid[1]]!='*')
                                {
                                    if(zamin[sefid[0] + 7][sefid[1]]=='-')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSefid[0]=sefid[0] + 8;
                                        makaneSefid[1]=sefid[1];
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makaneSefid[0]=sefid[0] + 6;
                                    makaneSefid[1]=sefid[1];
                                    b=false;
                                }
                            }
                            else
                            {
                                makaneSefid[0]=sefid[0] + 4;
                                makaneSefid[1]=sefid[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSefid[0]=sefid[0] + 2;
                            makaneSefid[1]=sefid[1];
                            b=false;
                        }
                    }
                    else if( harekat[0]=='c' ) ////////// چپ
                    {

                        if(zamin[sefid[0]][sefid[1] - 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[sefid[0]][sefid[1] - 2]!='*')
                        {
                            if(zamin[sefid[0]][sefid[1] - 3]=='|')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[sefid[0]][sefid[1] - 4]!='*')
                            {
                                if(zamin[sefid[0]][sefid[1] - 5]=='|')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[sefid[0]][sefid[1] - 6]!='*')
                                {
                                    if(zamin[sefid[0]][sefid[1] - 7]=='|')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSefid[0]=sefid[0];
                                        makaneSefid[1]=sefid[1] - 8;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makaneSefid[0]=sefid[0];
                                    makaneSefid[1]=sefid[1] - 6;
                                    b=false;
                                }
                            }
                            else
                            {
                                makaneSefid[0]=sefid[0];
                                makaneSefid[1]=sefid[1] - 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSefid[0]=sefid[0];
                            makaneSefid[1]=sefid[1] - 2;
                            b=false;
                        }
                    }
                    else if( harekat[0]=='r' ) ///////// راست
                    {

                        if(zamin[sefid[0]][sefid[1] + 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[sefid[0]][sefid[1] + 2]!='*')
                        {
                            if(zamin[sefid[0]][sefid[1] + 3]=='|')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[sefid[0]][sefid[1] + 4]!='*')
                            {
                                if(zamin[sefid[0]][sefid[1] + 5]=='|')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[sefid[0]][sefid[1] + 6]!='*')
                                {
                                    if(zamin[sefid[0]][sefid[1] + 7]=='|')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSefid[0]=sefid[0];
                                        makaneSefid[1]=sefid[1] + 8;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makaneSefid[0]=sefid[0];
                                    makaneSefid[1]=sefid[1] + 6;
                                    b=false;
                                }
                            }
                            else
                            {
                                makaneSefid[0]=sefid[0];
                                makaneSefid[1]=sefid[1] + 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSefid[0]=sefid[0];
                            makaneSefid[1]=sefid[1] + 2;
                            b=false;
                        }
                    }
                    else if(harekat[0]=='m') //////////// مورب
                    {
                        if( zamin[sefid[0] - 2][sefid[1]]!='*')
                        {
                            if(zamin[sefid[0] - 3][sefid[1]]=='-')
                            {
                                cout<<"harekat be samt chape "<<zamin[sefid[0] - 2][sefid[1]]<<" ya harekat be samt raste "<<zamin[sefid[0] - 2][sefid[1]]
                                        <<"?( chape "<<zamin[sefid[0] - 2][sefid[1]]<<" = c , raste "<<zamin[sefid[0] - 2][sefid[1]]<<"  = r ):";
                                char m[0];
                                cin>>m[0];
                                if(m[0]=='r')
                                {
                                    if(zamin[sefid[0] - 1][sefid[1] + 1]=='|' || zamin[sefid[0] - 1][sefid[1]]=='-'
                                            ||zamin[sefid[0] - 1][sefid[1] + 1]=='-' || zamin[sefid[0]-2][sefid[1]+2]!='*')
                                    {
                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSefid[0]=sefid[0] - 2 ;
                                        makaneSefid[1]=sefid[1] + 2 ;
                                        b=false;
                                    }
                                }
                                else if(m[0]=='c')
                                {
                                    if(zamin[sefid[0] - 1][sefid[1] - 1]=='|' || zamin[sefid[0] - 1][sefid[1]]=='-'
                                            ||zamin[sefid[0] - 1][sefid[1] - 1]=='-' ||zamin[sefid[0]-2][sefid[1]-2]!='*' )
                                    {
                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSefid[0]=sefid[0] - 2 ;
                                        makaneSefid[1]=sefid[1] - 2 ;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    printeror1(h);
                                    continue;
                                }
                            }
                            else if(zamin[sefid[0] - 4][sefid[1]]!='*')
                            {
                                if(zamin[sefid[0] - 5][sefid[1]]=='-')
                                {
                                    cout<<"harekat be samt chape "<<zamin[sefid[0] - 4][sefid[1]]<<" ya harekat be samt raste "<<zamin[sefid[0] - 4][sefid[1]]
                                            <<"?( chape "<<zamin[sefid[0] - 4][sefid[1]]<<" = c , raste "<<zamin[sefid[0] - 4][sefid[1]]<<"  = r ):";
                                    char m[0];
                                    cin>>m[0];
                                    if(m[0]=='r')
                                    {
                                        if(zamin[sefid[0] - 1][sefid[1] + 1]=='|' || zamin[sefid[0] - 1][sefid[1]]=='-'
                                                ||zamin[sefid[0] - 1][sefid[1] + 1]=='-' || zamin[sefid[0]-4][sefid[1]+2]!='*')
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makaneSefid[0]=sefid[0] - 4 ;
                                            makaneSefid[1]=sefid[1] + 2 ;
                                            b=false;
                                        }
                                    }
                                    else if(m[0]=='c')
                                    {
                                        if(zamin[sefid[0] - 1][sefid[1] - 1]=='|' || zamin[sefid[0] - 1][sefid[1]]=='-'
                                                ||zamin[sefid[0] - 1][sefid[1] - 1]=='-'|| zamin[sefid[0]-4][sefid[1]-2]!='*' )
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makaneSefid[0]=sefid[0] - 4 ;
                                            makaneSefid[1]=sefid[1] - 2 ;
                                            b=false;
                                        }
                                    }
                                    else
                                    {
                                        printeror1(h);
                                        continue;
                                    }
                                }

                            }
                            else if(zamin[sefid[0] - 6][sefid[1]]!='*')
                            {
                                if(zamin[sefid[0] - 7][sefid[1]]=='-')
                                {
                                    cout<<"harekat be samt chape "<<zamin[sefid[0] - 6][sefid[1]]<<" ya harekat be samt raste "<<zamin[sefid[0] - 6][sefid[1]]
                                            <<"?( chape "<<zamin[sefid[0] - 6][sefid[1]]<<" = c , raste "<<zamin[sefid[0] - 6][sefid[1]]<<"  = r ):";
                                    char m[0];
                                    cin>>m[0];
                                    if(m[0]=='r')
                                    {
                                        if(zamin[sefid[0] - 1][sefid[1] + 1]=='|' || zamin[sefid[0] - 1][sefid[1]]=='-'
                                                ||zamin[sefid[0] - 1][sefid[1] + 1]=='-'|| zamin[sefid[0]-6][sefid[1]+2]!='*')
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makaneSefid[0]=sefid[0] - 6 ;
                                            makaneSefid[1]=sefid[1] + 2 ;
                                            b=false;
                                        }
                                    }
                                    else if(m[0]=='c')
                                    {
                                        if(zamin[sefid[0] - 1][sefid[1] - 1]=='|' || zamin[sefid[0] - 1][sefid[1]]=='-'
                                                ||zamin[sefid[0] - 1][sefid[1] - 1]=='-'|| zamin[sefid[0]-6][sefid[1]-2]!='*' )
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makaneSefid[0]=sefid[0] - 6 ;
                                            makaneSefid[1]=sefid[1] - 2 ;
                                            b=false;
                                        }
                                    }
                                    else
                                    {
                                        printeror1(h);
                                        continue;
                                    }
                                }
                                else
                                {
                                    printeror2(h);
                                    continue;
                                }
                            }
                            else
                            {
                                printeror2(h);
                                continue;
                            }
                        }
                        else
                        {
                            printeror2(h);
                            continue;
                        }
                    }
                    else
                    {
                        printeror1(h);
                        continue;
                    }
                }
            }
            ////////////////////////////////////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////////////////////////////////

            if (taeen_nobat % 4 == 2)////////sabz
            {
                while (b)
                {
                    cout<<" G (user2) "<<" harekat baadi mohreh ra vared konid (bala=b , paeen=p, chap=c, rast=r, movarab=m)";
                    cin>> harekat[0];

                    if(harekat[0]=='b') /////////// بالا
                    {
                        if(zamin[sabz[0] - 1][sabz[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[sabz[0] - 2][sabz[1]]!='*')
                        {
                            if(zamin[sabz[0] - 3][sabz[1]]=='-')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[sabz[0] - 4][sabz[1]]!='*')
                            {
                                if(zamin[sabz[0] - 5][sabz[1]]=='-')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[sabz[0] - 6][sabz[1]]!='*')
                                {
                                    if(zamin[sabz[0] - 7][sabz[1]]=='-')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanesabz[0]=sabz[0] - 8;
                                        makanesabz[1]=sabz[1];
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makanesabz[0]=sabz[0] - 6;
                                    makanesabz[1]=sabz[1];
                                    b=false;
                                }
                            }
                            else
                            {
                                makanesabz[0]=sabz[0] - 4;
                                makanesabz[1]=sabz[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makanesabz[0]=sabz[0] - 2;
                            makanesabz[1]=sabz[1];
                            b=false;
                        }
                    }
                    else if(harekat[0]=='p' ) ////////// پایین
                    {
                        if(zamin[sabz[0] + 1][sabz[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[sabz[0] + 2][sabz[1]]!='*')
                        {
                            if(zamin[sabz[0] + 3][sabz[1]]=='-')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[sabz[0] + 4][sabz[1]]!='*')
                            {
                                if(zamin[sabz[0] + 5][sabz[1]]=='-')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[sabz[0] + 6][sabz[1]]!='*')
                                {
                                    if(zamin[sabz[0] + 7][sabz[1]]=='-')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanesabz[0]=sabz[0] + 8;
                                        makanesabz[1]=sabz[1];
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makanesabz[0]=sabz[0] + 6;
                                    makanesabz[1]=sabz[1];
                                    b=false;
                                }
                            }
                            else
                            {
                                makanesabz[0]=sabz[0] + 4;
                                makanesabz[1]=sabz[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makanesabz[0]=sabz[0] + 2;
                            makanesabz[1]=sabz[1];
                            b=false;
                        }
                    }
                    else if( harekat[0]=='c' ) ////////// چپ
                    {

                        if(zamin[sabz[0]][sabz[1] - 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[sabz[0]][sabz[1] - 2]!='*')
                        {
                            if(zamin[sabz[0]][sabz[1] - 3]=='|')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[sabz[0]][sabz[1] - 4]!='*')
                            {
                                if(zamin[sabz[0]][sabz[1] - 5]=='|')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[sabz[0]][sabz[1] - 6]!='*')
                                {
                                    if(zamin[sabz[0]][sabz[1] - 7]=='|')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanesabz[0]=sabz[0];
                                        makanesabz[1]=sabz[1] - 8;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makanesabz[0]=sabz[0];
                                    makanesabz[1]=sabz[1] - 6;
                                    b=false;
                                }
                            }
                            else
                            {
                                makanesabz[0]=sabz[0];
                                makanesabz[1]=sabz[1] - 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makanesabz[0]=sabz[0];
                            makanesabz[1]=sabz[1] - 2;
                            b=false;
                        }
                    }
                    else if( harekat[0]=='r' ) ///////// راست
                    {

                        if(zamin[sabz[0]][sabz[1] + 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[sabz[0]][sabz[1] + 2]!='*')
                        {
                            if(zamin[sabz[0]][sabz[1] + 3]=='|')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[sabz[0]][sabz[1] + 4]!='*')
                            {
                                if(zamin[sabz[0]][sabz[1] + 5]=='|')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[sabz[0]][sabz[1] + 6]!='*')
                                {
                                    if(zamin[sabz[0]][sabz[1] + 7]=='|')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanesabz[0]=sabz[0];
                                        makanesabz[1]=sabz[1] + 8;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makanesabz[0]=sabz[0];
                                    makanesabz[1]=sabz[1] + 6;
                                    b=false;
                                }
                            }
                            else
                            {
                                makanesabz[0]=sabz[0];
                                makanesabz[1]=sabz[1] + 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makanesabz[0]=sabz[0];
                            makanesabz[1]=sabz[1] + 2;
                            b=false;
                        }
                    }
                    else if(harekat[0]=='m') //////////// مورب
                    {
                        if( zamin[sabz[0]][sabz[1] - 2]!='*')
                        {
                            if(zamin[sabz[0]][sabz[1] - 3]=='|')
                            {
                                cout<<"harekat be samt balaye "<<zamin[sabz[0]][sabz[1]- 2]<<" ya harekat be samt paeene "<<zamin[sabz[0]][sabz[1] - 2]
                                        <<" ?( balaye "<<zamin[sabz[0]][sabz[1] - 2]<<" = b , paeene "<<zamin[sabz[0]][sabz[1] - 2]<<"  = p ):";
                                char m[0];
                                cin>>m[0];
                                if(m[0]=='p')
                                {
                                    if(zamin[sabz[0] + 1][sabz[1] - 2]=='-' || zamin[sabz[0]][sabz[1] - 1]=='|'
                                            ||zamin[sabz[0] + 2][sabz[1] - 1]=='|' ||zamin[sabz[0]+2][sabz[1]-2]!='*')
                                    {
                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanesabz[1]=sabz[1] - 2 ;
                                        makanesabz[0]=sabz[0] + 2 ;
                                        b=false;
                                    }
                                }
                                else if(m[0]=='b')
                                {
                                    if(zamin[sabz[0] - 1][sabz[1] - 2]=='-' || zamin[sabz[0]][sabz[1] - 1]=='|'
                                            ||zamin[sabz[0] - 2][sabz[1] - 1]=='|'||zamin[sabz[0]-2][sabz[1]-2]!='*')
                                    {
                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanesabz[1]=sabz[1] - 2 ;
                                        makanesabz[0]=sabz[0] - 2 ;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    printeror1(h);
                                    continue;
                                }
                            }
                            else if(zamin[sabz[0]][sabz[1] - 4]!='*')
                            {
                                if(zamin[sabz[0]][sabz[1] - 5]=='|')
                                {
                                    cout<<"harekat be samt balaye "<<zamin[sabz[0]][sabz[1]- 4]<<" ya harekat be samt paeene "<<zamin[sabz[0]][sabz[1] - 4]
                                            <<"?( balaye "<<zamin[sabz[0]][sabz[1] - 4]<<" = b , paeene "<<zamin[sabz[0]][sabz[1] - 4]<<"  = p ):";
                                    char m[0];
                                    cin>>m[0];
                                    if(m[0]=='p')
                                    {
                                        if(zamin[sabz[0] + 1][sabz[1] - 2]=='-' || zamin[sabz[0]][sabz[1] - 1]=='|'
                                                ||zamin[sabz[0] + 2][sabz[1] - 1]=='|'||zamin[sabz[0]+2][sabz[1]-4]!='*')
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makanesabz[0]=sabz[0] + 2 ;
                                            makanesabz[1]=sabz[1] - 4 ;
                                            b=false;
                                        }
                                    }
                                    else if(m[0]=='b')
                                    {
                                        if(zamin[sabz[0] - 1][sabz[1] - 2]=='-' || zamin[sabz[0]][sabz[1] - 1]=='|'
                                                ||zamin[sabz[0] - 2][sabz[1] - 1]=='|'||zamin[sabz[0]-2][sabz[1]-4]!='*')
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makanesabz[0]=sabz[0] - 2 ;
                                            makanesabz[1]=sabz[1] - 4 ;
                                            b=false;
                                        }
                                    }
                                    else
                                    {
                                        printeror1(h);
                                        continue;
                                    }
                                }

                            }
                            else if(zamin[sabz[0]][sabz[1] - 6]!='*')
                            {
                                if(zamin[sabz[0]][sabz[1] - 7]=='|')
                                {
                                    cout<<"harekat be samt balaye "<<zamin[sabz[0]][sabz[1]- 6]<<" ya harekat be samt paeene "<<zamin[sabz[0]][sabz[1] - 6]
                                            <<"?( balaye "<<zamin[sabz[0]][sabz[1] - 6]<<" = b , paeene "<<zamin[sabz[0]][sabz[1] - 6]<<"  = p ):";
                                    char m[0];
                                    cin>>m[0];
                                    if(m[0]=='p')
                                    {
                                        if(zamin[sabz[0] + 1][sabz[1] - 2]=='-' || zamin[sabz[0]][sabz[1] - 1]=='|'
                                                ||zamin[sabz[0] + 2][sabz[1] - 1]=='|'||zamin[sabz[0]+2][sabz[1]-6]!='*')
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makanesabz[0]=sabz[0] + 2 ;
                                            makanesabz[1]=sabz[1] - 6 ;
                                            b=false;
                                        }
                                    }
                                    else if(m[0]=='b')
                                    {
                                        if(zamin[sabz[0] - 1][sabz[1] - 2]=='-' || zamin[sabz[0]][sabz[1] - 1]=='|'
                                                ||zamin[sabz[0] - 2][sabz[1] - 1]=='|'||zamin[sabz[0]-2][sabz[1]-6]!='*')
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makanesabz[0]=sabz[0] - 2 ;
                                            makanesabz[1]=sabz[1] - 6 ;
                                            b=false;
                                        }
                                    }
                                    else
                                    {
                                        printeror1(h);
                                        continue;
                                    }
                                }
                                else
                                {
                                    printeror2(h);
                                    continue;
                                }
                            }
                            else
                            {
                                printeror2(h);
                                continue;
                            }
                        }
                        else
                        {
                            printeror2(h);
                            continue;
                        }
                    }
                    else
                    {
                        printeror1(h);
                        continue;
                    }
                }
            }
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            else if (taeen_nobat % 4 == 3)////////blue
            {
                while (b)
                {
                    cout<<" B (user3) "<<" harekat baadi mohreh ra vared konid (bala=b , paeen=p, chap=c, rast=r, movarab=m):";
                    cin>> harekat[0];

                    if(harekat[0]=='b') /////////// بالا
                    {
                        if(zamin[siah[0] - 1][siah[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[siah[0] - 2][siah[1]]!='*')
                        {
                            if(zamin[siah[0] - 3][siah[1]]=='-')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[siah[0] - 4][siah[1]]!='*')
                            {
                                if(zamin[siah[0] - 5][siah[1]]=='-')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[siah[0] - 6][siah[1]]!='*')
                                {
                                    if(zamin[siah[0] - 7][siah[1]]=='-')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSiah[0]=siah[0] - 8;
                                        makaneSiah[1]=siah[1];
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makaneSiah[0]=siah[0] - 6;
                                    makaneSiah[1]=siah[1];
                                    b=false;
                                }
                            }
                            else
                            {
                                makaneSiah[0]=siah[0] - 4;
                                makaneSiah[1]=siah[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSiah[0]=siah[0] - 2;
                            makaneSiah[1]=siah[1];
                            b=false;
                        }
                    }
                    else if(harekat[0]=='p' ) ////////// پایین
                    {
                        if(zamin[siah[0] + 1][siah[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[siah[0] + 2][siah[1]]!='*')
                        {
                            if(zamin[siah[0] + 3][siah[1]]=='-')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[siah[0] + 4][siah[1]]!='*')
                            {
                                if(zamin[siah[0] + 5][siah[1]]=='-')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[siah[0] + 6][siah[1]]!='*')
                                {
                                    if(zamin[siah[0] + 7][siah[1]]=='-')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSiah[0]=siah[0] + 8;
                                        makaneSiah[1]=siah[1];
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makaneSiah[0]=siah[0] + 6;
                                    makaneSiah[1]=siah[1];
                                    b=false;
                                }
                            }
                            else
                            {
                                makaneSiah[0]=siah[0] + 4;
                                makaneSiah[1]=siah[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSiah[0]=siah[0] + 2;
                            makaneSiah[1]=siah[1];
                            b=false;
                        }
                    }
                    else if( harekat[0]=='c' ) ////////// چپ
                    {

                        if(zamin[siah[0]][siah[1] - 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[siah[0]][siah[1] - 2]!='*')
                        {
                            if(zamin[siah[0]][siah[1] - 3]=='|')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[siah[0]][siah[1] - 4]!='*')
                            {
                                if(zamin[siah[0]][siah[1] - 5]=='|')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[siah[0]][siah[1] - 6]!='*')
                                {
                                    if(zamin[siah[0]][siah[1] - 7]=='|')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSiah[0]=siah[0];
                                        makaneSiah[1]=siah[1] - 8;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makaneSiah[0]=siah[0];
                                    makaneSiah[1]=siah[1] - 6;
                                    b=false;
                                }
                            }
                            else
                            {
                                makaneSiah[0]=siah[0];
                                makaneSiah[1]=siah[1] - 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSiah[0]=siah[0];
                            makaneSiah[1]=siah[1] - 2;
                            b=false;
                        }
                    }
                    else if( harekat[0]=='r' ) ///////// راست
                    {

                        if(zamin[siah[0]][siah[1] + 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[siah[0]][siah[1] + 2]!='*')
                        {
                            if(zamin[siah[0]][siah[1] + 3]=='|')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[siah[0]][siah[1] + 4]!='*')
                            {
                                if(zamin[siah[0]][siah[1] + 5]=='|')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[siah[0]][siah[1] + 6]!='*')
                                {
                                    if(zamin[siah[0]][siah[1] + 7]=='|')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSiah[0]=siah[0];
                                        makaneSiah[1]=siah[1] + 8;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makaneSiah[0]=siah[0];
                                    makaneSiah[1]=siah[1] + 6;
                                    b=false;
                                }
                            }
                            else
                            {
                                makaneSiah[0]=siah[0];
                                makaneSiah[1]=siah[1] + 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makaneSiah[0]=siah[0];
                            makaneSiah[1]=siah[1] + 2;
                            b=false;
                        }
                    }
                    else if(harekat[0]=='m') //////////// مورب
                    {
                        if( zamin[siah[0] + 2][siah[1]]!='*')
                        {
                            if(zamin[siah[0] + 3][siah[1]]=='-')
                            {
                                cout<<"harekat be samt chape "<<zamin[siah[0] + 2][siah[1]]<<" ya harekat be samt raste "<<zamin[siah[0] + 2][siah[1]]
                                        <<"?( chape "<<zamin[siah[0] + 2][siah[1]]<<" = c , raste "<<zamin[siah[0] + 2][siah[1]]<<"  = r ):";
                                char m[0];
                                cin>>m[0];
                                if(m[0]=='r')
                                {
                                    if(zamin[siah[0] + 1][siah[1] + 1]=='|' || zamin[siah[0] + 1][siah[1]]=='-'
                                            ||zamin[siah[0] + 1][siah[1] + 1]=='-' ||zamin[siah[0]+2][siah[1]+2])
                                    {
                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSiah[0]=siah[0] + 2 ;
                                        makaneSiah[1]=siah[1] + 2 ;
                                        b=false;
                                    }
                                }
                                else if(m[0]=='c')
                                {
                                    if(zamin[siah[0] + 1][siah[1] - 1]=='|' || zamin[siah[0] + 1][siah[1]]=='-'
                                            ||zamin[siah[0] + 1][siah[1] - 1]=='-'||zamin[siah[0]+2][siah[1]-2])
                                    {
                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makaneSiah[0]=siah[0] + 2 ;
                                        makaneSiah[1]=siah[1] - 2 ;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    printeror1(h);
                                    continue;
                                }
                            }
                            else if(zamin[siah[0] + 4][siah[1]]!='*')
                            {
                                if(zamin[siah[0] + 5][siah[1]]=='-')
                                {
                                    cout<<"harekat be samt chape "<<zamin[siah[0] + 4][siah[1]]<<" ya harekat be samt raste "<<zamin[siah[0] + 4][siah[1]]
                                            <<"?( chape "<<zamin[siah[0] + 4][siah[1]]<<" = c , raste "<<zamin[siah[0] + 4][siah[1]]<<"  = r ):";
                                    char m[0];
                                    cin>>m[0];
                                    if(m[0]=='r')
                                    {
                                        if(zamin[siah[0] + 1][siah[1] + 1]=='|' || zamin[siah[0] + 1][siah[1]]=='-'
                                                ||zamin[siah[0] + 1][siah[1] + 1]=='-'||zamin[siah[0]+4][siah[1]+2])
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makaneSiah[0]=siah[0] + 4 ;
                                            makaneSiah[1]=siah[1] + 2 ;
                                            b=false;
                                        }
                                    }
                                    else if(m[0]=='c')
                                    {
                                        if(zamin[siah[0] + 1][siah[1] - 1]=='|' || zamin[siah[0] + 1][siah[1]]=='-'
                                                ||zamin[siah[0] + 1][siah[1] - 1]=='-' ||zamin[siah[0]+4][siah[1]-2])
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makaneSiah[0]=siah[0] + 4 ;
                                            makaneSiah[1]=siah[1] - 2 ;
                                            b=false;
                                        }
                                    }
                                    else
                                    {
                                        printeror1(h);
                                        continue;
                                    }
                                }

                            }
                            else if(zamin[siah[0] + 6][siah[1]]!='*')
                            {
                                if(zamin[siah[0] + 7][siah[1]]=='-')
                                {
                                    cout<<"harekat be samt chape "<<zamin[siah[0] + 6][siah[1]]<<" ya harekat be samt raste "<<zamin[siah[0] + 6][siah[1]]
                                            <<"?( chape "<<zamin[siah[0] + 6][siah[1]]<<" = c , raste "<<zamin[siah[0] + 6][siah[1]]<<"  = r ):";
                                    char m[0];
                                    cin>>m[0];
                                    if(m[0]=='r')
                                    {
                                        if(zamin[siah[0] + 1][siah[1] + 1]=='|' || zamin[siah[0] + 1][siah[1]]=='-'
                                                ||zamin[siah[0] + 1][siah[1] + 1]=='-'||zamin[siah[0]+6][siah[1]+2])
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makaneSiah[0]=siah[0] + 6 ;
                                            makaneSiah[1]=siah[1] + 2 ;
                                            b=false;
                                        }
                                    }
                                    else if(m[0]=='c')
                                    {
                                        if(zamin[siah[0] + 1][siah[1] - 1]=='|' || zamin[siah[0] + 1][siah[1]]=='-'
                                                ||zamin[siah[0] + 1][siah[1] - 1]=='-' ||zamin[siah[0]+6][siah[1]-2])
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makaneSiah[0]=siah[0] + 6 ;
                                            makaneSiah[1]=siah[1] - 2 ;
                                            b=false;
                                        }
                                    }
                                    else
                                    {
                                        printeror1(h);
                                        continue;
                                    }
                                }
                                else
                                {
                                    printeror2(h);
                                    continue;
                                }
                            }
                            else
                            {
                                printeror2(h);
                                continue;
                            }
                        }
                        else
                        {
                            printeror2(h);
                            continue;
                        }
                    }
                    else
                    {
                        printeror1(h);
                        continue;
                    }
                }
            }
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////

            else if (taeen_nobat % 4 == 0)////////zard
            {
                while (b)
                {
                    cout<<" Y (user4) "<<" harekat baadi mohreh ra vared konid (bala=b , paeen=p, chap=c, rast=r, movarab=m):";
                    cin>> harekat[0];

                    if(harekat[0]=='b') /////////// بالا
                    {
                        if(zamin[zard[0] - 1][zard[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[zard[0] - 2][zard[1]]!='*')
                        {
                            if(zamin[zard[0] - 3][zard[1]]=='-')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[zard[0] - 4][zard[1]]!='*')
                            {
                                if(zamin[zard[0] - 5][zard[1]]=='-')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[zard[0] - 6][zard[1]]!='*')
                                {
                                    if(zamin[zard[0] - 7][zard[1]]=='-')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanezard[0]=zard[0] - 8;
                                        makanezard[1]=zard[1];
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makanezard[0]=zard[0] - 6;
                                    makanezard[1]=zard[1];
                                    b=false;
                                }
                            }
                            else
                            {
                                makanezard[0]=zard[0] - 4;
                                makanezard[1]=zard[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makanezard[0]=zard[0] - 2;
                            makanezard[1]=zard[1];
                            b=false;
                        }
                    }
                    else if(harekat[0]=='p' ) ////////// پایین
                    {
                        if(zamin[zard[0] + 1][zard[1]]=='-')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[zard[0] + 2][zard[1]]!='*')
                        {
                            if(zamin[zard[0] + 3][zard[1]]=='-')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[zard[0] + 4][zard[1]]!='*')
                            {
                                if(zamin[zard[0] + 5][zard[1]]=='-')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[zard[0] + 6][zard[1]]!='*')
                                {
                                    if(zamin[zard[0] + 7][zard[1]]=='-')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanezard[0]=zard[0] + 8;
                                        makanezard[1]=zard[1];
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makanezard[0]=zard[0] + 6;
                                    makanezard[1]=zard[1];
                                    b=false;
                                }
                            }
                            else
                            {
                                makanezard[0]=zard[0] + 4;
                                makanezard[1]=zard[1];
                                b=false;
                            }
                        }
                        else
                        {
                            makanezard[0]=zard[0] + 2;
                            makanezard[1]=zard[1];
                            b=false;
                        }
                    }
                    else if( harekat[0]=='c' ) ////////// چپ
                    {

                        if(zamin[zard[0]][zard[1] - 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[zard[0]][zard[1] - 2]!='*')
                        {
                            if(zamin[zard[0]][zard[1] - 3]=='|')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[zard[0]][zard[1] - 4]!='*')
                            {
                                if(zamin[zard[0]][zard[1] - 5]=='|')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[zard[0]][zard[1] - 6]!='*')
                                {
                                    if(zamin[zard[0]][zard[1] - 7]=='|')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanezard[0]=zard[0];
                                        makanezard[1]=zard[1] - 8;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makanezard[0]=zard[0];
                                    makanezard[1]=zard[1] - 6;
                                    b=false;
                                }
                            }
                            else
                            {
                                makanezard[0]=zard[0];
                                makanezard[1]=zard[1] - 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makanezard[0]=zard[0];
                            makanezard[1]=zard[1] - 2;
                            b=false;
                        }
                    }
                    else if( harekat[0]=='r' ) ///////// راست
                    {

                        if(zamin[zard[0]][zard[1] + 1]=='|')
                        {
                            printeror2(h);
                            continue;
                        }
                        else if(zamin[zard[0]][zard[1] + 2]!='*')
                        {
                            if(zamin[zard[0]][zard[1] + 3]=='|')
                            {

                                printeror2(h);
                                continue;
                            }
                            else if(zamin[zard[0]][zard[1] + 4]!='*')
                            {
                                if(zamin[zard[0]][zard[1] + 5]=='|')
                                {

                                    printeror2(h);
                                    continue;
                                }
                                else if(zamin[zard[0]][zard[1] + 6]!='*')
                                {
                                    if(zamin[zard[0]][zard[1] + 7]=='|')
                                    {

                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanezard[0]=zard[0];
                                        makanezard[1]=zard[1] + 8;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    makanezard[0]=zard[0];
                                    makanezard[1]=zard[1] + 6;
                                    b=false;
                                }
                            }
                            else
                            {
                                makanezard[0]=zard[0];
                                makanezard[1]=zard[1] + 4;
                                b=false;
                            }
                        }
                        else
                        {
                            makanezard[0]=zard[0];
                            makanezard[1]=zard[1] + 2;
                            b=false;
                        }
                    }
                    else if(harekat[0]=='m') //////////// مورب
                    {
                        if( zamin[zard[0]][zard[1] + 2]!='*')
                        {
                            if(zamin[zard[0]][zard[1] + 3]=='|')
                            {
                                cout<<"harekat be samt balaye "<<zamin[zard[0]][zard[1]+ 2]<<" ya harekat be samt paeene "<<zamin[zard[0]][zard[1] + 2]
                                        <<" ?( balaye "<<zamin[zard[0]][zard[1] + 2]<<" = b , paeene "<<zamin[zard[0]][zard[1] + 2]<<"  = p ):";
                                char m[0];
                                cin>>m[0];
                                if(m[0]=='p')
                                {
                                    if(zamin[zard[0] + 1][zard[1] + 2]=='-' || zamin[zard[0]][zard[1] + 1]=='|'
                                            ||zamin[zard[0] + 2][zard[1] + 1]=='|' ||zamin[zard[0]+2][zard[1]+2])
                                    {
                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanezard[1]=zard[1] + 2 ;
                                        makanezard[0]=zard[0] + 2 ;
                                        b=false;
                                    }
                                }
                                else if(m[0]=='b')
                                {
                                    if(zamin[zard[0] - 1][zard[1] + 2]=='-' || zamin[zard[0]][zard[1] + 1]=='|'
                                            ||zamin[zard[0] - 2][zard[1] + 1]=='|'||zamin[zard[0]-2][zard[1]+2])
                                    {
                                        printeror2(h);
                                        continue;
                                    }
                                    else
                                    {
                                        makanezard[1]=zard[1] + 2 ;
                                        makanezard[0]=zard[0] - 2 ;
                                        b=false;
                                    }
                                }
                                else
                                {
                                    printeror1(h);
                                    continue;
                                }
                            }
                            else if(zamin[zard[0]][zard[1] + 4]!='*')
                            {
                                if(zamin[zard[0]][zard[1] + 5]=='|')
                                {
                                    cout<<"harekat be samt balaye "<<zamin[zard[0]][zard[1]+ 4]<<" ya harekat be samt paeene "<<zamin[zard[0]][zard[1] + 4]
                                            <<"?( balaye "<<zamin[zard[0]][zard[1] + 4]<<" = b , paeene "<<zamin[zard[0]][zard[1] + 4]<<"  = p ):";
                                    char m[0];
                                    cin>>m[0];
                                    if(m[0]=='p')
                                    {
                                        if(zamin[zard[0] + 1][zard[1] + 2]=='-' || zamin[zard[0]][zard[1] + 1]=='|'
                                                ||zamin[zard[0] + 2][zard[1] + 1]=='|'||zamin[zard[0]+2][zard[1]+4])
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makanezard[0]=zard[0] + 2 ;
                                            makanezard[1]=zard[1] + 4 ;
                                            b=false;
                                        }
                                    }
                                    else if(m[0]=='b')
                                    {
                                        if(zamin[zard[0] - 1][zard[1] + 2]=='-' || zamin[zard[0]][zard[1] + 1]=='|'
                                                ||zamin[zard[0] - 2][zard[1] + 1]=='|'||zamin[zard[0]-2][zard[1]+4])
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makanezard[0]=zard[0] - 2 ;
                                            makanezard[1]=zard[1] + 4 ;
                                            b=false;
                                        }
                                    }
                                    else
                                    {
                                        printeror1(h);
                                        continue;
                                    }
                                }

                            }
                            else if(zamin[zard[0]][zard[1] + 6]!='*')
                            {
                                if(zamin[zard[0]][zard[1] + 7]=='|')
                                {
                                    cout<<"harekat be samt balaye "<<zamin[zard[0]][zard[1]+ 6]<<" ya harekat be samt paeene "<<zamin[zard[0]][zard[1] + 6]
                                            <<"?( balaye "<<zamin[zard[0]][zard[1] + 6]<<" = b , paeene "<<zamin[zard[0]][zard[1] + 6]<<"  = p ):";
                                    char m[0];
                                    cin>>m[0];
                                    if(m[0]=='p')
                                    {
                                        if(zamin[zard[0] + 1][zard[1] + 2]=='-' || zamin[zard[0]][zard[1] + 1]=='|'
                                                ||zamin[zard[0] + 2][zard[1] + 1]=='|'||zamin[zard[0]+2][zard[1]+6])
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makanezard[0]=zard[0] + 2 ;
                                            makanezard[1]=zard[1] + 6 ;
                                            b=false;
                                        }
                                    }
                                    else if(m[0]=='b')
                                    {
                                        if(zamin[zard[0] - 1][zard[1] + 2]=='-' || zamin[zard[0]][zard[1] + 1]=='|'
                                                ||zamin[zard[0] - 2][zard[1] + 1]=='|'||zamin[zard[0]-2][zard[1]+6])
                                        {
                                            printeror2(h);
                                            continue;
                                        }
                                        else
                                        {
                                            makanezard[0]=zard[0] - 2 ;
                                            makanezard[1]=zard[1] + 6 ;
                                            b=false;
                                        }
                                    }
                                    else
                                    {
                                        printeror1(h);
                                        continue;
                                    }
                                }
                                else
                                {
                                    printeror2(h);
                                    continue;
                                }
                            }
                            else
                            {
                                printeror2(h);
                                continue;
                            }
                        }
                        else
                        {
                            printeror2(h);
                            continue;
                        }
                    }
                    else
                    {
                        printeror1(h);
                        continue;
                    }
                }
            }
        }
        else
        {
            printeror1(h);
            continue;
        }

        jaygozary4playersDaliz( makaneSefid , makaneSiah , makanesabz , makanezard,  zamin , sefid , siah , sabz , zard);
        print4playersDaliz(zamin , h , wall1 , wall2 , wall3 , wall4);
        for(int i =0 ; i<19 ; i++)
        {
            if((zamin[1][i]=='R') ||
                    (zamin[7][9]=='R' && zamin[8][9] != '-')||
                    (zamin[11][9]=='R' && zamin[10][9] != '-') ||
                    (zamin[9][7]=='R' && zamin[9][8] != '|')||
                    (zamin[9][11]=='R' && zamin[9][10] != '|'))
            {
                winer=0;
                t=false;
            }
            if((zamin[17][i]=='B') ||
                    (zamin[7][9]=='B' && zamin[8][9] != '-')||
                    (zamin[11][9]=='B' && zamin[10][9] != '-') ||
                    (zamin[9][7]=='B' && zamin[9][8] != '|')||
                    (zamin[9][11]=='B' && zamin[9][10] != '|'))
            {
                winer=1;
                t=false;
            }
            if((zamin[i][17]=='Y') ||
                    (zamin[7][9]=='Y' && zamin[8][9] != '-')||
                    (zamin[11][9]=='Y' && zamin[10][9] != '-') ||
                    (zamin[9][7]=='Y' && zamin[9][8] != '|')||
                    (zamin[9][11]=='Y' && zamin[9][10] != '|'))
            {
                winer=3;
                t=false;
            }
            if((zamin[i][1]=='G') ||
                    (zamin[7][9]=='G' && zamin[8][9] != '-')||
                    (zamin[11][9]=='G' && zamin[10][9] != '-') ||
                    (zamin[9][7]=='G' && zamin[9][8] != '|')||
                    (zamin[9][11]=='G' && zamin[9][10] != '|'))
            {
                winer=2;
                t=false;
            }
        }
        taeen_nobat++;
    }
    return winer;

}
void harekat1( int sabz[2]  , int makanesabz[2], char zamin[abaad][abaad])
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    char harekat[1];
    bool b=true;
    while (b)
    {
        cout<<zamin[sabz[0]][sabz[1]]<<" harekat baadi mohreh ra vared konid (bala=b , paeen=p, chap=c, rast=r, movarab=m)";
        cin>> harekat[0];

        if(harekat[0]=='b') /////////// بالا
        {
            if(zamin[sabz[0] - 1][sabz[1]]=='-')
            {
                printeror2(h);
                continue;
            }
            else if(zamin[sabz[0] - 2][sabz[1]]!='*')
            {
                if(zamin[sabz[0] - 3][sabz[1]]=='-')
                {

                    printeror2(h);
                    continue;
                }
                else if(zamin[sabz[0] - 4][sabz[1]]!='*')
                {
                    if(zamin[sabz[0] - 5][sabz[1]]=='-')
                    {

                        printeror2(h);
                        continue;
                    }
                    else if(zamin[sabz[0] - 6][sabz[1]]!='*')
                    {
                        if(zamin[sabz[0] - 7][sabz[1]]=='-')
                        {

                            printeror2(h);
                            continue;
                        }
                        else
                        {
                            makanesabz[0]=sabz[0] - 8;
                            makanesabz[1]=sabz[1];
                            b=false;
                        }
                    }
                    else
                    {
                        makanesabz[0]=sabz[0] - 6;
                        makanesabz[1]=sabz[1];
                        b=false;
                    }
                }
                else
                {
                    makanesabz[0]=sabz[0] - 4;
                    makanesabz[1]=sabz[1];
                    b=false;
                }
            }
            else
            {
                makanesabz[0]=sabz[0] - 2;
                makanesabz[1]=sabz[1];
                b=false;
            }
        }
        else if(harekat[0]=='p' ) ////////// پایین
        {
            if(zamin[sabz[0] + 1][sabz[1]]=='-')
            {
                printeror2(h);
                continue;
            }
            else if(zamin[sabz[0] + 2][sabz[1]]!='*')
            {
                if(zamin[sabz[0] + 3][sabz[1]]=='-')
                {

                    printeror2(h);
                    continue;
                }
                else if(zamin[sabz[0] + 4][sabz[1]]!='*')
                {
                    if(zamin[sabz[0] + 5][sabz[1]]=='-')
                    {

                        printeror2(h);
                        continue;
                    }
                    else if(zamin[sabz[0] + 6][sabz[1]]!='*')
                    {
                        if(zamin[sabz[0] + 7][sabz[1]]=='-')
                        {

                            printeror2(h);
                            continue;
                        }
                        else
                        {
                            makanesabz[0]=sabz[0] + 8;
                            makanesabz[1]=sabz[1];
                            b=false;
                        }
                    }
                    else
                    {
                        makanesabz[0]=sabz[0] + 6;
                        makanesabz[1]=sabz[1];
                        b=false;
                    }
                }
                else
                {
                    makanesabz[0]=sabz[0] + 4;
                    makanesabz[1]=sabz[1];
                    b=false;
                }
            }
            else
            {
                makanesabz[0]=sabz[0] + 2;
                makanesabz[1]=sabz[1];
                b=false;
            }
        }
        else if( harekat[0]=='c' ) ////////// چپ
        {

            if(zamin[sabz[0]][sabz[1] - 1]=='|')
            {
                printeror2(h);
                continue;
            }
            else if(zamin[sabz[0]][sabz[1] - 2]!='*')
            {
                if(zamin[sabz[0]][sabz[1] - 3]=='|')
                {

                    printeror2(h);
                    continue;
                }
                else if(zamin[sabz[0]][sabz[1] - 4]!='*')
                {
                    if(zamin[sabz[0]][sabz[1] - 5]=='|')
                    {

                        printeror2(h);
                        continue;
                    }
                    else if(zamin[sabz[0]][sabz[1] - 6]!='*')
                    {
                        if(zamin[sabz[0]][sabz[1] - 7]=='|')
                        {

                            printeror2(h);
                            continue;
                        }
                        else
                        {
                            makanesabz[0]=sabz[0];
                            makanesabz[1]=sabz[1] - 8;
                            b=false;
                        }
                    }
                    else
                    {
                        makanesabz[0]=sabz[0];
                        makanesabz[1]=sabz[1] - 6;
                        b=false;
                    }
                }
                else
                {
                    makanesabz[0]=sabz[0];
                    makanesabz[1]=sabz[1] - 4;
                    b=false;
                }
            }
            else
            {
                makanesabz[0]=sabz[0];
                makanesabz[1]=sabz[1] - 2;
                b=false;
            }
        }
        else if( harekat[0]=='r' ) ///////// راست
        {

            if(zamin[sabz[0]][sabz[1] + 1]=='|')
            {
                printeror2(h);
                continue;
            }
            else if(zamin[sabz[0]][sabz[1] + 2]!='*')
            {
                if(zamin[sabz[0]][sabz[1] + 3]=='|')
                {

                    printeror2(h);
                    continue;
                }
                else if(zamin[sabz[0]][sabz[1] + 4]!='*')
                {
                    if(zamin[sabz[0]][sabz[1] + 5]=='|')
                    {

                        printeror2(h);
                        continue;
                    }
                    else if(zamin[sabz[0]][sabz[1] + 6]!='*')
                    {
                        if(zamin[sabz[0]][sabz[1] + 7]=='|')
                        {

                            printeror2(h);
                            continue;
                        }
                        else
                        {
                            makanesabz[0]=sabz[0];
                            makanesabz[1]=sabz[1] + 8;
                            b=false;
                        }
                    }
                    else
                    {
                        makanesabz[0]=sabz[0];
                        makanesabz[1]=sabz[1] + 6;
                        b=false;
                    }
                }
                else
                {
                    makanesabz[0]=sabz[0];
                    makanesabz[1]=sabz[1] + 4;
                    b=false;
                }
            }
            else
            {
                makanesabz[0]=sabz[0];
                makanesabz[1]=sabz[1] + 2;
                b=false;
            }
        }
        else if(harekat[0]=='m') //////////// مورب
        {
            if( zamin[sabz[0] - 2][sabz[1]]!='*')
            {
                if(zamin[sabz[0] - 3][sabz[1]]=='-')
                {
                    cout<<"harekat be samt chape "<<zamin[sabz[0] - 2][sabz[1]]<<" ya harekat be samt raste "<<zamin[sabz[0] - 2][sabz[1]]
                            <<"?( chape "<<zamin[sabz[0] - 2][sabz[1]]<<" = c , raste "<<zamin[sabz[0] - 2][sabz[1]]<<"  = r ):";
                    char m[0];
                    cin>>m[0];
                    if(m[0]=='r')
                    {
                        if(zamin[sabz[0] - 1][sabz[1] + 1]=='|' || zamin[sabz[0] - 1][sabz[1]]=='-'
                                ||zamin[sabz[0] - 1][sabz[1] + 1]=='-' || zamin[sabz[0]-2][sabz[1]+2]!='*')
                        {
                            printeror2(h);
                            continue;
                        }
                        else
                        {
                            makanesabz[0]=sabz[0] - 2 ;
                            makanesabz[1]=sabz[1] + 2 ;
                            b=false;
                        }
                    }
                    else if(m[0]=='c')
                    {
                        if(zamin[sabz[0] - 1][sabz[1] - 1]=='|' || zamin[sabz[0] - 1][sabz[1]]=='-'
                                ||zamin[sabz[0] - 1][sabz[1] - 1]=='-' ||zamin[sabz[0]-2][sabz[1]-2]!='*' )
                        {
                            printeror2(h);
                            continue;
                        }
                        else
                        {
                            makanesabz[0]=sabz[0] - 2 ;
                            makanesabz[1]=sabz[1] - 2 ;
                            b=false;
                        }
                    }
                    else
                    {
                        printeror1(h);
                        continue;
                    }
                }
                else if(zamin[sabz[0] - 4][sabz[1]]!='*')
                {
                    if(zamin[sabz[0] - 5][sabz[1]]=='-')
                    {
                        cout<<"harekat be samt chape "<<zamin[sabz[0] - 4][sabz[1]]<<" ya harekat be samt raste "<<zamin[sabz[0] - 4][sabz[1]]
                                <<"?( chape "<<zamin[sabz[0] - 4][sabz[1]]<<" = c , raste "<<zamin[sabz[0] - 4][sabz[1]]<<"  = r ):";
                        char m[0];
                        cin>>m[0];
                        if(m[0]=='r')
                        {
                            if(zamin[sabz[0] - 1][sabz[1] + 1]=='|' || zamin[sabz[0] - 1][sabz[1]]=='-'
                                    ||zamin[sabz[0] - 1][sabz[1] + 1]=='-' || zamin[sabz[0]-4][sabz[1]+2]!='*')
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makanesabz[0]=sabz[0] - 4 ;
                                makanesabz[1]=sabz[1] + 2 ;
                                b=false;
                            }
                        }
                        else if(m[0]=='c')
                        {
                            if(zamin[sabz[0] - 1][sabz[1] - 1]=='|' || zamin[sabz[0] - 1][sabz[1]]=='-'
                                    ||zamin[sabz[0] - 1][sabz[1] - 1]=='-'|| zamin[sabz[0]-4][sabz[1]-2]!='*' )
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makanesabz[0]=sabz[0] - 4 ;
                                makanesabz[1]=sabz[1] - 2 ;
                                b=false;
                            }
                        }
                        else
                        {
                            printeror1(h);
                            continue;
                        }
                    }

                }
                else if(zamin[sabz[0] - 6][sabz[1]]!='*')
                {
                    if(zamin[sabz[0] - 7][sabz[1]]=='-')
                    {
                        cout<<"harekat be samt chape "<<zamin[sabz[0] - 6][sabz[1]]<<" ya harekat be samt raste "<<zamin[sabz[0] - 6][sabz[1]]
                                <<"?( chape "<<zamin[sabz[0] - 6][sabz[1]]<<" = c , raste "<<zamin[sabz[0] - 6][sabz[1]]<<"  = r ):";
                        char m[0];
                        cin>>m[0];
                        if(m[0]=='r')
                        {
                            if(zamin[sabz[0] - 1][sabz[1] + 1]=='|' || zamin[sabz[0] - 1][sabz[1]]=='-'
                                    ||zamin[sabz[0] - 1][sabz[1] + 1]=='-'|| zamin[sabz[0]-6][sabz[1]+2]!='*')
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makanesabz[0]=sabz[0] - 6 ;
                                makanesabz[1]=sabz[1] + 2 ;
                                b=false;
                            }
                        }
                        else if(m[0]=='c')
                        {
                            if(zamin[sabz[0] - 1][sabz[1] - 1]=='|' || zamin[sabz[0] - 1][sabz[1]]=='-'
                                    ||zamin[sabz[0] - 1][sabz[1] - 1]=='-'|| zamin[sabz[0]-6][sabz[1]-2]!='*' )
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makanesabz[0]=sabz[0] - 6 ;
                                makanesabz[1]=sabz[1] - 2 ;
                                b=false;
                            }
                        }
                        else
                        {
                            printeror1(h);
                            continue;
                        }
                    }
                    else
                    {
                        printeror2(h);
                        continue;
                    }
                }
                else
                {
                    printeror2(h);
                    continue;
                }
            }
            else
            {
                printeror2(h);
                continue;
            }
        }
        else
        {
            printeror1(h);
            continue;
        }
    }

}
void harekat2( int sabz[2]  , int makanesabz[2], char zamin[abaad][abaad])
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    char harekat[1];
    bool b=true;
    while (b)
    {
        cout<<zamin[sabz[0]][sabz[1]]<<" harekat baadi mohreh ra vared konid (bala=b , paeen=p, chap=c, rast=r, movarab=m)";
        cin>> harekat[0];

        if(harekat[0]=='b') /////////// بالا
        {
            if(zamin[sabz[0] - 1][sabz[1]]=='-')
            {
                printeror2(h);
                continue;
            }
            else if(zamin[sabz[0] - 2][sabz[1]]!='*')
            {
                if(zamin[sabz[0] - 3][sabz[1]]=='-')
                {

                    printeror2(h);
                    continue;
                }
                else if(zamin[sabz[0] - 4][sabz[1]]!='*')
                {
                    if(zamin[sabz[0] - 5][sabz[1]]=='-')
                    {

                        printeror2(h);
                        continue;
                    }
                    else if(zamin[sabz[0] - 6][sabz[1]]!='*')
                    {
                        if(zamin[sabz[0] - 7][sabz[1]]=='-')
                        {

                            printeror2(h);
                            continue;
                        }
                        else
                        {
                            makanesabz[0]=sabz[0] - 8;
                            makanesabz[1]=sabz[1];
                            b=false;
                        }
                    }
                    else
                    {
                        makanesabz[0]=sabz[0] - 6;
                        makanesabz[1]=sabz[1];
                        b=false;
                    }
                }
                else
                {
                    makanesabz[0]=sabz[0] - 4;
                    makanesabz[1]=sabz[1];
                    b=false;
                }
            }
            else
            {
                makanesabz[0]=sabz[0] - 2;
                makanesabz[1]=sabz[1];
                b=false;
            }
        }
        else if(harekat[0]=='p' ) ////////// پایین
        {
            if(zamin[sabz[0] + 1][sabz[1]]=='-')
            {
                printeror2(h);
                continue;
            }
            else if(zamin[sabz[0] + 2][sabz[1]]!='*')
            {
                if(zamin[sabz[0] + 3][sabz[1]]=='-')
                {

                    printeror2(h);
                    continue;
                }
                else if(zamin[sabz[0] + 4][sabz[1]]!='*')
                {
                    if(zamin[sabz[0] + 5][sabz[1]]=='-')
                    {

                        printeror2(h);
                        continue;
                    }
                    else if(zamin[sabz[0] + 6][sabz[1]]!='*')
                    {
                        if(zamin[sabz[0] + 7][sabz[1]]=='-')
                        {

                            printeror2(h);
                            continue;
                        }
                        else
                        {
                            makanesabz[0]=sabz[0] + 8;
                            makanesabz[1]=sabz[1];
                            b=false;
                        }
                    }
                    else
                    {
                        makanesabz[0]=sabz[0] + 6;
                        makanesabz[1]=sabz[1];
                        b=false;
                    }
                }
                else
                {
                    makanesabz[0]=sabz[0] + 4;
                    makanesabz[1]=sabz[1];
                    b=false;
                }
            }
            else
            {
                makanesabz[0]=sabz[0] + 2;
                makanesabz[1]=sabz[1];
                b=false;
            }
        }
        else if( harekat[0]=='c' ) ////////// چپ
        {

            if(zamin[sabz[0]][sabz[1] - 1]=='|')
            {
                printeror2(h);
                continue;
            }
            else if(zamin[sabz[0]][sabz[1] - 2]!='*')
            {
                if(zamin[sabz[0]][sabz[1] - 3]=='|')
                {

                    printeror2(h);
                    continue;
                }
                else if(zamin[sabz[0]][sabz[1] - 4]!='*')
                {
                    if(zamin[sabz[0]][sabz[1] - 5]=='|')
                    {

                        printeror2(h);
                        continue;
                    }
                    else if(zamin[sabz[0]][sabz[1] - 6]!='*')
                    {
                        if(zamin[sabz[0]][sabz[1] - 7]=='|')
                        {

                            printeror2(h);
                            continue;
                        }
                        else
                        {
                            makanesabz[0]=sabz[0];
                            makanesabz[1]=sabz[1] - 8;
                            b=false;
                        }
                    }
                    else
                    {
                        makanesabz[0]=sabz[0];
                        makanesabz[1]=sabz[1] - 6;
                        b=false;
                    }
                }
                else
                {
                    makanesabz[0]=sabz[0];
                    makanesabz[1]=sabz[1] - 4;
                    b=false;
                }
            }
            else
            {
                makanesabz[0]=sabz[0];
                makanesabz[1]=sabz[1] - 2;
                b=false;
            }
        }
        else if( harekat[0]=='r' ) ///////// راست
        {

            if(zamin[sabz[0]][sabz[1] + 1]=='|')
            {
                printeror2(h);
                continue;
            }
            else if(zamin[sabz[0]][sabz[1] + 2]!='*')
            {
                if(zamin[sabz[0]][sabz[1] + 3]=='|')
                {

                    printeror2(h);
                    continue;
                }
                else if(zamin[sabz[0]][sabz[1] + 4]!='*')
                {
                    if(zamin[sabz[0]][sabz[1] + 5]=='|')
                    {

                        printeror2(h);
                        continue;
                    }
                    else if(zamin[sabz[0]][sabz[1] + 6]!='*')
                    {
                        if(zamin[sabz[0]][sabz[1] + 7]=='|')
                        {

                            printeror2(h);
                            continue;
                        }
                        else
                        {
                            makanesabz[0]=sabz[0];
                            makanesabz[1]=sabz[1] + 8;
                            b=false;
                        }
                    }
                    else
                    {
                        makanesabz[0]=sabz[0];
                        makanesabz[1]=sabz[1] + 6;
                        b=false;
                    }
                }
                else
                {
                    makanesabz[0]=sabz[0];
                    makanesabz[1]=sabz[1] + 4;
                    b=false;
                }
            }
            else
            {
                makanesabz[0]=sabz[0];
                makanesabz[1]=sabz[1] + 2;
                b=false;
            }
        }
        else if(harekat[0]=='m') //////////// مورب
        {
            if( zamin[sabz[0] + 2][sabz[1]]!='*')
            {
                if(zamin[sabz[0] + 3][sabz[1]]=='-')
                {
                    cout<<"harekat be samt chape "<<zamin[sabz[0] + 2][sabz[1]]<<" ya harekat be samt raste "<<zamin[sabz[0] + 2][sabz[1]]
                            <<"?( chape "<<zamin[sabz[0] + 2][sabz[1]]<<" = c , raste "<<zamin[sabz[0] + 2][sabz[1]]<<"  = r ):";
                    char m[0];
                    cin>>m[0];
                    if(m[0]=='r')
                    {
                        if(zamin[sabz[0] + 1][sabz[1] + 1]=='|' || zamin[sabz[0] + 1][sabz[1]]=='-'
                                ||zamin[sabz[0] + 1][sabz[1] + 1]=='-' ||zamin[sabz[0]+2][sabz[1]+2])
                        {
                            printeror2(h);
                            continue;
                        }
                        else
                        {
                            makanesabz[0]=sabz[0] + 2 ;
                            makanesabz[1]=sabz[1] + 2 ;
                            b=false;
                        }
                    }
                    else if(m[0]=='c')
                    {
                        if(zamin[sabz[0] + 1][sabz[1] - 1]=='|' || zamin[sabz[0] + 1][sabz[1]]=='-'
                                ||zamin[sabz[0] + 1][sabz[1] - 1]=='-'||zamin[sabz[0]+2][sabz[1]-2])
                        {
                            printeror2(h);
                            continue;
                        }
                        else
                        {
                            makanesabz[0]=sabz[0] + 2 ;
                            makanesabz[1]=sabz[1] - 2 ;
                            b=false;
                        }
                    }
                    else
                    {
                        printeror1(h);
                        continue;
                    }
                }
                else if(zamin[sabz[0] + 4][sabz[1]]!='*')
                {
                    if(zamin[sabz[0] + 5][sabz[1]]=='-')
                    {
                        cout<<"harekat be samt chape "<<zamin[sabz[0] + 4][sabz[1]]<<" ya harekat be samt raste "<<zamin[sabz[0] + 4][sabz[1]]
                                <<"?( chape "<<zamin[sabz[0] + 4][sabz[1]]<<" = c , raste "<<zamin[sabz[0] + 4][sabz[1]]<<"  = r ):";
                        char m[0];
                        cin>>m[0];
                        if(m[0]=='r')
                        {
                            if(zamin[sabz[0] + 1][sabz[1] + 1]=='|' || zamin[sabz[0] + 1][sabz[1]]=='-'
                                    ||zamin[sabz[0] + 1][sabz[1] + 1]=='-'||zamin[sabz[0]+4][sabz[1]+2])
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makanesabz[0]=sabz[0] + 4 ;
                                makanesabz[1]=sabz[1] + 2 ;
                                b=false;
                            }
                        }
                        else if(m[0]=='c')
                        {
                            if(zamin[sabz[0] + 1][sabz[1] - 1]=='|' || zamin[sabz[0] + 1][sabz[1]]=='-'
                                    ||zamin[sabz[0] + 1][sabz[1] - 1]=='-' ||zamin[sabz[0]+4][sabz[1]-2])
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makanesabz[0]=sabz[0] + 4 ;
                                makanesabz[1]=sabz[1] - 2 ;
                                b=false;
                            }
                        }
                        else
                        {
                            printeror1(h);
                            continue;
                        }
                    }

                }
                else if(zamin[sabz[0] + 6][sabz[1]]!='*')
                {
                    if(zamin[sabz[0] + 7][sabz[1]]=='-')
                    {
                        cout<<"harekat be samt chape "<<zamin[sabz[0] + 6][sabz[1]]<<" ya harekat be samt raste "<<zamin[sabz[0] + 6][sabz[1]]
                                <<"?( chape "<<zamin[sabz[0] + 6][sabz[1]]<<" = c , raste "<<zamin[sabz[0] + 6][sabz[1]]<<"  = r ):";
                        char m[0];
                        cin>>m[0];
                        if(m[0]=='r')
                        {
                            if(zamin[sabz[0] + 1][sabz[1] + 1]=='|' || zamin[sabz[0] + 1][sabz[1]]=='-'
                                    ||zamin[sabz[0] + 1][sabz[1] + 1]=='-'||zamin[sabz[0]+6][sabz[1]+2])
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makanesabz[0]=sabz[0] + 6 ;
                                makanesabz[1]=sabz[1] + 2 ;
                                b=false;
                            }
                        }
                        else if(m[0]=='c')
                        {
                            if(zamin[sabz[0] + 1][sabz[1] - 1]=='|' || zamin[sabz[0] + 1][sabz[1]]=='-'
                                    ||zamin[sabz[0] + 1][sabz[1] - 1]=='-' ||zamin[sabz[0]+6][sabz[1]-2])
                            {
                                printeror2(h);
                                continue;
                            }
                            else
                            {
                                makanesabz[0]=sabz[0] + 6 ;
                                makanesabz[1]=sabz[1] - 2 ;
                                b=false;
                            }
                        }
                        else
                        {
                            printeror1(h);
                            continue;
                        }
                    }
                    else
                    {
                        printeror2(h);
                        continue;
                    }
                }
                else
                {
                    printeror2(h);
                    continue;
                }
            }
            else
            {
                printeror2(h);
                continue;
            }
        }
        else
        {
            printeror1(h);
            continue;
        }
    }

}
