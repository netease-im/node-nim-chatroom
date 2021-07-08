const assert = require('assert')
const NIMChatRoomSDK = require('../js/nim_chatroom').default

const instance = new NIMChatRoomSDK.ChatRoom()

const globalRoomId = 2008
const globalToken = '2b5b639b0caee2c85370304fa76909d43a3773358d0295a87a7ac161e772a2ce269673f468e991d232bc4cc2e24988681fe9ebafef8e9d44c86ca85f264c93184866429c4de48c1e176e18631ae6011d2a46d8d0a048803949bc1e13be05a31b7c1154c089c7bb95fc113212d1e1eb7266e6f1d86392a5386f4335e5c261d9574e9060c470563d5fa5a9d4ac38ea2ed40f0f569edd5771c8f3ec3c7102e5eb9af41678355f3ed6af375965b39597236924551cd05acaa5e39890fe6ba8d683605dfa73a906e91e4618bb7b1e3cfdde1aa20f01a35ccb0cfafac437311afafaa72e7c3152d1f2ef63cd630d947b3a69e255bd6e0cd47a3b1bbb3be51fe6c32d1aba95fa7834c1bf709897169c81137e7a6a7eb018992b3af5aa1745c10eaa1a062987c187ec526ef92ceff1c0ddd776f42f84cc0530acde7c21e5e2624d4748f741a64cf5176edb9838eaccec392447921db224070374f28dae8b1d24d5aa13b40d5cde37530cdbd8ec841efd8a08bf1d8171faa93c84766cde6d7e65828497fb4a8a3ff66f6c380cc04047001028bac4e4d0404a5529117d53187e76746e0f3fa9d5c1004e4a142814e1cb61630d79010de59c1559739b45d73ed25f562e6b396f173c056e2b6ce7ba14927541e504231dfa9d0597bc912196de2fdb0900662e94ce7d60cc7f218001437f17b877fe2698a7c745e6d4f313c6dbdc291e224a3d241898915571a62a1e07b6ec09859f568d6dc41bc206cee5098a6f97fe8cead487122cb6f9069d83446391888d0f1a5fd0c48e07c1a1c72a0dff6aee7ab4e5d67681d708a62fbb48090f3e4446ff5083'

describe('NIM ChatRoom startup', () => {
  describe('#init', () => {
    it('Init should return 1', () => {
      const result = instance.init('')
      assert.strictEqual(result, 1)
    })
  })
  describe('#getLoginState', () => {
    it('Get login state before enter a chatroom should return kNIMChatRoomLoginStateUnLogin 2', () => {
      const state = instance.getLoginState(globalRoomId)
      assert.strictEqual(state, 2)
    })
  })
  describe('#enter', () => {
    it('Enter room should return 200 with enter info', (done) => {
      instance.regEnterCb((roomId, step, errorCode, info, memberInfo) => {
        if (step === 5) {
          assert.strictEqual(roomId, globalRoomId)
          assert.strictEqual(errorCode, 200)
          done()
        }
      })
      instance.enter(globalRoomId, globalToken, {
        nickname: 'Test',
        login_tags: ['abc', 'def', '999']
      })
    })
  })
  describe('#getLoginState', () => {
    it('Get login state after enter a chatroom should return kNIMChatRoomLoginStateLogin 1', () => {
      const state = instance.getLoginState(globalRoomId)
      assert.strictEqual(state, 1)
    })
  })
  describe('#sendMsg', () => {
    it('Send message should return 200', (done) => {
      const messageAttach = 'msg attach'
      instance.regSendMsgAckCb((roomId, errorCode, result) => {
        assert.strictEqual(roomId, globalRoomId)
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(result.msg_attach, messageAttach)
        done()
      })
      instance.sendMsg(globalRoomId, {
        body: 'msg body',
        msg_attach: messageAttach,
        msg_type: 0,
        client_msg_id: new Date().getTime().toString()
      })
    })
  })
  describe('#getMembersOnlineAsync', () => {
    it('Get members online async should return 200 with members', (done) => {
      instance.getMembersOnlineAsync(globalRoomId, {
        type: 0,
        timestampOffset: 0,
        limit: 10
      }, (roomId, errorCode, members) => {
        assert.strictEqual(roomId, globalRoomId)
        assert.strictEqual(errorCode, 200)
        assert.notStrictEqual(members.length, 0)
        /* members.map(member => {
          console.log(member.account_id)
          return true
        }) */
        done()
      })
    })
  })
  describe('#getMembersCountByTagOnlineAsync', () => {
    it('Get members count by tag online async should return 200 with no zero member count', (done) => {
      instance.getMembersCountByTagOnlineAsync(globalRoomId, 'abc', (roomId, errorCode, count) => {
        assert.strictEqual(roomId, globalRoomId)
        assert.strictEqual(errorCode, 200)
        assert.notStrictEqual(count, 0)
        done()
      })
    })
  })
  describe('#getMessageHistoryOnlineAsync', () => {
    it('Get message history should return 200 with some messages', (done) => {
      instance.getMessageHistoryOnlineAsync(globalRoomId, {
        start: 0,
        limit: 10,
        reverse: false,
        msgtypes: [0, 1, 2]
      }, (roomId, errorCode, messages) => {
        assert.strictEqual(roomId, globalRoomId)
        assert.strictEqual(errorCode, 200)
        assert.notStrictEqual(messages.length, 0)
        done()
      })
    }).timeout(4000)
  })
  describe('#setMemberAttributeOnlineAsync', () => {
    it('Set member attribute online async should return 200 with member attribute', (done) => {
      instance.setMemberAttributeOnlineAsync(globalRoomId, {
        account_id: 'jiajia01',
        attribute: -2,
        opt: true,
        notify_ext: 'notify extension...'
      }, (roomId, errorCode, changedMember) => {
        assert.strictEqual(roomId, globalRoomId)
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(changedMember.account_id, 'jiajia01')
        done()
      })
    })
  })
  describe('#setMemberAttributeOnlineAsync', () => {
    it('Set member attribute online async should return 200 with member attribute', (done) => {
      instance.setMemberAttributeOnlineAsync(globalRoomId, {
        account_id: 'jiajia01',
        attribute: -2,
        opt: false,
        notify_ext: 'notify extension...'
      }, (roomId, errorCode, changedMember) => {
        assert.strictEqual(roomId, globalRoomId)
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(changedMember.account_id, 'jiajia01')
        done()
      })
    })
  })
  describe('#getInfoAsync', () => {
    it('Get chatroom info should return 200 with correct ID', (done) => {
      instance.getInfoAsync(globalRoomId, (roomId, errorCode, info) => {
        assert.strictEqual(roomId, globalRoomId)
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(info.room_id, globalRoomId)
        done()
      })
    })
  })
  describe('#getMemberInfoByIDsAsync', () => {
    it('Get member info by IDs should return 200 with correct member info', (done) => {
      instance.getMemberInfoByIDsAsync(globalRoomId, [
        'jiajia01',
        'ljm2'
      ], (roomId, errorCode, members) => {
        assert.strictEqual(roomId, globalRoomId)
        assert.strictEqual(errorCode, 200)
        assert.notStrictEqual(members.length, 0)
        done()
      })
    })
  })
  describe.skip('#kickMemberAsync', () => {
    it('Kick member should return 200', (done) => {
      instance.kickMemberAsync(globalRoomId, 'xs01', 'notify extension...',
        (roomId, errorCode) => {
          assert.strictEqual(roomId, globalRoomId)
          assert.strictEqual(errorCode, 200)
          done()
        })
    })
  })
  describe('#tempMuteMemberAsync', () => {
    it('Temp mute member should return 200', (done) => {
      instance.tempMuteMemberAsync(globalRoomId, 'dong147', 10, false, '',
        (roomId, errorCode, member) => {
          assert.strictEqual(roomId, globalRoomId)
          assert.strictEqual(errorCode, 200)
          assert.strictEqual(member.account_id, 'dong147')
          done()
        })
    })
  })
  describe('#tempMuteMemberByTagAsync', () => {
    it('temp mute member by tag should return 200', (done) => {
      instance.tempMuteMemberByTagAsync(globalRoomId, 'abc', 10, false, '',
        (roomId, errorCode, member) => {
          assert.strictEqual(roomId, globalRoomId)
          assert.strictEqual(errorCode, 200)
          done()
        })
    })
  })
  describe('#updateRoomInfoAsync', () => {
    it('Update room info should return 200 with new name and announcement', (done) => {
      const name = `Name updated at ${new Date().getTime().toString()}`
      const announcement = `Updated at ${new Date().getTime().toString()}`
      instance.updateRoomInfoAsync(globalRoomId, {
        name,
        announcement
      }, true, 'notify extension...', (roomId, errorCode) => {
        instance.getInfoAsync(globalRoomId, (roomId, errorCode, info) => {
          assert.strictEqual(roomId, globalRoomId)
          assert.strictEqual(errorCode, 200)
          assert.strictEqual(info.name, name)
          assert.strictEqual(info.announcement, announcement)
          done()
        })
        assert.strictEqual(roomId, globalRoomId)
        assert.strictEqual(errorCode, 200)
      })
    })
  })
  describe('#updateMyRoomRoleAsync', () => {
    it('Update my info should return 200 with new nickanme', (done) => {
      const nick = `Updated at ${new Date().getTime().toString()}`
      instance.regNotificationCb((roomId, notification) => {
        assert.strictEqual(roomId, globalRoomId)
        assert.strictEqual(notification.opeNick, nick)
        instance.unregChatroomCb()
        done()
      })
      instance.updateMyRoomRoleAsync(globalRoomId, {
        nick
      }, true, 'notify extension...', (roomId, errorCode) => {
        assert.strictEqual(roomId, globalRoomId)
        assert.strictEqual(errorCode, 200)
      })
    })
  })
  describe('#queueOfferAsync', () => {
    it('Queue offer should return 200', (done) => {
      instance.queueOfferAsync(globalRoomId, {
        key: 'queueKey',
        value: 'queueValue'
      }, (roomId, errorCode) => {
        assert.strictEqual(roomId, globalRoomId)
        assert.strictEqual(errorCode, 200)
        done()
      })
    })
  })
  describe('#queueListAsync', () => {
    it('Queue list should return 200 with queue list', (done) => {
      instance.queueListAsync(globalRoomId, (roomId, errorCode, elements) => {
        let foundKey = false
        elements.map(element => {
          if (element.key === 'queueKey') {
            foundKey = true
          }
          return true
        })
        assert.strictEqual(foundKey, true)
        done()
      })
    })
  })
  describe('#queueHeaderAsync', () => {
    it('Query queue header should return 200 with headers', (done) => {
      instance.queueHeaderAsync(globalRoomId, (roomId, errorCode, element) => {
        assert.strictEqual(roomId, globalRoomId)
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(element.key, 'queueKey')
        assert.strictEqual(element.value, 'queueValue')
        done()
      })
    })
  })
  describe('#queueBatchUpdateAsync', () => {
    it('Batch update queue should return 200', (done) => {
      const notExistKey = 'notExistKey'
      instance.queueBatchUpdateAsync(globalRoomId, [{
        key: 'queueKey',
        value: 'queueNewValue'
      }, {
        key: notExistKey,
        value: 'newValue'
      }], true, 'notify extension...', (roomId, errorCode, notInQueue) => {
        assert.strictEqual(roomId, globalRoomId)
        assert.strictEqual(errorCode, 200)
        let foundKey = false
        notInQueue.map(key => {
          if (key === notExistKey) {
            foundKey = true
          }
          return true
        })
        assert.strictEqual(foundKey, true)
        done()
      })
    })
  })
  describe('#queuePollAsync', () => {
    it('Queue poll should return 200 with correct element', (done) => {
      instance.queuePollAsync(globalRoomId, 'queueKey', (roomId, errorCode, element) => {
        assert.strictEqual(roomId, globalRoomId)
        assert.strictEqual(errorCode, 200)
        assert.strictEqual(element.key, 'queueKey')
        assert.strictEqual(element.value, 'queueValue')
        done()
      })
    })
  })
  describe('#exit', () => {
    it('Exit shoud return 200', (done) => {
      instance.regExitCb((roomId, errorCode, exitInfo) => {
        assert.strictEqual(roomId, globalRoomId)
        assert.strictEqual(errorCode, 200)
        done()
      })
      instance.exit(globalRoomId)
    })
  })
  describe('#cleanUp', () => {
    it('Clean up return void', () => {
      instance.cleanUp()
      process.exit(0)
    })
  })
})
