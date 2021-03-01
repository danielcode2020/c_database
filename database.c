#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif


void back_to_menu()
{
    char c;
    printf("\n________________________________________________________________________________________");

    printf("\npress 'm' for main menu \n");

    do{
    c = getch();

     }while ((c!='m'));

    menu_principal();
}

void menu_principal()
{   system("cls");
    printf("Add data    (a) \n");
    printf("Find data   (f) \n");
    printf("Advanced    (v) \n");
    printf("Exit        (e) \n");
}

void add_data_menu()
{
    system("cls");
    printf("Add data about a person  (p) : \n");
    printf("Add some random data     (r) : \n");
    printf("Back to menu             (b) : \n");
}

void advanced_menu()
{
    system("cls");
    printf("Find data added on a specific date (d) \n");
    printf("View all the data added            (v) \n");
    printf("Back to menu                       (b) \n");
    //printf("\n");
}

void person_add_menu()
{
    system("cls");
    FILE *fp,*fu;
    char str[100];

    fp = fopen("E:\cdatabase.txt","a");
    fu = fopen("E:\\userdata.txt","a");
    printf("Enter full name or press (b) to cancel : \n");
    gets(str);
    if (strcmp(str,"b")==0)
        {
            menu_principal();

        }
    else
        {
            char text[100];
            time_t now = time(NULL);
            struct tm *t = localtime(&now);
            strftime(text, sizeof(text)-1, "%d %m %Y %H:%M", t);

            fprintf(fp, "\nn. %s", str);
            fprintf(fp, " | data added : --%s--|", text);
            fprintf(fu, "\n %s", str);
            printf("Enter date of birth (dd.mm.yyyy) : \n");
            gets(str);
            fprintf(fp, "\nd. %s", str);
            fprintf(fu, "\n %s", str);
            printf("Enter gender (m/f) : \n");
            gets(str);
            fprintf(fp, "\ng. %s", str);
            fprintf(fu, "\n %s", str);
            printf("Enter adress : \n");
            gets(str);
            fprintf(fp, "\na. %s", str);
            fprintf(fu, "\n %s", str);
            wait(1);
            printf("Data added succesfully !!! \n");
            printf("Going back to main menu ... ");
            wait(1);
            fclose(fp);
            fclose(fu);
            menu_principal();
        }

}

void add_random_data(){
    system("cls");
    FILE *fp, *fu;
    char str[100];

    fp = fopen("E:\cdatabase.txt","a");
    fu = fopen("E:\\userdata.txt","a");

    printf("Enter your random data or press (b) to cancel : \n");
    gets(str);
    if (strcmp(str,"b")==0)
        {
            menu_principal();

        }
    else
        {
            char text[100];
            time_t now = time(NULL);
            struct tm *t = localtime(&now);
            strftime(text, sizeof(text)-1, "%d %m %Y %H:%M", t);

            fprintf(fp, "\nr. %s", str);
            fprintf(fu, "\n %s", str);
            fprintf(fp, " | data added : --%s--|", text);

            wait(1);
            printf("Data added succesfully !!! \n");
            printf("Going back to main menu ... ");
            wait(1);
            fclose(fp);
            fclose(fu);
            menu_principal();
        }


}

void find_data_menu()
{
    system("cls");
    printf("Check if any data exists (a) \n");
    printf("Find data about a person (p) \n");
    printf("Find random data         (r) \n");
    printf("Menu principal           (m) \n");

}

void find_person()
{
    system("cls");
    char s[1000], file_name[20],f[1000];
    char* s2;
    FILE *fp;

    printf("Enter name to search :  \n ");
    gets(f);
    fp = fopen("E:\\cdatabase.txt","r");
    if( fp == NULL )
     {
       printf("\n Can not open the file.");
     }
    int k;
    k=0;
    int lines,count;
    lines=count=0;


    while( fgets(s, 1000,fp)  != NULL ){
        count++;

        if ((strstr(s,f)) && (strstr(s,"n.")))
        {

           lines=count;
           FILE *fu;
           fu = fopen("E:\\userdata.txt","r");
           if( fu == NULL )
            {
                printf("\n Can not open the file.");
            }

           int l;
           l=0;

           while( fgets(s, 1000,fu)  != NULL )
           {
               l++;
               if ((l==lines) || (l<=lines+3))
               {
                   printf("%s", s);
               }

           }
           fclose(fu);


        }
    }

    fclose(fp);
    back_to_menu();
}

void find_random()
{
    system("cls");
    char s[1000], file_name[20],f[1000];
    char* s2;
    FILE *fp;

    printf("Enter your data to search :  \n ");
    gets(f);
    fp = fopen("E:\\cdatabase.txt","r");
    if( fp == NULL )
     {
       printf("\n Can not open the file.");
     }
    int k;
    k=0;
    int lines,count;
    lines=count=0;


    while( fgets(s, 1000,fp)  != NULL ){
        count++;

        if ((strstr(s,f)) && (strstr(s,"r.")))
        {

           lines=count;
           FILE *fu;
           fu = fopen("E:\\userdata.txt","r");
           if( fu == NULL )
            {
                printf("\n Can not open the file.");
            }

           int l;
           l=0;

           while( fgets(s, 1000,fu)  != NULL )
           {
               l++;
               if ((l==lines))
               {
                   printf("%s", s);
               }

           }
           fclose(fu);


        }
    }

    fclose(fp);
    back_to_menu();
}

void check_data()
{
    system("cls");
    char s[1000], file_name[20],f[1000];
    char* s2;
    FILE *fp;

    printf("Enter data to search :  \n ");
    gets(f);
    fp = fopen("E:\\userdata.txt","r");
    if( fp == NULL )
     {
       printf("\nCan not open the file.");
     }
    int k;
    k=0;


    while( fgets(s, 1000,fp)  != NULL ){
        if (strstr(s,f))
        {
           printf("Yes");
           break;
        }
    }

    fclose(fp);
    back_to_menu();
}
void view_data_on_date()
{
    system("cls");
    char date[100];
    printf("Enter the date in this format (dd mm yyyy) (01 12 2020) : \n");
    gets(date);
    char s[1000], file_name[20],f[1000];
    char* s2;
    FILE *fp;

    fp = fopen("E:\\cdatabase.txt","r");
    if( fp == NULL )
     {
       printf("\n Can not open the file.");
     }
    int k;
    k=0;
    int lines,count;
    lines=count=0;


    while( fgets(s, 1000,fp)  != NULL ){
        count++;

        if ((strstr(s,date)) && (strstr(s,"n.")))
        {

           lines=count;
           FILE *fu;
           fu = fopen("E:\\userdata.txt","r");
           if( fu == NULL )
            {
                printf("\n Can not open the file.");
            }

           int l;
           l=0;

           while( fgets(s, 1000,fu)  != NULL )
           {
               l++;
               if ((l==lines) || (l<=lines+3))
               {
                   printf("%s", s);
               }

           }
           fclose(fu);


        }
        if ((strstr(s,date)) && (strstr(s,"r.")))
        {

           lines=count;
           FILE *fu;
           fu = fopen("E:\\userdata.txt","r");
           if( fu == NULL )
            {
                printf("\n Can not open the file.");
            }

           int l;
           l=0;

           while( fgets(s, 1000,fu)  != NULL )
           {
               l++;
               if ((l==lines))
               {
                   printf("%s", s);
               }

           }
           fclose(fu);


        }

    }

    fclose(fp);
    back_to_menu();


}

void view_data()
{
    system("cls");
    char s[1000], file_name[20],f[1000];
    FILE *fp;
    fp = fopen("E:\\userdata.txt","r");
    if( fp == NULL )
     {
       printf("\nCan not open the file.");
     }
    printf("Content of file : \n ");
    while( fgets(s, 1000,fp)  != NULL )
        {
           printf("%s", s);
        }

    fclose(fp);
    back_to_menu();
}

void wait(int seconds)
{
    #ifdef _WIN32
         Sleep(1000 * seconds );
    #else
         sleep(seconds);
    #endif // _WIN32
}


int main(){
    bool b = true;
    while (b)
    {
        menu_principal();
        char c = getch();
        switch(c)
        {
            case ('a'):
            {
                add_data_menu();

                char a = getch();
                switch(a)
                {
                    case('p'):
                    {
                        person_add_menu();
                        break;
                    }
                    case ('r'):
                    {
                        add_random_data();
                        break;
                    }
                    case ('b'):
                    {
                        menu_principal();
                        break;
                    }


                }break;

            }
            case ('f'):
                {
                    find_data_menu();
                    char a = getch();
                    switch(a)
                    {
                    case ('p'):
                    {
                        find_person();
                        break;
                    }
                    case ('a'):
                    {
                        check_data();
                        break;
                    }
                    case ('r'):
                    {
                        find_random();
                        break;
                    }


                    case ('b'):
                        {
                           menu_principal();
                           break;
                        }

                    }break;
                }
            case ('v'):
                {
                    advanced_menu();
                    char a = getch();
                    switch(a)
                    {
                    case ('d'):
                    {
                        view_data_on_date();
                        break;
                    }
                    case ('v'):
                    {
                        view_data();
                        break;
                    }

                    }break;
                }



            case ('e'):
                {
                    exit(0);
                }

        }

    }

}
