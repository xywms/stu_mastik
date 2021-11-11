/*
 * Copyright 2021 The University of Adelaide
 *
 * This file is part of Mastik.
 *
 * Mastik is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mastik is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Mastik.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MM_H
#define MM_H
#include <mastik/low.h>
#include <mastik/info.h>

enum pagetype {
  PAGETYPE_SMALL,
  PAGETYPE_HUGE
};
typedef enum pagetype pagetype_e;

enum cachelevel {
  L1,
  L2,
  L3
};
typedef enum cachelevel cachelevel_e;


typedef struct mm* mm_t;

mm_t mm_prepare(lxinfo_t l1info, lxinfo_t l2info, lxinfo_t l3info);

void* mm_requestline(mm_t mm, cachelevel_e cachelevel, int line);

void mm_returnline(mm_t mm, void* line);

void mm_release(mm_t mm);

int mm_initialisel3(mm_t mm);


#endif