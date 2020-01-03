/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents WGS84 coordinates with double precision. A `NMAGeoCoordinates`
 * encapsulates a latitude and longitude value, plus an optional altitude value.
 *
 * @note Although `NMAGeoCoordinates` are accepted and handled with double
 * precision (about 15 significant digits), the real precision of rendering
 * operations such as `-[NMAMapView setGeoCenter:zoomLevel:withAnimation:]`
 * might be lower due to internal conversions.
 * Overall precision of `NMAGeoCoordinates` can be assured for only six digits
 * following the decimal point.
 */
@interface NMAGeoCoordinates : NSObject

/**
 * Constructs a `NMAGeoCoordinates` with the specified latitude and longitude.
 *
 * @param latitude An initial latitude value
 * @param longitude An initial longitude value
 */
+ (instancetype)geoCoordinatesWithLatitude:(double)latitude
                                 longitude:(double)longitude
NS_SWIFT_UNAVAILABLE("identical to corresponding instance initializer");

/**
 * Constructs a `NMAGeoCoordinates` with the specified latitude, longitude,
 * and altitude.
 *
 * @param latitude An initial latitude value
 * @param longitude An initial longitude value
 * @param altitude An initial altitude value
 */
+ (instancetype)geoCoordinatesWithLatitude:(double)latitude
                                 longitude:(double)longitude
                                  altitude:(double)altitude
NS_SWIFT_UNAVAILABLE("identical to corresponding instance initializer");

/**
 * Initializes a `NMAGeoCoordinates` instance with specified latitude and
 * longitude values and zero altitude.
 *
 * @param latitude An initial latitude value. Values outside of [-90, 90] will
 * be clamped to that range (100 becomes 90).
 * @param longitude An initial longitude value. Values outside of [-180, 180]
 * will be wrapped to that range (200 becomes -160).
 * @return The `NMAGeoCoordinates` instance, or nil if initialization failed
 */
- (instancetype)initWithLatitude:(double)latitude
                       longitude:(double)longitude;

/**
 * Initializes a `NMAGeoCoordinates` instance with specified values for
 * the initial latitude, longitude and altitude.
 *
 * @param latitude An initial latitude value
 * @param longitude An initial longitude value
 * @param altitude An initial altitude value
 * @return The `NMAGeoCoordinates` instance, or nil if initialization failed
 */
- (instancetype)initWithLatitude:(double)latitude
                       longitude:(double)longitude
                        altitude:(double)altitude NS_DESIGNATED_INITIALIZER;

/**
 * The latitude, as measured in degrees, representing north-south coordinate
 * (y-axis on a map).
 *
 * @note The latitude must be in the range [-90, 90]. Values outside this range
 * will be clamped.
 */
@property (nonatomic) double latitude;

/**
 * The longitude, as measured in degrees, representing east-west coordinate
 * (x-axis on a map).
 *
 * @note The longitude must be in the range [-180, 180]. Values outside this range
 * will be wrapped. For example, a value of 200 degrees will be wrapped to -160.
 */
@property (nonatomic) double longitude;

/**
 * The altitude of the `NMAGeoCoordinates` measured in meters above sea-level.
 *
 * By default, the plane of the map is at 0 meters. Thus, geocoordinates with positive
 * altitudes represent points above the plane of the map, while negative altitudes are
 * below the plane of the map.
 *
 * @note Valid values are in the range [-10000.0, 10000.0]. If an invalid value is
 * specified, it will be adjusted to the closest possible valid value (e.g. a
 * specified value of -10200.0 will be set to -10000.0).
 */
@property (nonatomic) float altitude;

/**
 * Calculates (using the Haversine formula) the distance in meters between
 * this `NMAGeoCoordinates` instance and the specified `NMAGeoCoordinates`.
 *
 * @param coordinates A second `NMAGeoCoordinates` some distance away
 * @return The distance between the `NMAGeoCoordinates`, or -DBL_MAX if
 *         the coordinates parameter is nil
 */
- (double)distanceTo:(NMAGeoCoordinates *)coordinates
NS_SWIFT_NAME(distance(to:));

/**
 * Calculates the heading in degrees from this `NMAGeoCoordinates` instance
 * to the specified `NMAGeoCoordinates` instance.
 *
 * @param coordinates `NMAGeoCoordinates` to which to the heading is calculated.
 * @return Heading from this coordinate to the given coordinate, in degrees.
 *         0 = north, increasing clockwise. If coordinates is nil or invalid
 *         a negative result will be returned to indicate an error.
 */
- (double)headingTo:(NMAGeoCoordinates *)coordinates
NS_SWIFT_NAME(heading(to:));

/**
 * Determines whether this `NMAGeoCoordinates` is equal to another.
 *
 * @return YES if the coordinates are equal, NO otherwise
 */
- (BOOL)isEqualToGeoCoordinates:(NMAGeoCoordinates *)coordinates
NS_SWIFT_NAME(equals(_:));

@end

NS_ASSUME_NONNULL_END
