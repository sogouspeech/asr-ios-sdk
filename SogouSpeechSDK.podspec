#  SogoSpeechSDK podspec
#
#  Created by sogou on 2018/12/25.
#  Copyright 2018 Sogou Inc. All rights reserved.
#  Use of this source code is governed by the Apache 2.0
#  license that can be found in the LICENSE file.
#

Pod::Spec.new do |s|
  s.name             = 'SogouSpeechSDK'
  s.version          = '1.1.0'
  s.summary          = 'zhiyin lib'

  s.homepage         = 'https://github.com/sogouspeech/asr-ios-sdk'
  s.license          = 'Apache License, Version 2.0'
  s.author           = { 'machuanxing@sogou-inc.com' => 'machuanxing@sogou-inc.com' }
  s.source           = { :git => 'https://github.com/sogouspeech/asr-ios-sdk.git', :tag => s.version.to_s }

  s.ios.deployment_target = '8.0'

  s.vendored_libraries  = 'SogouSpeechSDK/Classes/Client/*.{a}'
  s.static_framework = true

  s.subspec "Client" do |cs|
    cs.source_files = 'SogouSpeechSDK/Classes/Client/SogouSpeechDelegate.h',
                      'SogouSpeechSDK/Classes/Client/SogouSpeechErrorCode.h',
                      'SogouSpeechSDK/Classes/Client/SogoSpeechSDK.h',
                      'SogouSpeechSDK/Classes/Client/SogouSpeechManager.h',
                      'SogouSpeechSDK/Classes/Client/SogouSpeechPropertySetting.h'
  end
  
  s.subspec "Messages" do |ms|
    ms.source_files = "SogouSpeechSDK/Classes/**/*.pbobjc.{h,m}"
    ms.header_mappings_dir = "SogouSpeechSDK/Classes/SogouSpeech"
    ms.private_header_files = "SogouSpeechSDK/Classes/**/*.pbobjc.h";
    ms.requires_arc = false
    ms.dependency "Protobuf"
  end

  s.subspec "Services" do |ss|
    ss.source_files = "SogouSpeechSDK/Classes/**/*.pbrpc.{h,m}"
    ss.header_mappings_dir = "SogouSpeechSDK/Classes/SogouSpeech"
    ss.private_header_files = "SogouSpeechSDK/Classes/**/*.pbrpc.h";
    ss.dependency "gRPC-ProtoRPC"
    ss.dependency "#{s.name}/Messages"
  end

  src_root = '$(PODS_ROOT)/SogouSpeechSDK'
  s.pod_target_xcconfig = {
    # This is needed by all pods that depend on Protobuf:
    'GCC_PREPROCESSOR_DEFINITIONS' => '$(inherited) GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS=1',
    # This is needed by all pods that depend on gRPC-RxLibrary:
    'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES',

    'GRPC_SRC_ROOT' => src_root,
    'HEADER_SEARCH_PATHS' => '"$(inherited)" "$(GRPC_SRC_ROOT)/Classes/SogouSpeech"',
    'USER_HEADER_SEARCH_PATHS' => '"$(GRPC_SRC_ROOT)" "$(GRPC_SRC_ROOT)/Classes/SogouSpeech"',
    #'USE_HEADERMAP' => 'NO',
    #'ALWAYS_SEARCH_USER_PATHS' => 'NO',
  }
end

