#include "nim_chatroom_node.h"
#include <node_object_wrap.h>
#include <iostream>
#include "helper/nim_chatroom_node_helper.h"
#include "nim_chatroom_node_event_handler.h"

namespace nim_chatroom_node {

DEFINE_CLASS(ChatRoom);

ChatRoom::ChatRoom(Isolate* isolate) {
    isolate_ = isolate;
}

ChatRoom::~ChatRoom() {}

void ChatRoom::InitModule(Local<Object>& module) {
    BEGIN_OBJECT_INIT(ChatRoom, New, 5)

    SET_PROTOTYPE(Init)
    SET_PROTOTYPE(RegEnterCb)
    SET_PROTOTYPE(RegExitCb);
    SET_PROTOTYPE(RegExitCbEx);
    SET_PROTOTYPE(RegSendMsgAckCb);
    SET_PROTOTYPE(RegReceiveMsgCb);
    SET_PROTOTYPE(RegReceiveMsgsCb);
    SET_PROTOTYPE(RegNotificationCb);
    SET_PROTOTYPE(RegLinkConditionCb);
    SET_PROTOTYPE(IndependentEnter);
    SET_PROTOTYPE(IndependentEnterEx)
    SET_PROTOTYPE(AnonymousEnter)
    SET_PROTOTYPE(AnonymousEnterEx)
    SET_PROTOTYPE(Enter)
    SET_PROTOTYPE(GetLoginState)
    SET_PROTOTYPE(SetMsgsBatchReport)
    SET_PROTOTYPE(SendMsg)
    SET_PROTOTYPE(GetMembersOnlineAsync)
    SET_PROTOTYPE(GetMembersByTagOnlineAsync);
    SET_PROTOTYPE(GetMembersCountByTagOnlineAsync);
    SET_PROTOTYPE(GetMessageHistoryOnlineAsync);
    SET_PROTOTYPE(SetMemberAttributeOnlineAsync);
    SET_PROTOTYPE(GetInfoAsync);
    SET_PROTOTYPE(GetMemberInfoByIDsAsync);
    SET_PROTOTYPE(KickMemberAsync);
    SET_PROTOTYPE(SetProxy);
    SET_PROTOTYPE(TempMuteMemberAsync);
    SET_PROTOTYPE(TempMuteMemberByTagAsync);
    SET_PROTOTYPE(UpdateRoomInfoAsync);
    SET_PROTOTYPE(UpdateMyRoomRoleAsync);
    SET_PROTOTYPE(QueueOfferAsync);
    SET_PROTOTYPE(QueuePollAsync);
    SET_PROTOTYPE(QueueListAsync);
    SET_PROTOTYPE(QueueHeaderAsync);
    SET_PROTOTYPE(QueueDropAsync);
    SET_PROTOTYPE(UnregChatroomCb);
    SET_PROTOTYPE(QueueBatchUpdateAsync);
    SET_PROTOTYPE(Exit)
    SET_PROTOTYPE(CleanUp)

    END_OBJECT_INIT(ChatRoom)
}

void ChatRoom::New(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    if (args.IsConstructCall()) {
        ChatRoom* chatroom = new ChatRoom(isolate);
        chatroom->Wrap(args.This());
        args.GetReturnValue().Set(args.This());
    } else {
        Local<Function> cons = Local<Function>::New(isolate, constructor);
        Local<Context> context = isolate->GetCurrentContext();
        Local<Object> instance = cons->NewInstance(context).ToLocalChecked();
        args.GetReturnValue().Set(instance);
    }
}

NIM_SDK_NODE_API_DEF(ChatRoom, Init) {
    CHECK_API_FUNC(ChatRoom, 1)
    UTF8String app_install_path;
    auto status = napi_ok;
    GET_ARGS_VALUE(isolate, 0, UTF8String, app_install_path)
    bool ret = nim_chatroom::ChatRoom::Init(app_install_path.toUtf8String());
    args.GetReturnValue().Set(Integer::New(args.GetIsolate(), ret ? 1 : 0));
}

NIM_SDK_NODE_API_DEF(ChatRoom, RegEnterCb) {
    CHECK_API_FUNC(ChatRoom, 2)
    UTF8String exten;
    ASSEMBLE_REG_CALLBACK(0, ChatRoomEventHandler, kChatRoomEnterCallback)
    auto status = napi_ok;
    GET_ARGS_VALUE(isolate, 1, utf8string, exten)
    auto callback =
        std::bind(&ChatRoomEventHandler::OnEnterCallback, std::placeholders::_1,
                  std::placeholders::_2, std::placeholders::_3,
                  std::placeholders::_4, std::placeholders::_5);
    nim_chatroom::ChatRoom::RegEnterCb(callback, exten.toUtf8String());
}

NIM_SDK_NODE_API_DEF(ChatRoom, RegExitCb) {
    CHECK_API_FUNC(ChatRoom, 2)
    UTF8String exten;
    ASSEMBLE_REG_CALLBACK(0, ChatRoomEventHandler, kChatRoomExitCallback)
    auto status = napi_ok;
    GET_ARGS_VALUE(isolate, 1, utf8string, exten)
    auto callback =
        std::bind(&ChatRoomEventHandler::OnExitCallback, std::placeholders::_1,
                  std::placeholders::_2, std::placeholders::_3);
    nim_chatroom::ChatRoom::RegExitCb(callback, exten.toUtf8String());
}

NIM_SDK_NODE_API_DEF(ChatRoom, RegExitCbEx) {
    CHECK_API_FUNC(ChatRoom, 2)
    UTF8String exten;
    ASSEMBLE_REG_CALLBACK(0, ChatRoomEventHandler, kChatRoomExitCallbackEx)
    auto status = napi_ok;
    GET_ARGS_VALUE(isolate, 1, utf8string, exten)
    auto callback = std::bind(&ChatRoomEventHandler::OnExitCallbackEx,
                              std::placeholders::_1, std::placeholders::_2,
                              std::placeholders::_3);
    nim_chatroom::ChatRoom::RegExitCb_2(callback, exten.toUtf8String());
}

NIM_SDK_NODE_API_DEF(ChatRoom, RegSendMsgAckCb) {
    CHECK_API_FUNC(ChatRoom, 2)
    UTF8String exten;
    ASSEMBLE_REG_CALLBACK(0, ChatRoomEventHandler, kChatRoomSendMsgAckCallback)
    auto status = napi_ok;
    GET_ARGS_VALUE(isolate, 1, utf8string, exten)
    auto callback = std::bind(&ChatRoomEventHandler::OnSendMsgAckCallback,
                              std::placeholders::_1, std::placeholders::_2,
                              std::placeholders::_3);
    nim_chatroom::ChatRoom::RegSendMsgAckCb(callback, exten.toUtf8String());
}

NIM_SDK_NODE_API_DEF(ChatRoom, RegReceiveMsgCb) {
    CHECK_API_FUNC(ChatRoom, 2)
    UTF8String exten;
    ASSEMBLE_REG_CALLBACK(0, ChatRoomEventHandler, kChatRoomReceiveMsgCallback)
    auto status = napi_ok;
    GET_ARGS_VALUE(isolate, 1, utf8string, exten)
    auto callback = std::bind(&ChatRoomEventHandler::OnReceiveMsgCallback,
                              std::placeholders::_1, std::placeholders::_2);
    nim_chatroom::ChatRoom::RegReceiveMsgCb(callback, exten.toUtf8String());
}

NIM_SDK_NODE_API_DEF(ChatRoom, RegReceiveMsgsCb) {
    CHECK_API_FUNC(ChatRoom, 2)
    UTF8String exten;
    ASSEMBLE_REG_CALLBACK(0, ChatRoomEventHandler, kChatRoomReceiveMsgsCallback)
    auto status = napi_ok;
    GET_ARGS_VALUE(isolate, 1, utf8string, exten)
    auto callback = std::bind(&ChatRoomEventHandler::OnReceiveMsgsCallback,
                              std::placeholders::_1, std::placeholders::_2);
    nim_chatroom::ChatRoom::RegReceiveMsgsCb(callback, exten.toUtf8String());
}

NIM_SDK_NODE_API_DEF(ChatRoom, RegNotificationCb) {
    CHECK_API_FUNC(ChatRoom, 2)
    UTF8String exten;
    ASSEMBLE_REG_CALLBACK(0, ChatRoomEventHandler,
                          kChatRoomNotificationCallback)
    auto status = napi_ok;
    GET_ARGS_VALUE(isolate, 1, utf8string, exten)
    auto callback = std::bind(&ChatRoomEventHandler::OnNotificationCallback,
                              std::placeholders::_1, std::placeholders::_2);
    nim_chatroom::ChatRoom::RegNotificationCb(callback, exten.toUtf8String());
}

NIM_SDK_NODE_API_DEF(ChatRoom, RegLinkConditionCb) {
    CHECK_API_FUNC(ChatRoom, 2)
    UTF8String exten;
    ASSEMBLE_REG_CALLBACK(0, ChatRoomEventHandler,
                          kChatRoomLinkConditionCallback)
    auto status = napi_ok;
    GET_ARGS_VALUE(isolate, 1, utf8string, exten)
    auto callback = std::bind(&ChatRoomEventHandler::OnLinkConditionCallback,
                              std::placeholders::_1, std::placeholders::_2);
    nim_chatroom::ChatRoom::RegLinkConditionCb(callback, exten.toUtf8String());
}

NIM_SDK_NODE_API_DEF(ChatRoom, IndependentEnter) {
    CHECK_API_FUNC(ChatRoom, 2)
    int64_t room_id;
    auto status = napi_ok;
    GET_ARGS_VALUE(isolate, 0, int64, room_id)
    nim_chatroom::ChatRoomIndependentEnterInfo info;
    status = nim_chatroom_independent_enter_info_obj_to_struct(
        isolate,
        args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked(), info);
    bool result = nim_chatroom::ChatRoom::IndependentEnter(room_id, info);
    args.GetReturnValue().Set(Boolean::New(args.GetIsolate(), result));
}

NIM_SDK_NODE_API_DEF(ChatRoom, IndependentEnterEx) {
    CHECK_API_FUNC(ChatRoom, 3)
    int64_t room_id;
    UTF8String utf8getter;
    auto status = napi_ok;
    GET_ARGS_VALUE(isolate, 0, int64, room_id)
    nim_chatroom::ChatRoomIndependentEnterInfo info;
    status = nim_chatroom_independent_enter_info_obj_to_struct(
        isolate,
        args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked(), info);
    GET_ARGS_VALUE(isolate, 2, utf8string, utf8getter)
    nim_chatroom::NIMChatRoomConfigGetter getter =
        const_cast<nim_chatroom::NIMChatRoomConfigGetter>(
            utf8getter.toUtf8String().c_str());
    bool result =
        nim_chatroom::ChatRoom::IndependentEnter2(room_id, info, getter);
    args.GetReturnValue().Set(Boolean::New(args.GetIsolate(), result));
}

NIM_SDK_NODE_API_DEF(ChatRoom, AnonymousEnter) {
    CHECK_API_FUNC(ChatRoom, 4)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id)
    nim_chatroom::ChatRoomAnoymityEnterInfo anoymity_enter_info;
    nim_chatroom_anoymity_enter_info_obj_to_struct(
        isolate,
        args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked(),
        anoymity_enter_info);
    nim_chatroom::ChatRoomEnterInfo enter_info;
    nim_chatroom_enter_info_obj_to_struct(
        isolate,
        args[2]->ToObject(isolate->GetCurrentContext()).ToLocalChecked(),
        enter_info);
    UTF8String ext;
    GET_ARGS_VALUE(isolate, 3, utf8string, ext)
    bool result = nim_chatroom::ChatRoom::AnonymousEnter(
        room_id, anoymity_enter_info, enter_info, ext.toUtf8String());
    args.GetReturnValue().Set(Boolean::New(args.GetIsolate(), result));
}

NIM_SDK_NODE_API_DEF(ChatRoom, AnonymousEnterEx) {
    CHECK_API_FUNC(ChatRoom, 4)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id)
    nim_chatroom::ChatRoomAnoymityEnterInfo anoymity_enter_info;
    nim_chatroom_anoymity_enter_info_obj_to_struct(
        isolate,
        args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked(),
        anoymity_enter_info);
    nim_chatroom::ChatRoomEnterInfo enter_info;
    nim_chatroom_enter_info_obj_to_struct(
        isolate,
        args[2]->ToObject(isolate->GetCurrentContext()).ToLocalChecked(),
        enter_info);
    UTF8String utf8getter;
    GET_ARGS_VALUE(isolate, 3, utf8string, utf8getter)
    nim_chatroom::NIMChatRoomConfigGetter getter =
        const_cast<nim_chatroom::NIMChatRoomConfigGetter>(
            utf8getter.toUtf8String().c_str());
    bool result = nim_chatroom::ChatRoom::AnonymousEnter2(
        room_id, anoymity_enter_info, enter_info, getter);
    args.GetReturnValue().Set(Boolean::New(args.GetIsolate(), result));
}

NIM_SDK_NODE_API_DEF(ChatRoom, Enter) {
    CHECK_API_FUNC(ChatRoom, 4)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id)
    UTF8String login_token;
    GET_ARGS_VALUE(isolate, 1, utf8string, login_token)
    nim_chatroom::ChatRoomEnterInfo enter_info;
    nim_chatroom_enter_info_obj_to_struct(
        isolate,
        args[2]->ToObject(isolate->GetCurrentContext()).ToLocalChecked(),
        enter_info);
    UTF8String ext;
    GET_ARGS_VALUE(isolate, 3, utf8string, ext)
    bool result = nim_chatroom::ChatRoom::Enter(
        room_id, login_token.toUtf8String(), enter_info, ext.toUtf8String());
    args.GetReturnValue().Set(Boolean::New(args.GetIsolate(), result));
}

NIM_SDK_NODE_API_DEF(ChatRoom, GetLoginState) {
    CHECK_API_FUNC(ChatRoom, 2)
    auto status = napi_ok;
    int64_t room_id;
    UTF8String ext;
    GET_ARGS_VALUE(isolate, 0, int64, room_id)
    GET_ARGS_VALUE(isolate, 1, utf8string, ext)
    auto result =
        nim_chatroom::ChatRoom::GetLoginState(room_id, ext.toUtf8String());
    args.GetReturnValue().Set(nim_napi_new_int32(args.GetIsolate(), result));
}

NIM_SDK_NODE_API_DEF(ChatRoom, SetMsgsBatchReport) {
    CHECK_API_FUNC(ChatRoom, 2)
    auto status = napi_ok;
    bool batch;
    UTF8String ext;
    GET_ARGS_VALUE(isolate, 0, bool, batch)
    GET_ARGS_VALUE(isolate, 1, utf8string, ext)
    nim_chatroom::ChatRoom::SetMsgsBatchReport(batch, ext.toUtf8String());
}

NIM_SDK_NODE_API_DEF(ChatRoom, SendMsg) {
    CHECK_API_FUNC(ChatRoom, 3)
    auto status = napi_ok;
    int64_t room_id;
    UTF8String ext;
    GET_ARGS_VALUE(isolate, 0, int64, room_id)

    auto object =
        args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();
    auto stringify = v8::JSON::Stringify(isolate->GetCurrentContext(), object);
    UTF8String msg;
    nim_napi_get_value_utf8string(isolate, stringify.ToLocalChecked(), msg);

    GET_ARGS_VALUE(isolate, 2, utf8string, ext);

    nim_chatroom::ChatRoom::SendMsg(room_id, msg.toUtf8String(),
                                    ext.toUtf8String());
}

NIM_SDK_NODE_API_DEF(ChatRoom, GetMembersOnlineAsync) {
    CHECK_API_FUNC(ChatRoom, 4)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id)

    nim_chatroom::ChatRoomGetMembersParameters params;
    nim_chatroom_get_member_params_obj_to_struct(
        isolate,
        args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked(),
        params);

    ASSEMBLE_BASE_CALLBACK(2);
    auto callback = std::bind(&ChatRoomEventHandler::OnGetMemberOnlineCallback,
                              bcb, std::placeholders::_1, std::placeholders::_2,
                              std::placeholders::_3);

    UTF8String ext;
    GET_ARGS_VALUE(isolate, 3, utf8string, ext);

    nim_chatroom::ChatRoom::GetMembersOnlineAsync(room_id, params, callback,
                                                  ext.toUtf8String());
}

NIM_SDK_NODE_API_DEF(ChatRoom, GetMembersByTagOnlineAsync) {
    CHECK_API_FUNC(ChatRoom, 4)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id)

    nim_chatroom::ChatRoomGetMembersByTagParameters params;
    nim_chatroom_get_member_by_tag_params_obj_to_struct(
        isolate,
        args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked(),
        params);

    ASSEMBLE_BASE_CALLBACK(2);
    auto callback = std::bind(&ChatRoomEventHandler::OnGetMemberOnlineCallback,
                              bcb, std::placeholders::_1, std::placeholders::_2,
                              std::placeholders::_3);

    UTF8String ext;
    GET_ARGS_VALUE(isolate, 3, utf8string, ext);

    nim_chatroom::ChatRoom::GetMembersByTagOnlineAsync(
        room_id, params, callback, ext.toUtf8String());
}

NIM_SDK_NODE_API_DEF(ChatRoom, GetMembersCountByTagOnlineAsync) {
    CHECK_API_FUNC(ChatRoom, 4)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id);

    UTF8String tag;
    GET_ARGS_VALUE(isolate, 1, UTF8String, tag);

    ASSEMBLE_BASE_CALLBACK(2);
    auto callback = std::bind(
        &ChatRoomEventHandler::OnGetMemberCountByTagCallback, bcb,
        std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);

    UTF8String ext;
    GET_ARGS_VALUE(isolate, 3, utf8string, ext);

    nim_chatroom::ChatRoom::GetMembersCountByTagOnlineAsync(
        room_id, tag.toUtf8String(), callback, ext.toUtf8String());
}

NIM_SDK_NODE_API_DEF(ChatRoom, GetMessageHistoryOnlineAsync) {
    CHECK_API_FUNC(ChatRoom, 4)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id);

    nim_chatroom::ChatRoomGetMsgHistoryParameters params;
    params.msg_types_.clear();
    nim_chatroom_get_message_history_params_obj_to_struct(
        isolate,
        args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked(),
        params);

    ASSEMBLE_BASE_CALLBACK(2);
    auto callback = std::bind(
        &ChatRoomEventHandler::OnGetMsgHistoryOnlineCallback, bcb,
        std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);

    UTF8String ext;
    GET_ARGS_VALUE(isolate, 3, utf8string, ext);

    nim_chatroom::ChatRoom::GetMessageHistoryOnlineAsync(
        room_id, params, callback, ext.toUtf8String());
}

NIM_SDK_NODE_API_DEF(ChatRoom, SetMemberAttributeOnlineAsync) {
    CHECK_API_FUNC(ChatRoom, 4)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id);

    nim_chatroom::ChatRoomSetMemberAttributeParameters params;
    nim_chatroom_set_member_attribute_params_obj_to_struct(
        isolate,
        args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked(),
        params);

    ASSEMBLE_BASE_CALLBACK(2);
    auto callback = std::bind(
        &ChatRoomEventHandler::OnMemberInfoChangedCallback, bcb,
        std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);

    UTF8String ext;
    GET_ARGS_VALUE(isolate, 3, utf8string, ext);

    nim_chatroom::ChatRoom::SetMemberAttributeOnlineAsync(
        room_id, params, callback, ext.toUtf8String());
}

NIM_SDK_NODE_API_DEF(ChatRoom, GetInfoAsync) {
    CHECK_API_FUNC(ChatRoom, 3)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id);

    ASSEMBLE_BASE_CALLBACK(1);
    auto callback = std::bind(&ChatRoomEventHandler::OnGetRoomInfoCallback, bcb,
                              std::placeholders::_1, std::placeholders::_2,
                              std::placeholders::_3);

    UTF8String ext;
    GET_ARGS_VALUE(isolate, 2, utf8string, ext);

    nim_chatroom::ChatRoom::GetInfoAsync(room_id, callback, ext.toUtf8String());
}

NIM_SDK_NODE_API_DEF(ChatRoom, GetMemberInfoByIDsAsync) {
    CHECK_API_FUNC(ChatRoom, 4)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id);
    std::list<std::string> ids;
    nim_napi_get_value_utf8string_list(
        isolate,
        args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked(), ids);

    ASSEMBLE_BASE_CALLBACK(2);
    auto callback = std::bind(&ChatRoomEventHandler::OnGetMemberOnlineCallback,
                              bcb, std::placeholders::_1, std::placeholders::_2,
                              std::placeholders::_3);

    UTF8String ext;
    GET_ARGS_VALUE(isolate, 3, utf8string, ext);

    nim_chatroom::ChatRoom::GetMemberInfoByIDsAsync(room_id, ids, callback,
                                                    ext.toUtf8String());
}
NIM_SDK_NODE_API_DEF(ChatRoom, KickMemberAsync) {
    CHECK_API_FUNC(ChatRoom, 5)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id);

    UTF8String id;
    GET_ARGS_VALUE(isolate, 1, utf8string, id);

    UTF8String notify_ext;
    GET_ARGS_VALUE(isolate, 2, utf8string, notify_ext);

    ASSEMBLE_BASE_CALLBACK(3);
    auto callback = std::bind(&ChatRoomEventHandler::OnBaseCallback, bcb,
                              std::placeholders::_1, std::placeholders::_2);

    UTF8String ext;
    GET_ARGS_VALUE(isolate, 4, utf8string, ext);

    nim_chatroom::ChatRoom::KickMemberAsync(room_id, id.toUtf8String(),
                                            notify_ext.toUtf8String(), callback,
                                            ext.toUtf8String());
}
NIM_SDK_NODE_API_DEF(ChatRoom, SetProxy) {
    CHECK_API_FUNC(ChatRoom, 5)
    auto status = napi_ok;
    int32_t type;
    GET_ARGS_VALUE(isolate, 0, int32, type);

    UTF8String host;
    GET_ARGS_VALUE(isolate, 1, utf8string, host);

    int32_t port;
    GET_ARGS_VALUE(isolate, 2, int32, port);

    UTF8String user;
    GET_ARGS_VALUE(isolate, 3, utf8string, user);

    UTF8String password;
    GET_ARGS_VALUE(isolate, 4, utf8string, password);

    nim_chatroom::ChatRoom::SetProxy(
        static_cast<nim_chatroom::NIMChatRoomProxyType>(type),
        host.toUtf8String(), port, user.toUtf8String(),
        password.toUtf8String());
}
NIM_SDK_NODE_API_DEF(ChatRoom, TempMuteMemberAsync) {
    CHECK_API_FUNC(ChatRoom, 7)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id);

    UTF8String accid;
    GET_ARGS_VALUE(isolate, 1, utf8string, accid);

    int64_t duration;
    GET_ARGS_VALUE(isolate, 2, int64, duration);

    bool need_notify;
    GET_ARGS_VALUE(isolate, 3, bool, need_notify);

    UTF8String notify_ext;
    GET_ARGS_VALUE(isolate, 4, utf8string, notify_ext);

    ASSEMBLE_BASE_CALLBACK(5);
    auto callback = std::bind(
        &ChatRoomEventHandler::OnMemberInfoChangedCallback, bcb,
        std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);

    UTF8String ext;
    GET_ARGS_VALUE(isolate, 6, utf8string, ext);

    nim_chatroom::ChatRoom::TempMuteMemberAsync(
        room_id, accid.toUtf8String(), duration, need_notify,
        notify_ext.toUtf8String(), callback, ext.toUtf8String());
}
NIM_SDK_NODE_API_DEF(ChatRoom, TempMuteMemberByTagAsync) {
    CHECK_API_FUNC(ChatRoom, 7)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id);

    UTF8String target_tag;
    GET_ARGS_VALUE(isolate, 1, utf8string, target_tag);

    int64_t duration;
    GET_ARGS_VALUE(isolate, 2, int64, duration);

    bool need_notify;
    GET_ARGS_VALUE(isolate, 3, bool, need_notify);

    UTF8String notify_ext;
    GET_ARGS_VALUE(isolate, 4, utf8string, notify_ext);

    ASSEMBLE_BASE_CALLBACK(5);
    auto callback = std::bind(
        &ChatRoomEventHandler::OnMemberInfoChangedCallback, bcb,
        std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);

    UTF8String ext;
    GET_ARGS_VALUE(isolate, 6, utf8string, ext);

    nim_chatroom::ChatRoom::TempMuteMemberByTagAsync(
        room_id, target_tag.toUtf8String(), duration, need_notify,
        notify_ext.toUtf8String(), callback, ext.toUtf8String());
}
NIM_SDK_NODE_API_DEF(ChatRoom, UpdateRoomInfoAsync) {
    CHECK_API_FUNC(ChatRoom, 6)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id);

    nim_chatroom::ChatRoomInfo info;
    nim_chatroom_room_info_obj_to_struct(
        isolate,
        args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked(), info);

    bool need_notify;
    GET_ARGS_VALUE(isolate, 2, bool, need_notify);

    UTF8String notify_ext;
    GET_ARGS_VALUE(isolate, 3, utf8string, notify_ext);

    ASSEMBLE_BASE_CALLBACK(4);
    auto callback = std::bind(&ChatRoomEventHandler::OnBaseCallback, bcb,
                              std::placeholders::_1, std::placeholders::_2);

    UTF8String ext;
    GET_ARGS_VALUE(isolate, 5, utf8string, ext);

    nim_chatroom::ChatRoom::UpdateRoomInfoAsync(room_id, info, need_notify,
                                                notify_ext.toUtf8String(),
                                                callback, ext.toUtf8String());
}
NIM_SDK_NODE_API_DEF(ChatRoom, UpdateMyRoomRoleAsync) {
    CHECK_API_FUNC(ChatRoom, 6)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id);

    nim_chatroom::ChatRoomMemberInfo info;
    nim_chatroom_member_info_obj_to_struct(
        isolate,
        args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked(), info);

    bool need_notify;
    GET_ARGS_VALUE(isolate, 2, bool, need_notify);

    UTF8String notify_ext;
    GET_ARGS_VALUE(isolate, 3, utf8string, notify_ext);

    ASSEMBLE_BASE_CALLBACK(4);
    auto callback = std::bind(&ChatRoomEventHandler::OnBaseCallback, bcb,
                              std::placeholders::_1, std::placeholders::_2);

    UTF8String ext;
    GET_ARGS_VALUE(isolate, 5, utf8string, ext);

    nim_chatroom::ChatRoom::UpdateMyRoomRoleAsync(room_id, info, need_notify,
                                                  notify_ext.toUtf8String(),
                                                  callback, ext.toUtf8String());
}
NIM_SDK_NODE_API_DEF(ChatRoom, QueueOfferAsync) {
    CHECK_API_FUNC(ChatRoom, 4)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id);

    nim_chatroom::ChatRoomQueueElement element;
    nim_chatroom_queue_element_obj_to_struct(
        isolate,
        args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked(),
        element);

    ASSEMBLE_BASE_CALLBACK(2);
    auto callback = std::bind(&ChatRoomEventHandler::OnBaseCallback, bcb,
                              std::placeholders::_1, std::placeholders::_2);

    UTF8String ext;
    GET_ARGS_VALUE(isolate, 3, utf8string, ext);

    nim_chatroom::ChatRoom::QueueOfferAsync(room_id, element, callback,
                                            ext.toUtf8String());
}
NIM_SDK_NODE_API_DEF(ChatRoom, QueuePollAsync) {
    CHECK_API_FUNC(ChatRoom, 4)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id);

    UTF8String element_key;
    GET_ARGS_VALUE(isolate, 1, UTF8String, element_key);

    ASSEMBLE_BASE_CALLBACK(2);
    auto callback = std::bind(&ChatRoomEventHandler::OnQueuePollCalback, bcb,
                              std::placeholders::_1, std::placeholders::_2,
                              std::placeholders::_3);

    UTF8String ext;
    GET_ARGS_VALUE(isolate, 3, utf8string, ext);

    nim_chatroom::ChatRoom::QueuePollAsync(room_id, element_key.toUtf8String(),
                                           callback, ext.toUtf8String());
}
NIM_SDK_NODE_API_DEF(ChatRoom, QueueListAsync) {
    CHECK_API_FUNC(ChatRoom, 3)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id);

    ASSEMBLE_BASE_CALLBACK(1);
    auto callback = std::bind(&ChatRoomEventHandler::OnQueueListCallback, bcb,
                              std::placeholders::_1, std::placeholders::_2,
                              std::placeholders::_3);

    UTF8String ext;
    GET_ARGS_VALUE(isolate, 2, utf8string, ext);

    nim_chatroom::ChatRoom::QueueListAsync(room_id, callback,
                                           ext.toUtf8String());
}
NIM_SDK_NODE_API_DEF(ChatRoom, QueueHeaderAsync) {
    CHECK_API_FUNC(ChatRoom, 3)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id);

    ASSEMBLE_BASE_CALLBACK(1);
    auto callback = std::bind(&ChatRoomEventHandler::OnQueuePollCalback, bcb,
                              std::placeholders::_1, std::placeholders::_2,
                              std::placeholders::_3);

    UTF8String ext;
    GET_ARGS_VALUE(isolate, 2, utf8string, ext);

    nim_chatroom::ChatRoom::QueueHeaderAsync(room_id, callback,
                                             ext.toUtf8String());
}
NIM_SDK_NODE_API_DEF(ChatRoom, QueueDropAsync) {
    CHECK_API_FUNC(ChatRoom, 3)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id);

    ASSEMBLE_BASE_CALLBACK(1);
    auto callback = std::bind(&ChatRoomEventHandler::OnBaseCallback, bcb,
                              std::placeholders::_1, std::placeholders::_2);

    UTF8String ext;
    GET_ARGS_VALUE(isolate, 2, utf8string, ext);

    nim_chatroom::ChatRoom::QueueDropAsync(room_id, callback,
                                           ext.toUtf8String());
}
NIM_SDK_NODE_API_DEF(ChatRoom, UnregChatroomCb) {
    CHECK_API_FUNC(ChatRoom, 0)
    ChatRoomEventHandler::GetInstance()->RemoveAllEventhandler();
    nim_chatroom::ChatRoom::UnregChatroomCb();
}

NIM_SDK_NODE_API_DEF(ChatRoom, QueueBatchUpdateAsync) {
    CHECK_API_FUNC(ChatRoom, 6)
    auto status = napi_ok;
    int64_t room_id;
    GET_ARGS_VALUE(isolate, 0, int64, room_id);

    nim_chatroom::ChatRoomBatchMembers barch_elements;
    nim_chatroom_queue_batch_member_array_to_list(
        isolate,
        args[1]->ToObject(isolate->GetCurrentContext()).ToLocalChecked(),
        barch_elements);

    bool need_notify;
    GET_ARGS_VALUE(isolate, 2, bool, need_notify);

    UTF8String notify_ext;
    GET_ARGS_VALUE(isolate, 3, utf8string, notify_ext);

    ASSEMBLE_BASE_CALLBACK(4);
    auto callback = std::bind(&ChatRoomEventHandler::OnQueueBatchUpdateCallback,
                              bcb, std::placeholders::_1, std::placeholders::_2,
                              std::placeholders::_3);

    UTF8String ext;
    GET_ARGS_VALUE(isolate, 5, utf8string, ext);

    nim_chatroom::ChatRoom::QueueBatchUpdateAsync(
        room_id, barch_elements, need_notify, notify_ext.toUtf8String(),
        callback, ext.toUtf8String());
}

NIM_SDK_NODE_API_DEF(ChatRoom, Exit) {
    CHECK_API_FUNC(ChatRoom, 2)
    auto status = napi_ok;
    int64_t room_id;
    UTF8String ext;
    GET_ARGS_VALUE(isolate, 0, int64, room_id)
    GET_ARGS_VALUE(isolate, 1, utf8string, ext)
    nim_chatroom::ChatRoom::Exit(room_id, ext.toUtf8String());
}

NIM_SDK_NODE_API_DEF(ChatRoom, CleanUp) {
    CHECK_API_FUNC(ChatRoom, 1)

    UTF8String ext;
    auto status = napi_ok;
    GET_ARGS_VALUE(isolate, 0, UTF8String, ext)

    nim_chatroom::ChatRoom::Cleanup(ext.toUtf8String());
}

}  // namespace nim_chatroom_node
