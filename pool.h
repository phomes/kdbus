/*
 * Copyright (C) 2013 Kay Sievers
 * Copyright (C) 2013 Greg Kroah-Hartman <gregkh@linuxfoundation.org>
 * Copyright (C) 2013 Linux Foundation
 * Copyright (C) 2013 Daniel Mack <daniel@zonque.org>
 *
 * kdbus is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation; either version 2.1 of the License, or (at
 * your option) any later version.
 */

#ifndef __KDBUS_POOL_H
#define __KDBUS_POOL_H

struct kdbus_pool;

int kdbus_pool_init(struct kdbus_pool **pool, size_t size);
void kdbus_pool_cleanup(struct kdbus_pool *pool);

int kdbus_pool_alloc(struct kdbus_pool *pool, size_t size, size_t *off);
int kdbus_pool_free(struct kdbus_pool *pool, size_t off);
size_t kdbus_pool_remain(const struct kdbus_pool *pool);

ssize_t kdbus_pool_write(const struct kdbus_pool *pool, size_t off,
			 void *data, size_t len);
ssize_t kdbus_pool_write_user(const struct kdbus_pool *pool, size_t off,
			 void __user *data, size_t len);
int kdbus_pool_mmap(const struct kdbus_pool *pool, struct vm_area_struct *vma);
#endif
