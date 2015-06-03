EXTRA_DIST = README TODO scripts
AM_CFLAGS = -Wall -Wstrict-prototypes -Wmissing-prototypes -I.\
	    -DGUNZIP='"/bin/gunzip -c"' -std=iso9899:2011

bin_PROGRAMS = man2html

# man2html sources
man2html_SOURCES = abbrev.c cgibase.c man2html.c strdefs.c defs.h

# extra manpage for man2html
dist_man_MANS = manpages/en/man2html.1 manpages/en/hman.1

# CGI scripts
scriptdir = $(datadir)
nobase_dist_script_DATA = scripts/cgi-bin/man/man2html scripts/cgi-bin/man/mansearch \
			  scripts/cgi-bin/man/mansec scripts/cgi-bin/man/manwhatis   \
			  scripts/cgi-bin/man/mansearchhelp			     \
			  scripts/cgi-aux/man/man.aux 				     \
			  scripts/cgi-aux/man/mansearch.aux			     \
			  scripts/cgi-aux/man/mansearchhelp.aux
