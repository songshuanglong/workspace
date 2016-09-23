#ifndef PLAYERDATA_H
#define PLAYERDATA_H

struct PlayerData
{
    // ID
    unsigned int _id;

    // 玩家性别
    unsigned char _sex;

    // 玩家状态
    unsigned char _status;

    // 当前等级
    unsigned char _level;

    // 当前玩家所在的桌子ID
    unsigned short _tid;

    // 当前玩家所在的椅子ID
    unsigned short _cid;

    // 当前已获得的经验
    long long _experience;

    // 当前已获得的积分
    long long _score;

    // 当前玩家账户中的钻石余额
    long long _diamond;

    // 当前玩家账户中的金币余额
    long long _gold;
};

#endif // PLAYERDATA_H
