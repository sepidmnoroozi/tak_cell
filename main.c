#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "d.h"

/*struct block{
    int energy;
    char type;
};
struct cell{
    int shomare_block_cell;
    int energy;
};

*/
void gotoxy(int x,int y)
{
 COORD pos;
 HANDLE hConsole = GetStdHandle ( STD_OUTPUT_HANDLE );

 if (INVALID_HANDLE_VALUE != hConsole)
 {
 pos.X = x;
 pos.Y = y;

 SetConsoleCursorPosition( hConsole, pos );
 }
}
/*void chap_block(int x, int y,char c,int chape_x)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int i,j;
    int k;
    if(c==1)
        k=169;
    else if(c==2)
        k=233;
    else if(c==3)
        k=201;
    else if(c==4)
        k=185;
    for(j=0;j<3;j++)
    {
        gotoxy(x,y);
        for(i=0;i<5;i++)
        {
            SetConsoleTextAttribute(hConsole,k);
            printf(" ");
        }
        y++;
    }
    if(chape_x==0 && c!=3)
    {
        gotoxy(x+2,y-2);
        printf("X");
    }
}

void chap_jadval(int width,int height,struct block arr[height*width],int tedad_cell_karbar,int arr_tasadofi[tedad_cell_karbar],int arr_por_khali[height*width])
{
    int i,j;
    int x=3;
    for(j=0;j<height;j++)
    {
        for(i=0;i<width;i++)
        {
            if(i%2==0)
            {
                int d;
                if(arr[x].type=='1')
                    d=1;
                else if(arr[x].type=='2')
                    d=2;
                else if(arr[x].type=='3')
                    d=3;
                else
                    d=4;
                chap_block(i*6,j*4,d,check_chap_x(tedad_cell_karbar,arr_tasadofi,x));
                if(check_chap_x(tedad_cell_karbar,arr_tasadofi,x)==0)
                    arr_por_khali[x]=0;
                x+=4;
            }
            else
            {
                int d;
                if(arr[x].type=='1')
                    d=1;
                else if(arr[x].type=='2')
                    d=2;
                else if(arr[x].type=='3')
                    d=3;
                else
                    d=4;
                chap_block(i*6,j*4+1,d,check_chap_x(tedad_cell_karbar,arr_tasadofi,x));
                if(check_chap_x(tedad_cell_karbar,arr_tasadofi,x)==0)
                    arr_por_khali[x]=0;
                x+=4;
            }
        }
        x-=17;

    }
}

void rahnama(int height,int width)
{
    chap_block(width+30,0,1,1);
    gotoxy(width+35,1);
    printf("energy");
    chap_block(width+30,4,2,1);
    gotoxy(width+35,5);
    printf("split");
    chap_block(width+30,8,3,1);
    gotoxy(width+35,9);
    printf("lock");
    chap_block(width+30,12,4,1);
    gotoxy(width+35,13);
    printf("normal");
}

int check_chap_x(int tedad_cell_karbar,int arr_tasadofi[tedad_cell_karbar],int shomare_block)
{
    int i;
    for(i=0;i<tedad_cell_karbar;i++)
    {
        if(arr_tasadofi[i]==shomare_block)
            return 0;// yani inja hast
    }
    return 1; //yani nist inja
}

int move_cell_sing(int height,int width,struct block arr[height*width],int shomare_cell_move,int jahat,int arr_por_khali[height*width],int tedad_cell_karbar,int arr_tasadofi[tedad_cell_karbar],struct cell * arr_cell)
{

    if(jahat==1)
    {
        if(arr[shomare_cell_move+1].type=='3')
            return 1;
        int andiss=andis(tedad_cell_karbar,arr_tasadofi,shomare_cell_move);
        arr_tasadofi[andiss]=shomare_cell_move+1;
        int i;
        for(i=0;i<tedad_cell_karbar;i++)
        {
            if(arr_cell[i].shomare_block_cell==shomare_cell_move)
            {
                arr_cell[i].shomare_block_cell=shomare_cell_move+1;
                break;
            }
        }
        arr_por_khali[shomare_cell_move]=-1;
        if(arr_por_khali[shomare_cell_move+1]!=-1)
        {
            return 1;
        }
        if(shomare_cell_move+1>=0 && shomare_cell_move+1<16)
        {
            arr_por_khali[shomare_cell_move+1]=0;
        }
    }
    else if(jahat==2)
    {
        if(arr[shomare_cell_move-1].type=='3')
            return 1;
        int andiss=andis(tedad_cell_karbar,arr_tasadofi,shomare_cell_move);
        arr_tasadofi[andiss]=shomare_cell_move-1;
        int i;
        for(i=0;i<tedad_cell_karbar;i++)
        {
            if(arr_cell[i].shomare_block_cell==shomare_cell_move)
            {
                arr_cell[i].shomare_block_cell=shomare_cell_move-1;
                break;
            }
        }
        arr_por_khali[shomare_cell_move]=-1;
        if(arr_por_khali[shomare_cell_move-1]!=-1)
        {
            return 1;
        }
        if(shomare_cell_move-1>=0 && shomare_cell_move-1<16 && arr_por_khali[shomare_cell_move-1]==-1)
        {
            arr_por_khali[shomare_cell_move-1]=0;
        }

    }
    else if(jahat==3)
    {
        if(arr[shomare_cell_move+4].type=='3')
            return 1;
        int andiss=andis(tedad_cell_karbar,arr_tasadofi,shomare_cell_move);
        arr_tasadofi[andiss]=shomare_cell_move+4;
        int i;
        for(i=0;i<tedad_cell_karbar;i++)
        {
            if(arr_cell[i].shomare_block_cell==shomare_cell_move)
            {
                arr_cell[i].shomare_block_cell=shomare_cell_move+4;
                break;
            }
        }
        arr_por_khali[shomare_cell_move]=-1;
        if(arr_por_khali[shomare_cell_move+4]!=-1)
        {
            return 1;
        }
        if(shomare_cell_move+4>=0 && shomare_cell_move+4<16 && arr_por_khali[shomare_cell_move+4]==-1)
        {
            arr_por_khali[shomare_cell_move+4]=0;
        }
    }
    else if(jahat==4)
    {
        if(arr[shomare_cell_move-4].type=='3')
            return 1;
        int andiss=andis(tedad_cell_karbar,arr_tasadofi,shomare_cell_move);
        arr_tasadofi[andiss]=shomare_cell_move-4;
        int i;
        for(i=0;i<tedad_cell_karbar;i++)
        {
            if(arr_cell[i].shomare_block_cell==shomare_cell_move)
            {
                arr_cell[i].shomare_block_cell=shomare_cell_move-4;
                break;
            }
        }
        arr_por_khali[shomare_cell_move]=-1;
        if(arr_por_khali[shomare_cell_move-4]!=-1)
        {
            return 1;
        }
        if(shomare_cell_move-4>=0 && shomare_cell_move-4<16 && arr_por_khali[shomare_cell_move-4]==-1)
        {
            arr_por_khali[shomare_cell_move-4]=0;
        }
    }
    else if(jahat==5)
    {
        if(arr[shomare_cell_move+3].type=='3')
            return 1;
        int andiss=andis(tedad_cell_karbar,arr_tasadofi,shomare_cell_move);
        arr_tasadofi[andiss]=shomare_cell_move+3;
        int i;
        for(i=0;i<tedad_cell_karbar;i++)
        {
            if(arr_cell[i].shomare_block_cell==shomare_cell_move)
            {
                arr_cell[i].shomare_block_cell=shomare_cell_move+3;
                break;
            }
        }
        arr_por_khali[shomare_cell_move]=-1;
        if(arr_por_khali[shomare_cell_move+3]!=-1)
        {
            return 1;
        }
        if(shomare_cell_move+3>=0 && shomare_cell_move+3<16 && arr_por_khali[shomare_cell_move+3]==-1)
        {
            arr_por_khali[shomare_cell_move+3]=0;
        }
    }
    else if(jahat==6)
    {
        if(arr[shomare_cell_move-5].type=='3')
            return 1;
        int andiss=andis(tedad_cell_karbar,arr_tasadofi,shomare_cell_move);
        arr_tasadofi[andiss]=shomare_cell_move-5;
        int i;
        for(i=0;i<tedad_cell_karbar;i++)
        {
            if(arr_cell[i].shomare_block_cell==shomare_cell_move)
            {
                arr_cell[i].shomare_block_cell=shomare_cell_move-5;
                break;
            }
        }
        arr_por_khali[shomare_cell_move]=-1;
        if(arr_por_khali[shomare_cell_move-5]!=-1)
        {
            return 1;
        }
        if(shomare_cell_move-5>=0 && shomare_cell_move-5<16 && arr_por_khali[shomare_cell_move-5]==-1)
        {
            arr_por_khali[shomare_cell_move-5]=-0;
        }
    }

}

int andis(int tedad_cell_karbar,int arr_tasadofi[tedad_cell_karbar],int shomare_cell_move)
{
    int i;
    for(i=0;i<tedad_cell_karbar;i++)
    {
        if(arr_tasadofi[i]==shomare_cell_move)
            return i;
    }
}

void jadval_energy_block(int height,int width,struct block arr[height*width])
{
    gotoxy(0,height+30);
    int i;
    for(i=0;i<height*width;i++)
    {
        printf("energy khoone shomare %d = %d\n",i,arr[i].energy);
    }
}

int split_cell_sing(int shomare_cell_split,int height,int width,struct block arr[height*width],int arr_por_khali[height*width],int tedad_cell_karbar,int * arr_tasadofi2,int *arr_tasadofi, struct cell * arr_cell,struct cell * arr_cell2)
{
    int f=1;
    while(f==1){
    time_t t=time(NULL);
    srand(t);
    int jahat_cell_split=rand() % 6;
    if(jahat_cell_split==0 && arr_por_khali[shomare_cell_split+1]==-1 && arr[shomare_cell_split+1].type!='3')
    {
        if(arr_tasadofi2==NULL)
            arr_tasadofi2=(int *)malloc((tedad_cell_karbar+1)*sizeof(int));
        else
            arr_tasadofi2=(int *)realloc(arr_tasadofi2,(tedad_cell_karbar+1)*sizeof(int));
        int i;
        for(i=0;i<tedad_cell_karbar;i++)
        {
            arr_tasadofi2[i]=arr_tasadofi[i];
        }
        arr_tasadofi2[tedad_cell_karbar]=shomare_cell_split+1;
        arr_por_khali[shomare_cell_split+1]=0;
        if(arr_cell2==NULL)
            arr_cell2=(struct cell *)malloc((tedad_cell_karbar+1)*sizeof(struct cell));
        else
            arr_cell2=(struct cell *)realloc(arr_cell,(tedad_cell_karbar+1)*sizeof(struct cell));
        for(i=0;i<tedad_cell_karbar;i++)
        {
            arr_cell2[i]=arr_cell[i];
            if(arr_cell2[i].shomare_block_cell==shomare_cell_split)
                arr_cell2[i].energy=10;
        }
        arr_cell2[tedad_cell_karbar].energy=10;
        arr_cell2[tedad_cell_karbar].shomare_block_cell=shomare_cell_split+1;
        return 0;
        f=0;
    }
    else if(jahat_cell_split==1 && arr_por_khali[shomare_cell_split+4]==-1 && arr[shomare_cell_split+4].type!='3')
    {
        if(arr_tasadofi2==NULL)
            arr_tasadofi2=(int *)malloc((tedad_cell_karbar+1)*sizeof(int));
        else
            arr_tasadofi2=(int *)realloc(arr_tasadofi2,(tedad_cell_karbar+1)*sizeof(int));
        int i;
        for(i=0;i<tedad_cell_karbar;i++)
        {
            arr_tasadofi2[i]=arr_tasadofi[i];
        }
        arr_tasadofi2[tedad_cell_karbar]=shomare_cell_split+4;
        arr_por_khali[shomare_cell_split+4]=0;
        if(arr_cell2==NULL)
            arr_cell2=(struct cell *)malloc((tedad_cell_karbar+1)*sizeof(struct cell));
        else
            arr_cell2=(struct cell *)realloc(arr_cell,(tedad_cell_karbar+1)*sizeof(struct cell));
        for(i=0;i<tedad_cell_karbar;i++)
        {
            arr_cell2[i]=arr_cell[i];
            if(arr_cell2[i].shomare_block_cell==shomare_cell_split)
                arr_cell2[i].energy=10;
        }
        arr_cell2[tedad_cell_karbar].energy=10;
        arr_cell2[tedad_cell_karbar].shomare_block_cell=shomare_cell_split+4;
        return 0;
        f=0;
    }
    else if(jahat_cell_split==2 && arr_por_khali[shomare_cell_split+3]==-1 && arr[shomare_cell_split+3].type!='3')
    {
        if(arr_tasadofi2==NULL)
            arr_tasadofi2=(int *)malloc((tedad_cell_karbar+1)*sizeof(int));
        else
            arr_tasadofi2=(int *)realloc(arr_tasadofi2,(tedad_cell_karbar+1)*sizeof(int));
        int i;
        for(i=0;i<tedad_cell_karbar;i++)
        {
            arr_tasadofi2[i]=arr_tasadofi[i];
        }
        arr_tasadofi2[tedad_cell_karbar]=shomare_cell_split+3;
        arr_por_khali[shomare_cell_split+3]=0;
        if(arr_cell2==NULL)
            arr_cell2=(struct cell *)malloc((tedad_cell_karbar+1)*sizeof(struct cell));
        else
            arr_cell2=(struct cell *)realloc(arr_cell,(tedad_cell_karbar+1)*sizeof(struct cell));
        for(i=0;i<tedad_cell_karbar;i++)
        {
            arr_cell2[i]=arr_cell[i];
            if(arr_cell2[i].shomare_block_cell==shomare_cell_split)
                arr_cell2[i].energy=10;
        }
        arr_cell2[tedad_cell_karbar].energy=10;
        arr_cell2[tedad_cell_karbar].shomare_block_cell=shomare_cell_split+3;
        return 0;
        f=0;
    }
    else if(jahat_cell_split==3 && arr_por_khali[shomare_cell_split-1]==-1 && arr[shomare_cell_split-1].type!='3')
    {
        if(arr_tasadofi2==NULL)
            arr_tasadofi2=(int *)malloc((tedad_cell_karbar+1)*sizeof(int));
        else
            arr_tasadofi2=(int *)realloc(arr_tasadofi2,(tedad_cell_karbar+1)*sizeof(int));
        int i;
        for(i=0;i<tedad_cell_karbar;i++)
        {
            arr_tasadofi2[i]=arr_tasadofi[i];
        }
        arr_tasadofi2[tedad_cell_karbar]=shomare_cell_split-1;
        arr_por_khali[shomare_cell_split-1]=0;
        if(arr_cell2==NULL)
            arr_cell2=(struct cell *)malloc((tedad_cell_karbar+1)*sizeof(struct cell));
        else
            arr_cell2=(struct cell *)realloc(arr_cell,(tedad_cell_karbar+1)*sizeof(struct cell));
        for(i=0;i<tedad_cell_karbar;i++)
        {
            arr_cell2[i]=arr_cell[i];
            if(arr_cell2[i].shomare_block_cell==shomare_cell_split)
                arr_cell2[i].energy=10;
        }
        arr_cell2[tedad_cell_karbar].energy=10;
        arr_cell2[tedad_cell_karbar].shomare_block_cell=shomare_cell_split-1;
        return 0;
        f=0;
    }
    else if(jahat_cell_split==4 && arr_por_khali[shomare_cell_split-5]==-1 && arr[shomare_cell_split-5].type!='3')
    {
        if(arr_tasadofi2==NULL)
            arr_tasadofi2=(int *)malloc((tedad_cell_karbar+1)*sizeof(int));
        else
            arr_tasadofi2=(int *)realloc(arr_tasadofi2,(tedad_cell_karbar+1)*sizeof(int));
        int i;
        for(i=0;i<tedad_cell_karbar;i++)
        {
            arr_tasadofi2[i]=arr_tasadofi[i];
        }
        arr_tasadofi2[tedad_cell_karbar]=shomare_cell_split-5;
        arr_por_khali[shomare_cell_split-5]=0;
        if(arr_cell2==NULL)
            arr_cell2=(struct cell *)malloc((tedad_cell_karbar+1)*sizeof(struct cell));
        else
            arr_cell2=(struct cell *)realloc(arr_cell,(tedad_cell_karbar+1)*sizeof(struct cell));
        for(i=0;i<tedad_cell_karbar;i++)
        {
            arr_cell2[i]=arr_cell[i];
            if(arr_cell2[i].shomare_block_cell==shomare_cell_split)
                arr_cell2[i].energy=10;
        }
        arr_cell2[tedad_cell_karbar].energy=10;
        arr_cell2[tedad_cell_karbar].shomare_block_cell=shomare_cell_split-5;
        return 0;
        f=0;
    }
    else if(jahat_cell_split==5 && arr_por_khali[shomare_cell_split-4]==-1 && arr[shomare_cell_split-4].type!='3')
    {
        if(arr_tasadofi2==NULL)
            arr_tasadofi2=(int *)malloc((tedad_cell_karbar+1)*sizeof(int));
        else
            arr_tasadofi2=(int *)realloc(arr_tasadofi2,(tedad_cell_karbar+1)*sizeof(int));
        int i;
        for(i=0;i<tedad_cell_karbar;i++)
        {
            arr_tasadofi2[i]=arr_tasadofi[i];
        }
        arr_tasadofi2[tedad_cell_karbar]=shomare_cell_split-4;
        arr_por_khali[shomare_cell_split-4]=0;
        if(arr_cell2==NULL)
            arr_cell2=(struct cell *)malloc((tedad_cell_karbar+1)*sizeof(struct cell));
        else
            arr_cell2=(struct cell *)realloc(arr_cell,(tedad_cell_karbar+1)*sizeof(struct cell));
        for(i=0;i<tedad_cell_karbar;i++)
        {
            arr_cell2[i]=arr_cell[i];
            if(arr_cell2[i].shomare_block_cell==shomare_cell_split)
                arr_cell2[i].energy=10;
        }
        arr_cell2[tedad_cell_karbar].energy=10;
        arr_cell2[tedad_cell_karbar].shomare_block_cell=shomare_cell_split-4;
        return 0;
        f=0;
    }
    else
    {
        return 1;
        f=0;
    }
    }
}

void show_info_cell(int tedad_cell_karbar,struct cell * arr_cell)
{
    int i;
    for(i=0;i<tedad_cell_karbar;i++)
    {
        printf("energy cell shomare %d = %d \n",arr_cell[i].shomare_block_cell,arr_cell[i].energy);
    }
}
*/


int main()
{
    //system("color 07");
    printf("[1] Load\n");
    printf("[2] New single player game\n");
    printf("[3] New Multi player game\n");
    printf("[4] Exit\n");
    int karbar1;
    scanf("%d",&karbar1);
    if(karbar1==1)
    {
    }
    else if(karbar1==2)
    {
       FILE * fpin=fopen("map.bin","rb");
       int width, height;
       fread(&width,4,1,fpin);
       fread(&height,4,1,fpin);
       int tedad_cell_karbar;
       printf("chand cell mikhahid baraye shooroo bazi?:)\n");
       scanf("%d",&tedad_cell_karbar);
       system("cls");
       struct block arr[height*width];
       int count2=0;
       int i;
       for(i=0;i<height*width;i++)
       {
           fread(&arr[i].energy,4,1,fpin);
           fread(&arr[i].type,1,1,fpin);
           if(arr[i].type=='3')
            count2++;
       }
       int shomare_block_ggo[count2];//ggo: gheire ghabele oboor
       int h=0;
       for(i=0;i<height*width;i++)
       {
           if(arr[i].type=='3')
           {
              shomare_block_ggo[h]=i;
              h++;
           }
       }
       int *arr_tasadofi=NULL;
       if(arr_tasadofi==NULL)
        arr_tasadofi=(int *)malloc(tedad_cell_karbar*sizeof(int));
       else
        arr_tasadofi=(int *)realloc(arr_tasadofi,tedad_cell_karbar*sizeof(int));
       time_t t=time(NULL);
       srand(t);
       int a=(rand())%16;
       for(i=0;i<tedad_cell_karbar;i++)
       {
           arr_tasadofi[i]=a;
       }
       int j=1;
       while(j<tedad_cell_karbar)
       {
           int x=(rand())%16;
           int k;
           int count1=0;
           for(k=0;k<j;k++)
           {
               if(x!=arr_tasadofi[k])
               {
                   count1++;
               }
           }
           int count3=0;
           for(k=0;k<count2;k++)
           {
               if(x!=shomare_block_ggo[k])
               {
                   count3++;
               }
           }
           if(count1==j && count3==count2)
           {
               arr_tasadofi[j]=x;
               j++;
           }
           else
            continue;

        }
        struct cell * arr_cell=NULL;
       struct cell * arr_cell2=NULL;
       if(arr_cell==NULL)
        arr_cell=(struct cell *)malloc(tedad_cell_karbar*sizeof(struct cell));
       else
        arr_cell=(struct cell *)realloc(arr_cell,tedad_cell_karbar*sizeof(struct cell));
       for(i=0;i<tedad_cell_karbar;i++)
       {
           int h=arr_tasadofi[i];
           arr_cell[i].shomare_block_cell=h;
           arr_cell[i].energy=0;
       }
       int arr_por_khali[height*width];
       for(i=0;i<height*width;i++)
       {
           arr_por_khali[i]=-1;
       }
       chap_jadval(width,height,arr,tedad_cell_karbar,arr_tasadofi,arr_por_khali);
       rahnama(height,width);
       jadval_energy_block(height,width,arr);
       show_info_cell(tedad_cell_karbar,arr_cell);
       while(1)
        {
            gotoxy(0,height+20);
            printf("[1] Move\n");
            printf("[2] Split a cell\n");
            printf("[3] Boost energy\n");
            printf("[4] Save\n");
            printf("[5] Exit\n");
            int karbar2;
            scanf("%d",&karbar2);
            system("cls");
            system("color 07");
            chap_jadval(width,height,arr,tedad_cell_karbar,arr_tasadofi,arr_por_khali);
            rahnama(height,width);
            jadval_energy_block(height,width,arr);
            show_info_cell(tedad_cell_karbar,arr_cell);
            if(karbar2==1)//move
            {
                gotoxy(0,height+20 );
                printf("kodom cell ro mikhay harekat bedi?\n");
                int shomare_cell_move;
                scanf("%d",&shomare_cell_move);
                printf("kodoom jahat?\n");
                printf("[1] North\n");
                printf("[2] South\n");
                printf("[3] Northeast\n");
                printf("[4] Northwest\n");
                printf("[5] Southeast\n");
                printf("[6] Southwest\n");
                int jahat;
                scanf("%d",&jahat);
                system("cls");
                system("color 07");
                chap_jadval(width,height,arr,tedad_cell_karbar,arr_tasadofi,arr_por_khali);
                rahnama(height,width);
                jadval_energy_block(height,width,arr);
                show_info_cell(tedad_cell_karbar,arr_cell);
                int k=move_cell_sing(height,width,arr,shomare_cell_move,jahat,arr_por_khali,tedad_cell_karbar,arr_tasadofi,arr_cell );
                if(k==1)
                  continue;
                chap_jadval(width,height,arr,tedad_cell_karbar,arr_tasadofi,arr_por_khali);
                continue;

            }
            else if(karbar2==2)//Split a cell
            {
                gotoxy(0,height+20);
                printf("kodom cell ro mikhay taghsim koni?\n");
                int shomare_cell_split;
                scanf("%d",&shomare_cell_split);
                system("cls");
                system("color 07");
                chap_jadval(width,height,arr,tedad_cell_karbar,arr_tasadofi,arr_por_khali);
                rahnama(height,width);
                jadval_energy_block(height,width,arr);
                show_info_cell(tedad_cell_karbar,arr_cell);
                if(arr[shomare_cell_split].type!='2')
                    continue;
                int i;
                int f=0;
                for(i=0;i<tedad_cell_karbar;i++)
                {
                    if(arr_cell[i].shomare_block_cell==shomare_cell_split && arr_cell[i].energy<20)
                    {
                        f=1;
                        break;
                    }
                }
                if(f==1)
                    continue;
                int * arr_tasadofi2=NULL;
                int k=split_cell_sing(shomare_cell_split,height,width,arr,arr_por_khali,tedad_cell_karbar,arr_tasadofi2,arr_tasadofi,arr_cell,arr_cell2);
                system("cls");
                system("color 07");
                chap_jadval(width,height,arr,tedad_cell_karbar,arr_tasadofi,arr_por_khali);
                rahnama(height,width);
                jadval_energy_block(height,width,arr);
                show_info_cell(tedad_cell_karbar,arr_cell2);
                if(k==1)
                    continue;
                chap_jadval(width,height,arr,tedad_cell_karbar+1,arr_tasadofi2,arr_por_khali);
                continue;
            }
            else if(karbar2==3)//Boost energy
            {
                gotoxy(0,height+20);
                printf("enegy kodom cell ro mikhay afzayesh bedi?\n");
                int shomare_cell_boost;
                scanf("%d",&shomare_cell_boost);
                system("cls");
                system("color 07");
                chap_jadval(width,height,arr,tedad_cell_karbar,arr_tasadofi,arr_por_khali);
                rahnama(height,width);
                jadval_energy_block(height,width,arr);
                show_info_cell(tedad_cell_karbar,arr_cell);
                if(arr[shomare_cell_boost].type!='1')
                    continue;
                int i;
                for(i=0;i<tedad_cell_karbar;i++)
                {
                    if(arr_cell[i].shomare_block_cell==shomare_cell_boost)
                    {
                        if(arr[shomare_cell_boost].energy>=15)
                        {
                            arr_cell[i].energy+=15;
                            arr[shomare_cell_boost].energy-=15;
                        }
                        else
                        {
                            arr_cell[i].energy+=arr[shomare_cell_boost].energy;
                            arr[shomare_cell_boost].energy=0;
                        }
                    }
                }
                system("cls");
                system("color 07");
                chap_jadval(width,height,arr,tedad_cell_karbar,arr_tasadofi,arr_por_khali);
                rahnama(height,width);
                jadval_energy_block(height,width,arr);
                show_info_cell(tedad_cell_karbar,arr_cell);

            }
            else if(karbar2==4)//Save
            {
                FILE * fp1=fopen("mapbyme_block.bin","wb");
                fwrite(&width,sizeof(int),1,fp1);
                fwrite(&height,sizeof(int),1,fp1);
                int i;
                for(i=0;i<height*width;i++)
                {
                    fwrite(&arr[i].energy,sizeof(int),1,fp1);
                    fwrite(&arr[i].type,sizeof(char),1,fp1);
                }
                fwrite(&tedad_cell_karbar,sizeof(int),1,fp1);


            }
            else//Exit
            {
                system("cls");
                break;
            }
        }
        free(arr_tasadofi);
        free(arr_cell2);
        free(arr_cell);
       fclose(fpin);
       //while(1);
    }
    else if(karbar1==3)
    {
        printf("be jane bacham naresidam:))\n");
    }
    else
    {
        system("cls");
    }
    return 0;
}
