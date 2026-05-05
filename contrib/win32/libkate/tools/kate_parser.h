/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 327 "kate_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int katedesc_parse (void);


#endif /* !YY_KATEDESC_KATE_PARSER_H_INCLUDED  */
