#ifndef CENGINE_H
#define CENGINE_H

#include "common.h"
#include "pool.h"
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>

class CBuffer;
class CPlayer;
class CTable;
class CDbOperator;
class CNetConnector;
class CNetAcceptor;

class CEngine :
        public boost::enable_shared_from_this< CEngine >,
        public boost::noncopyable
{
public:
    typedef boost::shared_ptr< CEngine > EnginePtr;

public:
    ~CEngine();

    // 对象构造器
    static EnginePtr get();

protected:
    CEngine();
};

#endif // CENGINE_H
