/**
 * @file nim_chatroom_node.h
 * @author Dylan
 * @brief NIM ChatRoom Node wrapper
 * @version 0.1
 * @date 2021-05-08
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef NIM_CHATROOM_SDK_NODE_API_NIM_CHATROOM_NODE_H_
#define NIM_CHATROOM_SDK_NODE_API_NIM_CHATROOM_NODE_H_

#include <node.h>
#include <node_object_wrap.h>
#include "nim_chatroom_cpp_wrapper/api/nim_chatroom_cpp.h"
#include "nim_wrapper_util/nim_json_util.h"
#include "nim_wrapper_util/nim_string_util.h"
#include "nim_node_helper.h"

namespace nim_chatroom_node {

class ChatRoom : public node::ObjectWrap {
private:
    /* data */
public:
    static void New(const FunctionCallbackInfo<Value>& args);
    static void InitModule(Local<Object>& module);

public:
    NIM_CHATROOM_SDK_NODE_API(Init);
    NIM_CHATROOM_SDK_NODE_API(RegEnterCb);
    NIM_CHATROOM_SDK_NODE_API(RegExitCb);
    NIM_CHATROOM_SDK_NODE_API(RegExitCbEx);
    NIM_CHATROOM_SDK_NODE_API(RegSendMsgAckCb);
    NIM_CHATROOM_SDK_NODE_API(RegReceiveMsgCb);
    NIM_CHATROOM_SDK_NODE_API(RegReceiveMsgsCb);
    NIM_CHATROOM_SDK_NODE_API(RegNotificationCb);
    NIM_CHATROOM_SDK_NODE_API(RegLinkConditionCb);
    NIM_CHATROOM_SDK_NODE_API(IndependentEnter);
    NIM_CHATROOM_SDK_NODE_API(IndependentEnterEx);
    NIM_CHATROOM_SDK_NODE_API(AnonymousEnter);
    NIM_CHATROOM_SDK_NODE_API(AnonymousEnterEx);
    NIM_CHATROOM_SDK_NODE_API(Enter);
    NIM_CHATROOM_SDK_NODE_API(GetLoginState);
    NIM_CHATROOM_SDK_NODE_API(SetMsgsBatchReport);
    NIM_CHATROOM_SDK_NODE_API(SendMsg);
    NIM_CHATROOM_SDK_NODE_API(GetMembersOnlineAsync);
    NIM_CHATROOM_SDK_NODE_API(GetMembersByTagOnlineAsync);
    NIM_CHATROOM_SDK_NODE_API(GetMembersCountByTagOnlineAsync);
    NIM_CHATROOM_SDK_NODE_API(GetMessageHistoryOnlineAsync);
    NIM_CHATROOM_SDK_NODE_API(SetMemberAttributeOnlineAsync);
    NIM_CHATROOM_SDK_NODE_API(GetInfoAsync);
    NIM_CHATROOM_SDK_NODE_API(GetMemberInfoByIDsAsync);
    NIM_CHATROOM_SDK_NODE_API(KickMemberAsync);
    NIM_CHATROOM_SDK_NODE_API(SetProxy);
    NIM_CHATROOM_SDK_NODE_API(TempMuteMemberAsync);
    NIM_CHATROOM_SDK_NODE_API(TempMuteMemberByTagAsync);
    NIM_CHATROOM_SDK_NODE_API(UpdateRoomInfoAsync);
    NIM_CHATROOM_SDK_NODE_API(UpdateMyRoomRoleAsync);
    NIM_CHATROOM_SDK_NODE_API(QueueOfferAsync);
    NIM_CHATROOM_SDK_NODE_API(QueuePollAsync);
    NIM_CHATROOM_SDK_NODE_API(QueueListAsync);
    NIM_CHATROOM_SDK_NODE_API(QueueHeaderAsync);
    NIM_CHATROOM_SDK_NODE_API(QueueDropAsync);
    NIM_CHATROOM_SDK_NODE_API(UnregChatroomCb);
    NIM_CHATROOM_SDK_NODE_API(QueueBatchUpdateAsync);
    NIM_CHATROOM_SDK_NODE_API(Exit);
    NIM_CHATROOM_SDK_NODE_API(CleanUp);

protected:
    explicit ChatRoom(Isolate* isolate);
    ~ChatRoom();

private:
    DECLARE_CLASS;
    Isolate* isolate_;
};

}  // namespace nim_chatroom_node

#endif  // NIM_CHATROOM_SDK_NODE_API_NIM_CHATROOM_NODE_H_
