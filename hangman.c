
#include <termios.h>
#include <unistd.h>
#include <panel.h>
#include <stdio.h>
#include <ncurses.h>
#include<string.h>
#include<time.h>

#define WIDTH 30
#define HEIGHT 10

int now_sec, now_min, now_hour, now_day, now_wday, now_month, now_year;
time_t now;
struct tm *now_tm;
typedef struct _PANEL_DATA {
 int hide; 
}PANEL_DATA;
int startx = 0;
int starty = 0;
char *choices[] = { 
			"New Game",
			"Resume game",
			"Quit",
		  };
void display_man(int state);
int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu_win, int highlight);
 void fereastra(WINDOW *hangman, int highlight);
int main(int argc, char* argv[])
{	WINDOW *menu_win;
	WINDOW *hangman;
	FILE *pfs;
	int now_sec, now_min, now_hour, now_day, now_wday, now_month, now_year;
	time_t now;
	struct tm *now_tm;
	int highlight = 1;
	int choice = 0;
	int i,c,x,j,m,n,p,l,o,r;
	int ok=0,oki=0;
	int nrm=0;
	int nr=0;
	char v[100],a[100],b[100];
	char s[100];
	char k[100];
	char *s1;
	char  *s2;
	s1=s;
	s1=&s;
	s1=&s1[0];
	s1=(char *)malloc(100*sizeof(char));
	s2=k;
	s2=&k;
	s2=&s2[0];
	s2=(char *)malloc(100*sizeof(char));


	highlight = 1;
	int nrc=0;
	int nrl=0;
	initscr();
	clear();
	noecho();

	cbreak();	
	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;



	pfs=fopen(argv[1], "r");

 	if (argc ==1)

	{ 
	printf ( "Nu se poate deschide la citire fişierul!");
	exit (1);  
	} 
       	 if (pfs= fopen(argv[1], "r") ==NULL)
	{ printf("[Eroare]: Fisierul %s nu poate fi deschis");
	  exit (1);
	}  
	



		 while ( fgets(s, 100,pfs)!=NULL)
	{ s1=(char*)realloc(s,100*sizeof(char));
	 nrl++;
	 for (i=0;i<strlen(s);i++)
		if ( isprint(s[i] ) ==0)
			memmove(&s[i], &s[i+1], strlen(s) - i); 
	
	if (strlen(s)>0) 
	for (i=0;i<strlen(s);i++)
	{ nrc++;
	if (isalpha(s[i]==1));
	    tolower(s[i]);


  }
    fclose (pfs);
	return 0;
   }   strcpy(k,s);
	
       i=0;
	while (i<strlen(s))
	
   {     nr=0;
	while (s[i]!='32')
	{
		nr++;
		i++;
	}
	if (nr==1)
	{
	v[r]='_';
	r++;
	}
	
	if (nr==2)
	{

	  v[r]=s[i-1];
	  r++;
	  v[r]='_';
	  r++;
	}
	
	if (nr>2)

	for (j=i+1;j<=i+nr-1;j++)
	
	{ if (s[j]==s[i])
	 { m++;
	   s[j]=s[i];}
	  if (s[j]==s[i+nr])
	{
	  n++;
	 s[j]=s[i+nr];
	}
	}
	if (nr>2)
	{nrm=nr; 
	while(nrm>0)
	{
	 v[r]=s[i]-nr;
	
	r++;
	nrm--;
	while (nrm>1)
	{
	v[r]='_';
	r++;
	nrm--;
	}
	v[r]=s[i]; 
	}     
	}
	while (s[i]=='32')
	i++;
	c=wgetch(hangman);
	for (i=0;i<strlen(s);i++)
	if (c>='33' && c<='255')
	{ ok=0;
	 for (p=1;p<=l;p++)
	if (a[p]==c)
	ok=1;
	if (ok==0)
	{
	l++;
	a[l]=c;
	oki=0;
	for (j=0;j<strlen(k);j++)
	if (k[j]==c && s[j]=='_')
	{ oki=1;
	s[r]=c;
	}
	if (oki==0)
	{o++;
	b[o]=c;
	}
        }
	}

	
	
	
	
	
	
	
	 	
	
	 
	
	

	 menu_win = newwin(HEIGHT, WIDTH, starty, startx); 
	keypad(menu_win, TRUE);
	refresh();
	print_menu(menu_win, highlight);
	while(1)
	{ 
	  c = wgetch(menu_win); 	 
	
		switch(c)
		
		{	 case KEY_UP:   
                                        if(highlight == 1 )

                       
                       { 
			 highlight = n_choices; } 
					
					 else
					{
					--highlight; }
				
				break;
			case KEY_DOWN:
				if(highlight == n_choices)
				{	highlight = 1;}
				else 
				{	++highlight;}
				break;

                            

			  }

			
			
		
		print_menu(menu_win, highlight);

	
	

	  if (highlight == 1 && c == 10)
	  {     delwin(menu_win);
		clrtoeol();
		refresh();
		endwin();
		
	
      		
		initscr();
		hangman = newwin(0, 0, 0, 0);
		box(hangman, 0, 0);
		keypad(hangman, TRUE);
		refresh();
		mvwprintw(hangman, 44, 100, "Incepeti jocul pe start");
		mvwprintw(hangman, 46, 100, "Trebuie sa ghiciti cuvantul pt a castiga");
		
		mvwprintw(hangman, 26, 26, nrc);
		mvwprintw(hangman, 28, 28, nrl);	
	
		

		mvwaddch(hangman, 10, 5, '-');
		mvwaddch(hangman, 9, 5, '|');
		mvwaddch(hangman, 8, 5, '|');
		mvwaddch(hangman, 10, 4, '-');
		mvwaddch(hangman, 10, 6, '-');
		mvwaddch(hangman, 7, 5, '|');
		mvwaddch(hangman, 6, 5, '|');
		mvwaddch(hangman, 5, 5, '|');
		mvwaddch (hangman, 4, 5, '|');
		mvwaddch(hangman, 3, 5, '|');
		mvwaddch(hangman, 2, 5, '_');
		mvwaddch(hangman, 2, 4, '_');
		mvwaddch(hangman, 2, 3, '_');
		mvwaddch(hangman, 2, 6, '_');
		mvwaddch(hangman, 2, 7, '_');
		mvwaddch(hangman, 2, 8, '_');
		mvwaddch(hangman, 2, 9, '_');
		mvwaddch(hangman, 2, 10, '_');
		mvwaddch(hangman, 2, 11, '_');
		mvwaddch(hangman, 2, 12, '_');
		 mvwaddch(hangman, 3, 10, '|');
		mvwaddch(hangman, 4, 10, '|');
		 mvwaddch(hangman, 5, 10, '|');
		 mvwaddch(hangman, 10, 3, '-');
		mvwaddch(hangman, 10, 7, '-');



     


       now = time (NULL);
        now_tm = localtime (&now);
        now_sec = now_tm->tm_sec;
        now_min = now_tm->tm_min;
        now_hour = now_tm->tm_hour;
        now_day = now_tm->tm_mday;
        now_wday = now_tm->tm_wday;
        now_month = now_tm->tm_mon + 1;
        now_year = now_tm->tm_year + 1900;

	mvwprintw(hangman,40,100,"TIME: %d:%d:%d",now_hour, now_min, now_sec);
        mvwprintw(hangman,42,100,"DATE: %d-%d-%d", now_day, now_month, now_year);	
	mvwprintw(hangman, 1, 2, "%s", s);
	mvwprintw(hangman, 11, 12, "%s",b);
 
}	








		

	if (highlight == 2 && c == 10)
	{ if (c==113)
	endwin;
	exit(0);
	}
		






	

	
		if ( c == 'Q' ) 
		{ clrtoeol();
		refresh();
		endwin();
		break; 
		}

	
		 
	if (highlight == 3 && c == 10)
	{clrtoeol();
 refresh();
 endwin();
		}
}

}


void print_menu(WINDOW *menu_win, int highlight)
{
	int x, y, i;	
 	
	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < n_choices; ++i)
	{	if(highlight == i + 1) 
		{	wattron(menu_win, A_REVERSE); 
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
} 

void fereastra(WINDOW *hangman, int highlight)
{
        int x, y, i;
        
        x = 2;
        y = 2;
        box(hangman, 0, 0);
        for(i = 0; i < n_choices; ++i)
        {       if(highlight == i + 1) 
                {       wattron(hangman, A_REVERSE);
                        mvwprintw(hangman, y, x, "%s", choices[i]);
                        wattroff(hangman, A_REVERSE);
                }
                else
                        mvwprintw(hangman, y, x, "%s", choices[i]);
                ++y;
        }
        wrefresh(hangman);
}

}














