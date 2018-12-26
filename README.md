# asr-ios-sdk

搜狗语音识别库/示例

## 准备工作

- 搜狗知音平台申请的 **appid** 和 **appkey**
- 运行OSX的苹果开发电脑、iPhone/iPad
- [Xcode](https://developer.apple.com/xcode/)

## 示例程序

- 克隆/下载本工程源码
- 进入Example目录，运行 `pod install`。
- 在Demo的ViewController中添加获取到的 **appid** 和 **appkey**，并填写使用的服务域名
- 运行

## 通过CocoaPods集成

- SogouSpeechSDK通过 [CocoaPods](https://cocoapods.org)集成，安装CocoaPods。
- 在Podfile中添加引用，如下：
```ruby
pod 'SogouSpeechSDK'
```

有关更详尽的cocoapods介绍请参见[cocoapods官网](https://cocoapods.org/).

## 依赖项

- TARGETS-->Info-->Custom iOS Target Properties   添加麦克风使用权限 (**Privacy - Microphone Usage Description**)
- TARGETS-->Build Settings-->Other Linker Flags 添加 **$(inherited)** （如已存在，不必再次添加）
- TARGETS-->Link Binary With Libraries 添加 **libz、libc++** 

使用方法请参考[搜狗知音文档](https://docs.zhiyin.sogou.com/docs/asr/sdk)
