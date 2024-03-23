/*
 * This work is hereby placed into the public domain. The author(s) waive
 * all copyright and related rights (including but not limited to economic
 * and moral rights) to the maximum extent permitted by law.
 *
 * Author(s):
 *         Indraj Gandham <indraj@posteo.net> (2024)
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
