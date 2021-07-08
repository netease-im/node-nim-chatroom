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
  constructor () {
    super()
    this.chatroom = new instance.ChatRoom()
  }

  init (appInstallDir: string): boolean {
    return this.chatroom.Init(appInstallDir)
  }

  regEnterCb (cb: NIMChatRoomEnterCallback): void {
    this.chatroom.RegEnterCb(cb, '')
  }

  regExitCb (cb: NIMChatRoomExitCallback): void {
    this.chatroom.RegExitCbEx(cb, '')
  }

  regSendMsgAckCb (cb: NIMChatRoomSendMsgAckCallback): void {
    this.chatroom.RegSendMsgAckCb(cb, '')
  }

  regReceiveMsgCb (cb: NIMChatRoomReceiveMsgCallback): void {
    this.chatroom.RegReceiveMsgCb(cb, '')
  }

  regReceiveMsgsCb (cb: NIMChatRoomReceiveMsgsCallback): void {
    this.chatroom.RegReceiveMsgsCb(cb, '')
  }

  regNotificationCb (cb: NIMChatRoomNotificationCallback): void {
    this.chatroom.RegNotificationCb(cb, '')
  }

  regLinkConditionCb (cb: NIMChatRoomLinkConditionCallback): void {
    this.chatroom.RegLinkConditionCb(cb, '')
  }

  unregChatroomCb (): void {
    this.chatroom.UnregChatroomCb()
  }

  enter (roomId: number, token: string, enterInfo: ChatRoomEnterInfo): void {
    this.chatroom.Enter(roomId, token, enterInfo, '')
  }

  independentEnter (roomId: number, independentEnterInfo: ChatRoomIndependentEnterInfo, config: string): void {
    this.chatroom.IndependentEnterEx(roomId, independentEnterInfo, config)
  }

  anonymousEnter (roomId: number, anoymityEnterInfo: ChatRoomAnoymityEnterInfo, enterInfo: ChatRoomEnterInfo, config: string): void {
    this.chatroom.AnonymousEnterEx(roomId, anoymityEnterInfo, enterInfo, config)
  }

  getLoginState (roomId: number): NIMChatRoomLoginState {
    return this.chatroom.GetLoginState(roomId, '')
  }

  setMsgsBatchReport (batch: boolean): void {
    this.chatroom.SetMsgsBatchReport(batch, '')
  }

  sendMsg (roomId: number, message: ChatRoomMessage): void {
    this.chatroom.SendMsg(roomId, message, '')
  }

  getMembersOnlineAsync (roomId: number, parameter: ChatRoomGetMembersParameters, cb: GetMemberOnlineCallback): void {
    this.chatroom.GetMembersOnlineAsync(roomId, parameter, cb, '')
  }

  getMembersCountByTagOnlineAsync (roomId: number, tag: string, cb: GetMemberCountByTagCallback): void {
    this.chatroom.GetMembersCountByTagOnlineAsync(roomId, tag, cb, '')
  }

  getMessageHistoryOnlineAsync (roomId: number, parameter: ChatRoomGetMsgHistoryParameters, cb: GetMsgHistoryOnlineCallback): void {
    this.chatroom.GetMessageHistoryOnlineAsync(roomId, parameter, cb, '')
  }

  setMemberAttributeOnlineAsync (roomId: number, parameter: ChatRoomSetMemberAttributeParameters, cb: MemberInfoChangedCallback): void {
    this.chatroom.SetMemberAttributeOnlineAsync(roomId, parameter, cb, '')
  }

  getInfoAsync (roomId: number, cb: GetRoomInfoCallback): void {
    this.chatroom.GetInfoAsync(roomId, cb, '')
  }

  getMemberInfoByIDsAsync (roomId: number, accountIDs: Array<string>, cb: GetMemberOnlineCallback): void {
    this.chatroom.GetMemberInfoByIDsAsync(roomId, accountIDs, cb, '')
  }

  kickMemberAsync (roomId: number, kickMemberId: string, notifyExtension: string, cb: ChatRoomBaseCallback): void {
    this.chatroom.KickMemberAsync(roomId, kickMemberId, notifyExtension, cb, '')
  }

  setProxy (proxyType: NIMChatRoomProxyType, host: string, port: number, username: string, password: string): void {
    this.chatroom.SetProxy(proxyType, host, port, username, password)
  }

  tempMuteMemberAsync (roomId: number, accountId: string, duration: number, needsNotify: boolean, notifyExtension: string, cb: MemberInfoChangedCallback): void {
    this.chatroom.TempMuteMemberAsync(roomId, accountId, duration, needsNotify, notifyExtension, cb, '')
  }

  tempMuteMemberByTagAsync (roomId: number, targetTag: string, duration: number, needsNotify: boolean, notifyExtension: string, cb: MemberInfoChangedCallback): void {
    this.chatroom.TempMuteMemberByTagAsync(roomId, targetTag, duration, needsNotify, notifyExtension, cb, '')
  }

  updateRoomInfoAsync (roomId: number, info: ChatRoomInfo, needsNotify: boolean, notifyExtension: string, cb: ChatRoomBaseCallback): void {
    this.chatroom.UpdateRoomInfoAsync(roomId, info, needsNotify, notifyExtension, cb, '')
  }

  updateMyRoomRoleAsync (roomId: number, memberInfo: ChatRoomMemberInfo, needsNotify: boolean, notifyExtension: string, cb: ChatRoomBaseCallback): void {
    this.chatroom.UpdateMyRoomRoleAsync(roomId, memberInfo, needsNotify, notifyExtension, cb, '')
  }

  queueOfferAsync (roomId: number, element: ChatRoomQueueElement, cb: ChatRoomBaseCallback): void {
    this.chatroom.QueueOfferAsync(roomId, element, cb, '')
  }

  queuePollAsync (roomId: number, elementKey: string, cb: QueuePollCalback): void {
    this.chatroom.QueuePollAsync(roomId, elementKey, cb, '')
  }

  queueListAsync (roomId: number, cb: QueueListCallback): void {
    this.chatroom.QueueListAsync(roomId, cb, '')
  }

  queueHeaderAsync (roomId: number, cb: QueuePollCalback): void {
    this.chatroom.QueueHeaderAsync(roomId, cb, '')
  }

  queueDropAsync (roomId: number, cb: ChatRoomBaseCallback): void {
    this.chatroom.QueueDropAsync(roomId, cb, '')
  }

  queueBatchUpdateAsync(roomId: number, elements: Array<ChatRoomQueueElement>, needsNotify: boolean, notifyExtension: string, cb: QueueBatchUpdateCallback): void {
    this.chatroom.QueueBatchUpdateAsync(roomId, elements, needsNotify, notifyExtension, cb, '')
  }

  exit (roomId: number): void {
    this.chatroom.Exit(roomId, '')
  }

  cleanUp () : void {
    return this.chatroom.CleanUp('')
  }
}

export default ChatRoom
