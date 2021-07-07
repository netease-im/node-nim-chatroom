#include "nim_chatroom_node_helper.h"
#include "nim_node_helper.h"

namespace nim_chatroom_node {

napi_status nim_chatroom_room_info_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomInfo& info) {
    UTF8String out;
    int32_t out_i;
    int64_t out_i64;
    bool out_b = false;
    std::list<utf8_string> out_list;
    Local<Value> out_v;

    if (nim_napi_get_object_value_int64(isolate, obj,
                                        nim_chatroom::kNIMChatRoomInfoKeyID,
                                        out_i64) == napi_ok)
        info.id_ = out_i64;
    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomInfoKeyName, out) ==
        napi_ok)
        info.name_ = out.toUtf8String();
    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomInfoKeyAnnouncement, out) ==
        napi_ok)
        info.announcement_ = out.toUtf8String();
    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomInfoKeyBroadcastUrl, out) ==
        napi_ok)
        info.broadcast_url_ = out.toUtf8String();
    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomInfoKeyCreatorID, out) ==
        napi_ok)
        info.creator_id_ = out.toUtf8String();
    if (nim_napi_get_object_value_bool(
            isolate, obj, nim_chatroom::kNIMChatRoomInfoKeyValidFlag, out_b) ==
        napi_ok)
        info.valid_flag_ = out_b;
    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomInfoKeyExt, out) == napi_ok)
        info.ext_ = out.toUtf8String();
    if (nim_napi_get_object_value_int32(
            isolate, obj, nim_chatroom::kNIMChatRoomInfoKeyOnlineCount, out_i))
        info.online_count_ = out_i;
    if (nim_napi_get_object_value_bool(
            isolate, obj, nim_chatroom::kNIMChatRoomInfoKeyMuteAll, out_b))
        info.mute_all_ = out_b ? 1 : 0;
    if (nim_napi_get_object_value_int32(
            isolate, obj, nim_chatroom::kNIMChatRoomInfoKeyQueuelevel, out_i))
        info.queuelevel = out_i;

    return napi_ok;
}

napi_status nim_chatroom_independent_enter_info_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomIndependentEnterInfo& info) {
    UTF8String out;
    int32_t out_i;
    std::list<utf8_string> out_list;
    Local<Value> out_v;
    if (nim_napi_get_object_value(isolate, obj,
                                  nim_chatroom::kNIMChatRoomEnterKeyAddress,
                                  out_v) == napi_ok) {
        if (nim_napi_get_value_utf8string_list(isolate, out_v, out_list) ==
            napi_ok)
            info.address_ = out_list;
    }
    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomEnterKeyAppDataPath, out) ==
        napi_ok)
        info.app_data_file_ = out.toUtf8String();
    if (nim_napi_get_object_value_int32(
            isolate, obj, nim_chatroom::kNIMChatRoomEnterKeyLogLevel, out_i) ==
        napi_ok)
        info.sdk_log_level_ = out_i;
    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomEnterKeyAppKey, out) ==
        napi_ok)
        info.app_key_ = out.toUtf8String();
    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomEnterKeyAccID, out) ==
        napi_ok)
        info.accid_ = out.toUtf8String();
    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomEnterKeyToken, out) ==
        napi_ok)
        info.token_ = out.toUtf8String();
    if (nim_napi_get_object_value(isolate, obj,
                                  nim_chatroom::kNIMChatRoomEnterLoginTags,
                                  out_v) == napi_ok) {
        if (nim_napi_get_value_utf8string_list(isolate, out_v, out_list) ==
            napi_ok)
            info.login_tags_ = out_list;
    }
    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomEnterNotifyTags, out) ==
        napi_ok)
        info.notify_tags_ = out.toUtf8String();

    return napi_ok;
}

napi_status nim_chatroom_independent_enter_info_to_obj(
    Isolate* isolate,
    const nim_chatroom::ChatRoomIndependentEnterInfo& config,
    Local<Object>& obj) {}

napi_status nim_chatroom_enter_info_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomEnterInfo& enter_info) {
    UTF8String out;
    Local<Value> out_v;
    std::list<utf8_string> out_list;
    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomEnterKeyNick, out) ==
        napi_ok)
        enter_info.SetNick(out.toUtf8String());
    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomEnterKeyAvatar, out) ==
        napi_ok)
        enter_info.SetAvatar(out.toUtf8String());
    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomEnterKeyExt, out) ==
        napi_ok)
        enter_info.SetExt(out.toUtf8String());
    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomEnterKeyNotifyExt, out) ==
        napi_ok)
        enter_info.SetNotifyExt(out.toUtf8String());
    if (nim_napi_get_object_value(isolate, obj,
                                  nim_chatroom::kNIMChatRoomEnterLoginTags,
                                  out_v) == napi_ok) {
        if (nim_napi_get_value_utf8string_list(isolate, out_v, out_list) ==
            napi_ok)
            enter_info.SetLoginTag(out_list);
    }
    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomEnterNotifyTags, out) ==
        napi_ok)
        enter_info.SetNotifyTags(out.toUtf8String());
    return napi_ok;
}

napi_status nim_chatroom_anoymity_enter_info_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomAnoymityEnterInfo& anoymity_enter_info) {
    bool out_b;
    if (nim_napi_get_object_value_bool(
            isolate, obj, nim_chatroom::kNIMChatRoomEnterKeyRandomID, out_b) ==
        napi_ok)
        anoymity_enter_info.random_id_ = out_b;

    // 复用 IndependentEnterInfo 转换逻辑
    nim_chatroom::ChatRoomIndependentEnterInfo enter_info;
    nim_chatroom_independent_enter_info_obj_to_struct(isolate, obj, enter_info);
    // 对输出重新赋值
    anoymity_enter_info.address_ = enter_info.address_;
    anoymity_enter_info.app_data_file_ = enter_info.app_data_file_;
    anoymity_enter_info.app_key_ = enter_info.app_key_;
    anoymity_enter_info.login_tags_ = enter_info.login_tags_;
    anoymity_enter_info.notify_tags_ = enter_info.notify_tags_;
    anoymity_enter_info.sdk_log_level_ = enter_info.sdk_log_level_;

    return napi_ok;
}

napi_status nim_chatroom_room_info_to_obj(
    Isolate* isolate,
    const nim_chatroom::ChatRoomInfo& info,
    Local<Object>& obj) {
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(isolate,
                                     nim_chatroom::kNIMChatRoomMsgKeyRoomID),
             nim_napi_new_int32(isolate, info.id_));
    obj->Set(
        isolate->GetCurrentContext(),
        nim_napi_new_utf8string(isolate, nim_chatroom::kNIMChatRoomInfoKeyName),
        nim_napi_new_utf8string(isolate, info.name_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomInfoKeyAnnouncement),
             nim_napi_new_utf8string(isolate, info.announcement_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomInfoKeyBroadcastUrl),
             nim_napi_new_utf8string(isolate, info.broadcast_url_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomInfoKeyCreatorID),
             nim_napi_new_utf8string(isolate, info.creator_id_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomInfoKeyValidFlag),
             nim_napi_new_bool(isolate, info.valid_flag_ == 1));
    obj->Set(
        isolate->GetCurrentContext(),
        nim_napi_new_utf8string(isolate, nim_chatroom::kNIMChatRoomInfoKeyExt),
        nim_napi_new_utf8string(isolate, info.ext_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomInfoKeyOnlineCount),
             nim_napi_new_int32(isolate, info.online_count_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(isolate,
                                     nim_chatroom::kNIMChatRoomInfoKeyMuteAll),
             nim_napi_new_bool(isolate, info.mute_all_ == 1));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomInfoKeyQueuelevel),
             nim_napi_new_int32(isolate, info.queuelevel));
    return napi_ok;
}

napi_status nim_chatroom_my_info_to_obj(
    Isolate* isolate,
    const nim_chatroom::ChatRoomMemberInfo& my_info,
    Local<Object>& obj) {
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyRoomID),
             nim_napi_new_int64(isolate, my_info.room_id_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyAccID),
             nim_napi_new_utf8string(isolate, my_info.account_id_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyType),
             nim_napi_new_utf8string(isolate, my_info.tags_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyLevel),
             nim_napi_new_int32(isolate, my_info.type_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyNick),
             nim_napi_new_int32(isolate, my_info.level_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyAvatar),
             nim_napi_new_utf8string(isolate, my_info.nick_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyExt),
             nim_napi_new_utf8string(isolate, my_info.avatar_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyTag),
             nim_napi_new_utf8string(isolate, my_info.ext_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyNotifyTags),
             nim_napi_new_utf8string(isolate, my_info.notify_tags_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyOnlineState),
             nim_napi_new_int32(isolate, my_info.state_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyGuestFlag),
             nim_napi_new_int32(isolate, my_info.guest_flag_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyEnterTimetag),
             nim_napi_new_int64(isolate, my_info.enter_timetag_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyEnterTimetag),
             nim_napi_new_bool(isolate, my_info.is_blacklist_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyMuted),
             nim_napi_new_bool(isolate, my_info.is_muted_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyValid),
             nim_napi_new_bool(isolate, my_info.is_valid_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyUpdateTimetag),
             nim_napi_new_int64(isolate, my_info.update_timetag_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyTempMute),
             nim_napi_new_bool(isolate, my_info.temp_muted_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate,
                 nim_chatroom::kNIMChatRoomMemberInfoKeyTempMuteRestDuration),
             nim_napi_new_int64(isolate, my_info.temp_muted_duration_));
    return napi_ok;
}

napi_status nim_chatroom_exit_reason_info_to_obj(
    Isolate* isolate,
    const nim_chatroom::NIMChatRoomExitReasonInfo& exit_reason_info,
    Local<Object>& obj) {
    obj->Set(
        isolate->GetCurrentContext(),
        nim_napi_new_utf8string(isolate,
                                nim_chatroom::kNIMChatRoomEnterKeyNotifyExt),
        nim_napi_new_utf8string(isolate, exit_reason_info.notify_ext_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(isolate, "exit_reason"),
             nim_napi_new_int32(isolate, exit_reason_info.code_));
    return napi_ok;
}

napi_status nim_chatroom_msg_settings_to_obj(
    Isolate* isolate,
    const nim_chatroom::ChatRoomMessageSetting& msg_settings,
    Local<Object>& obj) {
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMsgKeyResendFlag),
             nim_napi_new_bool(isolate, msg_settings.resend_flag_));
    obj->Set(
        isolate->GetCurrentContext(),
        nim_napi_new_utf8string(isolate, nim_chatroom::kNIMChatRoomMsgKeyExt),
        nim_napi_new_utf8string(isolate, msg_settings.ext_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMsgKeyAntiSpamEnable),
             nim_napi_new_bool(isolate, msg_settings.anti_spam_enable_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMsgKeyAntiSpamContent),
             nim_napi_new_utf8string(isolate,
                                     msg_settings.anti_spam_content_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMsgKeyHistorySave),
             nim_napi_new_bool(isolate, msg_settings.history_save_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMsgKeyAntiSpamBizId),
             nim_napi_new_utf8string(isolate,
                                     msg_settings.anti_spam_bizid_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMsgKeyAntiSpamUsingYiDun),
             nim_napi_new_int32(isolate, msg_settings.anti_spam_using_yidun_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMsgKeyHighPriorityFlag),
             nim_napi_new_int32(isolate, msg_settings.high_priority_));
    obj->Set(
        isolate->GetCurrentContext(),
        nim_napi_new_utf8string(isolate,
                                nim_chatroom::kNIMChatRoomMsgKeyEnvConfig),
        nim_napi_new_utf8string(isolate, msg_settings.env_config_.c_str()));
    return napi_ok;
}

napi_status nim_chatroom_room_message_to_obj(
    Isolate* isolate,
    const nim_chatroom::ChatRoomMessage& message,
    Local<Object>& obj) {
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(isolate,
                                     nim_chatroom::kNIMChatRoomMsgKeyRoomID),
             nim_napi_new_int64(isolate, message.room_id_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMsgKeyFromAccount),
             nim_napi_new_utf8string(isolate, message.from_id_.c_str()));
    obj->Set(
        isolate->GetCurrentContext(),
        nim_napi_new_utf8string(isolate, nim_chatroom::kNIMChatRoomMsgKeyTime),
        nim_napi_new_int64(isolate, message.timetag_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMsgKeyFromClientType),
             nim_napi_new_int64(isolate, message.from_client_type_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(isolate,
                                     nim_chatroom::kNIMChatRoomMsgKeyFromNick),
             nim_napi_new_utf8string(isolate, message.from_nick_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMsgKeyFromAvatar),
             nim_napi_new_utf8string(isolate, message.from_avatar_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(isolate,
                                     nim_chatroom::kNIMChatRoomMsgKeyFromExt),
             nim_napi_new_utf8string(isolate, message.from_ext_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMsgKeyThirdPartyCBEXT),
             nim_napi_new_utf8string(
                 isolate, message.third_party_callback_ext_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMsgKeyNotifyTags),
             nim_napi_new_utf8string(isolate, message.notify_tags_.c_str()));
    obj->Set(
        isolate->GetCurrentContext(),
        nim_napi_new_utf8string(isolate, nim_chatroom::kNIMChatRoomMsgKeyType),
        nim_napi_new_int32(isolate, message.msg_type_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(isolate,
                                     nim_chatroom::kNIMChatRoomMsgKeyAttach),
             nim_napi_new_utf8string(isolate, message.msg_attach_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMsgKeyClientMsgid),
             nim_napi_new_utf8string(isolate, message.client_msg_id_.c_str()));
    obj->Set(
        isolate->GetCurrentContext(),
        nim_napi_new_utf8string(isolate, nim_chatroom::kNIMChatRoomMsgKeyBody),
        nim_napi_new_utf8string(isolate, message.msg_body_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(isolate,
                                     nim_chatroom::kNIMChatRoomMsgKeySubType),
             nim_napi_new_int32(isolate, message.sub_type_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMsgKeyLocalFilePath),
             nim_napi_new_utf8string(isolate, message.local_res_path_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMsgKeyLocalResId),
             nim_napi_new_utf8string(isolate, message.local_res_id_.c_str()));

    // Message settings
    Local<Object> msg_settings_obj = Object::New(isolate);
    nim_chatroom_msg_settings_to_obj(isolate, message.msg_setting_,
                                     msg_settings_obj);
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(isolate, "msg_settings"),
             msg_settings_obj);

    return napi_ok;
}

napi_status nim_chatroom_room_messages_to_array(
    Isolate* isolate,
    const std::list<nim_chatroom::ChatRoomMessage>& messages,
    Local<Array>& array) {
    uint32_t index = 0;
    for (auto& message : messages) {
        Local<Object> message_obj = Object::New(isolate);
        nim_chatroom_room_message_to_obj(isolate, message, message_obj);
        array->Set(isolate->GetCurrentContext(), index++, message_obj);
    }
    return napi_ok;
}

napi_status nim_chatroom_get_member_params_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomGetMembersParameters& get_member_parameters) {
    int32_t out_i;
    int64_t out_i64;
    Local<Value> out_v;
    if (nim_napi_get_object_value_int32(
            isolate, obj, nim_chatroom::kNIMChatRoomGetMembersKeyType, out_i) ==
        napi_ok)
        get_member_parameters.type_ =
            static_cast<nim_chatroom::NIMChatRoomGetMemberType>(out_i);
    if (nim_napi_get_object_value_int64(
            isolate, obj, nim_chatroom::kNIMChatRoomGetMembersKeyOffset,
            out_i64) == napi_ok)
        get_member_parameters.timestamp_offset_ = out_i64;
    if (nim_napi_get_object_value_int32(
            isolate, obj, nim_chatroom::kNIMChatRoomGetMembersKeyLimit,
            out_i) == napi_ok)
        get_member_parameters.limit_ = out_i;
    return napi_ok;
}

napi_status nim_chatroom_get_member_by_tag_params_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomGetMembersByTagParameters& get_member_parameters) {
    UTF8String out;
    int32_t out_i;
    int64_t out_i64;
    Local<Value> out_v;
    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomGetMembersKeyTag, out) ==
        napi_ok)
        get_member_parameters.tag_ = out.toUtf8String();
    if (nim_napi_get_object_value_int64(
            isolate, obj, nim_chatroom::kNIMChatRoomGetMembersKeyOffset,
            out_i64) == napi_ok)
        get_member_parameters.timestamp_offset_ = out_i64;
    if (nim_napi_get_object_value_int32(
            isolate, obj, nim_chatroom::kNIMChatRoomGetMembersKeyLimit,
            out_i) == napi_ok)
        get_member_parameters.limit_ = out_i;
    return napi_ok;
}

napi_status nim_chatroom_room_notification_to_obj(
    Isolate* isolate,
    const nim_chatroom::ChatRoomNotification& notification,
    Local<Object>& obj) {
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(isolate,
                                     nim_chatroom::kChatRoomNotificationKeyID),
             nim_napi_new_int32(isolate, notification.id_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kChatRoomNotificationDataKeyExt),
             nim_napi_new_utf8string(isolate, notification.ext_.c_str()));
    obj->Set(
        isolate->GetCurrentContext(),
        nim_napi_new_utf8string(isolate,
                                nim_chatroom::kChatRoomNotificationDataKeyOpt),
        nim_napi_new_utf8string(isolate, notification.operator_id_.c_str()));
    obj->Set(
        isolate->GetCurrentContext(),
        nim_napi_new_utf8string(
            isolate, nim_chatroom::kChatRoomNotificationDataKeyOptNick),
        nim_napi_new_utf8string(isolate, notification.operator_nick_.c_str()));
    // target nicks
    Local<Array> target_nick_array =
        Array::New(isolate, notification.target_nick_.size());
    uint32_t index = 0;
    for (auto& target_nick : notification.target_nick_) {
        target_nick_array->Set(
            isolate->GetCurrentContext(), index++,
            nim_napi_new_utf8string(isolate, target_nick.c_str()));
    }
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kChatRoomNotificationDataKeyTargetNick),
             target_nick_array);

    // target ids
    Local<Array> target_ids_array =
        Array::New(isolate, notification.target_ids_.size());
    index = 0;
    for (auto& target_id : notification.target_ids_) {
        target_ids_array->Set(
            isolate->GetCurrentContext(), index++,
            nim_napi_new_utf8string(isolate, target_id.c_str()));
    }
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kChatRoomNotificationDataKeyTarget),
             target_ids_array);

    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate,
                 nim_chatroom::kChatRoomNotificationDataKeyTempMuteDuration),
             nim_napi_new_int64(isolate, notification.temp_mute_duration_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kChatRoomNotificationDataKeyMuteFlag),
             nim_napi_new_bool(isolate, notification.muted_));
    obj->Set(
        isolate->GetCurrentContext(),
        nim_napi_new_utf8string(
            isolate, nim_chatroom::kChatRoomNotificationDataKeyTempMutedFlag),
        nim_napi_new_bool(isolate, notification.temp_muted_));

    return napi_ok;
}

napi_status nim_chatroom_room_notifications_to_array(
    Isolate* isolate,
    const std::list<nim_chatroom::ChatRoomNotification>& notifications,
    Local<Array>& array) {
    uint32_t index = 0;
    for (auto& notification : notifications) {
        Local<Object> notification_obj = Object::New(isolate);
        nim_chatroom_room_notification_to_obj(isolate, notification,
                                              notification_obj);
        array->Set(isolate->GetCurrentContext(), index++, notification_obj);
    }
    return napi_ok;
}

napi_status nim_chatroom_member_info_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomMemberInfo& member_info) {
    UTF8String out;
    int32_t out_i;
    int64_t out_i64;
    bool out_b;
    Local<Value> out_v;
    if (nim_napi_get_object_value_int64(
            isolate, obj, nim_chatroom::kNIMChatRoomMemberInfoKeyRoomID,
            out_i64) == napi_ok)
        member_info.room_id_ = out_i64;

    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomMemberInfoKeyAccID, out) ==
        napi_ok)
        member_info.account_id_ = out.toUtf8String();

    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomMemberInfoKeyTag, out) ==
        napi_ok)
        member_info.tags_ = out.toUtf8String();

    if (nim_napi_get_object_value_int32(
            isolate, obj, nim_chatroom::kNIMChatRoomMemberInfoKeyType, out_i) ==
        napi_ok)
        member_info.type_ = out_i;

    if (nim_napi_get_object_value_int32(
            isolate, obj, nim_chatroom::kNIMChatRoomMemberInfoKeyLevel,
            out_i) == napi_ok)
        member_info.level_ = out_i;

    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomMemberInfoKeyNick, out) ==
        napi_ok)
        member_info.nick_ = out.toUtf8String();

    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomMemberInfoKeyAvatar, out) ==
        napi_ok)
        member_info.avatar_ = out.toUtf8String();

    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomMemberInfoKeyExt, out) ==
        napi_ok)
        member_info.ext_ = out.toUtf8String();

    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomMemberInfoKeyNotifyTags,
            out) == napi_ok)
        member_info.notify_tags_ = out.toUtf8String();

    if (nim_napi_get_object_value_int32(
            isolate, obj, nim_chatroom::kNIMChatRoomMemberInfoKeyOnlineState,
            out_i) == napi_ok)
        member_info.state_ =
            static_cast<nim_chatroom::NIMChatRoomOnlineState>(out_i);

    if (nim_napi_get_object_value_int32(
            isolate, obj, nim_chatroom::kNIMChatRoomMemberInfoKeyGuestFlag,
            out_i) == napi_ok)
        member_info.guest_flag_ =
            static_cast<nim_chatroom::NIMChatRoomGuestFlag>(out_i);

    if (nim_napi_get_object_value_bool(
            isolate, obj, nim_chatroom::kNIMChatRoomMemberInfoKeyBlacklist,
            out_b) == napi_ok)
        member_info.is_blacklist_ = out_b;

    if (nim_napi_get_object_value_bool(
            isolate, obj, nim_chatroom::kNIMChatRoomMemberInfoKeyMuted,
            out_b) == napi_ok)
        member_info.is_muted_ = out_b;

    if (nim_napi_get_object_value_bool(
            isolate, obj, nim_chatroom::kNIMChatRoomMemberInfoKeyValid,
            out_b) == napi_ok)
        member_info.is_valid_ = out_b;

    if (nim_napi_get_object_value_int64(
            isolate, obj, nim_chatroom::kNIMChatRoomMemberInfoKeyEnterTimetag,
            out_i64) == napi_ok)
        member_info.enter_timetag_ = out_i64;

    if (nim_napi_get_object_value_int64(
            isolate, obj, nim_chatroom::kNIMChatRoomMemberInfoKeyUpdateTimetag,
            out_i64) == napi_ok)
        member_info.update_timetag_ = out_i64;

    if (nim_napi_get_object_value_bool(
            isolate, obj, nim_chatroom::kNIMChatRoomMemberInfoKeyTempMute,
            out_b) == napi_ok)
        member_info.temp_muted_ = out_b;

    if (nim_napi_get_object_value_int64(
            isolate, obj,
            nim_chatroom::kNIMChatRoomMemberInfoKeyTempMuteRestDuration,
            out_i64) == napi_ok)
        member_info.temp_muted_duration_ = out_i64;

    return napi_ok;
}

napi_status nim_chatroom_member_info_to_obj(
    Isolate* isolate,
    const nim_chatroom::ChatRoomMemberInfo& member,
    Local<Object>& obj) {
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyRoomID),
             nim_napi_new_int64(isolate, member.room_id_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyAccID),
             nim_napi_new_utf8string(isolate, member.account_id_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyTag),
             nim_napi_new_utf8string(isolate, member.tags_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyType),
             nim_napi_new_int32(isolate, member.type_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyLevel),
             nim_napi_new_int32(isolate, member.level_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyNick),
             nim_napi_new_utf8string(isolate, member.nick_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyAvatar),
             nim_napi_new_utf8string(isolate, member.avatar_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyExt),
             nim_napi_new_utf8string(isolate, member.ext_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyNotifyTags),
             nim_napi_new_utf8string(isolate, member.notify_tags_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyOnlineState),
             nim_napi_new_int32(isolate, member.state_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyGuestFlag),
             nim_napi_new_int32(isolate, member.guest_flag_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyEnterTimetag),
             nim_napi_new_int64(isolate, member.enter_timetag_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyBlacklist),
             nim_napi_new_bool(isolate, member.is_blacklist_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyMuted),
             nim_napi_new_bool(isolate, member.is_muted_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyValid),
             nim_napi_new_bool(isolate, member.is_valid_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyUpdateTimetag),
             nim_napi_new_int64(isolate, member.update_timetag_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomMemberInfoKeyTempMute),
             nim_napi_new_bool(isolate, member.temp_muted_));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate,
                 nim_chatroom::kNIMChatRoomMemberInfoKeyTempMuteRestDuration),
             nim_napi_new_int64(isolate, member.temp_muted_duration_));
    return napi_ok;
}

napi_status nim_chatroom_members_info_to_array(
    Isolate* isolate,
    const std::list<nim_chatroom::ChatRoomMemberInfo>& members,
    Local<Array>& array) {
    uint32_t index = 0;
    for (auto& member : members) {
        Local<Object> member_obj = Object::New(isolate);
        nim_chatroom_member_info_to_obj(isolate, member, member_obj);
        array->Set(isolate->GetCurrentContext(), index++, member_obj);
    }
    return napi_ok;
}

napi_status nim_chatroom_get_message_history_params_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomGetMsgHistoryParameters& get_history_parameters) {
    UTF8String out;
    int32_t out_i;
    int64_t out_i64;
    bool out_b;
    Local<Value> out_v;
    if (nim_napi_get_object_value_int64(
            isolate, obj, nim_chatroom::kNIMChatRoomGetMsgHistoryKeyStartTime,
            out_i64) == napi_ok)
        get_history_parameters.start_timetag_ = out_i64;
    if (nim_napi_get_object_value_bool(
            isolate, obj, nim_chatroom::kNIMChatRoomGetMsgHistoryKeyReverse,
            out_b) == napi_ok)
        get_history_parameters.reverse_ = out_b;
    if (nim_napi_get_object_value_int32(
            isolate, obj, nim_chatroom::kNIMChatRoomGetMembersKeyLimit,
            out_i) == napi_ok)
        get_history_parameters.limit_ = out_i;

    if (nim_napi_get_object_value(
            isolate, obj, nim_chatroom::kNIMChatRoomGetMsgHistoryKeyMsgtypes,
            out_v) == napi_ok) {
        nim_napi_get_value_enumerate_list<
            std::vector<nim_chatroom::NIMChatRoomMsgType>,
            nim_chatroom::NIMChatRoomMsgType>(
            isolate, out_v, get_history_parameters.msg_types_);
    }
    return napi_ok;
}

napi_status nim_chatroom_set_member_attribute_params_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomSetMemberAttributeParameters&
        set_attribute_parameters) {
    UTF8String out;
    int32_t out_i;
    bool out_b;
    Local<Value> out_v;
    if (nim_napi_get_object_value_utf8string(
            isolate, obj,
            nim_chatroom::kNIMChatRoomSetMemberAttributeKeyAccoutID,
            out) == napi_ok)
        set_attribute_parameters.account_id_ = out.toUtf8String();
    if (nim_napi_get_object_value_int32(
            isolate, obj,
            nim_chatroom::kNIMChatRoomSetMemberAttributeKeyAttribute,
            out_i) == napi_ok)
        set_attribute_parameters.attribute_ =
            static_cast<nim_chatroom::NIMChatRoomMemberAttribute>(out_i);
    if (nim_napi_get_object_value_bool(
            isolate, obj, nim_chatroom::kNIMChatRoomSetMemberAttributeKeyOpt,
            out_b) == napi_ok)
        set_attribute_parameters.opt_ = out_b;
    if (nim_napi_get_object_value_utf8string(
            isolate, obj,
            nim_chatroom::kNIMChatRoomSetMemberAttributeKeyNotifyExt,
            out) == napi_ok)
        set_attribute_parameters.notify_ext_ = out.toUtf8String();
    return napi_ok;
}

napi_status nim_chatroom_queue_element_info_to_obj(
    Isolate* isolate,
    const nim_chatroom::ChatRoomQueueElement& element,
    Local<Object>& obj) {
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(isolate,
                                     nim_chatroom::kNIMChatRoomQueueElementKey),
             nim_napi_new_utf8string(isolate, element.key_.c_str()));
    obj->Set(isolate->GetCurrentContext(),
             nim_napi_new_utf8string(
                 isolate, nim_chatroom::kNIMChatRoomQueueElementValue),
             nim_napi_new_utf8string(isolate, element.value_.c_str()));
    return napi_ok;
}

napi_status nim_chatroom_queue_element_obj_to_struct(
    Isolate* isolate,
    const Local<Object>& obj,
    nim_chatroom::ChatRoomQueueElement& element) {
    UTF8String out;
    Local<Value> out_v;
    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomQueueElementKey, out) ==
        napi_ok)
        element.key_ = out.toUtf8String();
    if (nim_napi_get_object_value_utf8string(
            isolate, obj, nim_chatroom::kNIMChatRoomQueueElementValue, out) ==
        napi_ok)
        element.value_ = out.toUtf8String();
    return napi_ok;
}

napi_status nim_chatroom_queue_list_to_array(
    Isolate* isolate,
    const nim_chatroom::ChatRoomQueue& queue,
    Local<Array>& array) {
    uint32_t index = 0;
    for (auto& element : queue) {
        Local<Object> element_obj = Object::New(isolate);
        nim_chatroom_queue_element_info_to_obj(isolate, element, element_obj);
        array->Set(isolate->GetCurrentContext(), index++, element_obj);
    }
    return napi_ok;
}

napi_status nim_chatroom_queue_batch_member_array_to_list(
    Isolate* isolate,
    const Local<Object>& array,
    nim_chatroom::ChatRoomBatchMembers& batch_elements) {
    if (!array->IsArray())
        return napi_invalid_arg;
    Local<Array> arr = Local<Array>::Cast(array);
    uint32_t len = arr->Length();
    for (uint32_t i = 0; i < len; i++) {
        auto item = arr->Get(isolate->GetCurrentContext(), i)
                        .ToLocalChecked()
                        .As<Object>();
        UTF8String key;
        nim_napi_get_object_value_utf8string(
            isolate, item, nim_chatroom::kNIMChatRoomQueueElementKey, key);
        UTF8String value;
        nim_napi_get_object_value_utf8string(
            isolate, item, nim_chatroom::kNIMChatRoomQueueElementValue, value);
        batch_elements.members_values_[key.toUtf8String()] =
            value.toUtf8String();
    }
    return napi_ok;
}

}  // namespace nim_chatroom_node
