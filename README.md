# react-native-heremaps

A native module to use Here Maps with React Native

## Here Maps license
Go to [HERE website](https://developer.here.com/develop/mobile-sdks) and create your license key.

Then, open AndroidManifest.xml and update this section with your license.

```
    <!-- HEREMaps -->
    <meta-data
        android:name="com.here.android.maps.appid"
        android:value="YOUR-APP-ID-HERE" />

    <meta-data
        android:name="com.here.android.maps.apptoken"
        android:value="YOUR-APP-TOKEN-HERE" />

    <meta-data android:name="com.here.android.maps.license.key"
        android:value="YOUR-LICENSE-KEY-HERE"/>
```
