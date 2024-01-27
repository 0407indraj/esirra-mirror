/*
 * Copyright (c) 2024 Indraj Gandham <indraj@posteo.net>
 * Copyright (c) 2024 Elliot Blower <elliotb@airmail.cc>
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

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "esirra_queue.h"

void
esirra_Queue_init(struct esirra_Queue *queue)
{
        queue->len = 0;
        queue->front = NULL;
        queue->rear = NULL;
}

bool
esirra_Queue_push(struct esirra_Queue *queue, void *data, size_t size)
{
        struct esirra_QueueNode *node;

        node = malloc(sizeof(*node));
        if (node == NULL) {
                return false;
        }

        node->data = malloc(size);
        if (node->data == NULL) {
                free(node);
                return false;
        }

        memcpy(node->data, data, size);
        node->size = size;
        node->next = NULL;

        if (queue->len > 0) {
                queue->rear->next = node;
                queue->rear = node;
        } else {
                queue->rear = node;
                queue->front = node;
        }

        queue->len++;

        return true;
}

void *
esirra_Queue_pop(struct esirra_Queue *queue, size_t *size)
{
        struct esirra_QueueNode *new_front;
        void *data;

        if (queue->len <= 0) {
                return NULL;
        }

        if (size != NULL) {
                *size = queue->front->size;
        }

        data = queue->front->data;

        new_front = queue->front->next;
        free(queue->front);
        queue->front = new_front;
        queue->len--;

        return data;
}
