/*
 * Here are the routines of man2html that output a HREF string.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>		/* tolower() */
#include <string.h>		/* strlen() */
#include "defs.h"

/*
 * The default is to use cgibase. With relative html style
 * we generate URLs of the form "../manX/page.html".
 */
static int relat_html_style = 0;

/*
 * The default is to use cgibase. With current html style
 * we generate URLs of the form "./page.html".
 */
static int current_html_style = 0;

/*
 * Either the user is non-local (or local, but using httpd),
 * in which case we use http:/cgi-bin, or the user is local
 * and uses lynx, and we use lynxcgi:/usr/lib/cgi-bin.
 */

static char *man2htmlpath = "/cgi-bin/man/man2html"; 	/* default */
static char *cgibase_format = "http://%s"; 		/* host.domain:port */
static char *cgibase_ll_format = "lynxcgi:%s"; 		/* directory */
static char *cgibase = "";				/* default */

/*
 * Separator between URL and argument string.
 *
 * With http:<path to script>/a/b?c+d+e the script is called
 * with PATH_INFO=/a/b and QUERY_STRING=c+d+e and args $1=c, $2=d, $3=e.
 * With lynxcgi:<full path to script>?c+d+e no PATH_INFO is possible.
 */
static char sep = '?';					/* or '/' */

void
set_separator(char s) {
    sep = s;
}

void
set_lynxcgibase(char *s) {
    int n = strlen(cgibase_ll_format) + strlen(s);
    char *t = (char *) xmalloc(n);

    sprintf(t, cgibase_ll_format, s);
    cgibase = t;
}

void
set_cgibase(char *s) {
    int n = strlen(cgibase_format) + strlen(s);
    char *t = (char *) xmalloc(n);

    sprintf(t, cgibase_format, s);
    cgibase = t;
}

void
set_man2htmlpath(char *s) {
    man2htmlpath = xstrdup(s);
}

void
set_relative_html_links(void) {
    relat_html_style = 1;
}
void
set_current_html_links(void) {
    current_html_style = 1;
}

/* What shall we say in case of relat_html_style? */
static char *signature = "<hr />\n"
"This document was created by\n"
"<a href=\"http://github.com/man-pages-zh/man2html/\">man2html</a>,\n"
"using the manual pages.<br />\n"
"%s\n";

#define TIMEFORMAT "%T GMT, %B %d, %Y"
#define TIMEBUFSZ	500

void print_sig()
{
    char timebuf[TIMEBUFSZ];
    struct tm *timetm;
    time_t now;

    timebuf[0] = 0;
#ifdef TIMEFORMAT
    sprintf(timebuf, "Time: ");
    now=time(NULL);
    timetm=gmtime(&now);
    strftime(timebuf+6, TIMEBUFSZ-6, TIMEFORMAT, timetm);
    timebuf[TIMEBUFSZ-1] = 0;
#endif
    //printf(signature, cgibase, man2htmlpath, timebuf);
    printf(signature, timebuf);
}

void
include_file_html(char *g) {
    printf("<a href=\"file:///usr/include/%s\">%s</a>&gt;", g,g);
}

void
man_page_html(char *sec, char *h) {
    if (current_html_style) {
        if (!h)
            printf("<a href=\"./\">"
                    "Return to Main Contents</a>");
        else
            printf("<a href=\"./%s.html\">%s</a>",
                    h, h);
    } else if (relat_html_style) {
        if (!h)
            printf("<a href=\"../index.html\">"
                    "Return to Main Contents</a>");
        else
            printf("<a href=\"../man%s/%s.%s.html\">%s</a>",
                    sec, h, sec, h);
    } else {
        if (!h)
            printf("<a href=\"%s%s\">Return to Main Contents</a>",
                    cgibase, man2htmlpath);
        else if (!sec)
            printf("<a href=\"%s%s%c%s\">%s</a>",
                    cgibase, man2htmlpath, sep, h, h);
        else
            printf("<a href=\"%s%s%c%s+%s\">%s</a>",
                    cgibase, man2htmlpath, sep, sec, h, h);
    }
}

void
ftp_html(char *f) {
    printf("<a href=\"ftp://%s\">%s</a>", f, f);
}

void
www_html(char *f) {
    printf("<a href=\"http://%s\">%s</a>", f, f);
}

void
mailto_html(char *g) {
    printf("<a href=\"mailto:%s\">%s</a>", g, g);
}

void
url_html(char *g) {
    printf("<a href=\"%s\">%s</a>", g, g);
}

/* vim: set ts=8 sw=4 tw=0 et :*/
