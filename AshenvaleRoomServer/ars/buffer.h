#ifndef CBUFFER_H
#define CBUFFER_H

#include "common.h"
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>
#include <boost/asio.hpp>

class CBuffer :
        public boost::enable_shared_from_this< CBuffer >,
        public boost::noncopyable
{
public:
    typedef boost::shared_ptr< CBuffer > BufferPtr;
    typedef boost::asio::mutable_buffers_1 MutableBuffer;

public:
    ~CBuffer();

    // 重置此缓冲区
    void reset();

    // 生成读缓冲区对象
    MutableBuffer rb();

    // 生成写缓冲区对象
    MutableBuffer wb();

    // 默认对象构造器， 默认使用4k内存
    static BufferPtr get();

    // 对象构造器
    static BufferPtr get(size_t);

protected:
    CBuffer(size_t);

public:
    boost::shared_array< char > _memory;
    size_t _total;
    size_t _current;
};

#endif // CBUFFER_H
