/**
 * @file nim_chatroom_node_helper.h
 * @author Dylan
 * @brief NIM chatroom node plugin helpers
 * @version 0.1
 * @date 2021-05-08
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef NIM_CHATROOM_SDK_NODE_HELPER_NIM_CHATROOM_NODE_HELPER_H_
#define NIM_CHATROOM_SDK_NODE_HELPER_NIM_CHATROOM_NODE_HELPER_H_

#include <node.h>
#include <node_api.h>
#include <list>
#include "nim_chatroom_cpp_wrapper/helper/nim_chatroom_helper.h"

using v8::Array;
using v8::Context;
using v8::Exception;
using v8::Integer;
using v8::Isolate;
using v8::Local;
using v8::NewStringType;
using v8::Object;
using v8::String;
using v8::Value;

namespace nim_chatroom_node {

napi_status nim_chatroom_room_info_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomInfo& info);

napi_status nim_chatroom_independent_enter_info_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomIndependentEnterInfo& info);

napi_status nim_chatroom_independent_enter_info_to_obj(
    Isolate* isolate,
    const nim_chatroom::ChatRoomIndependentEnterInfo& config,
    Local<Object>& obj);

napi_status nim_chatroom_enter_info_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomEnterInfo& enter_info);

napi_status nim_chatroom_anoymity_enter_info_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomAnoymityEnterInfo& config);

napi_status nim_chatroom_room_info_to_obj(
    Isolate* isolate,
    const nim_chatroom::ChatRoomInfo& info,
    Local<Object>& obj);

napi_status nim_chatroom_my_info_to_obj(
    Isolate* isolate,
    const nim_chatroom::ChatRoomMemberInfo& my_info,
    Local<Object>& obj);

napi_status nim_chatroom_exit_reason_info_to_obj(
    Isolate* isolate,
    const nim_chatroom::NIMChatRoomExitReasonInfo& exit_reason_info,
    Local<Object>& obj);

napi_status nim_chatroom_msg_settings_to_obj(
    Isolate* isolate,
    const nim_chatroom::ChatRoomMessageSetting& msg_settings,
    Local<Object>& obj);

napi_status nim_chatroom_room_message_to_obj(
    Isolate* isolate,
    const nim_chatroom::ChatRoomMessage& message,
    Local<Object>& obj);

napi_status nim_chatroom_room_messages_to_array(
    Isolate* isolate,
    const std::list<nim_chatroom::ChatRoomMessage>& messages,
    Local<Array>& array);

napi_status nim_chatroom_get_member_params_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomGetMembersParameters& get_member_parameters);

napi_status nim_chatroom_get_member_by_tag_params_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomGetMembersByTagParameters& get_member_parameters);

napi_status nim_chatroom_room_notification_to_obj(
    Isolate* isolate,
    const nim_chatroom::ChatRoomNotification& notification,
    Local<Object>& obj);

napi_status nim_chatroom_room_notifications_to_array(
    Isolate* isolate,
    const std::list<nim_chatroom::ChatRoomNotification>& notifications,
    Local<Array>& array);

napi_status nim_chatroom_member_info_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomMemberInfo& member_info);

napi_status nim_chatroom_member_info_to_obj(
    Isolate* isolate,
    const nim_chatroom::ChatRoomMemberInfo& member,
    Local<Object>& obj);

napi_status nim_chatroom_members_info_to_array(
    Isolate* isolate,
    const std::list<nim_chatroom::ChatRoomMemberInfo>& members,
    Local<Array>& array);

napi_status nim_chatroom_get_message_history_params_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomGetMsgHistoryParameters& get_history_parameters);

napi_status nim_chatroom_set_member_attribute_params_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomSetMemberAttributeParameters&
        set_attribute_parameters);

napi_status nim_chatroom_queue_element_info_to_obj(
    Isolate* isolate,
    const nim_chatroom::ChatRoomQueueElement& element,
    Local<Object>& obj);

napi_status nim_chatroom_queue_element_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomQueueElement& element);

napi_status nim_chatroom_queue_list_to_array(
    Isolate* isolate,
    const nim_chatroom::ChatRoomQueue& queue,
    Local<Array>& array);

napi_status nim_chatroom_queue_batch_member_array_to_list(
    Isolate* isolate,
    const Local<Object>& array,
    nim_chatroom::ChatRoomBatchMembers& batch_elements);

}  // namespace nim_chatroom_node

#endif  // NIM_CHATROOM_SDK_NODE_HELPER_NIM_CHATROOM_NODE_HELPER_H_
