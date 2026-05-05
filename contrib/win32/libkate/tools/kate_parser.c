/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         katedesc_parse
#define yylex           katedesc_lex
#define yyerror         katedesc_error
#define yydebug         katedesc_debug
#define yynerrs         katedesc_nerrs

/* First part of user prologue.  */
#line 10 "kate_parser.y"


#define KATE_INTERNAL
#include "kate_internal.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#ifdef HAVE_STRING_H
#include <string.h>
#endif
#include <ctype.h>
#include "kate/oggkate.h"
#ifdef HAVE_PNG
#include "kpng.h"
#endif
#include "katedesc.h"
#include "kate_parser.h"

#define CHECK_KATE_API_ERROR(statement) \
  do {                                  \
    int ret=(statement);                \
    if (ret<0) {                        \
      yyerror("error in #statement");   \
      exit(-1);                         \
    }                                   \
  } while(0)

int nerrors=0;
int nwarnings=0;

static char *temp_macro_name=NULL;
static kate_float timebase = (kate_float)0;

typedef kate_style kd_style;
typedef kate_region kd_region;

typedef struct kd_curve {
  size_t idx;
  kate_curve *curve;
} kd_curve;

typedef struct kd_motion {
  size_t idx;
  kate_motion *motion;
} kd_motion;

typedef struct kd_palette {
  kate_palette *palette;
} kd_palette;

typedef struct kd_bitmap {
  kate_bitmap *bitmap;
} kd_bitmap;

static kate_style kstyle;
static kate_region kregion;
static kd_palette kpalette;
static kd_bitmap kbitmap;
static kd_curve kcurve;
static kate_font_range *krange=NULL;
static kate_font_mapping *kmapping=NULL;

static size_t nkmotions=0;
static kd_motion *kmotions=NULL;
static kate_motion *kmotion=NULL;

static char **style_names=NULL;
static char **region_names=NULL;
static char **palette_names=NULL;
static char **bitmap_names=NULL;
static char **curve_names=NULL;
static char **motion_names=NULL;
static char **font_range_names=NULL;
static char **font_mapping_names=NULL;

static size_t n_local_bitmaps=0;
static char **local_bitmap_names=NULL;
static kate_bitmap **local_bitmaps=NULL;

static int open_ended_curve=0;
static int n_curve_pts=-1;
static int n_palette_colors=-1;
static int n_bitmap_pixels=-1;
static size_t n_bytes_in_stream=0;
static char *byte_stream=NULL;
static size_t byte_stream_size=0;

static kate_float karaoke_base_height=(kate_float)0;
static kate_float karaoke_top_height=(kate_float)0;

typedef struct kd_event {
  kate_float t0;
  kate_float t1;
  kate_float duration;
  char *text;
  kate_markup_type text_markup_type;
  int region_index;
  const kate_region *region;
  int style_index;
  const kate_style *style;
  int secondary_style_index;
  const kate_style *secondary_style;
  int palette_index;
  const kate_palette *palette;
  int bitmap_index;
  const kate_bitmap *bitmap;
} kd_event;
static kd_event kevent;

static void katedesc_trace(const char *msg,...)
{
  va_list ap;
  va_start(ap,msg);
  vfprintf(stderr,msg,ap);
  va_end(ap);
}
/* #define KDTRACE(msg,args...) katedesc_trace(msg, ##args) */
#define KDTRACE katedesc_trace

int yyerror(const char *s)
{
  (void)s;
  KDTRACE("Error line %d: %s (token %s)\n",nlines,s,katedesc_text);
  nerrors++;
  return 1;
}

int yyerrorf(const char *msg,...)
{
  static char buffer[4096];
  va_list ap;
  va_start(ap,msg);
  vsnprintf(buffer,sizeof(buffer),msg,ap);
  buffer[sizeof(buffer)-1]=0;
  va_end(ap);
  return yyerror(buffer);
}

int yywarning(const char *s)
{
  (void)s;
  KDTRACE("Warning line %d: %s (token %s)\n",nlines,s,katedesc_text);
  nwarnings++;
  return 1;
}

static void add_meta(kate_meta **km,const char *tag,const char *value)
{
  if (!*km) {
    CHECK_KATE_API_ERROR(kate_meta_create(km));
  }
  CHECK_KATE_API_ERROR(kate_meta_add_string(*km,tag,value));
}

static void add_meta_byte_stream(kate_meta **km,const char *tag)
{
  if (!*km) {
    CHECK_KATE_API_ERROR(kate_meta_create(km));
  }
  CHECK_KATE_API_ERROR(kate_meta_add(*km,tag,byte_stream,byte_stream_size));

  kate_free(byte_stream);
  byte_stream=NULL;
  n_bytes_in_stream=0;
  byte_stream_size=0;
}

static char *catstrings(char *s1,const char *s2)
{
  size_t len;
  char *s;

  if (!s2) { yyerror("internal error: no string to append"); exit(-1); }
  len=(s1?strlen(s1):0)+strlen(s2)+1;
  s=(char*)kate_realloc(s1,len);
  if (!s) { yyerror("out of memory"); exit(-1); }
  if (s1) strcat(s,s2); else strcpy(s,s2);

  return s;
}

static char *dupstring(const char *s)
{
  size_t len;
  char *news;

  if (!s) { yyerror("internal error: no string"); exit(-1); }

  len=strlen(s);
  news=(char*)kate_malloc(len+1);
  if (!news) { yyerror("out of memory"); exit(-1); }
  memcpy(news,s,len+1);
  return news;
}

static int find_item(const char *name,size_t nnames,char **names)
{
  size_t n;
  for (n=0;n<nnames;++n) {
    if (names[n] && !strcmp(names[n],name)) return n;
  }
  yyerrorf("Named item not found: %s",name);
  return 0;
}

static void init_palette(void)
{
  kpalette.palette=(kate_palette*)kate_malloc(sizeof(kate_palette));
  if (!kpalette.palette) { yyerror("out of memory"); exit(-1); }
  if (kate_palette_init(kpalette.palette)<0) {
    yyerror("palette init failed");
    exit(-1);
  }
}

static void generate_full_filename(char *full_filename,size_t size,const char *filename)
{
  if (filename[0]=='/' || filename[0]=='\\') {
    strcpy(full_filename,filename);
  }
  else {
    snprintf(full_filename,size,"%s%s",base_path,filename);
    full_filename[size-1]=0;
  }
}

static void load_palette(const char *filename)
{
#ifdef HAVE_PNG
  int ncolors;
  kate_color *palette=NULL;
  static char full_filename[4096];

  generate_full_filename(full_filename,sizeof(full_filename),filename);
  if (kd_read_png8(full_filename,NULL,NULL,NULL,&palette,&ncolors,NULL)) {
    yyerrorf("failed to load %s",filename);
    return;
  }

  kpalette.palette->ncolors=ncolors;
  kpalette.palette->colors=palette;
#else
  yyerrorf("PNG support not compiled in: cannot load %s",filename);
  exit(-1);
#endif
}

static void check_palette(const kate_palette *kp)
{
  if (!kp) { yyerror("internal error: no palette"); exit(-1); }
}

static void add_palette(kate_info *ki,const char *name,kate_palette *kp)
{
  int ret;

  check_palette(kp);

  ret=kate_info_add_palette(ki,kp);
  if (ret<0) {
    yyerrorf("Failed to register palette: %d",ret);
  }
  else {
    palette_names=(char**)kate_realloc(palette_names,ki->npalettes*sizeof(char*));
    if (!palette_names) {
      yyerror("Out of memory");
      exit(-1);
    }
    palette_names[ki->npalettes-1]=name?dupstring(name):NULL;
  }
}

static int find_palette(const kate_info *ki,const char *name)
{
  return find_item(name,ki->npalettes,palette_names);
}

static void init_bitmap(void)
{
  kbitmap.bitmap=(kate_bitmap*)kate_malloc(sizeof(kate_bitmap));
  if (!kbitmap.bitmap) { yyerror("out of memory"); exit(-1); }
  if (kate_bitmap_init_new(kbitmap.bitmap)<0) {
    yyerror("bitmap init failed");
    exit(-1);
  }
}

static int compute_bitmap_x_offset(kate_float percent)
{
  if (kbitmap.bitmap->width) {
    return (int)(kbitmap.bitmap->width*percent/100+0.5);
  }
  else {
    yyerror("Bitmap width must be known before specifying offset as a percentage");
    return 0;
  }
}

static int compute_bitmap_y_offset(kate_float percent)
{
  if (kbitmap.bitmap->height) {
    return (int)(kbitmap.bitmap->height*percent/100+0.5);
  }
  else {
    yyerror("Bitmap height must be known before specifying offset as a percentage");
    return 0;
  }
}

static void load_bitmap(const char *filename,int paletted)
{
#ifdef HAVE_PNG
  int w,h;
  unsigned char *pixels=NULL;

  if (paletted) {
    int bpp;
    static char full_filename[4096];

    generate_full_filename(full_filename,sizeof(full_filename),filename);
    if (kd_read_png8(full_filename,&w,&h,&bpp,NULL,NULL,&pixels)) {
      yyerrorf("failed to load %s",filename);
      return;
    }

    kbitmap.bitmap->type=kate_bitmap_type_paletted;
    kbitmap.bitmap->width=w;
    kbitmap.bitmap->height=h;
    kbitmap.bitmap->bpp=bpp;
    kbitmap.bitmap->pixels=pixels;
    kbitmap.bitmap->size=0;
  }
  else {
    size_t size;
    static char full_filename[4096];

    generate_full_filename(full_filename,sizeof(full_filename),filename);
    if (kd_read_png(full_filename,&w,&h,&pixels,&size)) {
      yyerrorf("failed to load %s",filename);
      return;
    }

    kbitmap.bitmap->type=kate_bitmap_type_png;
    kbitmap.bitmap->width=w;
    kbitmap.bitmap->height=h;
    kbitmap.bitmap->bpp=0;
    kbitmap.bitmap->pixels=pixels;
    kbitmap.bitmap->size=size;
  }

  kbitmap.bitmap->palette=-1;
#else
  (void)paletted;
  yyerrorf("PNG support not compiled in: cannot load %s",filename);
  exit(-1);
#endif
}

static void check_bitmap(const kate_bitmap *kb)
{
  if (!kb) { yyerror("internal error: no bitmap"); exit(-1); }
}

static void add_bitmap(kate_info *ki,const char *name,kate_bitmap *kb)
{
  int ret;

  check_bitmap(kb);

  ret=kate_info_add_bitmap(ki,kb);
  if (ret<0) {
    yyerrorf("Failed to register bitmap: %d",ret);
  }
  else {
    bitmap_names=(char**)kate_realloc(bitmap_names,ki->nbitmaps*sizeof(char*));
    if (!bitmap_names) {
      yyerror("Out of memory");
      exit(-1);
    }
    bitmap_names[ki->nbitmaps-1]=name?dupstring(name):NULL;
  }
}

static void add_local_bitmap(kate_state *k,const char *name,kate_bitmap *kb)
{
  int ret;

  check_bitmap(kb);

  ret=kate_encode_add_bitmap(k,kb);
  if (ret<0) {
    yyerrorf("Failed to register bitmap: %d",ret);
  }
  else {
    ++n_local_bitmaps;
    local_bitmap_names=(char**)kate_realloc(local_bitmap_names,n_local_bitmaps*sizeof(char*));
    if (!local_bitmap_names) {
      yyerror("Out of memory");
      exit(-1);
    }
    local_bitmap_names[n_local_bitmaps-1]=name?dupstring(name):NULL;
    local_bitmaps=(kate_bitmap**)kate_realloc(local_bitmaps,n_local_bitmaps*sizeof(kate_bitmap*));
    if (!local_bitmaps) {
      yyerror("Out of memory");
      exit(-1);
    }
    local_bitmaps[n_local_bitmaps-1]=kb;
  }
}

static void add_local_bitmap_index(kate_state *k,const char *name,size_t idx)
{
  int ret;

  ret=kate_encode_add_bitmap_index(k,idx);
  if (ret<0) {
    yyerrorf("Failed to register bitmap: %d",ret);
  }
  else {
    ++n_local_bitmaps;
    local_bitmap_names=(char**)kate_realloc(local_bitmap_names,n_local_bitmaps*sizeof(char*));
    if (!local_bitmap_names) {
      yyerror("Out of memory");
      exit(-1);
    }
    local_bitmap_names[n_local_bitmaps-1]=name?dupstring(name):NULL;
    local_bitmaps=(kate_bitmap**)kate_realloc(local_bitmaps,n_local_bitmaps*sizeof(kate_bitmap*));
    if (!local_bitmaps) {
      yyerror("Out of memory");
      exit(-1);
    }
    local_bitmaps[n_local_bitmaps-1]=NULL;
  }
}

static int find_bitmap(const kate_info *ki,const char *name)
{
  int ret=find_item(name,ki->nbitmaps,bitmap_names);
  if (ret>=0) return ret;
  ret=find_item(name,n_local_bitmaps,local_bitmap_names);
  if (ret>=0) return ret+ki->nbitmaps;
  return ret;
}

static void check_style(const kate_style *ks)
{
  if (!ks) { yyerror("internal error: no style"); exit(-1); }
}

static void add_style(kate_info *ki,const char *name,const kate_style *ks)
{
  int ret;
  kate_style *ks2;

  check_style(ks);

  ks2=(kate_style*)kate_malloc(sizeof(*ks2));
  if (!ks2) {
    yyerrorf("Out of memory");
    exit(-1);
  }
  memcpy(ks2,ks,sizeof(*ks2));

  ret=kate_info_add_style(ki,ks2);
  if (ret<0) {
    yyerrorf("Failed to register style: %d",ret);
  }
  else {
    style_names=(char**)kate_realloc(style_names,ki->nstyles*sizeof(char*));
    if (!style_names) {
      yyerror("Out of memory");
      exit(-1);
    }
    style_names[ki->nstyles-1]=name?dupstring(name):NULL;
  }
}

static int find_style(const kate_info *ki,const char *name)
{
  return find_item(name,ki->nstyles,style_names);
}

static void check_region(const kate_region *kr)
{
  if (!kr) { yyerror("internal error: no region"); exit(-1); }
  if (kr->w<0) yyerrorf("Region width (%d) must be non negative",kr->w);
  if (kr->h<0) yyerrorf("Region height (%d) must be non negative",kr->h);
}

static void add_region(kate_info *ki,const char *name,const kate_region *kr)
{
  int ret;
  kate_region *kr2;

  check_region(kr);

  kr2=(kate_region*)kate_malloc(sizeof(*kr2));
  if (!kr2) {
    yyerrorf("Out of memory");
    exit(-1);
  }
  memcpy(kr2,kr,sizeof(*kr2));

  ret=kate_info_add_region(ki,kr2);
  if (ret<0) {
    yyerrorf("Failed to register region: %d",ret);
  }
  else {
    region_names=(char**)kate_realloc(region_names,ki->nregions*sizeof(char*));
    if (!region_names) {
      yyerror("Out of memory");
      exit(-1);
    }
    region_names[ki->nregions-1]=name?dupstring(name):NULL;
  }
}

static int find_region(const kate_info *ki,const char *name)
{
  return find_item(name,ki->nregions,region_names);
}

static void check_curve(const kate_curve *kc)
{
  size_t minpts=0,maxpts=INT_MAX;
  if (!kc) { yyerror("internal error: no curve"); exit(-1); }
  switch (kc->type) {
    case kate_curve_none: minpts=0; maxpts=0; break;
    case kate_curve_static: minpts=1; maxpts=1; break;
    case kate_curve_linear: minpts=2; maxpts=INT_MAX; break;
    case kate_curve_catmull_rom_spline: minpts=2; maxpts=INT_MAX; break;
    case kate_curve_bezier_cubic_spline: minpts=3; maxpts=INT_MAX; break;
    case kate_curve_bspline: minpts=2; maxpts=INT_MAX; break;
  }
  if (kc->npts<minpts) yyerrorf("Curve does not have enough points for this type (has %d, min pts %d)",kc->npts,minpts);
  if (kc->npts>maxpts) yyerrorf("Curve has too many points for this type (has %d, max pts %d)",kc->npts,maxpts);
  if (kc->type==kate_curve_bezier_cubic_spline) {
    if ((kc->npts-1)%3) yyerrorf("Cubic Bezier splines should have 1+3n points");
  }
}

static void add_curve(kate_info *ki,const char *name,kate_curve *kc)
{
  int ret;

  check_curve(kc);

  ret=kate_info_add_curve(ki,kc);
  if (ret<0) {
    yyerrorf("Failed to register curve: %d",ret);
  }
  else {
    curve_names=(char**)kate_realloc(curve_names,ki->ncurves*sizeof(char*));
    if (!curve_names) {
      yyerror("Out of memory");
      exit(-1);
    }
    curve_names[ki->ncurves-1]=name?dupstring(name):NULL;
  }
}

static int find_curve(const kate_info *ki,const char *name)
{
  return find_item(name,ki->ncurves,curve_names);
}

static void clear_motions(void)
{
  kate_free(kmotions);
  kmotions=NULL;
  kmotion=NULL;
  nkmotions=0;
}

static void check_motion(kate_motion *kmotion)
{
  if (!kmotion) { yyerror("internal error: no motion"); exit(-1); }

  if (kmotion->ncurves==0) { yyerror("motion must have at least one curve"); return; }
  if (kmotion->semantics==(kate_motion_semantics)-1) { yyerror("motion semantics is not defined"); return; }
}

static void add_motion(kate_info *ki,const char *name,kate_motion *km)
{
  int ret;

  check_motion(km);

  ret=kate_info_add_motion(ki,km);
  if (ret<0) {
    yyerrorf("Failed to register motion: %d",ret);
  }
  else {
    motion_names=(char**)kate_realloc(motion_names,ki->nmotions*sizeof(char*));
    if (!motion_names) {
      yyerror("Out of memory");
      exit(-1);
    }
    motion_names[ki->nmotions-1]=name?dupstring(name):NULL;
  }

  clear_motions();
}

static int find_motion(const kate_info *ki,const char *name)
{
  return find_item(name,ki->nmotions,motion_names);
}

static void init_style(kd_style *style)
{
  int ret=kate_style_init(style);
  if (ret<0) {
    yyerrorf("Error initializing style: %d\n",ret);
    exit(1);
  }
}

static void set_font_width(kd_style *style,kate_float s,kate_space_metric metric)
{
  if (style->font_width>=0) {
    yyerror("Font width already set");
  }
  if (style->font_height>=0 && style->font_metric!=metric) {
    yyerror("All font size metrics must be the same");
  }
  style->font_width=s;
  style->font_metric=metric;
}

static void set_font_height(kd_style *style,kate_float s,kate_space_metric metric)
{
  if (style->font_height>=0) {
    yyerror("Font height already set");
  }
  if (style->font_width>=0 && style->font_metric!=metric) {
    yyerror("All font size metrics must be the same");
  }
  style->font_height=s;
  style->font_metric=metric;
}

static void set_font(kd_style *style,const char *font)
{
  size_t len;
  if (!font) {
    yyerror("Internal error: no font");
    exit(-1);
  }
  len=strlen(font);
  if (style->font) {
    yyerror("Font already set");
  }
  style->font=(char*)kate_malloc(len+1);
  if (!style->font) {
    yyerror("out of memory");
    exit(-1);
  }
  strcpy(style->font,font);
}

static void set_font_size(kd_style *style,kate_float s,kate_space_metric metric)
{
  if (style->font_height>=0 || style->font_width>=0) {
    yyerror("Font width and/or height already set");
  }
  style->font_width=s;
  style->font_height=s;
  style->font_metric=metric;
}

static void set_margin(kd_style *style,kate_float *margin,kate_float m,kate_space_metric metric)
{
  int metric_already_set=0;
  if (&style->left_margin!=margin && style->left_margin!=0) metric_already_set=1;
  if (&style->top_margin!=margin && style->top_margin!=0) metric_already_set=1;
  if (&style->right_margin!=margin && style->right_margin!=0) metric_already_set=1;
  if (&style->bottom_margin!=margin && style->bottom_margin!=0) metric_already_set=1;
  if (metric_already_set && metric!=style->margin_metric) {
    yyerror("Metric must be the same for all margins");
    return;
  }
  *margin=m;
  style->margin_metric=metric;
}

static void set_margins(kd_style *style,
                        kate_float left,kate_space_metric left_metric,
                        kate_float top,kate_space_metric top_metric,
                        kate_float right,kate_space_metric right_metric,
                        kate_float bottom,kate_space_metric bottom_metric)
{
  if (left_metric!=right_metric || left_metric!=top_metric || left_metric!=bottom_metric) {
    yyerror("Metric must be the same for all margins");
    return;
  }
  style->left_margin=left;
  style->top_margin=top;
  style->right_margin=right;
  style->bottom_margin=bottom;
  style->margin_metric=left_metric;
}

static void init_style_from(int idx)
{
  const kate_style *from=ki.styles[idx];
  init_style(&kstyle);
  memcpy(&kstyle,from,sizeof(kate_style));
}

static void init_region(kd_region *region)
{
  int ret=kate_region_init(region);
  if (ret<0) {
    yyerrorf("Error initializing region: %d\n",ret);
    exit(1);
  }
}

static void init_region_from(int idx)
{
  const kate_region *from=ki.regions[idx];
  init_region(&kregion);
  memcpy(&kregion,from,sizeof(kate_region));
}

static void reference_curve_from(int idx)
{
  kcurve.idx=idx;
  kcurve.curve=NULL;
}

static void init_curve(void)
{
  kcurve.idx=0;
  kcurve.curve=(kate_curve*)kate_malloc(sizeof(kate_curve));
  if (!kcurve.curve) { yyerror("out of memory"); exit(-1); }
  if (kate_curve_init(kcurve.curve)<0) {
    yyerror("error initializing curve");
    exit(-1);
  }
}

static void init_curve_from(int idx)
{
  const kate_curve *from=ki.curves[idx];
  if (!from || !from->pts) {
    yyerror("invalid curve to init from");
    exit(-1);
  }
  init_curve();
  memcpy(kcurve.curve,from,sizeof(kate_curve));
  kcurve.curve->pts=(kate_float*)kate_malloc(kcurve.curve->npts*2*sizeof(kate_float));
  if (!kcurve.curve->pts) {
    yyerror("out of memory");
    exit(-1);
  }
  memcpy(kcurve.curve->pts,from->pts,kcurve.curve->npts*2*sizeof(kate_float));
}

static void init_curve_points(int npts)
{
  if (!kcurve.curve) { yyerror("internal error: curve not initialized"); exit(-1); }
  if (n_curve_pts<0) { katedesc_error("Curve type must be specified before the points"); exit(-1); }
  if (npts<=0) { katedesc_error("Number of points cannot be negative or zero"); exit(-1); }
  kcurve.curve->npts=npts;
  kcurve.curve->pts=(kate_float*)kate_malloc(npts*2*sizeof(kate_float));
  if (!kcurve.curve->pts) {
    yyerror("Out of memory");
    exit(-1);
  }
  open_ended_curve=0;
}

static void init_open_ended_curve_points(void)
{
  if (!kcurve.curve) { yyerror("internal error: curve not initialized"); exit(-1); }
  if (n_curve_pts<0) katedesc_error("Curve type must be specified before the points");
  kcurve.curve->npts=0;
  kcurve.curve->pts=NULL;
  open_ended_curve=1;
}

static void add_open_ended_curve_point(kate_float pt)
{
  if (!kcurve.curve) { yyerror("internal error: curve not initialized"); exit(-1); }
  ++n_curve_pts;
  kcurve.curve->npts=(n_curve_pts+1)/2;
  kcurve.curve->pts=(kate_float*)kate_realloc(kcurve.curve->pts,kcurve.curve->npts*2*sizeof(kate_float));
  if (!kcurve.curve->pts) {
    yyerror("Out of memory");
    exit(-1);
  }
  kcurve.curve->pts[n_curve_pts-1]=pt;
}

static void init_palette_colors(int ncolors)
{
  if (!kpalette.palette) { yyerror("internal error: palette not initialized"); exit(-1); }
  kpalette.palette->ncolors=ncolors;
  kpalette.palette->colors=(kate_color*)kate_malloc(ncolors*sizeof(kate_color));
  if (!kpalette.palette->colors) {
    yyerror("Out of memory");
    exit(-1);
  }
  n_palette_colors=0;
}

static void init_bitmap_pixels(int width,int height,int bpp)
{
  if (!kbitmap.bitmap) { yyerror("internal error: bitmap not initialized"); exit(-1); }
  if (width<=0 || height<=0) yyerror("Bitmap dimensions must be positive");
  if (bpp<=0) yyerror("Bitmap bit depth must be positive");
  if (bpp>8) yyerrorf("Bitmap bit depth must not be more than 8 (is %d)",bpp);
  kbitmap.bitmap->type=kate_bitmap_type_paletted;
  kbitmap.bitmap->width=width;
  kbitmap.bitmap->height=height;
  kbitmap.bitmap->bpp=bpp;
  kbitmap.bitmap->pixels=(unsigned char*)kate_malloc(width*height*sizeof(unsigned char));
  if (!kbitmap.bitmap->pixels) {
    yyerror("Out of memory");
    exit(-1);
  }
  kbitmap.bitmap->size=0;
  n_bitmap_pixels=0;
}

static void init_png_bitmap_pixels(int width,int height,int size)
{
  if (!kbitmap.bitmap) { yyerror("internal error: bitmap not initialized"); exit(-1); }
  if (width<=0 || height<=0) yyerror("Bitmap dimensions must be positive");
  kbitmap.bitmap->type=kate_bitmap_type_png;
  kbitmap.bitmap->width=width;
  kbitmap.bitmap->height=height;
  kbitmap.bitmap->bpp=0;
  kbitmap.bitmap->pixels=(unsigned char*)kate_malloc(size);
  if (!kbitmap.bitmap->pixels) {
    yyerror("Out of memory");
    exit(-1);
  }
  kbitmap.bitmap->size=size;
  n_bitmap_pixels=0;
}

static void init_byte_stream(int nbytes)
{
  if (nbytes<0) { yyerror("internal error: negative number of bytes"); exit(-1); }
  byte_stream=(char*)kate_malloc(nbytes);
  if (!byte_stream) {
    yyerror("Out of memory");
    exit(-1);
  }
  n_bytes_in_stream=0;
  byte_stream_size=nbytes;
}

static void set_color(kate_color *kc,uint32_t c)
{
  int r=(c>>24)&0xff;
  int g=(c>>16)&0xff;
  int b=(c>>8)&0xff;
  int a=(c>>0)&0xff;
  if (!kc) {
    yyerror("Internal error: null color");
    exit(-1);
  }
  if (r<0 || r>255) yyerrorf("red component (%d) must be between 0 and 255",r);
  if (g<0 || g>255) yyerrorf("green component (%d) must be between 0 and 255",g);
  if (b<0 || b>255) yyerrorf("blue component (%d) must be between 0 and 255",b);
  if (a<0 || a>255) yyerrorf("alpha component (%d) must be between 0 and 255",a);
  kc->r=r;
  kc->g=g;
  kc->b=b;
  kc->a=a;
}

static void init_event(kd_event *ev)
{
  if (!ev) {
    yyerror("Internal error: null event");
    exit(-1);
  }
  ev->t0=ev->t1=ev->duration=(kate_float)-1.0;
  ev->text=NULL;
  ev->text_markup_type=kate_markup_none;
  ev->region_index=ev->style_index=ev->secondary_style_index=-1;
  ev->region=NULL;
  ev->style=NULL;
  ev->secondary_style=NULL;
  ev->palette_index=ev->bitmap_index=-1;
  ev->palette=NULL;
  ev->bitmap=NULL;
}

static void kd_encode_set_id(kate_state *kstate,unsigned int id)
{
  if (id&0x80000000) yyerrorf("ID %d (hex %x) out of range, must fit on 31 bits",id,id);

  /* unused at the moment - will need to map an autogenerated id to this user id */
  (void)kstate;
  (void)id;
}

static int add_entity(const char *entity,char **text,size_t *wlen0)
{
  int count=0;

  if (!entity || !text || !wlen0) {
    yyerror("internal error: add_entity passed null parameter");
    exit(-1);
  }

  /* write out the entity */
  while (*entity) {
    int ret=kate_text_set_character(kate_utf8,*entity,text,wlen0);
    if (ret<0) return ret;
    count+=ret;
    ++entity;
  }
  return count;
}

static char *expand_numeric_entities(const char *text)
{
  enum {
    s_text,
    s_amp,
    s_code,
    s_named
  } state=s_text;
  int c,code=0,code_from_numeric,base=-1;
  size_t len=strlen(text),len0=len+1,rlen0=len0,wlen0=len0,allocated=len0;
  /* we might need to replace "&#00;" with "&amp;" - we can't use more characters, so we needn't allocate more */
  /* this might change if we even can replace a numeric entity with a named one that is longer as a string */
  char *newtext=(char*)kate_malloc(allocated),*newtextptr=newtext;

  if (!newtext) { yyerror("out of memory"); exit(-1); }

  while (1) {
    int ret=kate_text_get_character(kate_utf8,&text,&rlen0);
    if (ret<0) {
      yyerrorf("failed to read character: %d",ret);
      kate_free(newtext);
      return NULL;
    }
    c=ret;

    code_from_numeric=0;
    switch (state) {
      case s_text:
        if (c=='&') {
          state=s_amp;
          code=0;
        }
        break;
      case s_amp:
        if (c=='#') {
          state=s_code;
          base=-1; /* unknown yet */
        }
        else {
          state=s_named;

          /* we've encountered a named entity, and we've discarded the & already,
             so we need to add it now before the newly read character */
          ret=kate_text_set_character(kate_utf8,'&',&newtextptr,&wlen0);
          if (ret<0) {
            yyerrorf("failed to write character: %d",ret);
            kate_free(newtext);
            return NULL;
          }
        }
        break;
      case s_code:
        if (c==';') {
          if (base<0) {
            /* no code given */
            yyerrorf("no code given in numeric entity");
            c=0;
            code_from_numeric=1;
            state=s_text;
          }
          else {
            c=code; /* this will be written below */
            code_from_numeric=1;
            state=s_text;
          }
        }
        else {
          /* if first character, determine if this is decimal or hexadecimal */
          if (base<0) {
            if (c=='x' || c=='X') {
              base=16;
              break; /* the code starts next character */
            }
            else {
              base=10;
              /* fall through */
            }
          }

          code*=base;
          if (isdigit(c)) code+=(c-'0');
          else if (base==16 && isxdigit(c)) code+=(tolower(c)-'a'+10);
          else yyerrorf("invalid character in numeric entity (only numeric entities are supported), got %d",c);
        }
        break;
      case s_named:
        if (c==';') {
          state=s_text;
        }
        break;
    }

    if (state==s_text || state==s_named) {
      /* we don't want to expand characters in "<&>" as they would then be wrongly interpreted,
         so we insert here as entities - note that we don't want to expand them and do another
         pass to reencode them, as we then might pick up others that *were* in the text verbatim */
      if (code_from_numeric && (c&~0xff)==0 && strchr("<&>",c)) {
        switch (c) {
          case '<': ret=add_entity("&lt;",&newtextptr,&wlen0); break;
          case '&': ret=add_entity("&amp;",&newtextptr,&wlen0); break;
          case '>': ret=add_entity("&gt;",&newtextptr,&wlen0); break;
        }
      }
      else {
        ret=kate_text_set_character(kate_utf8,c,&newtextptr,&wlen0);
      }
      if (ret<0) {
        yyerrorf("failed to write character: %d",ret);
        kate_free(newtext);
        return NULL;
      }
    }
    if (c==0) break;
  }
  return newtext;
}

static char *getrawline(const char **text)
{
  size_t rlen0;
  int newline,in_newline=0;
  const char *start_of_line;
  int c;

  if (!text || !*text) {
    yyerror("error: getrawline passed invalid text pointer");
    exit(-1);
  }

  rlen0=strlen(*text)+1;
  start_of_line=*text;

  while (1) {
    const char *ptr=*text;
    int ret=kate_text_get_character(kate_utf8,text,&rlen0);
    if (ret<0) {
      yyerrorf("failed to read character: %d",ret);
      return NULL;
    }
    c=ret;
    if (c==0) {
      /* end of the string, return everything */
      size_t len=strlen(start_of_line);
      char *line=(char*)kate_malloc(len+1);
      memcpy(line,start_of_line,len+1);
      *text=ptr; /* do not push past the start of the new line */
      return line;
    }
    newline=(c=='\r' || c=='\n');
    if (!newline && in_newline) {
      /* we are at the start of a new line */
      char *line=(char*)kate_malloc(ptr-start_of_line+1);
      memcpy(line,start_of_line,ptr-start_of_line);
      line[ptr-start_of_line]=0;
      *text=ptr; /* do not push past the start of the new line */
      return line;
    }
    in_newline=newline;
  }
}

static void trimend(char *line,size_t rlen0,int *eol)
{
  int ret;
  int c;
  int ws;
  char *text=line;

  if (!line) return;
  
  ret=kate_text_get_character(kate_utf8,(const char**)&text,&rlen0);
  if (ret<0) {
    yyerrorf("failed to read character: %d",ret);
    return;
  }
  c=ret;
  if (c==0) {
    *eol=1;
    return;
  }

  trimend(text,rlen0,eol);

  ws=((c<=0xff) && (strchr(" \t\n\r",c)!=NULL));
  if (*eol && ws) *line=0;
  if (!ws) *eol=0;
}

static char *trimline(const char *line)
{
  char *trimmed;
  size_t rlen0;
  int c;
  int eol=0;

  if (!line) {
    yyerror("error: trimline passed null line");
    exit(-1);
  }

  rlen0=strlen(line)+1;

  /* first seek to the first non whitespace character in the line */
  while (1) {
    const char *ptr=line;
    int ret=kate_text_get_character(kate_utf8,&ptr,&rlen0);
    if (ret<0) {
      yyerrorf("failed to read character: %d",ret);
      return NULL;
    }
    c=ret;
    if (!c || (c!=' ' && c!='\t')) {
      /* we found a non whitespace, or an end of line, stop */
      break;
    }
    /* we can advance the start of the line */
    line=ptr;
  }

  rlen0=strlen(line)+1;
  trimmed=(char*)kate_malloc(rlen0);
  memcpy(trimmed,line,rlen0);
  trimend(trimmed,strlen(trimmed)+1,&eol);
  return trimmed;
}

static char *trimtext(const char *text)
{
  char *newtext=(char*)kate_malloc(1);
  *newtext=0;
  while (text && *text) {
    char *line=getrawline(&text);
    char *trimmed=trimline(line);
    kate_free(line);
    if (*trimmed && strcmp(trimmed,"\n")) {
      /* ignore empty lines */
      if (newtext && *newtext) {
        /* add a newline between lines (eg, not before the first line) */
        newtext=catstrings(newtext,"\n");
      }
      newtext=catstrings(newtext,trimmed);
    }
    kate_free(trimmed);
  }
  return newtext;
}

static char *trimtext_pre(const char *text)
{
  /* in pre, we just kill a new line at start and one at the end, if any */
  size_t len;
  char *newtext;

  if (!text) {
    yyerror("error: trimtext_pre passed null text");
    exit(-1);
  }

  len=strlen(text);
  newtext=(char*)kate_malloc(len+1);

  /* start */
  if (*text=='\n') {
    memcpy(newtext,text+1,len);
    --len;
  }
  else {
    memcpy(newtext,text,len+1);
  }

  /* end */
  if (len>0 && newtext[len-1]=='\n') {
    newtext[len-1]=0;
  }

  return newtext;
}

static void backslash_n_to_newline(char *text)
{
  char *ptr=text;
  while (ptr && (ptr=strstr(ptr,"\\n"))) {
    *ptr='\n';
    memmove(ptr+1,ptr+2,strlen(ptr+2)+1);
  }
}

static void set_event_text(kd_event *ev,const char *text,int pre,int markup)
{
  char *newtext,*expanded;
  size_t len;

  if (ev->text) {
    yyerrorf("text already set (to %s, trying to set to %s)",ev->text,text);
    return;
  }
  if (!text) {
    yyerror("null text");
    return;
  }

  len=strlen(text);
  newtext=(char*)kate_malloc(len+1);
  memcpy(newtext,text,len+1);
  backslash_n_to_newline(newtext);

  expanded=expand_numeric_entities(newtext);
  kate_free(newtext);
  newtext=expanded;

  if (!pre) {
    char *trimmed_newtext=trimtext(newtext);
    kate_free(newtext);
    newtext=trimmed_newtext;
  }
  else {
    char *trimmed_newtext=trimtext_pre(newtext);
    kate_free(newtext);
    newtext=trimmed_newtext;
  }

  if (markup) {
    ev->text_markup_type=kate_markup_simple;
  }
  else {
    ev->text_markup_type=kate_markup_none;
  }

  ev->text=newtext;
}

static void set_event_text_from(kd_event *ev,const char *source,int pre,int markup)
{
  FILE *f;
  char *text=NULL;
  char s[4096],*sret;

  f=fopen(source,"rt");
  if (!f) {
    yyerrorf("Failed to open file %s\n",source);
    exit(-1);
  }
  sret=fgets(s,sizeof(s),f);
  if (!sret) {
    yyerrorf("Failed to read from file %s\n",source);
    exit(-1);
  }
  while (!feof(f)) {
    /* This implicitely forbids embedded zeros - could this be a problem ? */
    text=catstrings(text,s);
    sret=fgets(s,sizeof(s),f);
    if (!sret) {
      yyerrorf("Failed to read from file %s\n",source);
      exit(-1);
    }
  }
  fclose(f);

  if (text) {
    set_event_text(ev,text,pre,markup);
    kate_free(text);
  }
}

static void set_event_t0_t1(kd_event *ev,kate_float t0,kate_float t1)
{
  if (ev->t0>=0) { yyerror("start time already set"); return; }
  if (ev->t1>=0) { yyerror("end time already set"); return; }
  ev->t0=t0;
  ev->t1=t1;
}

static void set_event_t0(kd_event *ev,kate_float v)
{
  if (ev->t0>=0) { yyerror("start time already set"); return; }
  ev->t0=v;
}

static void set_event_t1(kd_event *ev,kate_float v)
{
  if (ev->t1>=0) { yyerror("end time already set"); return; }
  ev->t1=v;
}

static void set_event_duration(kd_event *ev,kate_float v)
{
  if (ev->duration>=0) { yyerror("duration already set"); return; }
  ev->duration=v;
}

static void set_event_region_index(kd_event *ev,int r)
{
  int ret;
  if (ev->region_index>=0 || ev->region) { yyerror("region already set"); return; }
  ev->region_index=r;
  ret=kate_encode_set_region_index(&k,r);
  if (ret<0) yyerrorf("failed to set region index: %d",ret);
}

static void set_event_region(kd_event *ev,kate_region *kr)
{
  int ret;
  check_region(kr);
  if (ev->region_index>=0 || ev->region) { yyerror("region already set"); return; }
  ev->region=kr;
  ret=kate_encode_set_region(&k,kr);
  if (ret<0) yyerrorf("failed to set region: %d",ret);
}

static void set_event_style_index(kd_event *ev,int s)
{
  int ret;
  if (ev->style_index>=0 || ev->style) { yyerror("style already set"); return; }
  ev->style_index=s;
  ret=kate_encode_set_style_index(&k,s);
  if (ret<0) yyerrorf("failed to set style index: %d",ret);
}

static void set_event_secondary_style_index(kd_event *ev,int s)
{
  int ret;
  if (ev->secondary_style_index>=0 || ev->secondary_style) { yyerror("secondary style already set"); return; }
  ev->secondary_style_index=s;
  ret=kate_encode_set_secondary_style_index(&k,s);
  if (ret<0) yyerrorf("failed to set secondary style index: %d",ret);
}

static void set_event_style(kd_event *ev,kate_style *ks)
{
  int ret;
  check_style(ks);
  if (ev->style_index>=0 || ev->style) { yyerror("style already set"); return; }
  ev->style=ks;
  ret=kate_encode_set_style(&k,ks);
  if (ret<0) yyerrorf("failed to set style: %d",ret);
}

static void set_event_secondary_style(kd_event *ev,kate_style *ks)
{
  int ret;
  check_style(ks);
  if (ev->secondary_style_index>=0 || ev->secondary_style) { yyerror("secondary style already set"); return; }
  ev->secondary_style=ks;
  ret=kate_encode_set_secondary_style(&k,ks);
  if (ret<0) yyerrorf("failed to set secondary style: %d",ret);
}

static void set_event_palette_index(kd_event *ev,int p)
{
  int ret;
  if (ev->palette_index>=0 || ev->palette) { yyerror("palette already set"); return; }
  ev->palette_index=p;
  ret=kate_encode_set_palette_index(&k,p);
  if (ret<0) yyerrorf("failed to set palette index: %d",ret);
}

static void set_event_palette(kd_event *ev,kate_palette *kp)
{
  int ret;
  check_palette(kp);
  if (ev->palette_index>=0 || ev->palette) { yyerror("palette already set"); return; }
  ev->palette=kp;
  ret=kate_encode_set_palette(&k,kp);
  if (ret<0) yyerrorf("failed to set palette: %d",ret);
}

static void set_event_bitmap_index(kd_event *ev,int b)
{
  int ret;
  if (ev->bitmap_index>=0 || ev->bitmap) { yyerror("bitmap already set"); return; }
  ev->bitmap_index=b;
  ret=kate_encode_set_bitmap_index(&k,b);
  if (ret<0) yyerrorf("failed to set bitmap index: %d",ret);
}

static void set_event_bitmap(kd_event *ev,kate_bitmap *kb)
{
  int ret;
  check_bitmap(kb);
  if (ev->bitmap_index>=0 || ev->bitmap) { yyerror("bitmap already set"); return; }
  ev->bitmap=kb;
  ret=kate_encode_set_bitmap(&k,kb);
  if (ret<0) yyerrorf("failed to set bitmap: %d",ret);
}

static void kd_add_event_meta(const char *tag,const char *value)
{
  kate_meta *meta;
  int ret;

  ret=kate_meta_create(&meta);
  if (ret>=0) {
    ret=kate_meta_add_string(meta,tag,value);
    if (ret>=0) {
      ret=kate_encode_merge_meta(&k,meta);
      if (ret<0) {
        kate_meta_destroy(meta);
      }
    }
    else {
      kate_meta_destroy(meta);
    }
  }
  if (ret<0) yyerrorf("failed to add metadata: %d",ret);
}

static void kd_add_event_meta_byte_stream(const char *tag)
{
  kate_meta *meta;
  int ret;

  ret=kate_meta_create(&meta);
  if (ret>=0) {
    ret=kate_meta_add(meta,tag,byte_stream,byte_stream_size);
    if (ret>=0) {
      ret=kate_encode_merge_meta(&k,meta);
      if (ret<0) {
        kate_meta_destroy(meta);
      }
    }
    else {
      kate_meta_destroy(meta);
    }
  }
  if (ret<0) yyerrorf("failed to add metadata: %d",ret);

  kate_free(byte_stream);
  byte_stream=NULL;
  n_bytes_in_stream=0;
  byte_stream_size=0;
}

static kd_event *check_event(kd_event *ev)
{
  /* we can set:
     start and end
     start and duration
     duration and end
     */
  int sets=0;
  if (ev->t0>=(kate_float)0.0) ++sets;
  if (ev->t1>=(kate_float)0.0) ++sets;
  if (ev->duration>=(kate_float)0.0) ++sets;
  if (sets<2) { yyerror("start/end times underspecified"); return NULL; }
  if (sets>2) { yyerror("start/end times overspecified"); return NULL; }

  if (ev->t0<(kate_float)0.0) ev->t0=ev->t1-ev->duration;
  if (ev->t1<(kate_float)0.0) ev->t1=ev->t0+ev->duration;

  return ev;
}

static void init_motion(void)
{
  kmotions=(kd_motion*)kate_realloc(kmotions,(nkmotions+1)*sizeof(kd_motion));
  if (!kmotions) { yyerror("out of memory"); exit(-1); }
  ++nkmotions;
  kmotions[nkmotions-1].idx=0;
  kmotions[nkmotions-1].motion=kate_malloc(sizeof(kate_motion));
  kmotion=kmotions[nkmotions-1].motion;
  if (!kmotion) { yyerror("out of memory"); exit(-1); }

  if (kate_motion_init(kmotion)<0) {
    yyerror("failed to init motion");
    exit(-1);
  }
  kmotion->semantics=(kate_motion_semantics)-1;
}

static void add_curve_to_motion(kate_motion *kmotion,kate_float duration)
{
  kmotion->ncurves++;
  kmotion->curves=(kate_curve**)kate_realloc(kmotion->curves,kmotion->ncurves*sizeof(kate_curve*));
  if (!kmotion->curves) { yyerror("out of memory"); exit(-1); }
  kmotion->durations=(kate_float*)kate_realloc(kmotion->durations,kmotion->ncurves*sizeof(kate_float));
  if (!kmotion->durations) { yyerror("out of memory"); exit(-1); }

  if (kcurve.curve) {
    check_curve(kcurve.curve);
    kmotion->curves[kmotion->ncurves-1]=kcurve.curve;
    kcurve.curve=NULL;
  }
  else {
    if (kcurve.idx>=ki.ncurves) {
      yyerror("Internal error: curve index out of range");
      exit(-1);
    }
    kmotion->curves[kmotion->ncurves-1]=ki.curves[kcurve.idx];
  }

  kmotion->durations[kmotion->ncurves-1]=duration;
}

static size_t get_num_glyphs(const char *text)
{
  size_t len0;
  size_t nglyphs=0;
  int intag=0,c;

  if (!text) { yyerror("Internal error: get_num_glyphs got NULL text"); exit(-1); }

  len0=strlen(text)+1;
  while ((c=kate_text_get_character(kate_utf8,&text,&len0))>0) {
    if (c=='<') intag++;
    if (!intag) ++nglyphs;
    if (c=='>') intag--;
  }
  return nglyphs;
}

static void init_simple_glyph_pointer_motion(void)
{
  init_motion();
  kmotion->semantics=kate_motion_semantics_glyph_pointer_1;
  karaoke_base_height=(kate_float)0;
  karaoke_top_height=(kate_float)0;
}

static int get_glyph_pointer_offset(unsigned int pointer_id)
{
  if (pointer_id<1 || pointer_id>4) {
    yyerrorf("Only glyph pointers 1-4 are available (trying to set %d)",pointer_id);
    exit(-1);
  }
  return (kate_motion_semantics)(kate_motion_semantics_glyph_pointer_1+pointer_id-1);
}

static kate_float get_last_glyph_x(const kate_motion *km)
{
  const kate_curve *kc;
  if (!km) { yyerror("internal error: no motion"); exit(-1); }
  if (km->ncurves==0) return (kate_float)-0.5; /* by default, center of the glyph before the first one (eg, marks nothing yet) */
  kc=km->curves[km->ncurves-1];
  if (kc->npts<1) yyerror("internal error: no points in last curve");
  return kc->pts[kc->npts*2-2]; /* -1 would be y */
}

static kate_float compute_karaoke_height(float y)
{
  /* turn height (bottom to top) to screen coordinates (top to bottom): negate */
  return -(karaoke_base_height*(1-y)+karaoke_top_height*y);
}

static void add_glyph_pause(kate_float dt,kate_float y)
{
  init_curve();
  kcurve.curve->type=kate_curve_static;
  kcurve.curve->npts=1;
  kcurve.curve->pts=(kate_float*)kate_malloc(kcurve.curve->npts*2*sizeof(kate_float));
  if (!kcurve.curve->pts) { yyerror("out of memory"); exit(-1); }
  kcurve.curve->pts[0]=get_last_glyph_x(kmotion);
  kcurve.curve->pts[1]=compute_karaoke_height(y);
  add_curve_to_motion(kmotion,dt);
}

static void add_glyph_transition(unsigned int glyph,kate_float dt,kate_float ystart,kate_float ytop,int absolute,kate_float pause_fraction)
{
  /* get the last glyph position and the new one */
  kate_float x0=get_last_glyph_x(kmotion);
  kate_float x1=glyph+(kate_float)0.5;
  size_t n;

  /* convert absolute to relative */
  if (absolute) {
    for (n=0;n<kmotion->ncurves;++n) dt-=kmotion->durations[n];
  }

  if (dt<(kate_float)0.0) {
    yyerrorf("duration (%f) must not be negative\n",dt);
    exit(-1);
  }

  /* add a pause before the next jump */
  if (pause_fraction>(kate_float)0.0) {
    kate_float delay=dt*pause_fraction;
    add_glyph_pause(delay,ystart);
    dt-=delay;
    if (dt<(kate_float)0.0) dt=(kate_float)0.0;
    x0=get_last_glyph_x(kmotion);
  }

  init_curve();

  if (dt==(kate_float)0.0) {
    /* if zero duration, just add static point at the end point */
    kcurve.curve->type=kate_curve_static;
    kcurve.curve->npts=1;
    kcurve.curve->pts=(kate_float*)kate_malloc(kcurve.curve->npts*2*sizeof(kate_float));
    if (!kcurve.curve->pts) { yyerror("out of memory"); exit(-1); }
    /* directly at the end position */
    kcurve.curve->pts[0]=x1;
    kcurve.curve->pts[1]=compute_karaoke_height(ystart);
  }
  else {
    kcurve.curve->type=kate_curve_catmull_rom_spline;
    kcurve.curve->npts=3+2; /* the two end points are duplicated */
    kcurve.curve->pts=(kate_float*)kate_malloc(kcurve.curve->npts*2*sizeof(kate_float));
    if (!kcurve.curve->pts) { yyerror("out of memory"); exit(-1); }

    /* start position */
    kcurve.curve->pts[0]=kcurve.curve->pts[2]=x0;
    kcurve.curve->pts[1]=kcurve.curve->pts[3]=compute_karaoke_height(ystart);

    /* the interpolated points */
    for (n=2;n<kcurve.curve->npts-2;++n) {
      kate_float t=(n-1)/(kate_float)(kcurve.curve->npts-2-1);
      kcurve.curve->pts[n*2]=kcurve.curve->pts[n*2+2]=x1*t+x0*((kate_float)1.0-t);
      kcurve.curve->pts[n*2+1]=kcurve.curve->pts[n*2+3]=compute_karaoke_height(ytop);
    }

    /* end position */
    kcurve.curve->pts[kcurve.curve->npts*2-4]=kcurve.curve->pts[kcurve.curve->npts*2-2]=x1;
    kcurve.curve->pts[kcurve.curve->npts*2-3]=kcurve.curve->pts[kcurve.curve->npts*2-1]=compute_karaoke_height(ystart);
  }

  add_curve_to_motion(kmotion,dt);
}

static void add_glyph_transition_to_text(const char *text,kate_float dt,kate_float ystart,kate_float ytop,int absolute,kate_float pause_fraction)
{
  char *newtext;

  if (!text) {
    yyerror("null text");
    return;
  }

  if (kevent.text) {
    char *text2=(char*)kate_realloc(kevent.text,strlen(kevent.text)+strlen(text)+1);
    if (!text2) {
      yyerror("out of memory");
      return;
    }
    strcat(text2,text);
    kevent.text=text2;
  }
  else {
    char *text2=(char*)kate_malloc(strlen(text)+1);
    if (!text2) {
      yyerror("out of memory");
      return;
    }
    strcpy(text2,text);
    kevent.text=text2;
  }

  backslash_n_to_newline(kevent.text);
  newtext=expand_numeric_entities(kevent.text);
  if (!newtext) return;
  kate_free(kevent.text);
  kevent.text=newtext;

  add_glyph_transition(get_num_glyphs(kevent.text)-1,dt,ystart,ytop,absolute,pause_fraction);
}

static void set_style_morph(kd_event *ev,int from,int to)
{
  int ret;

  if (!ev) {
    yyerror("internal error: no event");
    exit(-1);
  }
  if (from<0 || to<0) {
    yyerror("error: style index cannot be negative");
    exit(-1);
  }

  if (ev->style_index>=0 || ev->style) { yyerror("style already set"); return; }
  ev->style_index=from;
  ret=kate_encode_set_style_index(&k,from);
  if (ret<0) yyerrorf("failed to set style index: %d",ret);

  if (ev->secondary_style_index>=0 || ev->secondary_style) { yyerror("secondary style already set"); return; }
  ev->secondary_style_index=to;
  ret=kate_encode_set_secondary_style_index(&k,to);
  if (ret<0) yyerrorf("failed to set secondary_style index: %d",ret);
}

static void clear_local_bitmaps(void)
{
  size_t n;

  if (local_bitmap_names) {
    for (n=0;n<n_local_bitmaps;++n) {
      if (local_bitmap_names[n]) kate_free(local_bitmap_names[n]);
      if (local_bitmaps[n]) {
        if(local_bitmaps[n]->meta) kate_meta_destroy(local_bitmaps[n]->meta);
        kate_free(local_bitmaps[n]->pixels);
        kate_free(local_bitmaps[n]);
      }
    }
    kate_free(local_bitmap_names);
    local_bitmap_names=NULL;
    kate_free(local_bitmaps);
    local_bitmaps=NULL;
  }
  n_local_bitmaps=0;
}

static void clear_event(kd_event *ev)
{
  if (!ev) {
    yyerror("internal error: no event");
    exit(-1);
  }
  if (ev->text) {
    kate_free(ev->text);
    ev->text=NULL;
  }
  clear_motions();
  clear_local_bitmaps();
}

static void kd_finalize_simple_timed_glyph_motion(kate_motion *kmotion)
{
  const kd_event *ev=&kevent;
  kate_float duration=ev->duration;
  kate_float t0=ev->t0,t1=ev->t1;
  kate_float duration_so_far;
  size_t n;
  int sets;

  if (!kmotion) {
    yyerror("internal error: kd_finalize_simple_timed_glyph_motion passed NULL motion");
    exit(-1);
  }

  /* for this helper motion, we require the timing of the event to be known in advance */
  sets=0;
  if (t0>=(kate_float)0.0) ++sets;
  if (t1>=(kate_float)0.0) ++sets;
  if (duration>=(kate_float)0.0) ++sets;
  if (sets<2) { yyerror("start/end times must be specified before timed glyph marker motion setup"); return; }
  if (sets>2) { yyerror("start/end times overspecified"); return; }

  if (t0<(kate_float)0.0) t0=t1-duration;
  if (t1<(kate_float)0.0) t1=t0+duration;
  duration=t1-t0;

  /* add a pause to take us to the end time */
  duration_so_far=(kate_float)0.0;
  for (n=0;n<kmotion->ncurves;++n) duration_so_far+=kmotion->durations[n];
  if (duration_so_far>duration) {
    yyerrorf("Simple timed glyph motion lasts longer than its event (motion %f, event %f)",duration_so_far,duration);
    exit(-1);
  }
  add_glyph_pause(duration-duration_so_far,(kate_float)1.0);
}

static void set_motion_mapping(kate_motion *kmotion,kate_motion_mapping x_mapping,kate_motion_mapping y_mapping)
{
  if (!kmotion) {
    yyerror("internal error: set_motion_mapping passed NULL motion");
    exit(-1);
  }

  kmotion->x_mapping=x_mapping;
  kmotion->y_mapping=y_mapping;
}

static void set_motion_semantics(kate_motion *kmotion,kate_motion_semantics semantics)
{
  if (!kmotion) {
    yyerror("internal error: set_motion_semantics passed NULL motion");
    exit(-1);
  }

  if (kmotion->semantics!=(kate_motion_semantics)-1) { yyerror("semantics is already defined"); return; }
  kmotion->semantics=semantics;
}

static kate_motion_semantics kd_get_marker_position_semantics(int n)
{
  switch (n) {
    case 1: return kate_motion_semantics_marker1_position;
    case 2: return kate_motion_semantics_marker2_position;
    case 3: return kate_motion_semantics_marker3_position;
    case 4: return kate_motion_semantics_marker4_position;
    default: yyerrorf("Invalid marker number: %d (only 1-4 are supported)",n); exit(-1);
  }
  return kate_motion_semantics_marker4_position;
}

static kate_motion_semantics kd_get_marker_bitmap_semantics(int n)
{
  switch (n) {
    case 1: return kate_motion_semantics_marker1_bitmap;
    case 2: return kate_motion_semantics_marker2_bitmap;
    case 3: return kate_motion_semantics_marker3_bitmap;
    case 4: return kate_motion_semantics_marker4_bitmap;
    default: yyerrorf("Invalid marker number: %d (only 1-4 are supported)",n); exit(-1);
  }
  return kate_motion_semantics_marker4_bitmap;
}

static kate_motion_semantics kd_get_glyph_pointer_semantics(int n)
{
  switch (n) {
    case 1: return kate_motion_semantics_glyph_pointer_1;
    case 2: return kate_motion_semantics_glyph_pointer_2;
    case 3: return kate_motion_semantics_glyph_pointer_3;
    case 4: return kate_motion_semantics_glyph_pointer_4;
    default: yyerrorf("Invalid glyph pointer number: %d (only 1-4 are supported)",n); exit(-1);
  }
  return kate_motion_semantics_glyph_pointer_4;
}

static kate_motion_semantics kd_get_glyph_pointer_bitmap_semantics(int n)
{
  switch (n) {
    case 1: return kate_motion_semantics_glyph_pointer_1_bitmap;
    case 2: return kate_motion_semantics_glyph_pointer_2_bitmap;
    case 3: return kate_motion_semantics_glyph_pointer_3_bitmap;
    case 4: return kate_motion_semantics_glyph_pointer_4_bitmap;
    default: yyerrorf("Invalid glyph pointer number: %d (only 1-4 are supported)",n); exit(-1);
  }
  return kate_motion_semantics_glyph_pointer_4_bitmap;
}

static void kd_add_event_motion(kate_motion *kmotion)
{
  int ret;

  if (!kmotion) {
    yyerror("internal error: kd_add_event_motion passed NULL motion");
    exit(-1);
  }

  check_motion(kmotion);
  ret=kate_encode_add_motion(&k,kmotion,1);
  if (ret<0) {
    yyerrorf("failed to add motion: %d",ret);
    exit(-1);
  }
  clear_motions();
}

static void kd_add_event_motion_index(size_t idx)
{
  int ret;

  if (idx>=ki.nmotions) { yyerrorf("Motion index %u out of range (%u motions available)",idx,ki.nmotions); exit(-1); }

  ret=kate_encode_add_motion_index(&k,idx);
  if (ret<0) {
    yyerrorf("failed to add motion: %d",ret);
    exit(-1);
  }
  clear_motions();
}

static void init_font_range(void)
{
  krange=(kate_font_range*)kate_malloc(sizeof(kate_font_range));
  if (!krange) { yyerror("out of memory"); exit(-1); }
  krange->first_code_point=-1;
  krange->last_code_point=-1;
  krange->first_bitmap=-1;
}

static void set_font_range_code_point_string(int *cp,const char *s)
{
  size_t len0;
  int ret,c;

  if (!cp) { yyerror("internal error: no code point pointer"); exit(-1); }
  if (!s) { yyerror("internal error: no string"); exit(-1); }
  len0=strlen(s)+1;
  ret=kate_text_get_character(kate_utf8,&s,&len0);
  if (ret<0) {
    yyerrorf("failed to get character from string: %d",ret);
    return;
  }
  c=ret;
  ret=kate_text_get_character(kate_utf8,&s,&len0);
  if (ret<0) {
    yyerrorf("failed to get character from string: %d",ret);
    return;
  }
  if (ret) {
    yyerror("code point string should contain only one character");
    return;
  }
  *cp=c;
}

static void set_font_range_first_code_point_string(const char *s)
{
  if (!s) { yyerror("internal error: no string"); exit(-1); }
  if (!krange) { yyerror("internal error: no font range"); exit(-1); }
  set_font_range_code_point_string(&krange->first_code_point,s);
}

static void set_font_range_last_code_point_string(const char *s)
{
  if (!s) { yyerror("internal error: no string"); exit(-1); }
  if (!krange) { yyerror("internal error: no font range"); exit(-1); }
  set_font_range_code_point_string(&krange->last_code_point,s);
}

static void set_font_range_first_code_point(int idx)
{
  if (!krange) { yyerror("internal error: no font range"); exit(-1); }
  krange->first_code_point=idx;
}

static void set_font_range_last_code_point(int idx)
{
  if (!krange) { yyerror("internal error: no font range"); exit(-1); }
  krange->last_code_point=idx;
}

static void set_font_range_first_bitmap(int idx)
{
  if (!krange) { yyerror("internal error: no font range"); exit(-1); }
  krange->first_bitmap=idx;
}

static void add_font_range(kate_info *ki,const char *name,kate_font_range *kfr)
{
  int ret;
  if (!ki || !kfr) { yyerror("internal error: no kate_info or kate_font_range"); exit(-1); }
  if (!krange) { yyerror("internal error: no font range"); exit(-1); }
  if (krange->first_code_point<0) yyerror("first code point not set");
  if (krange->last_code_point<0) yyerror("last code point not set");
  if (krange->last_code_point<krange->first_code_point) yyerror("last code point cannnot be less than first code point");
  if (krange->first_bitmap<0) yyerror("bitmap index not set");
  ret=kate_info_add_font_range(ki,kfr);
  if (ret<0) {
    yyerrorf("failed to add font range: %d",ret);
  }
  else {
    font_range_names=(char**)kate_realloc(font_range_names,ki->nfont_ranges*sizeof(char*));
    if (!font_range_names) {
      yyerror("Out of memory");
      exit(-1);
    }
    font_range_names[ki->nfont_ranges-1]=name?dupstring(name):NULL;
  }
}

static int find_font_range(const kate_info *ki,const char *name)
{
  return find_item(name,ki->nfont_ranges,font_range_names);
}

static void init_font_mapping(void)
{
  kmapping=(kate_font_mapping*)kate_malloc(sizeof(kate_font_mapping));
  if (!kmapping) { yyerror("out of memory"); exit(-1); }
  kmapping->nranges=0;
  kmapping->ranges=NULL;
}

static int check_font_overlap(const kate_font_range *kfr0,const kate_font_range *kfr1)
{
  if (!kfr0 || !kfr1) return KATE_E_INVALID_PARAMETER;

  if (kfr0->last_code_point<kfr1->first_code_point) return 0;
  if (kfr1->last_code_point<kfr0->first_code_point) return 0;

  return KATE_E_INIT;
}

static int check_font_ranges(const kate_font_mapping *kfm)
{
  size_t n,l;

  if (!kfm) return KATE_E_INVALID_PARAMETER;

  for (n=0;n<kfm->nranges;++n) {
    const kate_font_range *kfr=kfm->ranges[n];
    if (!kfr) return KATE_E_INIT;
    if (kfr->last_code_point<kfr->first_code_point) return KATE_E_INIT;
    for (l=n+1;l<kfm->nranges;++l) {
      int ret=check_font_overlap(kfr,kfm->ranges[l]);
      if (ret<0) return ret;
    }
  }

  return 0;
}

static void add_font_range_to_mapping(void)
{
  int ret;

  if (!krange) { yyerror("internal error: no font range"); exit(-1); }
  if (!kmapping) { yyerror("internal error: no font mapping"); exit(-1); }

  kmapping->ranges=(kate_font_range**)kate_realloc(kmapping->ranges,(kmapping->nranges+1)*sizeof(kate_font_range*));
  if (!kmapping->ranges) {
    yyerror("error: out of memory");
    exit(-1);
  }
  kmapping->ranges[kmapping->nranges]=krange;
  ++kmapping->nranges;

  ret=check_font_ranges(kmapping);
  if (ret<0) yyerror("font mapping ranges overlap");

  krange=NULL;
}

static void add_font_mapping(kate_info *ki,const char *name,kate_font_mapping *kfm)
{
  int ret;
  if (!ki) { yyerror("internal error: no kate_info"); exit(-1); }
  if (!kfm) { yyerror("internal error: no font mapping"); exit(-1); }
  if (kfm->nranges==0) yyerror("font mapping has no ranges");
  ret=kate_info_add_font_mapping(ki,kfm);
  if (ret<0) {
    yyerrorf("failed to add font mapping: %d",ret);
  }
  else {
    font_mapping_names=(char**)kate_realloc(font_mapping_names,ki->nfont_mappings*sizeof(char*));
    if (!font_mapping_names) {
      yyerror("Out of memory");
      exit(-1);
    }
    font_mapping_names[ki->nfont_mappings-1]=name?dupstring(name):NULL;
  }
}

static int find_font_mapping(const kate_info *ki,const char *name)
{
  return find_item(name,ki->nfont_mappings,font_mapping_names);
}

static void kd_write_headers(void)
{
  int ret=write_headers(katedesc_out);
  if (ret<0) {
    yyerrorf("Failed to write headers: %d\n",ret);
    exit(-1);
  }
}

static void kd_encode_text(kate_state *kstate,kd_event *ev)
{
  int ret;
  ogg_packet op;

  if (!ev) { yyerror("internal error: no event"); exit(-1); }
  ret=kate_encode_set_markup_type(kstate,ev->text_markup_type);
  if (ret<0) {
    yyerrorf("failed to set text markup type: %d",ret);
    return;
  }
  update_stream_time(kstate,katedesc_out,kate_duration_granule(kstate->ki,timebase+ev->t0));
  ret=kate_ogg_encode_text(kstate,timebase+ev->t0,timebase+ev->t1,ev->text?ev->text:"",ev->text?strlen(ev->text):0,&op);
  if (ret<0) {
    yyerrorf("failed to encode text %s: %d",ev->text?ev->text:"<none>",ret);
    return;
  }
  ret=send_packet(katedesc_out,&op,kate_duration_granule(kstate->ki,timebase+ev->t0));
  if (ret<0) {
    yyerrorf("failed to send text packet: %d",ret);
  }
}

static void kd_encode_set_language(kate_state *kstate,const char *s)
{
  int ret;
  if (!s) { yyerror("internal error: no language string"); exit(-1); }
  ret=kate_encode_set_language(kstate,s);
  if (ret<0) yyerrorf("failed to set event language override: %d",ret);
}

static uint32_t make_color(uint32_t r,uint32_t g,uint32_t b,uint32_t a)
{
  return (r<<24)|(g<<16)|(b<<8)|a;
}

static uint32_t make_color_alpha(uint32_t c,uint32_t a)
{
  return (c&0xffffff00)|a;
}

static void record_macro_name(const char *name)
{
  size_t len;
  if (!name) { yyerror("internal error: no macro name"); exit(-1); }
  len=strlen(name);
  if (temp_macro_name) kate_free(temp_macro_name);
  temp_macro_name=kate_malloc(len+1);
  if (!temp_macro_name) { yyerror("out of memory"); exit(-1); }
  strcpy(temp_macro_name,name);
}

static void add_temp_macro(const char *body)
{
  if (!body) { yyerror("internal error: no macro body"); exit(-1); }
  if (!temp_macro_name) { yyerror("internal error - unknown macro name"); return; }
  add_macro(temp_macro_name,body);
  kate_free(temp_macro_name);
  temp_macro_name=NULL;
}

static void set_granule_rate(unsigned int numerator,unsigned int denominator)
{
  ki.gps_numerator=numerator;
  ki.gps_denominator=denominator;
}

static void set_granule_shift(unsigned int granule_shift)
{
  if (granule_shift>=64) yyerror("granule shift out of range (0-64)\n");
  ki.granule_shift=granule_shift;
}

static void set_canvas_size(unsigned int width,unsigned int height)
{
  int ret=kate_info_set_original_canvas_size(&ki,width,height);
  if (ret<0) {
    yyerror("failed to set original canvas size");
    exit(-1);
  }
}

static void add_comment(kate_comment *kc,const char *s)
{
  /* check for "ENCODER=," as kateenc now sets it and we don't want cycles
     of decode/encode to duplicate them, and we want the new one to replace
     any existing one */
  int different=0;
  const char *encoder="ENCODER=",*sptr=s;
  while (*encoder) if ((*encoder++|32)!=(*sptr++|32)) {
    different=1;
    break;
  }
  if (different) {
    CHECK_KATE_API_ERROR(kate_comment_add(kc,s));
  }
}

static void cleanup_names(char **names,size_t count)
{
  size_t n;
  if (names) {
    for (n=0;n<count;++n) if (names[n]) kate_free(names[n]);
    kate_free(names);
  }
}

static void cleanup_memory(void)
{
  cleanup_names(style_names,ki.nstyles);
  cleanup_names(region_names,ki.nregions);
  cleanup_names(curve_names,ki.ncurves);
  cleanup_names(motion_names,ki.nmotions);
  cleanup_names(bitmap_names,ki.nbitmaps);
  cleanup_names(palette_names,ki.npalettes);
  cleanup_names(font_range_names,ki.nfont_ranges);
  cleanup_names(font_mapping_names,ki.nfont_mappings);
  cleanup_names(local_bitmap_names,n_local_bitmaps);

  free_macros();
}



#line 2264 "kate_parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_KATEDESC_KATE_PARSER_H_INCLUDED
# define YY_KATEDESC_KATE_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int katedesc_debug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KATE = 258,                    /* KATE  */
    DEFS = 259,                    /* DEFS  */
    LANGUAGE = 260,                /* LANGUAGE  */
    COMMENT = 261,                 /* COMMENT  */
    CATEGORY = 262,                /* CATEGORY  */
    DEFINE = 263,                  /* DEFINE  */
    MACRO = 264,                   /* MACRO  */
    STYLE = 265,                   /* STYLE  */
    REGION = 266,                  /* REGION  */
    CURVE = 267,                   /* CURVE  */
    TEXT = 268,                    /* TEXT  */
    BACKGROUND = 269,              /* BACKGROUND  */
    COLOR = 270,                   /* COLOR  */
    POSITION = 271,                /* POSITION  */
    SIZE = 272,                    /* SIZE  */
    DEFAULT = 273,                 /* DEFAULT  */
    METRIC = 274,                  /* METRIC  */
    HALIGN = 275,                  /* HALIGN  */
    VALIGN = 276,                  /* VALIGN  */
    HLEFT = 277,                   /* HLEFT  */
    HCENTER = 278,                 /* HCENTER  */
    HRIGHT = 279,                  /* HRIGHT  */
    VTOP = 280,                    /* VTOP  */
    VCENTER = 281,                 /* VCENTER  */
    VBOTTOM = 282,                 /* VBOTTOM  */
    POINTS = 283,                  /* POINTS  */
    EVENT = 284,                   /* EVENT  */
    STARTS = 285,                  /* STARTS  */
    ENDS = 286,                    /* ENDS  */
    AT = 287,                      /* AT  */
    START = 288,                   /* START  */
    END = 289,                     /* END  */
    TIME = 290,                    /* TIME  */
    DURATION = 291,                /* DURATION  */
    ARROW = 292,                   /* ARROW  */
    FROM = 293,                    /* FROM  */
    TO = 294,                      /* TO  */
    MAPPING = 295,                 /* MAPPING  */
    NONE = 296,                    /* NONE  */
    FRAME = 297,                   /* FRAME  */
    MOTION = 298,                  /* MOTION  */
    BEZIER_CUBIC = 299,            /* BEZIER_CUBIC  */
    LINEAR = 300,                  /* LINEAR  */
    CATMULL_ROM = 301,             /* CATMULL_ROM  */
    BSPLINE = 302,                 /* BSPLINE  */
    STATIC = 303,                  /* STATIC  */
    SEMANTICS = 304,               /* SEMANTICS  */
    EXTERNAL = 305,                /* EXTERNAL  */
    INTERNAL = 306,                /* INTERNAL  */
    ALIGNMENT = 307,               /* ALIGNMENT  */
    RG = 308,                      /* RG  */
    BA = 309,                      /* BA  */
    FOR = 310,                     /* FOR  */
    ALPHA = 311,                   /* ALPHA  */
    TIMEBASE = 312,                /* TIMEBASE  */
    MARKER = 313,                  /* MARKER  */
    POINTER = 314,                 /* POINTER  */
    SIMPLE_TIMED_GLYPH_MARKER = 315, /* SIMPLE_TIMED_GLYPH_MARKER  */
    SIMPLE_TIMED_GLYPH_STYLE_MORPH = 316, /* SIMPLE_TIMED_GLYPH_STYLE_MORPH  */
    GLYPH = 317,                   /* GLYPH  */
    PAUSE = 318,                   /* PAUSE  */
    IN = 319,                      /* IN  */
    MORPH = 320,                   /* MORPH  */
    SECONDARY = 321,               /* SECONDARY  */
    PATH = 322,                    /* PATH  */
    SECTION = 323,                 /* SECTION  */
    PERIODIC = 324,                /* PERIODIC  */
    DIRECTIONALITY = 325,          /* DIRECTIONALITY  */
    L2R_T2B = 326,                 /* L2R_T2B  */
    R2L_T2B = 327,                 /* R2L_T2B  */
    T2B_R2L = 328,                 /* T2B_R2L  */
    T2B_L2R = 329,                 /* T2B_L2R  */
    BITMAP = 330,                  /* BITMAP  */
    PALETTE = 331,                 /* PALETTE  */
    COLORS = 332,                  /* COLORS  */
    FONT = 333,                    /* FONT  */
    RANGE = 334,                   /* RANGE  */
    FIRST = 335,                   /* FIRST  */
    LAST = 336,                    /* LAST  */
    CODE = 337,                    /* CODE  */
    POINT = 338,                   /* POINT  */
    USER = 339,                    /* USER  */
    SOURCE = 340,                  /* SOURCE  */
    PNG = 341,                     /* PNG  */
    DRAW = 342,                    /* DRAW  */
    VISIBLE = 343,                 /* VISIBLE  */
    ID = 344,                      /* ID  */
    BOLD = 345,                    /* BOLD  */
    ITALICS = 346,                 /* ITALICS  */
    UNDERLINE = 347,               /* UNDERLINE  */
    STRIKE = 348,                  /* STRIKE  */
    JUSTIFY = 349,                 /* JUSTIFY  */
    BASE = 350,                    /* BASE  */
    OFFSET = 351,                  /* OFFSET  */
    GRANULE = 352,                 /* GRANULE  */
    RATE = 353,                    /* RATE  */
    SHIFT = 354,                   /* SHIFT  */
    WIDTH = 355,                   /* WIDTH  */
    HEIGHT = 356,                  /* HEIGHT  */
    CANVAS = 357,                  /* CANVAS  */
    LEFT = 358,                    /* LEFT  */
    TOP = 359,                     /* TOP  */
    RIGHT = 360,                   /* RIGHT  */
    BOTTOM = 361,                  /* BOTTOM  */
    MARGIN = 362,                  /* MARGIN  */
    MARGINS = 363,                 /* MARGINS  */
    HORIZONTAL = 364,              /* HORIZONTAL  */
    VERTICAL = 365,                /* VERTICAL  */
    CLIP = 366,                    /* CLIP  */
    PRE = 367,                     /* PRE  */
    MARKUP = 368,                  /* MARKUP  */
    LOCAL = 369,                   /* LOCAL  */
    WRAP = 370,                    /* WRAP  */
    WORD = 371,                    /* WORD  */
    META = 372,                    /* META  */
    NUMBER = 373,                  /* NUMBER  */
    UNUMBER = 374,                 /* UNUMBER  */
    STRING = 375,                  /* STRING  */
    FLOAT = 376,                   /* FLOAT  */
    COLORSPEC = 377,               /* COLORSPEC  */
    IDENTIFIER = 378,              /* IDENTIFIER  */
    MACRO_BODY = 379               /* MACRO_BODY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define KATE 258
#define DEFS 259
#define LANGUAGE 260
#define COMMENT 261
#define CATEGORY 262
#define DEFINE 263
#define MACRO 264
#define STYLE 265
#define REGION 266
#define CURVE 267
#define TEXT 268
#define BACKGROUND 269
#define COLOR 270
#define POSITION 271
#define SIZE 272
#define DEFAULT 273
#define METRIC 274
#define HALIGN 275
#define VALIGN 276
#define HLEFT 277
#define HCENTER 278
#define HRIGHT 279
#define VTOP 280
#define VCENTER 281
#define VBOTTOM 282
#define POINTS 283
#define EVENT 284
#define STARTS 285
#define ENDS 286
#define AT 287
#define START 288
#define END 289
#define TIME 290
#define DURATION 291
#define ARROW 292
#define FROM 293
#define TO 294
#define MAPPING 295
#define NONE 296
#define FRAME 297
#define MOTION 298
#define BEZIER_CUBIC 299
#define LINEAR 300
#define CATMULL_ROM 301
#define BSPLINE 302
#define STATIC 303
#define SEMANTICS 304
#define EXTERNAL 305
#define INTERNAL 306
#define ALIGNMENT 307
#define RG 308
#define BA 309
#define FOR 310
#define ALPHA 311
#define TIMEBASE 312
#define MARKER 313
#define POINTER 314
#define SIMPLE_TIMED_GLYPH_MARKER 315
#define SIMPLE_TIMED_GLYPH_STYLE_MORPH 316
#define GLYPH 317
#define PAUSE 318
#define IN 319
#define MORPH 320
#define SECONDARY 321
#define PATH 322
#define SECTION 323
#define PERIODIC 324
#define DIRECTIONALITY 325
#define L2R_T2B 326
#define R2L_T2B 327
#define T2B_R2L 328
#define T2B_L2R 329
#define BITMAP 330
#define PALETTE 331
#define COLORS 332
#define FONT 333
#define RANGE 334
#define FIRST 335
#define LAST 336
#define CODE 337
#define POINT 338
#define USER 339
#define SOURCE 340
#define PNG 341
#define DRAW 342
#define VISIBLE 343
#define ID 344
#define BOLD 345
#define ITALICS 346
#define UNDERLINE 347
#define STRIKE 348
#define JUSTIFY 349
#define BASE 350
#define OFFSET 351
#define GRANULE 352
#define RATE 353
#define SHIFT 354
#define WIDTH 355
#define HEIGHT 356
#define CANVAS 357
#define LEFT 358
#define TOP 359
#define RIGHT 360
#define BOTTOM 361
#define MARGIN 362
#define MARGINS 363
#define HORIZONTAL 364
#define VERTICAL 365
#define CLIP 366
#define PRE 367
#define MARKUP 368
#define LOCAL 369
#define WRAP 370
#define WORD 371
#define META 372
#define NUMBER 373
#define UNUMBER 374
#define STRING 375
#define FLOAT 376
#define COLORSPEC 377
#define IDENTIFIER 378
#define MACRO_BODY 379

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 2200 "kate_parser.y"

  int number;
  unsigned int unumber;
  kate_float fp;
  const char *string;
  char *dynstring;
  kate_style *style;
  kate_region *region;
  kate_curve *curve;
  uint32_t color;

#line 2577 "kate_parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int katedesc_parse (void);


#endif /* !YY_KATEDESC_KATE_PARSER_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KATE = 3,                       /* KATE  */
  YYSYMBOL_DEFS = 4,                       /* DEFS  */
  YYSYMBOL_LANGUAGE = 5,                   /* LANGUAGE  */
  YYSYMBOL_COMMENT = 6,                    /* COMMENT  */
  YYSYMBOL_CATEGORY = 7,                   /* CATEGORY  */
  YYSYMBOL_DEFINE = 8,                     /* DEFINE  */
  YYSYMBOL_MACRO = 9,                      /* MACRO  */
  YYSYMBOL_STYLE = 10,                     /* STYLE  */
  YYSYMBOL_REGION = 11,                    /* REGION  */
  YYSYMBOL_CURVE = 12,                     /* CURVE  */
  YYSYMBOL_TEXT = 13,                      /* TEXT  */
  YYSYMBOL_BACKGROUND = 14,                /* BACKGROUND  */
  YYSYMBOL_COLOR = 15,                     /* COLOR  */
  YYSYMBOL_POSITION = 16,                  /* POSITION  */
  YYSYMBOL_SIZE = 17,                      /* SIZE  */
  YYSYMBOL_DEFAULT = 18,                   /* DEFAULT  */
  YYSYMBOL_METRIC = 19,                    /* METRIC  */
  YYSYMBOL_HALIGN = 20,                    /* HALIGN  */
  YYSYMBOL_VALIGN = 21,                    /* VALIGN  */
  YYSYMBOL_HLEFT = 22,                     /* HLEFT  */
  YYSYMBOL_HCENTER = 23,                   /* HCENTER  */
  YYSYMBOL_HRIGHT = 24,                    /* HRIGHT  */
  YYSYMBOL_VTOP = 25,                      /* VTOP  */
  YYSYMBOL_VCENTER = 26,                   /* VCENTER  */
  YYSYMBOL_VBOTTOM = 27,                   /* VBOTTOM  */
  YYSYMBOL_POINTS = 28,                    /* POINTS  */
  YYSYMBOL_EVENT = 29,                     /* EVENT  */
  YYSYMBOL_STARTS = 30,                    /* STARTS  */
  YYSYMBOL_ENDS = 31,                      /* ENDS  */
  YYSYMBOL_AT = 32,                        /* AT  */
  YYSYMBOL_START = 33,                     /* START  */
  YYSYMBOL_END = 34,                       /* END  */
  YYSYMBOL_TIME = 35,                      /* TIME  */
  YYSYMBOL_DURATION = 36,                  /* DURATION  */
  YYSYMBOL_ARROW = 37,                     /* ARROW  */
  YYSYMBOL_FROM = 38,                      /* FROM  */
  YYSYMBOL_TO = 39,                        /* TO  */
  YYSYMBOL_MAPPING = 40,                   /* MAPPING  */
  YYSYMBOL_NONE = 41,                      /* NONE  */
  YYSYMBOL_FRAME = 42,                     /* FRAME  */
  YYSYMBOL_MOTION = 43,                    /* MOTION  */
  YYSYMBOL_BEZIER_CUBIC = 44,              /* BEZIER_CUBIC  */
  YYSYMBOL_LINEAR = 45,                    /* LINEAR  */
  YYSYMBOL_CATMULL_ROM = 46,               /* CATMULL_ROM  */
  YYSYMBOL_BSPLINE = 47,                   /* BSPLINE  */
  YYSYMBOL_STATIC = 48,                    /* STATIC  */
  YYSYMBOL_SEMANTICS = 49,                 /* SEMANTICS  */
  YYSYMBOL_EXTERNAL = 50,                  /* EXTERNAL  */
  YYSYMBOL_INTERNAL = 51,                  /* INTERNAL  */
  YYSYMBOL_ALIGNMENT = 52,                 /* ALIGNMENT  */
  YYSYMBOL_RG = 53,                        /* RG  */
  YYSYMBOL_BA = 54,                        /* BA  */
  YYSYMBOL_FOR = 55,                       /* FOR  */
  YYSYMBOL_ALPHA = 56,                     /* ALPHA  */
  YYSYMBOL_TIMEBASE = 57,                  /* TIMEBASE  */
  YYSYMBOL_MARKER = 58,                    /* MARKER  */
  YYSYMBOL_POINTER = 59,                   /* POINTER  */
  YYSYMBOL_SIMPLE_TIMED_GLYPH_MARKER = 60, /* SIMPLE_TIMED_GLYPH_MARKER  */
  YYSYMBOL_SIMPLE_TIMED_GLYPH_STYLE_MORPH = 61, /* SIMPLE_TIMED_GLYPH_STYLE_MORPH  */
  YYSYMBOL_GLYPH = 62,                     /* GLYPH  */
  YYSYMBOL_PAUSE = 63,                     /* PAUSE  */
  YYSYMBOL_IN = 64,                        /* IN  */
  YYSYMBOL_MORPH = 65,                     /* MORPH  */
  YYSYMBOL_SECONDARY = 66,                 /* SECONDARY  */
  YYSYMBOL_PATH = 67,                      /* PATH  */
  YYSYMBOL_SECTION = 68,                   /* SECTION  */
  YYSYMBOL_PERIODIC = 69,                  /* PERIODIC  */
  YYSYMBOL_DIRECTIONALITY = 70,            /* DIRECTIONALITY  */
  YYSYMBOL_L2R_T2B = 71,                   /* L2R_T2B  */
  YYSYMBOL_R2L_T2B = 72,                   /* R2L_T2B  */
  YYSYMBOL_T2B_R2L = 73,                   /* T2B_R2L  */
  YYSYMBOL_T2B_L2R = 74,                   /* T2B_L2R  */
  YYSYMBOL_BITMAP = 75,                    /* BITMAP  */
  YYSYMBOL_PALETTE = 76,                   /* PALETTE  */
  YYSYMBOL_COLORS = 77,                    /* COLORS  */
  YYSYMBOL_FONT = 78,                      /* FONT  */
  YYSYMBOL_RANGE = 79,                     /* RANGE  */
  YYSYMBOL_FIRST = 80,                     /* FIRST  */
  YYSYMBOL_LAST = 81,                      /* LAST  */
  YYSYMBOL_CODE = 82,                      /* CODE  */
  YYSYMBOL_POINT = 83,                     /* POINT  */
  YYSYMBOL_USER = 84,                      /* USER  */
  YYSYMBOL_SOURCE = 85,                    /* SOURCE  */
  YYSYMBOL_PNG = 86,                       /* PNG  */
  YYSYMBOL_DRAW = 87,                      /* DRAW  */
  YYSYMBOL_VISIBLE = 88,                   /* VISIBLE  */
  YYSYMBOL_ID = 89,                        /* ID  */
  YYSYMBOL_BOLD = 90,                      /* BOLD  */
  YYSYMBOL_ITALICS = 91,                   /* ITALICS  */
  YYSYMBOL_UNDERLINE = 92,                 /* UNDERLINE  */
  YYSYMBOL_STRIKE = 93,                    /* STRIKE  */
  YYSYMBOL_JUSTIFY = 94,                   /* JUSTIFY  */
  YYSYMBOL_BASE = 95,                      /* BASE  */
  YYSYMBOL_OFFSET = 96,                    /* OFFSET  */
  YYSYMBOL_GRANULE = 97,                   /* GRANULE  */
  YYSYMBOL_RATE = 98,                      /* RATE  */
  YYSYMBOL_SHIFT = 99,                     /* SHIFT  */
  YYSYMBOL_WIDTH = 100,                    /* WIDTH  */
  YYSYMBOL_HEIGHT = 101,                   /* HEIGHT  */
  YYSYMBOL_CANVAS = 102,                   /* CANVAS  */
  YYSYMBOL_LEFT = 103,                     /* LEFT  */
  YYSYMBOL_TOP = 104,                      /* TOP  */
  YYSYMBOL_RIGHT = 105,                    /* RIGHT  */
  YYSYMBOL_BOTTOM = 106,                   /* BOTTOM  */
  YYSYMBOL_MARGIN = 107,                   /* MARGIN  */
  YYSYMBOL_MARGINS = 108,                  /* MARGINS  */
  YYSYMBOL_HORIZONTAL = 109,               /* HORIZONTAL  */
  YYSYMBOL_VERTICAL = 110,                 /* VERTICAL  */
  YYSYMBOL_CLIP = 111,                     /* CLIP  */
  YYSYMBOL_PRE = 112,                      /* PRE  */
  YYSYMBOL_MARKUP = 113,                   /* MARKUP  */
  YYSYMBOL_LOCAL = 114,                    /* LOCAL  */
  YYSYMBOL_WRAP = 115,                     /* WRAP  */
  YYSYMBOL_WORD = 116,                     /* WORD  */
  YYSYMBOL_META = 117,                     /* META  */
  YYSYMBOL_NUMBER = 118,                   /* NUMBER  */
  YYSYMBOL_UNUMBER = 119,                  /* UNUMBER  */
  YYSYMBOL_STRING = 120,                   /* STRING  */
  YYSYMBOL_FLOAT = 121,                    /* FLOAT  */
  YYSYMBOL_COLORSPEC = 122,                /* COLORSPEC  */
  YYSYMBOL_IDENTIFIER = 123,               /* IDENTIFIER  */
  YYSYMBOL_MACRO_BODY = 124,               /* MACRO_BODY  */
  YYSYMBOL_125_ = 125,                     /* '{'  */
  YYSYMBOL_126_ = 126,                     /* '}'  */
  YYSYMBOL_127_ = 127,                     /* '/'  */
  YYSYMBOL_128_ = 128,                     /* '='  */
  YYSYMBOL_129_ = 129,                     /* '%'  */
  YYSYMBOL_130_m_ = 130,                   /* 'm'  */
  YYSYMBOL_131_x_ = 131,                   /* 'x'  */
  YYSYMBOL_132_ = 132,                     /* ':'  */
  YYSYMBOL_133_ = 133,                     /* '+'  */
  YYSYMBOL_134_z_ = 134,                   /* 'z'  */
  YYSYMBOL_135_Y_ = 135,                   /* 'Y'  */
  YYSYMBOL_136_ = 136,                     /* ','  */
  YYSYMBOL_YYACCEPT = 137,                 /* $accept  */
  YYSYMBOL_kd_kate = 138,                  /* kd_kate  */
  YYSYMBOL_139_1 = 139,                    /* $@1  */
  YYSYMBOL_140_2 = 140,                    /* $@2  */
  YYSYMBOL_kd_opt_defs = 141,              /* kd_opt_defs  */
  YYSYMBOL_kd_defs = 142,                  /* kd_defs  */
  YYSYMBOL_kd_def = 143,                   /* kd_def  */
  YYSYMBOL_144_3 = 144,                    /* $@3  */
  YYSYMBOL_145_4 = 145,                    /* $@4  */
  YYSYMBOL_146_5 = 146,                    /* $@5  */
  YYSYMBOL_147_6 = 147,                    /* $@6  */
  YYSYMBOL_148_7 = 148,                    /* $@7  */
  YYSYMBOL_149_8 = 149,                    /* $@8  */
  YYSYMBOL_150_9 = 150,                    /* $@9  */
  YYSYMBOL_151_10 = 151,                   /* $@10  */
  YYSYMBOL_152_11 = 152,                   /* $@11  */
  YYSYMBOL_153_12 = 153,                   /* $@12  */
  YYSYMBOL_kd_style_defs = 154,            /* kd_style_defs  */
  YYSYMBOL_kd_style_def = 155,             /* kd_style_def  */
  YYSYMBOL_156_13 = 156,                   /* $@13  */
  YYSYMBOL_kd_opt_space_metric = 157,      /* kd_opt_space_metric  */
  YYSYMBOL_kd_region_defs = 158,           /* kd_region_defs  */
  YYSYMBOL_kd_region_def = 159,            /* kd_region_def  */
  YYSYMBOL_160_14 = 160,                   /* $@14  */
  YYSYMBOL_kd_curve_defs = 161,            /* kd_curve_defs  */
  YYSYMBOL_kd_curve_def = 162,             /* kd_curve_def  */
  YYSYMBOL_163_15 = 163,                   /* $@15  */
  YYSYMBOL_164_16 = 164,                   /* $@16  */
  YYSYMBOL_kd_palette_defs = 165,          /* kd_palette_defs  */
  YYSYMBOL_kd_palette_def = 166,           /* kd_palette_def  */
  YYSYMBOL_167_17 = 167,                   /* $@17  */
  YYSYMBOL_kd_bitmap_defs = 168,           /* kd_bitmap_defs  */
  YYSYMBOL_kd_bitmap_def = 169,            /* kd_bitmap_def  */
  YYSYMBOL_170_18 = 170,                   /* $@18  */
  YYSYMBOL_171_19 = 171,                   /* $@19  */
  YYSYMBOL_172_20 = 172,                   /* $@20  */
  YYSYMBOL_kd_color = 173,                 /* kd_color  */
  YYSYMBOL_kd_wrap_mode = 174,             /* kd_wrap_mode  */
  YYSYMBOL_kd_curvetype = 175,             /* kd_curvetype  */
  YYSYMBOL_kd_curve_points = 176,          /* kd_curve_points  */
  YYSYMBOL_kd_palette_colors = 177,        /* kd_palette_colors  */
  YYSYMBOL_kd_bitmap_pixels = 178,         /* kd_bitmap_pixels  */
  YYSYMBOL_kd_png_bitmap_pixels = 179,     /* kd_png_bitmap_pixels  */
  YYSYMBOL_kd_byte_stream = 180,           /* kd_byte_stream  */
  YYSYMBOL_kd_opt_name = 181,              /* kd_opt_name  */
  YYSYMBOL_kd_style_name_or_index = 182,   /* kd_style_name_or_index  */
  YYSYMBOL_kd_region_name_or_index = 183,  /* kd_region_name_or_index  */
  YYSYMBOL_kd_curve_name_or_index = 184,   /* kd_curve_name_or_index  */
  YYSYMBOL_kd_motion_name_or_index = 185,  /* kd_motion_name_or_index  */
  YYSYMBOL_kd_palette_name_or_index = 186, /* kd_palette_name_or_index  */
  YYSYMBOL_kd_bitmap_name_or_index = 187,  /* kd_bitmap_name_or_index  */
  YYSYMBOL_kd_font_range_name_or_index = 188, /* kd_font_range_name_or_index  */
  YYSYMBOL_kd_font_mapping_name_or_index = 189, /* kd_font_mapping_name_or_index  */
  YYSYMBOL_kd_curve_def_name_or_index = 190, /* kd_curve_def_name_or_index  */
  YYSYMBOL_191_21 = 191,                   /* $@21  */
  YYSYMBOL_192_22 = 192,                   /* $@22  */
  YYSYMBOL_float = 193,                    /* float  */
  YYSYMBOL_bitmap_x_offset = 194,          /* bitmap_x_offset  */
  YYSYMBOL_bitmap_y_offset = 195,          /* bitmap_y_offset  */
  YYSYMBOL_timespec = 196,                 /* timespec  */
  YYSYMBOL_kd_events = 197,                /* kd_events  */
  YYSYMBOL_kd_event = 198,                 /* kd_event  */
  YYSYMBOL_199_23 = 199,                   /* $@23  */
  YYSYMBOL_200_24 = 200,                   /* $@24  */
  YYSYMBOL_kd_event_defs = 201,            /* kd_event_defs  */
  YYSYMBOL_kd_event_def = 202,             /* kd_event_def  */
  YYSYMBOL_203_25 = 203,                   /* $@25  */
  YYSYMBOL_204_26 = 204,                   /* $@26  */
  YYSYMBOL_205_27 = 205,                   /* $@27  */
  YYSYMBOL_206_28 = 206,                   /* $@28  */
  YYSYMBOL_207_29 = 207,                   /* $@29  */
  YYSYMBOL_208_30 = 208,                   /* $@30  */
  YYSYMBOL_209_31 = 209,                   /* $@31  */
  YYSYMBOL_210_32 = 210,                   /* $@32  */
  YYSYMBOL_211_33 = 211,                   /* $@33  */
  YYSYMBOL_212_34 = 212,                   /* $@34  */
  YYSYMBOL_kd_meta_byte_stream_def = 213,  /* kd_meta_byte_stream_def  */
  YYSYMBOL_214_35 = 214,                   /* $@35  */
  YYSYMBOL_kd_optional_secondary = 215,    /* kd_optional_secondary  */
  YYSYMBOL_strings = 216,                  /* strings  */
  YYSYMBOL_kd_motion_defs = 217,           /* kd_motion_defs  */
  YYSYMBOL_kd_motion_def = 218,            /* kd_motion_def  */
  YYSYMBOL_kd_optional_curve_duration = 219, /* kd_optional_curve_duration  */
  YYSYMBOL_kd_motion_mapping = 220,        /* kd_motion_mapping  */
  YYSYMBOL_kd_motion_semantics = 221,      /* kd_motion_semantics  */
  YYSYMBOL_kd_simple_timed_glyph_marker_defs = 222, /* kd_simple_timed_glyph_marker_defs  */
  YYSYMBOL_kd_simple_timed_glyph_marker_def = 223, /* kd_simple_timed_glyph_marker_def  */
  YYSYMBOL_kd_simple_timed_glyph_style_morph_defs = 224, /* kd_simple_timed_glyph_style_morph_defs  */
  YYSYMBOL_kd_simple_timed_glyph_style_morph_def = 225, /* kd_simple_timed_glyph_style_morph_def  */
  YYSYMBOL_unumber60 = 226,                /* unumber60  */
  YYSYMBOL_227_36 = 227,                   /* $@36  */
  YYSYMBOL_float60 = 228,                  /* float60  */
  YYSYMBOL_229_37 = 229,                   /* $@37  */
  YYSYMBOL_kd_opt_comma = 230,             /* kd_opt_comma  */
  YYSYMBOL_directionality = 231,           /* directionality  */
  YYSYMBOL_kd_font_range_defs = 232,       /* kd_font_range_defs  */
  YYSYMBOL_kd_font_range_def = 233,        /* kd_font_range_def  */
  YYSYMBOL_kd_font_mapping_defs = 234,     /* kd_font_mapping_defs  */
  YYSYMBOL_kd_font_mapping_def = 235,      /* kd_font_mapping_def  */
  YYSYMBOL_236_38 = 236                    /* $@38  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   641

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  137
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  309
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  588

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   379


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   129,     2,     2,
       2,     2,     2,   133,   136,     2,     2,   127,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   132,     2,
       2,   128,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   135,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   130,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     131,     2,   134,   125,     2,   126,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,  2286,  2286,  2286,  2286,  2289,  2290,  2293,  2294,  2297,
    2298,  2299,  2300,  2301,  2301,  2301,  2303,  2303,  2304,  2304,
    2305,  2305,  2306,  2306,  2307,  2307,  2308,  2308,  2309,  2309,
    2310,  2310,  2311,  2312,  2313,  2314,  2317,  2318,  2321,  2322,
    2323,  2324,  2325,  2326,  2327,  2328,  2329,  2330,  2331,  2332,
    2333,  2334,  2335,  2336,  2337,  2338,  2339,  2340,  2341,  2342,
    2343,  2344,  2345,  2346,  2348,  2349,  2349,  2352,  2353,  2354,
    2357,  2358,  2361,  2362,  2363,  2364,  2365,  2366,  2367,  2367,
    2370,  2371,  2374,  2375,  2375,  2378,  2378,  2381,  2382,  2385,
    2385,  2390,  2393,  2394,  2397,  2397,  2402,  2402,  2407,  2408,
    2409,  2410,  2411,  2411,  2414,  2415,  2416,  2417,  2420,  2421,
    2424,  2425,  2426,  2427,  2428,  2429,  2432,  2441,  2444,  2448,
    2451,  2464,  2467,  2475,  2478,  2486,  2489,  2490,  2493,  2494,
    2497,  2498,  2501,  2502,  2505,  2506,  2509,  2510,  2513,  2514,
    2517,  2518,  2521,  2522,  2525,  2526,  2526,  2527,  2527,  2531,
    2532,  2533,  2536,  2537,  2538,  2541,  2542,  2543,  2546,  2547,
    2548,  2551,  2552,  2555,  2555,  2558,  2558,  2563,  2564,  2567,
    2568,  2569,  2570,  2571,  2572,  2573,  2574,  2575,  2576,  2577,
    2578,  2579,  2579,  2581,  2581,  2582,  2584,  2584,  2586,  2586,
    2588,  2589,  2590,  2591,  2592,  2593,  2594,  2595,  2596,  2597,
    2597,  2598,  2599,  2599,  2601,  2601,  2603,  2604,  2605,  2605,
    2606,  2607,  2607,  2608,  2608,  2609,  2610,  2611,  2614,  2614,
    2617,  2618,  2621,  2622,  2625,  2626,  2629,  2630,  2631,  2632,
    2633,  2636,  2637,  2638,  2639,  2642,  2643,  2644,  2645,  2646,
    2647,  2653,  2654,  2655,  2656,  2657,  2658,  2659,  2660,  2661,
    2662,  2663,  2664,  2665,  2666,  2667,  2668,  2669,  2670,  2671,
    2672,  2673,  2674,  2675,  2676,  2677,  2678,  2679,  2680,  2681,
    2682,  2688,  2689,  2692,  2693,  2694,  2695,  2696,  2697,  2700,
    2701,  2704,  2705,  2707,  2708,  2709,  2710,  2711,  2714,  2714,
    2717,  2717,  2720,  2721,  2724,  2725,  2726,  2727,  2730,  2731,
    2734,  2735,  2736,  2737,  2738,  2741,  2742,  2745,  2745,  2746
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "KATE", "DEFS",
  "LANGUAGE", "COMMENT", "CATEGORY", "DEFINE", "MACRO", "STYLE", "REGION",
  "CURVE", "TEXT", "BACKGROUND", "COLOR", "POSITION", "SIZE", "DEFAULT",
  "METRIC", "HALIGN", "VALIGN", "HLEFT", "HCENTER", "HRIGHT", "VTOP",
  "VCENTER", "VBOTTOM", "POINTS", "EVENT", "STARTS", "ENDS", "AT", "START",
  "END", "TIME", "DURATION", "ARROW", "FROM", "TO", "MAPPING", "NONE",
  "FRAME", "MOTION", "BEZIER_CUBIC", "LINEAR", "CATMULL_ROM", "BSPLINE",
  "STATIC", "SEMANTICS", "EXTERNAL", "INTERNAL", "ALIGNMENT", "RG", "BA",
  "FOR", "ALPHA", "TIMEBASE", "MARKER", "POINTER",
  "SIMPLE_TIMED_GLYPH_MARKER", "SIMPLE_TIMED_GLYPH_STYLE_MORPH", "GLYPH",
  "PAUSE", "IN", "MORPH", "SECONDARY", "PATH", "SECTION", "PERIODIC",
  "DIRECTIONALITY", "L2R_T2B", "R2L_T2B", "T2B_R2L", "T2B_L2R", "BITMAP",
  "PALETTE", "COLORS", "FONT", "RANGE", "FIRST", "LAST", "CODE", "POINT",
  "USER", "SOURCE", "PNG", "DRAW", "VISIBLE", "ID", "BOLD", "ITALICS",
  "UNDERLINE", "STRIKE", "JUSTIFY", "BASE", "OFFSET", "GRANULE", "RATE",
  "SHIFT", "WIDTH", "HEIGHT", "CANVAS", "LEFT", "TOP", "RIGHT", "BOTTOM",
  "MARGIN", "MARGINS", "HORIZONTAL", "VERTICAL", "CLIP", "PRE", "MARKUP",
  "LOCAL", "WRAP", "WORD", "META", "NUMBER", "UNUMBER", "STRING", "FLOAT",
  "COLORSPEC", "IDENTIFIER", "MACRO_BODY", "'{'", "'}'", "'/'", "'='",
  "'%'", "'m'", "'x'", "':'", "'+'", "'z'", "'Y'", "','", "$accept",
  "kd_kate", "$@1", "$@2", "kd_opt_defs", "kd_defs", "kd_def", "$@3",
  "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12",
  "kd_style_defs", "kd_style_def", "$@13", "kd_opt_space_metric",
  "kd_region_defs", "kd_region_def", "$@14", "kd_curve_defs",
  "kd_curve_def", "$@15", "$@16", "kd_palette_defs", "kd_palette_def",
  "$@17", "kd_bitmap_defs", "kd_bitmap_def", "$@18", "$@19", "$@20",
  "kd_color", "kd_wrap_mode", "kd_curvetype", "kd_curve_points",
  "kd_palette_colors", "kd_bitmap_pixels", "kd_png_bitmap_pixels",
  "kd_byte_stream", "kd_opt_name", "kd_style_name_or_index",
  "kd_region_name_or_index", "kd_curve_name_or_index",
  "kd_motion_name_or_index", "kd_palette_name_or_index",
  "kd_bitmap_name_or_index", "kd_font_range_name_or_index",
  "kd_font_mapping_name_or_index", "kd_curve_def_name_or_index", "$@21",
  "$@22", "float", "bitmap_x_offset", "bitmap_y_offset", "timespec",
  "kd_events", "kd_event", "$@23", "$@24", "kd_event_defs", "kd_event_def",
  "$@25", "$@26", "$@27", "$@28", "$@29", "$@30", "$@31", "$@32", "$@33",
  "$@34", "kd_meta_byte_stream_def", "$@35", "kd_optional_secondary",
  "strings", "kd_motion_defs", "kd_motion_def",
  "kd_optional_curve_duration", "kd_motion_mapping", "kd_motion_semantics",
  "kd_simple_timed_glyph_marker_defs", "kd_simple_timed_glyph_marker_def",
  "kd_simple_timed_glyph_style_morph_defs",
  "kd_simple_timed_glyph_style_morph_def", "unumber60", "$@36", "float60",
  "$@37", "kd_opt_comma", "directionality", "kd_font_range_defs",
  "kd_font_range_def", "kd_font_mapping_defs", "kd_font_mapping_def",
  "$@38", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-375)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-289)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -375,    43,    56,  -375,   -37,   120,    26,  -375,  -375,  -375,
      30,    -1,    67,    69,    80,   278,   289,   319,   -24,   146,
    -375,  -375,    48,  -375,  -375,  -375,  -375,  -375,  -375,    96,
      96,    96,    96,    96,    96,    27,  -375,    71,  -375,  -375,
    -375,  -375,  -375,  -375,  -375,  -375,  -375,   121,   123,   139,
      87,  -375,   105,  -375,  -375,  -375,  -375,  -375,  -375,  -375,
      96,    96,   294,  -375,   145,  -375,   159,  -375,   266,  -375,
     166,   170,   189,   194,   200,   206,  -375,  -375,   154,   191,
    -375,   226,  -375,   147,   242,   260,   161,   -19,   362,   373,
     374,   379,   289,   289,   220,  -375,  -375,  -375,   319,   232,
     257,   378,   301,     8,    77,   307,  -375,   388,  -375,   436,
     318,   334,  -375,  -375,  -375,  -375,  -375,  -375,   352,   357,
    -375,   298,  -375,  -375,  -375,   385,  -375,  -375,   366,   387,
     401,   318,   289,   289,   289,   289,  -375,    18,  -375,  -375,
    -375,   397,   399,   400,  -375,  -375,  -375,  -375,   402,  -375,
    -375,  -375,   403,   262,  -375,   141,   164,   406,   318,   395,
     289,   323,   409,  -375,   344,    23,   186,    11,     9,    83,
    -375,  -375,  -375,  -375,    96,   405,  -375,  -375,  -375,  -375,
    -375,  -375,   289,   289,  -375,  -375,  -375,  -375,  -375,  -375,
    -375,  -375,   411,   318,   412,   318,  -375,   325,  -375,  -375,
    -375,   408,   410,  -375,   519,   521,   298,   298,  -375,  -375,
    -375,  -375,  -375,  -375,    45,   522,  -375,  -375,  -375,  -375,
    -375,   431,   432,   434,   435,   298,    17,   420,  -375,  -375,
     298,   298,   533,  -375,  -375,   424,  -375,  -375,  -375,  -375,
    -375,  -375,  -375,  -375,  -375,   517,  -375,  -375,  -375,   335,
     210,    20,  -375,  -375,  -375,   470,   427,   305,   428,   418,
    -375,  -375,   430,   474,  -375,  -375,   -47,    89,   425,  -375,
      31,  -375,  -375,    53,   181,   109,    65,   184,  -375,  -375,
    -375,  -375,  -375,   429,  -375,   -58,   -58,  -375,  -375,   298,
     298,   298,  -375,   -58,   298,   298,   298,   298,   327,  -375,
    -375,  -375,   437,   298,   298,   323,   438,   439,  -375,  -375,
    -375,   442,   497,   443,  -375,   520,  -375,  -375,   538,   441,
     210,   492,   447,   231,   543,  -375,   546,   548,   444,   510,
     455,   451,    41,   504,   465,   471,  -375,  -375,   257,  -375,
     452,   453,   454,   311,   456,   461,  -375,  -375,   354,  -375,
    -375,   119,   503,  -375,  -375,   232,   466,    93,  -375,  -375,
      -5,   531,   555,  -375,   554,  -375,   585,     4,   541,    49,
    -375,  -375,  -375,  -375,   472,  -375,   375,   479,   544,  -375,
    -375,   327,   327,   327,  -375,   327,   327,   327,   327,  -375,
    -375,   298,   356,  -375,  -375,  -375,   365,  -375,   477,   478,
     298,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,
     433,  -375,  -375,  -375,   536,   440,   553,   556,    28,   487,
    -375,  -375,  -375,   446,  -375,  -375,  -375,  -375,  -375,  -375,
     452,   453,   480,  -375,   383,   -62,   482,  -375,  -375,  -375,
     486,   232,   529,   530,  -375,  -375,  -375,   495,   142,   289,
     298,   210,   323,   496,   156,   289,   289,   289,  -375,   484,
    -375,   498,   499,  -375,  -375,  -375,  -375,  -375,  -375,  -375,
     327,  -375,  -375,  -375,  -375,   254,  -375,  -375,   384,   209,
    -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,   545,
    -375,  -375,  -375,  -375,  -375,   500,   502,  -375,  -375,  -375,
     396,   398,    79,  -375,   289,   289,  -375,   577,  -375,   583,
    -375,   289,   289,  -375,  -375,  -375,    92,  -375,   505,  -375,
     298,   501,   506,  -375,  -375,   285,   302,  -375,  -375,  -375,
    -375,   507,  -375,  -375,   394,   112,  -375,  -375,  -375,  -375,
    -375,  -375,  -375,   298,   613,  -375,  -375,   489,  -375,  -375,
     327,  -375,  -375,  -375,  -375,  -375,   508,   509,   -58,  -375,
    -375,  -375,   323,  -375,  -375,   298,   182,   187,   192,  -375,
    -375,   511,  -375,   327,  -375,  -375,  -375,   198,   203,   489,
    -375,   489,  -375,   489,  -375,  -375,  -375,  -375
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     0,     1,     0,     6,     0,     3,     8,   162,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     7,   165,     4,   161,     9,    12,    10,    13,   127,
     127,   127,   127,   127,   127,     0,   151,   150,   149,   290,
      32,   160,   294,   295,   296,   297,    11,     0,     0,     0,
       0,   168,     0,   126,    16,    18,    20,    22,    26,    24,
     127,   127,     0,   291,     0,    34,     0,   168,   166,    14,
       0,     0,     0,     0,     0,     0,    30,    28,   150,     0,
     159,     0,    35,   221,     0,     0,   183,     0,     0,     0,
       0,     0,     0,     0,   199,   202,   204,   220,     0,   211,
     208,     0,     0,     0,     0,     0,   223,     0,   167,     0,
     198,     0,    37,    71,    81,   225,    93,    88,     0,     0,
     289,     0,    33,   164,   170,     0,   131,   130,   180,     0,
       0,   190,     0,     0,     0,     0,   177,     0,   135,   134,
     201,     0,     0,     0,   171,   139,   138,   210,     0,   137,
     136,   207,     0,     0,   169,     0,     0,     0,   192,     0,
       0,   188,     0,    15,     0,     0,     0,     0,     0,     0,
     306,   299,   150,   158,   127,     0,    71,   194,   172,   173,
     174,   175,     0,     0,   225,   272,   280,    93,    88,   143,
     142,   206,     0,   191,     0,   193,   196,     0,   179,   129,
     128,   185,     0,   222,     0,     0,     0,     0,    40,    41,
      42,    43,    44,    45,     0,     0,    49,    50,    51,    52,
      53,     0,     0,     0,     0,     0,     0,     0,    17,    36,
       0,     0,     0,    72,    75,     0,    19,    70,    85,   110,
     114,   112,   113,   115,   111,     0,    21,    80,    82,   145,
       0,     0,   230,    23,   224,     0,     0,     0,     0,     0,
      27,    92,     0,     0,    25,    87,     0,     0,   213,    71,
       0,   176,   178,     0,     0,     0,     0,     0,   195,   197,
     218,   216,   217,     0,    37,     0,     0,    38,    39,     0,
       0,     0,    55,     0,     0,     0,     0,     0,    69,   108,
     109,    54,     0,     0,     0,     0,     0,     0,    83,   133,
     132,   144,   234,     0,   237,     0,   235,   236,     0,     0,
     226,     0,     0,     0,     0,   241,     0,     0,     0,     0,
       0,     0,   260,     0,     0,     0,   262,   228,     0,    98,
     153,   152,     0,     0,     0,     0,    91,    89,   307,    31,
     305,     0,     0,    29,   298,     0,     0,     0,   184,   200,
       0,     0,     0,   203,     0,   271,     0,     0,     0,     0,
     205,   279,   212,   209,     0,    37,     0,     0,   106,    46,
      47,    69,    69,    69,    48,    69,    69,    69,    69,    67,
      68,     0,     0,    73,    74,    76,     0,   117,     0,     0,
       0,   229,    81,   238,   239,   240,   227,   257,   242,   243,
       0,   247,   248,   244,   258,     0,     0,     0,     0,     0,
     265,   266,   270,     0,   269,   261,   263,   264,    99,   154,
     156,   155,     0,   100,     0,     0,     0,   141,   140,   309,
       0,     0,     0,     0,   215,    93,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   125,     0,
     189,     0,     0,    56,    57,    58,    59,    60,    61,    62,
      69,    65,    64,    78,    77,     0,   117,    81,   231,     0,
     251,   252,   259,   253,   254,   246,   245,   249,   267,   250,
     255,   256,   157,   102,   101,     0,     0,   119,   299,   304,
       0,     0,     0,   273,     0,     0,   276,     0,   274,     0,
     281,     0,     0,   283,   287,   286,     0,   187,   104,   107,
       0,     0,     0,    86,   116,     0,     0,   232,   233,   146,
     268,     0,    96,    94,     0,     0,   301,   300,   303,   302,
     214,   278,   277,     0,     0,   285,   284,   293,   219,   105,
      69,   125,   125,    84,   148,   125,     0,     0,     0,    90,
     308,   275,     0,   292,   124,     0,     0,     0,     0,   123,
     121,     0,   282,    69,    66,    79,   103,     0,     0,   293,
      63,   293,    97,   293,    95,   118,   122,   120
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,
    -375,  -375,  -375,  -375,  -375,  -375,  -375,  -255,  -375,  -375,
    -374,  -154,  -375,  -375,  -334,  -375,  -375,  -375,   448,  -375,
    -375,  -183,  -375,  -375,  -375,  -375,  -283,  -375,  -375,   151,
    -375,  -375,  -375,  -218,   -15,  -299,  -375,  -375,  -375,   290,
    -302,  -375,  -375,  -375,  -375,  -375,  -205,  -375,  -375,   -16,
    -375,  -375,  -375,  -375,   562,  -375,  -375,  -375,  -375,  -375,
    -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,   137,
     457,  -375,  -375,  -315,  -375,  -375,  -375,  -375,  -375,  -375,
    -375,    10,  -375,  -220,   532,   140,  -375,  -375,  -375,  -375
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     9,     7,    10,    21,    52,   111,    70,
      71,    72,    73,    75,    74,   119,   118,   164,   229,   521,
     391,   165,   237,   522,   166,   247,   398,   307,   169,   265,
     436,   168,   261,   557,   556,   531,   379,   301,   248,   475,
     534,   578,   577,   516,    54,   201,   128,   311,   140,   151,
     147,   439,   191,   312,   313,   399,    39,   343,   433,   107,
      11,    24,    50,    51,    68,   108,   175,   129,   283,   202,
     141,   142,   143,   152,   148,   356,   282,   374,   109,   110,
     167,   254,   401,   320,   337,   274,   365,   275,   371,    79,
     120,    41,    63,   564,    46,   267,   354,   266,   350,   440
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,   287,   288,   380,   276,   406,   395,   463,   464,   465,
     384,   466,   467,   468,   469,    55,    56,    57,    58,    59,
     298,   155,   270,   249,   495,   303,   304,   255,    22,   376,
     321,   322,   348,   323,   324,    12,    13,    14,    15,   230,
     231,   232,   233,     3,   487,    76,    77,   230,   231,   232,
     233,   250,   342,   444,   447,   325,   423,   182,   299,     4,
     251,   377,   289,   453,   378,   249,   130,    60,   479,   496,
     326,   327,    80,   183,    47,    48,   136,   137,   328,   349,
     252,   456,   329,   255,   381,   382,   383,    16,     5,   385,
     386,   387,   388,   250,   256,   330,   520,   255,   393,   394,
      17,   106,   251,   488,   331,   257,    61,   332,   333,   230,
     231,   232,   233,   457,   448,   357,   178,   179,   180,   181,
     459,   156,   252,   454,     6,    23,   258,    18,   259,   334,
     335,   173,    19,   300,   234,   260,   508,   253,   432,   499,
     235,   424,   234,   526,   198,   290,   291,   366,   235,   236,
     256,     8,    84,   509,   336,    85,    20,   358,    86,   268,
      87,   257,   157,    49,   256,   292,   271,   272,   262,   351,
     352,   367,   368,  -163,   504,   257,   565,    88,    89,   359,
      90,    91,   258,    92,   259,    93,   470,    25,   511,    26,
      94,   372,   351,   352,   441,   478,   258,   106,   259,   580,
      27,   442,   263,    62,   234,   540,   505,    95,    96,   264,
     235,   547,    67,    97,   238,   353,    53,    98,   548,   446,
     512,   314,    99,   100,   131,   101,   192,   239,    69,   369,
     240,   241,   242,   243,   244,   370,   102,   238,   560,   315,
      64,   158,    65,   360,   361,   507,   410,   411,   412,   194,
     239,   316,   317,   240,   241,   242,   243,   244,    66,   103,
     104,   106,   502,   572,   105,    36,    37,   106,    38,   262,
     524,    84,    81,   123,    85,   571,  -221,    86,    82,    87,
     126,   127,   362,   413,   106,   318,  -288,    28,    29,    30,
      31,   112,   193,   195,   319,   113,    88,    89,   414,    90,
      91,   547,    92,   263,    93,   245,   547,   363,   574,    94,
     373,   547,   246,   575,   114,   550,   364,   581,   576,   115,
     524,    32,   583,   121,   582,   116,    95,    96,   245,   584,
     238,   117,    97,   566,   567,   529,    98,   568,   561,   138,
     139,    99,   100,   239,   101,   122,   240,   241,   242,   243,
     244,   145,   146,    33,    34,   102,    35,   204,   205,   585,
     573,   586,   124,   587,   206,   207,   208,   209,   210,   211,
     212,   213,    36,   172,   125,    38,   149,   150,   103,   104,
     523,   189,   190,   105,    36,    37,   106,    38,   204,   205,
      42,    43,    44,    45,   132,   206,   207,   208,   209,   210,
     211,   212,   213,    36,   172,   133,    38,    36,    37,   134,
      38,   553,    36,    78,   135,    38,    36,   172,   153,    38,
     154,   245,   214,   340,   341,   160,    38,   159,   554,   430,
     431,   215,    38,   506,   216,   217,   218,   219,   220,   513,
     514,   515,   199,   200,   280,   281,   161,   221,   222,   223,
     224,   162,   225,   214,   309,   310,   389,   390,   163,   226,
     174,   227,   215,   408,   409,   216,   217,   218,   219,   220,
     228,   420,   421,   437,   438,   471,   472,   170,   221,   222,
     223,   224,   171,   225,   473,   474,   480,   481,   541,   542,
     226,  -181,   227,   483,   484,   545,   546,   204,   205,   490,
     491,   460,   493,   494,   206,   207,   208,   209,   210,   211,
     212,   213,   176,   527,   528,   536,   537,   538,   539,   558,
     559,   177,   184,   197,   185,   186,   196,   187,   188,   203,
     269,   278,   279,  -186,   285,   284,   286,   293,   294,   295,
     302,   296,   297,   305,   306,   308,   338,   339,   344,   345,
     346,   347,   400,   355,   375,   404,   403,   407,   415,   416,
     405,   417,   214,   418,   397,   392,   396,  -147,   402,   419,
     422,   215,   425,   426,   216,   217,   218,   219,   220,   427,
     435,  -151,  -150,   429,   434,   443,   449,   221,   222,   223,
     224,   445,   225,   450,   451,   452,   455,   458,   461,   226,
     462,   227,   476,   477,   482,   485,   489,   497,   486,   492,
     517,   498,   500,   501,   503,   510,   543,   518,   519,   532,
     530,   533,   544,   562,   549,   563,   551,   525,   428,    83,
     144,   552,   555,   569,   570,     0,   277,   579,   535,     0,
       0,   273
};

static const yytype_int16 yycheck[] =
{
      16,   206,   207,   286,   187,   320,   305,   381,   382,   383,
     293,   385,   386,   387,   388,    30,    31,    32,    33,    34,
     225,    13,   176,    12,    86,   230,   231,    18,    29,   284,
      10,    11,    79,    13,    14,     5,     6,     7,     8,    16,
      17,    18,    19,     0,    16,    60,    61,    16,    17,    18,
      19,    40,   257,   355,    59,    35,    15,    39,    41,     3,
      49,   119,    17,    59,   122,    12,    85,    40,   402,   131,
      50,    51,    62,    55,    98,    99,    92,    93,    58,   126,
      69,    32,    62,    18,   289,   290,   291,    57,   125,   294,
     295,   296,   297,    40,    85,    75,   470,    18,   303,   304,
      70,   120,    49,    75,    84,    96,    79,    87,    88,    16,
      17,    18,    19,    64,   119,   269,   132,   133,   134,   135,
     375,   113,    69,   119,     4,   126,   117,    97,   119,   109,
     110,   121,   102,   116,   111,   126,   451,   126,   343,   441,
     117,   100,   111,   477,   160,   100,   101,    38,   117,   126,
      85,   125,     5,   452,   134,     8,   126,   126,    11,   174,
      13,    96,    85,    17,    85,   120,   182,   183,    85,    80,
      81,    62,    63,   125,    32,    96,   550,    30,    31,   126,
      33,    34,   117,    36,   119,    38,   391,   120,    32,   120,
      43,   126,    80,    81,    75,   400,   117,   120,   119,   573,
     120,    82,   119,   132,   111,   126,    64,    60,    61,   126,
     117,   119,   125,    66,    28,   126,   120,    70,   126,   126,
      64,    11,    75,    76,    87,    78,    85,    41,   123,   120,
      44,    45,    46,    47,    48,   126,    89,    28,   126,    29,
     119,   104,   119,    62,    63,   450,    15,    16,    17,    85,
      41,    41,    42,    44,    45,    46,    47,    48,   119,   112,
     113,   120,   445,   562,   117,   118,   119,   120,   121,    85,
     475,     5,   127,   126,     8,   558,    10,    11,   119,    13,
     119,   120,   101,    52,   120,    75,   132,     9,    10,    11,
      12,   125,   155,   156,    84,   125,    30,    31,    67,    33,
      34,   119,    36,   119,    38,   119,   119,   126,   126,    43,
     126,   119,   126,   126,   125,   520,   135,   119,   126,   125,
     525,    43,   119,   132,   126,   125,    60,    61,   119,   126,
      28,   125,    66,   551,   552,   126,    70,   555,   543,   119,
     120,    75,    76,    41,    78,   119,    44,    45,    46,    47,
      48,   119,   120,    75,    76,    89,    78,    13,    14,   579,
     565,   581,   120,   583,    20,    21,    22,    23,    24,    25,
      26,    27,   118,   119,   114,   121,   119,   120,   112,   113,
     126,   119,   120,   117,   118,   119,   120,   121,    13,    14,
      71,    72,    73,    74,    32,    20,    21,    22,    23,    24,
      25,    26,    27,   118,   119,    32,   121,   118,   119,    35,
     121,   126,   118,   119,    35,   121,   118,   119,    40,   121,
     119,   119,    78,   118,   119,    37,   121,   120,   126,   118,
     119,    87,   121,   449,    90,    91,    92,    93,    94,   455,
     456,   457,   119,   120,   119,   120,    10,   103,   104,   105,
     106,   133,   108,    78,   119,   120,   129,   130,   124,   115,
      75,   117,    87,    16,    17,    90,    91,    92,    93,    94,
     126,    16,    17,   119,   120,   119,   120,   125,   103,   104,
     105,   106,   125,   108,   119,   120,    53,    54,   504,   505,
     115,   125,   117,    53,    54,   511,   512,    13,    14,    53,
      54,   126,   119,   120,    20,    21,    22,    23,    24,    25,
      26,    27,   125,   129,   130,   119,   120,   119,   120,   125,
     126,   120,   125,   128,   125,   125,   120,   125,   125,   120,
     125,   120,   120,   125,    15,   125,    15,    15,   107,   107,
     120,   107,   107,    10,   120,    28,    76,   120,   120,   131,
     120,    77,    55,   128,   125,    17,    36,    65,    15,    13,
     119,    13,    78,   119,   125,   128,   128,   125,   125,    59,
     119,    87,    68,   108,    90,    91,    92,    93,    94,   108,
     119,   129,   129,   129,   128,    82,    55,   103,   104,   105,
     106,   125,   108,    38,    40,    10,    55,   125,   119,   115,
      56,   117,   125,   125,    68,    52,   119,   125,    52,   129,
     126,   125,    83,    83,   119,   119,    39,   119,   119,   119,
      75,   119,    39,    10,   119,   136,   125,   476,   338,    67,
      98,   125,   125,   125,   125,    -1,   188,   126,   498,    -1,
      -1,   184
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   138,   139,     0,     3,   125,     4,   141,   125,   140,
     142,   197,     5,     6,     7,     8,    57,    70,    97,   102,
     126,   143,    29,   126,   198,   120,   120,   120,     9,    10,
      11,    12,    43,    75,    76,    78,   118,   119,   121,   193,
     196,   228,    71,    72,    73,    74,   231,    98,    99,    17,
     199,   200,   144,   120,   181,   181,   181,   181,   181,   181,
      40,    79,   132,   229,   119,   119,   119,   125,   201,   123,
     146,   147,   148,   149,   151,   150,   181,   181,   119,   226,
     228,   127,   119,   201,     5,     8,    11,    13,    30,    31,
      33,    34,    36,    38,    43,    60,    61,    66,    70,    75,
      76,    78,    89,   112,   113,   117,   120,   196,   202,   215,
     216,   145,   125,   125,   125,   125,   125,   125,   153,   152,
     227,   132,   119,   126,   120,   114,   119,   120,   183,   204,
      85,   216,    32,    32,    35,    35,   196,   196,   119,   120,
     185,   207,   208,   209,   231,   119,   120,   187,   211,   119,
     120,   186,   210,    40,   119,    13,   113,    85,   216,   120,
      37,    10,   133,   124,   154,   158,   161,   217,   168,   165,
     125,   125,   119,   228,    75,   203,   125,   120,   196,   196,
     196,   196,    39,    55,   125,   125,   125,   125,   125,   119,
     120,   189,    85,   216,    85,   216,   120,   128,   196,   119,
     120,   182,   206,   120,    13,    14,    20,    21,    22,    23,
      24,    25,    26,    27,    78,    87,    90,    91,    92,    93,
      94,   103,   104,   105,   106,   108,   115,   117,   126,   155,
      16,    17,    18,    19,   111,   117,   126,   159,    28,    41,
      44,    45,    46,    47,    48,   119,   126,   162,   175,    12,
      40,    49,    69,   126,   218,    18,    85,    96,   117,   119,
     126,   169,    85,   119,   126,   166,   234,   232,   181,   125,
     158,   196,   196,   217,   222,   224,   168,   165,   120,   120,
     119,   120,   213,   205,   125,    15,    15,   193,   193,    17,
     100,   101,   120,    15,   107,   107,   107,   107,   193,    41,
     116,   174,   120,   193,   193,    10,   120,   164,    28,   119,
     120,   184,   190,   191,    11,    29,    41,    42,    75,    84,
     220,    10,    11,    13,    14,    35,    50,    51,    58,    62,
      75,    84,    87,    88,   109,   110,   134,   221,    76,   120,
     118,   119,   193,   194,   120,   131,   120,    77,    79,   126,
     235,    80,    81,   126,   233,   128,   212,   158,   126,   126,
      62,    63,   101,   126,   135,   223,    38,    62,    63,   120,
     126,   225,   126,   126,   214,   125,   154,   119,   122,   173,
     173,   193,   193,   193,   173,   193,   193,   193,   193,   129,
     130,   157,   128,   193,   193,   182,   128,   125,   163,   192,
      55,   219,   125,    36,    17,   119,   220,    65,    16,    17,
      15,    16,    17,    52,    67,    15,    13,    13,   119,    59,
      16,    17,   119,    15,   100,    68,   108,   108,   186,   129,
     118,   119,   193,   195,   128,   119,   167,   119,   120,   188,
     236,    75,    82,    82,   187,   125,   126,    59,   119,    55,
      38,    40,    10,    59,   119,    55,    32,    64,   125,   154,
     126,   119,    56,   157,   157,   157,   157,   157,   157,   157,
     193,   119,   120,   119,   120,   176,   125,   125,   193,   161,
      53,    54,    68,    53,    54,    52,    52,    16,    75,   119,
      53,    54,   129,   119,   120,    86,   131,   125,   125,   187,
      83,    83,   168,   119,    32,    64,   196,   193,   220,   182,
     119,    32,    64,   196,   196,   196,   180,   126,   119,   119,
     157,   156,   160,   126,   193,   176,   161,   129,   130,   126,
      75,   172,   119,   119,   177,   232,   119,   120,   119,   120,
     126,   196,   196,    39,    39,   196,   196,   119,   126,   119,
     193,   125,   125,   126,   126,   125,   171,   170,   125,   126,
     126,   193,    10,   136,   230,   157,   180,   180,   180,   125,
     125,   173,   182,   193,   126,   126,   126,   179,   178,   126,
     157,   119,   126,   119,   126,   230,   230,   230
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   137,   139,   140,   138,   141,   141,   142,   142,   143,
     143,   143,   143,   144,   145,   143,   146,   143,   147,   143,
     148,   143,   149,   143,   150,   143,   151,   143,   152,   143,
     153,   143,   143,   143,   143,   143,   154,   154,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   156,   155,   157,   157,   157,
     158,   158,   159,   159,   159,   159,   159,   159,   160,   159,
     161,   161,   162,   163,   162,   164,   162,   165,   165,   167,
     166,   166,   168,   168,   170,   169,   171,   169,   169,   169,
     169,   169,   172,   169,   173,   173,   173,   173,   174,   174,
     175,   175,   175,   175,   175,   175,   176,   176,   177,   177,
     178,   178,   179,   179,   180,   180,   181,   181,   182,   182,
     183,   183,   184,   184,   185,   185,   186,   186,   187,   187,
     188,   188,   189,   189,   190,   191,   190,   192,   190,   193,
     193,   193,   194,   194,   194,   195,   195,   195,   196,   196,
     196,   197,   197,   199,   198,   200,   198,   201,   201,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   203,   202,   204,   202,   202,   205,   202,   206,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   207,
     202,   202,   208,   202,   209,   202,   202,   202,   210,   202,
     202,   211,   202,   212,   202,   202,   202,   202,   214,   213,
     215,   215,   216,   216,   217,   217,   218,   218,   218,   218,
     218,   219,   219,   219,   219,   220,   220,   220,   220,   220,
     220,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   222,   222,   223,   223,   223,   223,   223,   223,   224,
     224,   225,   225,   225,   225,   225,   225,   225,   227,   226,
     229,   228,   230,   230,   231,   231,   231,   231,   232,   232,
     233,   233,   233,   233,   233,   234,   234,   236,   235,   235
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     7,     4,     0,     2,     0,     2,
       2,     2,     2,     0,     0,     6,     0,     7,     0,     7,
       0,     7,     0,     7,     0,     7,     0,     7,     0,     8,
       0,     8,     2,     5,     3,     4,     2,     0,     2,     2,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     1,
       1,     1,     1,     1,     2,     2,     4,     4,     4,     4,
       4,     4,     4,     9,     4,     0,     8,     1,     1,     0,
       2,     0,     1,     3,     3,     1,     3,     4,     0,     8,
       2,     0,     1,     0,     6,     0,     5,     2,     0,     0,
       6,     2,     2,     0,     0,     9,     0,     9,     2,     3,
       3,     4,     0,     8,     3,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     5,     0,
       3,     0,     3,     0,     3,     0,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     0,     5,     1,
       1,     1,     1,     1,     2,     1,     1,     2,     5,     3,
       1,     2,     0,     0,     5,     0,     3,     2,     0,     2,
       2,     2,     3,     3,     3,     3,     4,     2,     4,     3,
       2,     0,     6,     0,     5,     3,     0,     7,     0,     6,
       2,     3,     2,     3,     3,     4,     3,     4,     1,     0,
       5,     2,     0,     5,     0,     5,     3,     2,     0,     5,
       2,     0,     5,     0,     8,     6,     4,     4,     0,     5,
       1,     0,     3,     1,     2,     0,     2,     3,     2,     3,
       1,     2,     3,     3,     0,     1,     1,     1,     2,     2,
       2,     1,     2,     2,     2,     3,     3,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       1,     2,     1,     2,     2,     2,     2,     3,     4,     2,
       2,     2,     0,     3,     3,     5,     3,     4,     4,     2,
       0,     3,     6,     3,     4,     4,     3,     3,     0,     2,
       0,     2,     1,     0,     1,     1,     1,     1,     2,     0,
       4,     4,     4,     4,     3,     2,     0,     0,     5,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 2286 "kate_parser.y"
         {nlines=1;}
#line 4248 "kate_parser.c"
    break;

  case 3: /* $@2: %empty  */
#line 2286 "kate_parser.y"
                                          { kd_write_headers(); }
#line 4254 "kate_parser.c"
    break;

  case 4: /* kd_kate: $@1 KATE '{' kd_opt_defs $@2 kd_events '}'  */
#line 2286 "kate_parser.y"
                                                                                { cleanup_memory(); }
#line 4260 "kate_parser.c"
    break;

  case 6: /* kd_opt_defs: %empty  */
#line 2290 "kate_parser.y"
             {}
#line 4266 "kate_parser.c"
    break;

  case 8: /* kd_defs: %empty  */
#line 2294 "kate_parser.y"
         {}
#line 4272 "kate_parser.c"
    break;

  case 9: /* kd_def: LANGUAGE STRING  */
#line 2297 "kate_parser.y"
                        { CHECK_KATE_API_ERROR(kate_info_set_language(&ki,(yyvsp[0].string))); }
#line 4278 "kate_parser.c"
    break;

  case 10: /* kd_def: CATEGORY STRING  */
#line 2298 "kate_parser.y"
                        { CHECK_KATE_API_ERROR(kate_info_set_category(&ki,(yyvsp[0].string))); }
#line 4284 "kate_parser.c"
    break;

  case 11: /* kd_def: DIRECTIONALITY directionality  */
#line 2299 "kate_parser.y"
                                      { CHECK_KATE_API_ERROR(kate_info_set_text_directionality(&ki,(yyvsp[0].number))); }
#line 4290 "kate_parser.c"
    break;

  case 12: /* kd_def: COMMENT STRING  */
#line 2300 "kate_parser.y"
                       { add_comment(&kc,(yyvsp[0].string)); }
#line 4296 "kate_parser.c"
    break;

  case 13: /* $@3: %empty  */
#line 2301 "kate_parser.y"
                     {set_macro_mode();}
#line 4302 "kate_parser.c"
    break;

  case 14: /* $@4: %empty  */
#line 2301 "kate_parser.y"
                                                    {record_macro_name((yyvsp[0].string));}
#line 4308 "kate_parser.c"
    break;

  case 15: /* kd_def: DEFINE MACRO $@3 IDENTIFIER $@4 MACRO_BODY  */
#line 2302 "kate_parser.y"
                     { add_temp_macro((yyvsp[0].string)); unset_macro_mode(); }
#line 4314 "kate_parser.c"
    break;

  case 16: /* $@5: %empty  */
#line 2303 "kate_parser.y"
                                 {init_style(&kstyle);}
#line 4320 "kate_parser.c"
    break;

  case 17: /* kd_def: DEFINE STYLE kd_opt_name $@5 '{' kd_style_defs '}'  */
#line 2303 "kate_parser.y"
                                                                              { add_style(&ki,(yyvsp[-4].string),&kstyle); }
#line 4326 "kate_parser.c"
    break;

  case 18: /* $@6: %empty  */
#line 2304 "kate_parser.y"
                                  {init_region(&kregion);}
#line 4332 "kate_parser.c"
    break;

  case 19: /* kd_def: DEFINE REGION kd_opt_name $@6 '{' kd_region_defs '}'  */
#line 2304 "kate_parser.y"
                                                                                  { add_region(&ki,(yyvsp[-4].string),&kregion); }
#line 4338 "kate_parser.c"
    break;

  case 20: /* $@7: %empty  */
#line 2305 "kate_parser.y"
                                 {init_curve();}
#line 4344 "kate_parser.c"
    break;

  case 21: /* kd_def: DEFINE CURVE kd_opt_name $@7 '{' kd_curve_defs '}'  */
#line 2305 "kate_parser.y"
                                                                       { add_curve(&ki,(yyvsp[-4].string),kcurve.curve); }
#line 4350 "kate_parser.c"
    break;

  case 22: /* $@8: %empty  */
#line 2306 "kate_parser.y"
                                  {init_motion();}
#line 4356 "kate_parser.c"
    break;

  case 23: /* kd_def: DEFINE MOTION kd_opt_name $@8 '{' kd_motion_defs '}'  */
#line 2306 "kate_parser.y"
                                                                          { add_motion(&ki,(yyvsp[-4].string),kmotion); }
#line 4362 "kate_parser.c"
    break;

  case 24: /* $@9: %empty  */
#line 2307 "kate_parser.y"
                                   {init_palette();}
#line 4368 "kate_parser.c"
    break;

  case 25: /* kd_def: DEFINE PALETTE kd_opt_name $@9 '{' kd_palette_defs '}'  */
#line 2307 "kate_parser.y"
                                                                             { add_palette(&ki,(yyvsp[-4].string),kpalette.palette); }
#line 4374 "kate_parser.c"
    break;

  case 26: /* $@10: %empty  */
#line 2308 "kate_parser.y"
                                  {init_bitmap();}
#line 4380 "kate_parser.c"
    break;

  case 27: /* kd_def: DEFINE BITMAP kd_opt_name $@10 '{' kd_bitmap_defs '}'  */
#line 2308 "kate_parser.y"
                                                                          { add_bitmap(&ki,(yyvsp[-4].string),kbitmap.bitmap); }
#line 4386 "kate_parser.c"
    break;

  case 28: /* $@11: %empty  */
#line 2309 "kate_parser.y"
                                      {init_font_range();}
#line 4392 "kate_parser.c"
    break;

  case 29: /* kd_def: DEFINE FONT RANGE kd_opt_name $@11 '{' kd_font_range_defs '}'  */
#line 2309 "kate_parser.y"
                                                                                      { add_font_range(&ki,(yyvsp[-4].string),krange); }
#line 4398 "kate_parser.c"
    break;

  case 30: /* $@12: %empty  */
#line 2310 "kate_parser.y"
                                        {init_font_mapping();}
#line 4404 "kate_parser.c"
    break;

  case 31: /* kd_def: DEFINE FONT MAPPING kd_opt_name $@12 '{' kd_font_mapping_defs '}'  */
#line 2310 "kate_parser.y"
                                                                                            { add_font_mapping(&ki,(yyvsp[-4].string),kmapping); }
#line 4410 "kate_parser.c"
    break;

  case 32: /* kd_def: TIMEBASE timespec  */
#line 2311 "kate_parser.y"
                          { timebase=(yyvsp[0].fp); }
#line 4416 "kate_parser.c"
    break;

  case 33: /* kd_def: GRANULE RATE UNUMBER '/' UNUMBER  */
#line 2312 "kate_parser.y"
                                         {set_granule_rate((yyvsp[-2].unumber),(yyvsp[0].unumber));}
#line 4422 "kate_parser.c"
    break;

  case 34: /* kd_def: GRANULE SHIFT UNUMBER  */
#line 2313 "kate_parser.y"
                              {set_granule_shift((yyvsp[0].unumber));}
#line 4428 "kate_parser.c"
    break;

  case 35: /* kd_def: CANVAS SIZE UNUMBER UNUMBER  */
#line 2314 "kate_parser.y"
                                    {set_canvas_size((yyvsp[-1].unumber),(yyvsp[0].unumber));}
#line 4434 "kate_parser.c"
    break;

  case 37: /* kd_style_defs: %empty  */
#line 2318 "kate_parser.y"
               {}
#line 4440 "kate_parser.c"
    break;

  case 38: /* kd_style_def: HALIGN float  */
#line 2321 "kate_parser.y"
                           { kstyle.halign=(yyvsp[0].fp); }
#line 4446 "kate_parser.c"
    break;

  case 39: /* kd_style_def: VALIGN float  */
#line 2322 "kate_parser.y"
                           { kstyle.valign=(yyvsp[0].fp); }
#line 4452 "kate_parser.c"
    break;

  case 40: /* kd_style_def: HLEFT  */
#line 2323 "kate_parser.y"
                    { kstyle.halign=(kate_float)-1.0; }
#line 4458 "kate_parser.c"
    break;

  case 41: /* kd_style_def: HCENTER  */
#line 2324 "kate_parser.y"
                      { kstyle.halign=(kate_float)0.0; }
#line 4464 "kate_parser.c"
    break;

  case 42: /* kd_style_def: HRIGHT  */
#line 2325 "kate_parser.y"
                     { kstyle.halign=(kate_float)1.0; }
#line 4470 "kate_parser.c"
    break;

  case 43: /* kd_style_def: VTOP  */
#line 2326 "kate_parser.y"
                   { kstyle.valign=(kate_float)-1.0; }
#line 4476 "kate_parser.c"
    break;

  case 44: /* kd_style_def: VCENTER  */
#line 2327 "kate_parser.y"
                      { kstyle.valign=(kate_float)0.0; }
#line 4482 "kate_parser.c"
    break;

  case 45: /* kd_style_def: VBOTTOM  */
#line 2328 "kate_parser.y"
                      { kstyle.valign=(kate_float)1.0; }
#line 4488 "kate_parser.c"
    break;

  case 46: /* kd_style_def: TEXT COLOR kd_color  */
#line 2329 "kate_parser.y"
                                  { set_color(&kstyle.text_color,(yyvsp[0].color)); }
#line 4494 "kate_parser.c"
    break;

  case 47: /* kd_style_def: BACKGROUND COLOR kd_color  */
#line 2330 "kate_parser.y"
                                        { set_color(&kstyle.background_color,(yyvsp[0].color)); }
#line 4500 "kate_parser.c"
    break;

  case 48: /* kd_style_def: DRAW COLOR kd_color  */
#line 2331 "kate_parser.y"
                                  { set_color(&kstyle.draw_color,(yyvsp[0].color)); }
#line 4506 "kate_parser.c"
    break;

  case 49: /* kd_style_def: BOLD  */
#line 2332 "kate_parser.y"
                   { kstyle.bold=1; }
#line 4512 "kate_parser.c"
    break;

  case 50: /* kd_style_def: ITALICS  */
#line 2333 "kate_parser.y"
                      { kstyle.italics=1; }
#line 4518 "kate_parser.c"
    break;

  case 51: /* kd_style_def: UNDERLINE  */
#line 2334 "kate_parser.y"
                        { kstyle.underline=1; }
#line 4524 "kate_parser.c"
    break;

  case 52: /* kd_style_def: STRIKE  */
#line 2335 "kate_parser.y"
                     { kstyle.strike=1; }
#line 4530 "kate_parser.c"
    break;

  case 53: /* kd_style_def: JUSTIFY  */
#line 2336 "kate_parser.y"
                      { kstyle.justify=1; }
#line 4536 "kate_parser.c"
    break;

  case 54: /* kd_style_def: WRAP kd_wrap_mode  */
#line 2337 "kate_parser.y"
                                { kstyle.wrap_mode=(yyvsp[0].number); }
#line 4542 "kate_parser.c"
    break;

  case 55: /* kd_style_def: FONT STRING  */
#line 2338 "kate_parser.y"
                          { set_font(&kstyle,(yyvsp[0].string)); }
#line 4548 "kate_parser.c"
    break;

  case 56: /* kd_style_def: FONT SIZE float kd_opt_space_metric  */
#line 2339 "kate_parser.y"
                                                  { set_font_size(&kstyle,(yyvsp[-1].fp),(yyvsp[0].number)); }
#line 4554 "kate_parser.c"
    break;

  case 57: /* kd_style_def: FONT WIDTH float kd_opt_space_metric  */
#line 2340 "kate_parser.y"
                                                   { set_font_width(&kstyle,(yyvsp[-1].fp),(yyvsp[0].number)); }
#line 4560 "kate_parser.c"
    break;

  case 58: /* kd_style_def: FONT HEIGHT float kd_opt_space_metric  */
#line 2341 "kate_parser.y"
                                                    { set_font_height(&kstyle,(yyvsp[-1].fp),(yyvsp[0].number)); }
#line 4566 "kate_parser.c"
    break;

  case 59: /* kd_style_def: LEFT MARGIN float kd_opt_space_metric  */
#line 2342 "kate_parser.y"
                                                    { set_margin(&kstyle,&kstyle.left_margin,(yyvsp[-1].fp),(yyvsp[0].number)); }
#line 4572 "kate_parser.c"
    break;

  case 60: /* kd_style_def: TOP MARGIN float kd_opt_space_metric  */
#line 2343 "kate_parser.y"
                                                   { set_margin(&kstyle,&kstyle.top_margin,(yyvsp[-1].fp),(yyvsp[0].number)); }
#line 4578 "kate_parser.c"
    break;

  case 61: /* kd_style_def: RIGHT MARGIN float kd_opt_space_metric  */
#line 2344 "kate_parser.y"
                                                     { set_margin(&kstyle,&kstyle.right_margin,(yyvsp[-1].fp),(yyvsp[0].number)); }
#line 4584 "kate_parser.c"
    break;

  case 62: /* kd_style_def: BOTTOM MARGIN float kd_opt_space_metric  */
#line 2345 "kate_parser.y"
                                                      { set_margin(&kstyle,&kstyle.bottom_margin,(yyvsp[-1].fp),(yyvsp[0].number)); }
#line 4590 "kate_parser.c"
    break;

  case 63: /* kd_style_def: MARGINS float kd_opt_space_metric float kd_opt_space_metric float kd_opt_space_metric float kd_opt_space_metric  */
#line 2347 "kate_parser.y"
                  { set_margins(&kstyle,(yyvsp[-7].fp),(yyvsp[-6].number),(yyvsp[-5].fp),(yyvsp[-4].number),(yyvsp[-3].fp),(yyvsp[-2].number),(yyvsp[-1].fp),(yyvsp[0].number)); }
#line 4596 "kate_parser.c"
    break;

  case 64: /* kd_style_def: META STRING '=' STRING  */
#line 2348 "kate_parser.y"
                                     { add_meta(&kstyle.meta,(yyvsp[-2].string),(yyvsp[0].string)); }
#line 4602 "kate_parser.c"
    break;

  case 65: /* $@13: %empty  */
#line 2349 "kate_parser.y"
                                      {init_byte_stream((yyvsp[0].unumber));}
#line 4608 "kate_parser.c"
    break;

  case 66: /* kd_style_def: META STRING '=' UNUMBER $@13 '{' kd_byte_stream '}'  */
#line 2349 "kate_parser.y"
                                                                                     { add_meta_byte_stream(&kstyle.meta,(yyvsp[-6].string)); }
#line 4614 "kate_parser.c"
    break;

  case 67: /* kd_opt_space_metric: '%'  */
#line 2352 "kate_parser.y"
                         { (yyval.number)=kate_percentage; }
#line 4620 "kate_parser.c"
    break;

  case 68: /* kd_opt_space_metric: 'm'  */
#line 2353 "kate_parser.y"
                         { (yyval.number)=kate_millionths; }
#line 4626 "kate_parser.c"
    break;

  case 69: /* kd_opt_space_metric: %empty  */
#line 2354 "kate_parser.y"
                     { (yyval.number)=kate_pixel; }
#line 4632 "kate_parser.c"
    break;

  case 71: /* kd_region_defs: %empty  */
#line 2358 "kate_parser.y"
                {}
#line 4638 "kate_parser.c"
    break;

  case 72: /* kd_region_def: METRIC  */
#line 2361 "kate_parser.y"
                      {kregion.metric=(yyvsp[0].number); }
#line 4644 "kate_parser.c"
    break;

  case 73: /* kd_region_def: POSITION float float  */
#line 2362 "kate_parser.y"
                                    { kregion.x=(yyvsp[-1].fp);kregion.y=(yyvsp[0].fp); }
#line 4650 "kate_parser.c"
    break;

  case 74: /* kd_region_def: SIZE float float  */
#line 2363 "kate_parser.y"
                                { kregion.w=(yyvsp[-1].fp);kregion.h=(yyvsp[0].fp); }
#line 4656 "kate_parser.c"
    break;

  case 75: /* kd_region_def: CLIP  */
#line 2364 "kate_parser.y"
                    { kregion.clip=1; }
#line 4662 "kate_parser.c"
    break;

  case 76: /* kd_region_def: DEFAULT STYLE kd_style_name_or_index  */
#line 2365 "kate_parser.y"
                                                    { kregion.style=(yyvsp[0].number); }
#line 4668 "kate_parser.c"
    break;

  case 77: /* kd_region_def: META STRING '=' STRING  */
#line 2366 "kate_parser.y"
                                      { add_meta(&kregion.meta,(yyvsp[-2].string),(yyvsp[0].string)); }
#line 4674 "kate_parser.c"
    break;

  case 78: /* $@14: %empty  */
#line 2367 "kate_parser.y"
                                       {init_byte_stream((yyvsp[0].unumber));}
#line 4680 "kate_parser.c"
    break;

  case 79: /* kd_region_def: META STRING '=' UNUMBER $@14 '{' kd_byte_stream '}'  */
#line 2367 "kate_parser.y"
                                                                                      { add_meta_byte_stream(&kregion.meta,(yyvsp[-6].string)); }
#line 4686 "kate_parser.c"
    break;

  case 81: /* kd_curve_defs: %empty  */
#line 2371 "kate_parser.y"
                {}
#line 4692 "kate_parser.c"
    break;

  case 82: /* kd_curve_def: kd_curvetype  */
#line 2374 "kate_parser.y"
                           { kcurve.curve->type=(yyvsp[0].number); n_curve_pts=0; }
#line 4698 "kate_parser.c"
    break;

  case 83: /* $@15: %empty  */
#line 2375 "kate_parser.y"
                             { init_curve_points((yyvsp[-1].unumber)); }
#line 4704 "kate_parser.c"
    break;

  case 84: /* kd_curve_def: UNUMBER POINTS $@15 '{' kd_curve_points '}'  */
#line 2375 "kate_parser.y"
                                                                                {
                if ((size_t)n_curve_pts!=kcurve.curve->npts*2) katedesc_error("Wrong number of points in the curve");
              }
#line 4712 "kate_parser.c"
    break;

  case 85: /* $@16: %empty  */
#line 2378 "kate_parser.y"
                     { init_open_ended_curve_points(); }
#line 4718 "kate_parser.c"
    break;

  case 88: /* kd_palette_defs: %empty  */
#line 2382 "kate_parser.y"
                 {}
#line 4724 "kate_parser.c"
    break;

  case 89: /* $@17: %empty  */
#line 2385 "kate_parser.y"
                               { init_palette_colors((yyvsp[-1].unumber)); }
#line 4730 "kate_parser.c"
    break;

  case 90: /* kd_palette_def: UNUMBER COLORS $@17 '{' kd_palette_colors '}'  */
#line 2385 "kate_parser.y"
                                                                                      {
                  if ((size_t)n_palette_colors!=kpalette.palette->ncolors) {
                    katedesc_error("Wrong number of colors in the palette");
                  }
                }
#line 4740 "kate_parser.c"
    break;

  case 91: /* kd_palette_def: SOURCE STRING  */
#line 2390 "kate_parser.y"
                              { load_palette((yyvsp[0].string)); }
#line 4746 "kate_parser.c"
    break;

  case 93: /* kd_bitmap_defs: %empty  */
#line 2394 "kate_parser.y"
                {}
#line 4752 "kate_parser.c"
    break;

  case 94: /* $@18: %empty  */
#line 2397 "kate_parser.y"
                                               { init_bitmap_pixels((yyvsp[-4].unumber),(yyvsp[-2].unumber),(yyvsp[0].unumber)); }
#line 4758 "kate_parser.c"
    break;

  case 95: /* kd_bitmap_def: UNUMBER 'x' UNUMBER 'x' UNUMBER $@18 '{' kd_bitmap_pixels '}'  */
#line 2397 "kate_parser.y"
                                                                                                          {
                 if ((size_t)n_bitmap_pixels!=kbitmap.bitmap->width*kbitmap.bitmap->height) {
                   katedesc_error("Wrong number of pixels in the bitmap");
                 }
               }
#line 4768 "kate_parser.c"
    break;

  case 96: /* $@19: %empty  */
#line 2402 "kate_parser.y"
                                               { init_png_bitmap_pixels((yyvsp[-4].unumber),(yyvsp[-2].unumber),(yyvsp[0].unumber)); }
#line 4774 "kate_parser.c"
    break;

  case 97: /* kd_bitmap_def: UNUMBER 'x' UNUMBER PNG UNUMBER $@19 '{' kd_png_bitmap_pixels '}'  */
#line 2402 "kate_parser.y"
                                                                                                                  {
                 if ((size_t)n_bitmap_pixels!=kbitmap.bitmap->size) {
                   katedesc_error("Wrong number of bytes in the PNG bitmap");
                 }
               }
#line 4784 "kate_parser.c"
    break;

  case 98: /* kd_bitmap_def: SOURCE STRING  */
#line 2407 "kate_parser.y"
                             { load_bitmap((yyvsp[0].string),0); }
#line 4790 "kate_parser.c"
    break;

  case 99: /* kd_bitmap_def: DEFAULT PALETTE kd_palette_name_or_index  */
#line 2408 "kate_parser.y"
                                                        { kbitmap.bitmap->palette=(yyvsp[0].number); }
#line 4796 "kate_parser.c"
    break;

  case 100: /* kd_bitmap_def: OFFSET bitmap_x_offset bitmap_y_offset  */
#line 2409 "kate_parser.y"
                                                      { kbitmap.bitmap->x_offset=(yyvsp[-1].number); kbitmap.bitmap->y_offset=(yyvsp[0].number); }
#line 4802 "kate_parser.c"
    break;

  case 101: /* kd_bitmap_def: META STRING '=' STRING  */
#line 2410 "kate_parser.y"
                                      { add_meta(&kbitmap.bitmap->meta,(yyvsp[-2].string),(yyvsp[0].string)); }
#line 4808 "kate_parser.c"
    break;

  case 102: /* $@20: %empty  */
#line 2411 "kate_parser.y"
                                       {init_byte_stream((yyvsp[0].unumber));}
#line 4814 "kate_parser.c"
    break;

  case 103: /* kd_bitmap_def: META STRING '=' UNUMBER $@20 '{' kd_byte_stream '}'  */
#line 2411 "kate_parser.y"
                                                                                      { add_meta_byte_stream(&kbitmap.bitmap->meta,(yyvsp[-6].string)); }
#line 4820 "kate_parser.c"
    break;

  case 104: /* kd_color: UNUMBER UNUMBER UNUMBER  */
#line 2414 "kate_parser.y"
                                  { (yyval.color)=make_color((yyvsp[-2].unumber),(yyvsp[-1].unumber),(yyvsp[0].unumber),255); }
#line 4826 "kate_parser.c"
    break;

  case 105: /* kd_color: UNUMBER UNUMBER UNUMBER UNUMBER  */
#line 2415 "kate_parser.y"
                                          { (yyval.color)=make_color((yyvsp[-3].unumber),(yyvsp[-2].unumber),(yyvsp[-1].unumber),(yyvsp[0].unumber)); }
#line 4832 "kate_parser.c"
    break;

  case 106: /* kd_color: COLORSPEC  */
#line 2416 "kate_parser.y"
                    { (yyval.color)=make_color_alpha((yyvsp[0].color),255); }
#line 4838 "kate_parser.c"
    break;

  case 107: /* kd_color: COLORSPEC ALPHA UNUMBER  */
#line 2417 "kate_parser.y"
                                  { (yyval.color)=make_color_alpha((yyvsp[-2].color),(yyvsp[0].unumber)); }
#line 4844 "kate_parser.c"
    break;

  case 108: /* kd_wrap_mode: NONE  */
#line 2420 "kate_parser.y"
                   { (yyval.number)=kate_wrap_none; }
#line 4850 "kate_parser.c"
    break;

  case 109: /* kd_wrap_mode: WORD  */
#line 2421 "kate_parser.y"
                   { (yyval.number)=kate_wrap_word; }
#line 4856 "kate_parser.c"
    break;

  case 110: /* kd_curvetype: NONE  */
#line 2424 "kate_parser.y"
                   { (yyval.number)=kate_curve_none; }
#line 4862 "kate_parser.c"
    break;

  case 111: /* kd_curvetype: STATIC  */
#line 2425 "kate_parser.y"
                     { (yyval.number)=kate_curve_static; }
#line 4868 "kate_parser.c"
    break;

  case 112: /* kd_curvetype: LINEAR  */
#line 2426 "kate_parser.y"
                     { (yyval.number)=kate_curve_linear; }
#line 4874 "kate_parser.c"
    break;

  case 113: /* kd_curvetype: CATMULL_ROM  */
#line 2427 "kate_parser.y"
                          { (yyval.number)=kate_curve_catmull_rom_spline; }
#line 4880 "kate_parser.c"
    break;

  case 114: /* kd_curvetype: BEZIER_CUBIC  */
#line 2428 "kate_parser.y"
                           { (yyval.number)=kate_curve_bezier_cubic_spline; }
#line 4886 "kate_parser.c"
    break;

  case 115: /* kd_curvetype: BSPLINE  */
#line 2429 "kate_parser.y"
                      { (yyval.number)=kate_curve_bspline; }
#line 4892 "kate_parser.c"
    break;

  case 116: /* kd_curve_points: kd_curve_points float  */
#line 2432 "kate_parser.y"
                                       {
                   if (open_ended_curve) {
                     add_open_ended_curve_point((yyvsp[0].fp));
                   }
                   else {
                     if ((size_t)n_curve_pts>=kcurve.curve->npts*2) katedesc_error("Too many points in curve");
                     else { kcurve.curve->pts[n_curve_pts++]=(yyvsp[0].fp); }
                   }
                 }
#line 4906 "kate_parser.c"
    break;

  case 117: /* kd_curve_points: %empty  */
#line 2441 "kate_parser.y"
                 {}
#line 4912 "kate_parser.c"
    break;

  case 118: /* kd_palette_colors: kd_palette_colors '{' kd_color '}' kd_opt_comma  */
#line 2444 "kate_parser.y"
                                                                   {
                     if ((size_t)n_palette_colors>=kpalette.palette->ncolors) katedesc_error("Too many colors in palette");
                     else { set_color(&kpalette.palette->colors[n_palette_colors++],(yyvsp[-2].color)); }
                   }
#line 4921 "kate_parser.c"
    break;

  case 119: /* kd_palette_colors: %empty  */
#line 2448 "kate_parser.y"
                   {}
#line 4927 "kate_parser.c"
    break;

  case 120: /* kd_bitmap_pixels: kd_bitmap_pixels UNUMBER kd_opt_comma  */
#line 2451 "kate_parser.y"
                                                        {
                    if ((size_t)n_bitmap_pixels>=kbitmap.bitmap->width*kbitmap.bitmap->height) {
                      katedesc_error("Too many pixels in bitmap");
                    }
                    else {
                      if ((yyvsp[-1].unumber)>(unsigned int)(1<<kbitmap.bitmap->bpp)-1) {
                        katedesc_error("pixels out of range for given bpp");
                      }
                      else {
                        kbitmap.bitmap->pixels[n_bitmap_pixels++]=(yyvsp[-1].unumber);
                      }
                    }
                  }
#line 4945 "kate_parser.c"
    break;

  case 121: /* kd_bitmap_pixels: %empty  */
#line 2464 "kate_parser.y"
                  {}
#line 4951 "kate_parser.c"
    break;

  case 122: /* kd_png_bitmap_pixels: kd_png_bitmap_pixels UNUMBER kd_opt_comma  */
#line 2467 "kate_parser.y"
                                                                {
                        if ((size_t)n_bitmap_pixels>=kbitmap.bitmap->size) {
                          katedesc_error("Too many pixels in bitmap");
                        }
                        else {
                          kbitmap.bitmap->pixels[n_bitmap_pixels++]=(yyvsp[-1].unumber);
                        }
                      }
#line 4964 "kate_parser.c"
    break;

  case 123: /* kd_png_bitmap_pixels: %empty  */
#line 2475 "kate_parser.y"
                      {}
#line 4970 "kate_parser.c"
    break;

  case 124: /* kd_byte_stream: kd_byte_stream UNUMBER kd_opt_comma  */
#line 2478 "kate_parser.y"
                                                    {
                        if (n_bytes_in_stream>=byte_stream_size) {
                          katedesc_error("Too many bytes in byte stream");
                        }
                        else {
                          byte_stream[n_bytes_in_stream++]=(yyvsp[-1].unumber);
                        }
                      }
#line 4983 "kate_parser.c"
    break;

  case 125: /* kd_byte_stream: %empty  */
#line 2486 "kate_parser.y"
                {}
#line 4989 "kate_parser.c"
    break;

  case 126: /* kd_opt_name: STRING  */
#line 2489 "kate_parser.y"
                    { (yyval.string)=(yyvsp[0].string); }
#line 4995 "kate_parser.c"
    break;

  case 127: /* kd_opt_name: %empty  */
#line 2490 "kate_parser.y"
             { (yyval.string)=NULL; }
#line 5001 "kate_parser.c"
    break;

  case 128: /* kd_style_name_or_index: STRING  */
#line 2493 "kate_parser.y"
                               { (yyval.number)=find_style(&ki,(yyvsp[0].string)); }
#line 5007 "kate_parser.c"
    break;

  case 129: /* kd_style_name_or_index: UNUMBER  */
#line 2494 "kate_parser.y"
                                { if ((yyvsp[0].unumber)>=ki.nstyles) yyerrorf("Invalid style index (%u/%d)",(yyvsp[0].unumber),ki.nstyles); (yyval.number)=(yyvsp[0].unumber); }
#line 5013 "kate_parser.c"
    break;

  case 130: /* kd_region_name_or_index: STRING  */
#line 2497 "kate_parser.y"
                                { (yyval.number)=find_region(&ki,(yyvsp[0].string)); }
#line 5019 "kate_parser.c"
    break;

  case 131: /* kd_region_name_or_index: UNUMBER  */
#line 2498 "kate_parser.y"
                                { if ((yyvsp[0].unumber)>=ki.nregions) yyerrorf("Invalid region index (%u/%u)",(yyvsp[0].unumber),ki.nregions); (yyval.number)=(yyvsp[0].unumber); }
#line 5025 "kate_parser.c"
    break;

  case 132: /* kd_curve_name_or_index: STRING  */
#line 2501 "kate_parser.y"
                               { (yyval.number)=find_curve(&ki,(yyvsp[0].string)); }
#line 5031 "kate_parser.c"
    break;

  case 133: /* kd_curve_name_or_index: UNUMBER  */
#line 2502 "kate_parser.y"
                                { if ((yyvsp[0].unumber)>=ki.ncurves) yyerrorf("Invalid curve index (%u/%u)",(yyvsp[0].unumber),ki.ncurves); (yyval.number)=(yyvsp[0].unumber); }
#line 5037 "kate_parser.c"
    break;

  case 134: /* kd_motion_name_or_index: STRING  */
#line 2505 "kate_parser.y"
                                { (yyval.number)=find_motion(&ki,(yyvsp[0].string)); }
#line 5043 "kate_parser.c"
    break;

  case 135: /* kd_motion_name_or_index: UNUMBER  */
#line 2506 "kate_parser.y"
                                 { if ((yyvsp[0].unumber)>=ki.nmotions) yyerrorf("Invalid motion index (%u/%u)",(yyvsp[0].unumber),ki.nmotions); (yyval.number)=(yyvsp[0].unumber); }
#line 5049 "kate_parser.c"
    break;

  case 136: /* kd_palette_name_or_index: STRING  */
#line 2509 "kate_parser.y"
                                 { (yyval.number)=find_palette(&ki,(yyvsp[0].string)); }
#line 5055 "kate_parser.c"
    break;

  case 137: /* kd_palette_name_or_index: UNUMBER  */
#line 2510 "kate_parser.y"
                                  { if ((yyvsp[0].unumber)>=ki.npalettes) yyerrorf("Invalid palette index (%u/%u)",(yyvsp[0].unumber),ki.npalettes); (yyval.number)=(yyvsp[0].unumber); }
#line 5061 "kate_parser.c"
    break;

  case 138: /* kd_bitmap_name_or_index: STRING  */
#line 2513 "kate_parser.y"
                                { (yyval.number)=find_bitmap(&ki,(yyvsp[0].string)); }
#line 5067 "kate_parser.c"
    break;

  case 139: /* kd_bitmap_name_or_index: UNUMBER  */
#line 2514 "kate_parser.y"
                                 { if ((yyvsp[0].unumber)>=ki.nbitmaps) yyerrorf("Invalid bitmap index (%u/%u)",(yyvsp[0].unumber),ki.nbitmaps); (yyval.number)=(yyvsp[0].unumber); }
#line 5073 "kate_parser.c"
    break;

  case 140: /* kd_font_range_name_or_index: STRING  */
#line 2517 "kate_parser.y"
                                    { (yyval.number)=find_font_range(&ki,(yyvsp[0].string)); }
#line 5079 "kate_parser.c"
    break;

  case 141: /* kd_font_range_name_or_index: UNUMBER  */
#line 2518 "kate_parser.y"
                                     { if ((yyvsp[0].unumber)>=ki.nfont_ranges) yyerrorf("Invalid font range index (%u/%u)",(yyvsp[0].unumber),ki.nfont_ranges); (yyval.number)=(yyvsp[0].unumber); }
#line 5085 "kate_parser.c"
    break;

  case 142: /* kd_font_mapping_name_or_index: STRING  */
#line 2521 "kate_parser.y"
                                      { (yyval.number)=find_font_mapping(&ki,(yyvsp[0].string)); }
#line 5091 "kate_parser.c"
    break;

  case 143: /* kd_font_mapping_name_or_index: UNUMBER  */
#line 2522 "kate_parser.y"
                                       { if ((yyvsp[0].unumber)>=ki.nfont_mappings) yyerrorf("Invalid font mapping index (%u/%u)",(yyvsp[0].unumber),ki.nfont_mappings); (yyval.number)=(yyvsp[0].unumber); }
#line 5097 "kate_parser.c"
    break;

  case 144: /* kd_curve_def_name_or_index: kd_curve_name_or_index  */
#line 2525 "kate_parser.y"
                                                   { reference_curve_from((yyvsp[0].number)); }
#line 5103 "kate_parser.c"
    break;

  case 145: /* $@21: %empty  */
#line 2526 "kate_parser.y"
                            { init_curve(); }
#line 5109 "kate_parser.c"
    break;

  case 146: /* kd_curve_def_name_or_index: $@21 '{' kd_curve_defs '}'  */
#line 2526 "kate_parser.y"
                                                                    {}
#line 5115 "kate_parser.c"
    break;

  case 147: /* $@22: %empty  */
#line 2527 "kate_parser.y"
                                                   { init_curve_from((yyvsp[0].number)); }
#line 5121 "kate_parser.c"
    break;

  case 148: /* kd_curve_def_name_or_index: kd_curve_name_or_index $@22 '{' kd_curve_defs '}'  */
#line 2527 "kate_parser.y"
                                                                                                  {}
#line 5127 "kate_parser.c"
    break;

  case 149: /* float: FLOAT  */
#line 2531 "kate_parser.y"
             { (yyval.fp)=(yyvsp[0].fp); }
#line 5133 "kate_parser.c"
    break;

  case 150: /* float: UNUMBER  */
#line 2532 "kate_parser.y"
               { (yyval.fp)=(kate_float)(yyvsp[0].unumber); }
#line 5139 "kate_parser.c"
    break;

  case 151: /* float: NUMBER  */
#line 2533 "kate_parser.y"
              { (yyval.fp)=(kate_float)(yyvsp[0].number); }
#line 5145 "kate_parser.c"
    break;

  case 152: /* bitmap_x_offset: UNUMBER  */
#line 2536 "kate_parser.y"
                         { (yyval.number)=(yyvsp[0].unumber); }
#line 5151 "kate_parser.c"
    break;

  case 153: /* bitmap_x_offset: NUMBER  */
#line 2537 "kate_parser.y"
                        { (yyval.number)=(yyvsp[0].number); }
#line 5157 "kate_parser.c"
    break;

  case 154: /* bitmap_x_offset: float '%'  */
#line 2538 "kate_parser.y"
                           { (yyval.number)=compute_bitmap_x_offset((yyvsp[-1].fp)); }
#line 5163 "kate_parser.c"
    break;

  case 155: /* bitmap_y_offset: UNUMBER  */
#line 2541 "kate_parser.y"
                         { (yyval.number)=(yyvsp[0].unumber); }
#line 5169 "kate_parser.c"
    break;

  case 156: /* bitmap_y_offset: NUMBER  */
#line 2542 "kate_parser.y"
                        { (yyval.number)=(yyvsp[0].number); }
#line 5175 "kate_parser.c"
    break;

  case 157: /* bitmap_y_offset: float '%'  */
#line 2543 "kate_parser.y"
                           { (yyval.number)=compute_bitmap_y_offset((yyvsp[-1].fp)); }
#line 5181 "kate_parser.c"
    break;

  case 158: /* timespec: UNUMBER ':' unumber60 ':' float60  */
#line 2546 "kate_parser.y"
                                            { (yyval.fp)=(yyvsp[-4].unumber)*3600+(yyvsp[-2].unumber)*60+(yyvsp[0].fp); }
#line 5187 "kate_parser.c"
    break;

  case 159: /* timespec: UNUMBER ':' float60  */
#line 2547 "kate_parser.y"
                              { (yyval.fp)=(yyvsp[-2].unumber)*60+(yyvsp[0].fp); }
#line 5193 "kate_parser.c"
    break;

  case 160: /* timespec: float60  */
#line 2548 "kate_parser.y"
                  { (yyval.fp)=(yyvsp[0].fp); }
#line 5199 "kate_parser.c"
    break;

  case 162: /* kd_events: %empty  */
#line 2552 "kate_parser.y"
           {}
#line 5205 "kate_parser.c"
    break;

  case 163: /* $@23: %empty  */
#line 2555 "kate_parser.y"
                { init_event(&kevent); }
#line 5211 "kate_parser.c"
    break;

  case 164: /* kd_event: EVENT $@23 '{' kd_event_defs '}'  */
#line 2555 "kate_parser.y"
                                                               {
            check_event(&kevent); kd_encode_text(&k,&kevent); clear_event(&kevent);
          }
#line 5219 "kate_parser.c"
    break;

  case 165: /* $@24: %empty  */
#line 2558 "kate_parser.y"
                { init_event(&kevent); }
#line 5225 "kate_parser.c"
    break;

  case 166: /* kd_event: EVENT $@24 kd_event_defs  */
#line 2558 "kate_parser.y"
                                                       {
            check_event(&kevent); kd_encode_text(&k,&kevent); clear_event(&kevent);
          }
#line 5233 "kate_parser.c"
    break;

  case 168: /* kd_event_defs: %empty  */
#line 2564 "kate_parser.y"
               {}
#line 5239 "kate_parser.c"
    break;

  case 169: /* kd_event_def: ID UNUMBER  */
#line 2567 "kate_parser.y"
                         { kd_encode_set_id(&k,(yyvsp[0].unumber)); }
#line 5245 "kate_parser.c"
    break;

  case 170: /* kd_event_def: LANGUAGE STRING  */
#line 2568 "kate_parser.y"
                              { kd_encode_set_language(&k,(yyvsp[0].string)); }
#line 5251 "kate_parser.c"
    break;

  case 171: /* kd_event_def: DIRECTIONALITY directionality  */
#line 2569 "kate_parser.y"
                                            { CHECK_KATE_API_ERROR(kate_encode_set_text_directionality(&k,(yyvsp[0].number))); }
#line 5257 "kate_parser.c"
    break;

  case 172: /* kd_event_def: STARTS AT timespec  */
#line 2570 "kate_parser.y"
                                 { set_event_t0(&kevent,(yyvsp[0].fp)); }
#line 5263 "kate_parser.c"
    break;

  case 173: /* kd_event_def: ENDS AT timespec  */
#line 2571 "kate_parser.y"
                               { set_event_t1(&kevent,(yyvsp[0].fp)); }
#line 5269 "kate_parser.c"
    break;

  case 174: /* kd_event_def: START TIME timespec  */
#line 2572 "kate_parser.y"
                                  { set_event_t0(&kevent,(yyvsp[0].fp)); }
#line 5275 "kate_parser.c"
    break;

  case 175: /* kd_event_def: END TIME timespec  */
#line 2573 "kate_parser.y"
                                { set_event_t1(&kevent,(yyvsp[0].fp)); }
#line 5281 "kate_parser.c"
    break;

  case 176: /* kd_event_def: FROM timespec TO timespec  */
#line 2574 "kate_parser.y"
                                        { set_event_t0_t1(&kevent,(yyvsp[-2].fp),(yyvsp[0].fp)); }
#line 5287 "kate_parser.c"
    break;

  case 177: /* kd_event_def: DURATION timespec  */
#line 2575 "kate_parser.y"
                                { set_event_duration(&kevent,(yyvsp[0].fp)); }
#line 5293 "kate_parser.c"
    break;

  case 178: /* kd_event_def: FROM timespec FOR timespec  */
#line 2576 "kate_parser.y"
                                         { set_event_t0(&kevent,(yyvsp[-2].fp)); set_event_duration(&kevent,(yyvsp[0].fp)); }
#line 5299 "kate_parser.c"
    break;

  case 179: /* kd_event_def: timespec ARROW timespec  */
#line 2577 "kate_parser.y"
                                      { set_event_t0_t1(&kevent,(yyvsp[-2].fp),(yyvsp[0].fp)); }
#line 5305 "kate_parser.c"
    break;

  case 180: /* kd_event_def: REGION kd_region_name_or_index  */
#line 2578 "kate_parser.y"
                                             { set_event_region_index(&kevent,(yyvsp[0].number)); }
#line 5311 "kate_parser.c"
    break;

  case 181: /* $@25: %empty  */
#line 2579 "kate_parser.y"
                                             { init_region_from((yyvsp[0].number)); }
#line 5317 "kate_parser.c"
    break;

  case 182: /* kd_event_def: REGION kd_region_name_or_index $@25 '{' kd_region_defs '}'  */
#line 2580 "kate_parser.y"
                     { set_event_region(&kevent,&kregion); }
#line 5323 "kate_parser.c"
    break;

  case 183: /* $@26: %empty  */
#line 2581 "kate_parser.y"
                     { init_region(&kregion); }
#line 5329 "kate_parser.c"
    break;

  case 184: /* kd_event_def: REGION $@26 '{' kd_region_defs '}'  */
#line 2581 "kate_parser.y"
                                                                       { set_event_region(&kevent,&kregion); }
#line 5335 "kate_parser.c"
    break;

  case 185: /* kd_event_def: kd_optional_secondary STYLE kd_style_name_or_index  */
#line 2583 "kate_parser.y"
                    { if ((yyvsp[-2].number)) set_event_secondary_style_index(&kevent,(yyvsp[0].number)); else set_event_style_index(&kevent,(yyvsp[0].number)); }
#line 5341 "kate_parser.c"
    break;

  case 186: /* $@27: %empty  */
#line 2584 "kate_parser.y"
                                                                 {init_style_from((yyvsp[0].number)); }
#line 5347 "kate_parser.c"
    break;

  case 187: /* kd_event_def: kd_optional_secondary STYLE kd_style_name_or_index $@27 '{' kd_style_defs '}'  */
#line 2585 "kate_parser.y"
                    { if ((yyvsp[-6].number)) set_event_secondary_style(&kevent,&kstyle); else set_event_style(&kevent,&kstyle); }
#line 5353 "kate_parser.c"
    break;

  case 188: /* $@28: %empty  */
#line 2586 "kate_parser.y"
                                          { init_style(&kstyle); }
#line 5359 "kate_parser.c"
    break;

  case 189: /* kd_event_def: kd_optional_secondary STYLE $@28 '{' kd_style_defs '}'  */
#line 2587 "kate_parser.y"
                    { if ((yyvsp[-5].number)) set_event_secondary_style(&kevent,&kstyle); else set_event_style(&kevent,&kstyle); }
#line 5365 "kate_parser.c"
    break;

  case 190: /* kd_event_def: TEXT strings  */
#line 2588 "kate_parser.y"
                           { set_event_text(&kevent,(yyvsp[0].dynstring),0,0); kate_free((yyvsp[0].dynstring)); }
#line 5371 "kate_parser.c"
    break;

  case 191: /* kd_event_def: PRE TEXT strings  */
#line 2589 "kate_parser.y"
                               { set_event_text(&kevent,(yyvsp[0].dynstring),1,0); kate_free((yyvsp[0].dynstring)); }
#line 5377 "kate_parser.c"
    break;

  case 192: /* kd_event_def: MARKUP strings  */
#line 2590 "kate_parser.y"
                             { set_event_text(&kevent,(yyvsp[0].dynstring),0,1); kate_free((yyvsp[0].dynstring)); }
#line 5383 "kate_parser.c"
    break;

  case 193: /* kd_event_def: PRE MARKUP strings  */
#line 2591 "kate_parser.y"
                                 { set_event_text(&kevent,(yyvsp[0].dynstring),1,1); kate_free((yyvsp[0].dynstring)); }
#line 5389 "kate_parser.c"
    break;

  case 194: /* kd_event_def: TEXT SOURCE STRING  */
#line 2592 "kate_parser.y"
                                 { set_event_text_from(&kevent,(yyvsp[0].string),0,0); }
#line 5395 "kate_parser.c"
    break;

  case 195: /* kd_event_def: PRE TEXT SOURCE STRING  */
#line 2593 "kate_parser.y"
                                     { set_event_text_from(&kevent,(yyvsp[0].string),1,0); }
#line 5401 "kate_parser.c"
    break;

  case 196: /* kd_event_def: MARKUP SOURCE STRING  */
#line 2594 "kate_parser.y"
                                   { set_event_text_from(&kevent,(yyvsp[0].string),0,1); }
#line 5407 "kate_parser.c"
    break;

  case 197: /* kd_event_def: PRE MARKUP SOURCE STRING  */
#line 2595 "kate_parser.y"
                                       { set_event_text_from(&kevent,(yyvsp[0].string),1,1); }
#line 5413 "kate_parser.c"
    break;

  case 198: /* kd_event_def: strings  */
#line 2596 "kate_parser.y"
                      { set_event_text(&kevent,(yyvsp[0].dynstring),0,0); kate_free((yyvsp[0].dynstring)); }
#line 5419 "kate_parser.c"
    break;

  case 199: /* $@29: %empty  */
#line 2597 "kate_parser.y"
                     { init_motion(); }
#line 5425 "kate_parser.c"
    break;

  case 200: /* kd_event_def: MOTION $@29 '{' kd_motion_defs '}'  */
#line 2597 "kate_parser.y"
                                                               { kd_add_event_motion(kmotion); }
#line 5431 "kate_parser.c"
    break;

  case 201: /* kd_event_def: MOTION kd_motion_name_or_index  */
#line 2598 "kate_parser.y"
                                             { kd_add_event_motion_index((yyvsp[0].number)); }
#line 5437 "kate_parser.c"
    break;

  case 202: /* $@30: %empty  */
#line 2599 "kate_parser.y"
                                        {init_simple_glyph_pointer_motion(); }
#line 5443 "kate_parser.c"
    break;

  case 203: /* kd_event_def: SIMPLE_TIMED_GLYPH_MARKER $@30 '{' kd_simple_timed_glyph_marker_defs '}'  */
#line 2600 "kate_parser.y"
                    { kd_finalize_simple_timed_glyph_motion(kmotion); kd_add_event_motion(kmotion); }
#line 5449 "kate_parser.c"
    break;

  case 204: /* $@31: %empty  */
#line 2601 "kate_parser.y"
                                             {init_simple_glyph_pointer_motion(); }
#line 5455 "kate_parser.c"
    break;

  case 205: /* kd_event_def: SIMPLE_TIMED_GLYPH_STYLE_MORPH $@31 '{' kd_simple_timed_glyph_style_morph_defs '}'  */
#line 2602 "kate_parser.y"
                    { kd_finalize_simple_timed_glyph_motion(kmotion); kd_add_event_motion(kmotion); }
#line 5461 "kate_parser.c"
    break;

  case 206: /* kd_event_def: FONT MAPPING kd_font_mapping_name_or_index  */
#line 2603 "kate_parser.y"
                                                         { CHECK_KATE_API_ERROR(kate_encode_set_font_mapping_index(&k,(yyvsp[0].number))); }
#line 5467 "kate_parser.c"
    break;

  case 207: /* kd_event_def: PALETTE kd_palette_name_or_index  */
#line 2604 "kate_parser.y"
                                               { set_event_palette_index(&kevent,(yyvsp[0].number)); }
#line 5473 "kate_parser.c"
    break;

  case 208: /* $@32: %empty  */
#line 2605 "kate_parser.y"
                      { init_palette(); }
#line 5479 "kate_parser.c"
    break;

  case 209: /* kd_event_def: PALETTE $@32 '{' kd_palette_defs '}'  */
#line 2605 "kate_parser.y"
                                                                  { set_event_palette(&kevent,kpalette.palette); }
#line 5485 "kate_parser.c"
    break;

  case 210: /* kd_event_def: BITMAP kd_bitmap_name_or_index  */
#line 2606 "kate_parser.y"
                                             { set_event_bitmap_index(&kevent,(yyvsp[0].number)); }
#line 5491 "kate_parser.c"
    break;

  case 211: /* $@33: %empty  */
#line 2607 "kate_parser.y"
                     { init_bitmap(); }
#line 5497 "kate_parser.c"
    break;

  case 212: /* kd_event_def: BITMAP $@33 '{' kd_bitmap_defs '}'  */
#line 2607 "kate_parser.y"
                                                               { set_event_bitmap(&kevent,kbitmap.bitmap); }
#line 5503 "kate_parser.c"
    break;

  case 213: /* $@34: %empty  */
#line 2608 "kate_parser.y"
                                              {init_bitmap();}
#line 5509 "kate_parser.c"
    break;

  case 214: /* kd_event_def: DEFINE LOCAL BITMAP kd_opt_name $@34 '{' kd_bitmap_defs '}'  */
#line 2608 "kate_parser.y"
                                                                                      { add_local_bitmap(&k,(yyvsp[-4].string),kbitmap.bitmap); }
#line 5515 "kate_parser.c"
    break;

  case 215: /* kd_event_def: DEFINE LOCAL BITMAP kd_opt_name '=' kd_bitmap_name_or_index  */
#line 2609 "kate_parser.y"
                                                                          { add_local_bitmap_index(&k,(yyvsp[-2].string),(yyvsp[0].number)); }
#line 5521 "kate_parser.c"
    break;

  case 216: /* kd_event_def: META STRING '=' STRING  */
#line 2610 "kate_parser.y"
                                     { kd_add_event_meta((yyvsp[-2].string),(yyvsp[0].string)); }
#line 5527 "kate_parser.c"
    break;

  case 217: /* kd_event_def: META STRING '=' kd_meta_byte_stream_def  */
#line 2611 "kate_parser.y"
                                                      { kd_add_event_meta_byte_stream((yyvsp[-2].string)); }
#line 5533 "kate_parser.c"
    break;

  case 218: /* $@35: %empty  */
#line 2614 "kate_parser.y"
                                 {init_byte_stream((yyvsp[0].unumber));}
#line 5539 "kate_parser.c"
    break;

  case 219: /* kd_meta_byte_stream_def: UNUMBER $@35 '{' kd_byte_stream '}'  */
#line 2614 "kate_parser.y"
                                                                                { (yyval.number)=0; }
#line 5545 "kate_parser.c"
    break;

  case 220: /* kd_optional_secondary: SECONDARY  */
#line 2617 "kate_parser.y"
                                 { (yyval.number)=1; }
#line 5551 "kate_parser.c"
    break;

  case 221: /* kd_optional_secondary: %empty  */
#line 2618 "kate_parser.y"
                       { (yyval.number)=0; }
#line 5557 "kate_parser.c"
    break;

  case 222: /* strings: strings '+' STRING  */
#line 2621 "kate_parser.y"
                            { (yyval.dynstring)=catstrings((yyvsp[-2].dynstring),(yyvsp[0].string)); }
#line 5563 "kate_parser.c"
    break;

  case 223: /* strings: STRING  */
#line 2622 "kate_parser.y"
                { (yyval.dynstring)=catstrings(NULL,(yyvsp[0].string)); }
#line 5569 "kate_parser.c"
    break;

  case 225: /* kd_motion_defs: %empty  */
#line 2626 "kate_parser.y"
                {}
#line 5575 "kate_parser.c"
    break;

  case 226: /* kd_motion_def: MAPPING kd_motion_mapping  */
#line 2629 "kate_parser.y"
                                         { set_motion_mapping(kmotion,(yyvsp[0].number),(yyvsp[0].number)); }
#line 5581 "kate_parser.c"
    break;

  case 227: /* kd_motion_def: MAPPING kd_motion_mapping kd_motion_mapping  */
#line 2630 "kate_parser.y"
                                                           { set_motion_mapping(kmotion,(yyvsp[-1].number),(yyvsp[0].number)); }
#line 5587 "kate_parser.c"
    break;

  case 228: /* kd_motion_def: SEMANTICS kd_motion_semantics  */
#line 2631 "kate_parser.y"
                                             { set_motion_semantics(kmotion,(yyvsp[0].number)); }
#line 5593 "kate_parser.c"
    break;

  case 229: /* kd_motion_def: CURVE kd_curve_def_name_or_index kd_optional_curve_duration  */
#line 2632 "kate_parser.y"
                                                                           { add_curve_to_motion(kmotion,(yyvsp[0].fp)); }
#line 5599 "kate_parser.c"
    break;

  case 230: /* kd_motion_def: PERIODIC  */
#line 2633 "kate_parser.y"
                        { kmotion->periodic=1; }
#line 5605 "kate_parser.c"
    break;

  case 231: /* kd_optional_curve_duration: FOR float  */
#line 2636 "kate_parser.y"
                                      { (yyval.fp)=(yyvsp[0].fp); }
#line 5611 "kate_parser.c"
    break;

  case 232: /* kd_optional_curve_duration: FOR float '%'  */
#line 2637 "kate_parser.y"
                                          { (yyval.fp)=-(yyvsp[-1].fp)/(kate_float)100.0; }
#line 5617 "kate_parser.c"
    break;

  case 233: /* kd_optional_curve_duration: FOR float 'm'  */
#line 2638 "kate_parser.y"
                                          { (yyval.fp)=-(yyvsp[-1].fp)/(kate_float)1000000.0; }
#line 5623 "kate_parser.c"
    break;

  case 234: /* kd_optional_curve_duration: %empty  */
#line 2639 "kate_parser.y"
                            { (yyval.fp)=(kate_float)-1.0; }
#line 5629 "kate_parser.c"
    break;

  case 235: /* kd_motion_mapping: NONE  */
#line 2642 "kate_parser.y"
                        { (yyval.number)=kate_motion_mapping_none; }
#line 5635 "kate_parser.c"
    break;

  case 236: /* kd_motion_mapping: FRAME  */
#line 2643 "kate_parser.y"
                         { (yyval.number)=kate_motion_mapping_frame; }
#line 5641 "kate_parser.c"
    break;

  case 237: /* kd_motion_mapping: REGION  */
#line 2644 "kate_parser.y"
                          { (yyval.number)=kate_motion_mapping_region; }
#line 5647 "kate_parser.c"
    break;

  case 238: /* kd_motion_mapping: EVENT DURATION  */
#line 2645 "kate_parser.y"
                                  { (yyval.number)=kate_motion_mapping_event_duration; }
#line 5653 "kate_parser.c"
    break;

  case 239: /* kd_motion_mapping: BITMAP SIZE  */
#line 2646 "kate_parser.y"
                               { (yyval.number)=kate_motion_mapping_bitmap_size; }
#line 5659 "kate_parser.c"
    break;

  case 240: /* kd_motion_mapping: USER UNUMBER  */
#line 2647 "kate_parser.y"
                                {
                     if ((yyvsp[0].unumber)<kate_motion_mapping_user) yyerrorf("invalid value for user motion mapping (%u), should be 128 or more",(yyvsp[0].unumber));
                     (yyval.number)=(kate_motion_mapping)(yyvsp[0].unumber);
                   }
#line 5668 "kate_parser.c"
    break;

  case 241: /* kd_motion_semantics: TIME  */
#line 2653 "kate_parser.y"
                          { (yyval.number)=kate_motion_semantics_time; }
#line 5674 "kate_parser.c"
    break;

  case 242: /* kd_motion_semantics: REGION POSITION  */
#line 2654 "kate_parser.y"
                                     { (yyval.number)=kate_motion_semantics_region_position; }
#line 5680 "kate_parser.c"
    break;

  case 243: /* kd_motion_semantics: REGION SIZE  */
#line 2655 "kate_parser.y"
                                 { (yyval.number)=kate_motion_semantics_region_size; }
#line 5686 "kate_parser.c"
    break;

  case 244: /* kd_motion_semantics: TEXT ALIGNMENT  */
#line 2656 "kate_parser.y"
                                    { (yyval.number)=kate_motion_semantics_text_alignment_int; }
#line 5692 "kate_parser.c"
    break;

  case 245: /* kd_motion_semantics: INTERNAL TEXT ALIGNMENT  */
#line 2657 "kate_parser.y"
                                             { (yyval.number)=kate_motion_semantics_text_alignment_int; }
#line 5698 "kate_parser.c"
    break;

  case 246: /* kd_motion_semantics: EXTERNAL TEXT ALIGNMENT  */
#line 2658 "kate_parser.y"
                                             { (yyval.number)=kate_motion_semantics_text_alignment_ext; }
#line 5704 "kate_parser.c"
    break;

  case 247: /* kd_motion_semantics: TEXT POSITION  */
#line 2659 "kate_parser.y"
                                   { (yyval.number)=kate_motion_semantics_text_position; }
#line 5710 "kate_parser.c"
    break;

  case 248: /* kd_motion_semantics: TEXT SIZE  */
#line 2660 "kate_parser.y"
                               { (yyval.number)=kate_motion_semantics_text_size; }
#line 5716 "kate_parser.c"
    break;

  case 249: /* kd_motion_semantics: MARKER UNUMBER POSITION  */
#line 2661 "kate_parser.y"
                                             { (yyval.number)=kd_get_marker_position_semantics((yyvsp[-1].unumber)); }
#line 5722 "kate_parser.c"
    break;

  case 250: /* kd_motion_semantics: GLYPH POINTER UNUMBER  */
#line 2662 "kate_parser.y"
                                           { (yyval.number)=kd_get_glyph_pointer_semantics((yyvsp[0].unumber)); }
#line 5728 "kate_parser.c"
    break;

  case 251: /* kd_motion_semantics: TEXT COLOR RG  */
#line 2663 "kate_parser.y"
                                   { (yyval.number)=kate_motion_semantics_text_color_rg; }
#line 5734 "kate_parser.c"
    break;

  case 252: /* kd_motion_semantics: TEXT COLOR BA  */
#line 2664 "kate_parser.y"
                                   { (yyval.number)=kate_motion_semantics_text_color_ba; }
#line 5740 "kate_parser.c"
    break;

  case 253: /* kd_motion_semantics: BACKGROUND COLOR RG  */
#line 2665 "kate_parser.y"
                                         { (yyval.number)=kate_motion_semantics_background_color_rg; }
#line 5746 "kate_parser.c"
    break;

  case 254: /* kd_motion_semantics: BACKGROUND COLOR BA  */
#line 2666 "kate_parser.y"
                                         { (yyval.number)=kate_motion_semantics_background_color_ba; }
#line 5752 "kate_parser.c"
    break;

  case 255: /* kd_motion_semantics: DRAW COLOR RG  */
#line 2667 "kate_parser.y"
                                   { (yyval.number)=kate_motion_semantics_draw_color_rg; }
#line 5758 "kate_parser.c"
    break;

  case 256: /* kd_motion_semantics: DRAW COLOR BA  */
#line 2668 "kate_parser.y"
                                   { (yyval.number)=kate_motion_semantics_draw_color_ba; }
#line 5764 "kate_parser.c"
    break;

  case 257: /* kd_motion_semantics: STYLE MORPH  */
#line 2669 "kate_parser.y"
                                 { (yyval.number)=kate_motion_semantics_style_morph; }
#line 5770 "kate_parser.c"
    break;

  case 258: /* kd_motion_semantics: TEXT PATH  */
#line 2670 "kate_parser.y"
                               { (yyval.number)=kate_motion_semantics_text_path; }
#line 5776 "kate_parser.c"
    break;

  case 259: /* kd_motion_semantics: TEXT PATH SECTION  */
#line 2671 "kate_parser.y"
                                       { (yyval.number)=kate_motion_semantics_text_path_section; }
#line 5782 "kate_parser.c"
    break;

  case 260: /* kd_motion_semantics: DRAW  */
#line 2672 "kate_parser.y"
                          { (yyval.number)=kate_motion_semantics_draw; }
#line 5788 "kate_parser.c"
    break;

  case 261: /* kd_motion_semantics: VISIBLE SECTION  */
#line 2673 "kate_parser.y"
                                     { (yyval.number)=kate_motion_semantics_text_visible_section; }
#line 5794 "kate_parser.c"
    break;

  case 262: /* kd_motion_semantics: 'z'  */
#line 2674 "kate_parser.y"
                         { (yyval.number)=kate_motion_semantics_z; }
#line 5800 "kate_parser.c"
    break;

  case 263: /* kd_motion_semantics: HORIZONTAL MARGINS  */
#line 2675 "kate_parser.y"
                                        { (yyval.number)=kate_motion_semantics_horizontal_margins; }
#line 5806 "kate_parser.c"
    break;

  case 264: /* kd_motion_semantics: VERTICAL MARGINS  */
#line 2676 "kate_parser.y"
                                      { (yyval.number)=kate_motion_semantics_vertical_margins; }
#line 5812 "kate_parser.c"
    break;

  case 265: /* kd_motion_semantics: BITMAP POSITION  */
#line 2677 "kate_parser.y"
                                     { (yyval.number)=kate_motion_semantics_bitmap_position; }
#line 5818 "kate_parser.c"
    break;

  case 266: /* kd_motion_semantics: BITMAP SIZE  */
#line 2678 "kate_parser.y"
                                 { (yyval.number)=kate_motion_semantics_bitmap_size; }
#line 5824 "kate_parser.c"
    break;

  case 267: /* kd_motion_semantics: MARKER UNUMBER BITMAP  */
#line 2679 "kate_parser.y"
                                           { (yyval.number)=kd_get_marker_bitmap_semantics((yyvsp[-1].unumber)); }
#line 5830 "kate_parser.c"
    break;

  case 268: /* kd_motion_semantics: GLYPH POINTER UNUMBER BITMAP  */
#line 2680 "kate_parser.y"
                                                  { (yyval.number)=kd_get_glyph_pointer_bitmap_semantics((yyvsp[-1].unumber)); }
#line 5836 "kate_parser.c"
    break;

  case 269: /* kd_motion_semantics: DRAW WIDTH  */
#line 2681 "kate_parser.y"
                                { (yyval.number)=kate_motion_semantics_draw_width; }
#line 5842 "kate_parser.c"
    break;

  case 270: /* kd_motion_semantics: USER UNUMBER  */
#line 2682 "kate_parser.y"
                                  {
                       if ((yyvsp[0].unumber)<kate_motion_semantics_user) yyerrorf("invalid value for user motion semantics (%u), should be 128 or more",(yyvsp[0].unumber));
                       (yyval.number)=(kate_motion_semantics)(yyvsp[0].unumber);
                     }
#line 5851 "kate_parser.c"
    break;

  case 272: /* kd_simple_timed_glyph_marker_defs: %empty  */
#line 2689 "kate_parser.y"
                                   {}
#line 5857 "kate_parser.c"
    break;

  case 273: /* kd_simple_timed_glyph_marker_def: GLYPH POINTER UNUMBER  */
#line 2692 "kate_parser.y"
                                                        { kmotion->semantics=get_glyph_pointer_offset((yyvsp[0].unumber)); }
#line 5863 "kate_parser.c"
    break;

  case 274: /* kd_simple_timed_glyph_marker_def: 'Y' MAPPING kd_motion_mapping  */
#line 2693 "kate_parser.y"
                                                                { kmotion->y_mapping=(yyvsp[0].number); }
#line 5869 "kate_parser.c"
    break;

  case 275: /* kd_simple_timed_glyph_marker_def: HEIGHT FROM float TO float  */
#line 2694 "kate_parser.y"
                                                             { karaoke_base_height=(yyvsp[-2].fp); karaoke_top_height=(yyvsp[0].fp); }
#line 5875 "kate_parser.c"
    break;

  case 276: /* kd_simple_timed_glyph_marker_def: PAUSE FOR timespec  */
#line 2695 "kate_parser.y"
                                                     { add_glyph_pause((yyvsp[0].fp),(kate_float)0.0); }
#line 5881 "kate_parser.c"
    break;

  case 277: /* kd_simple_timed_glyph_marker_def: GLYPH UNUMBER IN timespec  */
#line 2696 "kate_parser.y"
                                                            { add_glyph_transition((yyvsp[-2].unumber),(yyvsp[0].fp),(kate_float)0.0,(kate_float)1.0,0,(kate_float)0.0); }
#line 5887 "kate_parser.c"
    break;

  case 278: /* kd_simple_timed_glyph_marker_def: GLYPH UNUMBER AT timespec  */
#line 2697 "kate_parser.y"
                                                            { add_glyph_transition((yyvsp[-2].unumber),(yyvsp[0].fp),(kate_float)0.0,(kate_float)1.0,1,(kate_float)0.0); }
#line 5893 "kate_parser.c"
    break;

  case 280: /* kd_simple_timed_glyph_style_morph_defs: %empty  */
#line 2701 "kate_parser.y"
                                        {}
#line 5899 "kate_parser.c"
    break;

  case 281: /* kd_simple_timed_glyph_style_morph_def: GLYPH POINTER UNUMBER  */
#line 2704 "kate_parser.y"
                                                             { kmotion->semantics=get_glyph_pointer_offset((yyvsp[0].unumber)); }
#line 5905 "kate_parser.c"
    break;

  case 282: /* kd_simple_timed_glyph_style_morph_def: FROM STYLE kd_style_name_or_index TO STYLE kd_style_name_or_index  */
#line 2706 "kate_parser.y"
                                              { set_style_morph(&kevent,(yyvsp[-3].number),(yyvsp[0].number)); }
#line 5911 "kate_parser.c"
    break;

  case 283: /* kd_simple_timed_glyph_style_morph_def: PAUSE FOR timespec  */
#line 2707 "kate_parser.y"
                                                          { add_glyph_pause((yyvsp[0].fp),(kate_float)0.0); }
#line 5917 "kate_parser.c"
    break;

  case 284: /* kd_simple_timed_glyph_style_morph_def: GLYPH UNUMBER IN timespec  */
#line 2708 "kate_parser.y"
                                                                 { add_glyph_transition((yyvsp[-2].unumber),(yyvsp[0].fp),(kate_float)0.0,(kate_float)0.0,0,(kate_float)1.0); }
#line 5923 "kate_parser.c"
    break;

  case 285: /* kd_simple_timed_glyph_style_morph_def: GLYPH UNUMBER AT timespec  */
#line 2709 "kate_parser.y"
                                                                 { add_glyph_transition((yyvsp[-2].unumber),(yyvsp[0].fp),(kate_float)0.0,(kate_float)0.0,1,(kate_float)1.0); }
#line 5929 "kate_parser.c"
    break;

  case 286: /* kd_simple_timed_glyph_style_morph_def: STRING IN timespec  */
#line 2710 "kate_parser.y"
                                                          { add_glyph_transition_to_text((yyvsp[-2].string),(yyvsp[0].fp),(kate_float)0.0,(kate_float)0.0,0,(kate_float)1.0); }
#line 5935 "kate_parser.c"
    break;

  case 287: /* kd_simple_timed_glyph_style_morph_def: STRING AT timespec  */
#line 2711 "kate_parser.y"
                                                          { add_glyph_transition_to_text((yyvsp[-2].string),(yyvsp[0].fp),(kate_float)0.0,(kate_float)0.0,1,(kate_float)1.0); }
#line 5941 "kate_parser.c"
    break;

  case 288: /* $@36: %empty  */
#line 2714 "kate_parser.y"
                   { if ((yyvsp[0].unumber)>59) yyerrorf("Value must be between 0 and 59, but is %u",(yyvsp[0].unumber)); }
#line 5947 "kate_parser.c"
    break;

  case 289: /* unumber60: UNUMBER $@36  */
#line 2714 "kate_parser.y"
                                                                                            { (yyval.unumber)=(yyvsp[-1].unumber); }
#line 5953 "kate_parser.c"
    break;

  case 290: /* $@37: %empty  */
#line 2717 "kate_parser.y"
               { if ((yyvsp[0].fp)<(kate_float)0.0 || (yyvsp[0].fp)>=(kate_float)60.0) yyerrorf("Value must be between 0 (inclusive) and 60 (exclusive), but is %f",(yyvsp[0].fp)); }
#line 5959 "kate_parser.c"
    break;

  case 291: /* float60: float $@37  */
#line 2717 "kate_parser.y"
                                                                                                                                                     { (yyval.fp)=(yyvsp[-1].fp); }
#line 5965 "kate_parser.c"
    break;

  case 292: /* kd_opt_comma: ','  */
#line 2720 "kate_parser.y"
                  {}
#line 5971 "kate_parser.c"
    break;

  case 293: /* kd_opt_comma: %empty  */
#line 2721 "kate_parser.y"
              {}
#line 5977 "kate_parser.c"
    break;

  case 294: /* directionality: L2R_T2B  */
#line 2724 "kate_parser.y"
                        { (yyval.number)=kate_l2r_t2b; }
#line 5983 "kate_parser.c"
    break;

  case 295: /* directionality: R2L_T2B  */
#line 2725 "kate_parser.y"
                        { (yyval.number)=kate_r2l_t2b; }
#line 5989 "kate_parser.c"
    break;

  case 296: /* directionality: T2B_R2L  */
#line 2726 "kate_parser.y"
                        { (yyval.number)=kate_t2b_r2l; }
#line 5995 "kate_parser.c"
    break;

  case 297: /* directionality: T2B_L2R  */
#line 2727 "kate_parser.y"
                        { (yyval.number)=kate_t2b_l2r; }
#line 6001 "kate_parser.c"
    break;

  case 299: /* kd_font_range_defs: %empty  */
#line 2731 "kate_parser.y"
                    {}
#line 6007 "kate_parser.c"
    break;

  case 300: /* kd_font_range_def: FIRST CODE POINT STRING  */
#line 2734 "kate_parser.y"
                                           { set_font_range_first_code_point_string((yyvsp[0].string)); }
#line 6013 "kate_parser.c"
    break;

  case 301: /* kd_font_range_def: FIRST CODE POINT UNUMBER  */
#line 2735 "kate_parser.y"
                                            { set_font_range_first_code_point((yyvsp[0].unumber)); }
#line 6019 "kate_parser.c"
    break;

  case 302: /* kd_font_range_def: LAST CODE POINT STRING  */
#line 2736 "kate_parser.y"
                                          { set_font_range_last_code_point_string((yyvsp[0].string)); }
#line 6025 "kate_parser.c"
    break;

  case 303: /* kd_font_range_def: LAST CODE POINT UNUMBER  */
#line 2737 "kate_parser.y"
                                           { set_font_range_last_code_point((yyvsp[0].unumber)); }
#line 6031 "kate_parser.c"
    break;

  case 304: /* kd_font_range_def: FIRST BITMAP kd_bitmap_name_or_index  */
#line 2738 "kate_parser.y"
                                                        { set_font_range_first_bitmap((yyvsp[0].number)); }
#line 6037 "kate_parser.c"
    break;

  case 306: /* kd_font_mapping_defs: %empty  */
#line 2742 "kate_parser.y"
                      {}
#line 6043 "kate_parser.c"
    break;

  case 307: /* $@38: %empty  */
#line 2745 "kate_parser.y"
                           {init_font_range();}
#line 6049 "kate_parser.c"
    break;

  case 308: /* kd_font_mapping_def: RANGE $@38 '{' kd_font_range_defs '}'  */
#line 2745 "kate_parser.y"
                                                                           { add_font_range_to_mapping(); }
#line 6055 "kate_parser.c"
    break;

  case 309: /* kd_font_mapping_def: RANGE kd_font_range_name_or_index  */
#line 2746 "kate_parser.y"
                                                       { krange=ki.font_ranges[(yyvsp[0].number)]; add_font_range_to_mapping(); }
#line 6061 "kate_parser.c"
    break;


#line 6065 "kate_parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 2749 "kate_parser.y"


