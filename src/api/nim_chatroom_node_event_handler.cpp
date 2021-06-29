#include "nim_chatroom_node_event_handler.h"
#include <list>
#include <string>
#include "helper/nim_chatroom_node_helper.h"
#include "nim_node_async_queue.h"

namespace nim_chatroom_node {

void ChatRoomEventHandler::OnBaseCallback(const BaseCallbackPtr& bcb,
                                          int64_t room_id,
                                          int error_code) {
    nim_node::node_async_call::async_call([=]() {
        ChatRoomEventHandler::GetInstance()->Node_OnBaseCallback(bcb, room_id,
                                                                 error_code);
    });
}

void ChatRoomEventHandler::OnEnterCallback(
    int64_t room_id,
    const nim_chatroom::NIMChatRoomEnterStep step,
    int error_code,
    const nim_chatroom::ChatRoomInfo& info,
    const nim_chatroom::ChatRoomMemberInfo& my_info) {
    nim_node::node_async_call::async_call([=]() {
        ChatRoomEventHandler::GetInstance()->Node_OnEnterCallback(
            room_id, step, error_code, info, my_info);
    });
}

void ChatRoomEventHandler::OnExitCallback(
    int64_t room_id,
    int error_code,
    nim_chatroom::NIMChatRoomExitReason exit_reason) {
    nim_node::node_async_call::async_call([=]() {
        ChatRoomEventHandler::GetInstance()->Node_OnExitCallback(
            room_id, error_code, exit_reason);
    });
}

void ChatRoomEventHandler::OnExitCallbackEx(
    int64_t room_id,
    int error_code,
    const nim_chatroom::NIMChatRoomExitReasonInfo& exit_info) {
    nim_node::node_async_call::async_call([=]() {
        ChatRoomEventHandler::GetInstance()->Node_OnExitCallbackEx(
            room_id, error_code, exit_info);
    });
}

void ChatRoomEventHandler::OnSendMsgAckCallback(
    int64_t room_id,
    int error_code,
    const nim_chatroom::ChatRoomMessage& result) {
    nim_node::node_async_call::async_call([=]() {
        ChatRoomEventHandler::GetInstance()->Node_OnSendMsgAckCallback(
            room_id, error_code, result);
    });
}

void ChatRoomEventHandler::OnReceiveMsgCallback(
    int64_t room_id,
    const nim_chatroom::ChatRoomMessage& result) {
    nim_node::node_async_call::async_call([=]() {
        ChatRoomEventHandler::GetInstance()->Node_OnReceiveMsgCallback(room_id,
                                                                       result);
    });
}

void ChatRoomEventHandler::OnReceiveMsgsCallback(
    int64_t room_id,
    const std::list<nim_chatroom::ChatRoomMessage>& result) {
    nim_node::node_async_call::async_call([=]() {
        ChatRoomEventHandler::GetInstance()->Node_OnReceiveMsgsCallback(room_id,
                                                                        result);
    });
}

void ChatRoomEventHandler::OnNotificationCallback(
    int64_t room_id,
    const nim_chatroom::ChatRoomNotification& notification) {
    nim_node::node_async_call::async_call([=]() {
        ChatRoomEventHandler::GetInstance()->Node_OnNotificationCallback(
            room_id, notification);
    });
}

void ChatRoomEventHandler::OnLinkConditionCallback(
    int64_t room_id,
    const nim_chatroom::NIMChatRoomLinkCondition condition) {
    nim_node::node_async_call::async_call([=]() {
        ChatRoomEventHandler::GetInstance()->Node_OnLinkConditionCallback(
            room_id, condition);
    });
}

void ChatRoomEventHandler::OnGetMemberOnlineCallback(
    const BaseCallbackPtr& bcb,
    int64_t room_id,
    int error_code,
    const std::list<nim_chatroom::ChatRoomMemberInfo>& infos) {
    nim_node::node_async_call::async_call([=]() {
        ChatRoomEventHandler::GetInstance()->Node_OnGetMemberOnlineCallback(
            bcb, room_id, error_code, infos);
    });
}

void ChatRoomEventHandler::OnGetMemberCountByTagCallback(
    const BaseCallbackPtr& bcb,
    int64_t room_id,
    int error_code,
    uint64_t count) {
    nim_node::node_async_call::async_call([=]() {
        ChatRoomEventHandler::GetInstance()->Node_OnGetMemberCountByTagCallback(
            bcb, room_id, error_code, count);
    });
}

void ChatRoomEventHandler::OnGetMsgHistoryOnlineCallback(
    const BaseCallbackPtr& bcb,
    int64_t room_id,
    int error_code,
    const std::list<nim_chatroom::ChatRoomMessage>& msgs) {
    nim_node::node_async_call::async_call([=]() {
        ChatRoomEventHandler::GetInstance()->Node_OnGetMsgHistoryOnlineCallback(
            bcb, room_id, error_code, msgs);
    });
}

void ChatRoomEventHandler::OnMemberInfoChangedCallback(
    const BaseCallbackPtr& bcb,
    int64_t room_id,
    int error_code,
    const nim_chatroom::ChatRoomMemberInfo& info) {
    nim_node::node_async_call::async_call([=]() {
        ChatRoomEventHandler::GetInstance()->Node_OnMemberInfoChangedCallback(
            bcb, room_id, error_code, info);
    });
}

void ChatRoomEventHandler::OnGetRoomInfoCallback(
    const BaseCallbackPtr& bcb,
    int64_t room_id,
    int error_code,
    const nim_chatroom::ChatRoomInfo& info) {
    nim_node::node_async_call::async_call([=]() {
        ChatRoomEventHandler::GetInstance()->Node_OnGetRoomInfoCallback(
            bcb, room_id, error_code, info);
    });
}

void ChatRoomEventHandler::OnQueuePollCalback(
    const BaseCallbackPtr& bcb,
    int64_t room_id,
    int error_code,
    const nim_chatroom::ChatRoomQueueElement& element) {
    nim_node::node_async_call::async_call([=]() {
        ChatRoomEventHandler::GetInstance()->Node_OnQueuePollCalback(
            bcb, room_id, error_code, element);
    });
}

void ChatRoomEventHandler::OnQueueListCallback(
    const BaseCallbackPtr& bcb,
    int64_t room_id,
    int error_code,
    const nim_chatroom::ChatRoomQueue& queue) {
    nim_node::node_async_call::async_call([=]() {
        ChatRoomEventHandler::GetInstance()->Node_OnQueueListCallback(
            bcb, room_id, error_code, queue);
    });
}

void ChatRoomEventHandler::OnQueueBatchUpdateCallback(
    const BaseCallbackPtr& bcb,
    int64_t room_id,
    int error_code,
    const std::list<std::string>& not_in_queue) {
    nim_node::node_async_call::async_call([=]() {
        ChatRoomEventHandler::GetInstance()->Node_OnQueueBatchUpdateCallback(
            bcb, room_id, error_code, not_in_queue);
    });
}

void ChatRoomEventHandler::Node_OnBaseCallback(const BaseCallbackPtr& bcb,
                                               int64_t room_id,
                                               int error_code) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    const unsigned argc = 2;
    Local<Value> argv[argc] = {nim_napi_new_int64(isolate, room_id),
                               nim_napi_new_int32(isolate, error_code)};
    bcb->callback_.Get(isolate)->Call(isolate->GetCurrentContext(),
                                      bcb->data_.Get(isolate), argc, argv);
}

void ChatRoomEventHandler::Node_OnEnterCallback(
    int64_t room_id,
    const nim_chatroom::NIMChatRoomEnterStep step,
    int error_code,
    const nim_chatroom::ChatRoomInfo& info,
    const nim_chatroom::ChatRoomMemberInfo& my_info) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    const unsigned argc = 5;
    Local<Object> room_info = Object::New(isolate);
    nim_chatroom_room_info_to_obj(isolate, info, room_info);
    Local<Object> my_info_obj = Object::New(isolate);
    nim_chatroom_my_info_to_obj(isolate, my_info, my_info_obj);
    Local<Value> argv[argc] = {
        nim_napi_new_int64(isolate, room_id), nim_napi_new_int32(isolate, step),
        nim_napi_new_int32(isolate, error_code), room_info, my_info_obj};
    auto it = callbacks_.find(kChatRoomEnterCallback);
    if (it != callbacks_.end()) {
        it->second->callback_.Get(isolate)->Call(isolate->GetCurrentContext(),
                                                 it->second->data_.Get(isolate),
                                                 argc, argv);
    }
}

void ChatRoomEventHandler::Node_OnExitCallback(
    int64_t room_id,
    int error_code,
    nim_chatroom::NIMChatRoomExitReason exit_reason) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    const unsigned argc = 3;
    Local<Value> argv[argc] = {nim_napi_new_int64(isolate, room_id),
                               nim_napi_new_int32(isolate, error_code),
                               nim_napi_new_int32(isolate, exit_reason)};
    auto it = callbacks_.find(kChatRoomExitCallback);
    if (it != callbacks_.end()) {
        it->second->callback_.Get(isolate)->Call(isolate->GetCurrentContext(),
                                                 it->second->data_.Get(isolate),
                                                 argc, argv);
    }
}

void ChatRoomEventHandler::Node_OnExitCallbackEx(
    int64_t room_id,
    int error_code,
    const nim_chatroom::NIMChatRoomExitReasonInfo& exit_info) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    const unsigned argc = 3;
    Local<Object> exit_reason_info_obj = Object::New(isolate);
    nim_chatroom_exit_reason_info_to_obj(isolate, exit_info,
                                         exit_reason_info_obj);
    Local<Value> argv[argc] = {nim_napi_new_int64(isolate, room_id),
                               nim_napi_new_int32(isolate, error_code),
                               exit_reason_info_obj};
    auto it = callbacks_.find(kChatRoomExitCallbackEx);
    if (it != callbacks_.end()) {
        it->second->callback_.Get(isolate)->Call(isolate->GetCurrentContext(),
                                                 it->second->data_.Get(isolate),
                                                 argc, argv);
    }
}

void ChatRoomEventHandler::Node_OnSendMsgAckCallback(
    int64_t room_id,
    int error_code,
    const nim_chatroom::ChatRoomMessage& result) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    const unsigned argc = 3;
    Local<Object> message = Object::New(isolate);
    nim_chatroom_room_message_to_obj(isolate, result, message);
    Local<Value> argv[argc] = {nim_napi_new_int64(isolate, room_id),
                               nim_napi_new_int32(isolate, error_code),
                               message};
    auto it = callbacks_.find(kChatRoomSendMsgAckCallback);
    if (it != callbacks_.end()) {
        it->second->callback_.Get(isolate)->Call(isolate->GetCurrentContext(),
                                                 it->second->data_.Get(isolate),
                                                 argc, argv);
    }
}

void ChatRoomEventHandler::Node_OnReceiveMsgCallback(
    int64_t room_id,
    const nim_chatroom::ChatRoomMessage& result) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    const unsigned argc = 2;
    Local<Object> message = Object::New(isolate);
    nim_chatroom_room_message_to_obj(isolate, result, message);
    Local<Value> argv[argc] = {nim_napi_new_int64(isolate, room_id), message};
    auto it = callbacks_.find(kChatRoomReceiveMsgCallback);
    if (it != callbacks_.end()) {
        it->second->callback_.Get(isolate)->Call(isolate->GetCurrentContext(),
                                                 it->second->data_.Get(isolate),
                                                 argc, argv);
    }
}

void ChatRoomEventHandler::Node_OnReceiveMsgsCallback(
    int64_t room_id,
    const std::list<nim_chatroom::ChatRoomMessage>& result) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    const unsigned argc = 2;
    Local<Array> message_array = Array::New(isolate, result.size());
    nim_chatroom_room_messages_to_array(isolate, result, message_array);
    Local<Value> argv[argc] = {nim_napi_new_int64(isolate, room_id),
                               message_array};
    auto it = callbacks_.find(kChatRoomReceiveMsgsCallback);
    if (it != callbacks_.end()) {
        it->second->callback_.Get(isolate)->Call(isolate->GetCurrentContext(),
                                                 it->second->data_.Get(isolate),
                                                 argc, argv);
    }
}

void ChatRoomEventHandler::Node_OnNotificationCallback(
    int64_t room_id,
    const nim_chatroom::ChatRoomNotification& notification) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    const unsigned argc = 2;
    Local<Object> notification_obj = Object::New(isolate);
    nim_chatroom_room_notification_to_obj(isolate, notification,
                                          notification_obj);
    Local<Value> argv[argc] = {nim_napi_new_int64(isolate, room_id),
                               notification_obj};
    auto it = callbacks_.find(kChatRoomNotificationCallback);
    if (it != callbacks_.end()) {
        it->second->callback_.Get(isolate)->Call(isolate->GetCurrentContext(),
                                                 it->second->data_.Get(isolate),
                                                 argc, argv);
    }
}

void ChatRoomEventHandler::Node_OnLinkConditionCallback(
    int64_t room_id,
    const nim_chatroom::NIMChatRoomLinkCondition condition) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    const unsigned argc = 2;
    Local<Value> argv[argc] = {nim_napi_new_int64(isolate, room_id),
                               nim_napi_new_int32(isolate, condition)};
    auto it = callbacks_.find(kChatRoomLinkConditionCallback);
    if (it != callbacks_.end()) {
        it->second->callback_.Get(isolate)->Call(isolate->GetCurrentContext(),
                                                 it->second->data_.Get(isolate),
                                                 argc, argv);
    }
}

void ChatRoomEventHandler::Node_OnGetMemberOnlineCallback(
    const BaseCallbackPtr& bcb,
    int64_t room_id,
    int error_code,
    const std::list<nim_chatroom::ChatRoomMemberInfo>& infos) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    const unsigned argc = 3;
    Local<Array> members = Array::New(isolate, infos.size());
    nim_chatroom_members_info_to_array(isolate, infos, members);
    Local<Value> argv[argc] = {nim_napi_new_int64(isolate, room_id),
                               nim_napi_new_int32(isolate, error_code),
                               members};
    bcb->callback_.Get(isolate)->Call(isolate->GetCurrentContext(),
                                      bcb->data_.Get(isolate), argc, argv);
}

void ChatRoomEventHandler::Node_OnGetMemberCountByTagCallback(
    const BaseCallbackPtr& bcb,
    int64_t room_id,
    int error_code,
    uint64_t count) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    const unsigned argc = 3;
    Local<Value> argv[argc] = {nim_napi_new_int64(isolate, room_id),
                               nim_napi_new_int32(isolate, error_code),
                               nim_napi_new_int64(isolate, count)};
    bcb->callback_.Get(isolate)->Call(isolate->GetCurrentContext(),
                                      bcb->data_.Get(isolate), argc, argv);
}

void ChatRoomEventHandler::Node_OnGetMsgHistoryOnlineCallback(
    const BaseCallbackPtr& bcb,
    int64_t room_id,
    int error_code,
    const std::list<nim_chatroom::ChatRoomMessage>& msgs) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    const unsigned argc = 3;
    Local<Array> messages = Array::New(isolate, msgs.size());
    nim_chatroom_room_messages_to_array(isolate, msgs, messages);
    Local<Value> argv[argc] = {nim_napi_new_int64(isolate, room_id),
                               nim_napi_new_int32(isolate, error_code),
                               messages};
    bcb->callback_.Get(isolate)->Call(isolate->GetCurrentContext(),
                                      bcb->data_.Get(isolate), argc, argv);
}

void ChatRoomEventHandler::Node_OnMemberInfoChangedCallback(
    const BaseCallbackPtr& bcb,
    int64_t room_id,
    int error_code,
    const nim_chatroom::ChatRoomMemberInfo& info) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    const unsigned argc = 3;

    Local<Object> member = Object::New(isolate);
    nim_chatroom_member_info_to_obj(isolate, info, member);

    Local<Value> argv[argc] = {nim_napi_new_int64(isolate, room_id),
                               nim_napi_new_int32(isolate, error_code), member};
    bcb->callback_.Get(isolate)->Call(isolate->GetCurrentContext(),
                                      bcb->data_.Get(isolate), argc, argv);
}

void ChatRoomEventHandler::Node_OnGetRoomInfoCallback(
    const BaseCallbackPtr& bcb,
    int64_t room_id,
    int error_code,
    const nim_chatroom::ChatRoomInfo& info) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    const unsigned argc = 3;

    Local<Object> info_obj = Object::New(isolate);
    nim_chatroom_room_info_to_obj(isolate, info, info_obj);

    Local<Value> argv[argc] = {nim_napi_new_int64(isolate, room_id),
                               nim_napi_new_int32(isolate, error_code),
                               info_obj};
    bcb->callback_.Get(isolate)->Call(isolate->GetCurrentContext(),
                                      bcb->data_.Get(isolate), argc, argv);
}

void ChatRoomEventHandler::Node_OnQueuePollCalback(
    const BaseCallbackPtr& bcb,
    int64_t room_id,
    int error_code,
    const nim_chatroom::ChatRoomQueueElement& element) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    const unsigned argc = 3;

    Local<Object> element_obj = Object::New(isolate);
    nim_chatroom_queue_element_info_to_obj(isolate, element, element_obj);

    Local<Value> argv[argc] = {nim_napi_new_int64(isolate, room_id),
                               nim_napi_new_int32(isolate, error_code),
                               element_obj};
    bcb->callback_.Get(isolate)->Call(isolate->GetCurrentContext(),
                                      bcb->data_.Get(isolate), argc, argv);
}

void ChatRoomEventHandler::Node_OnQueueListCallback(
    const BaseCallbackPtr& bcb,
    int64_t room_id,
    int error_code,
    const nim_chatroom::ChatRoomQueue& queue) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    const unsigned argc = 3;

    Local<Array> queue_array = Array::New(isolate, queue.size());
    nim_chatroom_queue_list_to_array(isolate, queue, queue_array);

    Local<Value> argv[argc] = {nim_napi_new_int64(isolate, room_id),
                               nim_napi_new_int32(isolate, error_code),
                               queue_array};
    bcb->callback_.Get(isolate)->Call(isolate->GetCurrentContext(),
                                      bcb->data_.Get(isolate), argc, argv);
}

void ChatRoomEventHandler::Node_OnQueueBatchUpdateCallback(
    const BaseCallbackPtr& bcb,
    int64_t room_id,
    int error_code,
    const std::list<std::string>& not_in_queue) {
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    const unsigned argc = 3;

    Local<Array> not_in_queue_array = Array::New(isolate, not_in_queue.size());
    uint32_t i = 0;
    for (auto& item : not_in_queue) {
        not_in_queue_array->Set(isolate->GetCurrentContext(), i++,
                                nim_napi_new_utf8string(isolate, item.c_str()));
    }

    Local<Value> argv[argc] = {nim_napi_new_int64(isolate, room_id),
                               nim_napi_new_int32(isolate, error_code),
                               not_in_queue_array};
    bcb->callback_.Get(isolate)->Call(isolate->GetCurrentContext(),
                                      bcb->data_.Get(isolate), argc, argv);
}

}  // namespace nim_chatroom_node
