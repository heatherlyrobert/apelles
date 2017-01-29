/*============================----beg-of-source---============================*/
#include    "apelles.h"

tACCESSOR   my;

char
PROG_init            (void)
{
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   strlcpy (my.w_title, "apelles"    , LEN_LABEL);
   /*---(widths)-------------------------*/
   my.m_wide      = my.c_wide = 1000;
   my.t_wide      =  25;
   my.w_wide      = my.m_wide + my.t_wide;
   /*---(lefts)--------------------------*/
   my.t_left      =   0;
   my.m_left      = my.c_left = my.t_wide;
   /*---(talls)--------------------------*/
   my.c_tall      =  25;  
   my.m_tall      = 836;
   my.w_tall      = my.t_tall = my.c_tall + my.m_tall;
   /*---(bottoms)------------------------*/
   my.c_bott      = my.t_bott =   0;  
   my.m_bott      = my.c_tall;
   /*---(command)------------------------*/
   strlcpy (my.t_text, my.w_title   , LEN_STR  );
   strlcpy (my.c_text, ":command"   , LEN_STR  );
   /*---(font info)----------------------*/
   strlcpy (my.font_name, "comfortaa"  , LEN_LABEL);
   strlcpy (my.m_file, "/home/member/d_dege/tsae.tsa_revival/tsae.v24.clear.png", LEN_STR);
   my.font          = 0;
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
   yXINIT_start (my.w_title, my.w_wide, my.w_tall, YX_FOCUSABLE, YX_FIXED, 'n');
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
PROG_end             (void)
{
   DEBUG_TOPS   yLOG_enter   (__FUNCTION__);
   DEBUG_TOPS   yLOG_exit    (__FUNCTION__);
   return 0;
}

char       /* ---- : establish rational drawing settings ---------------------*/
DRAW_init          (void)
{
   DEBUG_GRAF   yLOG_enter   (__FUNCTION__);
   /*---(color)--------------------------*/
   glClearColor    (0.8f, 0.8f, 0.8f, 1.0f);
   glClearDepth    (1.0f);
   /*---(textures)-----------------------*/
   glEnable        (GL_TEXTURE_2D);    /* NEW */
   /*---(blending)-----------------------*/
   glShadeModel    (GL_SMOOTH);
   glEnable        (GL_DEPTH_TEST);
   glEnable        (GL_ALPHA_TEST);
   glAlphaFunc     (GL_GEQUAL, 0.0125);
   glEnable        (GL_BLEND);
   glBlendFunc     (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glDepthFunc     (GL_LEQUAL);
   /*---(anti-aliasing)------------------*/
   glHint          (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
   /*---(special polygon antialiasing)----------*/
   glEnable        (GL_POLYGON_SMOOTH);
   glPolygonMode   (GL_FRONT_AND_BACK, GL_FILL);
   glHint          (GL_POLYGON_SMOOTH_HINT, GL_NICEST);
   /*---(simple defaulting)--------------*/
   glLineWidth     (0.50f);
   /*---(process immediately)------------*/
   glFlush         ();
   /*---(complete)-----------------------*/
   DEBUG_GRAF   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
DRAW_title         (void)
{
   /*---(setup view)---------------------*/
   glViewport      (my.t_left, my.t_bott, my.t_wide, my.t_tall);
   glMatrixMode    (GL_PROJECTION);
   glLoadIdentity  ();
   glOrtho         ( 0.0f, my.t_wide, 0.0f, my.t_tall,  -500.0,   500.0);
   glMatrixMode    (GL_MODELVIEW);
   glPushMatrix    (); {
      glColor4f    (0.40f, 0.40f, 0.00f, 1.0f);
      glBegin         (GL_POLYGON); {
         glVertex3f  (0.0f     , my.t_tall,  0.0f);
         glVertex3f  (my.t_wide, my.t_tall,  0.0f);
         glVertex3f  (my.t_wide, 0.0f     ,  0.0f);
         glVertex3f  (0.0f     , 0.0f     ,  0.0f);
      } glEnd   ();
   } glPopMatrix   ();
   /*---(display)------------------------*/
   glPushMatrix    (); {
      glTranslatef (my.t_wide,   5.0f,    0.0f);
      glColor4f    (0.00f, 0.00f, 0.00f, 1.00f);
      glRotatef    ( 90.0, 0.0f, 0.0f, 1.0f);
      yFONT_print  (my.font,  16, YF_BOTLEF, my.t_text);
      glTranslatef (my.t_tall - 10.0,   0.0f,    0.0f);
      yFONT_print  (my.font,  16, YF_BOTRIG, VER_NUM);
   } glPopMatrix   ();
   /*---(complete)-----------------------*/
   return;
}

char
DRAW_command       (void)
{
   /*---(setup view)---------------------*/
   glViewport      (my.c_left, my.c_bott, my.c_wide, my.c_tall);
   glMatrixMode    (GL_PROJECTION);
   glLoadIdentity  ();
   glOrtho         ( 0.0f, my.w_wide, 0.0f, my.c_tall,  -500.0,   500.0);
   glMatrixMode    (GL_MODELVIEW);
   glPushMatrix    (); {
      glColor4f    (0.00f, 0.00f, 0.15f, 1.0f);
      glBegin         (GL_POLYGON); {
         glVertex3f  (0.0f     , my.c_tall,  0.0f);
         glVertex3f  (my.w_wide, my.c_tall,  0.0f);
         glVertex3f  (my.w_wide, 0.0f     ,  0.0f);
         glVertex3f  (0.0f     , 0.0f     ,  0.0f);
      } glEnd   ();
   } glPopMatrix   ();
   /*---(display)------------------------*/
   glPushMatrix    (); {
      glTranslatef (    2.0f,    0.0f,    0.0f);
      glColor4f    (1.00f, 1.00f, 1.00f, 1.00f);
      yFONT_print  (my.font,  16, YF_BOTLEF, my.c_text);
   } glPopMatrix   ();
   /*---(complete)-----------------------*/
   return;
}

char
DRAW_now             (void)
{
   int         i           = 0;
   int         j           = 0;
   char        x_text      [100]        = "testing";
   DEBUG_GRAF   yLOG_enter   (__FUNCTION__);
   /*===[[ SETUP VIEW ]]==================================*/
   DEBUG_GRAF   yLOG_note    ("set viewport");
   glViewport      (my.m_left, my.m_bott, my.m_wide, my.m_tall);
   glMatrixMode    (GL_PROJECTION);
   glLoadIdentity  ();
   glOrtho         (0  , my.m_wide, 0, my.m_tall, -500.0,  500.0);
   glMatrixMode    (GL_MODELVIEW);
   glPushMatrix(); {
      glBindTexture(GL_TEXTURE_2D, my.m_tex);
      glBegin(GL_QUAD_STRIP); {
         glTexCoord2d (     0.00,      0.00);
         glVertex3f   (     0.00,      0.00,   0.00);
         glTexCoord2d (     0.00,      1.00);
         glVertex3f   (     0.00, my.m_tall,   0.00);
         glTexCoord2d (     1.00,      0.00);
         glVertex3f   (my.m_wide,      0.00,   0.00);
         glTexCoord2d (     1.00,      1.00);
         glVertex3f   (my.m_wide, my.m_tall,   0.00);
      } glEnd();
      glBindTexture(GL_TEXTURE_2D, 0);
   } glPopMatrix();
   return 0;



   /*---(show title)---------------------*/
   DEBUG_GRAF   yLOG_note    ("set defaults");
   glLineWidth     (10.0);
   glPointSize     (5.00f);
   DEBUG_GRAF   yLOG_note    ("draw");
   for (i = -500; i <= 500; i += 100) {
      for (j = -500; j <= 500; j += 100) {
         /*> printf ("%4d to %4d\n", i, j);                                           <*/
         glPushMatrix    (); {
            glTranslatef (i, j,  5.00f);
            glColor4f    (0.0f, 0.0f, 0.0f, 1.0f);
            glColor4f    (1.0f, 0.0f, 0.0f, 1.0f);
            glBegin(GL_LINES); {
               glVertex3f( 5.0,  0.0,  0.0);
               glVertex3f(15.0,  0.0,  0.0);
            } glEnd();
            glRotatef    ( 90.0, 0.0f, 0.0f, 1.0f);
            yFONT_print  (my.font,  20, YF_BASLEF, x_text);
         } glPopMatrix   ();
      }
   }
   /*---(explanation)--------------------*/
   /*---(complete)-----------------------*/
   DEBUG_GRAF   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
PROG_event           (void)
{
   /*---(locals)-----------+-----------+-*/
   int         x_updates   = 0;
   char        rc          = 0;
   XKeyEvent  *key_event;
   char        the_key[5];
   int         the_bytes;
   uchar       ch          = 0;
   /*---(loop)---------------------------*/
   while (1) {
      XNextEvent(DISP, &EVNT);
      ++x_updates;
      switch(EVNT.type) {
      case Expose:
         break;
      case ConfigureNotify:
         break;
      case KeyPress:
         /*---(prepare)---------------*/
         key_event  = (XKeyEvent *) &EVNT;
         the_bytes = XLookupString((XKeyEvent *) &EVNT, the_key, 5, NULL, NULL);
         if (the_bytes < 1) break;
         /*---(handle)----------------*/
         ch      = the_key [0];
         switch (ch) {
         case 'Q'  :  return -1;
         }
      }
      /*> printf ("my.p_cursec = %6.1f, my_ppos = %6.1f\n", my.p_cursec, my_ppos);              <*/
      /*---(check boundaries)------------*/
      /*> if (my.p_moving == 'y')  my.p_cursec += my.p_adv;                                <*/
      /*> yVIKEYS_speed_adv  (&my.p_cursec);                                          <* 
       *> if (my.p_cursec <  0.0f)   {                                                <* 
       *>    yVIKEYS_speed_stop (&my.p_waitns);                                       <* 
       *>    my.p_cursec = 0.0;                                                       <* 
       *>    if (my.p_quit == 'y')  break;                                            <* 
       *> }                                                                           <* 
       *> if (my.p_cursec >= my.p_len) {                                              <* 
       *>    yVIKEYS_speed_stop (&my.p_waitns);                                       <* 
       *>    my.p_cursec = my.p_len;                                                  <* 
       *>    if (my.p_quit == 'y')  break;                                            <* 
       *> }                                                                           <* 
       *> if (my.p_endsec > 0.0 && my.p_cursec >= my.p_endsec) {                      <* 
       *>    yVIKEYS_speed_stop (&my.p_waitns);                                       <* 
       *>    if (my.p_quit == 'y')  break;                                            <* 
       *> }                                                                           <* 
       *> gait.pos = my.p_cursec;                                                     <*/
      /*---(check boundaries)------------*/
      DEBUG_GRAF   yLOG_note    ("clear background");
      glClear         (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      DRAW_title   ();
      DRAW_command ();
      DRAW_now    ();
      glXSwapBuffers(DISP, BASE);
      glFlush();
   }




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
   /*---(load font)-----------------------------*/
   my.font = yFONT_load (my.font_name);
   if (my.font < 0) {
      fprintf(stderr, "Problem loading %s\n", my.font_name);
      return -1;
   }
   my.m_tex    = yGLTEX_png2tex (my.m_file);
   printf ("%2d  %s\n", my.m_tex, my.m_file);
   DRAW_now             ();
   while (1) {
      rc = PROG_event           ();
      if (rc < 0) break;
   }
   PROG_end             ();
   return 0;
}

