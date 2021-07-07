const chatroom = require('bindings')('nim_chatroom')
const path = require('path')
if (process.platform === 'win32') {
  // Add the compiled product path to the environment variable,
  // so that the third party does not need to copy the
  // dynamic library separately to the program directory when importing.
  const asarPath = path.join(__dirname, '../../build/Release/')
  const unpackedPath = asarPath.replace('app.asar', 'app.asar.unpacked')
  process.env.PATH = `${unpackedPath};${process.env.PATH}`
}
export default chatroom
