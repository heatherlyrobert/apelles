/*============================----beg-of-source---============================*/
#include    "apelles.h"

char        g_wint      [LEN_STR]      = "apelles";
int         g_winw      = 600;
int         g_winh      = 600;

char
PROG_init            (void)
{
   return 0;
}

char
PROG_args            (int argc, char *argv[])
{
   return 0;
}

char
PROG_conf            (void)
{
   return 0;
}

char
PROG_begin           (void)
{
   /*---(open window)---------------------------*/
   yXINIT_start (g_wint, g_winw, g_winh, YX_FOCUSABLE, YX_FIXED, 'n');
   return 0;
}

char
PROG_end             (void)
{
   return 0;
}

char
DRAW_init            (void)
{
   glShadeModel(GL_SMOOTH);
   glClearColor(0.7f, 0.7f, 0.7f, 1.0f);       /* nice medium grey            */
   glClearDepth(1.0f);
   glEnable(GL_TEXTURE_2D);    /* NEW */
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_ALPHA_TEST);
   glEnable(GL_BLEND);
   glAlphaFunc(GL_GEQUAL, 0.0125);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
   /*---(special polygon antialiasing)----------*/
   glEnable(GL_POLYGON_SMOOTH);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
   glFlush();
   return 0;
}

int
main                 (int argc, char *argv[])
{
   /*---(locals)--------------------------------*/
   int rc = 0;
   /*---(start)---------------------------------*/
   if (rc >= 0)  rc = PROG_init            ();
   if (rc >= 0)  rc = yURG_logger          (argc, argv);
   if (rc >= 0)  rc = yURG_urgs            (argc, argv);
   if (rc >= 0)  rc = PROG_args            (argc, argv);
   if (rc >= 0)  rc = PROG_conf            ();
   if (rc >= 0)  rc = PROG_begin           ();
   if (rc <  0)  {
      PROG_end             ();
      return -1;
   }
   /*---(draw)----------------------------------*/
   DRAW_init            ();
   while (1) {
   }
   PROG_end             ();
   return 0;
}
