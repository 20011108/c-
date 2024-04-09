#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <hiredis/hiredis.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include "gen-cpp/container_mng.h"
using namespace std;
void AddUser(const char *_name, const char *_password)
{
    char buff[1024] = {0};

    sprintf(buff, "./add_user.sh %s %s", _name, _password);

    system(buff);
}
void AddUserMd5(const char *_name, const char *_password)
{
    char buff[1024] = {0};

    sprintf(buff, "echo '%s:%s' >> userfile", _name, _password);

    system(buff);
}
bool CheckUser(const char *_name, const char *_password_dgst)
{
    bool bRet = false;

    if (fork() > 0)
    {
        int iStatus = 0;
        wait(&iStatus);
        if (0 == iStatus)
        {
            bRet = true;
        }
    }
    else
    {
        execlp("./check_user.sh", "./check_user.sh", _name, _password_dgst, NULL);
    }


    return bRet;
}
void DelUser(const char *_name)
{
    char buff[1024] = {0};

    sprintf(buff, "./del_user.sh %s", _name);

    system(buff);
}

static int g_cur_select = 0;
std::string create_container(int room_no)
{
    //return "x.x.x.x xxxx"
    //
    //1 confirm which server to create container
    std::string server_array[2] = {"192.168.88.128", "192.168.88.128"};
    std::string cur_server = server_array[g_cur_select];
    g_cur_select++;
    g_cur_select %= sizeof(server_array)/sizeof(server_array[0]);
    shared_ptr<apache::thrift::transport::TTransport> socket(new apache::thrift::transport::TSocket(cur_server.c_str(), 9090));
    shared_ptr<apache::thrift::protocol::TProtocol> protocol(new apache::thrift::protocol::TBinaryProtocol(socket));

    container_mngClient client(protocol);

    socket->open();
    int port = client.create_room(room_no);
#if 0
    //2 send create container req to that server
    //publish a piece of message to channel "create_room"
    auto pc = redisConnect("127.0.0.1", 6379);
    if (NULL != pc)
    {
        freeReplyObject(redisCommand(pc, "publish create_room %s:%d", cur_server.c_str(), room_no));
        //3 wait for new container's port
        freeReplyObject(redisCommand(pc, "subscribe server_port"));
        redisReply*reply = NULL;
        if (REDIS_OK == redisGetReply(pc, (void **)&reply))
        {
            port.append(reply->element[2]->str);
            freeReplyObject(reply);
        }
        redisFree(pc);
    }
#endif


    //4 return IP + PORT
    cur_server.append(" ");
    return cur_server +  std::to_string(port);
}

std::string check_room(const char *_room_no)
{
    //return "x.x.x.x xxxx"
    std::string ret;

    auto pc = redisConnect("127.0.0.1", 6379);
    if (NULL != pc)
    {
        redisReply *reply = (redisReply *)redisCommand(pc, "get room_no%s", _room_no);
        if (reply->str != NULL)
            ret.append(reply->str);
        freeReplyObject(reply);
        redisFree(pc);
    }
    return ret;
}
