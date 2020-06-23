// RNTMapManager.m
#import <MapKit/MapKit.h>
@import NMAKit;
#import <React/RCTViewManager.h>
#import "HRMapView.h"

@interface RNTMapManager : RCTViewManager
@end

@implementation RNTMapManager

RCT_EXPORT_MODULE()
@synthesize bridge = _bridge;

- (UIView *)view
{    
    return [[HRMapView alloc] initWithEventDispatcher:self.bridge.eventDispatcher];
}

RCT_EXPORT_VIEW_PROPERTY(mapCenter, NSDictionary);
RCT_EXPORT_VIEW_PROPERTY(userLocation, NSDictionary);
RCT_EXPORT_VIEW_PROPERTY(markersList, NSArray);
RCT_EXPORT_VIEW_PROPERTY(initialZoom, float);

@end
