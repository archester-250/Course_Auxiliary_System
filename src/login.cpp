#include "login.h"
int hash(int i);
int main()
{
    HashMap<int, int> h(100);
    h.put(1,2);
    h.put(3,4);
    printf("%d", h.get(3));
    return 0;
}
int hash(int i)
{
    return i;
}
