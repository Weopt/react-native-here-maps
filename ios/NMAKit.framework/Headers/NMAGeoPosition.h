/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class CLLocation;
@class NMAGeoCoordinates;

/**
 * A constant used to indicate an unknown measurement value.
 */
extern const double NMAGeoPositionUnknownValue;

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents position, speed, and course information as provided by a
 * positioning source for a distinct moment in time.
 */
@interface NMAGeoPosition : NSObject

/**
 * A convenience constructor for creating `NMAGeoPosition` instances with
 * specified coordinates, speed, course, and accuracy.
 *
 * @note The accuracy parameter will be used for all of latitudeAccuracy,
 * longitudeAccuracy, and altitudeAccuracy.
 *
 * @note The timestamp will be set to the current time.
 */
+ (instancetype)geoPositionWithCoordinates:(NMAGeoCoordinates *)coordinates
                                     speed:(double)speed
                                    course:(double)course
                                  accuracy:(double)accuracy;

/**
 * A convenience constructor for creating `NMAGeoPosition` instances with
 * specified coordinates, speed, course, and accuracy.
 *
 * @note The accuracy parameter will be used for all of latitudeAccuracy,
 * longitudeAccuracy, and altitudeAccuracy.
 */
+ (instancetype)geoPositionWithCoordinates:(NMAGeoCoordinates *)coordinates
                                     speed:(double)speed
                                    course:(double)course
                                  accuracy:(double)accuracy
                                 timestamp:(NSDate *)timestamp;

/**
 * A convenience constructor for creating `NMAGeoPosition` instances with
 * specified coordinates, speed, course, latitudeAccuracy, longitudeAccuracy
 * and altitudeAccuracy.
 */
+ (instancetype)geoPositionWithCoordinates:(NMAGeoCoordinates *)coordinates
                           speed:(double)speed
                          course:(double)course
                latitudeAccuracy:(double)latitudeAccuracy
               longitudeAccuracy:(double)longitudeAccuracy
                altitudeAccuracy:(double)altitudeAccuracy
                       timestamp:(NSDate *)timestamp;

/**
 * A convenience constructor for creating `NMAGeoPosition` instances with
 * the specified CLLocation.
 */
+ (instancetype)geoPositionWithCLLocation:(CLLocation *)location
NS_SWIFT_NAME(init(location:));

/**
 * The geographical location of the position.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *coordinates;

/**
 * The accuracy of the latitude coordinate, in meters.
 *
 * @note Will be `NMAGeoPositionUnknownValue` if unknown.
 */
@property (nonatomic, readonly) double latitudeAccuracy;

/**
 * The accuracy of the longitude coordinate, in meters.
 *
 * @note Will be `NMAGeoPositionUnknownValue` if unknown.
 */
@property (nonatomic, readonly) double longitudeAccuracy;

/**
 * The accuracy of the altitude, in meters.
 *
 * @note Will be `NMAGeoPositionUnknownValue` if unknown.
 */
@property (nonatomic, readonly) double altitudeAccuracy;

/**
 * The movement speed of the position.
 *
 * @note Will be `NMAGeoPositionUnknownValue` if unknown.
 */
@property (nonatomic, readonly) double speed;

/**
 * The course (direction of travel) of the position, in degrees.
 *
 * Valid course values are in the range [0, 360), with 0 degrees representing
 * north and values increasing clockwise. Thus, east is 90 degrees, south is
 * 180 degrees, and so on.
 *
 * @note Will be `NMAGeoPositionUnknownValue` if unknown.
 */
@property (nonatomic, readonly) double course;

/**
 * The time at which the position measurements were taken.
 */
@property (nonatomic, readonly, strong) NSDate *timestamp;

/**
 * Indicates the validity of the `NMAGeoPosition`. The position is valid
 * if its coordinates are valid.
 */
@property (nonatomic, readonly) BOOL isValid;

@end

NS_ASSUME_NONNULL_END
