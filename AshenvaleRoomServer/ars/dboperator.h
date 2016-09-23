#ifndef CDBOPERATOR_H
#define CDBOPERATOR_H

#include "common.h"
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

#include <mysql.h>

struct PlayerData;

class CDbOperator :
        public boost::enable_shared_from_this< CDbOperator >,
        public boost::noncopyable
{
public:
    typedef boost::shared_ptr< CDbOperator > DbOperatorPtr;

public:
    ~CDbOperator();

    // 初始化并连接数据库
    bool init();

    // 从数据库读取用户信息
    bool queryPlayerData(PlayerData * data);

    // 对象构造器
    static DbOperatorPtr get();

protected:
    CDbOperator();

private:
    std::string _host;
    std::string _user;
    std::string _password;
    std::string _db;

    unsigned short _port;

    //
    MYSQL * _con;
};

#endif // CDBOPERATOR_H
