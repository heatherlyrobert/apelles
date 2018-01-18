/*============================----beg-of-source---============================*/
#include    "apelles.h"

tACCESSOR   my;


static char   s_quit  = '-';
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
      if (c >= 25) {
         c = 0;
         ++x_unit;
      }
      x_map->map [i] = x_unit;
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
   printf ("mapping cols\n");
   if (a_type == YVIKEYS_INIT)  MAP_driver   ('C');
   else                         MAP_driver   ('c');
   return 0;
}

char
MAP_row              (char a_type)
{
   printf ("mapping rows\n");
   if (a_type == YVIKEYS_INIT)  MAP_driver   ('R');
   else                         MAP_driver   ('r');
   return 0;
}

char USER_quit (void) { s_quit = 'y'; }

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
   rc = yVIKEYS_cmds_add ('f', "quit"        , "q"   , ""     , USER_quit            , "quit current file (if no changes), exit if the only file"    );
   /*> printf ("rc = %d\n", rc);                                                      <*/
   rc = yVIKEYS_cmds_add ('f', "quitall"     , "qa"  , ""     , USER_quit            , "quit all files (if no changes), and exit"                    );
   /*> printf ("rc = %d\n", rc);                                                      <*/
   rc = yVIKEYS_cmds_add ('f', "writequit"   , "wq"  , ""     , USER_quit            , ""                                                            );
   /*> printf ("rc = %d\n", rc);                                                      <*/
   rc = yVIKEYS_cmds_add ('f', "writequitall", "wqa" , ""     , USER_quit            , ""                                                            );
   /*> printf ("rc = %d\n", rc);                                                      <*/
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
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
PROG_end             (void)
{
   yX11_end     ();
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
VIEW_sizer           (int a_wide, int a_tall)
{
   yX11_resize (a_wide, a_tall);
   return 0;
}

char       /* ---- : establish rational drawing settings ---------------------*/
DRAW_init          (void)
{
   /*---(locals)-----------+-----------+-*/
   char        rc          =    0;
   int         x_wide      =    0;
   int         x_tall      =    0;
   DEBUG_GRAF   yLOG_enter   (__FUNCTION__);
   /*---(color)--------------------------*/
   /*> PROG_sizes  (1000, 860);                                                       <*/
   rc = yVIKEYS_view_init    (VIEW_sizer, my.w_title, VER_NUM);
   rc = yVIKEYS_view_resize  ('-', NULL, 1000, 860, 'y');
   rc = yVIKEYS_view_corners ('w', NULL, NULL, &x_wide, &x_tall, NULL);
   rc = yX11_start (my.w_title, x_wide, x_tall, YX_FOCUSABLE, YX_FIXED, '-');
   yGLTEX_init     ();
   glClearColor    (0.8f, 0.8f, 0.8f, 1.0f);
   /*---(complete)-----------------------*/
   DEBUG_GRAF   yLOG_exit    (__FUNCTION__);
   return 0;
}

char          /*----: draw the saved status ----------------------------------*/
DRAW_cursor        (void)
{
   /*> if (my.touch == 'y')  return 0;                                                <*/
   int         x_tall;
   yVIKEYS_view_corners ('m', NULL   , NULL   , NULL   , &x_tall, NULL);
   glPointSize  (5.0);
   glColor4f    (1.00f, 0.00f, 0.00f, 1.0f);
   glBegin      (GL_POINTS); {
      glVertex3f   (s_colmap.cur / s_mag, x_tall - (s_rowmap.cur / s_mag), 20.0);
   } glEnd ();
   return 0;
}

char
DRAW_now             (void)
{
   int         i           = 0;
   int         j           = 0;
   int         x_left, x_bott, x_wide, x_tall;
   char        x_text      [100]        = "testing";
   char        rc          = 0;
   DEBUG_GRAF   yLOG_enter   (__FUNCTION__);
   /*===[[ SETUP VIEW ]]==================================*/
   rc = yVIKEYS_view_corners ('m', &x_left, &x_bott, &x_wide, &x_tall, NULL);
   DEBUG_GRAF   yLOG_note    ("set viewport");
   glViewport      (x_left, x_bott, x_wide, x_tall);
   glMatrixMode    (GL_PROJECTION);
   glLoadIdentity  ();
   glOrtho         (0  , x_wide, 0, x_tall, -500.0,  500.0);
   glMatrixMode    (GL_MODELVIEW);
   glPushMatrix(); {
      glBindTexture(GL_TEXTURE_2D, my.m_tex);
      glBegin(GL_QUAD_STRIP); {
         glTexCoord2d (     0.00,      0.00);
         glVertex3f   (     0.00,      0.00,   0.00);
         glTexCoord2d (     0.00,      1.00);
         glVertex3f   (     0.00, x_tall,   0.00);
         glTexCoord2d (     1.00,      0.00);
         glVertex3f   (x_wide,      0.00,   0.00);
         glTexCoord2d (     1.00,      1.00);
         glVertex3f   (x_wide, x_tall,   0.00);
      } glEnd();
      glBindTexture(GL_TEXTURE_2D, 0);
   } glPopMatrix();
   DRAW_cursor ();
   /*---(complete)-----------------------*/
   DEBUG_GRAF   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
DRAW_main            (void)
{
   glClear         (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   yVIKEYS_view_title       ();
   yVIKEYS_view_status      ();
   yVIKEYS_view_command     ();
   yVIKEYS_view_ribbon      ();
   /*> DRAW_title   ();                                                            <*/
   /*> DRAW_command ();                                                            <*/
   DRAW_now    ();
   glXSwapBuffers(DISP, BASE);
   glFlush();
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
      yVIKEYS_main_handle (x_ch);
      if (s_quit == 'y')  break;
      ++x_loop;
      if ((x_loop % 20) == 0)  DRAW_main();
      /*---(sleeping)--------------------*/
      nanosleep    (&x_dur, NULL);
   }
   /*---(complete)------------------------------*/
   DEBUG_TOPS   yLOG_exit     (__FUNCTION__);
   return 1;
}

/*> char                                                                                                  <* 
 *> PROG_event           (void)                                                                           <* 
 *> {                                                                                                     <* 
 *>    /+---(locals)-----------+-----------+-+/                                                           <* 
 *>    int         x_updates   = 0;                                                                       <* 
 *>    char        rc          = 0;                                                                       <* 
 *>    XKeyEvent  *key_event;                                                                             <* 
 *>    char        the_key[5];                                                                            <* 
 *>    int         the_bytes;                                                                             <* 
 *>    uchar       ch          = 0;                                                                       <* 
 *>    /+---(loop)---------------------------+/                                                           <* 
 *>    while (1) {                                                                                        <* 
 *>       XNextEvent(DISP, &EVNT);                                                                        <* 
 *>       ++x_updates;                                                                                    <* 
 *>       switch(EVNT.type) {                                                                             <* 
 *>       case Expose:                                                                                    <* 
 *>          break;                                                                                       <* 
 *>       case ConfigureNotify:                                                                           <* 
 *>          break;                                                                                       <* 
 *>       case KeyPress:                                                                                  <* 
 *>          /+---(prepare)---------------+/                                                              <* 
 *>          key_event  = (XKeyEvent *) &EVNT;                                                            <* 
 *>          the_bytes = XLookupString((XKeyEvent *) &EVNT, the_key, 5, NULL, NULL);                      <* 
 *>          if (the_bytes < 1) break;                                                                    <* 
 *>          /+---(handle)----------------+/                                                              <* 
 *>          ch      = the_key [0];                                                                       <* 
 *>          switch (ch) {                                                                                <* 
 *>          case 'Q'  :                                                                                  <* 
 *>             return -1;                                                                                <* 
 *>             break;                                                                                    <* 
 *>          case '1'  :                                                                                  <* 
 *>             PROG_sizes  (my.i_wide / 1.0, my.i_tall / 1.0);                                           <* 
 *>             yX11_resize (my.w_wide, my.w_tall);                                                       <* 
 *>             break;                                                                                    <* 
 *>          case '2'  :                                                                                  <* 
 *>             PROG_sizes  (my.i_wide / 2.0, my.i_tall / 2.0);                                           <* 
 *>             yX11_resize (my.w_wide, my.w_tall);                                                       <* 
 *>             break;                                                                                    <* 
 *>          case '3'  :                                                                                  <* 
 *>             PROG_sizes  (my.i_wide / 3.0, my.i_tall / 3.0);                                           <* 
 *>             yX11_resize (my.w_wide, my.w_tall);                                                       <* 
 *>             break;                                                                                    <* 
 *>          case '4'  :                                                                                  <* 
 *>             PROG_sizes  (my.i_wide / 4.0, my.i_tall / 4.0);                                           <* 
 *>             yX11_resize (my.w_wide, my.w_tall);                                                       <* 
 *>             break;                                                                                    <* 
 *>          }                                                                                            <* 
 *>       }                                                                                               <* 
 *>       /+> printf ("my.p_cursec = %6.1f, my_ppos = %6.1f\n", my.p_cursec, my_ppos);              <+/   <* 
 *>       /+---(check boundaries)------------+/                                                           <* 
 *>       /+> if (my.p_moving == 'y')  my.p_cursec += my.p_adv;                                <+/        <* 
 *>       /+> yVIKEYS_speed_adv  (&my.p_cursec);                                          <*              <* 
 *>        *> if (my.p_cursec <  0.0f)   {                                                <*              <* 
 *>        *>    yVIKEYS_speed_stop (&my.p_waitns);                                       <*              <* 
 *>        *>    my.p_cursec = 0.0;                                                       <*              <* 
 *>        *>    if (my.p_quit == 'y')  break;                                            <*              <* 
 *>        *> }                                                                           <*              <* 
 *>        *> if (my.p_cursec >= my.p_len) {                                              <*              <* 
 *>        *>    yVIKEYS_speed_stop (&my.p_waitns);                                       <*              <* 
 *>        *>    my.p_cursec = my.p_len;                                                  <*              <* 
 *>        *>    if (my.p_quit == 'y')  break;                                            <*              <* 
 *>        *> }                                                                           <*              <* 
 *>        *> if (my.p_endsec > 0.0 && my.p_cursec >= my.p_endsec) {                      <*              <* 
 *>        *>    yVIKEYS_speed_stop (&my.p_waitns);                                       <*              <* 
 *>        *>    if (my.p_quit == 'y')  break;                                            <*              <* 
 *>        *> }                                                                           <*              <* 
 *>        *> gait.pos = my.p_cursec;                                                     <+/             <* 
 *>       /+---(check boundaries)------------+/                                                           <* 
 *>       DEBUG_GRAF   yLOG_note    ("clear background");                                                 <* 
 *>       DRAW_main ();                                                                                   <* 
 *>    }                                                                                                  <* 
*>    return 0;                                                                                          <* 
*> }                                                                                                     <*/


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
   my.m_tex    = yGLTEX_png2tex (my.m_file);
   yGLTEX_get_size (&x_wide, &x_tall);
   /*> printf ("%2d  %-30.30s  %4dw  %4dt\n", my.m_tex, my.m_file, x_wide, x_tall);   <*/
   /*> PROG_sizes  (my.i_wide / 2.0, my.i_tall / 2.0);                                <*/
   rc = yVIKEYS_view_resize  ('r', NULL, x_wide / s_mag, x_tall / s_mag, 'y');
   yVIKEYS_map_init (MAP_col, MAP_row);
   /*> yX11_resize (my.w_wide, my.w_tall);                                            <*/
   /*---(load font)-----------------------------*/
   my.font = yFONT_load (my.font_name);
   if (my.font < 0) {
      fprintf(stderr, "Problem loading %s\n", my.font_name);
      return -1;
   }
   DRAW_now             ();
   while (s_quit != 'y') {
      rc = PROG_event           ();
      if (rc < 0) break;
   }
   PROG_end             ();
   return 0;
}

