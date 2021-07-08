/**
 * 聊天室在线状态枚举
 */
export enum NIMChatRoomOnlineState {
  kNIMChatRoomOnlineStateOffline = 0, /**  不在线 */
  kNIMChatRoomOnlineStateOnline = 1, /**  在线 */
}

/**
 * 聊天室游客类型枚举
 */
export enum NIMChatRoomGuestFlag {
  kNIMChatRoomGuestFlagNoGuest = 0, /**  非游客 */
  kNIMChatRoomGuestFlagGuest = 1, /**  游客 */
}

/**
 * 聊天室信息
 */
export interface ChatRoomInfo {
  id: number, /**  聊天室ID */
  name: string, /**  聊天室名称 */
  announcement: string, /**  聊天室公告 */
  broadcast_url: string, /**  视频直播拉流地址 */
  creator_id: string, /**  聊天室创建者账号 */
  valid_flag: boolean, /**  聊天室有效标记, 1:有效,0:无效 */
  ext: string, /**  第三方扩展字段, 必须为可以解析为json的非格式化的字符串, 长度4k */
  online_count: number, /**  在线人数 */
  mute_all: boolean, /**  聊天室禁言标志 1:禁言,0:非禁言 */
  queuelevel: number/** int, 队列管理权限：0:所有人都有权限变更队列，1:只有主播管理员才能操作变更 */
}

/**
 * 聊天室成员信息
 */
export interface ChatRoomMemberInfo {
  room_id: number, /**  聊天室id */
  account_id: string, /**  成员账号 */
  tags: string, /**  聊天室成员登录时指定的 tag 信息 */
  type: number, /**  成员类型, -2:未设置;-1:受限用户; 0:普通;1:创建者;2:管理员;3:临时用户,非固定成员;4:匿名非注册用户,非云信注册用户 */
  level: number, /**  成员级别: >=0表示用户开发者可以自定义的级别 */
  nick: string, /**  聊天室内的昵称字段,预留字段, 可从Uinfo中取 */
  avatar: string, /**  聊天室内的头像,预留字段, 可从Uinfo中取icon */
  ext: string, /**  开发者扩展字段, 长度限制2k, 必须为可以解析为json的非格式化的字符串 */
  notify_tags: string, /**  聊天室成员登录时指定的 notify_tags 信息 */
  online_state: NIMChatRoomOnlineState, /**  成员是否处于在线状态, 仅特殊成员才可能离线, 对游客/匿名用户而言只能是在线 */
  guest_flag: NIMChatRoomGuestFlag, /**  是否是普通游客类型,0:不是游客,1:是游客; 游客身份在聊天室中没有持久化, 只有在线时才会有内存状态 */
  enter_timetag: number, /**  进入聊天室的时间点,对于离线成员该字段为空 */
  is_blacklist: boolean, /**  是黑名单 */
  is_muted: boolean, /**  是禁言用户 */
  valid: boolean, /**  记录有效标记位 */
  update_timetag: number, /**  固定成员的记录更新时间,用于固定成员列表的排列查询 */
  temp_mute: boolean, /**  临时禁言 */
  temp_mute_rest_duration: number /**  临时禁言的解除时长,单位秒 */
}

/**
 * 聊天室登录阶段枚举
 */
export enum NIMChatRoomEnterStep {
  kNIMChatRoomEnterStepInit = 1, /**  本地服务初始化 */
  kNIMChatRoomEnterStepServerConnecting = 2, /**  服务器连接中 */
  kNIMChatRoomEnterStepServerConnectOver = 3, /**  服务器连接结束,连接结果见error_code */
  kNIMChatRoomEnterStepRoomAuthing = 4, /**  聊天室鉴权中 */
  kNIMChatRoomEnterStepRoomAuthOver = 5, /**  聊天室鉴权结束,鉴权结果见error_code, error_code非408则需要开发者重新请求聊天室进入信息 */
}

/**
 * 聊天室加入回调模板
 */
export interface NIMChatRoomEnterCallback {
  (
    roomId: number, /** 聊天室 ID */
    step: NIMChatRoomEnterStep, /** 当前登录阶段 */
    errorCode: number, /** 每个阶段对应的状态码 */
    info: ChatRoomInfo, /** 加入成功后的聊天室信息 */
    memberInfo: ChatRoomMemberInfo /** 加入成功后的成员信息 */
  ): void
}

/**
 * 加入聊天室所需信息
 */
export interface ChatRoomEnterInfo {
  nick?: string, /** 昵称 */
  avatar?: string, /** 头像地址 */
  ext?: string, /** 拓展信息 */
  notify_ext?: string, /** 加入聊天室后的拓展通知信息 */
  login_tags?: Array<string>, /** 登录时使用的标签列表 */
  notify_tags?: string /** 登录时要通知的标签表达式字符串 */
}

/**
 * 聊天室登录状态类型
 */
export enum NIMChatRoomLoginState {
  kNIMChatRoomLoginStateLogin = 1, /**  登录状态 */
  kNIMChatRoomLoginStateUnLogin = 2, /**  未登录状态 */
}

/**
 * 退出聊天室原因类型
 */
export enum NIMChatRoomExitReason {
  kNIMChatRoomExitReasonExit = 0, /**  自行退出,重登前需要重新请求进入 */
  kNIMChatRoomExitReasonRoomInvalid = 1, /**  聊天室已经被解散,重登前需要重新请求进入 */
  kNIMChatRoomExitReasonKickByManager = 2, /**  被管理员踢出,重登前需要重新请求进入 */
  kNIMChatRoomExitReasonKickByMultiSpot = 3, /**  多端被踢 */
  kNIMChatRoomExitReasonIllegalState = 4, /**  当前链接状态异常 */
  kNIMChatRoomExitReasonBeBlacklisted = 5, /**  被加黑了 */
}

/**
 * 退出聊天室原因信息
 */
export interface NIMChatRoomExitReasonInfo {
  notify_ext: string /**  附加信息长度限制 2048 字节 */
  reason: NIMChatRoomExitReason /**  退出原因的代码 */
}

/**
 * 退出聊天室的回调模板
 */
export interface NIMChatRoomExitCallback {
  (
    roomId: number, /** 退出的聊天室 ID */
    errorCode: number, /** 退出聊天室的返回代码 */
    exitInfo: NIMChatRoomExitReasonInfo /** 退出聊天室原因信息 */
  ): void
}

/**
 * 加入到聊天室的客户端类型
 */
export enum NIMChatRoomClientType {
  kNIMChatRoomClientTypeDefault = 0, /**  default,unset */
  kNIMChatRoomClientTypeAndroid = 1, /**  android */
  kNIMChatRoomClientTypeiOS = 2, /**  iOS */
  kNIMChatRoomClientTypePCWindows = 4, /**  PC */
  kNIMChatRoomClientTypeWindowsPhone = 8, /**  WindowsPhone */
  kNIMChatRoomClientTypeWeb = 16, /**  Web */
  kNIMChatRoomClientTypeRestAPI = 32, /**  RestAPI */
  kNIMChatRoomClientTypeMacOS = 64, /**  Mac */
}

/**
 * 聊天室消息类型
 */
export enum NIMChatRoomMsgType {
  kNIMChatRoomMsgTypeText = 0, /**  文本类型消息 */
  kNIMChatRoomMsgTypeImage = 1, /**  图片类型消息 */
  kNIMChatRoomMsgTypeAudio = 2, /**  声音类型消息 */
  kNIMChatRoomMsgTypeVideo = 3, /**  视频类型消息 */
  kNIMChatRoomMsgTypeLocation = 4, /**  位置类型消息 */
  kNIMChatRoomMsgTypeNotification = 5, /**  活动室通知 */
  kNIMChatRoomMsgTypeFile = 6, /**  文件类型消息 */
  kNIMChatRoomMsgTypeRobot = 11, /**  波特机器人消息 */
  kNIMChatRoomMsgTypeTips = 10, /**  提醒类型消息 */
  kNIMChatRoomMsgTypeCustom = 100, /**  自定义消息 */
  kNIMChatRoomMsgTypeUnknown = 1000, /**  未知类型消息，作为默认值 */
}

/**
 * 聊天室消息属性设置声明
 */
export interface ChatRoomMessageSetting {
  resend_flag: boolean, /**  消息重发标记位 */
  ext: string, /**  第三方扩展字段, 必须为可以解析为json的非格式化的字符串，长度限制4096 */
  anti_spam_enable: boolean, /**  是否需要过易盾反垃圾 */
  anti_spam_content: string, /**  (可选)开发者自定义的反垃圾字段,长度限制2048 */
  anti_spam_business_id: string, /**  (可选)用户配置的对某些单条消息另外的反垃圾的业务ID */
  anti_spam_using_yidun: boolean, /**  int,  (可选) 单条消息是否使用易盾反垃圾 0:(在开通易盾的情况下)不过易盾反垃圾而是通用反垃圾其他都是按照原来的规则 */
  yidun_anti_cheating: string, /**  (可选)String, 易盾反垃圾增强反作弊专属字段, 限制json，长度限制1024 */
  history_save: boolean, /**  (可选)是否存云端消息历史，默认存 */
  high_priority_flag: number, /**  高优先级消息标记,1:是; 非高优先级消息不带该字段,服务器填写,发送方不需要填写 */
  env_config: string /**  (可选) 自定义抄送配置 */
}

/**
 * 聊天室消息对象声明
 */
export interface ChatRoomMessage {
  room_id: number, /**  消息所属的聊天室id,服务器填写,发送方不需要填写 */
  from_id?: string, /**  消息发送者的账号,服务器填写,发送方不需要填写 */
  timetag?: number, /**  消息发送的时间戳(毫秒),服务器填写,发送方不需要填写 */
  from_client_type?: NIMChatRoomClientType, /**  消息发送方客户端类型,服务器填写,发送方不需要填写 */
  from_nick?: string, /**  发送方昵称,服务器填写,发送方不需要填写 */
  from_avator?: string, /**  发送方头像,服务器填写,发送方不需要填写 */
  from_ext?: string, /**  发送方身份扩展字段,服务器填写,发送方不需要填写 */
  third_party_callback_ext?: string, /**  第三方回调回来的自定义扩展字段 */
  notify_tags: string, /**  发送消息或通知时携带的 notify tags 信息 */
  msg_type: NIMChatRoomMsgType, /**  消息类型 */
  msg_sub_type?: number, /**  消息的子类型，客户端定义，服务器透传 */
  msg_attach?: string, /**  消息内容,长度限制2048,json结构, 文本消息和其他消息保持一致 */
  client_msg_id: string, /**  客户端消息id */
  body?: string, /**  文本消息内容（聊天室机器人文本消息） */
  msg_settings: ChatRoomMessageSetting, /**  消息属性设置 */
  local_res_path?: string, /**  媒体文件本地绝对路径（客户端） */
  res_id?: string /**  媒体文件ID（客户端） */
}

/**
 * 聊天室发送消息 Ack 回调模板
 */
export interface NIMChatRoomSendMsgAckCallback {
  (
    roomId: number, /** 聊天室 ID */
    errorCode: number, /** 返回错误码 */
    result: ChatRoomMessage /** 发送后的消息体 */
  ): void
}

/**
 * 聊天室接收到单个消息的回调模板
 */
export interface NIMChatRoomReceiveMsgCallback {
  (
    roomId: number, /** 聊天室 ID */
    message: ChatRoomMessage /** 消息体 */
  ): void
}

/**
 * 聊天室收到批量消息的回调模板
 */
export interface NIMChatRoomReceiveMsgsCallback {
  (
    roomId: number, /** 聊天室 ID */
    messages: Array<ChatRoomMessage> /** 消息列表 */
  ): void
}

/**
 * 聊天室通知消息类型
 */
export enum NIMChatRoomNotificationId {
  kNIMChatRoomNotificationIdMemberIn = 301, /** 成员进入聊天室 */
  kNIMChatRoomNotificationIdMemberExit = 302, /** 成员离开聊天室 */
  kNIMChatRoomNotificationIdAddBlack = 303, /** 成员被加黑 */
  kNIMChatRoomNotificationIdRemoveBlack = 304, /** 成员被取消黑名单 */
  kNIMChatRoomNotificationIdAddMute = 305, /** 成员被设置禁言 */
  kNIMChatRoomNotificationIdRemoveMute = 306, /** 成员被取消禁言 */
  kNIMChatRoomNotificationIdAddManager = 307, /** 设置为管理员 */
  kNIMChatRoomNotificationIdRemoveManager = 308, /** 取消管理员 */
  kNIMChatRoomNotificationIdAddFixed = 309, /** 成员设定为固定成员 */
  kNIMChatRoomNotificationIdRemoveFixed = 310, /** 成员取消固定成员 */
  kNIMChatRoomNotificationIdClosed = 311, /** 聊天室被关闭了 */
  kNIMChatRoomNotificationIdInfoUpdated = 312, /** 聊天室信息被更新了 */
  kNIMChatRoomNotificationIdMemberKicked = 313, /** 成员被踢了 */
  kNIMChatRoomNotificationIdMemberTempMute = 314, /** 临时禁言 */
  kNIMChatRoomNotificationIdMemberTempUnMute = 315, /** 主动解除临时禁言 */
  kNIMChatRoomNotificationIdMyRoleUpdated = 316, /** 成员主动更新了聊天室内的角色信息(仅指nick/avator/ext) */
  kNIMChatRoomNotificationIdQueueChanged = 317, /** 麦序队列中有变更 "ext" : {"_e":"OFFER", "key":"element_key", "content":"element_value"} */
  kNIMChatRoomNotificationIdRoomMuted = 318, /** 聊天室被禁言了,只有管理员可以发言,其他人都处于禁言状态 */
  kNIMChatRoomNotificationIdRoomDeMuted = 319, /** 聊天室解除全体禁言状态 */
  kNIMChatRoomNotificationIdQueueBatchChanged = 320, /** 麦序队列中有批量变更，发生在元素提交者离开聊天室或者从聊天室异常掉线时 */
}

/**
 * 聊天室通知信息模板
 */
export interface ChatRoomNotification {
  id: NIMChatRoomNotificationId, /** 通知类型 */
  data: string /** 上层开发自定义的事件通知扩展字段, 必须为可以解析为 json 的非格式化的字符串 */
  operator: string, /** 操作者的账号accid */
  opeNick: string, /** 操作者的账号nick */
  tarNick: Array<string>, /** 被操作者的账号nick列表 */
  target: Array<string>, /** 被操作者的accid列表 */
  muteDuration: number, /** 当通知为临时禁言相关时有该值，禁言时代表本次禁言的时长(秒)，解禁时代表本次禁言剩余时长(秒); 当通知为聊天室进入事件，代表临时禁言时长(秒); 其他通知事件不带该数据 */
  tempMuted: boolean, /** 当通知为聊天室进入事件才有，代表是否禁言状态 */
  muteTtl: boolean, /** 当通知为聊天室进入事件才有，代表是否临时禁言状态 */
  queueChange: string, /** 当通知为聊天室队列变更事件才有，代表变更的内容 */
}

/**
 * 聊天室全局通知回调模板
 */
export interface NIMChatRoomNotificationCallback {
  (
    roomId: number, /** 通知来自哪个聊天室的 ID */
    notification: ChatRoomNotification /** 通知信息 */
  ): void
}

/** 聊天室链接状态变更类型 */
export enum NIMChatRoomLinkCondition {
  kNIMChatRoomLinkConditionAlive = 0, /** 链接正常 */
  kNIMChatRoomLinkConditionDeadAndRetry = 1, /** 链接失败,sdk尝试重链 */
  kNIMChatRoomLinkConditionDead = 2, /** 链接失败,开发者需要重新申请聊天室进入信息 */
}

/**
 * 聊天室链接状态变更回调
 */
export interface NIMChatRoomLinkConditionCallback {
  (
    roomId: number, /** 聊天室 ID */
    condition: NIMChatRoomLinkCondition /** 链接状态 */
  ): void
}

export enum NIMSDKLogLevel {
  kNIMSDKLogLevelFatal = 1, /** SDK Fatal级别Log */
  kNIMSDKLogLevelError = 2, /** SDK Error级别Log */
  kNIMSDKLogLevelWarn = 3, /** SDK Warn级别Log */
  kNIMSDKLogLevelApp = 5, /** SDK应用级别Log，正式发布时为了精简sdk log，可采用此级别 */
  kNIMSDKLogLevelPro = 6, /** SDK调试过程级别Log，更加详细，更有利于开发调试 */
}

/**
 * 使用独立模式加入聊天室的信息
 */
export interface ChatRoomIndependentEnterInfo {
  address: Array<string>, /** 连接的聊天室地址列表 */
  app_data_path: string, /** 用户自定义数据目录 */
  log_level: NIMSDKLogLevel, /** 日志界别 */
  app_key: string, /** appKey */
  accid: string, /** 用户 ID */
  token: string, /** 用户 Token */
  login_tags: Array<string>, /** 登录时携带的标签列表 */
  notify_tags: string /** 登录时通知的标签表达式字符串 */
}

/** 匿名方式加入聊天室信息 */
export interface ChatRoomAnoymityEnterInfo {
  address: Array<string>, /** 聊天室地址 */
  app_data_path: string, /** 用户数据目录 */
  log_level: NIMSDKLogLevel, /** 日志级别 */
  app_key: string, /** appKey */
  random_id: boolean, /** 是否使用随即 ID 模式 */
  login_tags: Array<string>, /** 登录使用的标签 */
  notify_tags: string /** 登录时要通知的标签列表表达式 */
}

/**
 * 获取成员类型枚举
 */
export enum NIMChatRoomGetMemberType {
  kNIMChatRoomGetMemberTypeSolid = 0, /** 固定成员,固定成员,包括创建者,管理员,普通等级用户,受限用户(禁言+黑名单) 即使非在线也可以在列表中看到,有数量限制,查询时时间戳使用"updatetime" */
  kNIMChatRoomGetMemberTypeTemp = 1, /** 非固定成员,非固定成员,又称临时成员,只有在线时才能在列表中看到,数量无上限,查询时时间戳使用"进入聊天室时间" */
  kNIMChatRoomGetMemberTypeSolidOL = 2, /** 在线固定成员 查询时时间戳使用"updatetime" */
  kNIMChatRoomGetMemberTypeTempOL = 3, /** 非固定成员(反向查询) 查询时时间戳使用"进入聊天室时间" */
}

/**
 * 获取成员参数列表
 */
export interface ChatRoomGetMembersParameters {
  type: NIMChatRoomGetMemberType, /** 查询成员的类型 */
  timestampOffset: number, /** 要查询的起始时间戳 */
  limit: number /** 查询结果数量限制 */
}

/**
 * 根据标签查询指定成员的参数列表
 */
export interface ChatRoomGetMembersByTagParameters {
  tag: string, /** 查询的标签信息 */
  offset: number, /** 要查询的起始时间戳 */
  limit: number /** 查询结果数量限制 */
}

/**
 * 获取在线成员列表的回调模板
 */
export interface GetMemberOnlineCallback {
  (
    roomId: number, /** 聊天室 ID */
    errorCode: number, /** 返回错误码 */
    members: Array<ChatRoomMemberInfo> /** 成员信息列表 */
  ): void
}

/**
 * 获取在线成员数量的回调模板
 */
export interface GetMemberCountByTagCallback {
  (
    roomId: number, /** 聊天室 ID */
    errorCode: number, /** 返回错误码 */
    count: number /** 返回的成员数量 */
  ): void
}

/**
 * 获取聊天室历史消息的参数列表
 */
export interface ChatRoomGetMsgHistoryParameters {
  start: number, /** 开始时间,单位毫秒 */
  limit: number, /** 本次返回的消息数量 */
  reverse: boolean, /** 按时间正序起查，正序排列,false:按时间逆序起查，逆序排列 */
  msgtypes: Array<NIMChatRoomMsgType> /** 要查询的消息类型，取值NIMChatRoomMsgType中所枚举类型 */
}

/**
 * 获取聊天室历史消息的回调模板
 */
export interface GetMsgHistoryOnlineCallback {
  (
    roomId: number, /** 聊天室 ID */
    errorCode: number, /** 返回错误码 */
    messages: Array<ChatRoomMessage> /** 消息列表 */
  ): void
}

/**
 * 聊天室成员类型枚举
 */
export enum NIMChatRoomMemberAttribute {
  kNIMChatRoomMemberAttributeAdminister = 1, /** 管理员,operator必须是创建者 */
  kNIMChatRoomMemberAttributeNomalMember = 2, /** 普通成员,operator必须是创建者或管理员 */
  kNIMChatRoomMemberAttributeBlackList = -1, /** 黑名单,operator必须是创建者或管理员 */
  kNIMChatRoomMemberAttributeMuteList = -2 /** 禁言,operator必须是创建者或管理员 */
}

/**
 * 设置聊天室成员类型的参数列表
 */
export interface ChatRoomSetMemberAttributeParameters {
  account_id: string, /** 成员ID */
  attribute: NIMChatRoomMemberAttribute, /** 身份标识 */
  opt: boolean, /** true:是,false:否 */
  notify_ext: string /** 通知的扩展字段, 必须为可以解析为Json的非格式化的字符串 */
}

/**
 * 聊天室成员信息变更回调模板
 */
export interface MemberInfoChangedCallback {
  (
    roomId: number, /** 聊天室 ID */
    errorCode: number, /** 返回错误码 */
    member: ChatRoomMemberInfo /** 聊天室成员信息 */
  ): void
}

/**
 * 获取聊天室信息回调模板
 */
export interface GetRoomInfoCallback {
  (
    roomId: number, /** 聊天室 ID */
    errorCode: number, /** 返回错误码 */
    info: ChatRoomInfo /** 聊天室信息 */
  ): void
}

/**
 * 基础回调模板，仅包含聊天室 ID 和状态码
 */
export interface ChatRoomBaseCallback {
  (
    roomId: number, /** 聊天室 ID */
    errorCode: number /** 返回错误码 */
  ): void
}

/**
 * 设置代理类型枚举
 */
export enum NIMChatRoomProxyType {
  kNIMChatRoomProxyNone = 0, /**  不使用代理 */
  kNIMChatRoomProxyHttp11 = 1, /**  HTTP 1.1 Proxy（暂不支持） */
  kNIMChatRoomProxySocks4 = 4, /**  Socks4 Proxy */
  kNIMChatRoomProxySocks4a = 5, /**  Socks4a Proxy */
  kNIMChatRoomProxySocks5 = 6, /**  Socks5 Proxy */
}

/**
 * 聊天室队列元素类型声明
 */
export interface ChatRoomQueueElement {
  key: string, /** 自定义 Key */
  value: string /** 自定义 Value */
}

/**
 * 拉取队列回调模板
 */
export interface QueuePollCalback {
  (
    roomId: number, /** 聊天室 ID */
    errorCode: number, /** 返回错误码 */
    element: ChatRoomQueueElement /** 队列中的单个元素信息 */
  ): void
}

/**
 * 获取队列列表回调模板
 */
export interface QueueListCallback {
  (
    roomId: number, /** 聊天室 ID */
    errorCode: number, /** 返回错误码 */
    elements: Array<ChatRoomQueueElement> /** 队列列表 */
  ): void
}

/**
 * 批量更新队列信息回调模板
 */
export interface QueueBatchUpdateCallback {
  (
    roomId: number, /** 聊天室 ID */
    errorCode: number, /** 返回错误码 */
    notInQueue: Array<string> /** 无效信息，未在队列列表的 Key */
  ): void
}

export interface NIMChatRoomAPI {
  Init(appInstallDir: string): boolean
  RegEnterCb(cb: NIMChatRoomEnterCallback, extension: string): void
  RegExitCbEx(cb: NIMChatRoomExitCallback, extension: string): void
  RegSendMsgAckCb(cb: NIMChatRoomSendMsgAckCallback, extension: string): void
  RegReceiveMsgCb(cb: NIMChatRoomReceiveMsgCallback, extension: string): void
  RegReceiveMsgsCb(cb: NIMChatRoomReceiveMsgsCallback, extension: string): void
  RegNotificationCb(cb: NIMChatRoomNotificationCallback, extension: string): void
  RegLinkConditionCb(cb: NIMChatRoomLinkConditionCallback, extension: string): void
  UnregChatroomCb(): void
  Enter(roomId: number, token: string, info: ChatRoomEnterInfo, extension: string): void
  IndependentEnterEx(roomId: number, independentEnterInfo: ChatRoomIndependentEnterInfo, config: string): void
  AnonymousEnterEx(roomId: number, anoymityEnterInfo: ChatRoomAnoymityEnterInfo, enterInfo: ChatRoomEnterInfo, config: string): void
  GetLoginState(roomId: number, extension: string): NIMChatRoomLoginState
  SetMsgsBatchReport(batch: boolean, extension: string): void
  SendMsg(roomId: number, message: ChatRoomMessage, extension: string): void
  GetMembersOnlineAsync(roomId: number, parameter: ChatRoomGetMembersParameters, cb: GetMemberOnlineCallback, extension: string): void
  GetMembersByTagOnlineAsync(roomId: number, parameter: ChatRoomGetMembersByTagParameters, cb: GetMemberOnlineCallback, extension: string): void
  GetMembersCountByTagOnlineAsync(roomId: number, tag: string, cb: GetMemberCountByTagCallback, extension: string): void
  GetMessageHistoryOnlineAsync(roomId: number, parameter: ChatRoomGetMsgHistoryParameters, cb: GetMsgHistoryOnlineCallback, extension: string): void
  SetMemberAttributeOnlineAsync(roomId: number, parameter: ChatRoomSetMemberAttributeParameters, cb: MemberInfoChangedCallback, extension: string): void
  GetInfoAsync(roomId: number, cb: GetRoomInfoCallback, extension: string): void
  GetMemberInfoByIDsAsync(roomId: number, accountIDs: Array<string>, cb: GetMemberOnlineCallback, extension: string): void
  KickMemberAsync(roomId: number, kickMemberId: string, notifyExtension: string, cb: ChatRoomBaseCallback, extension: string): void
  SetProxy(proxyType: NIMChatRoomProxyType, host: string, port: number, username: string, password: string): void
  TempMuteMemberAsync(roomId: number, accountId: string, duration: number, needsNotify: boolean, notifyExtension: string, cb: MemberInfoChangedCallback, extension: string): void
  TempMuteMemberByTagAsync(roomId: number, targetTag: string, duration: number, needsNotify: boolean, notifyExtension: string, cb: MemberInfoChangedCallback, extension: string): void
  UpdateRoomInfoAsync(roomId: number, info: ChatRoomInfo, needsNotify: boolean, notifyExtension: string, cb: ChatRoomBaseCallback, extension: string): void
  UpdateMyRoomRoleAsync(roomId: number, memberInfo: ChatRoomMemberInfo, needsNotify: boolean, notifyExtension: string, cb: ChatRoomBaseCallback, extension: string): void
  QueueOfferAsync(roomId: number, element: ChatRoomQueueElement, cb: ChatRoomBaseCallback, extension: string): void
  QueuePollAsync(roomId: number, elementKey: string, cb: QueuePollCalback, extension: string): void
  QueueListAsync(roomId: number, cb: QueueListCallback, extension: string): void
  QueueHeaderAsync(roomId: number, cb: QueuePollCalback, extension: string): void
  QueueDropAsync(roomId: number, cb: ChatRoomBaseCallback, extension: string): void
  QueueBatchUpdateAsync(roomId: number, elements: Array<ChatRoomQueueElement>, needsNotify: boolean, notifyExtension: string, cb: QueueBatchUpdateCallback, extension: string): void
  Exit(roomId: number, extension: string): void
  CleanUp(extension: string): void
}
