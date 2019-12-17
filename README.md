# react-native-here-maps

A native module to use Here Maps with React Native


## Install

```
yarn add https://github.com/Weopt/react-native-here-maps/tarball/master

react-native link
```
In AndroidManifest.xml add:

    <uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />
    <uses-permission android:name="android.permission.INTERNET" />
    <uses-permission android:name="android.permission.ACCESS_WIFI_STATE" />
    <uses-permission android:name="android.permission.ACCESS_FINE_LOCATION" />


In MainApplication.java :

```
import com.heremapsrn.HereMapPackage;

protected List<ReactPackage> getPackages() {
      return Arrays.<ReactPackage>asList(
          new MainReactPackage(),
            new HereMapPackage() // <------ Add this line
      );
    }
    
```

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
