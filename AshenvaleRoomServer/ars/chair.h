#ifndef CCHAIR_H
#define CCHAIR_H

#include "common.h"
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

class CPlayer;

class CChair :
        public boost::enable_shared_from_this< CChair >,
        public boost::noncopyable
{
public:
    typedef boost::shared_ptr< CChair > ChairPtr;
    typedef boost::shared_ptr< CPlayer > PlayerPtr;

public:
    ~CChair();

    // 获取椅子ID
    unsigned short id();

    // 获取当前椅子上的玩家
    const PlayerPtr &player();

    // 玩家坐下
    bool sitdown(const PlayerPtr &player);

    // 玩家离开
    void leave();

protected:
    CChair();

private:
    // 椅子ID
    unsigned short _id;

    // 椅子所坐的玩家
    PlayerPtr _player;
};

#endif // CCHAIR_H
