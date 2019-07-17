package com.heremapsrn.react.map;

import android.util.Log;

import com.facebook.infer.annotation.Assertions;
import com.facebook.react.bridge.ReadableArray;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.common.MapBuilder;
import com.facebook.react.uimanager.ThemedReactContext;
import com.facebook.react.uimanager.ViewGroupManager;
import com.facebook.react.uimanager.annotations.ReactProp;

import java.util.Map;

import javax.annotation.Nullable;

class HereMapManager extends ViewGroupManager<HereMapView> {

    private static final int COMMAND_ZOOM_IN = 1;
    private static final int COMMAND_ZOOM_OUT = 2;
    private static final int COMMAND_SET_CENTER = 3;

    static final String REACT_CLASS = "HereMapView";

    private static final String TAG = HereMapManager.class.getSimpleName();

    @Override
    public String getName() {
        return REACT_CLASS;
    }

    @Override
    protected HereMapView createViewInstance(ThemedReactContext reactContext) {
        return new HereMapView(reactContext);
    }

    @Override
    public Map<String, Integer> getCommandsMap() {
        Log.d("React"," View manager getCommandsMap:");
        return MapBuilder.of(
                "zoomIn", COMMAND_ZOOM_IN,
                "zoomOut", COMMAND_ZOOM_OUT,
                "setCenter", COMMAND_SET_CENTER);
    }

    @Override
    public void receiveCommand(HereMapView view,
                               int commandType,
                               @Nullable ReadableArray args) {

        Assertions.assertNotNull(view);
        Assertions.assertNotNull(args);

        switch (commandType) {
            case COMMAND_ZOOM_IN: {
                double zoomLevel = args.getDouble(0);
                view.setZoomLevel(zoomLevel);
                return;
            }

            case COMMAND_ZOOM_OUT: {
                double zoomLevel = args.getDouble(0);
                view.setZoomLevel(zoomLevel);
                return;
            }

            case COMMAND_SET_CENTER: {
                ReadableMap coordinate = args.getMap(0);
                view.setCenter(coordinate);
                return;
            }

            default:
                throw new IllegalArgumentException(String.format(
                        "Unsupported command %d received by %s.",
                        commandType,
                        getClass().getSimpleName()));
        }
    }

    @ReactProp(name = "center")
    public void setCenter(HereMapView view, @Nullable ReadableMap center) {
        Log.d(TAG, "======================= Center " + center);
        view.setCenter(center);
    }

    @ReactProp(name = "mapType")
    public void setMapType(HereMapView view, @Nullable String type) {
        Log.d(TAG, "======================= Map Type " + type);
        view.setMapType(type);
    }

    @ReactProp(name = "initialZoom", defaultDouble = 10.0)
    public void setZoomLevel(HereMapView view, double zoomLevel) {
        Log.d(TAG, "======================= ZOOM lolilol " + zoomLevel);
        view.setZoomLevel(zoomLevel);
    }

    @ReactProp(name = "userLocation")
    public void setUserLocation(HereMapView view, @Nullable ReadableMap markerPosition) {
        Log.d(TAG, "======================= Marker " + markerPosition);
        view.setUserLocation(markerPosition);
    }

    @ReactProp(name = "markersList")
    public void setMarkersList(HereMapView view, @Nullable ReadableArray markersPosition) {
        Log.d(TAG, "======================= Markers List " + markersPosition);
        view.setMarkersList(markersPosition);
    }
}
