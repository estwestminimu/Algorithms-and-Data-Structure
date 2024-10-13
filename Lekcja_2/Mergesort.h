// Szymon Tomaszewski
#ifndef MERGESORT
#define MERGESORT

template <typename T>
void mergesort(T first, T last)
{
    int distance = last - first;
    if (distance > 1)
    {
        T mid = first + (distance / 2);
        mergesort(first, mid);
        mergesort(mid, last);
        std::inplace_merge(first, mid, last);
    }
}

#endif
