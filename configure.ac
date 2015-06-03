#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([man2html], [1.6g-7p1], [https://github.com/man-pages-zh/man2html/], [man2html])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([defs.h])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([strchr strdup strrchr strstr])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

# vim: set ts=8 sw=4 tw=0 et :
