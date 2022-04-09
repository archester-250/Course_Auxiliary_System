#include "login.h"
int hash(int i);
int main()
{
    HashMap<int, int, hash> h;
    h.put(1,2);
    h.put(3,4);
    printf("%d", h.get(3));
    return 0;
}
int hash(int i)
{
    return i;
}
