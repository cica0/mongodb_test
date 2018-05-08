#ifndef MONGODB_H
#define MONGODB_H

#include "base.h"
#include "mongo/client/dbclient.h"

//TODO:这个命名空间的名字不太对
namespace mongo_db {

class MongoData{
public:
    void init(const string &dbname, const string &collection);
    int insert(const string &field, const string &value);
    int get(vector<string> &result, const string &field, const string &query="");
    int delOnce(const string &field, const string &value);
private:
    mongo::DBClientConnection conn;
    string strCollection;
};

}

#endif
