#include "base.h"
#include "split_word.h"
#include "index.h"

hash_map<uint32_t, Nodes> g_index_data;

int main(int argc, char** argv) {
    //index初始化
    init_index();
    //启动监听端口，监听请求
//    vector<string> words;
//    string input = "他来到了网易杭研大厦";
//    split_word(input, words);
//    cout << limonp::Join(words.begin(), words.end(), "/") << endl;
    return 0;
}
