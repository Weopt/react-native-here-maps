/*
 * Copyright (c) 2011-2019 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoCoordinates;

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents a bounding box that defines a rectangular area in a
 * geographic coordinate system.
 *
 * Although the bounding box is specified by its top-left and bottom-right corner,
 * the box is not necessarily the smallest rectangle spanned by these two points.
 * It is possible to define bounding boxes that are wider than 180 degrees or higher than
 * 90 degrees (e.g. by set ting the longitude of top-left corner to a bigger value than
 * the longitude of the bottom-right corner).
 *
 * For example, a bounding box with a longitude of -180 degrees for the
 * top-left corner and a longitude of 180 degrees for the bottom-right corner
 * will construct an area the encircles the globe, whereas a bounding box
 * with the same longitude values for both corners will construct a
 * bounding box with a width of 0 degrees.
 */
@interface NMAGeoBoundingBox : NSObject

/**
 * Initializes a `NMAGeoBoundingBox` instance with specified top-left
 * and bottom-right `NMAGeoCoordinates`.
 *
 * @param topLeft A top-left `NMAGeoCoordinates` value for the new `NMAGeoBoundingBox`
 * @param bottomRight A bottom-right `NMAGeoCoordinates` value for the new
 * `NMAGeoBoundingBox`
 * @return The `NMAGeoBoundingBox`
 */
- (instancetype)initWithTopLeft:(NMAGeoCoordinates *)topLeft
                    bottomRight:(NMAGeoCoordinates *)bottomRight NS_DESIGNATED_INITIALIZER;

/**
 * Constructs a `NMAGeoBoundingBox` from `NMAGeoCoordinates` defining its top left and
 * bottom right corners.
 *
 * @param topLeft The `NMAGeoCoordinates` representing the top left corner of the bounding box
 * @param bottomRight The `NMAGeoCoordinates` representing the bottom right corner of the bounding box
 * @return The `NMAGeoBoundingBox`
 */
+ (instancetype)geoBoundingBoxWithTopLeft:(NMAGeoCoordinates *)topLeft
                              bottomRight:(NMAGeoCoordinates *)bottomRight
NS_SWIFT_UNAVAILABLE("identical to corresponding instance initializer");

/**
 * Constructs a `NMAGeoBoundingBox` from `NMAGeoCoordinates` defining its top right and
 * bottom left corners.
 *
 * @param topRight The `NMAGeoCoordinates` representing the top right corner of the bounding box
 * @param bottomLeft The `NMAGeoCoordinates` representing the bottom left corner of the bounding box
 * @return The `NMAGeoBoundingBox`
 */
+ (instancetype)geoBoundingBoxWithTopRight:(NMAGeoCoordinates *)topRight
                                bottomLeft:(NMAGeoCoordinates *)bottomLeft;

/**
 * Constructs a `NMAGeoBoundingBox` from a `NMAGeoCoordinates` center point and a height and width
 * in degrees.
 *
 * @note If the specified values produce a box with top edge latitude > 90 or bottom edge latitude < -90,
 * the box will be clamped to that range. If the top edge latitude is less than the bottom edge latitude,
 * nil will be returned.
 *
 * @param center The `NMAGeoCoordinates` representing the center of the bounding box
 * @param width The width of the bounding box in degrees longitude
 * @param height The height of the bounding box in degrees latitude
 * @return The `NMAGeoBoundingBox` if the inputs are valid, else nil
 */
+ (instancetype)geoBoundingBoxWithCenter:(NMAGeoCoordinates *)center
                                   width:(double)width
                                  height:(double)height;

/**
 * Constructs a `NMAGeoBoundingBox` which contains all coordinates in an array.
 *
 * The constructed `NMAGeoBoundingBox` will be the smallest possible box which contains all
 * the `NMAGeoCoordinates` in the input array.
 *
 * @param coordinates A `NSArray` of `NMAGeoCoordinates` defining the new `NMAGeoBoundingBox`
 * @return The `NMAGeoBoundingBox` if the inputs are valid, else nil
 */
+ (nullable instancetype)geoBoundingBoxContainingGeoCoordinates:(NSArray<NMAGeoCoordinates *> *)coordinates
NS_SWIFT_NAME(init(containingCoordinates:));

/**
 * Constructs a `NMAGeoBoundingBox` which contains all bounding boxes in an array.
 *
 * The constructed `NMAGeoBoundingBox` will be the smallest possible box which contains all
 * the `NMAGeoBoundingBoxes` in the input array.
 *
 * @param boundingBoxes A `NSArray` of `NMAGeoBoundingBox` defining the new `NMAGeoBoundingBox`
 * @return The `NMAGeoBoundingBox` if the inputs are valid, else nil
 */
+ (nullable instancetype)geoBoundingBoxContainingGeoBoundingBoxes:(NSArray<NMAGeoBoundingBox *> *)boundingBoxes
NS_SWIFT_NAME(init(containingBoundingBoxes:));

/**
 * The `NMAGeoBoundingBox` width, in degrees.
 */
@property (nonatomic, readonly) double width;

/**
 * The `NMAGeoBoundingBox` height, in degrees.
 */
@property (nonatomic, readonly) double height;

/**
 * The `NMAGeoCoordinates` representing the top-left corner of the
 * `NMAGeoBoundingBox`.
 */
@property (nonatomic, strong) NMAGeoCoordinates *topLeft;

/**
 * The `NMAGeoCoordinates` representing the top-right corner of the
 * `NMAGeoBoundingBox`.
 */
@property (nonatomic, strong) NMAGeoCoordinates *topRight;

/**
 * The `NMAGeoCoordinates` representing the bottom-left corner of the
 * `NMAGeoBoundingBox`.
 */
@property (nonatomic, strong) NMAGeoCoordinates *bottomLeft;

/**
 * The `NMAGeoCoordinates` representing the bottom-right corner of the
 * `NMAGeoBoundingBox`.
 */
@property (nonatomic, strong) NMAGeoCoordinates *bottomRight;

/**
 * The `NMAGeoCoordinates` representing the center of the `NAMGeoBoundingBox`.
 */
@property (nonatomic, readonly, weak) NMAGeoCoordinates *center;

/**
 * Indicates whether this `NMAGeoBoundingBox` crosses the international date line.
 */
@property (nonatomic, readonly) BOOL crossesInternationalDateLine;

/**
 * Determines whether the specified `NMAGeoCoordinates` object is contained
 * within this `NMAGeoBoundingBox` (boundary included).
 *
 * @param coordinates A `NMAGeoCoordinates` object to check for containment
 *                    within this `NMAGeoBoundingBox`
 * @return YES if contained within the `NMAGeoBoundingBox`, NO otherwise
 */
- (BOOL)containsGeoCoordinates:(NMAGeoCoordinates *)coordinates
NS_SWIFT_NAME(contains(_:));

/**
 * Determines whether the specified `NMAGeoBoundingBox` is covered entirely
 * by this `NMAGeoBoundingBox` (boundary included).
 *
 * @param boundingBox A `NMAGeoBoundingBox` to check for containment within
 *                    this `NMAGeoBoundingBox`
 * @return YES if contained within the `NMAGeoBoundingBox`, NO otherwise
 */
- (BOOL)containsGeoBoundingBox:(NMAGeoBoundingBox *)boundingBox
NS_SWIFT_NAME(contains(_:));

/**
 * Determines whether the intesection of this `NMAGeoBoundingBox` and the
 * specified `NMAGeoBoundingBox` is non-empty.
 *
 * @param boundingBox A `NMAGeoBoundingBox` to check for intersection with this
 * `NMAGeoBoundingBox`
 * @return YES if the intersection of `NMAGeoBoundingBox` objects is non-empty,
 *         NO otherwise
 */
- (BOOL)intersectsGeoBoundingBox:(NMAGeoBoundingBox *)boundingBox
NS_SWIFT_NAME(intersects(_:));

/**
 * Computes the intersection of this and another `NMAGeoBoundingBox`.
 *
 * @note The interection may have zero area.
 *
 * @param boundingBox The `NMAGeoBoundingBox` to intersect with
 * @return The `NMAGeoBoundingBox` representing the intersection, or nil if the
 *         boxes do not uniquely intersect
 */
- (nullable NMAGeoBoundingBox *)intersectionWithGeoBoundingBox:(NMAGeoBoundingBox *)boundingBox
NS_SWIFT_NAME(intersection(_:));

/**
 * Determines whether the size of the enclosed `NMAGeoBoundingBox` is 0.
 *
 * @return YES if the size of the enclosed area is 0, NO otherwise
 */
- (BOOL)isEmpty;

/**
 * Determines whether this `NMAGeoBoundingBox` is equal to another.
 *
 * @return YES if the bounding boxes are equal, NO otherwise
 */
- (BOOL)isEqualToGeoBoundingBox:(NMAGeoBoundingBox *)boundingBox
NS_SWIFT_NAME(equals(_:));

@end

NS_ASSUME_NONNULL_END
