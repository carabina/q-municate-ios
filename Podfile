
platform :ios, '8.1'
xcodeproj 'Q-municate.xcodeproj'
source 'https://github.com/CocoaPods/Specs.git'

target 'Q-municate' do
    
    pod 'UIDevice-Hardware', '~> 0.1.3'
    pod 'SVProgressHUD', '~> 1.0'
    pod 'SSKeychain', '~> 1.2.2'
    pod 'SDWebImage', '~> 4.0.0'
    pod 'Reachability', '~> 3.2'
    pod 'TTTAttributedLabel', '~> 2.0'
    pod 'libextobjc/EXTScope', '~> 0.4.1'
    pod 'libextobjc/EXTKeyPathCoding', '~> 0.4.1'
    pod 'Flurry-iOS-SDK/FlurrySDK'
    pod 'NYTPhotoViewer', '~> 1.1.0'
    #    pod 'QMChatViewController'
    #    pod 'QMServices'
    
    #Facebook
    pod 'FBSDKCoreKit'
    pod 'FBSDKShareKit'
    pod 'FBSDKLoginKit'
    
    #Twitter
    pod 'Fabric'
    pod 'Crashlytics'
    
    #Firebase
    pod 'FirebaseUI/Phone', '~> 4.0'
    
    #For development pods
    #    pod 'QMCVDevelopment', :path => '../QMChatViewController-ios/'
    #    pod 'QMServicesDevelopment', :path => '../q-municate-services-ios/'
    
    pod 'QMCVDevelopment', :git => 'git@github.com:QuickBlox/QMChatViewController-ios.git', :branch => 'feature/QMShareExtension'
    pod 'QMServicesDevelopment',:git => 'git@github.com:QuickBlox/q-municate-services-ios.git', :branch => 'feature/IQMUNICATE-650'
    
end

target 'QMSiriExtension' do
    pod 'QMServicesDevelopment',:git => 'git@github.com:QuickBlox/q-municate-services-ios.git', :branch => 'feature/IQMUNICATE-650'
    # pod 'QMServicesDevelopment', :path => '../q-municate-services-ios/'
    
end

post_install do |installer|
    
    installer.pods_project.targets.each do |target|
        case target.name
            when 'Bolts'
            target.build_configurations.each do |config|
                config.build_settings['APPLICATION_EXTENSION_API_ONLY'] = 'NO'
            end
        end
    end
    #This script fixes an issue with application icon on iOS 11
    #MORE INFO: https://github.com/CocoaPods/CocoaPods/issues/7003
    installer.aggregate_targets.each do |target|
        copy_pods_resources_path = "Pods/Target Support Files/#{target.name}/#{target.name}-resources.sh"
        string_to_replace = '--compile "${BUILT_PRODUCTS_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}"'
        assets_compile_with_app_icon_arguments = '--compile "${BUILT_PRODUCTS_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}" --app-icon "${ASSETCATALOG_COMPILER_APPICON_NAME}" --output-partial-info-plist "${BUILD_DIR}/assetcatalog_generated_info.plist"'
        text = File.read(copy_pods_resources_path)
        new_contents = text.gsub(string_to_replace, assets_compile_with_app_icon_arguments)
        File.open(copy_pods_resources_path, "w") {|file| file.puts new_contents }
    end
end
