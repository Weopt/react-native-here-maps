//
//  HRMapView.h
//  RNHereMapsIos
//
//  Created by WeOpt Mac on 11/02/2019.
//  Copyright © 2019 Facebook. All rights reserved.
//
#import "React/RCTEventDispatcher.h"
#import "React/RCTView.h"
#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
@import NMAKit;

@class RCTEventDispatcher;

@interface HRMapView : UIView<NMAMapViewDelegate>

@property (strong, nonatomic) IBOutlet NMAMapView *mapView;
@property (nonatomic, strong) NSDictionary *mapCenter;
@property (nonatomic, strong) NSDictionary *userLocation;
@property (nonatomic, strong) NSArray *markersList;
@property (nonatomic) float initialZoom;


- (instancetype)initWithEventDispatcher:(RCTEventDispatcher *)eventDispatcher NS_DESIGNATED_INITIALIZER;


@end

