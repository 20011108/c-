#include <stdio.h>
#include <string>

void AddUser(const char *_name, const char *_password);
bool CheckUser(const char *_name, const char *_password_dgst);
void DelUser(const char *_name);
void AddUserMd5(const char *_name, const char *_password);
std::string create_container(int _room_no);
std::string check_room(const char *_room_no);
