Pod::Spec.new do |s|
  s.name             = 'AelixSDK'
  s.version          = '1.0.0'
  s.summary          = 'Aelix 广告聚合 SDK'
  s.description      = 'AelixSDK 提供 Banner、插屏、开屏、激励视频、全屏视频、信息流等广告形式，支持多广告平台聚合接入。'
  s.homepage         = 'https://github.com/AndrewXF/AelixSDK'
  s.license          = { :type => 'Apache-2.0', :file => 'LICENSE' }
  s.author           = { 'Aelix' => '858440119@qq.com' }
  s.source           = { :git => 'https://github.com/AndrewXF/AelixSDK.git', :tag => s.version.to_s }

  s.ios.deployment_target = '12.0'
  s.static_framework = true
  s.vendored_frameworks = 'AelixSDK.xcframework'

  s.frameworks = 'UIKit', 'Foundation', 'AdSupport', 'MapKit', 'WebKit', 'MediaPlayer',
                 'CoreLocation', 'CoreMedia', 'AVFoundation', 'CoreTelephony', 'StoreKit',
                 'SystemConfiguration', 'MobileCoreServices', 'CoreMotion', 'Accelerate',
                 'AudioToolbox', 'JavaScriptCore', 'Security', 'CoreImage', 'ImageIO',
                 'QuartzCore', 'CoreGraphics', 'CoreText', 'CoreData', 'AVKit', 'MessageUI',
                 'QuickLook', 'SafariServices', 'Photos', 'DeviceCheck'

  s.libraries = 'z', 'sqlite3', 'c++', 'c++abi', 'xml2', 'bz2', 'iconv', 'resolv'

  s.user_target_xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }

  # UbiX 广告渠道
  s.dependency 'UBiXMediationSDK', '2.12.2.11.1001'
  s.dependency 'UBiXMUBiXAdapter', '2.9.0.11.0'
end
