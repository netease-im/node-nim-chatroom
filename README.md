# NetEase IM chatroom node.js addon wrapper

## How to use

```bash
npm install --save node-nim-chatroom
```

If you are using `electron-builder` to package your electron app, when you run `electron-builder`, it will copy all binary libraries to your electron app resources folder automatically.

## Build environment

 - CMake 3.10 or higher
 - Visual Studio 2017 or MSBuild 2017

## Command line

|Options|Descroption|
|---|---|
|fetch-wrapper|Download NIM C++ SDK source files and C binary files|
|build-wrapper|Build NIM C++ SDK|
|package|Package the compiled artifacts|
|build|Build with specified parameters (build-wrapper+package)|

Examples:

Fetch C++ wrapper source files and build C++ addon for node.js.

```bash
npx just fetch-wrapper --target_platform=win32 --target_arch=ia32
npx just build --runtime=electron --target=13.1.2 --target_platform=win32 --target_arch=ia32
```

Build NIM chatroom C++ wrapper only, needs run `npx just fetch-wrapper` first.

```bash
npx just build-wrapper --target_platform=win32 --target_arch=ia32
```

Packing a compiled artifact as `.tar.gz` in `packages` folder.

```bash
npx just package --runtime=electron --target=13.1.2 --target_platform=win32 --target_arch=ia32
```

## Test

Your need to build typescript before run test.

```
npm run test
```

## Documentation

You can use jsdoc to automatically generate documentation.

```bash
npm install -g jsdoc
jsdoc js -r -R README.md -d docs -t ./node_modules/ink-docstrap/template
```
