#include<iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void Boardini(int Board[][9])
{
    Board[0][0] = 20;
    Board[1][0] = 19;
    Board[2][0] = 18;
    Board[3][0] = 23;
    Board[4][0] = 24;
    Board[5][0] = 23;
    Board[6][0] = 18;
    Board[7][0] = 19;
    Board[8][0] = 20;
    Board[1][1] = 21;
    Board[7][1] = 22;
    for (int i=0 ;i<9;i++){
        Board[i][2] = 17;
        Board[i][6] = 1;
    }
    Board[1][7] = 6;  //KK
    Board[7][7] = 5;  //HS
    Board[0][8] = 4;  //KS
    Board[1][8] = 3;  //KE
    Board[2][8] = 2;  //Gn
    Board[3][8] = 7;  //Kn
    Board[4][8] = 8;  //Ou
    Board[5][8] = 7;
    Board[6][8] = 2;
    Board[7][8] = 3;
    Board[8][8] = 4;
}

void BoardDisp(int Board[][9],char Koma[][6])
{
    for (int i=0;i<9;i++){
        cout << i<<"    ";
    }
    cout << " "<<endl;
    
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            if (Board[j][i] == 0){
                cout << Koma[14][0]<<Koma[14][1]<<Koma[14][2]<<Koma[14][3]<<Koma[14][4];
            }
            else{
                cout << Koma[Board[j][i]-1][0] ;
                cout << Koma[Board[j][i]-1][1] ;
                cout << Koma[Board[j][i]-1][2] ;
                cout << Koma[Board[j][i]-1][3] ;
                cout << Koma[Board[j][i]-1][4] ;
            }
        }
        cout << i <<endl;
    }
}

bool Check0(int X,int Y,int X2,int Y2,int Player,int Board[][9])
{
    bool FLAG = true;
    if (X<0 || 8<X){
        FLAG = false;
    }
    else if (Y<0 || 8<Y){
        FLAG = false;
    }
    else if (X2<0 || 8<X2){
        FLAG = false;
    }
    else if (Y2<0 || 8<Y2){
        FLAG = false;
    }
    else if (Board[X][Y]<8*Player+8 || 8*Player + 23<Board[X][Y]){
        FLAG = false;
    }

    return FLAG;
}

bool Check1(int X,int Y,int X2,int Y2,int Board[][9],int Player)
{
    bool FLAG = false;
    int delX = X2 - X;
    int delY = Y2 - Y;
    if (Board[X][Y] == 0){
        FLAG = false;
    }

    Board[X][Y] = Board[X][Y] - 8*(Player + 1);

    if (Board[X][Y] == 1){
        if (delX==0 && delY==-1){
            FLAG = true;
        }
    }
    if (Board[X][Y] == 2){
        if (delX==1 && delY==-1){
            FLAG = true;
        }
        else if (delX==0 && delY==-1){
            FLAG = true;
        }
        else if (delX==-1 && delY==-1){
            FLAG = true;
        }        
        else if (delX==-1 && delY==1){
            FLAG = true;
        }
        else if (delX==1 && delY==1){
            FLAG = true;
        }  
    }
    if (Board[X][Y] == 3){
        if (delX==1 && delY==-2){
            FLAG = true;
        }
        else if (delX==-1 && delY==-2){
            FLAG = true;
        }
    }
    if (Board[X][Y] == 4){
        if (delX==0 && delY<0){
            FLAG = true;
        }
    }
    if (Board[X][Y]==7||Board[X][Y]==9||Board[X][Y]==10||Board[X][Y]==11||Board[X][Y]==12){
        if (delX==1 && delY==-1){
            FLAG = true;
        }
        else if (delX==0 && delY==-1){
            FLAG = true;
        }
        else if (delX==-1 && delY==-1){
            FLAG = true;
        }
        else if (delX==-1 && delY==0){
            FLAG = true;
        }  
        else if (delX==1 && delY==0){
            FLAG = true;
        } 
        else if (delX==0 && delY==1){
            FLAG = true;
        }     
    }
    if (Board[X][Y] == 6){
        if (delX == delY)
            FLAG = true;
        else if (delX == -delY){
            FLAG = true;
        }
        if (delX==0 && delY==0){
            FLAG = false;
        }
    }
    if (Board[X][Y] == 5){
        if (delX==0 || delY==0){
            FLAG = true;
        }
        else if (delX==0 && delY==0){
            FLAG = false;
        }
    }
    if (Board[X][Y] == 8){
        
        for (int i=-1;i<2;i++){
            for (int j=-1;j<2;j++){
                if (delX==i && delY==j){
                    FLAG = true;
                }
            }
        }
        if (delX==0 && delY==0){
            FLAG = false;
        }
    }
    if (Board[X][Y] == 13){
        for (int i=-1;i<2;i++){
            for (int j=-1;j<2;j++){
                if (delX==i && delY==j){
                    FLAG = true;
                }
            }
        }
        if (delX==0 || delY==0){
            FLAG = true;
        }
        else if (delX==0 && delY==0){
            FLAG = false;
        }
    }
    if (Board[X][Y] == 14){
        for (int i=-1;i<2;i++){
            for (int j=-1;j<2;j++){
                if (delX==i && delY==j){
                    FLAG = true;
                }
            }
        }
        if (delX == delY)
            FLAG = true;
        else if (delX == -delY){
            FLAG = true;
        }
        if (delX==0 && delY==0){
            FLAG = false;
        }
    }
    
    Board[X][Y] = Board[X][Y] + 8*(Player + 1);
    return FLAG;
}

int Sign(int A)
{
    int B;
    if (A>0){
        B = 1;
    }
    else if (A==0){
        B = 0;
    }
    else if (A<0){
        B = -1;
    }
    return B;
}

bool Check2(int X,int Y,int X2,int Y2,int Board[][9],int Player)
{
    bool FLAG = true;
    int delX = X2 - X;
    int delY = Y2 - Y;
    if (8*Player+8< Board[X2][Y2] && Board[X2][Y2] <8*Player + 23){
        FLAG = false;
    } //自分の駒がある位置には動かせない。
    Board[X][Y] = Board[X][Y] - 8*(Player + 1);
    if (Board[X][Y] == 4){
        for (int i=1;i<-delY;i++){
            if (Board[X][Y-i] != 0){
                FLAG = false;
            }
        }
    }
    if (Board[X][Y] == 6||Board[X][Y]==14){
        int SignX = Sign(delX);
        int SignY = Sign(delY);
        int AbsDel = abs(delX);
        for (int i=1;i<AbsDel;i++){
            if (Board[X+SignX*i][Y+SignY*i] != 0){
                FLAG = false;
            }
        }    
    }
    if (Board[X][Y] == 5||Board[X][Y]==13){
        int SignX = Sign(delX);
        int SignY = Sign(delY);
        int AbsdelX = abs(delX);
        int AbsdelY = abs(delY);
        int AbsDel;
        if (AbsdelX>AbsdelY){
            AbsDel = AbsdelX;
        }
        else if (AbsdelX<AbsdelY){
            AbsDel = AbsdelY;
        }
        for (int i=1;i<AbsDel;i++){
            if (Board[X+SignX*i][Y+SignY*i] != 0){
                FLAG = false;
            }
        }     
    }
    Board[X][Y] = Board[X][Y] + 8*(Player + 1);
    return FLAG;
}

bool checkPro(int X,int Y,int Y2,int Board[][9],int Player)
{
    bool FLAG =false;
    int Koma = Board[X][Y] - 8*(Player + 1);
    if (Koma==1||Koma==2||Koma==3||Koma==4||Koma==5||Koma==6)
        if (Y>2 && Y2 <3){
            FLAG = true;
        }
        else if (Y<3){
           FLAG = true;
        }
    return FLAG;
}

void StockDisp(int Stock[][7],int Player,char Koma[][6])
{
    cout << "Player"<<int(0.5*Player+1.5)<<"  ";
    for (int i=0;i<7;i++){
        for (int j=0;j<4;j++){
            cout << Koma[i + 8*(Player+1)][j];
        }
        cout << "*" << Stock[int(0.5*Player+0.5)][i] << ";   ";
    }
    cout << " " << endl;
}


int main()
{
    char Koma[32][6] = {"Ho   ","GN   ","Ke   ","KS   ","Hi   ","KK   ","Ki   ","Ou   "
                       ,"ToK  ","NGN  ","NKe  ","NKy  ","RyO  ","RyM  ","EMP  ","EMP  "
                       ,"Ho.  ","GN.  ","Ke.  ","KS.  ","Hi.  ","KK.  ","Ki.  ","Ou.  "
                       ,"ToK. ","NGN. ","NKe. ","NKy. ","RyO. ","RyM. ","EMP. ","EMP. "
                       };
    int Board[9][9] = {0};
    int Boardtmp[9][9] = {0};
    int FLAG1 = 1;
    int FLAG2 = 1;
    bool FLAG3 = true;
    bool FLAG4;
    bool FLAG5;
    bool FLAG6;
    int X,Y;
    int X2,Y2;
    int X3,Y3;
    int Player = -1;//-1 or 1
    int ProJ;
    int Stock[2][7]={};
    int SeKoma;


    Boardini(Board);
    StockDisp(Stock,-1*Player,Koma);
    BoardDisp(Board,Koma);
    StockDisp(Stock,Player,Koma);

    while (FLAG1 == 1){
        FLAG2 = 2;
        while (!(FLAG2==0 || FLAG2==1)){
            cout << "Move or Place? move:0, place:1"<<endl;
            cin >> FLAG2;
        }
        while (FLAG2 == 1){
            FLAG2 = 2;
            cout << "Ho=1 Gn=2 Ke=3 Ks=4 Hi=5 KK=6 Ki=7 Cancel=10"<<endl;
            cin >> SeKoma;
            if (SeKoma==10){
                FLAG2=0;
                continue;
            }
            cout << "Please select the Xplace of the Koma to place"<<endl;
            cin >> X3;
            cout << "Please select the Yplace of the Koma to place"<<endl;
            cin >> Y3;
            if (Stock[int(0.5*Player+0.5)][SeKoma-1]==0){
                cout << "You don't have stock." << endl;
                FLAG2 = 1;
            }
            if (!(Board[X3][Y3]==0)&&FLAG2 == 2){
                cout << "Please Select the place one more" << endl;
                FLAG2 = 1;
            }
            if (SeKoma==1){
                for (int i=0;i<8;i++){
                    if (Board[X3][i]==1+8*(Player+1)){
                        FLAG2 = 1;
                    }
                }
            }
            if (FLAG2 == 2){
                Board[X3][Y3] = SeKoma + 8*(Player+1);
            }            
        }
        
        while (FLAG2 == 0){
            FLAG2 = 2;
            FLAG3 = true;
            cout <<"Please select the Xplace of the Koma to move" << endl;
            cin >> X;
            cout <<"Please select the Yplace of the Koma to move" << endl;
            cin >> Y;
            cout <<"Please select the Xplace to go" << endl;
            cin >> X2;
            cout <<"Please select the Yplace to go" << endl;
            cin >> Y2;

            FLAG3 = Check0(X,Y,X2,Y2,Player,Board);
            if (FLAG3 == false){
                cout << "Please one more"<<endl;
                FLAG2 = 0;
            }
            FLAG4 = Check1(X,Y,X2,Y2,Board,Player);
            if (FLAG4 == false){
                cout << "Please one more2"<<endl;
                FLAG2 = 0;
            }
            FLAG5 = Check2(X,Y,X2,Y2,Board,Player);
            if (FLAG5 == false){
                cout << "Please one more3"<<endl;
                FLAG2 = 0;
            }
            if (FLAG2 == 2 && Board[X2][Y2] == 8*(Player+1)+8){
                cout << "Player"<<int(0.5*Player+1.5)<<"won !";
                FLAG1 = 0;
            }
            FLAG6 = checkPro(X,Y,Y2,Board,Player);
            if (FLAG6 == true){
                cout << "Do you promote your Koma? if yes:1 no:2"<<endl;;
                cin >> ProJ;
                if (ProJ == 1){
                    Board[X][Y] = Board[X][Y] + 8;
                }
            }
            if (8*(-1*Player+1)<Board[X2][Y2] && Board[X2][Y2]<8*(-1*Player+1)+15){
                Stock[int(0.5*Player+0.5)][Board[X2][Y2]%8-1] = Stock[int(0.5*Player+0.5)][Board[X2][Y2]%8-1] + 1;
            }
            Board[X2][Y2] = Board[X][Y];
            Board[X][Y] = 0;
        }
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                Boardtmp[i][j] = Board[i][j];
            }
        }
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                Board[i][j] = Boardtmp[8-i][8-j];
            }
        }
        StockDisp(Stock,Player,Koma);
        BoardDisp(Board,Koma);
        StockDisp(Stock,-1*Player,Koma);
        
        Player = -1*Player;
    }

    return 0;
}