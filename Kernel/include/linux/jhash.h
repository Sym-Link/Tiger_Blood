#ifndef _LINUX_JHASH_H
#define _LINUX_JHASH_H

/* jhash.h: Jenkins hash support.
 *
 * Copyright (C) 1996 Bob Jenkins (bob_jenkins@burtleburtle.net)
 *
 * http://burtleburtle.net/bob/hash/
 *
 * These are the credits from Bob's sources:
 *
 * lookup2.c, by Bob Jenkins, December 1996, Public Domain.
 * hash(), hash2(), hash3, and mix() are externally useful functions.
 * Routines to test the hash are included if SELF_TEST is defined.
 * You can use this free for any purpose.  It has no warranty.
 *
 * Copyright (C) 2003 David S. Miller (davem@redhat.com)
 *
 * I've modified Bob's hash to be useful in the Linux kernel, and
 * any bugs present are surely my fault.  -DaveM
 */

/* Best hash sizes are of power of two */
#define jhash_size(n)   ((u32)1<<(n))
/* Mask the hash value, i.e (value & jhash_mask(n)) instead of (value % n) */
#define jhash_mask(n)   (jhash_size(n)-1)

extern u32 jhash(const void *key, u32 length, u32 initval);
extern u32 jhash2(const u32 *k, u32 length, u32 initval);
extern u32 jhash_3words(u32 a, u32 b, u32 c, u32 initval);

static inline u32 jhash_2words(u32 a, u32 b, u32 initval)
{
	return jhash_3words(a, b, 0, initval);
}

static inline u32 jhash_1word(u32 a, u32 initval)
{
	return jhash_3words(a, 0, 0, initval);
}

#endif /* _LINUX_JHASH_H */
