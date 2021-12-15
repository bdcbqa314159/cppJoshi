#ifndef WRAPPER_H
#define WRAPPER_H

template <class T>
class Wrapper
{

public:
    Wrapper()
    {
        dataPtr = 0;
    }

    Wrapper(const T &inner)
    {
        dataPtr = inner.clone();
    }

    ~Wrapper()
    {
        if (dataPtr != 0)
        {
            delete dataPtr;
        }
    }

    Wrapper(const Wrapper<T> &original)
    {
        if (original.dataPtr != 0)
        {
            dataPtr = original.dataPtr->clone();
        }
        else
        {
            dataPtr = 0;
        }
    }

    Wrapper &operator=(const Wrapper<T> &original)
    {

        if (this != &original)
        {
            if (dataPtr != 0)
            {
                delete dataPtr;
            }
            dataPtr = (original.dataPtr != 0) ? original.dataPtr->clone() : 0;
        }

        return *this;
    }

    T &operator*()
    {
        return *dataPtr;
    }

    const T &operator*() const
    {
        return *dataPtr;
    }

    const T *const operator->() const
    {
        return dataPtr;
    }

    T *operator->()
    {
        return dataPtr;
    }

private:
    T *dataPtr;
};

#endif