
/*--------------------------------------------------------------------*/
/*--- Nulgrind: The minimal Valgrind tool.               wt_main.c ---*/
/*--------------------------------------------------------------------*/

/*
   This file is part of Nulgrind, the minimal Valgrind tool,
   which does no instrumentation or analysis.

   Copyright (C) 2002-2017 Nicholas Nethercote
      njn@valgrind.org

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307, USA.

   The GNU General Public License is contained in the file COPYING.
*/

#include "pub_tool_basics.h"
#include "pub_tool_tooliface.h"

static void wt_post_clo_init(void)
{
}

static
IRSB* wt_instrument ( VgCallbackClosure* closure,
                      IRSB* bb,
                      const VexGuestLayout* layout, 
                      const VexGuestExtents* vge,
                      const VexArchInfo* archinfo_host,
                      IRType gWordTy, IRType hWordTy )
{
    return bb;
}

static void wt_fini(Int exitcode)
{
}

static void wt_pre_clo_init(void)
{
   VG_(details_name)            ("SuperWtyczka");
   VG_(details_version)         (NULL);
   VG_(details_description)     ("this is my own plugin");
   VG_(details_copyright_author)(
      "author: Aleksandra Poreba");
   VG_(details_bug_reports_to)  (VG_BUGS_TO);

   VG_(details_avg_translation_sizeB) ( 275 );

   VG_(basic_tool_funcs)        (wt_post_clo_init,
                                 wt_instrument,
                                 wt_fini);

   /* No needs, no core events to track */
}

VG_DETERMINE_INTERFACE_VERSION(wt_pre_clo_init)

/*--------------------------------------------------------------------*/
/*--- end                                                          ---*/
/*--------------------------------------------------------------------*/
