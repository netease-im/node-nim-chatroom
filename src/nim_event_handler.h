#ifndef NIM_NODE_SDK_EVENTHANDLER_H
#define NIM_NODE_SDK_EVENTHANDLER_H

#include <node.h>
#include <unordered_map>
#include "nim_node_helper.h"

using v8::Function;
using v8::Object;
using v8::Persistent;

namespace nim_node {

class EventHandler {
private:
    /* data */
public:
    EventHandler(/* args */){};
    ~EventHandler(){};

    void AddEventHandler(const utf8_string& eventName,
                         Persistent<Object>& obj,
                         Persistent<Function>& callback);
    int RemoveEventHandler(const utf8_string& eventName);
    void RemoveAllEventhandler();

protected:
    std::unordered_map<utf8_string, BaseCallbackPtr> callbacks_;
};
}  // namespace nim_node
#endif  // NIM_NODE_SDK_EVENTHANDLER_H