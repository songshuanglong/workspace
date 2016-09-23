#ifndef ITABLE_H
#define ITABLE_H

struct PlayerData;

class ITable
{
public:
    // 桌子ID
    virtual unsigned int __cdecl id() = 0;

    // 当前桌子中的玩家数量
    virtual unsigned short __cdecl currentPlayerCount() = 0;

    // 当前桌子所能承载的最大玩家数量
    virtual unsigned short __cdecl maxPlayerCount() = 0;

    // 当前桌子中的椅子数
    virtual unsigned short __cdecl chairCount() = 0;

    // 获取指定椅子上的玩家数据
    virtual const PlayerData * __cdecl playerData(unsigned short chairID) = 0;

    // 获取当前桌子状态
    virtual unsigned short __cdecl status() = 0;

    // 设置当前桌子状态
    virtual void setStatus(unsigned short tableStatus) = 0;

    // 设置定时期
    virtual bool __cdecl setTimer(unsigned int timerID, unsigned long elapse, unsigned int bRepeat) = 0;

    // 删除定时器
    virtual bool __cdecl killTimer(unsigned int timerID) = 0;

    // 向指定玩家发送数据
    virtual bool __cdecl sendData(unsigned short chairID, unsigned short cmd, void *data, unsigned short size) = 0;

    // 结束游戏
    virtual bool __cdecl endGame() = 0;

    // 保存玩家对局后获得经验、积分、钻石及金币
    virtual bool __cdecl writePlayerScore(unsigned short chairID, long long score, unsigned int revenue, unsigned short kind, const char *comment) = 0;
};

#endif // ITABLE_H
