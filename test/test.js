const assert = require('assert')
const NIMChatRoomSDK = require('../js/nim_chatroom').default

const instance = new NIMChatRoomSDK.ChatRoom()

const globalRoomId = 2008
const globalToken = '2b5b639b0caee2c85370304fa76909d43a3773358d0295a87a7ac161e772a2ce269673f468e991d232bc4cc2e24988681fe9ebafef8e9d44c86ca85f264c93189a50b95870653b9324f094fadc627eff233e86f2c8f9be279f6fa6fa862b2daca989df26ddb5934e5e634a2c0c8d33f92c1c8fec207b2ea545970330e635a3bc4e9060c470563d5fa5a9d4ac38ea2ed4ada49a06a93645b210aa05da45e145fbf41678355f3ed6af375965b395972369b8c33a5bdb53d0007596049f65c551fd3ea306f181918ca70a951f31c52e4be93df62a3330c35ad20083ce8d9431ef83503808c867b7fc3c5771491b9fc63fdc55bd6e0cd47a3b1bbb3be51fe6c32d1aba95fa7834c1bf709897169c81137e7a6a7eb018992b3af5aa1745c10eaa1a062987c187ec526ef92ceff1c0ddd776f42f84cc0530acde7c21e5e2624d4748f741a64cf5176edb9838eaccec392447921db224070374f28dae8b1d24d5aa13b40d5cde37530cdbd8ec841efd8a08bf1d8171faa93c84766cde6d7e65828497fb4a8a3ff66f6c380cc04047001028bac47858c1b3b3f5463aa8a503fdaf767ab8856eba6f242d766a21538638f4461c7ff6f6c84399bfe3c906f82bd7f5277d574f541bff8e23b8315796efecc6cc7a0a027b47712bee18467f2b3ef9490f8c17e181649653e2c6c846b36a17d245fddd2809f7f4b069b7f90260c4ab4a429f0bdc29840c1ac55a378731e016594be4f71d5e1e965b650287c01d4000923a51ce780a3a20450dbf4412fa265115294fddd0dc239a92ec036ef3bf224a08b45df190501bed6a92a1e0ba39766e7104b69c'

describe('NIM ChatRoom startup', () => {
  describe('#init', () => {
    it('Init should return 1', () => {
      const result = instance.init('')
      assert.strictEqual(result, 1)
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
        nickname: 'Test'
      })
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
