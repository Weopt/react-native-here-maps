Pod::Spec.new do |s|
    s.name         = "RNHereMapsIos"
    s.version      = "1.0.0"
    s.summary      = "RNHereMapsIos"
    s.description  = <<-DESC
                    RNHereMapsIos
                     DESC
    s.homepage     = "RNHereMapsIos"
    s.license      = "MIT"
    # s.license      = { :type => "MIT", :file => "FILE_LICENSE" }
    s.author             = { "author" => "n.potier@we-opt.com" }
    s.platform     = :ios, "7.0"
    s.source       = { :git => "https://github.com/Weopt/react-native-here-maps.git", :tag => "master" }
    s.source_files = "ios/**/*.{h,m,swift,a}"
    s.requires_arc = true

    s.dependency "React"
    s.dependency "HEREMaps"  
end