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

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "esirra_queue.h"

void
test_esirra_Queue(void)
{
        struct esirra_Queue queue;
        double x[3];
        double *temp;

        x[0] = 0.0;
        x[1] = 0.1;
        x[2] = 0.2;

        esirra_Queue_init(&queue);

        assert(esirra_Queue_push(&queue, &x[0], sizeof(double)));
        assert(esirra_Queue_push(&queue, &x[1], sizeof(double)));
        assert(esirra_Queue_push(&queue, &x[2], sizeof(double)));
        
        assert((&queue)->len == 3);

        for (int i = 0; i < 3; i++) {
                temp = esirra_Queue_pop(&queue, NULL);
                assert(temp != NULL);
                assert(*temp == x[i]);
                free(temp);
                temp = NULL;
        }

}

int
main(void)
{
        printf("test: esirra_Queue ... ");
        test_esirra_Queue();
        printf("done\n");

        printf("pass: all tests succeeded\n");
        return EXIT_SUCCESS;
}
