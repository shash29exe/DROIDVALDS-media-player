/* SoX Resampler Library      Copyright (c) 2007-13 robs@users.sourceforge.net
 * Licence for this file: LGPL v2.1                  See LICENCE for details. */

#include <stdlib.h>
#include <math.h>
#include <libavutil/version.h>
#define USE_LAVUTIL_TX  (LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(57,19,100))
#if USE_LAVUTIL_TX
# include <libavutil/tx.h>
# include <libavutil/mem.h>
# include <string.h>

typedef struct AVTXWrapper {
    AVTXContext *ctx;
    av_tx_fn fn;

    int len;
    int inv;

    float *tmp;
} AVTXWrapper;
#else /* !USE_LAVUTIL_TX */
#include <libavcodec/avfft.h>
#endif /* !USE_LAVUTIL_TX */
#include "filter.h"
#include "rdft_t.h"

#if USE_LAVUTIL_TX
static void * forward_setup(int len) {
    int ret;
    float scale = 0 ? 0.5f : 1.0f;
    AVTXWrapper *s;

    s = av_mallocz(sizeof(*s));
    if (!s)
        return NULL;

    s->len = 1 << (int)(log(len)/log(2)+.5);
    s->inv = 0;

    ret = av_tx_init(&s->ctx, &s->fn, AV_TX_FLOAT_RDFT, 0,
                     s->len, &scale, 0x0);
    if (ret < 0) {
        av_free(s);
        return NULL;
    }

    s->tmp = av_malloc((s->len + 2)*sizeof(float));
    if (!s->tmp) {
        av_tx_uninit(&s->ctx);
        av_free(s);
        return NULL;
    }

    return s;
}
static void * backward_setup(int len) {
    int ret;
    float scale = 1 ? 0.5f : 1.0f;
    AVTXWrapper *s;

    s = av_mallocz(sizeof(*s));
    if (!s)
        return NULL;

    s->len = 1 << (int)(log(len)/log(2)+.5);
    s->inv = 1;

    ret = av_tx_init(&s->ctx, &s->fn, AV_TX_FLOAT_RDFT, 1,
                     s->len, &scale, 0x0);
    if (ret < 0) {
        av_free(s);
        return NULL;
    }

    s->tmp = av_malloc((s->len + 2)*sizeof(float));
    if (!s->tmp) {
        av_tx_uninit(&s->ctx);
        av_free(s);
        return NULL;
    }

    return s;
}
static void rdft(int length, void * setup, float * data) {
    AVTXWrapper *w = setup;
    float *src = w->inv ? w->tmp : data;
    float *dst = w->inv ? data : w->tmp;

    if (w->inv) {
        memcpy(src, data, w->len*sizeof(float));

        src[w->len] = src[1];
        src[1] = 0.0f;
    }

    w->fn(w->ctx, dst, (void *)src, sizeof(float));

    if (!w->inv) {
        dst[1] = dst[w->len];
        memcpy(data, dst, w->len*sizeof(float));
    }
    (void)length;
}
static void rdft_end(AVTXWrapper *s)
{
    if (s) {
        av_tx_uninit(&s->ctx);
        av_free(s->tmp);
        av_free(s);
    }
}
#else
static void * forward_setup(int len) {return av_rdft_init((int)(log(len)/log(2)+.5),DFT_R2C);}
static void * backward_setup(int len) {return av_rdft_init((int)(log(len)/log(2)+.5),IDFT_C2R);}
static void rdft(int length, void * setup, float * h) {av_rdft_calc(setup, h); (void)length;}
#endif
static int multiplier(void) {return 2;}
static void nothing(void) {}
static int flags(void) {return 0;}

fn_t _soxr_rdft32_cb[] = {
  (fn_t)forward_setup,
  (fn_t)backward_setup,
#if USE_LAVUTIL_TX
  (fn_t)rdft_end,
#else
  (fn_t)av_rdft_end,
#endif
  (fn_t)rdft,
  (fn_t)rdft,
  (fn_t)rdft,
  (fn_t)rdft,
  (fn_t)_soxr_ordered_convolve_f,
  (fn_t)_soxr_ordered_partial_convolve_f,
  (fn_t)multiplier,
  (fn_t)nothing,
  (fn_t)malloc,
  (fn_t)calloc,
  (fn_t)free,
  (fn_t)flags,
};
