#include "mongodb.h"

namespace mongo_db{

void MongoData::init(const string &dbname, const string &collection) {
    try {
        conn.connect("localhost");
        strCollection = dbname + "." + collection;
        cout << "connect ok" << endl;
    } catch(mongo::DBException &e) {
        cout << "caught" <<e.what() << endl;
    }
}

int MongoData::insert(const string &field, const string &value) {
    mongo::BSONObjBuilder oBOJCharacter;
    oBOJCharacter.append(field, value); // 学号  
//    oBOJCharacter.append("name", "myname"); // 名字    
    try {  
        conn.insert( strCollection, oBOJCharacter.obj());  
        std::string strDBError = conn.getLastError();  
        if (!strDBError.empty()) {  
            std::cout << "mongodb error, err = " << strDBError.c_str() << std::endl;  
            return -1;
        }  
    } catch( const mongo::DBException &e ) {  
        std::cout << "insert Info caught " << e.what() << std::endl;  
        return -1;
    }  
    return 0;
}

int MongoData::get(vector<string> &result, const string &field,const string &query) {
    try {  
        std::auto_ptr<mongo::DBClientCursor> cursor = conn.query(strCollection,query);
        mongo::BSONObj p;
        while(cursor->more()) {
            p = cursor->next();
            if (p.hasField(field)) {
                cout << p.getField(field) << endl;
                result.push_back(p.getField(field));
            }
        }
    } catch (const mongo::DBException &e) {  
        std::cout << "getInfo caught " << e.what() << std::endl;  
        return -1;
    }  
    return 0;
}

int MongoData::delOnce(const string &field, const string &value) {
    mongo::BSONObjBuilder oBOJCharacter;
    try {  
        conn.remove(strCollection, mongo::BSONObjBuilder().append(field, value).obj(), true);
    } catch (const mongo::DBException &e) {  
        std::cout << "delInfo caught " << e.what() << std::endl;  
        return -1;
    }  
    return 0;
}

}
