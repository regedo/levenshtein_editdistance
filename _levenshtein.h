/* @(#) $Id: Levenshtein.h,v 1.22 2005/01/13 20:02:56 yeti Exp $ */
#ifndef size_t
#  include <stdlib.h>
#endif
#include <stdio.h>

/* In C, this is just wchar_t and unsigned char, in Python, lev_wchar can
 * be anything.  If you really want to cheat, define wchar_t to any integer
 * type you like before including Levenshtein.h and recompile it. */
#ifndef lev_wchar
#  ifndef wchar_t
#    include <wchar.h>
#  endif
#  define lev_wchar wchar_t
#endif
typedef unsigned char lev_byte;
size_t lev_edit_distance(size_t len1, const lev_byte *string1,
                         size_t len2, const lev_byte *string2,
                         int xcost);