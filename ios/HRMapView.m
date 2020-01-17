//
//  HRMapView.m
//  RNHereMapsIos
//
//  Created by WeOpt Mac on 11/02/2019.
//  Copyright © 2019 Facebook. All rights reserved.
//

#import "HRMapView.h"
#import "React/RCTEventDispatcher.h"
#import <React/RCTLog.h>

@import NMAKit;

@interface HRMapView ()


@end

@implementation HRMapView {
    
    RCTEventDispatcher *_eventDispatcher;
    
}


- (void)setMapCenter:(NSDictionary *)mapCenter
{
    RCTLogInfo(@"Set center map to %f,%f", [[mapCenter objectForKey:(@"latitude")] doubleValue], [[mapCenter objectForKey:(@"longitude")] doubleValue]);
    
    if (![mapCenter isEqual:_mapCenter]) {
        _mapCenter = [mapCenter copy];
        NMAGeoCoordinates* coord = [[NMAGeoCoordinates alloc]
                                    initWithLatitude: [[mapCenter objectForKey:(@"latitude")] doubleValue]
                                    longitude:[[mapCenter objectForKey:(@"longitude")] doubleValue]];
        [_mapView setGeoCenter:coord
                     zoomLevel:NMAMapViewPreserveValue
                 withAnimation:NMAMapAnimationNone];
    }
}

- (void)setInitialZoom:(float)initialZoom
{
    RCTLogInfo(@"Set initial zoom map to %f", initialZoom);
    
    self.mapView.zoomLevel = initialZoom;
}

- (void)setUserLocation:(NSDictionary *)userLocation
{
    RCTLogInfo(@"Set user location marker to %f,%f", [[userLocation objectForKey:(@"latitude")] doubleValue], [[userLocation objectForKey:(@"longitude")] doubleValue]);
    UIImage  *myImage = [UIImage imageNamed:@"userLocation"];
    // Add the marker on the map
    NMAMapMarker *positionMarker =
    [NMAMapMarker
        mapMarkerWithGeoCoordinates:[NMAGeoCoordinates
            geoCoordinatesWithLatitude:[[userLocation objectForKey:(@"latitude")] doubleValue]
            longitude:[[userLocation objectForKey:(@"longitude")] doubleValue]]
            image: myImage];
    
    [_mapView addMapObject:positionMarker];
}

- (void)setMarkersList:(NSArray *)markersList
{
    RCTLogInfo(@"Set markers List");
    for (id marker in markersList) {
        RCTLogInfo(@"Set marker on map to %f,%f", [[marker objectForKey:(@"latitude")] doubleValue], [[marker objectForKey:(@"longitude")] doubleValue]);
        
        // Add the marker on the map
        NMAMapMarker *positionMarker =
        [NMAMapMarker
         mapMarkerWithGeoCoordinates:[NMAGeoCoordinates
                geoCoordinatesWithLatitude:[[marker objectForKey:(@"latitude")] doubleValue]
                longitude:[[marker objectForKey:(@"longitude")] doubleValue]]
                image:[UIImage imageNamed:@"marker"]];
        
        // [positionMarker setTitle:[marker objectForKey:(@"title")]];
        if ( [marker objectForKey:(@"description")] != (id)[NSNull null] ) {
            // [positionMarker setTextDescription:[marker objectForKey:(@"description")]];
        }
        
        
        [_mapView addMapObject:positionMarker];
        
    }
}


- (instancetype)initWithEventDispatcher:(RCTEventDispatcher *)eventDispatcher
{
    if ((self = [super init])) {
        // Do any additional setup after loading the view, typically from a nib.
        //set geo center
        
        _eventDispatcher = eventDispatcher;
        _mapView = [[NMAMapView alloc] init];
        
        NMAGeoCoordinates *geoCoordCenter =
        [[NMAGeoCoordinates alloc] initWithLatitude:49.260327 longitude:-123.115025];
        [_mapView setGeoCenter:geoCoordCenter withAnimation:NMAMapAnimationNone];
        _mapView.copyrightLogoPosition = NMALayoutPositionBottomCenter;
        //set zoom level
        _mapView.zoomLevel = 13;
        
        //Allow to use didSelectObjects to detect when we click on a marker
        self.mapView.delegate = self;
        
        
    }
    
    return self;
}

-(void)mapView:(NMAMapView *)mapView didSelectObjects:(NSArray *)objects {
    RCTLogInfo(@"TAP on marker !");
    NMAMapMarker *mapMarker = (NMAMapMarker *) objects.firstObject;
    // [mapMarker showInfoBubble];
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    self.mapView.frame = self.bounds;
    [self addSubview:_mapView];
}

@end
