#ifndef TKB_H
#define TKB_H

#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __linux__
  #include <linux/kd.h>
#endif

#define TKEY_UP    0x1b5b41
#define TKEY_DOWN  0x1b5b42
#define TKEY_RIGHT 0x1b5b43
#define TKEY_LEFT  0x1b5b44

#define TRIM_RAWKB 1
#define TRIM_DEFKB 0

int _trim_kb_mode;
int _trim_evfd;

typedef struct {
	int code;
	int state;
} tkey;

tkey *_trim_old_kbst;
tkey *_trim_cur_kbst;
int _trim_old_kbsize;
int _trim_cur_kbsize;

struct termios _tty_old;

void trim_initkb(void);
void trim_poll(void);
int trim_keydown(int key);
int trim_keyheld(int key);
int trim_keyup(int key);
void trim_closekb(void);

#endif
