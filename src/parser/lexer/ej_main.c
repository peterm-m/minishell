#include "ft_dlst.h"

void pr(void *n)
{
    printf("%s\n", (char *)n);
}

int main()
{
    t_dlst	*head;
    t_dlst  *new;


    head = ft_dlstnew(NULL);
    head->data = "1";
    new = ft_dlstnew(NULL);
    new->data = "2";
    ft_dlstadd(head, new);
    ft_dlstiter(head, pr);
    return (0);
}
