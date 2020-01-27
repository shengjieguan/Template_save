#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

typedef struct    s_l
{
    char    file_name[256];
    char    *pw_name;
    char    *gr_name;
}                t_l;

typedef    struct s_flag
{
    int    l;
}                t_flag;

typedef struct s_ls
{
    t_flag    flag;
}                t_ls;

void    save_flag(t_ls *ls, char *s)
{
    s++;
    while(*s)
    {
        if(*s == 'l')
            ls->flag.l = 1;
        else
        {
            printf("ls: illegal option -- %c\n", *s);
            printf("usage: ls [-l] [file ...]");
            exit(1);
        }
        s++;
    }
}
int        find_flag(int ar, char **av, t_ls *ls)
{
    int    i;

    i = 1;
    while (av[i][0] == '-')
    {
        if(!av[i][1])
            puts("ls: -: No such file or directory");
        save_flag(ls, av[i]);
        i++;
		if(i == ar)
			return (i);
    }#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

typedef struct    s_l
{
    char    file_name[256];
    char    *pw_name;
    char    *gr_name;
}                t_l;

typedef    struct s_flag
{
    int    l;
}                t_flag;

typedef struct s_ls
{
    t_flag    flag;
}                t_ls;

void    save_flag(t_ls *ls, char *s)
{
    s++;
    while(*s)
    {
        if(*s == 'l')
            ls->flag.l = 1;
        else
        {
            printf("ls: illegal option -- %c\n", *s);
            printf("usage: ls [-l] [file ...]");
            exit(1);
        }
        s++;
    }
}
int        find_flag(int ar, char **av, t_ls *ls)
{
    int    i;

    i = 1;
    while (av[i][0] == '-')
    {
        if(!av[i][1])
            puts("ls: -: No such file or directory");
        save_flag(ls, av[i]);
        i++;
		if(i == ar)
			return (i);
    }
    return (i);
}

int        print_no_flag(int ar, char **av)
{
    int i;
    struct dirent *de;
    DIR *dr = opendir(".");

    while((de = readdir(dr)))  
        printf("%s\n", de->d_name);
    closedir(dr);
    return (1);
}

void    init_ls(t_ls *ls)
{
    ls->flag.l = 0;
}
int main(int ar, char **av)
{
    int i;
    t_ls    ls;
    
    
    init_ls(&ls);
    if (ar < 2)
        return(print_no_flag(ar, av));

    if(ar >= 2)
    {
        i = find_flag(ar, &*av, &ls);
    }
	
    return (0);
}
    return (i);
}

int        print_no_flag(int ar, char **av)
{
    int i;
    struct dirent *de;
    DIR *dr = opendir(".");

    while((de = readdir(dr)))  
        printf("%s\n", de->d_name);
    closedir(dr);
    return (1);
}

void    init_ls(t_ls *ls)
{
    ls->flag.l = 0;
}
int main(int ar, char **av)
{
    int i;
    t_ls    ls;
    
    
    init_ls(&ls);
    if (ar < 2)
        return(print_no_flag(ar, av));

    if(ar >= 2)
    {
        i = find_flag(ar, &*av, &ls);
    }
	
    return (0);
}
