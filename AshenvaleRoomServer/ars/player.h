#ifndef CPLAYER_H
#define CPLAYER_H

#include "common.h"
#include "playerdata.h"
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

class CPlayer :
        public boost::enable_shared_from_this< CPlayer >,
        public boost::noncopyable,
        public PlayerData
{
public:
    typedef boost::shared_ptr< CPlayer > PlayerPtr;

public:
    ~CPlayer();

protected:
    CPlayer();
};

#endif // CPLAYER_H
