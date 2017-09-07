/************************************
 *  Ekon LPlus 2013 - 2016          *
 *  Version 1.6.0508                *
 *  EN/RO Version                 *
 *  Moldovan Catalin	            *
 ************************************/
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<windows.h>
#include<ctime>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<ctime>
HANDLE  hConsole;
char version[]="1.6.0508"; //Date: 08.05.2016
char v[1000][1000],a[1000][1000],p[1000][1000],ch,nume1[100],parola1[100],nume3[100][100],parola3[100][100],semn[100]; //REGISTER/LOGIN
long i=1,j,k,l=1,stn[1000],stm[1000],eroare=0,stop=0,joc,exemplu[1000],iesi=1000,nn,mm,matr=0,nul=0,locscor=0;
long num=0,par=0,reset=0,minte=0,seadaugabani=0,primibani=0,baniinainte=0,premium=1,nrcont,contnr=0; //Score Table + Adaugare Bani
long nor[1000][1000], numar, pa=0,sfarsit=0,ka[1000], mutare,nra,total=0,retin=0,bloc[1000],stdr,alegere[1000],stabilit,lamp,stalon=0,nivel=1; //Maze Game
long long ks=10000,bani3[100],banutijoc=0; //Bani
int blocat=0;
int inreglog;
int m1,m2,yes; //Create Maze Table
int salvare[100]; //Saves
char denum[100];
int previousgame=0;
int varn,varm,varstalpi,varchei;
int anulat=0; //Discard Map
char lang[1000][1000],enlang[1000][1000],rolang[1000][1000];
int limba=1, liniilang; //Language
using namespace std;
ifstream fin("logare.in");
ifstream en("lang(en).txt");
ifstream ro("lang(ro).txt");
/*
void resetare()
void log()
void logare()
void inregistrare()
void inceput()
void banutiinceput(int banutiinceput)
void meniu(int k)
void scor()
void desen(int n,int m)
void retinere(int rt[1000],int he)
void statistica(int linia,int coloana,int n,int m,int total,int stalpi2,int nr,int nrchei,int usas)
void creeazaharta()
void loading(int o)
void incepeunjocaleatoriu()
void instructiuni2(int o)
void Instructiuni2(int o)
void calculator()
void Instructiuni()
void instructiuni()
void estisigur(int k)
void iesire()
void next()
void decizie()
void afisare(int k, int l)
void thrown()
void inregistraresaulogare2(int o)
void inregistraresaulogare()
int main()
*/
void resetare()
{
    ofstream fout("logare.in");
    for(i=0; i<=reset-2; ++i)
    {
        fout<<nume3[i]<<'\n';
        fout<<parola3[i]<<'\n';
        fout<<bani3[i]<<'\n';
    }
    if(inreglog==1)
    {
        fout<<nume1<<'\n';
        fout<<parola1<<'\n';
        fout<<"0"<<'\n';
    }
    fout<<"-";
}
void log()
{
    char nume[100],parola[100];
    long long bani;
    fin.get(nume,100);
    fin.get();
    fin.get(parola,100);
    fin.get();
    fin>>bani;
    fin.get();
    strcpy(nume3[reset],nume);
    strcpy(parola3[reset],parola);
    bani3[reset]=bani;
    reset++;
    if(strcmp(nume1,nume)==0)
        num++;
    if(strcmp(parola1,parola)==0)
        par++;
    if(contnr==0)
        nrcont++;
    if(strcmp(nume1,nume)==0 && strcmp(parola1,parola)==0)
        contnr=1;
    if(blocat==0)
        if(num==1 && par==1)
        {
            minte=reset-1;
            blocat=1;
        }
    if(nume[0]=='-')
        nul=1;
    strcpy(semn,nume);
}
void logare()
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int i=0,j=0,k=0,n=1;
    char a;
    system("cls");
    SetConsoleTextAttribute(hConsole, 7);
    cout<<'\n'<<"   --";
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"+"<<'\n';
    SetConsoleTextAttribute(hConsole, 7);
    cout<<"   |";
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"El";
    SetConsoleTextAttribute(hConsole, 7);
    cout<<""<<'\n'<<"   ---"<<'\n';
    for(j=1; j<=4; ++j)
        cout<<'\n';
    SetConsoleTextAttribute(hConsole, 3);
    cout<<"                                      "<<lang[1]<<'\n'<<'\n'<<'\n';
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"                           "<<lang[2]<<": ";
    SetConsoleTextAttribute(hConsole, 15);
    cin>>nume1;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<'\n'<<"                           "<<lang[3]<<": ";
    SetConsoleTextAttribute(hConsole, 15);
    for(i=0;;)
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            parola1[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            parola1[i]='\0';
            break;
        }
    }
    for(i=1; i<=n; i++)
    {
        log();
        resetare();
        if(semn[0]!='-')
            n++;
    }
    Sleep(400);
}
void inregistrare()
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int i=0,j=0,k=0,n=1;
    char a;
    SetConsoleTextAttribute(hConsole, 7);
    system("cls");
    cout<<'\n'<<"   --";
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"+"<<'\n';
    SetConsoleTextAttribute(hConsole, 7);
    cout<<"   |";
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"El";
    SetConsoleTextAttribute(hConsole, 7);
    cout<<""<<'\n'<<"   ---"<<'\n';
    for(j=1; j<=4; ++j)
        cout<<'\n';
    SetConsoleTextAttribute(hConsole, 3);
    cout<<"                                     "<<lang[4]<<'\n'<<'\n'<<'\n';
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"                           "<<lang[2]<<": ";
    SetConsoleTextAttribute(hConsole, 15);
    cin>>nume1;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<'\n'<<"                           "<<lang[3]<<": ";
    SetConsoleTextAttribute(hConsole, 15);
    for(i=0;;)
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            parola1[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            parola1[i]='\0';
            break;
        }
    }
    for(i=1; i<=n; i++)
    {
        log();
        resetare();
        if(semn[0]!='-')
            n++;
    }
    SetConsoleTextAttribute(hConsole, 10);
    cout<<'\n'<<'\n'<<'\n'<<"                            "<<lang[5];
    Sleep(700);
    system("cls");

}
void inceput()
{
    int i=1,n=1,k=0;
    ifstream fin("salvari.in");
    salvare[i]=100;
    while(i!=4)
    {
        fin>>salvare[i];
        i++;
    }
    i--;
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for(j=1; j<=100; ++j)
    {
        system("cls");
        if(n>5)
        {
            k++;
            for(i=1; i<=k; ++i)
                cout<<'\n';
        }
        SetConsoleTextAttribute(hConsole, 12);
        if(n>4)
            cout<<"                           "<<(char) 219<<(char) 219<<(char) 219<<(char) 219<<"  "<<(char) 219<<"  "<<(char) 219<<"   "<<(char) 219<<(char) 219<<"   "<<(char) 219<<"   "<<(char) 219<<'\n';
        if(n>3)
        {
            cout<<"                           "<<(char) 219<<"     "<<(char) 219<<" "<<(char) 219<<"   "<<(char) 219<<"  "<<(char) 219<<"  "<<(char) 219<<(char) 219<<"  "<<(char) 219;
            cout<<"   "<<(char) 219<<'\n';
        }
        if(n>2)
        {
            cout<<"                           "<<(char) 219<<(char) 219<<(char) 219<<(char) 219<<"  "<<(char) 219<<(char) 219<<"    "<<(char) 219<<"  "<<(char) 219<<"  "<<(char) 219<<" "<<(char) 219<<" "<<(char) 219;
            cout<<"  "<<(char) 219<<(char) 219<<(char) 219<<'\n';
        }
        if(n>1)
        {
            cout<<"                           "<<(char) 219<<"     "<<(char) 219<<" "<<(char) 219<<"   "<<(char) 219<<"  "<<(char) 219<<"  "<<(char) 219<<"  "<<(char) 219<<(char) 219;
            cout<<"   "<<(char) 219<<'\n';
        }
        cout<<"                           "<<(char) 219<<(char) 219<<(char) 219<<(char) 219<<"  "<<(char) 219<<"  "<<(char) 219<<"   "<<(char) 219<<(char) 219<<"   "<<(char) 219<<"   "<<(char) 219<<'\n';
        if(n!=13)
            n++;
        else
            break;
        Sleep(20);
    }
    SetConsoleTextAttribute(hConsole, 11);
    cout<<'\n'<<'\n';
    cout<<"                                 2013 - 2016";
    cout<<'\n'<<'\n';
    cout<<"                 ";
    SetConsoleTextAttribute(hConsole, 240);
    cout<<"                                          "<<'\n';
    SetConsoleTextAttribute(hConsole, 11);
    cout<<"                 ";
    SetConsoleTextAttribute(hConsole, 240);
    cout<<"             "<<lang[6]<<" "<<version<<"            "<<'\n';
    SetConsoleTextAttribute(hConsole, 11);
    cout<<"                 ";
    SetConsoleTextAttribute(hConsole, 240);
    cout<<"                                          ";
    Sleep(1000);
}
void banutiinceput(int banutiinceput)
{
    if(banutiinceput==1)
        banutijoc=bani3[minte];
    else
    {
        bani3[minte]=banutijoc;
        resetare();
    }
}
void meniu(int k)
{
    int talon,n=1;
    for(talon=1; talon<=n; talon++)
    {
        if(seadaugabani>1)
            Sleep(1000);
        HANDLE  hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 7);
        system("cls");
        cout<<'\n'<<'\n'<<"                                   ";
        cout<<"   --";
        SetConsoleTextAttribute(hConsole, 12);
        cout<<"+"<<'\n';
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"                                      |";
        SetConsoleTextAttribute(hConsole, 12);
        cout<<"El";
        SetConsoleTextAttribute(hConsole, 7);
        cout<<""<<'\n'<<"                                      ---"<<'\n';
        SetConsoleTextAttribute(hConsole, 12);
        cout<<"                                   E";
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"kon ";
        SetConsoleTextAttribute(hConsole, 12);
        cout<<"LP";
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"lus";
        cout<<'\n';
        SetConsoleTextAttribute(hConsole, 12);
        cout<<"                                 -------------";
        SetConsoleTextAttribute(hConsole, 10);
        cout<<'\n'<<"-/---------------/-"<<'\n';
        SetConsoleTextAttribute(hConsole, 15);
        if(k==1)
        {
            SetConsoleTextAttribute(hConsole, 3);
            cout<<"                                >> "<<lang[7]<<" <<";
            /*SetConsoleTextAttribute(hConsole, 12);
            cout<<"  - build a maze";*/
        }
        else
            cout<<"                                   "<<lang[7];
        SetConsoleTextAttribute(hConsole, 12);
        cout<<'\n'<<"   "<<nume1;
        cout<<'\n';
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"  "<<lang[8]<<":";
        SetConsoleTextAttribute(hConsole, 14);
        int basc;
        if(seadaugabani==2)
        {
            banutijoc=basc;
            seadaugabani=0;
        }
        if(seadaugabani==1)
        {
            basc=banutijoc;
            banutijoc=primibani;
        }
        if(banutijoc<10)
            cout<<"      "<<banutijoc;
        else if(banutijoc<100)
            cout<<"     "<<banutijoc;
        else if(banutijoc<1000)
            cout<<"    "<<banutijoc;
        else if(banutijoc<10000)
            cout<<"   "<<banutijoc;
        else if(banutijoc<100000)
            cout<<"  "<<banutijoc;
        else if(banutijoc<1000000)
            cout<<" "<<banutijoc;
        else
            cout<<banutijoc;
        cout<<"           ";
        SetConsoleTextAttribute(hConsole, 15);
        if(k==2)
        {
            SetConsoleTextAttribute(hConsole, 3);
            cout<<"    >> "<<lang[9]<<" <<";
            /*SetConsoleTextAttribute(hConsole, 12);
            cout<<"  - escape from the maze";*/
        }
        else
            cout<<"       "<<lang[9];
        SetConsoleTextAttribute(hConsole, 13);
        cout<<'\n';
        if(seadaugabani==1)
        {
            cout<<"         ";
            if(baniinainte<10)
                cout<<"+      "<<baniinainte;
            else if(baniinainte<100)
                cout<<"+     "<<baniinainte;
            else if(baniinainte<1000)
                cout<<"+    "<<baniinainte;
            else if(baniinainte<10000)
                cout<<"+   "<<baniinainte;
            else if(baniinainte<100000)
                cout<<"+  "<<baniinainte;
            else if(baniinainte<1000000)
                cout<<"+ "<<baniinainte;
            else
                cout<<"+"<<baniinainte;
            seadaugabani=2;
            n++;
        }
        SetConsoleTextAttribute(hConsole, 15);
        cout<<'\n';
        if(k==3)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout<<"-/---------------/-";
            SetConsoleTextAttribute(hConsole, 3);
            cout<<"            >> "<<lang[10]<<" <<";
            /*SetConsoleTextAttribute(hConsole, 12);
            cout<<"  - just jump and jump";*/
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout<<"-/---------------/-";
            SetConsoleTextAttribute(hConsole, 15);
            cout<<"               "<<lang[10];
        }
        cout<<'\n';
        if(k==8)
        {
            SetConsoleTextAttribute(hConsole, 3);
            cout<<"   >> "<<lang[11]<<" <<";
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 6);
            cout<<"      "<<lang[11];
        }
        cout<<'\n';
        SetConsoleTextAttribute(hConsole, 15);
        if(k==4)
        {
            SetConsoleTextAttribute(hConsole, 3);
            cout<<"                               >> "<<lang[12]<<" <<";
        }
        else
            cout<<"                                  "<<lang[12];
        cout<<'\n'<<'\n';
        SetConsoleTextAttribute(hConsole, 15);
        if(k==5)
        {
            SetConsoleTextAttribute(hConsole, 3);
            cout<<"                                 >> "<<lang[13]<<" <<";
        }
        else
            cout<<"                                    "<<lang[13];
        cout<<'\n'<<'\n';
        SetConsoleTextAttribute(hConsole, 15);
        if(k==6)
        {
            SetConsoleTextAttribute(hConsole, 3);
            cout<<"                                  >> "<<lang[14]<<" <<";
        }
        else
            cout<<"                                     "<<lang[14];
        SetConsoleTextAttribute(hConsole, 15);
        cout<<'\n';
        SetConsoleTextAttribute(hConsole, 7);
        cout<<'\n';
        cout<<" "<<lang[6]<<" "<<version<<'\n'<<'\n';
        cout<<" "<<lang[119]<<" #"<<nrcont;
        cout<<"                                                ";
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"® Moldovan Catalin   "<<'\n';
        SetConsoleTextAttribute(hConsole, 7);
        //cout<<" "<<(char) 006<<" Ekon LPlus 2013 - 2016                                             ";
        cout<<" Ekon LPlus+ 2013 - 2016                                              ";
        SetConsoleTextAttribute(hConsole, 15);
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );
        cout<<  now->tm_mday<<'/';
        cout<< (now->tm_mon + 1) << '/';
        cout << (now->tm_year + 1900);
        cout<<'\n';
    }
}
void scor()
{
    int pluss=0,sector=0,pune=0,lesa=0,scoruri=1,coca=0,scrola;
    long long infinit=0,bani4[100];
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    for(i=0; i<=reset-2; ++i)
        bani4[i]=bani3[i];
    cout<<'\n';
    SetConsoleTextAttribute(hConsole, 10);
    cout<<"                                   "<<lang[12];
    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n'<<'\n';
    for(i=0; i<=reset-2; ++i)
    {
        infinit=0;
        for(j=0; j<=reset-2; ++j)
        {
            if(bani4[j]>=infinit)
            {
                infinit=bani4[j];
                lesa=j;
            }
        }
        scoruri++;
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"                              ";
        for(int k=1; k<=21; k++)
            cout<<(char) 205;
        cout<<'\n';
        pune=0;
        if(strcmp(nume1,nume3[lesa])==0)
            SetConsoleTextAttribute(hConsole, 12);
        else
            SetConsoleTextAttribute(hConsole, 3);
        cout<<"                              ";
        cout<<nume3[lesa];
        SetConsoleTextAttribute(hConsole, 15);
        for(j=1; j<=10-strlen(nume3[lesa]); ++j)
            cout<<" ";
        cout<<(char) 186;
        SetConsoleTextAttribute(hConsole, 14);
        if(bani3[lesa]==0)
            pune++;
        sector=bani3[lesa];
        while(sector!=0)
        {
            sector=sector/10;
            pune++;
        }
        for(j=1; j<=8-pune; ++j)
            cout<<" ";
        if(strcmp(nume1,nume3[lesa])==0)
        {
            SetConsoleTextAttribute(hConsole, 12);
            if(locscor>(scoruri-1))
            {
                scrola=locscor-(scoruri-1);
                coca=1;
            }
            locscor=scoruri-1;
        }
        cout<<"  "<<bani3[lesa]<<'\n';
        bani4[lesa]=-1;
    }
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"                              ";
    for(int k=1; k<=21; k++)
        cout<<(char) 205;
    cout<<'\n'<<'\n';
    cout<<"                    "<<lang[15]<<" "<<locscor<<" "<<lang[16]<<" "<<scoruri-1<<" "<<lang[17];

    cout<<'\n'<<'\n';
    if(coca==1)
    {
        SetConsoleTextAttribute(hConsole, 12);
        cout<<"                            "<<lang[18]<<" "<<scrola;
        if(scrola<2)
            cout<<" "<<lang[19];
        else
            cout<<" "<<lang[20];
    }
    cout<<'\n';
    SetConsoleTextAttribute(hConsole, 3);
    cout<<"   <- "<<lang[21];
    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n';
    int valu=500;
    for(i=1; i<=valu; ++i)
    {
        ch=getch();
        if(ch=='\r')
            valu=1;
        else
            valu++;
    }
    system("cls");
    meniu(0);
}
void lottodesen(int nrl[100][100],int ales,int markeaza[10],int ins,int stop,int baniintrare,int random[100])
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int lp=1;
    cout<<'\n'<<'\n'<<"                             ";
    if(stop==0)
        SetConsoleTextAttribute(hConsole, 15);
    else
        SetConsoleTextAttribute(hConsole, 8);
    for(int i=1; i<=4; ++i)
    {
        for(int j=1; j<=8; ++j)
        {
            if(nrl[i][j]!=0)
            {
                if(nrl[i][j]<10)
                    cout<<" ";
                for(int st=1; st<ins; ++st)
                    if(markeaza[st]==nrl[i][j])
                        SetConsoleTextAttribute(hConsole, 12);
                if(ales==nrl[i][j])
                {
                    SetConsoleTextAttribute(hConsole, 240);
                    for(int st=1; st<ins; ++st)
                        if(markeaza[st]==ales)
                            SetConsoleTextAttribute(hConsole, 192);
                    if(stop==2 || stop==3)
                        SetConsoleTextAttribute(hConsole, 12);
                }
                if(stop==3)
                {
                    for(int pot=1; pot<=ins-1; ++pot)
                        for(int por=1; por<=ins-1; ++por)
                            if(random[por]==markeaza[pot] && markeaza[pot]==nrl[i][j])
                                SetConsoleTextAttribute(hConsole, 14);
                }
                cout<<nrl[i][j];
                if(stop==0)
                    SetConsoleTextAttribute(hConsole, 15);
                else
                    SetConsoleTextAttribute(hConsole, 8);
                cout<<" ";
            }
        }
        cout<<'\n'<<'\n'<<"                             ";
    }
    SetConsoleTextAttribute(hConsole, 15);
    if(stop==0 || stop==2 || stop==3)
    {
        SetConsoleTextAttribute(hConsole, 15);
        cout<<'\n'<<"  "<<lang[116]<<": ";
        SetConsoleTextAttribute(hConsole, 12);
        cout<<nume1<<'\n';
        SetConsoleTextAttribute(hConsole, 15);
        cout<<'\n'<<"  "<<lang[22]<<":";
        SetConsoleTextAttribute(hConsole, 14);
        if(banutijoc<10)
            cout<<"      "<<banutijoc;
        else if(banutijoc<100)
            cout<<"     "<<banutijoc;
        else if(banutijoc<1000)
            cout<<"    "<<banutijoc;
        else if(banutijoc<10000)
            cout<<"   "<<banutijoc;
        else if(banutijoc<100000)
            cout<<"  "<<banutijoc;
        else if(banutijoc<1000000)
            cout<<" "<<banutijoc;
        else
            cout<<banutijoc;
        cout<<'\n';
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"                                           "<<lang[23];
        cout<<'\n'<<"  "<<lang[24]<<":";
        SetConsoleTextAttribute(hConsole, 14);
        if(baniintrare<10)
            cout<<"      "<<baniintrare;
        else if(baniintrare<100)
            cout<<"     "<<baniintrare;
        else if(baniintrare<1000)
            cout<<"    "<<baniintrare;
        else if(baniintrare<10000)
            cout<<"   "<<baniintrare;
        else if(baniintrare<100000)
            cout<<"  "<<baniintrare;
        else if(baniintrare<1000000)
            cout<<" "<<baniintrare;
        else
            cout<<baniintrare;
        cout<<'\n';


        SetConsoleTextAttribute(hConsole, 15);
        cout<<"                                                               ^";
        cout<<'\n'<<"  "<<lang[25]<<": ";
        SetConsoleTextAttribute(hConsole, 10);
        cout<<ins-1      <<"/5";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"                                      "<<lang[26]<<" <   > "<<'\n';
        cout<<"                                                               v";
        cout<<'\n'<<"  "<<lang[27]<<": ";
        SetConsoleTextAttribute(hConsole, 12);
        for(int i=1; i<ins; ++i)
        {
            if(markeaza[i]<10)
                cout<<" ";
            cout<<markeaza[i]<<" ";
        }
    }
}
void lotto()
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    int nrl[100][100],numerotare=1,ales,markeaza[100],ins=1,ups=0,linia=1,coloana=1,gresit,random[100];
    for(int i=1; i<=4; ++i)
        for(int j=1; j<=8; ++j)
        {
            if(numerotare<=30)
            {
                nrl[i][j]=numerotare;
                numerotare++;
            }
        }
    int k=1000,stop=1,baniintrare;
    int pst=0;
    for(int i=1; i<=1000; ++i)
    {
        system("cls");
        lottodesen(nrl,ales,markeaza,ins,stop,baniintrare,random);
        SetConsoleTextAttribute(hConsole, 15);
        cout<<'\n'<<"  "<<lang[116]<<": ";
        SetConsoleTextAttribute(hConsole, 12);
        cout<<nume1<<'\n';
        SetConsoleTextAttribute(hConsole, 15);
        cout<<'\n'<<"  "<<lang[22]<<":";
        SetConsoleTextAttribute(hConsole, 14);
        if(banutijoc<10)
            cout<<"      "<<banutijoc;
        else if(banutijoc<100)
            cout<<"     "<<banutijoc;
        else if(banutijoc<1000)
            cout<<"    "<<banutijoc;
        else if(banutijoc<10000)
            cout<<"   "<<banutijoc;
        else if(banutijoc<100000)
            cout<<"  "<<banutijoc;
        else if(banutijoc<1000000)
            cout<<" "<<banutijoc;
        else
            cout<<banutijoc;
        cout<<'\n';
        if(pst==1)
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"                   "<<lang[41];
            pst=0;
        }
        SetConsoleTextAttribute(hConsole, 15);
        cout<<'\n'<<"  "<<lang[24]<<":";
        SetConsoleTextAttribute(hConsole, 14);
        cin>>baniintrare;
        if(baniintrare<=banutijoc)
            break;
        else
            pst=1;
    }

    system("cls");
    lottodesen(nrl,ales,markeaza,ins,stop,baniintrare,random);
    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n'<<"  "<<lang[116]<<": ";
    SetConsoleTextAttribute(hConsole, 12);
    cout<<nume1<<'\n';
    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n'<<"  "<<lang[22]<<":";
    SetConsoleTextAttribute(hConsole, 14);
    if(banutijoc<10)
        cout<<"      "<<banutijoc;
    else if(banutijoc<100)
        cout<<"     "<<banutijoc;
    else if(banutijoc<1000)
        cout<<"    "<<banutijoc;
    else if(banutijoc<10000)
        cout<<"   "<<banutijoc;
    else if(banutijoc<100000)
        cout<<"  "<<banutijoc;
    else if(banutijoc<1000000)
        cout<<" "<<banutijoc;
    else
        cout<<banutijoc;
    cout<<'\n';
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"       ";
    if(baniintrare<10)
        cout<<"-      "<<baniintrare;
    else if(baniintrare<100)
        cout<<"-     "<<baniintrare;
    else if(baniintrare<1000)
        cout<<"-    "<<baniintrare;
    else if(baniintrare<10000)
        cout<<"-   "<<baniintrare;
    else if(baniintrare<100000)
        cout<<"-  "<<baniintrare;
    else if(baniintrare<1000000)
        cout<<"- "<<baniintrare;
    else
        cout<<"-"<<baniintrare;
    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n'<<"  "<<lang[24]<<":";
    SetConsoleTextAttribute(hConsole, 14);
    cout<<baniintrare;
    banutijoc=banutijoc-baniintrare;
    Sleep(500);

    ales=1;
    stop=0;
    int art=1,incheiere=0;
    for(int k=1; k<=ks; ++k)
    {
        system("cls");
        lottodesen(nrl,ales,markeaza,ins,stop,baniintrare,random);
        if(incheiere==1)
        {
            stop=3;
            system("cls");
            lottodesen(nrl,ales,markeaza,ins,stop,baniintrare,random);
            break;
        }
        ups=0;
        ch=getch();
        if(ch=='\r') //ENTER
        {
            gresit=0;
            for(int st=1; st<ins; ++st)
                if(ales==markeaza[st])
                    gresit=1;
            if(gresit==0)
            {
                markeaza[ins]=ales;
                ins++;
                srand (time(NULL));
                random[art] = rand() % 30 + 1;
                art++;
            }
        }

        if(ch!='\0')
        {
            ch=getch();
            if(ch=='H' && nrl[linia-1][coloana]!=NULL) //SUS
            {
                linia=linia-1;
                ales=nrl[linia][coloana];
            }
            else if(ch=='K' && nrl[linia][coloana-1]!=NULL) //STANGA
            {
                coloana=coloana-1;
                ales=nrl[linia][coloana];
            }
            else if(ch=='P' && nrl[linia+1][coloana]!=NULL) //JOS
            {
                linia=linia+1;
                ales=nrl[linia][coloana];
            }
            else if(ch=='M' && nrl[linia][coloana+1]!=NULL) //DREAPTA
            {
                coloana=coloana+1;
                ales=nrl[linia][coloana];
            }
            else
                ups=1;
        }

        if(ins>5)
        {
            stop=2;
            incheiere=1;
        }
    }
    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n'<<'\n'<<"  "<<lang[28]<<": ";
    SetConsoleTextAttribute(hConsole, 12);
    for(int i=1; i<art; ++i)
    {
        if(random[i]<10)
            cout<<" ";
        cout<<random[i]<<" ";
        Sleep(150);
    }
    float amplificare=1;
    int ok=0;

    for(int pot=1; pot<ins; ++pot)
        for(int por=1; por<=art; ++por)
            if(random[por]==markeaza[pot])
                amplificare++;
    if(amplificare==1)
        amplificare=0;
    if(amplificare==2)
        amplificare=1.4;
    if(amplificare==3)
        amplificare=1.7;
    if(amplificare==4)
        amplificare=2.1;
    if(amplificare==5)
        amplificare=2.5;
    if(amplificare==6)
        amplificare=3.2;

    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n'<<'\n'<<"  "<<lang[29]<<": ";
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"x"<<amplificare;
    SetConsoleTextAttribute(hConsole, 14);
    int intreg;
    intreg=baniintrare*amplificare;
    cout<<" (+"<<intreg<<")";
    primibani=banutijoc;
    banutijoc=banutijoc+(baniintrare*amplificare);
    baniinainte=baniintrare*amplificare;
    banutiinceput(2);
    if(amplificare>1)
        seadaugabani=1;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<'\n'<<"                          <--         "<<lang[30]<<"            -->";
}
void desen(int n,int m)
{
    int i;
    cout<<"  | ";
    for(i=1; i<=m; i++)
        cout<<i<<' ';
    cout<<'\n';

    for(i=1; i<=2*m+3; i++)
        cout<<'-';
    cout<<"            ";
    cout<<(char) 201;
    for(i=1; i<=(2*m+3-2)/2; i++)
        cout<<(char) 205;
    cout<<(char) 187;
    cout<<'\n';

    for(i=1; i<=n; i++)
    {
        cout<<i<<" |";
        for(j=1; j<=m; ++j)
            if(v[i][j])
                cout<<" "<<v[i][j];

        cout<<"            ";
        cout<<(char) 186;
        for(j=1; j<=m; ++j)
        {
            if(v[i][j]=='X')
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout<<(char) 254;
                SetConsoleTextAttribute(hConsole, 15);
            }
            else if(v[i][j]==' ')
                cout<<' ';
            else if(v[i][j]=='M')
                cout<<(char) 219;
            else if(v[i][j]=='@')
            {
                SetConsoleTextAttribute(hConsole, 14);
                cout<<(char) 239;
                SetConsoleTextAttribute(hConsole, 15);
            }
            else if(v[i][j]=='0')
                cout<<(char) 176;
            else
            {
                SetConsoleTextAttribute(hConsole, 11);
                cout<<v[i][j];
                SetConsoleTextAttribute(hConsole, 15);
            }
        }
        cout<<(char) 186;
        cout<<'\n';
    }
    for(i=1; i<=3+(2*m); ++i)
        cout<<" ";
    cout<<"            ";
    cout<<(char) 200;
    for(i=1; i<=(2*m+3-2)/2; i++)
        cout<<(char) 205;
    cout<<(char) 188;
    cout<<'\n';
    l++;
}
void retinere(int rt[1000],int he,int stalpi,int nrchei)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char denumire[100];
    system("cls");
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"-/----------------------------------------/-"<<'\n'<<'\n';
    SetConsoleTextAttribute(hConsole, 15);
    desen(varn,varm);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"-/----------------------------------------/-"<<'\n'<<'\n';
    SetConsoleTextAttribute(hConsole, 15);
    int decid;
    int sup;
    ofstream fout("memorat.out");
    for(int k=1; k<he; ++k)
        fout<<rt[k]<<'\n';
    cout<<"                  "<<lang[31]<<'\n';
    cout<<"                                   "<<lang[32]<<"    '1' / '2' / '3' - "<<lang[33]<<'\n'<<'\n';
    cout<<"                                   '0' - "<<lang[34]<<" / '10' - "<<lang[35]<<'\n'<<'\n';
    cout<<"                  "<<lang[36]<<": ";
    cin>>decid;
    cout<<'\n';
    if(decid==1 || decid==2 || decid==3)
        cout<<"                                   "<<lang[37];
    if(decid==10)
        cout<<"                                   "<<lang[38];
    if(decid==0)
        cout<<"                                   "<<lang[39];
    if(decid==1)
    {
        ofstream ful1("Folder1.in");
        ofstream Space1("Space1.in");
        for(int k=1; k<he; ++k)
            ful1<<rt[k]<<'\n';
        cout<<lang[75]<<" 1";
        cout<<'\n'<<'\n';
        cout<<"          "<<lang[40]<<": #";
        cin>>denumire;
        Space1<<denumire<<endl<<nume1<<endl<<varn<<endl<<varm<<endl<<stalpi<<endl<<nrchei;
    }
    if(decid==2)
    {
        ofstream ful2("Folder2.in");
        ofstream Space2("Space2.in");
        for(int k=1; k<he; ++k)
            ful2<<rt[k]<<'\n';
        cout<<lang[75]<<" 2";
        cout<<'\n'<<'\n';
        cout<<"          "<<lang[40]<<": #";
        cin>>denumire;
        Space2<<denumire<<endl<<nume1<<endl<<varn<<endl<<varm<<endl<<stalpi<<endl<<nrchei;;
    }
    if(decid==3)
    {
        ofstream ful3("Folder3.in");
        ofstream Space3("Space3.in");
        for(int k=1; k<he; ++k)
            ful3<<rt[k]<<'\n';
        cout<<lang[75]<<" 3";
        cout<<'\n'<<'\n';
        cout<<"          "<<lang[40]<<": #";
        cin>>denumire;
        Space3<<denumire<<endl<<nume1<<endl<<varn<<endl<<varm<<endl<<stalpi<<endl<<nrchei;;
    }
    if(decid==10)
        anulat=1;
    fout.close();
}
void statistica(int linia,int coloana,int n,int m,int total,int stalpi2,int nr,int nrchei,int usas)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"-/----------------------------------------/-";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n';
    if(yes==1)
    {
        if(eroare==1)
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"                          "<<lang[41]<<" X("<<m1<<") Y("<<m2<<")";
            SetConsoleTextAttribute(hConsole, 15);
            eroare=0;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout<<"                                X("<<m1<<") Y("<<m2<<")";
            SetConsoleTextAttribute(hConsole, 15);
        }
    }
    cout<<'\n';
    if(n==0)
        cout<<"       "<<lang[42]<<": -/-"<<'\n';
    else
        cout<<"       "<<lang[42]<<": "<<n<<"/"<<m<<'\n';
    if(linia==0)
        cout<<"     "<<lang[43]<<": X(-) Y(-)"<<'\n';
    else
        cout<<"     "<<lang[43]<<": X("<<linia<<") Y("<<coloana<<")"<<'\n';
    cout<<"            "<<lang[44]<<": "<<total<<"/"<<m*n<<'\n';
    cout<<"             "<<lang[45]<<": "<<stalpi2<<'\n';
    cout<<"              "<<lang[117]<<": "<<nr<<"/"<<nrchei<<'\n';
    cout<<"              "<<lang[47]<<": ";
    if(usas==0)
        cout<<lang[48]<<'\n';
    else
        cout<<lang[49]<<'\n';
}
void creeazaharta()
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
    long cheien,cheiem,usan,usam,cheie=0,total=0,stalpi=0,nrchei=0,gameover=0,usas=0,nr=0,stalpi2;
    int cheitotal=0;
    int n=0;
    int m=0;
    int linia=0;
    int coloana=0;
    long campuri;
    long ocupat;
    int x[100],y[100],errors=0;
    int rt[1000],he=1;
    campuri=0;
    ocupat=0;
    exemplu[2]=0;
    yes=0;
    if(joc==1)
        exemplu[joc]=1;
    if(joc==2)
        exemplu[joc]=2;
    if(joc==3)
        exemplu[joc]=3;
    if(joc==4)
        exemplu[joc]=4;
    if(joc==5)
        exemplu[joc]=5;
    if(joc==6)
        exemplu[joc]=6;
    if(joc==7)
        exemplu[joc]=7;
    if(joc==0)
    {
        system("cls");
        statistica(linia,coloana,n,m,total,stalpi,nr,nrchei,usas);
        SetConsoleTextAttribute(hConsole, 14);
        cout<<"   "<<lang[50]<<'\n';
        SetConsoleTextAttribute(hConsole, 12);
        cout<<"-/----------------------------------------/-"<<'\n'<<'\n';
        SetConsoleTextAttribute(hConsole, 15);
    }
    ifstream fin("exemplu.in");
    ifstream fin2("exemplu2.in");
    ifstream fin3("exemplu3.in");

    ifstream fin4("memorat.out");

    ifstream fol1("Folder1.in");
    ifstream fol2("Folder2.in");
    ifstream fol3("Folder3.in");
    if(exemplu[joc]==1)
        fin>>n>>m;
    else if(exemplu[joc]==2)
        fin2>>n>>m;
    else if(exemplu[joc]==3)
        fin3>>n>>m;
    else if(exemplu[joc]==4)
        fin4>>n>>m;
    else if(exemplu[joc]==5)
        fol1>>n>>m;
    else if(exemplu[joc]==6)
        fol2>>n>>m;
    else if(exemplu[joc]==7)
        fol3>>n>>m;
    else
    {
        cout<<" "<<lang[51]<<" - ";
        cin>>n;
        cout<<'\n'<<" "<<lang[52]<<" - ";
        cin>>m;
        rt[he]=n;
        he++;
        rt[he]=m;
        he++;
        varn=n;
        varm=m;
    }
    total=m*n;
    if(joc==0)
    {
        system("cls");
        statistica(linia,coloana,n,m,total,stalpi,nr,nrchei,usas);
    }
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            v[i][j]='0';
    for(i=1; i<=n+1; ++i)
        v[i][0]=v[i][m+1]='M';
    for(i=1; i<=m+1; ++i)
        v[0][i]=v[n+1][i]='M';
    if(exemplu[joc]==1)
        fin>>linia>>coloana;
    else if(exemplu[joc]==2)
        fin2>>linia>>coloana;
    else if(exemplu[joc]==3)
        fin3>>linia>>coloana;
    else if(exemplu[joc]==4)
        fin4>>linia>>coloana;
    else if(exemplu[joc]==5)
        fol1>>linia>>coloana;
    else if(exemplu[joc]==6)
        fol2>>linia>>coloana;
    else if(exemplu[joc]==7)
        fol3>>linia>>coloana;
    else
    {
        for(k=1; k<=ks; k++)
        {
            SetConsoleTextAttribute(hConsole, 14);
            cout<<"             "<<lang[53]<<'\n';
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"-/----------------------------------------/-"<<'\n'<<'\n';
            SetConsoleTextAttribute(hConsole, 15);
            cout<<" X - ";
            cin>>x[k];
            cout<<'\n'<<" Y - ";
            cin>>y[k];
            m1=x[k];
            m2=y[k];
            yes=1;
            if(x[k]<=n && y[k]<=m && x[k]>0 && y[k]>0)
            {
                linia=x[k];
                coloana=y[k];
                k=ks+1;
                total=m*n-1;
                eroare=0;
                rt[he]=linia;
                rt[he]=linia;
                he++;
                rt[he]=coloana;
                he++;
            }
            else
            {
                eroare=1;
                system("cls");
                statistica(linia,coloana,n,m,total,stalpi,nr,nrchei,usas);
            }
        }
    }
    if(joc==0)
    {
        system("cls");
        statistica(linia,coloana,n,m,total,stalpi,nr,nrchei,usas);
    }
    v[linia][coloana]='X';
    stalpi=0;
    //                                  Construire harta
    for(k=1; k<=ks; ++k)
    {
        if(joc==0)
        {
            system("cls");
            statistica(linia,coloana,n,m,total,stalpi,nr,nrchei,usas);
            SetConsoleTextAttribute(hConsole, 14);
            cout<<"   "<<lang[54]<<'\n';
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"-/----------------------------------------/-"<<'\n'<<'\n';
            SetConsoleTextAttribute(hConsole, 15);
            desen(n,m);
        }
        if(exemplu[joc]==1)
            fin>>stn[k]>>stm[k];
        else if(exemplu[joc]==2)
            fin2>>stn[k]>>stm[k];
        else if(exemplu[joc]==3)
            fin3>>stn[k]>>stm[k];
        else if(exemplu[joc]==4)
            fin4>>stn[k]>>stm[k];
        else if(exemplu[joc]==5)
            fol1>>stn[k]>>stm[k];
        else if(exemplu[joc]==6)
            fol2>>stn[k]>>stm[k];
        else if(exemplu[joc]==7)
            fol3>>stn[k]>>stm[k];
        else
        {
            cout<<"n= ";
            cin>>stn[k];
            nn=stn[k];
            cout<<"m= ";
            cin>>stm[k];
            mm=stm[k];
            m1=nn;
            m2=mm;
            //cout<<'\n'<<"Pole Position -> M("<<stn[k]<<")("<<stm[k]<<")"<<'\n';
            //Sleep(350);
        }
        if(stn[k]==0 && stm[k]==0)
        {
            k=ks+2;
            rt[he]=nn;
            he++;
            rt[he]=mm;
            he++;
        }
        else
        {
            if(v[stn[k]][stm[k]]=='0')
            {
                v[stn[k]][stm[k]]='M';
                total--;
                stalpi++;
                eroare=0;
                rt[he]=nn;
                he++;
                rt[he]=mm;
                he++;
            }
            else
                eroare=1;
        }
    }
    yes=0;
    ocupat=total;
    stalpi2=stalpi;
    //                                  Plaseza iesirea
    for(k=1; k<=ks; ++k)
    {
        if(joc==0)
        {
            system("cls");
            statistica(linia,coloana,n,m,total,stalpi2,nr,nrchei,usas);
            SetConsoleTextAttribute(hConsole, 14);
            cout<<"             "<<lang[55]<<'\n';
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"-/----------------------------------------/-"<<'\n'<<'\n';
            SetConsoleTextAttribute(hConsole, 15);
            desen(n,m);
        }
        if(exemplu[joc]==1)
            fin>>usan>>usam;
        else if(exemplu[joc]==2)
            fin2>>usan>>usam;
        else if(exemplu[joc]==3)
            fin3>>usan>>usam;
        else if(exemplu[joc]==4)
            fin4>>usan>>usam;
        else if(exemplu[joc]==5)
            fol1>>usan>>usam;
        else if(exemplu[joc]==6)
            fol2>>usan>>usam;
        else if(exemplu[joc]==7)
            fol3>>usan>>usam;
        else
        {
            cout<<"n= ";
            cin>>usan;
            nn=usan;
            cout<<"m= ";
            cin>>usam;
            mm=usam;
            m1=nn;
            m2=mm;
            yes=1;
            //cout<<'\n'<<"Door Position -> #("<<usan<<")("<<usam<<")"<<'\n';
        }
        if(v[usan][usam]=='0')
        {
            v[usan][usam]='#';
            k=ks+1;
            stalpi++;
            total--;
            eroare=0;
            usas=1;
            rt[he]=nn;
            he++;
            rt[he]=mm;
            he++;
        }
        else
            eroare=1;
    }
    //                                      Plaseza cheia
    if(joc==0)
        system("cls");
    nr=0;
    if(exemplu[joc]==1)
        fin>>nrchei;
    else if(exemplu[joc]==2)
        fin2>>nrchei;
    else if(exemplu[joc]==3)
        fin3>>nrchei;
    else if(exemplu[joc]==4)
        fin4>>nrchei;
    else if(exemplu[joc]==5)
        fol1>>nrchei;
    else if(exemplu[joc]==6)
        fol2>>nrchei;
    else if(exemplu[joc]==7)
        fol3>>nrchei;
    else
    {
        if(joc==0)
        {
            statistica(linia,coloana,n,m,total,stalpi2,nr,nrchei,usas);
            SetConsoleTextAttribute(hConsole, 14);
            cout<<"     "<<lang[56]<<'\n';
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"-/----------------------------------------/-"<<'\n'<<'\n';
            SetConsoleTextAttribute(hConsole, 15);
            cout<<" "<<lang[46]<<" - ";
            cin>>nrchei;
        }
        rt[he]=nrchei;
        he++;
    }
    if(nrchei==0)
        v[usan][usam]='/';
    cheitotal=nrchei;
    int nrcheii;
    nrcheii=nrchei;
    for(k=1; k<=nrcheii; ++k)
    {
        if(joc==0)
        {
            system("cls");
            statistica(linia,coloana,n,m,total,stalpi2,nr,nrchei,usas);
            SetConsoleTextAttribute(hConsole, 14);
            cout<<"                "<<lang[57]<<'\n';
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"-/----------------------------------------/-"<<'\n'<<'\n';
            SetConsoleTextAttribute(hConsole, 15);
            desen(n,m);
        }
        if(exemplu[joc]==1)
            fin>>cheien>>cheiem;
        else if(exemplu[joc]==2)
            fin2>>cheien>>cheiem;
        else if(exemplu[joc]==3)
            fin3>>cheien>>cheiem;
        else if(exemplu[joc]==4)
            fin4>>cheien>>cheiem;
        else if(exemplu[joc]==5)
            fol1>>cheien>>cheiem;
        else if(exemplu[joc]==6)
            fol2>>cheien>>cheiem;
        else if(exemplu[joc]==7)
            fol3>>cheien>>cheiem;
        else
        {
            cout<<"n= ";
            cin>>cheien;
            nn=cheien;
            cout<<"m= ";
            cin>>cheiem;
            mm=cheiem;
            m1=nn;
            m2=mm;
            yes=1;
            //cout<<'\n'<<"Key Position -> @("<<cheien<<")("<<cheiem<<")"<<'\n';
        }
        if(v[cheien][cheiem]=='0')
        {
            v[cheien][cheiem]='@';
            nr++;
            stalpi++;
            total--;
            eroare=0;
            rt[he]=nn;
            he++;
            rt[he]=mm;
            he++;
        }
        else
        {
            eroare=1;
            nrcheii++;
        }
    }
    system("cls");
    if(joc==0)
        statistica(linia,coloana,n,m,total,stalpi2,nr,nrchei,usas);
    cout<<'\n'<<'\n';
    if(exemplu[joc]==0)
    {
        desen(n,m);
        retinere(rt,he,stalpi2,nrchei);
        Sleep(700);
    }
    fin.close();
    fin2.close();
    fin3.close();
    fin4.close();

    fol1.close();
    fol2.close();
    fol3.close();
    if(anulat==0)
    {
        previousgame=1;
        int i,incarcare=0,io,iio=25,iip=1,ip,nivele=0;
        for(j=1; j<=26; ++j)
        {
            nivele++;
            HANDLE  hConsole;
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 3);
            system("cls");
            for(i=1; i<=11; ++i)
                cout<<'\n';
            if(nivele<8)
                cout<<"                               "<<lang[58];
            if(nivele>=8 && nivele<16)
                cout<<"                              "<<lang[59];
            if(nivele>16)
                cout<<"                               "<<lang[60];
            if(j%3==1)
                cout<<".";
            if(j%3==2)
                cout<<"..";
            if(j%3==0)
                cout<<"...";
            cout<<'\n';
            SetConsoleTextAttribute(hConsole, 15);
            cout<<"                         ";
            cout<<(char) 201;
            for(i=1; i<=26; ++i)
                cout<<(char) 205;
            cout<<(char) 187;
            cout<<'\n';
            cout<<"                         ";
            cout<<(char) 186;
            SetConsoleTextAttribute(hConsole, 12);
            ip=iip;
            iip++;
            io=iio;
            iio--;
            while(ip!=0)
            {
                cout<<(char) 219;
                ip--;
            }
            while(io!=0)
            {
                cout<<(char) 176;
                io--;
            }
            SetConsoleTextAttribute(hConsole, 15);
            cout<<(char) 186;
            cout<<" ";
            SetConsoleTextAttribute(hConsole, 12);
            cout<<incarcare<<"%"<<'\n';
            SetConsoleTextAttribute(hConsole, 15);
            cout<<"                         ";
            cout<<(char) 200;
            for(i=1; i<=26; ++i)
                cout<<(char) 205;
            cout<<(char) 188;
            cout<<'\n';
            for(i=1; i<=10; ++i)
                cout<<'\n';
            incarcare+=4;
            Sleep(50);
        }
        SetConsoleTextAttribute(hConsole, 15);
        Sleep(300);
        int cheinr;
        cheinr=0;
        int ups=0;
        varstalpi=stalpi2;
        varchei=nrchei;
        //                                          Incepe jocul
        for(k=1; k<=ks; ++k)
        {
            if(ups==0)
            {
                system("cls");
                for(i=1; i<=8; ++i)
                    cout<<'\n';
                SetConsoleTextAttribute(hConsole, 11);
                if(nr<10)
                    cout<<"                                         "<<lang[46]<<":  "<<cheinr<<"/"<<cheitotal;
                else
                    cout<<"                                         "<<lang[46]<<": "<<cheinr<<"/"<<cheitotal;
                SetConsoleTextAttribute(hConsole, 14);
                if(cheinr==cheitotal)
                    cout<<"    -> "<<lang[61];
                cout<<'\n';
                SetConsoleTextAttribute(hConsole, 13);
                if(cheinr==cheitotal && cheitotal!=0 && ocupat/1.3<=campuri)
                    cout<<"                                                          "<<lang[62]<<" x3";
                else if(cheinr==cheitotal && cheitotal!=0)
                    cout<<"                                                          "<<lang[62]<<" x2";
                else if(ocupat/1.3<=campuri)
                    cout<<"                                                          "<<lang[63]<<" x2";
                cout<<'\n';
                SetConsoleTextAttribute(hConsole, 10);
                cout<<"                                      "<<lang[44]<<": "<<campuri<<"/"<<ocupat<<'\n';
                SetConsoleTextAttribute(hConsole, 15);
                /* for(i=1; i<=m; i++)
                     cout<<' ';
                 cout<<'\n';
                 cout<<" ";
                 cout<<(char) 201;
                 for(i=1; i<=2*m+3-2; i++)
                     cout<<(char) 205;
                 cout<<(char) 187;
                 cout<<'\n';
                 for(i=1; i<=n; i++)
                 {
                     cout<<" ";
                     cout<<(char) 186;
                     for(j=1; j<=m; ++j)
                     {
                         if(v[i][j])
                             cout<<" "<<v[i][j];
                     }
                     cout<<" ";
                     cout<<(char) 186<<'\n';
                 }
                 cout<<" ";
                 cout<<(char) 200;
                 for(i=1; i<=2*m+3-2; i++)
                     cout<<(char) 205;
                 cout<<(char) 188;
                 cout<<'\n';
                 l++;
                 cout<<'\n'; */
                {
                    for(i=1; i<=m; i++)
                        cout<<' ';
                    cout<<'\n';
                    cout<<" ";
                    cout<<(char) 201;
                    for(i=1; i<=(2*m+3-2)/2; i++)
                        cout<<(char) 205;
                    cout<<(char) 187;
                    cout<<'\n';
                    for(i=1; i<=n; i++)
                    {
                        cout<<" ";
                        cout<<(char) 186;
                        for(j=1; j<=m; ++j)
                        {
                            if(v[i][j]=='X')
                            {
                                SetConsoleTextAttribute(hConsole, 12);
                                cout<<(char) 254;
                                SetConsoleTextAttribute(hConsole, 15);
                            }
                            else if(v[i][j]==' ')
                                cout<<' ';
                            else if(v[i][j]=='M')
                                cout<<(char) 219;
                            else if(v[i][j]=='@')
                            {
                                SetConsoleTextAttribute(hConsole, 14);
                                cout<<(char) 239;
                                SetConsoleTextAttribute(hConsole, 15);
                            }
                            else if(v[i][j]=='0')
                                cout<<(char) 176;
                            else
                            {
                                SetConsoleTextAttribute(hConsole, 11);
                                cout<<v[i][j];
                                SetConsoleTextAttribute(hConsole, 15);
                            }
                        }
                        cout<<(char) 186<<'\n';
                    }
                    cout<<" ";
                    cout<<(char) 200;
                    for(i=1; i<=(2*m+3-2)/2; i++)
                        cout<<(char) 205;
                    cout<<(char) 188;
                    cout<<'\n';
                    l++;
                    cout<<'\n';
                }
            }
            ups=0;
            ch=getch();
            if(ch=='\r') //ENTER
            {
                gameover=5;
                break;
            }
            if(ch!='\0')
            {
                ch=getch();
                if(ch=='H' && v[linia-1][coloana]!='M' && v[linia-1][coloana]!=' ' && v[linia-1][coloana]!='#') //SUS
                {
                    v[linia][coloana]=' ';
                    linia=linia-1;
                    campuri++;
                }
                else if(ch=='K' && v[linia][coloana-1]!='M' && v[linia][coloana-1]!=' ' && v[linia][coloana-1]!='#') //STANGA
                {
                    v[linia][coloana]=' ';
                    coloana=coloana-1;
                    campuri++;
                }
                else if(ch=='P' && v[linia+1][coloana]!='M' && v[linia+1][coloana]!=' ' && v[linia+1][coloana]!='#') //JOS
                {
                    v[linia][coloana]=' ';
                    linia=linia+1;
                    campuri++;
                }
                else if(ch=='M' && v[linia][coloana+1]!='M' && v[linia][coloana+1]!=' ' && v[linia][coloana+1]!='#') //DREAPTA
                {
                    v[linia][coloana]=' ';
                    coloana=coloana+1;
                    campuri++;
                }
                else
                    ups=1;
            }

            if(v[linia][coloana]=='@')
            {
                nrchei--;
                cheinr++;
            }
            if(nrchei==0)
            {
                cheie=1;
                v[usan][usam]='/';
            }
            if(cheie==1 && v[linia][coloana]=='/')
                k=ks+1;
            v[linia][coloana]='X';
            //                                                     Ai pierdut
            if(v[linia-1][coloana]!='0'  && v[linia][coloana-1]!='0' && v[linia+1][coloana]!='0' && v[linia][coloana+1]!='0')
                if(v[linia-1][coloana]=='/'  || v[linia][coloana-1]=='/' || v[linia+1][coloana]=='/' || v[linia][coloana+1]=='/' || v[linia-1][coloana]=='@'  || v[linia][coloana-1]=='@' || v[linia+1][coloana]=='@' || v[linia][coloana+1]=='@')
                    cout<<"";
                else if(k!=ks+1)
                {
                    gameover=1;
                    break;
                }
        }
        system("cls");
        int bonus=0,nota=0;
        if(gameover==0)
        {
            for(i=1; i<=2; ++i)
                cout<<'\n';
            cout<<"                                "<<lang[63]<<'\n';
            cout<<"                                    "<<lang[64]<<'\n'<<'\n';
            Sleep(250);
        }
        else if(gameover==5)
        {
            for(i=1; i<=2; ++i)
                cout<<'\n';
            cout<<"                              "<<lang[65]<<'\n'<<'\n';
            Sleep(250);
        }
        else
        {
            for(i=1; i<=2; ++i)
                cout<<'\n';
            cout<<"                         "<<lang[66]<<'\n'<<'\n';
            Sleep(250);
        }
        Sleep(250);
        cout<<'\n';
        cout<<"                                 "<<lang[67]<<": ";
        if(ocupat/1.3<=campuri)
        {
            cout<<"#### (4/4)";
            nota=4;
        }
        else
        {
            if(ocupat/1.5<=campuri)
            {
                cout<<"###0 (3/4)";
                nota=3;
            }
            else
            {
                if(ocupat/2<=campuri)
                {
                    cout<<"##00 (2/4)";
                    nota=2;
                }
                else
                {
                    cout<<"#000 (1/4)";
                    nota=1;
                }
            }
        }
        Sleep(150);
        if(campuri==ocupat)
            bonus=1;
        cout<<'\n'<<'\n';
        cout<<"                                ";
        for(i=1; i<=18; i++)
            cout<<(char) 205;
        SetConsoleTextAttribute(hConsole, 10);
        cout<<'\n'<<"                               "<<" "<<lang[118]<<"  "<<(char) 186<<" "<<campuri<<"/"<<ocupat;
        SetConsoleTextAttribute(hConsole, 15);
        cout<<'\n'<<"                                ";
        for(i=1; i<=18; i++)
            cout<<(char) 205;
        Sleep(150);
        SetConsoleTextAttribute(hConsole, 11);
        cout<<'\n'<<"                                "<<"  "<<lang[46]<<"   "<<(char) 186<<"  "<<cheinr<<"/"<<cheitotal;
        SetConsoleTextAttribute(hConsole, 15);
        cout<<'\n'<<"                                ";
        for(i=1; i<=18; i++)
            cout<<(char) 205;
        Sleep(150);
        SetConsoleTextAttribute(hConsole, 9);
        cout<<'\n'<<"                                "<<"  "<<lang[67]<<"   "<<(char) 186<<"  "<<nota<<"/4";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<'\n'<<"                                ";
        for(i=1; i<=18; i++)
            cout<<(char) 205;
        Sleep(150);
        if(cheinr!=0)
            campuri=campuri*cheinr;
        if(nota!=0)
            campuri=campuri*nota;
        SetConsoleTextAttribute(hConsole, 13);
        int premium=1;
        if(cheinr==cheitotal && cheitotal!=0)
            premium++;
        if(nota==4)
            premium++;
        cout<<'\n'<<"                                "<<" "<<lang[62]<<" "<<(char) 186<<"  ";
        if(campuri==campuri*premium)
            cout<<" -";
        else
            cout<<" x"<<premium;
        campuri=campuri*premium;
        SetConsoleTextAttribute(hConsole, 15);
        if(bonus==1)
        {
            cout<<'\n'<<"                                ";
            for(i=1; i<=18; i++)
                cout<<(char) 205;
            Sleep(150);
            SetConsoleTextAttribute(hConsole, 12);
            cout<<'\n'<<"                                "<<"  "<<lang[68]<<"  "<<(char) 186<<"   x2";
            SetConsoleTextAttribute(hConsole, 15);
            campuri=campuri*2;
        }
        cout<<'\n'<<"                                ";
        for(i=1; i<=18; i++)
            cout<<(char) 205;
        Sleep(150);
        SetConsoleTextAttribute(hConsole, 14);
        cout<<'\n'<<"                                "<<"  "<<lang[69]<<"  "<<(char) 186<<"  "<<campuri;
        SetConsoleTextAttribute(hConsole, 15);
        cout<<'\n'<<"                                ";
        for(i=1; i<=18; i++)
            cout<<(char) 205;
        primibani=banutijoc;
        banutijoc+=campuri;
        baniinainte=campuri;
        banutiinceput(2);
        for(i=1; i<=3; ++i)
            cout<<'\n';
        //Sleep(200);
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"   <- "<<lang[21];
        SetConsoleTextAttribute(hConsole, 15);
        cout<<'\n'<<'\n';
        joc=0;
        int valu=500;
        for(i=1; i<=valu; ++i)
        {
            ch=getch();
            if(ch=='\r')
                valu=1;
            else
                valu++;
        }
        system("cls");
        seadaugabani=1;
    }
    anulat=0;
    meniu(0);
}
void loading(int o)
{
    int n[10], m[10], stalpi[10], nrchei[10];
    char Sp1[100], Sp2[100], Sp3[100], numeSp1[100], numeSp2[100], numeSp3[100];
    ifstream Space1("Space1.in");
    ifstream Space2("Space2.in");
    ifstream Space3("Space3.in");
    n[4]=varn;
    m[4]=varm;
    stalpi[4]=varstalpi;
    nrchei[4]=varchei;
    Space1>>Sp1>>numeSp1>>n[5]>>m[5]>>stalpi[5]>>nrchei[5];
    Space2>>Sp2>>numeSp2>>n[6]>>m[6]>>stalpi[6]>>nrchei[6];
    Space3>>Sp3>>numeSp3>>n[7]>>m[7]>>stalpi[7]>>nrchei[7];

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    system("cls");
    cout<<'\n';
    cout<<"                                     "<<lang[70]<<'\n'<<'\n';
    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n';
    if(o==4 || o==5 || o==6 || o==7)
    {
        SetConsoleTextAttribute(hConsole, 12);
        cout<<"                                  S:";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<n[o]<<"/"<<m[o];
        SetConsoleTextAttribute(hConsole, 12);
        cout<<" P:";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<stalpi[o];
        if(stalpi[o]<10)
            cout<<" ";
        SetConsoleTextAttribute(hConsole, 12);
        cout<<" K:";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<nrchei[o];
    }

    cout<<'\n';
    cout<<"                           ----------------------------"<<'\n';
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"      S ";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"- ";
    SetConsoleTextAttribute(hConsole, 14);
    cout<<"S";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"ize";
    cout<<"             ";
    if(o==1)
    {
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"|        >> "<<lang[71]<<" <<        |";
    }
    else
        cout<<"|           "<<lang[71]<<"           |";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<nume3[salvare[1]-1];
    cout<<'\n'<<"                           ----------------------------"<<'\n';
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"      P ";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"- ";
    SetConsoleTextAttribute(hConsole, 14);
    cout<<"P";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"oles";
    cout<<"            ";
    if(o==2)
    {
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"|        >> "<<lang[72]<<" <<        |";
    }
    else
        cout<<"|           "<<lang[72]<<"           |";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<nume3[salvare[2]-1];
    cout<<'\n'<<"                           ----------------------------"<<'\n';
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"      K ";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"- ";
    SetConsoleTextAttribute(hConsole, 14);
    cout<<"K";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"eys";
    cout<<"             ";
    if(o==3)
    {
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"|       >> "<<lang[73]<<" <<      |";
    }
    else
        cout<<"|          "<<lang[73]<<"         |";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<nume3[salvare[3]-1];
    cout<<'\n'<<"                           ----------------------------"<<'\n';
    cout<<"                           ";
    if(o==4)
    {
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"|   >> "<<lang[74]<<" <<  |";
        SetConsoleTextAttribute(hConsole, 12);
    }
    else
    {
        if(previousgame==0)
            SetConsoleTextAttribute(hConsole, 8);
        cout<<"|      "<<lang[74]<<"     |";
    }
    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n'<<"                           ----------------------------"<<'\n';
    cout<<"                           ";
    if(o==5)
    {
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"|     >> "<<lang[75]<<" 1  <<    |";
    }
    else
        cout<<"|        "<<lang[75]<<" 1        |";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"  --> #"<<Sp1;
    cout<<'\n'<<"                           ----------------------------"<<'\n';
    cout<<"                           ";
    if(o==6)
    {
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"|     >> "<<lang[75]<<" 2  <<    |";
    }
    else
        cout<<"|        "<<lang[75]<<" 2        |";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"  --> #"<<Sp2;
    cout<<'\n'<<"                           ----------------------------"<<'\n';
    cout<<"                           ";
    if(o==7)
    {
        SetConsoleTextAttribute(hConsole, 240);
        cout<<"|     >> "<<lang[75]<<" 3  <<    |";
    }
    else
        cout<<"|        "<<lang[75]<<" 3        |";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"  --> #"<<Sp3;
    cout<<'\n'<<"                           ----------------------------";
    cout<<'\n'<<"                                      ";
    if(o==5)
    {
        if(nume1==numeSp1)
            SetConsoleTextAttribute(hConsole, 12);
        else
            SetConsoleTextAttribute(hConsole, 14);
        cout<<numeSp1;
    }

    if(o==6)
    {
        if(nume1==numeSp2)
            SetConsoleTextAttribute(hConsole, 12);
        else
            SetConsoleTextAttribute(hConsole, 14);
        cout<<numeSp2;
    }
    if(o==7)
    {
        if(nume1==numeSp3)
            SetConsoleTextAttribute(hConsole, 12);
        else
            SetConsoleTextAttribute(hConsole, 14);
        cout<<numeSp3;
    }
    SetConsoleTextAttribute(hConsole, 12);
    cout<<'\n'<<'\n'<<'\n'<<"               <--                    "<<lang[21]<<"                      -->"<<'\n';
}
void incepeunjocaleatoriu()
{
    system("cls");
    int aici;
    int paci=0;
    int inapoi=0,o=1,opop=1000;
    loading(1);
    for(i=1; i<=opop; ++i)
    {
        ch=getch();
        if(ch!='\r')
        {
            ch=getch();
            if(ch=='H')
            {
                o--;
                if(o==4 && previousgame==0)
                    o--;
            }

            else    if(ch=='P')
            {
                o++;
                if(o==4 && previousgame==0)
                    o++;
            }
            else    if(ch=='K' || ch=='M')
            {
                paci=1;
                break;
            }
        }
        else
            inapoi=1;
        int ups=0;
        if(inapoi==1)
        {
            if(o==1)
            {
                aici=1;
                break;
            }
            else if(o==2)
            {
                aici=2;
                break;
            }
            else if(o==3)
            {
                aici=3;
                break;
            }
            else if(o==4)
            {
                aici=4;
                break;
            }
            else if(o==5)
            {
                aici=5;
                break;
            }
            else if(o==6)
            {
                aici=6;
                break;
            }
            else if(o==7)
            {
                aici=7;
                break;
            }
        }
        else
        {
            if(o<1)
                o=7;
            if(o>7)
                o=1;
            if(ups==0)
                loading(o);
        }
    }
    if(paci==0)
    {
        joc=aici;
        creeazaharta();
    }
    else
        meniu(0);
}
void instructiuni2(int o)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    system("cls");
    cout<<'\n';
    cout<<"                                       "<<lang[13]<<'\n';
    cout<<'\n'<<'\n';
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"                 "<<lang[76]<<"                 ";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"|"<<'\n';
    cout<<"                                           |"<<'\n';
    cout<<"      "<<lang[77]<<" |"<<'\n';
    cout<<" "<<lang[78]<<" |"<<'\n';
    cout<<" "<<lang[79]<<" |"<<'\n';
    cout<<" "<<lang[80]<<"                    |"<<'\n';
    if(o==1)
    {
        cout<<"                                           |";
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"       >> "<<lang[81]<<" <<";
    }
    else
        cout<<"                                           |          "<<lang[81]<<" ";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n';
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"                "<<lang[10]<<"               ";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"|"<<'\n';
    if(o==2)
    {
        cout<<"                                           |";
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"       >> "<<lang[82]<<" <<"<<'\n';
    }
    else
        cout<<"                                           |          "<<lang[82]<<'\n';
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"      "<<lang[83]<<" |"<<'\n';
    if(o==3)
    {
        cout<<" "<<lang[84]<<" |";
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"         >> "<<lang[21]<<" <<";
    }
    else
        cout<<" "<<lang[84]<<" |            "<<lang[21]<<"";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n';
    cout<<" "<<lang[85]<<" |";
    cout<<'\n';
    if(o==4)
    {
        cout<<" "<<lang[86]<<"          |";
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"     >> "<<lang[87]<<" <<";
    }
    else
        cout<<" "<<lang[86]<<"          |        "<<lang[87]<<"";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n';
    cout<<"                                           |"<<'\n';
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"                   "<<lang[11];
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"                   |"<<'\n';
    cout<<"                                           |"<<'\n';
    cout<<"      "<<lang[88]<<" |"<<'\n';
    cout<<" "<<lang[89]<<"                |";
    SetConsoleTextAttribute(hConsole, 10);
    cout<<"         "<<lang[90]<<'\n';
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"                                           | ";
    SetConsoleTextAttribute(hConsole, 10);
    if(o==5)
    {
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"   >> "<<lang[91]<<" <<"<<'\n';
    }
    else
        cout<<"      "<<lang[91]<<'\n';
    SetConsoleTextAttribute(hConsole, 10);
    cout<<"                  "<<lang[92]<<"                   ";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"|"<<'\n';

}
void Instructiuni2(int o)
{
    cout<<'\n';
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    system("cls");
    cout<<'\n';
    cout<<"                                       "<<lang[82]<<'\n';
    cout<<'\n'<<'\n';
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"   ^                                       |"<<'\n';
    cout<<"   | - "<<lang[93]<<"                        |"<<'\n';
    cout<<"                                           |";
    cout<<'\n';
    cout<<"  <- - "<<lang[94]<<"                     |";
    cout<<'\n';
    cout<<"                                           |";
    cout<<'\n';
    cout<<"  -> - "<<lang[95]<<"                    |"<<'\n';
    cout<<"                                           |";
    cout<<'\n';
    cout<<"   | - "<<lang[96]<<"                        |";
    SetConsoleTextAttribute(hConsole, 3);
    cout<<"        >> "<<lang[21]<<" <<"<<'\n';
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"   v                                       |"<<'\n';
    cout<<"                                           |";
    cout<<'\n';
    cout<<"                                           |"<<'\n';
    cout<<"   "<<(char) 254<<" - "<<lang[97]<<"                       |"<<'\n';
    cout<<"                                           |"<<'\n';
    cout<<"   "<<(char) 239<<" - "<<lang[98]<<"                               |"<<'\n';
    cout<<"                                           |"<<'\n';
    cout<<"   # - "<<lang[99]<<"                        |"<<'\n';
    cout<<"                                           |"<<'\n';
    cout<<"   / - "<<lang[100]<<"                         |"<<'\n';
    cout<<"                                           |"<<'\n';
    cout<<"   "<<lang[101]<<"                  |"<<'\n';
}
void calculator()
{
    limba++;
    if(limba%2==0)
        for(i=1; i<=liniilang; ++i)
            strcpy(lang[i],enlang[i]);

    else
        for(i=1; i<=liniilang; ++i)
            strcpy(lang[i],rolang[i]);
    instructiuni2(1);
}
void Instructiuni()
{
    Instructiuni2(1);
    int inapoi=0,o=1,opop=1000;
    for(i=1; i<=opop; ++i)
    {
        ch=getch();
        if(ch!='\r')
        {
            ch=getch();
            if(ch=='H')
                o--;
            else    if(ch=='P')
                o++;
        }
        else
            inapoi=1;
        int ups=0;
        if(inapoi==1)
        {
            opop=0;
            instructiuni2(0);
            inapoi=0;
            o=0;
        }
        else
        {
            if(o!=1)
            {
                o=1;
                ups=1;
            }
            if(ups==0)
                Instructiuni2(o);
        }
    }
}
void instructiuni()
{
    instructiuni2(1);
    long inapoi=0,o=1,opop=1000;
    for(i=1; i<=opop; ++i)
    {
        ch=getch();
        if(ch!='\r')
        {
            ch=getch();
            if(ch=='H')
                o--;
            else    if(ch=='P')
                o++;
        }
        else
            inapoi=1;
        int ups=0;
        if(inapoi==1)
        {
            if(o==1)
                calculator();
            else if(o==2)
                Instructiuni();
            else if(o==3)
            {
                opop=0;
                meniu(0);
            }
            else if(o==4)
            {
                banutijoc=0;
                banutiinceput(2);
                opop=0;
                meniu(0);
            }
            else if(o==5)
            {
                system ("Info.txt");
                opop=0;
                meniu(0);
            }
            inapoi=0;
            o=0;
        }
        else
        {
            if(o<1)
            {
                //o=1;
                //ups=1;
                o=5;
            }
            if(o>5)
            {
                //o=4;
                //ups=1;
                o=1;
            }
            if(ups==0)
                instructiuni2(o);
        }
    }
}
void estisigur(int k)
{
    system("cls");
    for(i=1; i<=10; ++i)
        cout<<'\n';
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"                          "<<lang[102]<<'\n'<<'\n';
    SetConsoleTextAttribute(hConsole, 15);
    if(k==1)
    {
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"                           >> "<<lang[103]<<" <<";
    }
    else
        cout<<"                              "<<lang[103];
    SetConsoleTextAttribute(hConsole, 15);
    if(k==2)
    {
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"         >> "<<lang[104]<<" <<";
    }
    else
        cout<<"         "<<lang[104];
    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n';
}
void iesire()
{
    int intrare=0,k=1;
    estisigur(1);
    for(i=1; i<=iesi; ++i)
    {
        ch=getch();
        if(ch!='\r')
        {
            ch=getch();
            if(ch=='K')
                k--;
            else    if(ch=='M')
                k++;
        }
        else
            intrare=1;
        int ups=0;
        if(intrare==1)
        {
            if(k==1)
                iesi=1;
            else
            {
                inreglog=1;
                iesi=1;
                break;
            }
            intrare=0;
            k=0;
        }
        else
        {
            if(k<1)
            {
                k=1;
                ups=1;
            }
            if(k>2)
            {
                k=2;
                ups=1;
            }
            if(ups==0)
                estisigur(k);
        }
    }
}
void next()
{
    if(nra!=ka[pa-1] && ka[pa-1]!=10)
        sfarsit=1;
    else
        total++;
}
void decizie()
{
    if(ka[pa+1]!=10)
    {
        if(ka[pa]==10)
            ka[pa+1]=lamp;
        else
        {
            if(ka[pa]==1)
                ka[pa+1]=ka[pa]+1;
            else if(ka[pa]==5)
                ka[pa+1]=ka[pa]-1;
            else
            {
                int random;
                srand (time(NULL));
                random = rand() % 6;
                if(random<3)
                    ka[pa+1]=ka[pa]+1;
                else if(random>=3)
                    ka[pa+1]=ka[pa]-1;
            }
        }
    }
}
void afisare(int k, int l)
{
    int i;
    cout<<'\n'<<'\n'<<"               ";
    if(k==1)
        for(i=1; i<=5; ++i)
        {
            if(nor[i][l]==0 || nor[i][l]==2 || nor[i][l]==3 || nor[i][l]==4)
                cout<<"       ";
            else if(alegere[l]==1)
            {
                if(stabilit==1)
                {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout<<"  "<<(char) 254<<(char) 254<<(char) 254<<"  ";
                    SetConsoleTextAttribute(hConsole, 15);
                    alegere[l]=0;
                    nor[i+2][l]=5;
                }
                else
                {
                    cout<<"       ";
                    alegere[l]=0;
                    nor[i][l]=5;
                }
            }
            else if(nor[i][l]==1)
            {
                SetConsoleTextAttribute(hConsole, 12);
                cout<<"  "<<(char) 254<<(char) 254<<(char) 254<<"  ";
                SetConsoleTextAttribute(hConsole, 15);
            }
            cout<<"   ";
        }
    cout<<'\n'<<"               ";
    for(i=1; i<=5; ++i)
    {
        if(nor[i][l]==0)
            cout<<"       ";
        else if(nor[i][l]==3)
            cout<<(char) 219<<(char) 179<<(char) 219<<(char) 179<<(char) 219<<(char) 179<<(char) 219;
        else if(nor[i][l]==4)
            cout<<(char) 177<<(char) 177<<(char) 177<<(char) 177<<(char) 177<<(char) 177<<(char) 177;
        else
            cout<<(char) 219<<(char) 219<<(char) 219<<(char) 219<<(char) 219<<(char) 219<<(char) 219;
        cout<<"   ";
    }
    cout<<'\n';
}
void thrown()
{
    system("cls");
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);
    int i,j,first=1,stalon1=0,timp=60,timpcurent,timpcurent2,timp2,bonus=0,total2=0;
    int ip,ipp;
    for(i=3; i>=0; --i)
    {

        system("cls");
        for(j=1; j<=10; ++j)
            cout<<'\n';
        if(i==1)
        {
            cout<<"                                    ";
            cout<<"   X  "<<'\n'<<"                                    ";
            cout<<"  XX  "<<'\n'<<"                                    ";
            cout<<"   X  "<<'\n'<<"                                    ";
            cout<<"   X  "<<'\n'<<"                                    ";
            cout<<"  XXX  "<<'\n';
        }
        if(i==2)
        {
            cout<<"                                    ";
            cout<<" XXXXX"<<'\n'<<"                                    ";
            cout<<"     X"<<'\n'<<"                                    ";
            cout<<" XXXXX"<<'\n'<<"                                    ";
            cout<<" X    "<<'\n'<<"                                    ";
            cout<<" XXXXX"<<'\n';
        }
        if(i==3)
        {
            cout<<"                                    ";
            cout<<" XXXXX"<<'\n'<<"                                    ";
            cout<<"     X"<<'\n'<<"                                    ";
            cout<<" XXXXX"<<'\n'<<"                                    ";
            cout<<"     X"<<'\n'<<"                                    ";
            cout<<" XXXXX"<<'\n';
        }
        if(i==0)
        {
            cout<<"                             ";
            cout<<"   XXXX    XXXX   X"<<'\n'<<"                             ";
            cout<<"  X       X    X  X"<<'\n'<<"                             ";
            cout<<" X    XX X      X X"<<'\n'<<"                             ";
            cout<<"  X    X  X    X   "<<'\n'<<"                             ";
            cout<<"  XXXX     XXXX   X"<<'\n';
        }
        if(i!=0)
            Sleep(500);
        else
            Sleep(300);
    }
    SetConsoleTextAttribute(hConsole, 15);
    time_t now = time(0);
    tm *ltm = localtime(&now);
    timpcurent=ltm->tm_min*60 + ltm->tm_sec;
    timpcurent2=ltm->tm_min*60 + ltm->tm_sec +90;
    for(i=1; i<=5; ++i)
        nor[i][pa]=0;
    nor[3][pa]=1;
    ka[pa]=3;
    for(j=1; j<=2; ++j)
    {
        decizie();
        pa++;
        for(i=1; i<=5; ++i)
            nor[i][pa]=0;
        nor[ka[pa]][pa]=1;
    }
    system("cls");
    for(j=pa; j>=pa-1; --j)
        afisare(0,j);
    cout<<'\n'<<"               ";
    for(i=1; i<=5; ++i)
    {
        if(nor[i][j]==0)
            cout<<"       ";
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"  "<<(char) 254<<(char) 254<<(char) 254<<"  ";
            SetConsoleTextAttribute(hConsole, 15);
        }
        cout<<"   ";
    }
    cout<<'\n'<<"               ";
    for(i=1; i<=5; ++i)
    {
        if(nor[i][j]==0)
            cout<<"       ";
        else
            cout<<(char) 219<<(char) 219<<(char) 219<<(char) 219<<(char) 219<<(char) 219<<(char) 219;
        cout<<"   ";
    }
    cout<<'\n'<<'\n';
    nra=ka[pa-2];
    for(j=1; j<=6; ++j)
        cout<<'\n';
    SetConsoleTextAttribute(hConsole, 14);
    cout<<"           "<<lang[105]<<":0"<<'\n'<<'\n';
    SetConsoleTextAttribute(hConsole, 10);
    cout<<"           "<<lang[106]<<":1"<<'\n'<<'\n';
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"           "<<lang[107]<<":90";
    SetConsoleTextAttribute(hConsole, 15);
    for(j=1; j<=1000; ++j)
    {
        if(sfarsit==1)
            break;
        stabilit=0;
        ch=getch();
        if(ch!='\r')
        {
            ch=getch();
            if(ch=='K')
            {
                stabilit=1;
                nra--;
            }
            else    if(ch=='M')
            {
                stabilit=2;
                nra++;
            }
        }
        system("cls");
        next();
        decizie();
        pa++;
        for(i=1; i<=5; ++i)
            if(nor[i][pa]==NULL)
                nor[i][pa]=0;
        nor[ka[pa]][pa]=1;
        int random;
        srand (time(NULL));
        random = rand() % 13;
        if(total>40)
            if(random<=3)
            {
                if(ka[pa]==1)
                    nor[4][pa]=2;
                if(ka[pa]==2)
                    nor[5][pa]=2;
                if(ka[pa]==4)
                    nor[1][pa]=2;
                if(ka[pa]==5)
                    nor[2][pa]=2;
            }
        if(total>100)
            if(random>=2 && random<6)
            {
                if(ka[pa]==2)
                {
                    nor[1][pa+1]=3;
                    nor[3][pa+1]=3;
                }
                if(ka[pa]==3)
                {
                    nor[2][pa+1]=3;
                    nor[4][pa+1]=3;
                }
                if(ka[pa]==4)
                {
                    nor[3][pa+1]=3;
                    nor[5][pa+1]=3;
                }
            }
        if(total>150)
            if(random>=6 && random<8)
            {
                if(ka[pa]==2)
                {
                    nor[1][pa+1]=1;
                    nor[3][pa+1]=1;
                    nor[2][pa+2]=1;
                }
                if(ka[pa]==3)
                {
                    nor[2][pa+1]=1;
                    nor[4][pa+1]=1;
                    nor[3][pa+2]=1;
                }
                if(ka[pa]==4)
                {
                    nor[3][pa+1]=1;
                    nor[5][pa+1]=1;
                    nor[4][pa+2]=1;
                }
                if(ka[pa]==2 || ka[pa]==3 || ka[pa]==4)
                {
                    alegere[pa+1]=1;
                    ka[pa+1]=10;
                    lamp=ka[pa];
                }
            }
        if(total>200)
            if((random>=8 && random<10) || (random>=1 && random<3))
                nor[ka[pa]][pa+1]=4;
        for(j=pa; j>=pa-1; --j)
            afisare(0,j);
        afisare(1,j);
        SetConsoleTextAttribute(hConsole, 12);
        time_t now = time(0);
        tm *ltm = localtime(&now);
        timpcurent=ltm->tm_min*60 + ltm->tm_sec;
        timp=timpcurent2-timpcurent;
        cout<<'\n'<<'\n';
        if(timp<=5)
        {
            SetConsoleTextAttribute(hConsole, 14);
            cout<<"                                 5";
            if(timp<=4)
            {
                SetConsoleTextAttribute(hConsole, 11);
                cout<<"   4";
                if(timp<=3)
                {
                    SetConsoleTextAttribute(hConsole, 10);
                    cout<<"   3";
                    if(timp<=2)
                    {
                        SetConsoleTextAttribute(hConsole, 13);
                        cout<<"   2";
                        if(timp<=1)
                        {
                            SetConsoleTextAttribute(hConsole, 12);
                            cout<<"   1";
                        }
                    }
                }
            }
        }
        cout<<'\n';
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"                         ";
        cout<<(char) 201;
        for(i=1; i<=30; ++i)
            cout<<(char) 205;
        cout<<(char) 187;
        cout<<'\n';
        cout<<"                         ";
        cout<<(char) 186;
        SetConsoleTextAttribute(hConsole, 12);
        ip=(90-timp)/3;
        ipp=ip;
        if(ip!=0)
        {
            while(ip!=0)
            {
                if(timp>60)
                    SetConsoleTextAttribute(hConsole, 14);
                else if(timp>30)
                    SetConsoleTextAttribute(hConsole, 10);
                else if(timp>=0)
                    SetConsoleTextAttribute(hConsole, 12);
                cout<<(char) 219;
                ip--;
            }
        }
        for(int s=1; s<=30-ipp; ++s)
            cout<<" ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<(char) 186<<'\n';
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"                         ";
        cout<<(char) 200;
        for(i=1; i<=30; ++i)
            cout<<(char) 205;
        cout<<(char) 188;
        cout<<'\n';
        SetConsoleTextAttribute(hConsole, 4);
        if(timp<=60)
            cout<<"                                  30|  ";
        if(timp<=30)
            cout<<"       |60";
        cout<<'\n';
        cout<<"                                     ";
        SetConsoleTextAttribute(hConsole, 10);
        for(int s=1; s<=nivel; s++)
            cout<<(char) 219<<" ";
        cout<<'\n';
        SetConsoleTextAttribute(hConsole, 14);
        cout<<"           "<<lang[105]<<":"<<total<<'\n'<<'\n';
        SetConsoleTextAttribute(hConsole, 10);
        cout<<"           "<<lang[106]<<":"<<nivel<<'\n';
        if(total==40 || total==100 || total==150 || total==200)
            nivel++;
        SetConsoleTextAttribute(hConsole, 12);
        SetConsoleTextAttribute(hConsole, 12);
        if(total>=320 && total<350)
            cout<<"                                       "<<lang[62]<<": x2";
        else if(total>=350)
            cout<<"                                       "<<lang[62]<<": x3";
        cout<<'\n';
        cout<<"           "<<lang[107]<<":"<<timp;
        SetConsoleTextAttribute(hConsole, 15);
        cout<<'\n'<<'\n';
        if(timp<=0)
            break;
    }
    system("cls");
    if(timp<0)
        timp=0;
    if(timp==0)
    {
        for(i=1; i<=2; ++i)
            cout<<'\n';
        cout<<"                                    "<<lang[108]<<'\n'<<'\n';
        Sleep(250);
    }
    else
    {
        for(i=1; i<=2; ++i)
            cout<<'\n';
        cout<<"                                  "<<lang[109]<<'\n'<<'\n';
        Sleep(250);
    }
    cout<<'\n'<<'\n';
    cout<<"                                ";
    for(i=1; i<=18; i++)
        cout<<(char) 205;
    SetConsoleTextAttribute(hConsole, 10);
    cout<<'\n'<<"                                "<<"  "<<lang[110]<<"  "<<(char) 186<<"  ";
    if(total<100)
        cout<<" ";
    cout<<total;
    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n'<<"                                ";
    for(i=1; i<=18; i++)
        cout<<(char) 205;
    Sleep(150);
    SetConsoleTextAttribute(hConsole, 11);
    cout<<'\n'<<"                                "<<"  "<<lang[111]<<"  "<<(char) 186<<"  "<<nivel<<"/5";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n'<<"                                ";
    for(i=1; i<=18; i++)
        cout<<(char) 205;
    Sleep(150);
    SetConsoleTextAttribute(hConsole, 9);
    cout<<'\n'<<"                                "<<"  "<<lang[112]<<"   "<<(char) 186<<" ";
    if((60-timp)<10)
        cout<<" ";
    cout<<90-timp<<"/90";
    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n'<<"                                ";
    int timpul=0;
    timpul=(90-timp)/18;
    if(timpul==0)
        timpul=1;
    total2=(total*nivel)*timpul;
    for(i=1; i<=18; i++)
        cout<<(char) 205;
    Sleep(150);
    SetConsoleTextAttribute(hConsole, 13);
    cout<<'\n'<<"                                "<<" "<<lang[62]<<" "<<(char) 186<<"  ";
    if(total<320)
        cout<<" -";
    else if(total>=320 && total<350)
    {
        total2=total2*2;
        cout<<" x2";
    }
    else
    {
        total2=total2*3;
        cout<<" x3";
    }
    SetConsoleTextAttribute(hConsole, 15);

    if(timp==0)
    {
        cout<<'\n'<<"                                ";
        for(i=1; i<=18; i++)
            cout<<(char) 205;
        Sleep(150);
        SetConsoleTextAttribute(hConsole, 12);
        cout<<'\n'<<"                                "<<"  "<<lang[68]<<"  "<<(char) 186<<"   x2";
        SetConsoleTextAttribute(hConsole, 15);
        total2=total2*2;
    }
    cout<<'\n'<<"                                ";
    for(i=1; i<=18; i++)
        cout<<(char) 205;
    Sleep(150);
    SetConsoleTextAttribute(hConsole, 14);
    cout<<'\n'<<"                                "<<"  "<<lang[69]<<"  "<<(char) 186<<"  "<<total2;
    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n'<<"                                ";
    for(i=1; i<=18; i++)
        cout<<(char) 205;
    primibani=banutijoc;
    banutijoc+=total2;
    baniinainte=total2;
    banutiinceput(2);
    for(i=1; i<=3; ++i)
        cout<<'\n';
    //Sleep(200);
    SetConsoleTextAttribute(hConsole, 3);
    cout<<"   <- "<<lang[21];
    SetConsoleTextAttribute(hConsole, 15);
    cout<<'\n'<<'\n';
    joc=0;
    int valu=500;
    for(i=1; i<=valu; ++i)
    {
        ch=getch();
        if(ch=='\r')
            valu=1;
        else
            valu++;
    }
    system("cls");
    seadaugabani=1;
    for(i=1; i<=400; ++i)
    {
        ka[i]=0;
        bloc[i]=0;
        alegere[i]=0;
        for(j=1; j<=5; ++j)
            nor[j][i]=0;
    }
    pa=0;
    sfarsit=0;
    total=0;
    retin=0;
    stalon=0;
    nivel=1;
    meniu(0);
}
void inregistraresaulogare2(int o)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
    system("cls");
    cout<<'\n'<<'\n'<<'\n'<<"   --";
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"+"<<'\n';
    SetConsoleTextAttribute(hConsole, 7);
    cout<<"   |";
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"El";
    SetConsoleTextAttribute(hConsole, 7);
    cout<<""<<'\n'<<"   ---"<<'\n';
    for(int i=1; i<=3; ++i)
        cout<<'\n';
    SetConsoleTextAttribute(hConsole, 14);
    if(o!=1)
        SetConsoleTextAttribute(hConsole, 10);
    cout<<"                          |-/------------------/-|"<<'\n'<<'\n';
    if(o==1)
    {
        cout<<"                          |  ";
        SetConsoleTextAttribute(hConsole, 3);
        cout<<">> "<<lang[4]<<" <<";
        SetConsoleTextAttribute(hConsole, 14);
        cout<<"  |";
    }
    else
    {
        cout<<"                          |     ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<lang[4];
        SetConsoleTextAttribute(hConsole, 10);
        cout<<"     |";
    }
    cout<<'\n'<<'\n';
    if(o==2)
    {
        cout<<"                          |  ";
        SetConsoleTextAttribute(hConsole, 3);
        cout<<">> "<<lang[1]<<" <<";
        SetConsoleTextAttribute(hConsole, 10);
        cout<<"  |";
    }
    else
    {
        cout<<"                          |     ";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<lang[1];
        SetConsoleTextAttribute(hConsole, 14);
        cout<<"     |";
    }
    cout<<'\n'<<'\n';
    if(o!=1)
        SetConsoleTextAttribute(hConsole, 10);
    cout<<"                          |-/------------------/-|";
    for(int i=1; i<=5; ++i)
        cout<<'\n';
    SetConsoleTextAttribute(hConsole, 7);
    cout<<'\n';
    cout<<" "<<lang[6]<<" "<<version<<'\n'<<'\n';
    cout<<" "<<lang[113]<<"";
    cout<<"                                              ";
    SetConsoleTextAttribute(hConsole, 240);
    cout<<"® Moldovan Catalin   "<<'\n';
    SetConsoleTextAttribute(hConsole, 7);
    //cout<<" "<<(char) 006<<" Ekon LPlus 2013 - 2016                                             ";
    cout<<" Ekon LPlus 2013 - 2016                                              ";
    SetConsoleTextAttribute(hConsole, 15);
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    cout<<  now->tm_mday<<'/';
    cout<< (now->tm_mon + 1) << '/';
    cout << (now->tm_year + 1900);
    cout<<'\n';
}
void inregistraresaulogare()
{
    inregistraresaulogare2(1);
    int inapoi=0,o=1,opop=1000;
    for(i=1; i<=opop; ++i)
    {
        ch=getch();
        if(ch!='\r')
        {
            ch=getch();
            if(ch=='H')
                o--;
            else    if(ch=='P')
                o++;
        }
        else
            inapoi=1;
        int ups=0;
        if(inapoi==1)
        {
            if(o==1)
            {
                inreglog=1;
                break;
            }
            else if(o==2)
            {
                inreglog=2;
                break;
            }
            inapoi=0;
            o=0;
        }
        else
        {
            if(o<1)
            {
                //o=1;
                //ups=1;
                o=2;
            }
            if(o>2)
            {
                //o=2;
                //ups=1;
                o=1;
            }
            if(ups==0)
                inregistraresaulogare2(o);
        }
    }
}
int main()
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
    int i=1;
        while(!en.eof())
    {
        en.get(enlang[i],1000);
        if(i<10)
            strcpy(enlang[i],enlang[i]+2);
        else if(i<100)
            strcpy(enlang[i],enlang[i]+3);
        else
            strcpy(enlang[i],enlang[i]+4);
        en.get();
        i++;
    }
    i=1;
    while(!ro.eof())
    {
        ro.get(rolang[i],1000);
        if(i<10)
            strcpy(rolang[i],rolang[i]+2);
        else if(i<100)
            strcpy(rolang[i],rolang[i]+3);
        else
            strcpy(rolang[i],rolang[i]+4);
        ro.get();
        i++;
    }
    liniilang=i-1;
     for(i=1; i<=liniilang; ++i)
            strcpy(lang[i],rolang[i]);
    int k=1,p=1,intrare=0,nup=0;
    i=20;
    int inceputbanuti=1;
    inregistraresaulogare();
    system("cls");
    if(inreglog==1)
        inregistrare();
    else
    {
        logare();
        if(num==1 && par==1)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout<<'\n'<<'\n'<<'\n'<<"                                  "<<lang[114];
            Sleep(700);
            inceput();
            banutiinceput(1);
            inceputbanuti=2;
            meniu(1);
            for(i=1; i<=iesi; ++i)
            {
                ch=getch();
                if(ch!='\r')
                {
                    if(nup==0)
                    {
                        ch=getch();
                        if(ch=='H')
                            k--;
                        if(ch=='P')
                            k++;
                        if(ch=='K')
                        {
                            k=8;
                            nup=1;
                        }
                        if(nup==0)
                            p=k;
                    }
                    else if(ch=='M')
                    {
                        k=p;
                        nup=0;
                    }
                }
                else
                    intrare=1;
                int ups=0;
                if(intrare==1)
                {
                    if(k==8)
                    {
                        lotto();
                        nup=0;
                    }

                    if(k==1)
                        creeazaharta();
                    else if(k==2)
                        incepeunjocaleatoriu();
                    else if(k==3)
                        thrown();
                    else if(k==4)
                        scor();
                    else if(k==5)
                        instructiuni();
                    else if(k==6)
                        iesire();
                    intrare=0;
                    k=0;
                }
                else
                {
                    if(k<1)
                    {
                        //k=1;
                        //ups=1;
                        k=6;
                    }
                    if(k>6 && k!=8)
                    {
                        //k=6;
                        //ups=1;
                        k=1;
                    }

                    if(ups==0)
                        meniu(k);
                }
            }
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout<<'\n'<<'\n'<<'\n'<<"                          "<<lang[115];
            Sleep(700);
            system("cls");
            inreglog=1;
        }
    }
    if(inreglog==1)
        system ("EL+.exe");
}
