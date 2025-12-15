#include <gio/gio.h>

#if defined (__ELF__) && ( __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 6))
# define SECTION __attribute__ ((section (".gresource.grade_calc"), aligned (sizeof(void *) > 8 ? sizeof(void *) : 8)))
#else
# define SECTION
#endif

static const SECTION union { const guint8 data[1212]; const double alignment; void * const ptr;}  grade_calc_resource_data = { {
  0107, 0126, 0141, 0162, 0151, 0141, 0156, 0164, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 
  0030, 0000, 0000, 0000, 0034, 0001, 0000, 0000, 0000, 0000, 0000, 0050, 0011, 0000, 0000, 0000, 
  0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0001, 0000, 0000, 0000, 0001, 0000, 0000, 0000, 
  0003, 0000, 0000, 0000, 0004, 0000, 0000, 0000, 0006, 0000, 0000, 0000, 0007, 0000, 0000, 0000, 
  0010, 0000, 0000, 0000, 0302, 0257, 0211, 0013, 0004, 0000, 0000, 0000, 0034, 0001, 0000, 0000, 
  0004, 0000, 0114, 0000, 0040, 0001, 0000, 0000, 0044, 0001, 0000, 0000, 0323, 0206, 0135, 0176, 
  0003, 0000, 0000, 0000, 0044, 0001, 0000, 0000, 0006, 0000, 0114, 0000, 0054, 0001, 0000, 0000, 
  0060, 0001, 0000, 0000, 0376, 0375, 0125, 0172, 0001, 0000, 0000, 0000, 0060, 0001, 0000, 0000, 
  0006, 0000, 0114, 0000, 0070, 0001, 0000, 0000, 0074, 0001, 0000, 0000, 0375, 0337, 0223, 0021, 
  0000, 0000, 0000, 0000, 0074, 0001, 0000, 0000, 0010, 0000, 0114, 0000, 0104, 0001, 0000, 0000, 
  0110, 0001, 0000, 0000, 0324, 0265, 0002, 0000, 0377, 0377, 0377, 0377, 0110, 0001, 0000, 0000, 
  0001, 0000, 0114, 0000, 0114, 0001, 0000, 0000, 0120, 0001, 0000, 0000, 0275, 0370, 0340, 0012, 
  0002, 0000, 0000, 0000, 0120, 0001, 0000, 0000, 0010, 0000, 0114, 0000, 0130, 0001, 0000, 0000, 
  0134, 0001, 0000, 0000, 0060, 0145, 0013, 0153, 0005, 0000, 0000, 0000, 0134, 0001, 0000, 0000, 
  0006, 0000, 0114, 0000, 0144, 0001, 0000, 0000, 0150, 0001, 0000, 0000, 0363, 0301, 0004, 0032, 
  0006, 0000, 0000, 0000, 0150, 0001, 0000, 0000, 0005, 0000, 0114, 0000, 0160, 0001, 0000, 0000, 
  0164, 0001, 0000, 0000, 0255, 0102, 0077, 0377, 0007, 0000, 0000, 0000, 0164, 0001, 0000, 0000, 
  0023, 0000, 0166, 0000, 0210, 0001, 0000, 0000, 0273, 0004, 0000, 0000, 0143, 0157, 0155, 0057, 
  0003, 0000, 0000, 0000, 0115, 0171, 0101, 0160, 0160, 0057, 0000, 0000, 0002, 0000, 0000, 0000, 
  0151, 0143, 0157, 0156, 0163, 0057, 0000, 0000, 0005, 0000, 0000, 0000, 0145, 0170, 0141, 0155, 
  0160, 0154, 0145, 0057, 0001, 0000, 0000, 0000, 0057, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 
  0150, 0151, 0143, 0157, 0154, 0157, 0162, 0057, 0006, 0000, 0000, 0000, 0062, 0064, 0170, 0062, 
  0064, 0057, 0000, 0000, 0007, 0000, 0000, 0000, 0141, 0160, 0160, 0163, 0057, 0000, 0000, 0000, 
  0010, 0000, 0000, 0000, 0160, 0165, 0162, 0160, 0137, 0165, 0160, 0154, 0157, 0141, 0144, 0137, 
  0151, 0155, 0147, 0056, 0160, 0156, 0147, 0000, 0043, 0003, 0000, 0000, 0000, 0000, 0000, 0000, 
  0211, 0120, 0116, 0107, 0015, 0012, 0032, 0012, 0000, 0000, 0000, 0015, 0111, 0110, 0104, 0122, 
  0000, 0000, 0000, 0030, 0000, 0000, 0000, 0030, 0010, 0006, 0000, 0000, 0000, 0340, 0167, 0075, 
  0370, 0000, 0000, 0000, 0001, 0163, 0122, 0107, 0102, 0000, 0256, 0316, 0034, 0351, 0000, 0000, 
  0000, 0004, 0147, 0101, 0115, 0101, 0000, 0000, 0261, 0217, 0013, 0374, 0141, 0005, 0000, 0000, 
  0000, 0011, 0160, 0110, 0131, 0163, 0000, 0000, 0016, 0303, 0000, 0000, 0016, 0303, 0001, 0307, 
  0157, 0250, 0144, 0000, 0000, 0002, 0270, 0111, 0104, 0101, 0124, 0110, 0113, 0355, 0224, 0313, 
  0117, 0123, 0101, 0024, 0306, 0277, 0271, 0317, 0136, 0050, 0024, 0260, 0345, 0121, 0270, 0102, 
  0265, 0054, 0210, 0004, 0171, 0024, 0044, 0240, 0073, 0025, 0335, 0310, 0206, 0245, 0030, 0266, 
  0132, 0211, 0262, 0164, 0001, 0177, 0202, 0161, 0145, 0214, 0211, 0046, 0056, 0115, 0064, 0272, 
  0020, 0103, 0202, 0211, 0006, 0023, 0022, 0260, 0304, 0064, 0076, 0122, 0002, 0101, 0210, 0362, 
  0050, 0345, 0241, 0066, 0226, 0336, 0336, 0307, 0270, 0240, 0225, 0333, 0251, 0305, 0270, 0321, 
  0015, 0277, 0344, 0054, 0346, 0073, 0163, 0316, 0067, 0047, 0231, 0031, 0340, 0200, 0077, 0100, 
  0130, 0301, 0116, 0137, 0115, 0247, 0322, 0326, 0120, 0377, 0300, 0351, 0056, 0053, 0262, 0353, 
  0213, 0123, 0341, 0225, 0370, 0116, 0174, 0360, 0356, 0352, 0114, 0302, 0256, 0377, 0065, 0003, 
  0336, 0200, 0072, 0365, 0360, 0031, 0265, 0164, 0075, 0053, 0106, 0232, 0057, 0320, 0041, 0365, 
  0324, 0370, 0120, 0115, 0247, 0302, 0326, 0260, 0160, 0254, 0220, 0313, 0336, 0220, 0323, 0217, 
  0306, 0060, 0363, 0164, 0034, 0147, 0256, 0135, 0302, 0331, 0353, 0003, 0247, 0165, 0160, 0203, 
  0131, 0133, 0177, 0303, 0276, 0006, 0273, 0307, 0243, 0024, 0000, 0042, 0023, 0323, 0170, 0062, 
  0174, 0013, 0217, 0157, 0334, 0204, 0307, 0127, 0203, 0236, 0301, 0176, 0300, 0062, 0145, 0266, 
  0206, 0045, 0257, 0101, 0260, 0252, 0263, 0265, 0272, 0302, 0073, 0001, 0112, 0311, 0326, 0362, 
  0032, 0144, 0247, 0102, 0253, 0033, 0353, 0341, 0155, 0364, 0203, 0160, 0004, 0246, 0256, 0003, 
  0034, 0337, 0164, 0105, 0155, 0077, 0306, 0326, 0332, 0311, 0153, 0340, 0164, 0026, 0366, 0373, 
  0175, 0276, 0132, 0120, 0212, 0310, 0304, 0064, 0326, 0346, 0026, 0211, 0134, 0240, 0100, 0056, 
  0120, 0120, 0122, 0341, 0006, 0000, 0034, 0121, 0325, 0076, 0265, 0134, 0035, 0143, 0153, 0355, 
  0344, 0065, 0240, 0204, 0360, 0261, 0215, 0115, 0062, 0073, 0361, 0006, 0311, 0257, 0161, 0034, 
  0015, 0064, 0241, 0167, 0044, 0210, 0336, 0221, 0040, 0074, 0265, 0325, 0340, 0171, 0036, 0202, 
  0300, 0103, 0222, 0244, 0254, 0033, 0306, 0302, 0263, 0102, 0206, 0056, 0127, 0335, 0371, 0343, 
  0055, 0315, 0035, 0056, 0042, 0303, 0132, 0377, 0116, 0102, 0317, 0137, 0302, 0022, 0070, 0154, 
  0054, 0255, 0140, 0051, 0034, 0301, 0122, 0070, 0202, 0371, 0311, 0267, 0320, 0222, 0051, 0353, 
  0260, 0242, 0334, 0016, 0177, 0213, 0046, 0331, 0036, 0330, 0157, 0002, 0131, 0226, 0041, 0211, 
  0022, 0001, 0001, 0041, 0204, 0100, 0055, 0053, 0107, 0062, 0264, 0000, 0055, 0264, 0000, 0155, 
  0146, 0067, 0332, 0332, 0333, 0321, 0022, 0150, 0055, 0050, 0261, 0212, 0057, 0263, 0365, 0031, 
  0362, 0032, 0000, 0000, 0115, 0137, 0241, 0114, 0330, 0123, 0273, 0153, 0002, 0111, 0224, 0100, 
  0070, 0070, 0262, 0323, 0173, 0344, 0065, 0260, 0130, 0041, 0355, 0221, 0066, 0373, 0365, 0070, 
  0030, 0343, 0034, 0362, 0032, 0230, 0206, 0256, 0333, 0172, 0202, 0000, 0040, 0044, 0035, 0231, 
  0115, 0004, 0240, 0324, 0002, 0005, 0111, 0331, 0153, 0355, 0344, 0375, 0213, 0256, 0126, 0164, 
  0370, 0112, 0335, 0356, 0141, 0101, 0024, 0177, 0175, 0007, 0366, 0323, 0144, 0046, 0324, 0165, 
  0055, 0276, 0032, 0333, 0036, 0276, 0267, 0076, 0025, 0265, 0245, 0377, 0035, 0071, 0023, 0234, 
  0363, 0373, 0145, 0137, 0242, 0244, 0034, 0304, 0054, 0245, 0006, 0157, 0335, 0211, 0206, 0076, 
  0006, 0275, 0135, 0047, 0166, 0064, 0274, 0027, 0044, 0115, 0226, 0300, 0067, 0104, 0127, 0153, 
  0047, 0335, 0225, 0237, 0116, 0156, 0353, 0346, 0234, 0107, 0244, 0272, 0041, 0010, 0165, 0332, 
  0116, 0074, 0162, 0177, 0163, 0066, 0316, 0366, 0313, 0171, 0007, 0335, 0174, 0245, 0307, 0041, 
  0052, 0027, 0055, 0160, 0335, 0034, 0307, 0165, 0007, 0212, 0252, 0266, 0122, 0246, 0256, 0072, 
  0104, 0014, 0160, 0340, 0274, 0006, 0265, 0352, 0134, 0245, 0211, 0102, 0023, 0146, 0217, 0314, 
  0023, 0207, 0300, 0053, 0065, 0046, 0265, 0072, 0077, 0257, 0047, 0136, 0317, 0143, 0313, 0144, 
  0373, 0345, 0030, 0204, 0023, 0261, 0037, 0201, 0342, 0252, 0042, 0315, 0064, 0106, 0011, 0057, 
  0274, 0322, 0014, 0243, 0310, 0041, 0362, 0134, 0312, 0320, 0106, 0165, 0320, 0131, 0201, 0343, 
  0304, 0230, 0053, 0376, 0102, 0322, 0344, 0017, 0111, 0112, 0277, 0300, 0064, 0016, 0121, 0112, 
  0027, 0104, 0271, 0160, 0375, 0335, 0316, 0262, 0306, 0366, 0073, 0340, 0377, 0363, 0023, 0370, 
  0002, 0003, 0212, 0024, 0054, 0251, 0170, 0000, 0000, 0000, 0000, 0111, 0105, 0116, 0104, 0256, 
  0102, 0140, 0202, 0000, 0000, 0050, 0165, 0165, 0141, 0171, 0051
} };

static GStaticResource static_resource = { grade_calc_resource_data.data, sizeof (grade_calc_resource_data.data) - 1 /* nul terminator */, NULL, NULL, NULL };

G_MODULE_EXPORT
GResource *grade_calc_get_resource (void);
GResource *grade_calc_get_resource (void)
{
  return g_static_resource_get_resource (&static_resource);
}
/* GLIB - Library of useful routines for C programming
 * Copyright (C) 1995-1997  Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Modified by the GLib Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GLib Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GLib at ftp://ftp.gtk.org/pub/gtk/.
 */

#ifndef __G_CONSTRUCTOR_H__
#define __G_CONSTRUCTOR_H__

/*
  If G_HAS_CONSTRUCTORS is true then the compiler support *both* constructors and
  destructors, in a usable way, including e.g. on library unload. If not you're on
  your own.

  Some compilers need #pragma to handle this, which does not work with macros,
  so the way you need to use this is (for constructors):

  #ifdef G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA
  #pragma G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(my_constructor)
  #endif
  G_DEFINE_CONSTRUCTOR(my_constructor)
  static void my_constructor(void) {
   ...
  }

*/

#ifndef __GTK_DOC_IGNORE__

#if  __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 7)

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR(_func) static void __attribute__((constructor)) _func (void);
#define G_DEFINE_DESTRUCTOR(_func) static void __attribute__((destructor)) _func (void);

#elif defined (_MSC_VER)

/*
 * Only try to include gslist.h if not already included via glib.h,
 * so that items using gconstructor.h outside of GLib (such as
 * GResources) continue to build properly.
 */
#ifndef __G_LIB_H__
#include "gslist.h"
#endif

#include <stdlib.h>

#define G_HAS_CONSTRUCTORS 1

/* We do some weird things to avoid the constructors being optimized
 * away on VS2015 if WholeProgramOptimization is enabled. First we
 * make a reference to the array from the wrapper to make sure its
 * references. Then we use a pragma to make sure the wrapper function
 * symbol is always included at the link stage. Also, the symbols
 * need to be extern (but not dllexport), even though they are not
 * really used from another object file.
 */

/* We need to account for differences between the mangling of symbols
 * for x86 and x64/ARM/ARM64 programs, as symbols on x86 are prefixed
 * with an underscore but symbols on x64/ARM/ARM64 are not.
 */
#ifdef _M_IX86
#define G_MSVC_SYMBOL_PREFIX "_"
#else
#define G_MSVC_SYMBOL_PREFIX ""
#endif

#define G_DEFINE_CONSTRUCTOR(_func) G_MSVC_CTOR (_func, G_MSVC_SYMBOL_PREFIX)
#define G_DEFINE_DESTRUCTOR(_func) G_MSVC_DTOR (_func, G_MSVC_SYMBOL_PREFIX)

#define G_MSVC_CTOR(_func,_sym_prefix) \
  static void _func(void); \
  extern int (* _array ## _func)(void);              \
  int _func ## _wrapper(void);              \
  int _func ## _wrapper(void) { _func(); g_slist_find (NULL,  _array ## _func); return 0; } \
  __pragma(comment(linker,"/include:" _sym_prefix # _func "_wrapper")) \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) int (* _array ## _func)(void) = _func ## _wrapper;

#define G_MSVC_DTOR(_func,_sym_prefix) \
  static void _func(void); \
  extern int (* _array ## _func)(void);              \
  int _func ## _constructor(void);              \
  int _func ## _constructor(void) { atexit (_func); g_slist_find (NULL,  _array ## _func); return 0; } \
   __pragma(comment(linker,"/include:" _sym_prefix # _func "_constructor")) \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) int (* _array ## _func)(void) = _func ## _constructor;

#elif defined(__SUNPRO_C)

/* This is not tested, but i believe it should work, based on:
 * http://opensource.apple.com/source/OpenSSL098/OpenSSL098-35/src/fips/fips_premain.c
 */

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA 1
#define G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA 1

#define G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(_func) \
  init(_func)
#define G_DEFINE_CONSTRUCTOR(_func) \
  static void _func(void);

#define G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(_func) \
  fini(_func)
#define G_DEFINE_DESTRUCTOR(_func) \
  static void _func(void);

#else

/* constructors not supported for this compiler */

#endif

#endif /* __GTK_DOC_IGNORE__ */
#endif /* __G_CONSTRUCTOR_H__ */

#ifdef G_HAS_CONSTRUCTORS

#ifdef G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA
#pragma G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(grade_calcresource_constructor)
#endif
G_DEFINE_CONSTRUCTOR(grade_calcresource_constructor)
#ifdef G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA
#pragma G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(grade_calcresource_destructor)
#endif
G_DEFINE_DESTRUCTOR(grade_calcresource_destructor)

#else
#warning "Constructor not supported on this compiler, linking in resources will not work"
#endif

static void grade_calcresource_constructor (void)
{
  g_static_resource_init (&static_resource);
}

static void grade_calcresource_destructor (void)
{
  g_static_resource_fini (&static_resource);
}
