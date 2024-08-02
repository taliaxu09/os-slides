#include <assert.h>
#include <stdio.h>
#include <sys/queue.h>

struct list_entry {
    int id;
    TAILQ_ENTRY(list_entry) pointers;
};
TAILQ_HEAD(list_head, list_entry);
static struct list_head list_head;

void print_list(void) {
    printf("List:");
    struct list_entry* e;
    TAILQ_FOREACH(e, &list_head, pointers) {
        printf(" %d", e->id);
    }
    printf("\n");
}

void print_list_last(void) {
    struct list_entry* e = TAILQ_LAST(&list_head, list_head);
    printf("List last: %d\n", e->id);
}

int main(void) {
    TAILQ_INIT(&list_head);
    assert(TAILQ_EMPTY(&list_head));

    struct list_entry e1;
    e1.id = 1;
    TAILQ_INSERT_TAIL(&list_head, &e1, pointers);
    printf("Inserted 1\n");
    print_list();

    struct list_entry e2;
    e2.id = 2;
    TAILQ_INSERT_TAIL(&list_head, &e2, pointers);
    printf("\nInserted 2\n");
    print_list();
    print_list_last();

    TAILQ_REMOVE(&list_head, &e1, pointers);
    printf("\nRemoved 1\n");
    print_list();

    return 0;
}
