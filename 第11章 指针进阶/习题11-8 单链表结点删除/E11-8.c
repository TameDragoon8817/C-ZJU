struct ListNode *readlist()
{
    struct ListNode *head, *p1, *p2;
    int n = 0;
    head = NULL;
    p1 = p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    scanf("%d", &p1->data);
    while (p1->data != -1)
    {
        n++;
        if (n == 1)
            head = p1;
        else
            p2->next = p1;

        p2 = p1;
        p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
        scanf("%d", &p1->data);
    }
    p2->next = NULL;
    return head;
}
struct ListNode *deletem(struct ListNode *L, int m)
{
    struct ListNode *p, *q;
    for (p = L, q = NULL; p != NULL; p = p->next)
    {
        if (p->data == m)
        {
            if (q && p != L)
            {
                q->next = p->next;
            }
            else
            {
                L = p->next;
            }
        }
        else
        {
            q = p;
        }
    }
    return L;
}