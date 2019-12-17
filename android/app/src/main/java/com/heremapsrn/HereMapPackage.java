package com.heremapsrn;

import android.app.Activity;

import com.facebook.react.ReactPackage;
import com.facebook.react.bridge.JavaScriptModule;
import com.facebook.react.bridge.NativeModule;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.uimanager.ViewManager;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class HereMapPackage implements ReactPackage {
    public HereMapPackage() {
    }

    public HereMapPackage(Activity activity) {
    } // backwards compatibility


    @Override
    public List<NativeModule> createNativeModules(ReactApplicationContext reactContext) {
        return Arrays.<NativeModule>asList(new HereMapModule(reactContext));
    }

    public List<Class<? extends JavaScriptModule>> createJSModules() {
        return Collections.emptyList();
    }

    @Override
    public List<ViewManager> createViewManagers(ReactApplicationContext reactContext) {
        //HereMapManager mapManager = new HereMapManager(reactContext);
        HereMapManager mapManager = new HereMapManager();
        return Arrays.<ViewManager>asList(mapManager);
    }
}
