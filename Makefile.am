EXTRA_DISTS = README TODO scripts locales
AM_CFLAGS = -Wall -Wstrict-prototypes -Wmissing-prototypes -I.\
	    -DGUNZIP='"/bin/gunzip -c"' -std=iso9899:2011

bin_PROGRAMS = man2html

# man2html sources
man2html_SOURCES = abbrev.c cgibase.c man2html.c strdefs.c defs.h

# extra manpage for man2html
man_MANS = manpages/en/man2html.1 manpages/en/hman.1
