/*
 * OpenixIMG.h Tool for unpack Allwinner IMAGEWTY image
 * Copyright (c) 2012, Ithamar R. Adema <ithamar@upgrade-android.com>
 * Copyright (c) 2022, YuzukiTsuru <GloomyGhost@GloomyGhost.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * See README and LICENSE for more details.
 */

#ifndef OPENIXIMG_OPENIXIMG_H
#define OPENIXIMG_OPENIXIMG_H

#include <stdio.h>

#include "twofish.h"
#include "rc6.h"

#include "IMAGEWTY.h"

#ifdef WIN32
#define MKDIR(p)    mkdir(p)
#else
#define MKDIR(p)    mkdir(p,S_IRWXU)
#endif


int flag_encryption_enabled;

/* Crypto */
rc6_ctx_t header_ctx;
rc6_ctx_t fileheaders_ctx;
rc6_ctx_t filecontent_ctx;
u4byte tf_key[32];

const char *progname;

void recursive_mkdir(const char *dir);

void crypto_init(void);

void *rc6_decrypt_inplace(void *p, size_t len, rc6_ctx_t *ctx);

FILE *dir_fopen(const char *dir, const char *path, const char *mode);

int unpack_image(const char *infn, const char *outdn);

void dump_image(const char *image_file, char *outdir);

#endif //OPENIXIMG_OPENIXIMG_H