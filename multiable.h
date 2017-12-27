#ifndef MULTIABLE_H
#define MULTIABLE_H
#include <set>

class Compare;

template <class KEY, bool BOOL, class compare = Compare >
class MultiableSet
{
    std::multiset<KEY,compare> _ms;

public:

    std::multiset<KEY,compare> data()
    {
        return _ms;
    }



    void kiir()
    {
        typename std::multiset<KEY>::iterator i = _ms.begin();
        while( i != _ms.end())
        {
            KEY element = *i;
            std::cout << element << std::endl;
            i++;
        }
    }

    compare key_comp() const
    {
        compare c;
        return c;
    }

    MultiableSet& insert(const KEY& key)
    {
        if(!BOOL)
        {
            typename std::multiset<KEY>::iterator it;

            it = _ms.find(key);

            if( it == _ms.end() )
            {
                _ms.insert(key);
            }
        }
        else
        {
            _ms.insert(key);
        }

        return *this;
    }

    template <class T = const KEY*>
    void insert(T key1, T key2)
    {
        if(!BOOL)
        {
            typename std::multiset<KEY>::iterator it;

            for(; key1 < key2; key1++)
            {
                    it = _ms.find(*key1);

                    if( it == _ms.end() )
                    {
                        _ms.insert(*key1);
                    }
            }
        }
        else
        {
            for(; key1 <= key2; key1++)
            {
                _ms.insert(*key1);
            }
        }
    }

    int size() const
    {
        return _ms.size();
    }

    int count(const KEY& key) const
    {
        return _ms.count(key);
    }

    void erase(const KEY& key)
    {
        _ms.erase(key);
    }

};

#endif // MULTIABLE_H
