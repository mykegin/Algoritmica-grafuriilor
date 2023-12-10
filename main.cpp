#include <iostream>
#include <winbgim.h>


using namespace std;

void MainMenu();
void meniuGrafN();
void meniuGrafO();

void resetmatrix(int a[505][505],int n)
{
    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            a[i][j]=0;
}

int xbutGN,ybutGN,xbutGO,ybutGO;
int ct,R=20,MatriceAdiac[505][505],butonas;
int rx,ry=100;
int consolex=17,consoley=95;


struct nod
{
    int x,y;
    int val;

} a[505];

void GNButtons() /// aceasta fucntie inregistreaza fiecare apasatura a mousului si toate butoanele posibile de pe o pagina cu GN
{
    int x,y;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        ///cout<<x<<" "<<y;

        if(x>=0 && x<=100 && y>=0 && y<=40)
        {
            butonas=0;
            MainMenu();
        }

        if(x>=0 && x<=130 && y>=40 && y<=80)
        {
            butonas=0;
            meniuGrafO();
        }

        if(x>=220 && x<=385 && y>=710 && y<=735)///activare buton creare muchii
            if(butonas!=3)
            {
                butonas=3;
                ///cout<<butonas<<" ";
            }

        if(x>=447 && x<=612 && y>=710 && y<=735)///activare buton stergere muchii
            if(butonas!=4)
            {
                butonas=4;
                ///cout<<butonas<<" ";
            }

        if(x>=653 && x<=818 && y>=710 && y<=735)///activare buton creare nod
            if(butonas!=1)
            {
                butonas=1;
                ///cout<<butonas<<" ";
            }

        if(x>=880 && x<=1045 && y>=710 && y<=735)///activare buton stergere nod
            if(butonas!=2)
            {
                butonas=2;
                cout<<butonas<<" ";
            }

        if(x>=1086 && x<=1251 && y>=710 && y<=735)///activare buton creare cost
            if(butonas!=5)
            {
                butonas=5;
                ///cout<<butonas<<" ";
            }

        if(x>=1313 && x<=1478 && y>=710 && y<=735)///activare buton stergere cost
            if(butonas!=6)
            {
                butonas=6;
                ///cout<<butonas<<" ";
            }

        if(x>=225 && x<=1175 && y>=105 && y<=625)
            if(butonas==1)
            {
                ct++;
                a[ct].x=x;
                a[ct].y=y;
                if(ct==10) R+=4;
                if(ct==100) R+=5;
                setcolor(BLACK);
                circle(x,y,R);
                setfillstyle(SOLID_FILL,COLOR(17,19,58));
                floodfill(x,y,BLACK);
                setcolor(WHITE);
                char nr[5];
                sprintf(nr,"%d",ct);
                if(ct>=100)  outtextxy(x-15, y-10,nr);
                else if(ct>=10) outtextxy(x-11, y-10,nr);
                else outtextxy(x-7, y-10,nr);
            }

        if(x>=447 && x<=612 && y>=710 && y<=735)
        {
            int m1=0,m2=0;

            char str[1];
            rx = 20;
            str[1]=0;
            str[0]=getch();
            m1=str[0]-'0';
            setbkcolor(DARKGRAY);
            outtextxy(rx, ry,str);
            setbkcolor(COLOR(17,19,58));

            rx+=40;
            str[0]=getch();
            m2=str[0]-'0';
            setbkcolor(DARKGRAY);
            outtextxy(rx, ry,str);
            setbkcolor(COLOR(17,19,58));
            ry+=30;

            if(m1<=ct && m2<=ct )
            {
                MatriceAdiac[m1][m2]=0;
                setcolor(WHITE);
                line(a[m1].x,a[m1].y,a[m2].x,a[m2].y);
            }
        }

        if(x>=220 && x<=385 && y>=710 && y<=735)
        {
            int m1,m2,nou;
            char sir[105];
            int k=0;
            consolex=17;
            consoley+=25;
            char var=getch();
            while(var!=13)
            {
                if(var>='0' && var<='9' || var==32)
                {
                    sir[k++]=var;
                    char str[2];
                    str[0]=var;
                    str[1]=0;
                    setbkcolor(DARKGRAY);
                    outtextxy(consolex-15, consoley-15,str);
                    setbkcolor(COLOR(17,19,58));
                    consolex+=15;
                    if(consolex>200)
                    {
                        consoley+=25;
                        consolex=17;
                    }
                }
                if(var==8)
                {
                    sir[--k]=0;
                    sir[k]=0;
                    if(consolex-17>0) consolex-=15;
                    else
                    {
                        consoley-=25;
                        consolex=197;
                    }
                    setfillstyle(SOLID_FILL,DARKGRAY);
                    setcolor(LIGHTGRAY);
                    rectangle(consolex-15,consoley-15,consolex,consoley);
                    floodfill(consolex-5,consoley-5,LIGHTGRAY);
                    setcolor(WHITE);
                }
                var=getch();
            }
            sir[k]=0;
            m1=m2=nou=0;

            char *p,sep[]=" ",aux[105];
            p=strtok(sir,sep);
            while(p!=0)
            {
                nou=0;
                strcpy(aux,p);
                for(int i=0; i<strlen(aux); i++)
                    nou=nou*10+(aux[i]-48);
                if(m1==0 && m2==0) m1=nou;
                else if(m2==0) m2=nou;
                p=strtok(0,sep);
            }

            if(m1<=ct && m2<=ct && m1!=0 && m2!=0)
            {
                MatriceAdiac[m1][m2]=1;
                setcolor(COLOR(17,19,58));
                line(a[m1].x,a[m1].y,a[m2].x,a[m2].y);
                setcolor(WHITE);
            }
        }
    }
}


void meniuGrafN() /// aceasta functie genereaza de fiecare data o pagina in care se prelugreaza grafuri neorientate
{
    int x,y;
    ry=100;
    cleardevice();

    resetmatrix(MatriceAdiac,ct);
    ct=0;
    rectangle(0,0,130,40);/// mmenu but

    char titlu[50]="MMenu";
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(10,10,titlu);

    rectangle(0,40,130,80); /// refresh but
    strcpy(titlu,"REFRESH");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(10,50,titlu);

    rectangle(130, 0, 1499, 80);/// topbar

    rectangle(200, 650, 1499, 749);///bottom bar


    setfillstyle(SOLID_FILL,DARKGRAY);
    rectangle(0, 80, 200, 749);/// consola
    floodfill(5,85,WHITE);


    strcpy(titlu,"OPERATII MUCHII");///titlu muchii
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(300,665,titlu);


    rectangle(220,710,385,735);///adugare muchie

    strcpy(titlu,"adauga muchie");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(225,712,titlu);

    rectangle(447, 710, 612, 735);///stergere muchie

    strcpy(titlu,"sterge muchie");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(458,712,titlu);


    line(633,650,633,749); /// linie stanga jos


    strcpy(titlu,"OPERATII NODURI");///titlu muchii
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(735,665,titlu);

    rectangle(653,710,818,735);///adugare nod

    strcpy(titlu,"adauga nod");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(675,712,titlu);

    rectangle(880, 710, 1045, 735);///stergere nod

    strcpy(titlu,"sterge nod");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(909,712,titlu);

    line(1066,650,1066,749);  /// linie dreapta jos


    strcpy(titlu,"OPERATII COSTURI");///titlu costuri
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1170,665,titlu);

    rectangle(1086,710,1251,735);///adugare cost

    strcpy(titlu,"adauga cost");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1110,712,titlu);

    rectangle(1313, 710, 1478, 735);///stergere cost

    strcpy(titlu,"sterge cost");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1340,712,titlu);

    rectangle(1200, 80, 1499, 650);///lista comenzilor
    line(1200, 150, 1499, 150);///line titlu
    strcpy(titlu,"COMENZI");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1295,110,titlu);

    line(1349, 150, 1349, 650);///linie imaginara mijloc

    rectangle(1310, 190, 1385, 230);
    strcpy(titlu,"DFS");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1325,200,titlu);

    rectangle(1310, 250, 1385, 290);
    strcpy(titlu,"BFS");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1325,260,titlu);

    rectangle(1250, 310, 1450, 350);
    strcpy(titlu,"CONEXITATE");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1270,320,titlu);

    rectangle(1250, 370, 1450, 410);
    strcpy(titlu,"COMPONENTE");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1265,380,titlu);

    rectangle(1280, 430, 1425, 470);
    strcpy(titlu,"DIJKSTRA");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1295,440,titlu);

    /*strcpy(titlu,"COMENZI");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1295,110,titlu);*/

    setfillstyle(SOLID_FILL,WHITE);
    rectangle(200, 80, 1200, 650); /// play board
    floodfill(205, 85, WHITE);




    bool gata=0;
    do
    {
        GNButtons();
    }
    while(!gata);
}

void GOButtons() /// aceasta functie inregistreaza toate apasaturile de mouse si toate butoanele posibile de pe o pagina cu GO
{
    int x,y,m,n;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        ///cout<<x<<" "<<y;

        if(x>=0 && x<=100 && y>=0 && y<=40)
        {
            butonas=0;
            MainMenu();
        }

        if(x>=0 && x<=130 && y>=40 && y<=80)
        {
            butonas=0;
            meniuGrafO();
        }

        if(x>=220 && x<=385 && y>=710 && y<=735)///activare buton creare muchii
            if(butonas!=3)
            {
                butonas=3;
                ///cout<<butonas<<" ";
            }

        if(x>=447 && x<=612 && y>=710 && y<=735)///activare buton stergere muchii
            if(butonas!=4)
            {
                butonas=4;
                ///cout<<butonas<<" ";
            }

        if(x>=653 && x<=818 && y>=710 && y<=735)///activare buton creare nod
            if(butonas!=1)
            {
                butonas=1;
                ///cout<<butonas<<" ";
            }

        if(x>=880 && x<=1045 && y>=710 && y<=735)///activare buton stergere nod
            if(butonas!=2)
            {
                butonas=2;
                cout<<butonas<<" ";
            }

        if(x>=1086 && x<=1251 && y>=710 && y<=735)///activare buton creare cost
            if(butonas!=5)
            {
                butonas=5;
                ///cout<<butonas<<" ";
            }

        if(x>=1313 && x<=1478 && y>=710 && y<=735)///activare buton stergere cost
            if(butonas!=6)
            {
                butonas=6;
                ///cout<<butonas<<" ";
            }

        if(x>=225 && x<=1175 && y>=105 && y<=625)
            if(butonas==1)
            {
                ct++;
                a[ct].x=x;
                a[ct].y=y;
                if(ct==10) R+=4;
                if(ct==100) R+=5;
                setcolor(BLACK);
                circle(x,y,R);
                setfillstyle(SOLID_FILL,COLOR(17,19,58));
                floodfill(x,y,BLACK);
                setcolor(WHITE);
                char nr[5];
                sprintf(nr,"%d",ct);
                if(ct>=100)  outtextxy(x-15, y-10,nr);
                else if(ct>=10) outtextxy(x-11, y-10,nr);
                else outtextxy(x-7, y-10,nr);
            }

        if(x>=447 && x<=612 && y>=710 && y<=735)
            if(butonas==4)
        {
            int m1=0,m2=0;

            char str[1];
            rx = 20;
            str[1]=0;
            str[0]=getch();
            m1=str[0]-'0';
            setbkcolor(DARKGRAY);
            outtextxy(rx, ry,str);
            setbkcolor(COLOR(17,19,58));

            rx+=40;
            str[0]=getch();
            m2=str[0]-'0';
            setbkcolor(DARKGRAY);
            outtextxy(rx, ry,str);
            setbkcolor(COLOR(17,19,58));
            ry+=30;

            if(m1<=ct && m2<=ct )
            {
                MatriceAdiac[m1][m2]=0;
                setcolor(WHITE);
                line(a[m1].x,a[m1].y,a[m2].x,a[m2].y);
            }
        }

        if(x>=220 && x<=385 && y>=710 && y<=735)
            if(butonas==3)
        {
            int m1,m2,nou;
            char sir[105];
            int k=0;
            consolex=17;
            consoley+=25;
            char var=getch();
            while(var!=13)
            {
                if(var>='0' && var<='9' || var==32)
                {
                    sir[k++]=var;
                    char str[2];
                    str[0]=var;
                    str[1]=0;
                    setbkcolor(DARKGRAY);
                    outtextxy(consolex-15, consoley-15,str);
                    setbkcolor(COLOR(17,19,58));
                    consolex+=15;
                    if(consolex>200)
                    {
                        consoley+=25;
                        consolex=17;
                    }
                }
                if(var==8)
                {
                    sir[--k]=0;
                    sir[k]=0;
                    if(consolex-17>0) consolex-=15;
                    else
                    {
                        consoley-=25;
                        consolex=197;
                    }
                    setfillstyle(SOLID_FILL,DARKGRAY);
                    setcolor(LIGHTGRAY);
                    rectangle(consolex-15,consoley-15,consolex,consoley);
                    floodfill(consolex-5,consoley-5,LIGHTGRAY);
                    setcolor(WHITE);
                }
                var=getch();
            }
            sir[k]=0;
            m1=m2=nou=0;

            char *p,sep[]=" ",aux[105];
            p=strtok(sir,sep);
            while(p!=0)
            {
                nou=0;
                strcpy(aux,p);
                for(int i=0; i<strlen(aux); i++)
                    nou=nou*10+(aux[i]-48);
                if(m1==0 && m2==0) m1=nou;
                else if(m2==0) m2=nou;
                p=strtok(0,sep);
            }

            if(m1<=ct && m2<=ct && m1!=0 && m2!=0)
            {
                MatriceAdiac[m1][m2]=1;
                setcolor(COLOR(17,19,58));
                line(a[m1].x,a[m1].y,a[m2].x,a[m2].y);
                setcolor(WHITE);
            }
        }
    }
}


void meniuGrafO() ///aceasta functie genereaza de fiecare data o pagina in care se prelucreaza grafuri orientate
{
    int x,y;
    ry=100;
    cleardevice();

    resetmatrix(MatriceAdiac,ct);
    ct=0;

    rectangle(0,0,130,40);/// mmenu but

    char titlu[50]="MMenu";
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(10,10,titlu);

    rectangle(0,40,130,80); /// refresh but
    strcpy(titlu,"REFRESH");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(10,50,titlu);

    rectangle(130, 0, 1499, 80);/// topbar

    rectangle(200, 650, 1499, 749);///bottom bar


    setfillstyle(SOLID_FILL,DARKGRAY);
    rectangle(0, 80, 200, 749);/// consola
    floodfill(5,85,WHITE);


    strcpy(titlu,"OPERATII MUCHII");///titlu muchii
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(300,665,titlu);


    rectangle(220,710,385,735);///adugare muchie

    strcpy(titlu,"adauga muchie");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(225,712,titlu);

    rectangle(447, 710, 612, 735);///stergere muchie

    strcpy(titlu,"sterge muchie");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(458,712,titlu);


    line(633,650,633,749); /// linie stanga jos


    strcpy(titlu,"OPERATII NODURI");///titlu noduri
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(735,665,titlu);

    rectangle(653,710,818,735);///adugare nod

    strcpy(titlu,"adauga nod");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(675,712,titlu);

    rectangle(880, 710, 1045, 735);///stergere nod

    strcpy(titlu,"sterge nod");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(909,712,titlu);

    line(1066,650,1066,749);  /// linie dreapta jos


    strcpy(titlu,"OPERATII COSTURI");///titlu costuri
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1170,665,titlu);

    rectangle(1086,710,1251,735);///adugare cost

    strcpy(titlu,"adauga cost");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1110,712,titlu);

    rectangle(1313, 710, 1478, 735);///stergere cost

    strcpy(titlu,"sterge cost");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1340,712,titlu);

    rectangle(1200, 80, 1499, 650);///lista comenzilor
    line(1200, 150, 1499, 150);///line titlu
    strcpy(titlu,"COMENZI");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1295,110,titlu);

    line(1349, 150, 1349, 650);///linie imaginara mijloc

    rectangle(1310, 190, 1385, 230);
    strcpy(titlu,"DFS");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1325,200,titlu);

    rectangle(1310, 250, 1385, 290);
    strcpy(titlu,"BFS");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1325,260,titlu);

    rectangle(1250, 310, 1450, 350);
    strcpy(titlu,"CONEXITATE");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1270,320,titlu);

    rectangle(1250, 370, 1450, 410);
    strcpy(titlu,"COMPONENTE");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1265,380,titlu);

    rectangle(1280, 430, 1425, 470);
    strcpy(titlu,"DIJKSTRA");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1295,440,titlu);

    /*strcpy(titlu,"COMENZI");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    outtextxy(1295,110,titlu);*/

    setfillstyle(SOLID_FILL,WHITE);
    rectangle(200, 80, 1200, 650); /// play board
    floodfill(205, 85, WHITE);

    bool gata=0;
    do
    {
        GOButtons();
    }
    while(!gata);
}

void MainButtons() /// aceasta funtie inregistreaza fiecare apasatura de mouse si toate butoanele posibile de pe pagina main
{
    int x,y;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        if(x>=xbutGN-500 && x<=xbutGN-150 && y>=ybutGN+100 && ybutGN+200)
            meniuGrafN();
        if(x>=xbutGO+150 && x<=xbutGO+500 && y>=ybutGO+100 && y<=ybutGO+200)
            meniuGrafO();
    }
}

void MainMenu() ///aici genereaza de fiecare data cand este apelata functia o pagina de tip main menu
{
    cleardevice();
    int mx,my;
    mx=getmaxx();
    my=getmaxy();

    int midx=mx/2;
    int midy=my/2;
    ///cout<<midx<<" "<<midy;
    ///line(midx,0,midx,my);
    ///line (0,midy,mx,midy);
    xbutGN=midx;
    ybutGN=midy;
    xbutGO=midx;
    ybutGO=midy;
    rectangle(xbutGN-500,ybutGN+100,xbutGN-150,ybutGN+200);

    char titlu[50]="Graf Neorientat";
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 4);
    outtextxy(xbutGN-470,ybutGN+130,titlu);

    rectangle(xbutGO+150,ybutGO+100,xbutGO+500,ybutGO+200);

    strcpy(titlu,"Graf Orientat");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 4);
    outtextxy(xbutGN+210,ybutGN+130,titlu);

    strcpy(titlu,"Proiect");
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 4);
    outtextxy(midx-60,100,titlu);

    bool gata=0;
    do
    {
        MainButtons();///fiecare buton posibil
    }
    while(!gata);

}


int main()
{
    initwindow(1500,750);
    setbkcolor(COLOR(17,19,58));
    clearviewport();
    MainMenu();
    closegraph();
    cout<<butonas;
    return 0;
}
