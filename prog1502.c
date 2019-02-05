/**********/
/* A Game */
/**********/

/*****************************************************/
/* To compile this prgram, use "cc tet.c -lncursesw" */
/*****************************************************/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <curses.h>

#define XPOS 20
#define YPOS 3
#define XSIZE 10
#define YSIZE 15

/* map = game map, aka frame buffer */
/* -1: wall  */
/*  0: empty */
/*  1: block */
int map[XSIZE+2][YSIZE+2];

/* block pattern */
struct BLOCK {
  int x, y;
  int bitmap[4][4];
};

void tet_put(struct BLOCK block);

/* cleap map[][] */
void init_tet_map(void)
{
  int x, y;
  for( x=0 ; x<XSIZE+2 ; x++ ){
    map[x][0] = map[x][YSIZE+1] = -1;
    for( y=1 ; y<YSIZE+1 ; y++ ){
      map[x][y] = 0;
    }
  }
  for( y=0 ; y<YSIZE+2 ; y++ ){
    map[0][y] = map[XSIZE+1][y] = -1;
  }
}

/* display map[][] to screen */
void tet_disp(void)
{
  int x, y;
  for( x=0 ; x<XSIZE+2 ; x++ ){
    for( y=1 ; y<YSIZE+2 ; y++ ){
      char s[3];
      switch( map[x][y] ){
      case -1:
	strcpy(s, "##");
	break;
      case 0:
	strcpy(s, "  ");
	break;
      case 1:
	strcpy(s, "[]");
	break;
      }
      mvaddstr(y+YPOS, x*2+XPOS, s);
    }
  }
}

/* create new block */
/* using random function */
struct BLOCK tet_create(void)
{
  time_t t;
  struct tm *tim;
  struct BLOCK b[7] = {
    {XSIZE/2, 1,  {{0, 0, 0, 0},
		   {0, 1, 1, 0},
		   {0, 1, 1, 0},
		   {0, 0, 0, 0}}},
    {XSIZE/2, 1,  {{0, 0, 1, 0},
		   {0, 0, 1, 0},
		   {0, 0, 1, 0},
		   {0, 0, 1, 0}}},
    {XSIZE/2, 1,  {{0, 0, 0, 0},
		   {0, 0, 1, 0},
		   {0, 1, 1, 0},
		   {0, 0, 1, 0}}},
    {XSIZE/2, 1,  {{0, 0, 0, 0},
		   {0, 1, 0, 0},
		   {0, 1, 1, 0},
		   {0, 0, 1, 0}}},
    {XSIZE/2, 1,  {{0, 0, 0, 0},
		   {0, 0, 1, 0},
		   {0, 1, 1, 0},
		   {0, 1, 0, 0}}},
    {XSIZE/2, 1,  {{0, 0, 0, 0},
		   {0, 1, 1, 0},
		   {0, 1, 0, 0},
		   {0, 1, 0, 0}}},
    {XSIZE/2, 1,  {{0, 0, 0, 0},
		   {0, 1, 1, 0},
		   {0, 0, 1, 0},
		   {0, 0, 1, 0}}},
  };
  t = time(NULL);
  tim = localtime( &t );
  return b[ tim->tm_sec % 7 ];
}


/* check collision between a block and map[][] */
/* 0: no collision */
/* 1: collision */
int tet_check(struct BLOCK block)
{
  int x, y;
  for( x=0 ; x < 4 ; x++ ){
    for( y=0 ; y<4 ; y++ ){
      if( block.bitmap[x][y] == 1 ){
	if( map[block.x+x][block.y+y] != 0 ){
	  return 1;
	}
      }
    }
  }
  return 0;
}


/* move a block to left */
void tet_move_left(struct BLOCK *p)
{
  p->x--;
  if( tet_check(*p)==1 ){
    p->x++;
  }
}

/* move a block to right */
void tet_move_right(struct BLOCK *p)
{
  /* WRITE CODE */
  p->x++;
  if( tet_check(*p)==1 ){
    p->x--;
  }
}

/* move a block down */
void tet_move_down(struct BLOCK *p)
{
  p->y++;
  if( tet_check(*p)==1 ){
    p->y--;
  }
}


/* rotate a block */
void tet_rotate(struct BLOCK *p)
{
  struct BLOCK tst = *p;
  // struct BLOCK tst;
  int x, y;

  /* WRITE CODE */
  for(x=0; x<4; x++){
    for(y=0; y<4; y++){
      tst.bitmap[y][3-x] = p->bitmap[x][y];
    }
  }
  if( tet_check(tst) == 0 ){
    *p = tst;
  }
}

/* check line y is filled(1) or not(0) */
int tet_line_check(int y)
{
  /* WRITE CODE */
  int i;
  for(i=0;i<=XSIZE;i++){
    if(map[i][y] == 0){
      return 0;
    }
  }
  return 1;
  
}

/* delete line y and down all blocks avove y */
void tet_fall_down(int y)
{
  int x, yy;
  for( yy = y-1 ; y>0 ; y-- ){
    for( x=1 ; x<XSIZE+1 ; x++ ){
      map[x][y] = map[x][y-1];
    }
  }
}

/* check line and down blocks */
void tet_fall(void)
{
  int i, y;
  for( i=0 ; i<4 ; i++ ){
    for( y=0 ; y<YSIZE+1 ; y++ ){
      if( tet_line_check(y)==1 ){
	tet_fall_down(y);
      }
    }
  }
}

/* down a block */
void tet_down(struct BLOCK *p)
{
  p->y++;
  if( tet_check(*p)==1 ){
    p->y--;
    tet_put(*p);
    tet_fall();
    *p = tet_create();
  }
}


/* place a block on map[][] */
void tet_put(struct BLOCK block)
{
  int x, y;
  for( x=0 ; x < 4 ; x++ ){
    for( y=0 ; y<4 ; y++ ){
      if( block.bitmap[x][y] == 1 ){
	map[block.x+x][block.y+y] = 1;
      }
    }
  }
}

/* delete a block from map[][] */
void tet_delete(struct BLOCK block)
{
  int x, y;
  for( x=0 ; x < 4 ; x++ ){
    for( y=0 ; y<4 ; y++ ){
      if( block.bitmap[x][y] == 1 ){
	map[block.x+x][block.y+y] = 0;
      }
    }
  }
}

/* main loop */
/* user input, auto down, exit */
void tet_main(void)
{
  int ch, oldsec = -1;
  time_t t;
  struct tm *tim;
  struct BLOCK block;

  mvaddstr(0, 0, "End = [q] key");

  /* init map[][] */
  init_tet_map();
  block = tet_create();

  while ((ch = getch()) != 'q') {
    /* key input and its action */
    switch( ch ){
    case KEY_LEFT:
      tet_move_left(&block);
      break;
    case KEY_RIGHT:
      tet_move_right(&block);
      break;
    case KEY_DOWN:
      tet_move_down(&block);
      break;
    case ' ':
      tet_rotate(&block);
      break;
    }

    /* auto down a block */
    t = time(NULL);
    tim = localtime( &t );
    if( oldsec != tim->tm_sec ){
      tet_down(&block);
      oldsec = tim->tm_sec;
      if( tet_check(block)==1 ){
	/* collide with bottom(floor) */
	    return;
      }
    }

    /* place a block on map[][] */
    tet_put(block);

    /* display map[][] */
    tet_disp();
		
    /* remove a block from map[][] */
    tet_delete(block);
  }
}

int main(void)
{
  initscr();
  noecho();
  cbreak();
  wtimeout(stdscr, 200);
  keypad(stdscr, TRUE);

  tet_main();

  endwin();
  return 0;
}

