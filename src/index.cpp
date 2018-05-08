#include "index.h"
#include "mongodb.h"

extern unordered_map<uint32_t, Nodes*> g_index_data;

void init_index_data() {
}
int init_index() {
    //初始化日志

    //连接数据库
    mongo_db::MongoData database;
    database.init("mytest","test");
//    if (!database.insert("student_id","myid")) {
//        cout << "insert ok" << endl;
//    }
    //用哈希桶实现倒排，每种倒排用一个哈希桶,目前暂时只实现关键字的倒排
    std::hash<std::string> hashFunc;
    vector<string> resultId;
    vector<string> resultURL;
    database.get(resultId, "id");
    database.get(resultURL, "url");
    if (resultId.size()!=resultURL.size()) {
        cout << "the data in database is err" << endl;
        return -1;
    }
    for(unsigned int i = 0; i < resultId.size(); ++i) {
        //插入倒排中
        if (g_index_data.find(hashFunc(resultId[i])) == g_index_data.end()) {
            Nodes *NodePtr = new Nodes();
            NodePtr->next = NULL;
            NodePtr->url = resultURL[i];
//            NodePtr->first = NodePtr;
        } else {
            Nodes *NodePtr = g_index_data[hashFunc(resultId[i])];
            while(NodePtr->url != resultURL[i]) {
                NodePtr = NodePtr->next;
            }
            if (NodePtr->next != NULL) {
                continue;
            }
            Nodes *NodePtr_temp = new Nodes();
            NodePtr_temp->next = NULL;
            NodePtr_temp->url = resultURL[i];
            NodePtr->next = NodePtr_temp;
        }
    }

//    database.get(result, "name");
//    if (!database.delOnce("student_id", "myid")) {
//        cout << "del ok" << endl;
//    }
    //遍历数据库，创建倒排
    return 0;
}
