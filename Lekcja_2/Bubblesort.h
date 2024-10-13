// Szymon Tomaszewski
#ifndef BUBBLESORT
#define BUBBLESORT

template <typename T>
void bubblesort(T first, T last)
{
    bool swapped;
    do
    {
        swapped = false;
        for (T i = first; i < last - 1; ++i)
        {
            if (*(i + 1) < *i)
            {
                auto temp = *i;
                *i = *(i + 1);
                *(i + 1) = temp;
                swapped = true;
            }
        }
        --last;
    } while (swapped);
}

#endif
