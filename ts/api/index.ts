import ev from 'events'
import instance from './nim_chatroom_bindings'
import {
  NIMChatRoomAPI,
  NIMChatRoomEnterCallback,
  ChatRoomEnterInfo,
  NIMChatRoomExitCallback,
  ChatRoomMessage,
  NIMChatRoomSendMsgAckCallback
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

  regSendMsgAckCb (cb: NIMChatRoomSendMsgAckCallback, jsonExtension: string) {
    this.chatroom.RegSendMsgAckCb(cb, '')
  }

  regExitCb (cb: NIMChatRoomExitCallback): void {
    this.chatroom.RegExitCbEx(cb, '')
  }

  enter (roomId: number, token: string, enterInfo: ChatRoomEnterInfo): void {
    this.chatroom.Enter(roomId, token, enterInfo, '')
  }

  sendMsg (roomId: number, message: ChatRoomMessage) {
    this.chatroom.SendMsg(roomId, message, '')
  }

  exit (roomId: number) {
    this.chatroom.Exit(roomId, '')
  }

  cleanUp () : void {
    return this.chatroom.CleanUp('')
  }
}

export default ChatRoom
