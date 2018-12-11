# asr-ios-sdk
搜狗语音识别库/示例

## 准备工作
- 搜狗知音平台申请的 **appid** 和 **appkey**
- 运行OSX的苹果开发电脑、iPhone/iPad
- [Xcode](https://developer.apple.com/xcode/)

## 集成方式
- 下载本工程[Releases](https://github.com/sogouspeech/asr-iOS-sdk/releases)页面的静态库 (**SDK library**).
- 将静态库以及源文件(头文件)集成到开发项目中.

## 依赖项
- TARGETS-->Info-->Custom iOS Target Properties   添加麦克风使用权限 (**Privacy - Microphone Usage Description**)
- TARGETS-->Build Settings-->Other Linker Flags 添加 **-ObjC**
- TARGETS-->Link Binary With Libraries 添加 **libz、libc++** 

## 运行Demo
- 克隆/下载本工程源码
- 将Releases页面的静态库下载后，重新引入到工程中
- 在Demo的ViewController中添加获取到的 **appid** 和 **appkey**，并填写使用的服务域名
- 运行


使用方法请参考[搜狗知音文档](https://docs.zhiyin.sogou.com/docs/asr/sdk)
