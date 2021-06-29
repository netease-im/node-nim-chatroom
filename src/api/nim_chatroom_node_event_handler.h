/**
 * @file nim_chatroom_node_event_handler.h
 * @author Dylan
 * @brief NIM chatroom node event handler header file
 * @version 0.1
 * @date 2021-05-10
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef NIM_CHATROOM_SDK_NODE_API_NIM_CHATROOM_NODE_EVENT_HANDLER_H_
#define NIM_CHATROOM_SDK_NODE_API_NIM_CHATROOM_NODE_EVENT_HANDLER_H_

#include <node.h>
#include "nim_chatroom_cpp_wrapper/helper/nim_chatroom_helper.h"
#include "nim_event_handler.h"
#include "nim_node_helper.h"

using v8::Object;

namespace nim_chatroom_node {

static const char* kChatRoomBaseCallback = "OnChatRoomBaseCallback";
static const char* kChatRoomEnterCallback = "OnEnterCallback";
static const char* kChatRoomExitCallback = "OnExitCallback";
static const char* kChatRoomExitCallbackEx = "OnExitCallbackEx";
static const char* kChatRoomSendMsgAckCallback = "OnSendMsgAckCallback";
static const char* kChatRoomReceiveMsgCallback = "OnReceiveMsgCallback";
static const char* kChatRoomReceiveMsgsCallback = "OnReceiveMsgsCallback";
static const char* kChatRoomNotificationCallback = "OnNotificationCallback";
static const char* kChatRoomLinkConditionCallback = "OnLinkConditionCallback";

static const char* kChatRoomGetMemberCallback = "OnGetMembersOnlineCallback";
static const char* kChatRoomGetMemberCountByTagCallback =
    "OnGetMemberCountByTagOnlienCallback";
static const char* kChatRoomGetMsgHisCallback = "OnGetMsgHisCallback";
static const char* kChatRoomMemberInfoCallback = "OnMemberInfoChangedCallback";
static const char* kChatRoomRoomInfoCallback = "OnGetRoomInfoCallback";

static const char* kChatRoomQueuePollCallback = "QueuePollCallback";
static const char* kChatRoomQueueListCallback = "QueueListCallback";

class ChatRoomEventHandler : public nim_node::EventHandler {
private:
    /* data */
public:
    ChatRoomEventHandler() {}
    ~ChatRoomEventHandler() {}
    SINGLETON_DEFINE(ChatRoomEventHandler);

    static void OnBaseCallback(const BaseCallbackPtr& bcb,
                               int64_t room_id,
                               int error_code);
    static void OnEnterCallback(
        int64_t room_id,
        const nim_chatroom::NIMChatRoomEnterStep step,
        int error_code,
        const nim_chatroom::ChatRoomInfo& info,
        const nim_chatroom::ChatRoomMemberInfo& my_info);
    static void OnExitCallback(int64_t room_id,
                               int error_code,
                               nim_chatroom::NIMChatRoomExitReason exit_reason);
    static void OnExitCallbackEx(
        int64_t room_id,
        int error_code,
        const nim_chatroom::NIMChatRoomExitReasonInfo& exit_info);
    static void OnSendMsgAckCallback(
        int64_t room_id,
        int error_code,
        const nim_chatroom::ChatRoomMessage& result);
    static void OnReceiveMsgCallback(
        int64_t room_id,
        const nim_chatroom::ChatRoomMessage& result);
    static void OnReceiveMsgsCallback(
        int64_t room_id,
        const std::list<nim_chatroom::ChatRoomMessage>& result);
    static void OnNotificationCallback(
        int64_t room_id,
        const nim_chatroom::ChatRoomNotification& notification);
    static void OnLinkConditionCallback(
        int64_t room_id,
        const nim_chatroom::NIMChatRoomLinkCondition condition);
    static void OnGetMemberOnlineCallback(
        const BaseCallbackPtr& bcb,
        int64_t room_id,
        int error_code,
        const std::list<nim_chatroom::ChatRoomMemberInfo>& infos);
    static void OnGetMemberCountByTagCallback(const BaseCallbackPtr& bcb,
                                              int64_t room_id,
                                              int error_code,
                                              uint64_t count);
    static void OnGetMsgHistoryOnlineCallback(
        const BaseCallbackPtr& bcb,
        int64_t room_id,
        int error_code,
        const std::list<nim_chatroom::ChatRoomMessage>& msgs);
    static void OnMemberInfoChangedCallback(
        const BaseCallbackPtr& bcb,
        int64_t room_id,
        int error_code,
        const nim_chatroom::ChatRoomMemberInfo& info);
    static void OnGetRoomInfoCallback(const BaseCallbackPtr& bcb,
                                      int64_t room_id,
                                      int error_code,
                                      const nim_chatroom::ChatRoomInfo& info);
    static void OnQueuePollCalback(
        const BaseCallbackPtr& bcb,
        int64_t room_id,
        int error_code,
        const nim_chatroom::ChatRoomQueueElement& element);
    static void OnQueueListCallback(const BaseCallbackPtr& bcb,
                                    int64_t room_id,
                                    int error_code,
                                    const nim_chatroom::ChatRoomQueue& queue);
    static void OnQueueBatchUpdateCallback(
        const BaseCallbackPtr& bcb,
        int64_t room_id,
        int error_code,
        const std::list<std::string>& not_in_queue);

private:
    void Node_OnBaseCallback(const BaseCallbackPtr& bcb,
                             int64_t room_id,
                             int error_code);
    void Node_OnEnterCallback(int64_t room_id,
                              const nim_chatroom::NIMChatRoomEnterStep step,
                              int error_code,
                              const nim_chatroom::ChatRoomInfo& info,
                              const nim_chatroom::ChatRoomMemberInfo& my_info);
    void Node_OnExitCallback(int64_t room_id,
                             int error_code,
                             nim_chatroom::NIMChatRoomExitReason exit_reason);
    void Node_OnExitCallbackEx(
        int64_t room_id,
        int error_code,
        const nim_chatroom::NIMChatRoomExitReasonInfo& exit_info);
    void Node_OnSendMsgAckCallback(int64_t room_id,
                                   int error_code,
                                   const nim_chatroom::ChatRoomMessage& result);
    void Node_OnReceiveMsgCallback(int64_t room_id,
                                   const nim_chatroom::ChatRoomMessage& result);
    void Node_OnReceiveMsgsCallback(
        int64_t room_id,
        const std::list<nim_chatroom::ChatRoomMessage>& result);
    void Node_OnNotificationCallback(
        int64_t room_id,
        const nim_chatroom::ChatRoomNotification& notification);
    void Node_OnLinkConditionCallback(
        int64_t room_id,
        const nim_chatroom::NIMChatRoomLinkCondition condition);
    void Node_OnGetMemberOnlineCallback(
        const BaseCallbackPtr& bcb,
        int64_t room_id,
        int error_code,
        const std::list<nim_chatroom::ChatRoomMemberInfo>& infos);
    void Node_OnGetMemberCountByTagCallback(const BaseCallbackPtr& bcb,
                                            int64_t room_id,
                                            int error_code,
                                            uint64_t count);
    void Node_OnGetMsgHistoryOnlineCallback(
        const BaseCallbackPtr& bcb,
        int64_t room_id,
        int error_code,
        const std::list<nim_chatroom::ChatRoomMessage>& msgs);
    void Node_OnMemberInfoChangedCallback(
        const BaseCallbackPtr& bcb,
        int64_t room_id,
        int error_code,
        const nim_chatroom::ChatRoomMemberInfo& info);
    void Node_OnGetRoomInfoCallback(const BaseCallbackPtr& bcb,
                                    int64_t room_id,
                                    int error_code,
                                    const nim_chatroom::ChatRoomInfo& info);
    void Node_OnQueuePollCalback(
        const BaseCallbackPtr& bcb,
        int64_t room_id,
        int error_code,
        const nim_chatroom::ChatRoomQueueElement& element);
    void Node_OnQueueListCallback(const BaseCallbackPtr& bcb,
                                  int64_t room_id,
                                  int error_code,
                                  const nim_chatroom::ChatRoomQueue& queue);
    void Node_OnQueueBatchUpdateCallback(
        const BaseCallbackPtr& bcb,
        int64_t room_id,
        int error_code,
        const std::list<std::string>& not_in_queue);
};

}  // namespace nim_chatroom_node

#endif  // NIM_CHATROOM_SDK_NODE_API_NIM_CHATROOM_NODE_EVENT_HANDLER_H_
