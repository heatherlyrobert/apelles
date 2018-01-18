/*============================----beg-of-source---============================*/
#ifndef     APELLES
#define     APELLES loaded



/*===[[ VERSION ]]========================================*/
/* rapidly evolving version number to aid with visual change confirmation     */
#define     VER_NUM     "0.2a"
#define     VER_TXT     "uses yVIKEYS for map mode and moving a basic cursor"



/*===[[ HEADERS ]]========================================*/
/*---(ansi-c standard)-------------------*/
#include    <stdio.h>        /* CLIBC   standard input/output                 */
#include    <stdlib.h>       /* CLIBC   standard general purpose              */
#include    <string.h>       /* CLIBC   standard string handling              */
#include    <time.h>         /* CLIBC   standard time and date handling       */
/*---(X11 standard)----------------------*/
#include    <X11/X.h>        /* X11     standard overall file                 */
#include    <X11/Xlib.h>     /* X11     standard C API                        */
/*---(opengl standard)-------------------*/
#include    <GL/gl.h>        /* OPENGL  standard primary header               */
#include    <GL/glx.h>       /* OPENGL  standard X11 integration              */
/*---(heatherly made)--------------------*/
#include    <yURG.h>         /* CUSTOM  heatherly urgent processing           */
#include    <yLOG.h>         /* CUSTOM  heatherly program logging             */
#include    <yX11.h>         /* CUSTOM  heatherly xlib/glx setup/teardown     */
#include    <yFONT.h>        /* CUSTOM  heatherly texture-mapped fonts        */
#include    <ySTR.h>         /* CUSTOM  heatherly string handling             */
#include    <yVIKEYS.h>      /* CUSTOM  heatherly vi_keys standard            */
#include    <yGLTEX.h>       /* CUSTOM  heatherly texture handling            */






/*===[[ RATIONAL LIMITS ]]====================================================*/
/*   LEN_ is a length or size of something
 *   MIN_ is a minimum count
 *   DEF_ is a default count
 *   MAX_ is a maximum count
 *
 */
/*---(string length)------------------*/
#define     LEN_RECD    2000
#define     LEN_STR     200
#define     LEN_LABEL   20

/*---(run as)----------*/
#define     RUN_USER           'i'      /* running in user mode (ncurses)     */
#define     RUN_TEST           '-'      /* running as a test    (no ncurses)  */


typedef struct timespec  tTSPEC;


typedef     struct      cACCESSOR  tACCESSOR;
struct cACCESSOR {
   /*---(full window)-----*/
   char        w_title   [LEN_STR];
   int         w_wide;
   int         w_tall;
   /*---(image)-----------*/
   int         i_wide;
   int         i_tall;
   /*---(font)------------*/
   char        font_name   [LEN_LABEL];
   char        font;
   /*---(title window)----*/
   int         t_wide;                      /* width  of title window         */
   int         t_left;                      /* left   of title window         */
   int         t_tall;                      /* height of title window         */
   int         t_bott;                      /* bottom of title window         */
   char        t_text    [LEN_STR];         /* title bar text                 */
   /*---(main window)-----*/
   int         m_wide;                      /* width  of main window          */
   int         m_left;                      /* left   of main window          */
   int         m_tall;                      /* height of main window          */
   int         m_bott;                      /* bottom of main window          */
   char        m_file    [LEN_STR];         /* image to load and save         */
   int         m_tex;                       /* image texture                  */
   /*---(command line)----*/
   int         c_wide;                      /* width  of command window       */
   int         c_left;                      /* left   of command window       */
   int         c_tall;                      /* height of command window       */
   int         c_bott;                      /* bottom of command window       */
   char        c_text      [LEN_STR];       /* current text in command mode   */
};
extern      tACCESSOR   my;

char DRAW_init            (void);
char PROG_sizes           (int a_wide, int a_tall);


#endif

/*============================----end-of-source---============================*/
