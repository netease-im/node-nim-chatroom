import ev from 'events'
import instance from './nim_chatroom_bindings'
import {
  NIMChatRoomAPI,
  NIMChatRoomEnterCallback,
  ChatRoomEnterInfo,
  NIMChatRoomLoginState,
  NIMChatRoomExitCallback,
  ChatRoomMessage,
  NIMChatRoomSendMsgAckCallback,
  NIMChatRoomReceiveMsgCallback,
  NIMChatRoomReceiveMsgsCallback,
  NIMChatRoomNotificationCallback,
  NIMChatRoomLinkConditionCallback,
  ChatRoomIndependentEnterInfo,
  ChatRoomAnoymityEnterInfo,
  ChatRoomGetMembersParameters,
  GetMemberOnlineCallback,
  ChatRoomGetMembersByTagParameters,
  GetMemberCountByTagCallback,
  ChatRoomGetMsgHistoryParameters,
  GetMsgHistoryOnlineCallback,
  ChatRoomSetMemberAttributeParameters,
  MemberInfoChangedCallback,
  GetRoomInfoCallback,
  ChatRoomBaseCallback,
  NIMChatRoomProxyType,
  ChatRoomInfo,
  ChatRoomMemberInfo,
  ChatRoomQueueElement,
  QueuePollCalback,
  QueueListCallback,
  QueueBatchUpdateCallback
} from './nim_chatroom_def'

class ChatRoom extends ev.EventEmitter {
  chatroom: NIMChatRoomAPI

  /**
   * NIM chatroom 类构造函数
   * @return void
   */
  constructor () {
    super()
    this.chatroom = new instance.ChatRoom()
  }

  /**
   * 聊天室模块初始化(SDK初始化时调用一次)
   * @param  {string} appInstallDir SDK动态库所在的目录全路径（如果传入为空，则按照默认规则搜索该动态库）
   * @returns boolean 模块加载结果，true 为加载成功，false 为失败
   */
  init (appInstallDir: string): boolean {
    return this.chatroom.Init(appInstallDir)
  }

  /**
   * 注册全局登录回调
   * @param  {NIMChatRoomEnterCallback} cb 回调函数
   * @returns void 无返回值
   */
  regEnterCb (cb: NIMChatRoomEnterCallback): void {
    this.chatroom.RegEnterCb(cb, '')
  }

  /**
   * 注册全局登出、被踢回调
   * @param  {NIMChatRoomExitCallback} cb 回调函数
   * @returns void 无返回值
   */
  regExitCb (cb: NIMChatRoomExitCallback): void {
    this.chatroom.RegExitCbEx(cb, '')
  }

  /**
   * 注册全局发送消息回执回调
   * @param  {NIMChatRoomSendMsgAckCallback} cb 回调函数
   * @returns void 无返回值
   */
  regSendMsgAckCb (cb: NIMChatRoomSendMsgAckCallback): void {
    this.chatroom.RegSendMsgAckCb(cb, '')
  }

  /**
   * 注册全局接收消息回调
   * @param  {NIMChatRoomReceiveMsgCallback} cb 回调函数
   * @returns void 无返回值
   */
  regReceiveMsgCb (cb: NIMChatRoomReceiveMsgCallback): void {
    this.chatroom.RegReceiveMsgCb(cb, '')
  }

  /**
   * 注册全局接收批量消息回调
   * @param  {NIMChatRoomReceiveMsgsCallback} cb 回调函数
   * @returns void 无返回值
   */
  regReceiveMsgsCb (cb: NIMChatRoomReceiveMsgsCallback): void {
    this.chatroom.RegReceiveMsgsCb(cb, '')
  }

  /**
   * 注册全局接收通知回调
   * @param  {NIMChatRoomNotificationCallback} cb 回调函数
   * @returns void 无返回值
   */
  regNotificationCb (cb: NIMChatRoomNotificationCallback): void {
    this.chatroom.RegNotificationCb(cb, '')
  }

  /**
   * 注册全局聊天室链接情况回调
   * @param  {NIMChatRoomLinkConditionCallback} cb 回调函数
   * @returns void 无返回值
   */
  regLinkConditionCb (cb: NIMChatRoomLinkConditionCallback): void {
    this.chatroom.RegLinkConditionCb(cb, '')
  }

  /**
   * 反注册在 Chatroom 中注册的所有回调
   * @returns void 无返回值
   */
  unregChatroomCb (): void {
    this.chatroom.UnregChatroomCb()
  }

  /**
   * 加入聊天室
   * @param  {number} roomId 聊天室ID
   * @param  {string} token 聊天室登录信息(NIM SDK 请求聊天室返回的数据)
   * @param  {ChatRoomEnterInfo} enterInfo 聊天室可选信息
   * @returns void 无返回值
   */
  enter (roomId: number, token: string, enterInfo: ChatRoomEnterInfo): void {
    this.chatroom.Enter(roomId, token, enterInfo, '')
  }

  /**
   * 使用自定义聊天室地址进入
   * @param  {number} roomId
   * @param  {ChatRoomIndependentEnterInfo} independentEnterInfo 聊天室进入信息
   * @param  {string} config 聊天室配置对象
   * @returns void 无返回值
   */
  independentEnter (roomId: number, independentEnterInfo: ChatRoomIndependentEnterInfo, config: string): void {
    this.chatroom.IndependentEnterEx(roomId, independentEnterInfo, config)
  }

  /**
   * 匿名方式加入聊天室
   * @param  {number} roomId 聊天室ID
   * @param  {ChatRoomAnoymityEnterInfo} anoymityEnterInfo 匿名登录相关信息
   * @param  {ChatRoomEnterInfo} enterInfo 聊天室进入信息
   * @param  {string} config 聊天室配置对象
   * @returns void 无返回值
   */
  anonymousEnter (roomId: number, anoymityEnterInfo: ChatRoomAnoymityEnterInfo, enterInfo: ChatRoomEnterInfo, config: string): void {
    this.chatroom.AnonymousEnterEx(roomId, anoymityEnterInfo, enterInfo, config)
  }

  /**
   * 获取当前已经加入的聊天室状态
   * @param  {number} roomId 聊天室ID
   * @returns NIMChatRoomLoginState 当前是否已经加入房间的状态
   */
  getLoginState (roomId: number): NIMChatRoomLoginState {
    return this.chatroom.GetLoginState(roomId, '')
  }

  /** 设置消息接收批量上报开关
   * @param  {boolean} batch 批量开关 true 为开启，false 为关闭
   * @returns void 无返回值
   */
  setMsgsBatchReport (batch: boolean): void {
    this.chatroom.SetMsgsBatchReport(batch, '')
  }

  /**
   * 发送消息
   * @param  {number} roomId 聊天室ID
   * @param  {ChatRoomMessage} message 消息内容，见 ChatRoomMessage 声明
   * @returns void 无返回值
   */
  sendMsg (roomId: number, message: ChatRoomMessage): void {
    this.chatroom.SendMsg(roomId, message, '')
  }

  /**
   * 异步查询成员列表
   * @param  {number} roomId 聊天室ID
   * @param  {ChatRoomGetMembersParameters} parameter 查询茶树
   * @param  {GetMemberOnlineCallback} cb 回调函数
   * @returns void 无返回值
   */
  getMembersOnline (roomId: number, parameter: ChatRoomGetMembersParameters, cb: GetMemberOnlineCallback): void {
    this.chatroom.GetMembersOnlineAsync(roomId, parameter, cb, '')
  }

  /**
   * 根据 tag 异步查询聊天室成员列表
   * @param  {number} roomId 聊天室ID
   * @param  {ChatRoomGetMembersByTagParameters} parameter 查询参数
   * @param  {GetMemberOnlineCallback} cb 回调函数
   * @param  {string} extension
   * @returns void
   */
  getMembersByTagOnline (roomId: number, parameter: ChatRoomGetMembersByTagParameters, cb: GetMemberOnlineCallback): void {
    this.chatroom.GetMembersByTagOnlineAsync(roomId, parameter, cb, '')
  }

  /**
   * 获取聊天室内指定 tag 的成员数量
   * @param  {number} roomId 聊天室ID
   * @param  {string} tag 要查询的 tag 字符串
   * @param  {GetMemberCountByTagCallback} cb 回调函数
   * @returns void 无返回值
   */
  getMembersCountByTagOnline (roomId: number, tag: string, cb: GetMemberCountByTagCallback): void {
    this.chatroom.GetMembersCountByTagOnlineAsync(roomId, tag, cb, '')
  }

  /**
   * 异步查询消息历史
   * @param  {number} roomId 聊天室ID
   * @param  {ChatRoomGetMsgHistoryParameters} parameter 查询参数
   * @param  {GetMsgHistoryOnlineCallback} cb 回调函数
   * @returns void 无返回值
   */
  getMessageHistoryOnline (roomId: number, parameter: ChatRoomGetMsgHistoryParameters, cb: GetMsgHistoryOnlineCallback): void {
    this.chatroom.GetMessageHistoryOnlineAsync(roomId, parameter, cb, '')
  }

  /**
   * 异步设置成员身份标识
   * @param  {number} roomId 聊天室ID
   * @param  {ChatRoomSetMemberAttributeParameters} parameter 查询参数
   * @param  {MemberInfoChangedCallback} cb 回调函数
   * @returns void 无返回值
   */
  setMemberAttributeOnline (roomId: number, parameter: ChatRoomSetMemberAttributeParameters, cb: MemberInfoChangedCallback): void {
    this.chatroom.SetMemberAttributeOnlineAsync(roomId, parameter, cb, '')
  }

  /**
   * 异步获取当前聊天室信息
   * @param  {number} roomId 聊天室ID
   * @param  {GetRoomInfoCallback} cb 回调函数
   * @returns void 无返回值
   */
  getInfo (roomId: number, cb: GetRoomInfoCallback): void {
    this.chatroom.GetInfoAsync(roomId, cb, '')
  }

  /**
   * 异步获取指定成员信息
   * @param  {number} roomId 聊天室ID
   * @param  {Array<string>} accountIDs 要获取的成员 ID 信息列表
   * @param  {GetMemberOnlineCallback} cb 回调函数
   * @returns void 无返回值
   */
  getMemberInfoByIDs (roomId: number, accountIDs: Array<string>, cb: GetMemberOnlineCallback): void {
    this.chatroom.GetMemberInfoByIDsAsync(roomId, accountIDs, cb, '')
  }

  /**
   * 异步踢掉指定成员
   * @param  {number} roomId 聊天室ID
   * @param  {string} kickMemberId 要踢出的成员 ID
   * @param  {string} notifyExtension 放到事件通知中的扩展字段
   * @param  {ChatRoomBaseCallback} cb 回调函数
   * @returns void 无返回值
   */
  kickMember (roomId: number, kickMemberId: string, notifyExtension: string, cb: ChatRoomBaseCallback): void {
    this.chatroom.KickMemberAsync(roomId, kickMemberId, notifyExtension, cb, '')
  }

  /**
   * 设置 SDK 统一的网络代理，不需要代理时，type 设置为 kNIMProxyNone，其余参数都传空字符串（端口设为0）。有些代理不需要用户名和密码，相应参数也传空字符串。
   * @param  {NIMChatRoomProxyType} proxyType 代理类型，见 NIMChatRoomProxyType 定义
   * @param  {string} host 代理地址
   * @param  {number} port 代理端口
   * @param  {string} username 代理用户名
   * @param  {string} password 代理密码
   * @returns void 无返回值
   */
  setProxy (proxyType: NIMChatRoomProxyType, host: string, port: number, username: string, password: string): void {
    this.chatroom.SetProxy(proxyType, host, port, username, password)
  }

  /**
   * 异步临时禁言/解禁成员
   * @param  {number} roomId 聊天室ID
   * @param  {string} accountId 成员ID
   * @param  {number} duration 临时禁言时长（秒），解禁填 0
   * @param  {boolean} needsNotify 是否聊天室内广播通知
   * @param  {string} notifyExtension 通知中的自定义字段，长度限制 2048
   * @param  {MemberInfoChangedCallback} cb 回调函数
   * @returns void 无返回值
   */
  tempMuteMember (roomId: number, accountId: string, duration: number, needsNotify: boolean, notifyExtension: string, cb: MemberInfoChangedCallback): void {
    this.chatroom.TempMuteMemberAsync(roomId, accountId, duration, needsNotify, notifyExtension, cb, '')
  }

  /**
   * 异步根据 tag 临时禁言/解禁成员
   * @param  {number} roomId 聊天室ID
   * @param  {string} targetTag 要禁言的指定 tag
   * @param  {number} duration 临时禁言时长（秒），解禁填0
   * @param  {boolean} needsNotify 是否聊天室内广播通知
   * @param  {string} notifyExtension 通知中的自定义字段，长度限制 2048
   * @param  {MemberInfoChangedCallback} cb 回调函数
   * @returns void 无返回值
   */
  tempMuteMemberByTag (roomId: number, targetTag: string, duration: number, needsNotify: boolean, notifyExtension: string, cb: MemberInfoChangedCallback): void {
    this.chatroom.TempMuteMemberByTagAsync(roomId, targetTag, duration, needsNotify, notifyExtension, cb, '')
  }

  /**
   * 更新聊天室信息
   * @param  {number} roomId 聊天室ID
   * @param  {ChatRoomInfo} info 聊天室信息
   * @param  {boolean} needsNotify 是否聊天室内广播通知
   * @param  {string} notifyExtension 通知中的自定义字段，长度限制 2048
   * @param  {ChatRoomBaseCallback} cb 回调函数
   * @returns void 无返回值
   */
  updateRoomInfo (roomId: number, info: ChatRoomInfo, needsNotify: boolean, notifyExtension: string, cb: ChatRoomBaseCallback): void {
    this.chatroom.UpdateRoomInfoAsync(roomId, info, needsNotify, notifyExtension, cb, '')
  }

  /**
   * 更新我的信息
   * @param  {number} roomId 聊天室ID
   * @param  {ChatRoomMemberInfo} memberInfo 我的信息
   * @param  {boolean} needsNotify 是否聊天室内广播通知
   * @param  {string} notifyExtension 通知中的自定义字段，长度限制 2048
   * @param  {ChatRoomBaseCallback} cb 回调函数
   * @returns void 无返回值
   */
  updateMyRoomRole (roomId: number, memberInfo: ChatRoomMemberInfo, needsNotify: boolean, notifyExtension: string, cb: ChatRoomBaseCallback): void {
    this.chatroom.UpdateMyRoomRoleAsync(roomId, memberInfo, needsNotify, notifyExtension, cb, '')
  }

  /**
   * 新加(更新)麦序队列元素，如果 element.key 对应的元素已经在队列中存在了，则执行更新操作，如果不存在，则放入队列尾部
   * @param  {number} roomId 聊天室ID
   * @param  {ChatRoomQueueElement} element 麦序队列元素
   * @param  {ChatRoomBaseCallback} cb 回调函数
   * @returns void 无返回值
   */
  queueOffer (roomId: number, element: ChatRoomQueueElement, cb: ChatRoomBaseCallback): void {
    this.chatroom.QueueOfferAsync(roomId, element, cb, '')
  }

  /**
   * 取出麦序元素
   * @param  {number} roomId 聊天室ID
   * @param  {string} elementKey 需要取出的元素的 UniqKey, 传空传表示取出第一个元素
   * @param  {QueuePollCalback} cb 回调函数
   * @returns void 无返回值
   */
  queuePoll (roomId: number, elementKey: string, cb: QueuePollCalback): void {
    this.chatroom.QueuePollAsync(roomId, elementKey, cb, '')
  }

  /**
   * 排序列出所有元素
   * @param  {number} roomId 聊天室ID
   * @param  {QueueListCallback} cb 回调函数
   * @returns void 无返回值
   */
  queueList (roomId: number, cb: QueueListCallback): void {
    this.chatroom.QueueListAsync(roomId, cb, '')
  }

  /**
   * 查看麦序头元素
   * @param  {number} roomId 聊天室ID
   * @param  {QueuePollCalback} cb 回调函数
   * @returns void 无返回值
   */
  queueHeader (roomId: number, cb: QueuePollCalback): void {
    this.chatroom.QueueHeaderAsync(roomId, cb, '')
  }

  /**
   * (管理员权限)删除麦序队列
   * @param  {number} roomId 聊天室ID
   * @param  {ChatRoomBaseCallback} cb 回调函数
   * @returns void 无返回值
   */
  queueDrop (roomId: number, cb: ChatRoomBaseCallback): void {
    this.chatroom.QueueDropAsync(roomId, cb, '')
  }

  /**
   * 批量更新聊天室排序队列信息
   * @param  {number} roomId 聊天室ID
   * @param  {Array<ChatRoomQueueElement>} elements 所有需要更新的列表
   * @param  {boolean} needsNotify 是否聊天室内广播通知
   * @param  {string} notifyExtension 通知中的自定义字段，长度限制 2048
   * @param  {QueueBatchUpdateCallback} cb 回调函数
   * @returns void 无返回值
   */
  queueBatchUpdate (roomId: number, elements: Array<ChatRoomQueueElement>, needsNotify: boolean, notifyExtension: string, cb: QueueBatchUpdateCallback): void {
    this.chatroom.QueueBatchUpdateAsync(roomId, elements, needsNotify, notifyExtension, cb, '')
  }

  /**
   * 聊天室登出
   * @param  {number} roomId 聊天室ID
   * @returns void 无返回值
   */
  exit (roomId: number): void {
    this.chatroom.Exit(roomId, '')
  }

  /**
   * 聊天室模块清理(SDK 卸载前调用一次)
   * @returns void 无返回值
   */
  cleanUp () : void {
    return this.chatroom.CleanUp('')
  }
}

export default ChatRoom
