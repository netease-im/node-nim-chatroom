const assert = require('assert');
const NIMChatRoom = require('../build/Release/nim-chatroom')
const NIM = require('../build/Release/nim')


/**
 * NIM instance
 */
const client = new NIM.Client()
const session = new NIM.Session()
const talk = new NIM.Talk()
const msglog = new NIM.MsgLog()
const team = new NIM.Team()
const plugin = new NIM.PlugIn()

/**
 * ChatRoom instance
 */
const chatroom = new NIMChatRoom.ChatRoom()

const current = process.cwd()
process.chdir(`${current}/build/Release`)
console.log(`Current run path: ${process.cwd()} for NIM SDK`)

const gOperator = 'jiajia02'
const gRoomId = 2008
const gQueuHead = 'jiajia01'
let gMyRoomInfo

describe('NIM client startup', () => {
  describe('#Init', () => {
    it('Init NIM SDK should return 1', () => {
      const result = client.Init('', 'NIM_SDK_NODE_TEST', '', {})
      assert.strictEqual(result, 1)
    })
  })
  describe('#Login', () => {
    it('Login should return 200 at step 3', (done) => {
      client.Login('45c6af3c98409b18a84451215d0bdd6e', 'ljm2', 'e10adc3949ba59abbe56e057f20f883e', (loginResult) => {
        if (loginResult.login_step === 3) {
          done()
        }
      }, '')
    })
  })
})

describe('NIM test suite', () => {
  describe('Team suite', () => {
    describe('#UpdateTInfoLocal', () => {
      it('Update tinfo list should return sccuess 1, failed 0', (done) => {
        team.UpdateTInfoLocal([{
          tid: '3860273806',
          name: 'jiajia01 team',
          intro: 'Modified by NIM node addon test',
          announcement: 'Modified by NIM node addon test'
        }], (success, failed) => {
          assert.strictEqual(success.length, 1)
          assert.strictEqual(failed.length, 0)
          done()
        }, '')
      })
    })
  })

  describe('Talk suite', () => {
    let messageId
    describe('#SendMsg', () => {
      it('Send message should return 200', (done) => {
        talk.RegSendMsgCb((ack) => {
          messageId = ack.msg_id
          done()
        }, '')
        talk.SendMsg({
          to_type: 0,
          to_accid: 'jiajia02',
          time: new Date().getTime(),
          msg_type: 0,
          msg_body: 'Send from NIM node test.',
          client_msg_id: new Date().getTime().toString(),
        }, '', () => {

        })
      })
    })
    describe.skip('#QueryMsgByIDAysnc', () => {
      it('Reply message should return 200', (done) => {
        msglog.QueryMsgByIDAysnc(messageId, (errorCode, messageId, message) => {
          talk.ReplyMessage(message, {
            to_type: 0,
            to_accid: 'jiajia02',
            time: new Date().getTime(),
            msg_type: 0,
            msg_body: 'This is a reply message.',
            client_msg_id: new Date().getTime().toString(),
          })
          done()
        }, '')
      })
    })
  })

  describe('Stick top session suite', () => {
    describe('#SetToStickTopSession', () => {
      it('Set stick top session should return 200', (done) => {
        session.SetToStickTopSession(gOperator, 0, '', (errorCode, stickSessionInfo) => {
          assert.strictEqual(errorCode, 200)
          done()
        })
      })
    })
    describe('#UpdateToStickTopSession', () => {
      it('Update stick top session should return 200', (done) => {
        session.UpdateToStickTopSession(gOperator, 0, '', (errorCode, stickSessionInfo) => {
          assert.strictEqual(errorCode, 200)
          done()
        })
      })
    })
    describe('#QueryStickTopSessionList', () => {
      it('Query stick top session list should return 200 and list size > 0', (done) => {
        session.QueryStickTopSessionList((errorCode, stickSessionList) => {
          assert.strictEqual(errorCode, 200)
          assert.notStrictEqual(stickSessionList.length, 0)
          done()
        })
      })
    })
    describe('#CancelToStickTopSession', () => {
      it('Cancel stick top session should return 200', (done) => {
        session.CancelToStickTopSession(gOperator, 0, (errorCode, sessionId, sessionType) => {
          assert.strictEqual(errorCode, 200)
          assert.strictEqual(sessionId, gOperator)
          assert.strictEqual(sessionType, 0)
          done()
        })
      })
    })
  })

  describe('Roaming message suite', () => {
    describe('#DeleteSessionRoamingMessage', () => {
      it('Delete roaming should return 200', (done) => {
        const result = session.DeleteSessionRoamingMessage(gOperator, 0, (errorCode, sessionType, sessionId) => {
          assert.strictEqual(errorCode, 200)
          assert.strictEqual(sessionId, gOperator)
          assert.strictEqual(sessionType, 0)
          done()
        }, '')
        assert.strictEqual(result, true)
      })
    })
    describe('#SetMultiUnreadCountZeroAsync', () => {
      it('Set multi unread coung zero should return 200', (done) => {
        const result = session.SetMultiUnreadCountZeroAsync(false, [{
          id: gOperator,
          type: 0
        }], (errorCode, sessionList, unreadCount) => {
          assert.strictEqual(errorCode, 200)
          done()
        })
        assert.strictEqual(result, true)
      })
    })
    describe('#QueryHasmoreRoammsg', () => {
      it('Query session has more roaming msg should return 200', (done) => {
        session.QueryHasmoreRoammsg(gOperator, 0, (errorCode, info) => {
          done()
        })
      })
    })
    describe.skip('#SendMsg', () => {
      it('Send message should return 200', () => {
        talk.SendMsg({
          to_type: 0,
          to_accid: 'jiajia02',
          time: new Date().getTime(),
          msg_type: 0,
          msg_body: 'Send from NIM node test.',
          client_msg_id: new Date().getTime().toString(),
        }, '', () => {

        })
      })
    })
    describe('#UpdateHasmoreRoammsg', () => {
      it('Update session has more roaming msg should return 200', (done) => {
        msglog.QueryMsgAsync('jiajia02', 0, 1, 0, (errorCode, sessionId, sessionType, result) => {
          assert.strictEqual(errorCode, 200)
          const message = result.content[0]
          session.UpdateHasmoreRoammsg(message, (errorCode) => {
            assert.strictEqual(errorCode, 200)
            done()
          })
        }, '')
      })
    })
    describe('#QueryAllHasmoreRoammsg', () => {
      it('Query all session roaming msg should return 200', (done) => {
        session.QueryAllHasmoreRoammsg((errorCode, infos) => {
          assert.strictEqual(errorCode, 200)
          done()
        })
      })
    })
    describe('#DeleteHasmoreRoammsg', () => {
      it('Delete has more roam msg should return 200', (done) => {
        session.DeleteHasmoreRoammsg(gOperator, 0, (errorCode) => {
          assert.strictEqual(errorCode, 200)
          done()
        })
      })
    })
  })
})

describe('NIMChatRoom Test Suite', () => {
  describe('#Init', () => {
    it('Init should return 1', () => {
      const result = chatroom.Init('')
      assert.strictEqual(result, 1)
    })
  })
  describe('#ChatRoomRequestEnterAsync', () => {
    it('Enter chatroom should return 200 at step 5', (done) => {
      chatroom.RegEnterCb((roomId, step, errorCode, info, myInfo) => {
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
        if (errorCode === 200 && step === 5) {
          gMyRoomInfo = myInfo
          done()
        } else if (errorCode != 200 && step === 5) {
          done(errorCode)
        }
      }, '')
      // Get enter token for enter chatroom
      plugin.ChatRoomRequestEnterAsync(gRoomId, (errorCode, enterToken) => {
        assert.strictEqual(errorCode, 200)
        chatroom.Enter(gRoomId, enterToken, {
          nick: 'ljm2_node_test',
          avatar: 'https://yunxin.163.com/',
          login_tags: ['abc', 'def', 'ghi']
        }, '')
      }, '')
    })
  })
  describe('#GetLoginState', () => {
    it('Get login state should return 1 when entered room', () => {
      assert.strictEqual(chatroom.GetLoginState(gRoomId, ''), 1)
    })
  })
  describe.skip('#SendMsg', () => {
    it('Send message ack should return 200', (done) => {
      chatroom.RegSendMsgAckCb((roomId, errorCode, result) => {
        console.log(errorCode, JSON.stringify(result))
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
        if (errorCode === 200)
          done()
        else
          done(errorCode)
      }, '')
      chatroom.SendMsg(gRoomId, {
        msg_type: 0,
        msg_attach: 'This is attach of message',
        body: 'This is body of message',
        client_msg_id: new Date().getTime().toString(),
        resend_flag: false,
        ext: '',
        anti_spam_enable: false,
        anti_spam_content: '',
        history_save: false,
        anti_spam_using_yidun: 1,
      }, '')
    })
  })
  describe('#GetMembersOnlineAsync', () => {
    it('Get members should return 200', (done) => {
      chatroom.GetMembersOnlineAsync(gRoomId, {
        type: 0,
        offset: 0,
        limit: 10
      }, (roomId, errorCode, members) => {
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
        assert.notStrictEqual(members.length, 0)
        done()
      }, '')
    })
  })
  describe('#GetMembersByTagOnlineAsync', () => {
    it('Get members by tag online should return 200 with specified tag', (done) => {
      chatroom.GetMembersByTagOnlineAsync(gRoomId, {
        tag: 'abc',
        offset: 0,
        limit: 10
      }, (roomId, errorCode, members) => {
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
        assert.notStrictEqual(members.length, 0)
        for (let j = 0; j < members.length; j++) {
          const memberTags = JSON.parse(members[j].tags)
          let foundTag = false
          for (let i = 0; i < memberTags.length; i++) {
            if (memberTags[i] === 'abc')
              foundTag = true
          }
          assert.strictEqual(foundTag, true)
        }
        done()
      }, '')
    })
  })
  describe('#GetMessageHistoryOnlineAsync', () => {
    it('Get message history online should return 200', (done) => {
      chatroom.GetMessageHistoryOnlineAsync(gRoomId, {
        start: 0,
        limit: 10,
        reverse: false,
        msgtypes: [0, 1, 2]
      }, (roomId, errorCode, messages) => {
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
        assert.notStrictEqual(messages.length, 0)
        done()
      }, '')
    })
  })
  describe('#SetMemberAttributeOnlineAsync', () => {
    it('Set member attribute as -1 should return 200 and member type should return -1', (done) => {
      chatroom.SetMemberAttributeOnlineAsync(gRoomId, {
        account_id: 'jiajia01',
        attribute: -1
      }, (roomId, errorCode, memberInfo) => {
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
      }, '')
      setTimeout(() => {
        chatroom.GetMemberInfoByIDsAsync(gRoomId, ['jiajia01'], (roomId, errorCode, members) => {
          JSON.stringify(members)
          assert.strictEqual(errorCode, 200)
          assert.strictEqual(roomId, gRoomId)
          assert.notStrictEqual(members.length, 0)
          assert.strictEqual(members[0].type, -1)
          done()
        }, '')
      }, 1000)
    }, 4000)
  })
  describe('#SetMemberAttributeOnlineAsync', () => {
    it('Set member attribute as 1 should return 200 and member type should return 2', (done) => {
      chatroom.SetMemberAttributeOnlineAsync(gRoomId, {
        account_id: 'jiajia01',
        attribute: 1
      }, (roomId, errorCode, memberInfo) => {
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
      }, '')
      setTimeout(() => {
        chatroom.GetMemberInfoByIDsAsync(gRoomId, ['jiajia01'], (roomId, errorCode, members) => {
          assert.strictEqual(errorCode, 200)
          assert.strictEqual(roomId, gRoomId)
          assert.notStrictEqual(members.length, 0)
          assert.strictEqual(members[0].type, 2)
          done()
        }, '')
      }, 1000)
    }, 4000)
  })
  describe('#GetInfoAsync', () => {
    it('Get room info should return room ID 2008', (done) => {
      chatroom.GetInfoAsync(gRoomId, (roomId, errorCode, info) => {
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
        assert.strictEqual(info.room_id, 2008)
        done()
      }, '')
    })
  })
  describe('#KickMemberAsync', () => {
    it('Kick member should return 404', (done) => {
      chatroom.KickMemberAsync(gRoomId, 'jiajia02', '', (roomId, errorCode) => {
        assert.strictEqual(errorCode, 404)
        assert.strictEqual(roomId, gRoomId)
        done()
      }, '')
    })
  })
  describe('#SetProxy', () => {
    it('Set proxy has no return value', () => {
      chatroom.SetProxy(6, '127.0.0.1', 1080, '', '')
    })
  })
  describe('#TempMuteMemberAsync', () => {
    it('Mute member should return 200', (done) => {
      chatroom.TempMuteMemberAsync(gRoomId, 'jiajia01', 10, true, 'notify ext content', (roomId, errorCode, member) => {
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
        assert.strictEqual(member.account_id, 'jiajia01')
        done()
      }, '')
    })
  })
  describe('Mute member by tag async', () => {
    it('Mute member by tag should return 200', (done) => {
      chatroom.TempMuteMemberByTagAsync(gRoomId, 'abc', 10, true, 'notify ext content', (roomId, errorCode, member) => {
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
        done()
      }, '')
    })
  })
  describe('#UpdateRoomInfoAsync', () => {
    it('Update room info should return 200', (done) => {
      chatroom.UpdateRoomInfoAsync(gRoomId, {
        id: gRoomId,
        name: 'Modified by Dylan',
        announcement: 'New announcement modified by Dylan',
        broadcast_url: '',
        mute_all: false,
        queuelevel: 1
      }, true, 'Modify chatroom info by Dylan', (roomId, errorCode) => {
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
        done()
      }, '')
    })
  })
  describe('#UpdateMyRoomRoleAsync', () => {
    it('Update my room role should return 200', (done) => {
      gMyRoomInfo.nick = new Date().toString()
      gMyRoomInfo.avatar = new Date().toString()
      chatroom.UpdateMyRoomRoleAsync(gRoomId, gMyRoomInfo, true, "Notify ext content", (roomId, errorCode) => {
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
        done()
      }, '')
    })
  })
  describe('#QueueOfferAsync', () => {
    it('Queue offer async should return 200', (done) => {
      chatroom.QueueOfferAsync(gRoomId, {
        key: gQueuHead,
        value: '0'
      }, (roomId, errorCode) => {
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
        done()
      }, '')
    })
  })
  describe('#QueueListAsync', () => {
    it(`Queue list async shoud return 200 with key ${gQueuHead}`, (done) => {
      chatroom.QueueListAsync(gRoomId, (roomId, errorCode, list) => {
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
        let foundMember = false
        list.map((element) => {
          if (element.key === gQueuHead) {
            foundMember = true
          }
        })
        assert.strictEqual(foundMember, true)
        done()
      }, '')
    })
  })
  describe('#QueueHeaderAsync', () => {
    it('Queue header async should return 200', (done) => {
      chatroom.QueueHeaderAsync(gRoomId, (roomId, errorCode, element) => {
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
        assert.strictEqual(element.key, gQueuHead)
        done()
      }, '')
    })
  })
  describe('#QueueBatchUpdateAsync', () => {
    it('Queue batch update should return 200', (done) => {
      chatroom.QueueBatchUpdateAsync(gRoomId, [{
        key: gQueuHead,
        value: '100'
      }, {
        key: 'jiajia02',
        value: '200'
      }], true, "notify ext content", (roomId, errorCode, notInQueueList) => {
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
        let found = false
        notInQueueList.map((element) => {
          if (element === 'jiajia02') {
            found = true
          }
        })
        assert.strictEqual(found, true)
        done()
      }, '')
    })
  })
  describe('#QueueDropAsync', () => {
    it('Queue drop async should return 200', (done) => {
      chatroom.QueueDropAsync(gRoomId, (roomId, errorCode) => {
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
        done()
      }, '')
    })
  })
  describe.skip('#QueueOfferAsync', () => {
    it('Queue poll async should return 200', (done) => {
      chatroom.QueueOfferAsync(gRoomId, gQueuHead, (roomId, errorCode, element) => {
        console.log(roomId, errorCode)
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
        done()
      }, '')
    })
  })
  describe.skip('#RegExitCb', () => {
    it('Exit room should return 200 with room ID 2008 and reason 0', (done) => {
      chatroom.RegExitCb((roomId, errorCode, reason) => {
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(roomId, gRoomId)
        if (reason === 0)
          done()
        else
          done(reason)
      }, '')
      chatroom.Exit(gRoomId, '')
    })
  })
  describe('#RegExitCbEx', () => {
    it('Exit room should return 200 with room ID 2008 and reason 0', (done) => {
      setTimeout(() => {
        chatroom.RegExitCbEx((roomId, errorCode, info) => {
          assert.strictEqual(errorCode, 200)
          assert.strictEqual(roomId, gRoomId)
          if (info.reason === 0)
            done()
          else
            done(info.reason)
        }, '')
        chatroom.Exit(gRoomId, '')
      })
    })
  })
  describe('#ChatRoom::CleanUp', () => {
    it('Cleanup test', () => {
      chatroom.CleanUp('')
    })
  })
})

describe('#Logout', () => {
  describe('Logout from NIM SDK', () => {
    it('Logout should return 1', (done) => {
      client.Logout(1, (errorCode) => {
        assert.strictEqual(errorCode, 200)
        done()
      }, '')
    })
  })
  describe('#CleanUp', () => {
    it('Cleanup SDK has not return value', (done) => {
      client.CleanUp('')
      done()
      setTimeout(() => {
        process.exit(0)
      }, 1000)
    })
  })
})
