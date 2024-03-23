/*
 * This work is hereby placed into the public domain. The author(s) waive
 * all copyright and related rights (including but not limited to economic
 * and moral rights) to the maximum extent permitted by law.
 *
 * Author(s):
 *         Indraj Gandham <indraj@posteo.net> (2024)
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
