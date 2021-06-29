/**
 * @file nim_chatroom_node_engine.cpp
 * @author Dylan
 * @brief NIM chatroom node plugin engine root file
 * @version 0.1
 * @date 2021-05-08
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "nim_chatroom_node_engine.h"
#include <node.h>
#include <node_object_wrap.h>
#include "api/nim_chatroom_node.h"

using v8::Local;
using v8::Object;

void InitChatRoom(Local<Object> module) {
    printf("init chatroom begin.\n");
    nim_chatroom_node::ChatRoom::InitModule(module);
    printf("init chatroom end.\n");
}

NODE_MODULE(nim_chatroom, InitChatRoom)
