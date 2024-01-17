/*                                                                       
 * Copyright (c) 2024 Indraj Gandham <indraj@posteo.net>                 
 *                                                                       
 * Permission to use, copy, modify, and distribute this software for any 
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.     
 *                                                                       
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF      
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN 
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.        
 */

#ifndef ESIRRA_QUEUE_H
#define ESIRRA_QUEUE_H

#include <stdbool.h>

/* INTERNAL USE ONLY */
struct esirra_QueueNode {

        struct esirra_QueueNode *next;
        void *data;
        size_t size;

};

struct esirra_Queue {

        size_t len;
        struct esirra_QueueNode *front;
        struct esirra_QueueNode *rear;

};

void
esirra_Queue_init(struct esirra_Queue *queue);

bool
esirra_Queue_push(struct esirra_Queue *queue, void *data, size_t size);

void *
esirra_Queue_pop(struct esirra_Queue *queue, size_t *size);

#endif
