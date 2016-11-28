/* Our own header, to be included before all standard system header */

#ifndef _APUE_H
#define _APUE_H

#define _XOPEN_SOURCE    600  /* Single UNIX Specification, Version 3 */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/termios.h>     /* for winsize */
#ifndef TIOCGWINSZ
#include <sys/ioctl.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define MAXLINE    4096    /* max line length */

/*
 * Default file access permissions for new files.
 */
#define FILE_MODE    (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

/*
 * Default permissions for new directories.
 */
#define DIR_MODE     (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

typedef void Sigfunc(int);    /* for signel handler */

#if defined(SIG_IGN) && !defined(SIG_ERR)
#define SIG_ERR ((Sigfunc *)-1)
#endif

#define min(a,b)    ((a) < (b) ? (a) : (b))
#define max(a,b)    ((a) > (b) ? (a) : (b))


void err_dump(const char *, ...);
void err_msg(const char *, ...);
void err_quit(const char *, ...);
void err_exit(const char *, ...);
void err_ret(const char *, ...);
void err_sys(const char *, ...);

void log_msg(const char *, ...);
void log_open(const char *, ...);
void log_quit(const char *, ...);
void log_ret(const char *, ...);
void log_sys(const char *, ...);

#endif /* _APUE_H  */
