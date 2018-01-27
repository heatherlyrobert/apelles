/*============================----beg-of-source---============================*/
#include    "apelles.h"

tACCESSOR   my;


static float  s_mag   = 2.2;



#define     ICON_SET  "/usr/local/share/fonts/outline_icons.png"


char
MAP_driver           (char a_dir)
{
   /*---(locals)-----------+-----------+-*/
   tMAPPED    *x_map       = NULL;
   int         x_max       =    0;
   int         i           =    0;
   int         c           =    0;
   int         x_unit      =    0;
   /*---(get the size)-------------------*/
   switch (a_dir) {
   case 'R' : case 'r' :
      x_map   = &s_rowmap;
      yGLTEX_get_size (NULL  , &x_max);
      break;
   case 'C' : case 'c' :
      x_map   = &s_colmap;
      yGLTEX_get_size (&x_max, NULL  );
      break;
   }
   /*---(clear)--------------------------*/
   for (i= 0; i < LEN_MAP; ++i)  x_map->map [i] =  YVIKEYS_EMPTY;
   x_map->gmin = x_map->amin = x_map->lmin = x_map->prev = -1;
   x_map->gmax = x_map->amax = x_map->lmax = x_map->next = -1;
   /*---(do columns)---------------------*/
   for (i = 0; i <= x_max; ++i) {
      /*> if (c >= 25) {                                                              <* 
       *>    c = 0;                                                                   <* 
       *>    ++x_unit;                                                                <* 
       *> }                                                                           <*/
      x_map->map [i] = ++x_unit;
      ++c;
   }
   x_map->avail = x_max - 1;
   x_map->gmin  = 0;
   x_map->gmax  = x_max - 1;
   /*---(other)--------------------------*/
   if (a_dir != tolower (a_dir)) {
      x_map->beg   = 0;
      x_map->cur   = 0;
      x_map->end   = 0;
      x_map->len   = 0;
      x_map->tend  = 0;
      x_map->gbeg  = 0;
      x_map->gcur  = 0;
      x_map->gend  = 0;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
MAP_col              (char a_type)
{
   /*> printf ("mapping cols\n");                                                     <*/
   if (a_type == YVIKEYS_INIT)  MAP_driver   ('C');
   else                         MAP_driver   ('c');
   return 0;
}

char
MAP_row              (char a_type)
{
   /*> printf ("mapping rows\n");                                                     <*/
   if (a_type == YVIKEYS_INIT)  MAP_driver   ('R');
   else                         MAP_driver   ('r');
   return 0;
}

char
PROG_init            (void)
{
   char        rc          = 0;
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   strlcpy (my.w_title, "apelles"    , LEN_LABEL);
   /*---(command)------------------------*/
   strlcpy (my.t_text, my.w_title   , LEN_STR  );
   strlcpy (my.c_text, ":command"   , LEN_STR  );
   /*---(font info)----------------------*/
   strlcpy (my.font_name, "comfortaa"  , LEN_LABEL);
   /*> strlcpy (my.m_file, "/home/member/d_dege/tsae.tsa_revival/tsae.v24.clear.png", LEN_STR);   <*/
   strlcpy (my.m_file, ICON_SET, LEN_STR);
   my.font          = 0;
   yVIKEYS_mode_init   ();
   yVIKEYS_mode_enter  (MODE_MAP);
   yVIKEYS_cmds_init   ();
   yVIKEYS_view_palette  (  0, "lana", "full", "vivid");
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
PROG_args            (int argc, char *argv[])
{
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
PROG_conf            (void)
{
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
PROG_begin           (void)
{
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   /*---(open window)---------------------------*/
   /*> yX11_start (my.w_title, my.w_wide, my.w_tall, YX_FOCUSABLE, YX_FIXED, 'n');    <*/
   /*> yVIKEYS_view_init (my.w_title, my.w_wide, my.w_tall, YX_FOCUSABLE, YX_FIXED, 'n');   <*/
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
PROG_end             (void)
{
   /*> yX11_end     ();                                                               <*/
   yVIKEYS_view_wrap ();
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}


char
DRAW_view_main       (void)
{
   int         i           = 0;
   int         j           = 0;
   int         x_left, x_bott, x_wide, x_tall;
   char        x_text      [100]        = "testing";
   char        rc          = 0;
   DEBUG_WIND   yLOG_enter   (__FUNCTION__);
   /*===[[ SETUP VIEW ]]==================================*/
   rc = yVIKEYS_view_size    (YVIKEYS_MAIN, &x_left, &x_wide, &x_bott, &x_tall, NULL);
   DEBUG_GRAF   yLOG_complex ("main", "bott %4d, left %4d, wide %4d, tall %4d, on %c", x_bott, x_left, x_wide, x_tall, rc);
   DEBUG_WIND   yLOG_note    ("set viewport");
   glPushMatrix(); {
      glBindTexture(GL_TEXTURE_2D, my.m_tex);
      glBegin(GL_QUAD_STRIP); {
         glTexCoord2d (     0.00,   0.00);
         glVertex3f   (     0.00,   0.00,  10.00);
         glTexCoord2d (     0.00,   1.00);
         glVertex3f   (     0.00, x_tall,  10.00);
         glTexCoord2d (     1.00,   0.00);
         glVertex3f   (x_wide   ,   0.00,  10.00);
         glTexCoord2d (     1.00,   1.00);
         glVertex3f   (x_wide   , x_tall,  10.00);
      } glEnd();
      glBindTexture(GL_TEXTURE_2D, 0);
   } glPopMatrix();
   /*---(complete)-----------------------*/
   DEBUG_WIND  yLOG_exit    (__FUNCTION__);
   return 0;
}

char       /* ---- : establish rational drawing settings ---------------------*/
DRAW_init          (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rc          =    0;
   int         x_wide      =    0;
   int         x_tall      =    0;
   DEBUG_WIND   yLOG_enter   (__FUNCTION__);
   /*---(window)-------------------------*/
   yVIKEYS_view_init     (my.w_title, VER_NUM, 1000, 860, 0);
   yVIKEYS_view_moderate (YVIKEYS_MAIN    , YVIKEYS_FLAT, YVIKEYS_BOTLEF, YCOLOR_POS_MAX, DRAW_view_main);
   yVIKEYS_view_moderate (YVIKEYS_ALT     , YVIKEYS_FLAT, YVIKEYS_MIDCEN, YCOLOR_GRY_MAX, NULL  );
   yVIKEYS_view_simple   (YVIKEYS_PROGRESS, YCOLOR_GRY_MIN, NULL );
   yVIKEYS_view_simple   (YVIKEYS_NAV     , YCOLOR_GRY_MIN, NULL  );
   yVIKEYS_view_colors   (YCOLOR_POS, YCOLOR_BAS, YCOLOR_NEG, YCOLOR_POS);
   /*> rc = yVIKEYS_view_moderate (YVIKEYS_ALT     , YVIKEYS_DISABLE, 0             , 0             , NULL    );   <*/
   /*> rc = yVIKEYS_view_moderate (YVIKEYS_NAV     , YVIKEYS_DISABLE, 0             , 0             , NULL    );   <*/
   /*> rc = yVIKEYS_view_moderate (YVIKEYS_DETAILS , YVIKEYS_DISABLE, 0             , 0             , NULL    );   <*/
   /*> rc = yVIKEYS_view_moderate (YVIKEYS_PROGRESS, YVIKEYS_DISABLE, 0             , 0             , NULL    );   <*/
   /*> rc = yVIKEYS_view_moderate (YVIKEYS_FORMULA , YVIKEYS_DISABLE, 0             , 0             , NULL    );   <*/
   /*---(image)--------------------------*/
   yGLTEX_init     ();
   my.m_tex    = yGLTEX_png2tex (my.m_file);
   yGLTEX_get_size (&x_wide, &x_tall);
   /*---(resize)-------------------------*/
   x_wide /=  s_mag;
   x_tall /=  s_mag;
   yVIKEYS_view_resize  (x_wide, x_tall, 0);
   /*---(complete)-----------------------*/
   DEBUG_WIND   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
PROG_event           (void)
{
   /*---(local variables)------------------*/
   tTSPEC      x_dur;
   /*---(for keypresses)-------------------*/
   XKeyEvent  *key_event;
   char        t           [5] = "";
   int         c           =    0;
   char        x_ch        =  ' ';
   char        rc          =    0;;
   int         x_loop      =    0;
   /*---(for timer)------------------------*/
   x_dur.tv_sec    = 0;
   x_dur.tv_nsec   = 0.5 * 1000000;
   /*---(header)-------------------------*/
   DEBUG_TOPS   yLOG_enter    (__FUNCTION__);
   while (1) {
      x_ch = -1;
      if (XPending(DISP)) {
         XNextEvent(DISP, &EVNT);
         switch(EVNT.type) {
         case KeyPress:
            key_event  = (XKeyEvent *) &EVNT;
            c = XLookupString((XKeyEvent *) &EVNT, t, 5, NULL, NULL);
            if (c < 1) break;
            x_ch = t [0];
            break;
         }
      }
      x_ch = yVIKEYS_main_input  (RUN_USER, x_ch);
      rc   = yVIKEYS_main_handle (x_ch);
      if (yVIKEYS_quit ())  break;
      ++x_loop;
      if ((x_loop % 20) == 0)  yVIKEYS_view_all (s_mag);
      /*---(sleeping)--------------------*/
      nanosleep    (&x_dur, NULL);
   }
   /*---(complete)------------------------------*/
   DEBUG_TOPS   yLOG_exit     (__FUNCTION__);
   return 1;
}

int
main                 (int argc, char *argv[])
{
   /*---(locals)--------------------------------*/
   int rc = 0;
   int         x_wide      = 0;
   int         x_tall      = 0;
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
   yVIKEYS_map_init (YVIKEYS_RIGHT, MAP_col, MAP_row);
   /*---(load font)-----------------------------*/
   my.font = yFONT_load (my.font_name);
   if (my.font < 0) {
      fprintf(stderr, "Problem loading %s\n", my.font_name);
      return -1;
   }
   while (!yVIKEYS_quit ()) {
      rc = PROG_event  ();
      if (rc < 0)           break;
   }
   PROG_end             ();
   return 0;
}

