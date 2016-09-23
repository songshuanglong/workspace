#ifndef CPOOL_H
#define CPOOL_H

#include "common.h"
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include <list>
#include <algorithm>

template < typename T >
class CPool :
        public boost::noncopyable
{
public:
    typedef boost::mutex Mutex;
    typedef boost::mutex::scoped_lock ScopedLock;
    typedef boost::shared_ptr< T > Element;

public:
    CPool()
    {}
    ~CPool()
    {}

    Element alloc()
    {
        Element e;
        ScopedLock lock(_lock);

        if(_elements.empty()){
            e = T::get();
        }else{
            for(typename std::list< Element >::iterator it = _elements.begin(); it != _elements.end(); ++it){
                if((*it).use_count() == 1){
                    e = *it;
                    break;
                }
            }
        }

        return e;
    }

    void free(const Element &e)
    {
        ScopedLock lock(_lock);

        typename std::list< Element >::iterator it =
                std::find(_elements.begin(), _elements.end(), e);
        if(it == _elements.end()){
            _elements.push_back(e);
        }
    }

private:
    // 对象队列
    std::list< Element > _elements;

    // 对象队列锁
    Mutex _lock;
};

#endif // CPOOL_H
